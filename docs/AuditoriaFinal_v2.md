# Auditoria Final — MaxwellKey / MaxwellKeyPLUS (v2)

**Data:** 10 de Junho de 2026  
**Tipo:** Auditoria hostil completa — todos os artefactos  
**Estado do build:** ✅ 2000 jobs, 0 erros  
**Classificação de certeza:** CONFIRMADO (verificável), PROVÁVEL (fortes indícios), POSSÍVEL (suspeita), INCERTO (intuição)

---

## Sumário Executivo

| Gravidade | Quantidade | IDs |
|-----------|-----------|-----|
| CRÍTICO | 1 | AF-01 |
| ALTO | 4 | AF-02, AF-03, AF-04, AF-05 |
| MÉDIO | 5 | AF-06, AF-07, AF-08, AF-09, AF-10 |
| BAIXO | 5 | AF-11, AF-12, AF-13, AF-14, AF-15 |

**Conclusão:** O projeto compila sem erros, mas tem 1 problema CRÍTICO de consistência física (N₀ no C vs Lean), 4 problemas ALTOS de inconsistência entre documentação/código, e 10 problemas médios/baixos. O núcleo matemático é sólido, mas a integração experimental e a documentação precisam de atenção antes da publicação.

---

## Problemas CRÍTICOS

### AF-01 [CRÍTICO] [CONFIRMADO] — `N0` no código C (`key_generation.c`) é inconsistente com o Lean

**Localização:** `build/key_generation.c:26` vs `MaxwellKey/Examples/TwoParallelStrips.lean:42` / `scripts/params.json:6`

**Descrição:** O código C define:
```c
#define N0_DEFAULT   1.0e-9   /* Densidade espectral de ruído (W/Hz) */
```

Mas o Lean usa:
```lean
def N0_val : ℝ := 4.0038821e-15   -- TwoParallelStrips.lean:42
```

E o `params.json` exporta:
```json
"N0": 4.0038821e-15
```

A discrepância é de **6 ordens de magnitude** (1e-9 vs 4e-15). Isto significa que:
- `alpha = Z0² / N0` no C: `2500 / 1e-9 = 2.5e12`
- `alpha` no Lean: `2500 / 4e-15 = 6.25e17`

As capacidades calculadas no C serão drasticamente diferentes das do Lean. O firmware de referência não está sincronizado com o modelo formal.

**Impacto:** O firmware de referência calcula capacidades de segredo incorretas. Se o David usar o C como base para o hardware, os valores não corresponderão às garantias formais.

**Correção sugerida:**
1. Alterar `N0_DEFAULT` no C para `4.0038821e-15` (ou ler do `params.json`)
2. Adicionar comentário no C indicando que o valor deve ser sincronizado com o Lean
3. Idealmente: o C deveria ler `params.json` em runtime

---

## Problemas ALTOS

### AF-02 [ALTO] [CONFIRMADO] — Valores de `M_self`/`M_mutual` inconsistentes entre C, Python e Lean

**Localização:** Múltiplos ficheiros

**Descrição:** Cada componente do projeto usa valores diferentes para os mesmos parâmetros:

| Fonte | M_self | M_mutual | Ratio |
|-------|--------|----------|-------|
| `TwoParallelStrips.lean` | 0.003109761664971414 | 0.000004150620831811415 | ~0.0013 |
| `TwoParallelStripsComputable.lean` | 0.003109761664971414 | 0.000004150620831811415 | ~0.0013 |
| `scripts/params.json` | 0.20988116783269223 | 0.021513464513514543 | ~0.10 |
| `build/key_generation.c` | 0.2098811678 | 0.0215134645 | ~0.10 |
| `TemplateRealParams.lean` (typical) | 0.6 | 0.15 | 0.25 |
| `TemplateRealParams.lean` (fallback) | 0.21 | 0.022 | ~0.10 |

