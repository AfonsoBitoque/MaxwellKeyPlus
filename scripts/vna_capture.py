#!/usr/bin/env python3
"""
MaxwellKey / scripts / vna_capture.py
-------------------------------------
Captura de S-parameters de um Analisador de Redes Vetorial (VNA)
para o testbed experimental MaxwellKey.

Suporta:
- Keysight E5063A (SCPI via pyvisa)
- NanoVNA V2 (USB serial via pyserial)
- Ficheiro .s2p (para processamento offline)

Dependencias:
    pip install pyvisa pyserial numpy

    Para Keysight: tambem necessita do driver VISA (Keysight IO Libraries)

Uso:
    # Com VNA Keysight (via LAN)
    python scripts/vna_capture.py --vna keysight --ip 192.168.1.10 --output measured.s2p

    # Com NanoVNA (via USB)
    python scripts/vna_capture.py --vna nanovna --port /dev/ttyACM0 --output measured.s2p

    # Processar ficheiro .s2p existente
    python scripts/vna_capture.py --file measured.s2p --output params.json
"""

import argparse
import json
import sys
import struct
from dataclasses import dataclass
from pathlib import Path
from typing import Optional, List, Tuple

import numpy as np

# ---------------------------------------------------------------------------
# Constantes
# ---------------------------------------------------------------------------

Z0_DEFAULT = 50.0       # Ohm (impedancia de referencia do VNA)
FREQ_MHZ_DEFAULT = 100.0  # Frequencia de operacao (Hz -> MHz no output)


@dataclass
class SParams:
    """S-parameters de uma rede de 2 portas."""
    freqs: np.ndarray          # Hz
    s11: np.ndarray            # complex
    s12: np.ndarray            # complex
    s21: np.ndarray            # complex
    s22: np.ndarray            # complex

    def at_freq(self, freq_hz: float) -> Tuple[complex, complex, complex, complex]:
        """Interpola S-parameters na frequencia desejada."""
        idx = np.argmin(np.abs(self.freqs - freq_hz))
        return (self.s11[idx], self.s12[idx], self.s21[idx], self.s22[idx])


# ---------------------------------------------------------------------------
# Leitura de ficheiros Touchstone (.s2p)
# ---------------------------------------------------------------------------

