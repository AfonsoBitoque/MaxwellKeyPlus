#!/usr/bin/env python3
"""
MaxwellKey / scripts / sparams_to_params.py
-------------------------------------------
Converte S-parameters medidos (de VNA ou ficheiro .s2p) nos parametros
normalizados M_self, M_mutual do MaxwellKey.

Formula:
    Z = Z0 * (I + S) * (I - S)^-1      [matriz de impedancia]
    Y = Z^-1                            [matriz de admitancia]

    M_self  = Z0 * |Im(Y_11)|  (adimensional)
    M_mutual = Z0 * |Im(Y_12)|  (adimensional)

Assume regime quase-estatico sem pernas dieletricas (G = 0),
logo Y e puramente imaginaria. A parte real (condutancia) e
medida para referencia mas nao usada no modelo Lean atual.

Dependencias:
    pip install numpy

Uso:
    # A partir de ficheiro .s2p
    python scripts/sparams_to_params.py --s2p measured.s2p --freq 100e6

    # A partir de JSON intermediario (do vna_capture.py)
    python scripts/sparams_to_params.py --json measured.json --freq 100e6

    # A partir de valores manualmente introduzidos
    python scripts/sparams_to_params.py --manual

Output:
    scripts/params.json (mesmo formato do simulate_circuit.py,
                         mas com valores MEDIDOS em vez de simulados)
"""

import argparse
import json
import math
import sys
from dataclasses import dataclass, asdict
from pathlib import Path

import numpy as np

from vna_capture import parse_s2p, SParams


# ---------------------------------------------------------------------------
# Constantes
# ---------------------------------------------------------------------------

Z0_REF = 50.0  # Ohm (impedancia de referencia do VNA)


@dataclass
class MaxwellKeyParams:
    """Parametros do MaxwellKey extraidos de medicoes reais."""
    # --- Parametros normalizados (usados no Lean) ---
    M_self: float
    M_mutual: float
    Z0: float
    f: float
    min_f_sq: float
    weak_coupling_ok: bool
    f_sq_ge_min_ok: bool

    # --- Parametros fisicos brutos (para referencia) ---
    C_self: float
    L_self: float
    C_mutual: float
    M_mutual_H: float  # indutancia mutua em Henry (diferente do M_mutual normalizado!)
    G: float           # condutancia dieletrica (medida, nao usada no Lean)

    # --- Metadados da medicao ---
    frequency_hz: float
    s11_mag: float
    s11_phase_deg: float
    s21_mag: float
    s21_phase_deg: float
    Y_self_imag: float
    Y_mutual_imag: float
    Y_self_real: float   # condutancia (para referencia)
    Y_mutual_real: float # para referencia

    # --- Notas ---
    notes: str = ""


# ---------------------------------------------------------------------------
# Conversao S -> Z -> Y
# ---------------------------------------------------------------------------

def s_to_y_matrix(s11: complex, s12: complex, s21: complex, s22: complex,
                  z0: float = Z0_REF) -> np.ndarray:
    """Converte matriz S 2x2 para matriz Y 2x2.

    Z = Z0 * (I + S) * (I - S)^-1
    Y = Z^-1
    """
    I = np.eye(2, dtype=complex)
    S = np.array([[s11, s12], [s21, s22]], dtype=complex)

    # Z = Z0 * (I + S) * inv(I - S)
    I_minus_S = I - S
    I_plus_S = I + S
    Z = z0 * I_plus_S @ np.linalg.inv(I_minus_S)

    # Y = inv(Z)
    Y = np.linalg.inv(Z)
    return Y