**Problemas:**
1. O Lean tem **duas geometrias diferentes** com o mesmo nome: `TwoParallelStrips` (valores pequenos, ~0.003) e `TemplateRealParams` fallback (valores médios, ~0.21)
2. O C e o `params.json` usam valores médios (~0.21)
3. Os valores "typical" (0.6, 0.15) são **artificiais** (escolhidos para `norm_num`)
4. Não há um único conjunto de referência coerente

**Impacto:** Impossível reproduzir resultados. Cada componente dá números diferentes. Um revisor não consegue verificar se os exemplos são realistas.

**Correção sugerida:**
1. Escolher UM conjunto de parâmetros de referência (recomendo os do `params.json`, que são fisicamente derivados)
2. Atualizar `TwoParallelStrips.lean` para usar os mesmos valores
3. Documentar claramente que os "typical" são apenas para testes de `norm_num`

---

### AF-03 [ALTO] [CONFIRMADO] — README desatualizado e com referências inexistentes

**Localização:** `README.md:96`, estrutura do repositório

**Descrição:** O README afirma:
```
├── Main.lean                       # Entry point
```

Mas `Main.lean` **não existe**. Os ficheiros raiz são `MaxwellKey.lean` e `MaxwellKeyPLUS.lean`.

Além disso, o README não menciona:
- `SecrecyCapacityGeneral.lean` (módulo importante)
- `ExactChannelHermitian.lean` (módulo importante)
- `Assumptions.lean` (manifesto de hipóteses)

**Impacto:** Documentação enganadora. Novos utilizadores não encontram o ficheiro `Main.lean`.

**Correção sugerida:** Atualizar a estrutura do repositório no README, remover `Main.lean`, adicionar os módulos PLUS.

---

### AF-04 [ALTO] [PROVÁVEL] — Discrepância entre `S_eve_matrix` e `S_eve_sym`

**Localização:** `DegradednessGeneral.lean:144-148` vs `ExactChannel.lean:210-212`

**Descrição:** Duas definições diferentes para a matriz de Eve:
- `DegradednessParamsGeneral.S_eve_matrix`: escalar em `(0,0)` → `[[s, 0], [0, 0]]`
- `ExactChannel.S_eve_sym`: escalar na diagonal → `[[s, 0], [0, s]]`

A condição `S_bob ⪰ S_eve_sym` é **mais forte** que `S_bob ⪰ S_eve_matrix`. O canal exato (`ExactChannel.degradedness_exact`) requer a hipótese mais forte. Não há prova formal de que a hipótese mais fraca (`DegradednessGeneral`) implica a mais forte.

**Impacto:** Gap lógico entre o teorema de degradedness generalizado e a aplicação do canal exato.

**Correção sugerida:** Unificar as definições ou adicionar lema de implicação.

---

### AF-05 [ALTO] [CONFIRMADO] — `TemplateRealParams.lean` tem comentário matematicamente inconsistente sobre `f`

**Localização:** `TemplateRealParams.lean:155-160`

**Descrição:** O comentário diz:
```
Para d_eve / d_bob = 3: f ≈ (0.6/0.15) · 27 = 4 · 27 = 108.
No entanto, na prática o decaimento não é exactamente 1/d³
devido ao substrato PCB, logo usamos f ≈ 3 como conservador.
```

O cálculo analítico dá **f = 108**, mas o valor "conservador" usado é **f = 3**. A diferença é de um fator **36×**. Se o cálculo teórico dá 108, usar 3 não é "conservador" — é completamente diferente e sem justificação física.

**Impacto:** Os valores "typical" (f=3, M_self=0.6, M_mutual=0.15) parecem ter sido escolhidos independentemente. Não há uma história coerente.

**Correção sugerida:** Remover o comentário confuso ou explicar porque 3 é fisicamente justificado.

---

## Problemas MÉDIOS

### AF-06 [MÉDIO] [CONFIRMADO] — `Assumptions.lean` tem hipóteses decorativas

