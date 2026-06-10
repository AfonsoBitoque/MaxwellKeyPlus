# Arquitetura do Testbed Experimental MaxwellKey

## Visão Geral

O testbed experimental fecha a lacuna entre verificação formal (Lean 4) e o mundo físico. Em vez de depender apenas de simulações (Python/COMSOL), extraímos os parâmetros de acoplamento `M_self`, `M_mutual` diretamente de medições numa PCB real usando um Analisador de Redes Vetorial (VNA) ou Rádios Definidos por Software (SDR).

## Pipeline Experimental

```
┌──────────────┐     ┌──────────────┐     ┌──────────────┐     ┌──────────────┐
│  PCB Real    │────▶│  VNA / SDR   │────▶│  Processamento│────▶│  Lean 4      │
│  (2 pistas)  │     │  S-parameters│     │  M_self,      │     │  Verificação │
│              │     │  Admitâncias │     │  M_mutual,    │     │  Formal      │
└──────────────┘     └──────────────┘     │  min_f_sq     │     └──────────────┘
                                           └──────────────┘
```

## Hardware Necessário

### 1. PCB de Teste

| Parâmetro | Valor Sugerido | Nota |
|-----------|---------------|------|
| Material | FR-4 (εᵣ ≈ 4.4) | Standard, baixo custo |
| Espessura do substrato (h) | 1.6 mm | Standard |
| Largura das pistas (w) | 1.0 mm | w/h ≈ 0.625 |
| Separacao entre pistas (s) | 2.0 mm | s/h ≈ 1.25 |
| Comprimento das pistas (l) | 100 mm | << λ/4 a 100 MHz |
| Espessura do cobre | 35 μm (1 oz) | Standard |

**Conectores:** SMA de borda nas 4 extremidades (2 por pista).

### 2. Analisador de Redes Vetorial (VNA)

Recomendações (por ordem de preferência):

1. **Keysight E5063A** — VNA de bancada, precisão alta, API robusta (SCPI via USB/LAN)
2. **Rohde & Schwarz ZNLE** — Alternativa europeia, excelente documentação
3. **NanoVNA V2** — Budget (~€50), suficiente para prova de conceito, API USB-serial
4. **LiteVNA** — Open-source hardware, extensível

### 3. Alternativa: Rádios Definidos por Software (SDR)

Para setups low-cost:

1. **USRP B210** — SDR de referência, ~€1.5k, API UHD (C++/Python)
2. **HackRF One** — Budget (~€300), TX+RX half-duplex
3. **RTL-SDR v4** — Ultra budget (~€30), apenas RX (limitado para medição bidirecional)

**Nota:** SDR requer software de medição customizado (GNU Radio). VNA é preferível.

## Extração de Parâmetros de S-Parameters

Dados os S-parameters medidos `S_ij(ω)` da rede de 2 portas (as duas pistas), convertemos para matriz de admitância `Y`:

```
Z = Z₀ · (I + S) · (I - S)⁻¹    [matriz de impedância]
Y = Z⁻¹                           [matriz de admitância]
```

Para uma matriz simétrica 2×2:
```
Y = [[Y_self,  Y_mutual],
     [Y_mutual, Y_self]]
```

Os parâmetros normalizados do MaxwellKey são então:
```
M_self  = Z₀ · |Im(Y_self)|   (adimensional)
M_mutual = Z₀ · |Im(Y_mutual)| (adimensional)
```

**Nota:** Assumimos regime quase-estático sem pernas dielétricas (`G = 0`), logo `Y` é puramente imaginária. A parte real de `Y` (condutância) é medida mas não usada no modelo atual — documentada para trabalho futuro.

## Arquitetura de Software

```
scripts/
├── simulate_circuit.py          # Simulador analítico (fallback)
├── vna_capture.py              # NOVO: Captura S-parameters do VNA
├── sparams_to_params.py        # NOVO: Converte S → M_self, M_mutual
└── params.json                 # Output (mesmo formato)

docs/
├── TestbedArchitecture.md        # Este documento
├── ExperimentalGuide.md        # Protocolo detalhado de medição
└── ...
```

## Protocolo de Medição (Resumo)

1. **Calibrar o VNA** — calibração SOLT (Short, Open, Load, Thru) ou TRL
2. **Conectar a PCB** — 2 portas do VNA às 2 pistas
3. **Configurar sweep** — frequência de 10 MHz a 200 MHz, 1601 pontos
4. **Medir S-parameters** — exportar para Touchstone (.s2p)
5. **Processar** — `sparams_to_params.py` extrai M_self, M_mutual, f_att, min_f_sq
6. **Verificar em Lean** — copiar valores para `TemplateRealParams.lean`, correr `lake build`

## Segurança Física do Protocolo

O protocolo MaxwellKey é seguro **informação-teoricamente** se:

1. **Acoplamento fraco:** `|M_mutual| < |M_self|/2` (medido pelo VNA)
2. **Eve suficientemente longe:** `f² ≥ min_f_sq` (onde `f = |M_self / M_eve|`, e `M_eve` é estimado da posição de Eve)
3. **Regime quase-estático:** `l < c/(4f)` (verificado pelo comprimento da pista)

O VNA valida a condição 1 diretamente. A condição 2 depende da geometria (onde colocamos a antena de Eve). A condição 3 é verificada por design da PCB.

## Trabalho Futuro

- Incorporar pernas dielétricas (`G`) no modelo Lean
- Medir variação temporal dos parâmetros (envelhecimento, temperatura)
- Validar com diferentes geometrias (pistas curvas, múltiplas pares)
- Integrar medição em tempo real com geração de chave (firmware C)