def extract_params_at_freq(sp: SParams, freq_hz: float,
                           z0: float = Z0_REF,
                           d_eve_ratio: float = 3.0) -> MaxwellKeyParams:
    """Extrai parametros MaxwellKey de S-parameters numa frequencia especifica.

    Args:
        sp: S-parameters (objecto SParams do vna_capture.py)
        freq_hz: Frequencia de operacao (Hz)
        z0: Impedancia de referencia (Ohm)
        d_eve_ratio: Razao de distancias d_eve / d_bob (para estimar f_att)
    """
    # Interpolar S-parameters na frequencia desejada
    idx = np.argmin(np.abs(sp.freqs - freq_hz))
    s11 = sp.s11[idx]
    s12 = sp.s12[idx]
    s21 = sp.s21[idx]
    s22 = sp.s22[idx]

    # Converter S -> Y
    Y = s_to_y_matrix(s11, s12, s21, s22, z0)

    Y_self = Y[0, 0]
    Y_mutual = Y[0, 1]

    # Partes real e imaginaria
    Y_self_re = Y_self.real
    Y_self_im = Y_self.imag
    Y_mutual_re = Y_mutual.real
    Y_mutual_im = Y_mutual.imag

    # Parametros normalizados (modelo MaxwellKey)
    M_self = z0 * abs(Y_self_im)
    M_mutual = z0 * abs(Y_mutual_im)

    # Estimativa de f_att (modelo near-field ~1/d^3)
    if abs(M_mutual) < 1e-12:
        f_att = float('inf')
        note = "AVISO: M_mutual ~ 0, f_att = inf. Verificar ligacao."
    else:
        f_att = abs(M_self / M_mutual) * (d_eve_ratio ** 3)
        note = ""

    # min_f_sq
    denom = max((M_self**2 - M_mutual**2)**2, 1e-18)
    min_f_sq = ((M_self**2 + M_mutual**2) * (M_self + M_mutual)**2) / denom

    # Verificacoes
    weak_coupling_ok = abs(M_mutual) < abs(M_self) / 2
    f_sq_ge_min_ok = f_att**2 >= min_f_sq

    # Parametros fisicos (aproximacao: extrair C e L de Y)
    omega = 2 * math.pi * freq_hz
    # Y_self = j*omega*C - 1/(j*omega*L) = j*(omega*C + 1/(omega*L))
    # Aproximacao para regime acima da ressonancia: C ~ |Im(Y)|/omega
    C_self_approx = abs(Y_self_im) / omega
    L_self_approx = 1.0 / (omega * abs(Y_self_im))
    C_mutual_approx = abs(Y_mutual_im) / omega
    M_mutual_H_approx = 1.0 / (omega * abs(Y_mutual_im))
    G_cond = Y_self_re  # condutancia dieletrica

    return MaxwellKeyParams(
        M_self=M_self,
        M_mutual=M_mutual,
        Z0=z0,
        f=f_att,
        min_f_sq=min_f_sq,
        weak_coupling_ok=weak_coupling_ok,
        f_sq_ge_min_ok=f_sq_ge_min_ok,
        C_self=C_self_approx,
        L_self=L_self_approx,
        C_mutual=C_mutual_approx,
        M_mutual_H=M_mutual_H_approx,
        G=G_cond,
        frequency_hz=freq_hz,
        s11_mag=abs(s11),
        s11_phase_deg=np.angle(s11, deg=True),
        s21_mag=abs(s21),
        s21_phase_deg=np.angle(s21, deg=True),
        Y_self_imag=Y_self_im,
        Y_mutual_imag=Y_mutual_im,
        Y_self_real=Y_self_re,
        Y_mutual_real=Y_mutual_re,
        notes=note,
    )


# ---------------------------------------------------------------------------
# Modo manual (para testes sem VNA)
# ---------------------------------------------------------------------------

def manual_mode() -> MaxwellKeyParams:
    """Modo interativo para introduzir valores manualmente."""
    print("=" * 60)
    print("  MaxwellKey — Modo Manual de Entrada de S-Parameters")
    print("=" * 60)

    freq_hz = float(input("Frequencia de operacao (Hz): "))
    z0 = float(input(f"Impedancia de referencia Z0 (default {Z0_REF}): ") or Z0_REF)

    print("\n--- S-Parameters (polar: magnitude, fase em graus) ---")
    s11_mag = float(input("|S11|: "))
    s11_deg = float(input("ang(S11) em graus: "))
    s12_mag = float(input("|S12|: "))
    s12_deg = float(input("ang(S12) em graus: "))
    s21_mag = float(input("|S21|: "))
    s21_deg = float(input("ang(S21) em graus: "))
    s22_mag = float(input("|S22|: "))
    s22_deg = float(input("ang(S22) em graus: "))

    d_eve_ratio = float(input("\nRazao de distancias d_eve/d_bob (default 3.0): ") or "3.0")

    s11 = s11_mag * (math.cos(math.radians(s11_deg)) + 1j * math.sin(math.radians(s11_deg)))
    s12 = s12_mag * (math.cos(math.radians(s12_deg)) + 1j * math.sin(math.radians(s12_deg)))
    s21 = s21_mag * (math.cos(math.radians(s21_deg)) + 1j * math.sin(math.radians(s21_deg)))
    s22 = s22_mag * (math.cos(math.radians(s22_deg)) + 1j * math.sin(math.radians(s22_deg)))

    sp = SParams(
        freqs=np.array([freq_hz]),
        s11=np.array([s11]),
        s12=np.array([s12]),
        s21=np.array([s21]),
        s22=np.array([s22]),
    )

    return extract_params_at_freq(sp, freq_hz, z0, d_eve_ratio)