**Localização:** `Assumptions.lean:58-67`

**Descrição:** Três "hipóteses" são definidas como `True`:
```lean
def eve_scalar_channel : Prop := True
def linearity : Prop := True
def unit_input_power : Prop := True
```

Isto é tecnicamente válido em Lean (qualquer prova de `True` é trivial), mas como "manifesto formal de hipóteses" é enganador. Não são hipóteses — são placeholders.

**Impacto:** Um leitor pode pensar que estas propriedades foram formalmente especificadas, quando na verdade são vazias.

**Correção sugerida:** Ou adicionar conteúdo real (ex: definições de linearidade), ou remover e documentar no paper.

---

### AF-07 [MÉDIO] [CONFIRMADO] — `SecrecyCapacityGeneral.lean` é "órfão"

**Localização:** `MaxwellKeyPLUS.lean:6`

**Descrição:** `SecrecyCapacityGeneral.lean` é importado em `MaxwellKeyPLUS.lean` mas **nunca é usado** por nenhum outro módulo. Não há teoremas que o referenciem, não é usado em exemplos, e o teorema principal `arg_bob_gt_arg_eve_general` não é aplicado em lado nenhum.

**Impacto:** Código morto. O trabalho de generalizar `arg_bob_gt_arg_eve` para `min_f_sq` não foi integrado.

**Correção sugerida:** Criar um exemplo que use `SecrecyCapacityGeneral`, ou integrar no `TemplateRealParams`.

---

### AF-08 [MÉDIO] [CONFIRMADO] — `Extraction.lean` tem teorema trivial e código não computável

**Localização:** `Extraction.lean:89-91`

**Descrição:** O teorema `key_agreement_succeeds_det` é:
```lean
theorem key_agreement_succeeds_det (c : ChannelModel) (n : ℕ) :
    generate_key_bob c n = generate_key_bob c n := rfl
```

Isto é `A = A`, provado por reflexividade. Não diz nada sobre segurança.

Além disso, `generate_key_bob` usa `List.replicate` com o mesmo bit, gerando uma chave de `n` bits **todos iguais**.

**Impacto:** O protocolo de extração é um esqueleto não funcional. Não gera chaves secretas reais.

**Correção sugerida:** Adicionar nota clara de que é um esqueleto, ou implementar protocolo probabilístico.

---

### AF-09 [MÉDIO] [CONFIRMADO] — `Simulation.lean` é um placeholder sem simulação

**Localização:** `MaxwellKey/Tests/Simulation.lean`

**Descrição:** O ficheiro contém apenas:
```lean
def num_trials : ℕ := 10000
def sim_bandwidth : ℝ := 1e6
theorem args_positive : arg_bob example_params > 0 ∧ arg_eve example_params > 0
theorem secrecy_positive : secrecy_capacity example_params > 0
```

Não há simulação Monte Carlo. Não há geração de ruído. Não há cálculo de BER.

**Impacto:** O diretório `Tests/` sugere testes, mas não há testes.

**Correção sugerida:** Renomear para `SanityChecks.lean` ou adicionar simulação real (em Python, se Lean não tiver PRNG).

---

### AF-10 [MÉDIO] [POSSÍVEL] — Valores "typical" escolhidos por conveniência, não por realismo físico

**Localização:** `TemplateRealParams.lean:36-44`

**Descrição:** Os valores `typical_M_self = 6/10` e `typical_M_mutual = 15/100` foram escolhidos como frações simples (6/10, 15/100). O comentário no próprio ficheiro admite:
> "Foram escolhidos como frações simples (6/10, 15/100) para facilitar as provas norm_num."

Comparando com valores fisicamente estimados:
- Fallback simulator: ratio ~0.10
- TwoParallelStrips: ratio ~0.0013
- Typical: ratio = 0.25 (limite máximo permitido)

**Impacto:** Os exemplos "typical" representam o **pior caso** (acoplamento máximo permitido), não um caso típico. Isto pode confundir um revisor.

