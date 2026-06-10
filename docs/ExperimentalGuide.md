# Guia de Medicao Experimental MaxwellKey

## Objetivo

Este guia descreve o protocolo completo para medir os parametros de acoplamento de uma PCB real e verificar as hipoteses de seguranca do MaxwellKey usando Lean 4.

## Materiais Necessarios

### Hardware

| Item | Especificacao Minima | Nota |
|------|---------------------|------|
| PCB de teste | 2 pistas paralelas, FR-4, 1.6mm | Ver secao "Design da PCB" |
| VNA | NanoVNA V2 (~€50) ou Keysight E5063A | NanoVNA suficiente para PoC |
| Cabos coaxiais | 4x SMA-SMA, curtos (<30cm) | Minimizar perdas |
| Conectores SMA | 4x edge-launch ou end-launch | Para as 4 extremidades |
| Computador | USB para NanoVNA, LAN para Keysight | |

### Software

- Python 3.8+
- `pip install numpy pyserial pyvisa`
- Lean 4 (para verificacao formal)

## Design da PCB

### Geometria

```
     <-- l -->
    +---------+    +---------+
    |   P1    | s  |   P2    |
    +---------+    +---------+
     <-- w -->

    h = espessura do substrato (1.6 mm)
    w = largura da pista (1.0 mm)
    s = separacao entre pistas (2.0 mm)
    l = comprimento da pista (100 mm)
```

### Especificacoes

| Parametro | Valor | Razao | Estado |
|-----------|-------|-------|--------|
| h (substrato) | 1.6 mm | — | FR-4 standard |
| w (largura) | 1.0 mm | w/h = 0.625 | Validado para formulas Hammerstad-Jensen |
| s (separacao) | 2.0 mm | s/h = 1.25 | Acoplamento fraco |
| l (comprimento) | 100 mm | l << λ/4 a 100 MHz | Quase-estatico verificado |
| Cobre | 35 μm (1 oz) | — | Standard |

**Verificacao de regime quase-estatico:**
```
λ = c / (f * sqrt(eps_eff)) ≈ 3e8 / (1e8 * 2.1) ≈ 1.43 m
λ/4 ≈ 0.36 m = 360 mm
l = 100 mm << 360 mm  ✅
```

## Protocolo de Medicao

### Passo 1: Calibracao do VNA

A calibracao e **obrigatoria** para medicoes precisas.

#### NanoVNA V2

1. Ligar o NanoVNA via USB ao computador
2. Abrir a aplicacao NanoVNA-QT ou usar terminal serial
3. Correr calibracao SOLI (Short, Open, Load, Isolation)
4. Guardar a calibracao na memoria 0

#### Keysight E5063A

1. Ligar o VNA via LAN
2. Abrir o software Keysight VNA Cal Wizard
3. Selecionar calibracao SOLT (Short, Open, Load, Thru)
4. Seguir as instrucoes do wizard com os kits de calibracao
5. Guardar o estado de calibracao

### Passo 2: Conexao da PCB

```
    Porta 1 do VNA  ──▶  Extremidade A da Pista 1
    Porta 2 do VNA  ──▶  Extremidade A da Pista 2
                         (Extremidade B terminada em 50 Ohm)
```

**Nota:** Para medicao completa (S11, S12, S21, S22), e necessario:
- Medicao 1: Porta 1 → P1, Porta 2 → P2
- Medicao 2: Trocar as portas (para S22 e S12)
- Ou usar um switch de RF (se disponivel)

Para o MaxwellKey, basta S11 e S21 (ou S12 pela reciprocidade).

### Passo 3: Configuracao do Sweep

| Parametro | Valor |
|-----------|-------|
| Frequencia inicial | 10 MHz |
| Frequencia final | 200 MHz |
| Pontos | 101 (NanoVNA) ou 1601 (Keysight) |
| Potencia | -10 dBm (baixa, para nao aquecer a PCB) |
| IF BW | 1 kHz |

### Passo 4: Captura de Dados

#### Opcao A: NanoVNA (automatico)

```bash
python scripts/vna_capture.py --vna nanovna --port /dev/ttyACM0 \
    --freq-start 10e6 --freq-stop 200e6 --points 101 \
    --output measured.s2p
```

#### Opcao B: Keysight (automatico)

```bash
python scripts/vna_capture.py --vna keysight --ip 192.168.1.10 \
    --freq-start 10e6 --freq-stop 200e6 --points 1601 \
    --output measured.s2p
```

#### Opcao C: Exportacao manual do VNA