def parse_s2p(filepath: str) -> SParams:
    """Parse um ficheiro Touchstone .s2p (formato MA: magnitude/angle)."""
    freqs = []
    s11, s12, s21, s22 = [], [], [], []
    freq_unit = 1.0  # Hz por default

    with open(filepath, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('!'):
                continue
            if line.startswith('#'):
                # Parse header: # Hz S MA R 50
                parts = line.lower().split()
                if 'khz' in parts:
                    freq_unit = 1e3
                elif 'mhz' in parts:
                    freq_unit = 1e6
                elif 'ghz' in parts:
                    freq_unit = 1e9
                continue

            vals = [float(x) for x in line.split()]
            if len(vals) < 9:
                continue  # ignorar linhas mal-formadas

            freqs.append(vals[0] * freq_unit)
            s11.append(polar_to_complex(vals[1], vals[2]))
            s12.append(polar_to_complex(vals[3], vals[4]))
            s21.append(polar_to_complex(vals[5], vals[6]))
            s22.append(polar_to_complex(vals[7], vals[8]))

    return SParams(
        freqs=np.array(freqs),
        s11=np.array(s11),
        s12=np.array(s12),
        s21=np.array(s21),
        s22=np.array(s22),
    )


def polar_to_complex(mag: float, angle_deg: float) -> complex:
    """Converte magnitude/angulo (graus) para complexo."""
    angle_rad = np.deg2rad(angle_deg)
    return mag * (np.cos(angle_rad) + 1j * np.sin(angle_rad))


# ---------------------------------------------------------------------------
# Comunicacao com VNA (Keysight via pyvisa)
# ---------------------------------------------------------------------------

def capture_keysight(ip: str, freq_start: float, freq_stop: float,
                     points: int = 1601) -> SParams:
    """Captura S-parameters de um Keysight E5063A via LAN.

    Args:
        ip: Endereco IP do VNA
        freq_start: Frequencia inicial (Hz)
        freq_stop: Frequencia final (Hz)
        points: Numero de pontos do sweep
    """
    try:
        import pyvisa
    except ImportError:
        print("[ERRO] pyvisa nao instalado. Correr: pip install pyvisa")
        sys.exit(1)

    rm = pyvisa.ResourceManager()
    inst = rm.open_resource(f"TCPIP0::{ip}::inst0::INSTR")
    inst.timeout = 10000  # ms

    # Configurar sweep
    inst.write(f"SENS:FREQ:START {freq_start}")
    inst.write(f"SENS:FREQ:STOP {freq_stop}")
    inst.write(f"SENS:SWE:POIN {points}")
    inst.write("CALC:PAR:SEL 'CH1_S11'")
    inst.write("FORM:DATA REAL,32")

    # Trigger sweep
    inst.write("INIT:IMM")
    inst.query("*OPC?")

    # Ler dados S11
    inst.write("CALC:DATA? FDATA")
    raw = inst.read_raw()
    s11_re = parse_bin32(raw)

    # (Simplificado — numa implementacao completa, ler todas as S-parameters)
    # Para o MaxwellKey, basta S11 e S21 (ou S12 pela reciprocidade)

    freqs = np.linspace(freq_start, freq_stop, points)

    # Placeholder: usar S2P exportado em vez de binario
    inst.write("MMEM:STOR 'D:\\temp.s2p'")
    print("[INFO] Dados exportados para temp.s2p no VNA. Transferir manualmente.")

    inst.close()
    rm.close()

    # Ler o ficheiro S2P exportado
    return parse_s2p("scripts/temp.s2p")


# ---------------------------------------------------------------------------
# Comunicacao com NanoVNA V2
# ---------------------------------------------------------------------------

def capture_nanovna(port: str, freq_start: float, freq_stop: float,
                    points: int = 101) -> SParams:
    """Captura S-parameters de um NanoVNA V2 via USB serial.

    Args:
        port: Porta serial (ex: /dev/ttyACM0 ou COM3)
        freq_start: Frequencia inicial (Hz)
        freq_stop: Frequencia final (Hz)
        points: Numero de pontos
    """
    try:
        import serial
    except ImportError:
        print("[ERRO] pyserial nao instalado. Correr: pip install pyserial")
        sys.exit(1)

    ser = serial.Serial(port, baudrate=4000000, timeout=2)

    # Comando NanoVNA: sweep
    ser.write(f"scan {int(freq_start)} {int(freq_stop)} {points}\r".encode())

    freqs = np.linspace(freq_start, freq_stop, points)
    s11, s12, s21, s22 = [], [], [], []

    for _ in range(points):
        line = ser.readline().decode().strip()
        if not line:
            continue
        parts = line.split()
        if len(parts) >= 5:
            s11.append(complex(float(parts[1]), float(parts[2])))
            s21.append(complex(float(parts[3]), float(parts[4])))

    ser.close()

    # NanoVNA V2 nao mede S12/S22 no modo basico; usar reciprocidade
    s12 = np.array(s21)
    s22 = np.array(s11)  # aproximacao para estrutura simetrica

    return SParams(
        freqs=freqs,
        s11=np.array(s11),
        s12=s12,
        s21=np.array(s21),
        s22=s22,
    )


# ---------------------------------------------------------------------------
# Parse binario Keysight
# ---------------------------------------------------------------------------

def parse_bin32(raw: bytes) -> np.ndarray:
    """Parse bloco binario IEEE 488.2 (definite length arbitrary block)."""
    # Formato: #<n><length><data...>
    if raw[0] != ord('#'):
        raise ValueError("Formato binario invalido")
    n = int(chr(raw[1]))
    length = int(raw[2:2+n].decode())
    data = raw[2+n:2+n+length]
    return np.frombuffer(data, dtype=np.float32)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description="Captura S-parameters para o testbed MaxwellKey"
    )
    parser.add_argument("--vna", choices=["keysight", "nanovna"],
                        help="Tipo de VNA")
    parser.add_argument("--ip", default="192.168.1.10",
                        help="IP do VNA Keysight")
    parser.add_argument("--port", default="/dev/ttyACM0",
                        help="Porta serial do NanoVNA")
    parser.add_argument("--file",
                        help="Ficheiro .s2p existente (modo offline)")
    parser.add_argument("--output", default="scripts/measured.s2p",
                        help="Ficheiro de output")
    parser.add_argument("--freq-start", type=float, default=10e6,
                        help="Frequencia inicial (Hz)")
    parser.add_argument("--freq-stop", type=float, default=200e6,
                        help="Frequencia final (Hz)")
    parser.add_argument("--points", type=int, default=1601,
                        help="Pontos do sweep")

    args = parser.parse_args()

    if args.file:
        print(f"[INFO] A processar ficheiro existente: {args.file}")
        sp = parse_s2p(args.file)
    elif args.vna == "keysight":
        print(f"[INFO] A conectar ao Keysight em {args.ip}...")
        sp = capture_keysight(args.ip, args.freq_start, args.freq_stop, args.points)
    elif args.vna == "nanovna":
        print(f"[INFO] A conectar ao NanoVNA em {args.port}...")
        sp = capture_nanovna(args.port, args.freq_start, args.freq_stop, args.points)
    else:
        parser.print_help()
        sys.exit(1)

    print(f"[OK] Capturados {len(sp.freqs)} pontos de {sp.freqs[0]/1e6:.1f} a "
          f"{sp.freqs[-1]/1e6:.1f} MHz")

    # Guardar em formato intermediario (JSON com arrays complexos)
    export_json(sp, args.output.replace('.s2p', '.json'))
    print(f"[OK] Exportado para {args.output}")


def export_json(sp: SParams, path: str):
    """Exporta S-parameters para JSON (formato intermediario)."""
    data = {
        "freqs_hz": sp.freqs.tolist(),
        "s11_real": sp.s11.real.tolist(),
        "s11_imag": sp.s11.imag.tolist(),
        "s12_real": sp.s12.real.tolist(),
        "s12_imag": sp.s12.imag.tolist(),
        "s21_real": sp.s21.real.tolist(),
        "s21_imag": sp.s21.imag.tolist(),
        "s22_real": sp.s22.real.tolist(),
        "s22_imag": sp.s22.imag.tolist(),
    }
    with open(path, 'w') as f:
        json.dump(data, f, indent=2)


if __name__ == "__main__":
    main()