**Correção sugerida:** Renomear `typical_*` para `worst_case_*` ou `test_*`, e criar `typical_*` com valores do fallback simulator.

---

## Problemas BAIXOS

### AF-11 [BAIXO] [CONFIRMADO] — `paper_outline.md` está desatualizado e duplicado

**Localização:** `MaxwellKeyPLUS/paper_outline.md`

**Descrição:** Ficheiro antigo que menciona `G = 1e-5 S` (parâmetro removido) e usa fórmulas diferentes do artigo final. Duplica parcialmente `paper/MaxwellKey_Paper.md`.

**Correção sugerida:** Marcar como `[OBSOLETO]` ou remover.

---

### AF-12 [BAIXO] [CONFIRMADO] — `MaxwellKey/Degradedness.lean` tem código duplicado

**Localização:** `MaxwellKey/Degradedness.lean`

**Descrição:** O módulo antigo (`f ≥ 3`) é funcionalmente redundante com `DegradednessGeneral`. A única diferença é o limiar (`9` vs `min_f_sq`). O código poderia ser eliminado e substituído por uma instanciação de `DegradednessGeneral` com `f² = 9`.

**Correção sugerida:** Manter para retrocompatibilidade, mas documentar que é obsoleto.

---

### AF-13 [BAIXO] [CONFIRMADO] — `Min_f_sq_gt_one` nunca é usado

**Localização:** `DegradednessGeneral.lean:22`

**Descrição:** O lema `min_f_sq_gt_one` prova que `min_f_sq > 1` sob certas condições, mas nunca é referenciado.

**Correção sugerida:** Usar na prova generalizada de `arg_bob_gt_arg_eve`, ou remover.

---

### AF-14 [BAIXO] [CONFIRMADO] — Comentário de `h_f_sq_ge_min` em `DegradednessParamsGeneral` tem prova inline complexa

**Localização:** `DegradednessGeneral.lean:128-131`

**Descrição:** A estrutura `DegradednessParamsGeneral` contém uma prova `by` inline no campo `h_f_sq_ge_min`:
```lean
h_f_sq_ge_min : f^2 ≥ min_f_sq M_self M_mutual (by
  have h1 : |M_mutual| < |M_self| / 2 := h_weak
  have h2 : |M_mutual| < |M_self| := by nlinarith [h1, abs_nonneg M_self]
  exact h2)
```

Isto é uma prova dentro de uma definição de estrutura, o que é válido mas não é boa prática. Dificulta a leitura.

**Correção sugerida:** Extrair para um lema auxiliar `weak_coupling_implies_lt_self`.

---

### AF-15 [BAIXO] [INCERTO] — Script Python pode calcular `M_self`/`M_mutual` incorretamente

**Localização:** `scripts/simulate_circuit.py:127-130`

**Descrição:** O Python calcula:
```python
Y_self_mag = abs(omega * C_self - 1.0/(omega * L_self))
Y_mutual_mag = abs(1.0/(omega * M_mutual_H) - omega * C_mutual)
M_self = Z0_term * Y_self_mag
M_mutual = Z0_term * Y_mutual_mag
```

Mas no modelo Lean (`AdmittanceMatrix.lean`):
```lean
Y_self = Complex.I * omega * C_self + 1 / (Complex.I * omega * L_self)
Y_mutual = -Complex.I * omega * C_mutual - 1 / (Complex.I * omega * M_mutual)
```

O Python usa `abs(omega*C_self - 1/(omega*L_self))`, que é o valor absoluto da parte imaginária de `Y_self`. O Lean modela `Y_self` como complexo. A magnitude de `Y_self` seria `abs(omega*C_self - 1/(omega*L_self))` se a parte real fosse zero, o que é verdade no modelo ideal (sem condutância G).

**Impacto:** Se o modelo físico incluir G (parte real), o Python subestima a magnitude de Y.