1. Exportar dados do VNA para formato Touchstone (.s2p)
2. Copiar o ficheiro para `scripts/measured.s2p`

### Passo 5: Processamento

Extrair parametros do MaxwellKey:

```bash
python scripts/sparams_to_params.py --s2p measured.s2p --freq 100e6 \
    --eve-ratio 3.0 --output scripts/params.json
```

Este script:
1. Le o ficheiro .s2p
2. Converte S → Z → Y na frequencia de operacao
3. Calcula M_self = Z0 · |Im(Y11)| e M_mutual = Z0 · |Im(Y12)|
4. Estima f_att e min_f_sq
5. Verifica weak_coupling e f_sq_ge_min
6. Exporta para scripts/params.json

### Passo 6: Verificacao Formal em Lean

Abrir `MaxwellKeyPLUS/Examples/TemplateRealParams.lean` e atualizar:

```lean
def measured_params : DegradednessParamsGeneral :=
  params_from_json
    (M_self := ...)    -- valor do params.json
    (M_mutual := ...)  -- valor do params.json
    (Z₀ := ...)       -- valor do params.json
    (f := ...)        -- valor do params.json
    (by norm_num) (by norm_num) (by norm_num) (by norm_num)
```

Correr a verificacao:

```bash
cd /path/to/MaxwellKey
lake build
```

Se `lake build` passa, as hipoteses de seguranca estao satisfeitas para a PCB medida.

## Interpretacao dos Resultados

### Tabela de Verificacoes

| Verificacao | Condicao | Significado |
|-------------|----------|-------------|
| weak_coupling | `\|M_mutual\| < \|M_self\|/2` | Acoplamento suficientemente fraco |
| f_sq_ge_min | `f^2 >= min_f_sq` | Eve esta suficientemente longe |
| regime_qs | `l < c/(4f)` | Regime quase-estatico valido |

Se **todas** as verificacoes passam, o protocolo MaxwellKey e teoricamente seguro para esta geometria.

### Exemplo de Output

```
  MAXWELLKEY — Parametros Extraidos de Medicoes Reais
  ============================================================
  Frequencia    : 100.00 MHz

  M_self        : 0.003112  (normalizado)
  M_mutual      : 0.000004  (normalizado)
  Z0            : 50.0 Ohm
  f_att         : 263.41
  min_f_sq      : 1.000028

  weak_coupling : PASSA
  f_sq >= min   : PASSA
  ============================================================
```

## Troubleshooting

### Problema: `M_mutual` muito pequeno (~0)

**Causa provavel:** Ligacao solta ou pista partida.
**Solucao:** Verificar continuidade com multimetro. Verificar solda dos conectores SMA.

### Problema: `M_mutual` muito grande (> M_self/2)

**Causa provavel:** Separacao entre pistas demasiado pequena.
**Solucao:** Aumentar s (separacao) ou reduzir l (comprimento). Verificar se ha curto-circuito entre pistas.

### Problema: `f_sq_ge_min` falha

**Causa provavel:** Eve nao esta suficientemente longe (f_att demasiado baixo).
**Solucao:** Aumentar a razao de distancias (d_eve/d_bob). Ou reduzir M_mutual (aumentar separacao).

### Problema: `lake build` falha em `h_f_sq_ge_min`

**Causa provavel:** `norm_num` nao consegue provar a desigualdade.
**Solucao:** Usar `field_simp` e `nlinarith` em vez de `norm_num`. Verificar se os valores foram copiados corretamente.

## Variacoes do Protocolo

### Medicao com SDR (HackRF / USRP)

Para setups com SDR, o processo e similar mas requer:

1. **Transmissao de sinal conhecido** (ex: tom sinusoidal) pela P1
2. **Recepcao** na P2 e na antena de Eve
3. **Estimacao do canal** usando correlacao cruzada
4. **Extracao de M_self/M_mutual** a partir da resposta em frequencia

Este metodo e mais complexo e requer software customizado (GNU Radio). O VNA e preferivel para validacao inicial.

### Medicao de Temperatura

O modelo de ruído usa `N0 = k_B * T * B`. Para validacao completa:

1. Medir a temperatura da PCB (termopar ou sensor IR)
2. Atualizar `temperature` em `NoiseModel`
3. Verificar que `N0` calculado e consistente com SNR medido

## Referencias

- [NanoVNA User Guide](https://nanorfe.com/nanovna-user-guide/)
- [Keysight E5063A Programming Guide](https://www.keysight.com/us/en/assets/7018-06723/programming-guides/5950-6658.pdf)
- Hammerstad-Jensen, "Accurate Models for Microstrip Computer-Aided Design", 1980
