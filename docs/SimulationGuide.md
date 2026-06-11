# Guia de Simulação Eletromagnética para o MaxwellKey

> **AVISO IMPORTANTE:** O modelo Lean atual assume **G = 0** (sem pernas dielétricas).
> A condutância `G` é calculada neste guia para referência completa, mas **NÃO é
> usada nas provas formais**. No regime quase-estático a 100 MHz, as pernas no
> FR-4 (tan δ ≈ 0.02) são desprezáveis face ao acoplamento capacitivo/indutivo.
> A inclusão de G no modelo é trabalho futuro. Ver `MaxwellKeyPLUS/Assumptions.lean`.

## 1. Objetivo

Este guia descreve os passos necessários para extrair os parâmetros físicos do acoplamento eletromagnético entre pistas de cobre numa PCB, usando simulações por elementos finitos (COMSOL Multiphysics) ou métodos de diferenças finitas no domínio do tempo (OpenEMS). Os parâmetros extraídos alimentam a verificação formal em Lean 4 do protocolo MaxwellKey.

**Parâmetros a extrair:**
- `C_self` — Capacidade própria (F)
- `L_self` — Indutância própria (H)
- `C_mutual` — Capacidade mútua (F)
- `M_mutual` — Indutância mútua (H)
- `G` — Condutância de pernas no dielétrico (S) — **calculado para referência; não usado no Lean**
- `f_att` — Fator de atenuação para a posição do espião

---

## 2. Geometria Alvo

### 2.1 PCB de Referência

```
┌─────────────────────────────────────────────────────────────┐
│  Substrato FR-4, ε_r = 4.4, tan δ = 0.02, h = 1.6 mm       │
│  ─────────────────────────────────────────────────────────  │
│                                                             │
│   Pista 1 (w=1mm)    s=2mm    Pista 2 (w=1mm)              │
│   ━━━━━━━━━━━━━━━┐    ↓    ┌━━━━━━━━━━━━━━━                │
│   ←── 10 cm ───→│         │←── 10 cm ───→                │
│                  │         │                                │
│  ─────────────────────────────────────────────────────────  │
│  Plano de massa (face inferior, cobre 35 µm)                │
└─────────────────────────────────────────────────────────────┘
```

| Parâmetro | Valor | Descrição |
|-----------|-------|-----------|
| `w` | 1 mm | Largura das pistas |
| `s` | 2 mm | Separação entre pistas (centro a centro) |
| `l` | 100 mm | Comprimento das pistas |
| `h` | 1.6 mm | Espessura do substrato FR-4 |
| `t_cu` | 35 µm | Espessura do cobre |
| `ε_r` | 4.4 | Permissividade relativa do FR-4 (@ 100 MHz) |
| `tan δ` | 0.02 | Factor de perdas do dielétrico (@ 100 MHz) |

### 2.2 Notas sobre a Geometria

- O regime **quase-estático** aplica-se quando o comprimento elétrico `l ≪ λ/4`. A 100 MHz, `λ ≈ 3 m` no ar e `λ/ε_eff ≈ 1.5 m` no substrato. Como `l = 10 cm ≪ 375 mm`, o regime é válido.
- O acoplamento é predominantemente **capacitivo e indutivo** (near-field). A radiação é desprezável a esta escala.

---

## 3. Simulação em COMSOL Multiphysics

### 3.1 Setup do Modelo

1. **Módulo:** AC/DC → **Circuito Equivalente** ou **Electromagnético Quase-Estático** (EQS).
2. **Dimensão:** 3D (recomendado para precisão) ou 2D transversal + comprimento.
3. **Frequência:** 100 MHz (ponto único).

### 3.2 Passos Detalhados

#### Passo 1: Geometria
```matlab
% COMSOL LiveLink para MATLAB (opcional)
model.param.set('w', '1[mm]');
model.param.set('s', '2[mm]');
model.param.set('l', '100[mm]');
model.param.set('h_sub', '1.6[mm]');
model.param.set('t_cu', '35[um]');
model.param.set('eps_r', '4.4');
model.param.set('tan_delta', '0.02');
```

#### Passo 2: Materiais
- **Substrato:** Definir como dielétrico com `ε_r = 4.4`, `tan δ = 0.02`.
- **Cobre:** Condutor perfeito (PEC) ou condutor com `σ = 5.8e7 S/m` para perdas ohmicas.
- **Ar:** `ε_r = 1.0`.

#### Passo 3: Condições de Fronteira
- Plano de massa na face inferior: **Condutor Elétrico** (ground).
- Faces laterais: **Perfectly Matched Layer** (PML) ou **Condições de Radiação**.

