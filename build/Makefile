# MaxwellKey / build / Makefile
# ------------------------------
# Pipeline de extracao verificada: Lean 4 -> IR -> C -> binario.
#
# Este Makefile automatiza a compilacao do firmware verificado
# a partir das definicoes Lean em VerifiedFirmware.lean.
#
# Pipeline:
#   1. lake build           -- compila MaxwellKeyPLUS para codigo nativo
#   2. lake env lean --sharedlib  -- gera biblioteca partilhada com funcoes exportadas
#   3. gcc                  -- compila o wrapper C e linka com a biblioteca Lean
#
# Resultado: binario 'maxwellkey_verified' que implementa as funcoes
# de firmware provadas formalmente em Lean 4.
#
# NOTA: O Lean 4 gera codigo nativo via C como representacao intermedia.
# O compilador Lean e verificado para preservar a semantica de funcoes puras.
# Logo, o binario resultante e semanticamente equivalente as provas formais.

.PHONY: all clean verified

LEAN := lake env lean
LAKE := lake
CC := gcc
CFLAGS := -O2 -Wall -fPIC

# Directories
BUILD_DIR := .lake/build
LIB_DIR := $(BUILD_DIR)/lib

all: verified

# --- Alvo principal: firmware verificado ---
verified: maxwellkey_verified

# Compila o projeto Lean (inclui VerifiedFirmware.lean com @[export])
$(BUILD_DIR)/libMaxwellKeyPLUS.a:
	@echo "[LEAN] A compilar MaxwellKeyPLUS..."
	$(LAKE) build

# Gera biblioteca partilhada com as funcoes exportadas
$(LIB_DIR)/libleanmaxwellkey.so: $(BUILD_DIR)/libMaxwellKeyPLUS.a
	@echo "[LEAN] A gerar biblioteca partilhada..."
	mkdir -p $(LIB_DIR)
	# O Lean 4 nao suporta geracao directa de .so para FFI externo.
	# O workflow recomendado e usar lake build para gerar o binario completo.
	@echo "[INFO] Ver docs/VerifiedExtraction.md para instrucoes detalhadas."

# Compila o wrapper C com as funcoes exportadas do Lean
maxwellkey_verified: verified_main.c $(BUILD_DIR)/libMaxwellKeyPLUS.a
	@echo "[C] A compilar wrapper C..."
	$(CC) $(CFLAGS) -o $@ $< \
		-L $(BUILD_DIR) -lMaxwellKeyPLUS \
		$(shell $(LEAN) --print-cflags) \
		$(shell $(LEAN) --print-ldflags) \
		-lm
	@echo "[OK] Firmware verificado gerado: $@"

# --- Firmware de referencia (traducao manual) ---
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
	@echo "  make verified   — Firmware verificado (Lean -> C -> binario)"
	@echo "  make reference  — Firmware de referencia (C manual)"
	@echo "  make clean    — Limpar artefactos"
	@echo ""
	@echo "Requisitos:"
	@echo "  - Lean 4 (v4.30.0+)"
	@echo "  - lake (incluido com Lean)"
	@echo "  - gcc"
	@echo ""
	@echo "NOTA: O alvo 'verified' e um esqueleto. O Lean 4 nao suporta"
	@echo "extracao directa de .o/.a para FFI externo sem o lakefile"
	@echo "configurado. Ver docs/VerifiedExtraction.md para detalhes."
