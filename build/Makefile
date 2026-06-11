# MaxwellKey / build / Makefile
# ------------------------------
# Pipeline de extracao verificada: Lean 4 -> IR -> C -> binario.
#
# STATUS: O alvo 'reference' (firmware C manual) funciona.
# O alvo 'verified' (extracao automatica Lean -> C) E UM ESQUELETO.
# O Lean 4 requer configuracao adicional no lakefile para gerar
# bibliotecas estaticas/partilhadas para FFI externo. Ver
# docs/VerifiedExtraction.md para a abordagem recomendada.
#
# Pipeline pretendido:
#   1. lake build           -- compila MaxwellKeyPLUS para codigo nativo
#   2. gcc                  -- compila o wrapper C e linka com a biblioteca Lean
#
# NOTA: O Lean 4 gera codigo nativo via C como representacao intermedia.
# O compilador Lean e verificado para preservar a semantica de funcoes puras.

.PHONY: all clean reference help

LEAN := lake env lean
LAKE := lake
CC := gcc
CFLAGS := -O2 -Wall -fPIC

# Directories
BUILD_DIR := .lake/build
LIB_DIR := $(BUILD_DIR)/lib

all: reference

# --- Alvo principal: firmware verificado (ESQUELETO) ---
# O Lean 4 nao gera .a/.so automaticamente para FFI sem lakefile custom.
# O workflow e usar 'lake build' directamente, que compila todo o projeto
# incluindo VerifiedFirmware.lean com @[export].
# Para chamar funcoes Lean de C, ver docs/VerifiedExtraction.md.
verified: verified_main.c
	@echo "[INFO] Alvo 'verified' e um esqueleto."
	@echo "[INFO] O Lean 4 nao suporta extracao directa de .a/.so"
	@echo "       para FFI externo sem configuracao do lakefile."
	@echo "[INFO] Ver docs/VerifiedExtraction.md para instrucoes."
	@false

# --- Firmware de referencia (traducao manual) ---
# Este alvo FUNCIONA e gera um binario executavel.
# E uma simulacao didatica, NAO e seguro para producao.
reference: key_generation.c
	@echo "[C] A compilar firmware de referencia..."
	$(CC) $(CFLAGS) -o keygen $< -lm
	@echo "[OK] Firmware de referencia gerado: keygen"

# --- Limpeza ---
clean:
	rm -f maxwellkey_verified keygen
	rm -rf $(LIB_DIR)
	$(LAKE) clean

# --- Help ---
help:
	@echo "MaxwellKey — Makefile de Extracao Verificada"
	@echo ""
	@echo "Alvos:"
	@echo "  make reference  — Firmware de referencia (C manual) — FUNCIONA"
	@echo "  make verified   — Firmware verificado (Lean -> C) — ESQUELETO"
	@echo "  make clean      — Limpar artefactos"
	@echo ""
	@echo "Requisitos:"
	@echo "  - Lean 4 (v4.30.0+)"
	@echo "  - lake (incluido com Lean)"
	@echo "  - gcc"
	@echo ""
	@echo "NOTA: O alvo 'verified' requer configuracao adicional do lakefile"
	@echo "para exportar funcoes Lean como biblioteca estatica. Ver"
	@echo "docs/VerifiedExtraction.md para a abordagem recomendada."