#### Passo 4: Excitação e Ports
- Adicionar **Lumped Ports** nas extremidades das pistas (impedância de referência 50 Ω).
- Definir **Port 1** na Pista 1, **Port 2** na Pista 2.
- Activar cálculo da matriz **S** e **Y** (parametrização de portos).

#### Passo 5: Malha
- Malha fina nas regiões das pistas e no dielétrico entre elas.
- Elementos tetraédricos com refinamento adaptativo.

#### Passo 6: Solver
- **Study:** Frequency Domain.
- Frequência: `100[MHz]`.
- Solver directo PARDISO (recomendado para matrizes densas em EQS).

### 3.3 Extração de Parâmetros

Após a simulação, os resultados aparecem em **Results → Global Evaluation** ou **Derived Values**.

#### Matriz de Admitâncias Y (2×2)
```
┌                    ┐
│  Y_11    Y_12     │
│  Y_21    Y_22     │
└                    ┘
```

Por reciprocidade: `Y_12 = Y_21`.

| Parâmetro | Fórmula de Extração |
|-----------|---------------------|
| `Y_self` | `Y_11 = G_self + jωC_self` |
| `Y_mutual` | `Y_12 = G_mutual + jωC_mutual` |

**Atenção:** A parte real de `Y` inclui `G` (condutância do dielétrico). Se o COMSOL usar condutores perfeitos, `G` vem apenas do dielétrico.

### 3.4 Cálculo dos Parâmetros para o MaxwellKey

A partir dos parâmetros Y extraídos:

```python
import numpy as np

omega = 2 * np.pi * 100e6  # 100 MHz

# Admitâncias complexas
Y_11 = complex(...)  # do COMSOL
Y_12 = complex(...)  # do COMSOL

# Capacidades e condutâncias
C_self = np.imag(Y_11) / omega
G_self = np.real(Y_11)
C_mutual = np.imag(Y_12) / omega
G_mutual = np.real(Y_12)

# Indutâncias (modelo pi-equivalente)
# Para linhas de transmissão curtas: L_self ≈ Im(Z_11)/omega onde Z = Y^(-1)
Y_matrix = np.array([[Y_11, Y_12], [Y_12, Y_11]])  # simétrica
Z_matrix = np.linalg.inv(Y_matrix)

L_self = np.imag(Z_matrix[0,0]) / omega
M_mutual = np.imag(Z_matrix[0,1]) / omega

# Condutância total de perdas
G = G_self + G_mutual  # ou apenas G_self se G_mutual for desprezável
```

### 3.5 Cálculo de G a partir de tan δ (Alternativa)

Se o COMSOL não fornecer `G` explicitamente:

```
G ≈ 2πf · C_self · tan δ
```

```python
f = 100e6
tan_delta = 0.02
G = 2 * np.pi * f * C_self * tan_delta
```

---

## 4. Simulação em OpenEMS (Alternativa Open-Source)

### 4.1 Setup

OpenEMS usa FDTD e é ideal para validação independente.

```bash
# Instalação (Ubuntu)
sudo apt-get install openems
```

### 4.2 Script Python de Setup (OpenEMS)

```python
import CSXCAD
import openEMS

# Dimensões (em metros)
w = 1e-3      # 1 mm
s = 2e-3      # 2 mm
l = 100e-3    # 10 cm
h = 1.6e-3    # 1.6 mm
t = 35e-6     # 35 um

# Grid
grid = CSXCAD.CSRectGrid()
grid.Add('x', np.linspace(-l/2, l/2, 201))
grid.Add('y', [-s/2-w/2, -s/2+w/2, s/2-w/2, s/2+w/2])
grid.Add('z', [0, t, t+h])

# Materiais
CSX = CSXCAD.ContinuousStructure()
CSX.SetMaterialProperty('FR4', epsilon=4.4, kappa=2*np.pi*100e6*8.854e-12*4.4*0.02)
CSX.AddMaterial('copper', type='PEC')

# Pistas
strip1 = CSX.AddMetal('strip1')
strip1.AddBox(start=[-l/2, -s/2-w/2, t], stop=[l/2, -s/2+w/2, t+t])

strip2 = CSX.AddMetal('strip2')
strip2.AddBox(start=[-l/2, s/2-w/2, t], stop=[l/2, s/2+w/2, t+t])

# Ports lumped (excitação diferencial)
port1 = CSX.AddLumpedPort(1, 50, start=[-l/2, 0, 0], stop=[-l/2+1e-3, 0, t+h])
port2 = CSX.AddLumpedPort(2, 50, start=[l/2, 0, 0], stop=[l/2-1e-3, 0, t+h])

# Simulação
FDTD = openEMS.OPENEMS(NrTS=100000)
FDTD.SetSinusExcite(100e6)
FDTD.Run(SimDir='/tmp/maxwellkey_sim')
```

