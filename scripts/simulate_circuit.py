#!/usr/bin/env python3
"""
MaxwellKey / scripts / simulate_circuit.py
------------------------------------------
Simulador analitico de fallback para parametros de acoplamento
entre pistas paralelas em PCB. Usa formulas de microstrip
(Hammerstad-Jensen) e modelo de decaimento near-field.

NOTA: Este script calcula a condutancia G como parametro de saida
para referencia, mas o modelo Lean atual (DegradednessGeneral) nao
usa G. As perdas no dieletrico sao desprezaveis no regime
quase-estatico a 100 MHz e serao incorporadas em trabalho futuro.

Uso:
    python scripts/simulate_circuit.py
    # Gera scripts/params.json

Limitacoes: Aproximacoes validas para w/h <= 1, s/h >= 0.3.
"""

import json
import math
from dataclasses import dataclass, asdict

C0 = 299_792_458.0
EPS0 = 8.854187817e-12


def effective_permittivity(w_over_h: float, eps_r: float) -> float:
    """Permissividade efetiva (Hammerstad-Jensen)."""
    a = (eps_r + 1) / 2
    b = (eps_r - 1) / 2
    c = (1 + 12 / w_over_h) ** (-0.5)
    return a + b * c


def microstrip_impedance(w_over_h: float, eps_r: float) -> float:
    """Impedancia caracteristica Z_c (Hammerstad-Jensen)."""
    eps_eff = effective_permittivity(w_over_h, eps_r)
    if w_over_h <= 1:
        return (60 / math.sqrt(eps_eff)) * math.log(8 / w_over_h + 0.25 * w_over_h)
    return (120 * math.pi / math.sqrt(eps_eff)) / (w_over_h + 1.393 + 0.667 * math.log(w_over_h + 1.444))


def capacitance_per_meter(w: float, h: float, eps_r: float) -> float:
    """Capacitancia por metro (F/m)."""
    woh = w / h
    eps_eff = effective_permittivity(woh, eps_r)
    zc = microstrip_impedance(woh, eps_r)
    vp = C0 / math.sqrt(eps_eff)
    return 1 / (vp * zc)


def inductance_per_meter(w: float, h: float, eps_r: float) -> float:
    """Indutancia por metro (H/m)."""
    woh = w / h
    eps_eff = effective_permittivity(woh, eps_r)
    zc = microstrip_impedance(woh, eps_r)
    vp = C0 / math.sqrt(eps_eff)
    return zc / vp


def mutual_capacitance(w: float, s: float, h: float, l: float, eps_r: float) -> float:
    """Capacidade mutua (modelo empirico)."""
    c_prime = capacitance_per_meter(w, h, eps_r)
    soh = s / h
    factor = min(0.5 * (soh ** (-1.5)) * math.exp(-soh), 0.25)
    return c_prime * factor * l


def mutual_inductance(w: float, s: float, h: float, l: float, eps_r: float) -> float:
    """Indutancia mutua (modelo empirico)."""
    l_prime = inductance_per_meter(w, h, eps_r)
    soh = s / h
    factor = min(0.5 * (soh ** (-1.5)) * math.exp(-soh), 0.25)
    return l_prime * factor * l


def conductance_dielectric(c_self: float, f: float, tan_delta: float) -> float:
    """Condutancia de perdas no dieletrico (S)."""
    return 2 * math.pi * f * c_self * tan_delta


def eve_attenuation_factor(m_self: float, m_mutual: float, ratio: float) -> float:
    """Fator de atenuacao f_att para Eve (~1/d^3)."""
    if abs(m_mutual) < 1e-12:
        return float('inf')
    return abs(m_self / m_mutual) * (ratio ** 3)


@dataclass
class MaxwellKeyParams:
    M_self: float
    M_mutual: float
    Z0: float
    f: float
    G: float
    C_self: float
    L_self: float
    C_mutual: float
    M_mutual_H: float
    min_f_sq: float
    weak_coupling_ok: bool
    f_sq_ge_min_ok: bool


def compute_all_params(
    w: float = 1e-3,
    s: float = 2e-3,
    l: float = 0.1,
    h: float = 1.6e-3,
    eps_r: float = 4.4,
    tan_delta: float = 0.02,
    f: float = 100e6,
    Z0_term: float = 50.0,
    d_eve_ratio: float = 3.0,
) -> MaxwellKeyParams:
    """Calcula todos os parametros do MaxwellKey."""
    c_prime = capacitance_per_meter(w, h, eps_r)
    l_prime = inductance_per_meter(w, h, eps_r)
    C_self = c_prime * l
    L_self = l_prime * l
    C_mutual = mutual_capacitance(w, s, h, l, eps_r)
    M_mutual_H = mutual_inductance(w, s, h, l, eps_r)
    G = conductance_dielectric(C_self, f, tan_delta)
    omega = 2 * math.pi * f
    Y_self_mag = abs(omega * C_self - 1.0/(omega * L_self))
    Y_mutual_mag = abs(1.0/(omega * M_mutual_H) - omega * C_mutual)
    M_self = Z0_term * Y_self_mag
    M_mutual = Z0_term * Y_mutual_mag
    f_att = eve_attenuation_factor(M_self, M_mutual, d_eve_ratio)
    denom = max((M_self**2 - M_mutual**2)**2, 1e-18)
    min_f_sq = ((M_self**2 + M_mutual**2) * (M_self + M_mutual)**2) / denom
    return MaxwellKeyParams(
        M_self=M_self, M_mutual=M_mutual, Z0=Z0_term, f=f_att, G=G,
        C_self=C_self, L_self=L_self, C_mutual=C_mutual,
        M_mutual_H=M_mutual_H, min_f_sq=min_f_sq,
        weak_coupling_ok=abs(M_mutual) < abs(M_self) / 2,
        f_sq_ge_min_ok=f_att**2 >= min_f_sq,
    )


def print_params(p: MaxwellKeyParams) -> None:
    print("=" * 60)
    print("  MAXWELLKEY — Parametros Calculados (Fallback Analitico)")
    print("=" * 60)
    print(f"  M_self    = {p.M_self:.6f}  (normalizado)")
    print(f"  M_mutual  = {p.M_mutual:.6f}  (normalizado)")
    print(f"  Z0        = {p.Z0:.1f} Ohm")
    print(f"  f_att     = {p.f:.4f}")
    print(f"  G         = {p.G:.6e} S")
    print(f"  C_self    = {p.C_self:.6e} F")
    print(f"  L_self    = {p.L_self:.6e} H")
    print(f"  C_mutual  = {p.C_mutual:.6e} F")
    print(f"  M_mutual  = {p.M_mutual_H:.6e} H")
    print()
    print(f"  min_f_sq       = {p.min_f_sq:.6f}")
    print(f"  weak_coupling  = {'PASSA' if p.weak_coupling_ok else 'FALHA'}")
    print(f"  f_sq >= min    = {'PASSA' if p.f_sq_ge_min_ok else 'FALHA'}")
    print("=" * 60)


def export_json(p: MaxwellKeyParams, path: str = "scripts/params.json") -> None:
    data = asdict(p)
    data["_metadata"] = {
        "source": "simulate_circuit.py",
        "note": "Valores analiticos aproximados. Usar COMSOL para precisao.",
    }
    with open(path, "w") as f:
        json.dump(data, f, indent=2)
    print(f"[OK] Exportado para {path}")


if __name__ == "__main__":
    params = compute_all_params()
    print_params(params)
    export_json(params)