# ---------------------------------------------------------------------------
# Exportacao
# ---------------------------------------------------------------------------

def export_params(p: MaxwellKeyParams, path: str = "scripts/params.json") -> None:
    """Exporta parametros para JSON (formato compativel com simulate_circuit.py)."""
    data = asdict(p)
    data["_metadata"] = {
        "source": "sparams_to_params.py",
        "method": "measured",
        "note": "Valores extraidos de S-parameters reais (VNA). "
                "Usar simulate_circuit.py para comparacao com modelo analitico.",
    }
    with open(path, "w") as f:
        json.dump(data, f, indent=2)
    print(f"[OK] Parametros exportados para {path}")


def print_params(p: MaxwellKeyParams) -> None:
    """Imprime parametros formatados."""
    print("=" * 60)
    print("  MAXWELLKEY — Parametros Extraidos de Medicoes Reais")
    print("=" * 60)
    print(f"  Frequencia    : {p.frequency_hz/1e6:.2f} MHz")
    print()
    print(f"  M_self        : {p.M_self:.6f}  (normalizado)")
    print(f"  M_mutual      : {p.M_mutual:.6f}  (normalizado)")
    print(f"  Z0            : {p.Z0:.1f} Ohm")
    print(f"  f_att         : {p.f:.4f}")
    print(f"  min_f_sq      : {p.min_f_sq:.6f}")
    print()
    print(f"  weak_coupling : {'PASSA' if p.weak_coupling_ok else 'FALHA'}")
    print(f"  f_sq >= min   : {'PASSA' if p.f_sq_ge_min_ok else 'FALHA'}")
    print()
    print(f"  C_self (est.) : {p.C_self:.6e} F")
    print(f"  L_self (est.) : {p.L_self:.6e} H")
    print(f"  C_mutual(est.) : {p.C_mutual:.6e} F")
    print(f"  M_mutual_H    : {p.M_mutual_H:.6e} H")
    print(f"  G (condut.)   : {p.G:.6e} S")
    print()
    print(f"  Y_self_imag   : {p.Y_self_imag:.6e} S")
    print(f"  Y_mutual_imag : {p.Y_mutual_imag:.6e} S")
    print(f"  Y_self_real   : {p.Y_self_real:.6e} S  (nao usado no Lean)")
    print("=" * 60)
    if p.notes:
        print(f"  NOTA: {p.notes}")


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description="Converte S-parameters para parametros MaxwellKey"
    )
    parser.add_argument("--s2p", help="Ficheiro .s2p (Touchstone)")
    parser.add_argument("--json", help="Ficheiro JSON (do vna_capture.py)")
    parser.add_argument("--manual", action="store_true",
                        help="Modo interativo manual")
    parser.add_argument("--freq", type=float, default=100e6,
                        help="Frequencia de operacao (Hz)")
    parser.add_argument("--z0", type=float, default=Z0_REF,
                        help="Impedancia de referencia (Ohm)")
    parser.add_argument("--eve-ratio", type=float, default=3.0,
                        help="Razao de distancias d_eve/d_bob")
    parser.add_argument("--output", default="scripts/params.json",
                        help="Ficheiro de output")

    args = parser.parse_args()

    if args.manual:
        params = manual_mode()
    elif args.s2p:
        print(f"[INFO] A processar {args.s2p}...")
        sp = parse_s2p(args.s2p)
        params = extract_params_at_freq(sp, args.freq, args.z0, args.eve_ratio)
    elif args.json:
        print(f"[INFO] A processar {args.json}...")
        with open(args.json, 'r') as f:
            data = json.load(f)
        sp = SParams(
            freqs=np.array(data["freqs_hz"]),
            s11=np.array(data["s11_real"]) + 1j * np.array(data["s11_imag"]),
            s12=np.array(data["s12_real"]) + 1j * np.array(data["s12_imag"]),
            s21=np.array(data["s21_real"]) + 1j * np.array(data["s21_imag"]),
            s22=np.array(data["s22_real"]) + 1j * np.array(data["s22_imag"]),
        )
        params = extract_params_at_freq(sp, args.freq, args.z0, args.eve_ratio)
    else:
        parser.print_help()
        sys.exit(1)

    print_params(params)
    export_params(params, args.output)

    # Instrucoes para Lean
    print("\n--- Proximos passos ---")
    print("1. Abrir MaxwellKeyPLUS/Examples/TemplateRealParams.lean")
    print("2. Copiar os valores M_self, M_mutual, Z0, f acima")
    print("3. Colar na funcao params_from_json ou create_params")
    print("4. Correr 'lake build' para verificar as hipoteses")


if __name__ == "__main__":
    main()