### 4.3 Extração de Parâmetros em OpenEMS

Após a simulação, os parâmetros S são guardados em ficheiros `.sNp`. Converter para Y:

```python
import skrf as rf

# Ler parâmetros S
network = rf.Network('/tmp/maxwellkey_sim/port.s2p')
Y_network = network.y

# A 100 MHz
freq_idx = np.argmin(np.abs(network.f - 100e6))
Y_11 = Y_network[freq_idx, 0, 0]
Y_12 = Y_network[freq_idx, 0, 1]

# Extrair C, L, G como na secção 3.4
```

---

## 5. Simulação do Canal do Espião (Eve)

### 5.1 Geometria para Eve

Adicionar uma **terceira pista** (Pista 3) à distância `d_eve` da Pista 1 (Bob).

```
┌──────────────────────────────────────────────────────────────────────┐
│                                                                      │
│   Pista 1 (Bob)    s=2mm    Pista 2 (Bob)        d_eve=10cm       │
│   ━━━━━━━━━━━━┐    ↓    ┌━━━━━━━━━━━━┐              ━━━━━━━━━━━━   │
│               │         │                  Pista 3 (Eve)             │
│               │         │                                          │
└──────────────────────────────────────────────────────────────────────┘
```

| Cenário | `d_eve` | `f_att` estimado |
|---------|---------|------------------|
| Conservador | 3 cm | ~3 |
| Moderado | 10 cm | ~10 |
| Forte | 30 cm | ~30 |

### 5.2 Extração do Canal Eve

Simular apenas a Pista 3 (como receptor) excitada pela Pista 1 (transmissor).

```python
# No COMSOL: definir Port 3 na Pista 3
# Extrair Y_13 (acoplamento Bob→Eve)

Y_13 = complex(...)  # do COMSOL

# O canal de Eve é dominado pelo acoplamento mais próximo
# Se Eve está a d_eve, o acoplamento decai ~1/d_eve^3

# Fator de atenuação normalizado
f_att = abs(Y_11) / abs(Y_13)
```

---

## 6. Fórmulas de Cálculo para o MaxwellKey

### 6.1 Resumo das Fórmulas

| Parâmetro Lean | Fórmula | Unidade |
|----------------|---------|---------|
| `M_self` | `Z₀ * |Y_self|` (normalizado) | admensional |
| `M_mutual` | `Z₀ * |Y_mutual|` | admensional |
| `Z₀` | Impedância de terminação (tipicamente 50 Ω) | Ω |
| `f` | `f_att` (fator de distância) | admensional |
| `G` | `Re(Y_self)` ou `2πf C_self tan δ` | S |

**Normalização:**
```python
Z0 = 50.0  # Ohm
M_self = Z0 * abs(Y_self)   # normalizado
M_mutual = Z0 * abs(Y_mutual)  # normalizado
```

### 6.2 Verificação das Hipóteses

```python
# Acoplamento fraco (obrigatório para o teorema)
assert abs(M_mutual) < abs(M_self) / 2, "Acoplamento não é fraco!"

# f^2 >= min_f_sq (obrigatório para degradedness)
min_f_sq = ((M_self**2 + M_mutual**2) * (M_self + M_mutual)**2) / (M_self**2 - M_mutual**2)**2
assert f**2 >= min_f_sq, "f_att é insuficiente!"
```

---

## 7. Checklist para o David

- [ ] Simular geometria base (Pistas 1 e 2) no COMSOL ou OpenEMS
- [ ] Extrair `Y_11`, `Y_12` a 100 MHz
- [ ] Calcular `C_self`, `L_self`, `C_mutual`, `M_mutual`, `G`
- [ ] Simular geometria com Pista 3 (Eve)
- [ ] Extrair `Y_13` e calcular `f_att`
- [ ] Verificar `|M_mutual| < |M_self|/2`
- [ ] Verificar `f^2 >= min_f_sq`
- [ ] Preencher `scripts/params.json` (ver script Python)
- [ ] Colar valores em `MaxwellKeyPLUS/Examples/TemplateRealParams.lean`
- [ ] Correr `lake build` e confirmar zero erros

---

## 8. Referências

1. COMSOL Multiphysics — *RF Module User's Guide*, v6.2.
2. OpenEMS — *Documentation*, https://openems.de/
3. Hammerstad, E. & Jensen, O. — "Accurate Models for Microstrip Computer-Aided Design." *IEEE MTT-S*, 1980.
4. Pozar, D. M. — *Microwave Engineering*, 4th Ed., Wiley, 2011.
5. MaxwellKey Project — `docs/` e `README.md` neste repositório.