**Correção sugerida:** Documentar que o Python assume G=0.

---

## Suspeitas Não Confirmadas

1. **O `min_f_sq` é realmente ótimo (tight)?** Provamos que `f² ≥ min_f_sq` é suficiente para degradedness. Mas não provamos que é necessário — i.e., se `f² < min_f_sq`, a degradedness falha para algum vetor `x`. A afirmação "ótimo" no paper pode ser exagerada.

2. **A aproximação `H_bob = Z₀·Y` é valida para todos os parâmetros?** O comentário em `ChannelMatrix.lean` diz que é "aproximação de primeira ordem para acoplamento fraco". Mas não há uma estimativa formal do erro desta aproximação.

3. **A matriz `S_bob` realmente corresponde a `H_bob H_bob^†`?** O `ExactChannelHermitian.lean` agora compila (foi corrigido), mas a conexão entre o modelo físico e a matriz real depende de múltiplas simplificações algébricas. Uma verificação numérica independente seria valiosa.

4. **O `contexto.md` ainda é relevante?** Este ficheiro existe na raiz do projeto. Pode estar desatualizado.

5. **A função `compute_all_params` no Python usa `tan_delta = 0.02`**, mas o Lean ignora G. As perdas no dielétrico são realmente desprezáveis? Para `C_self = 6.68 pF`, `f = 100 MHz`, `G = 2*pi*f*C*tan_delta = 8.4e-5 S`. A admitância reativa é `omega*C = 4.2e-3 S`. O rácio `G/omega*C = 0.02` (2%). Não é completamente desprezável.

---

## Verificações de Rotina (Atualizadas)

| Verificação | Resultado |
|-------------|-----------|
| `grep "sorry" *.lean` (código) | 0 ocorrências |
| `grep "axiom" *.lean` | 0 ocorrências |
| `grep "admit" *.lean` (tática) | 0 ocorrências |
| `lake build` | ✅ 2000 jobs, 0 erros |
| Imports cíclicos | Nenhum detectado |
| `MaxwellKey` depende de `MaxwellKeyPLUS`? | Não |
| `MaxwellKeyPLUS` depende de `MaxwellKey`? | Sim (LoewnerOrder, etc.) |
| `ExactChannelHermitian.lean` compila? | ✅ Sim (foi corrigido) |
| `SecrecyCapacityGeneral.lean` compila? | ✅ Sim (foi corrigido) |

---

## Veredicto Final

**O projeto compila e os teoremas principais são matematicamente sólidos.** As provas de `degradedness_loewner_general`, `f_monotone_psd`, e `arg_bob_gt_arg_eve` estão corretas. Não há `sorry` nem `axiom`.

**No entanto, há 1 problema CRÍTICO que impede a demonstração experimental:**
- **AF-01:** O firmware C usa `N0 = 1e-9`, inconsistente com o Lean (`N0 = 4e-15`). As capacidades calculadas serão erradas.

**E 4 problemas ALTOS de inconsistência:**
- **AF-02:** Valores de parâmetros diferentes em cada componente (Lean, C, Python, typical)
- **AF-03:** README com referências inexistentes (`Main.lean`)
- **AF-04:** Gap entre `S_eve_matrix` e `S_eve_sym`
- **AF-05:** Inconsistência numérica no comentário de `f`

**Recomendação para publicação:**
1. Corrigir AF-01 (sincronizar N₀ entre C e Lean)
2. Unificar os valores de parâmetros (AF-02)
3. Atualizar README (AF-03)
4. Documentar o gap S_eve_matrix/S_eve_sym (AF-04)
5. Corrigir comentário confuso sobre f (AF-05)

**Recomendação para demonstração experimental:**
- Prioridade máxima: AF-01 (o hardware não pode usar N0 errado)
- Depois: AF-02 (usar um único conjunto de parâmetros)

---

*Auditoria conduzida por Kimi. INOVATION, 10 de Junho de 2026.*
