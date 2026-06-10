# Relatório de Auditoria Hostil — MaxwellKey / MaxwellKeyPLUS

**Data:** 2026-06-09
**Auditor:** Revisão sistemática de todos os artefactos (Lean 4, Python, C, Markdown)
**Escopo:** `MaxwellKey/`, `MaxwellKeyPLUS/`, `scripts/`, `build/`, `paper/`, `docs/`, `README.md`
**Conclusão:** O projeto está sólido na sua fundação, mas contém 2 problemas críticos/altos que exigem correção antes da submissão.

---

## Sumário de Problemas

| ID | Gravidade | Ficheiro | Descrição |
|----|-----------|----------|-----------|
| A1 | **CRÍTICO** | `DegradednessGeneral.lean`, `TemplateRealParams.lean` | Parâmetro fantasma `G` — não afeta nenhuma matriz nem teorema |
| A2 | **ALTO** | `ExactChannel.lean` | Prova aplica-se a matrizes reais; conexão com o modelo físico complexo não está estabelecida |
| A3 | **ALTO** | `contexto.md` vs código | Documentação promete Loewner sobre matrizes Hermitianas; código implementa sobre matrizes reais |
| A4 | **MÉDIO** | `TwoParallelStrips.lean` | Usa o teorema antigo (`f ≥ 3`), não a generalização `min_f_sq` |
| A5 | **MÉDIO** | `TemplateRealParams.lean` | Valores "typical" são frações convenientes, não necessariamente realistas |
| A6 | **BAIXO** | `build/key_generation.c` | Código escrito manualmente, não extraído do Lean |
| A7 | **BAIXO** | `TemplateRealParams.lean:173` | Variável `h_pos` não utilizada (linter warning) |

---

## Análise Detalhada

### A1 [CRÍTICO] — Parâmetro fantasma `G`

**Ficheiros:** `DegradednessGeneral.lean` (linhas 121-132), `TemplateRealParams.lean` (linhas 50-54, 102-120)

**Descrição:** O parâmetro `G` (condutância de perdas no dielétrico) foi adicionado à estrutura `DegradednessParamsGeneral` e à função `create_params`, com a respetiva prova de positividade `h_G_pos`. No entanto, `G` não é utilizado em nenhuma definição subsequente:

- `S_bob` (linha 140-143) não usa `G`
- `S_eve_matrix` (linha 145-148) não usa `G`
- `min_f_sq` (linha 12-13) não usa `G`
- Nenhum lema ou teorema em `DegradednessGeneral.lean` referencia `G`

**Impacto:** A estrutura `DegradednessParamsGeneral` declara um campo que promete modelar perdas no dielétrico, mas esse campo é completamente ignorado pela matemática. Isto é enganador para leitores e revisores. O modelo com perdas é mais complexo (a matriz Y passa a ter parte real, H_bob deixa de ser puramente imaginário, S_bob = H_bob H_bob^† muda), e essa complexidade não está capturada.

**Correção sugerida:** Duas opções:
1. **Remover `G`** da estrutura e de `create_params`, com uma nota explicativa de que as perdas são modeladas como desprezáveis no regime quase-estático (aproximação válida para FR-4 a 100 MHz com tan δ = 0.02).
2. **Incorporar `G` corretamente:** redefinir `M_self` e `M_mutual` para incluir o efeito de G, derivar novas expressões para `S_bob` e `min_f_sq`, e reprovar os teoremas. Isto é trabalhoso e provavelmente desnecessário para a primeira publicação.

**Recomendação:** Opção 1. Adicionar justificação física no comentário do módulo.

---

### A2 [ALTO] — ExactChannel.lean: desconexão com o modelo físico

**Ficheiro:** `ExactChannel.lean` (298 linhas)

**Análise da prova `f_monotone_psd`:**

A prova é **internamente correta** para matrizes reais simétricas da forma `[[a,b],[b,a]]` com a,b ∈ ℝ. Os passos são:
1. Redução da ordem de Loewner a desigualdades escalares: `a₁+b₁ ≥ a₂+b₂` e `a₁-b₁ ≥ a₂-b₂`
2. Monotonia da função escalar `g(t) = 1 - 1/(1+t)` para `t > -1`
3. Composição: os "autovalores" de f(A) são g(a+b) e g(a-b)

Não há erro lógico nesta cadeia. O problema está na **aplicabilidade ao modelo físico:**

**O que o código faz:**
- `S_bob` (real, definida em `DegradednessParamsGeneral`) é convertida para `symm_matrix` via `S_bob_as_symm`
- `S_eve_sym` (real) é definida como `symm_matrix(s, 0)`
- `f_on_symm` é aplicada a estas matrizes reais
- O teorema `degradedness_exact` conclui `f(S_bob) ⪰ f(S_eve_sym)`

**O que o modelo físico exigiria:**
- A matriz de canal é `H_bob = Z₀·Y` (complexa, ℂ²ˣ²)
- A matriz de sinal verdadeira é `H_bob H_bob^†` (Hermitiana, ℂ²ˣ²)
- A matriz de SNR é `A = H_bob H_bob^† / N₀` (Hermitiana PSD)
- A transformação exata é `f(A) = I - (I+A)⁻¹` aplicada a A Hermitiana

**Gap:** `S_bob` (real) é uma aproximação de `|H_bob|²` (magnitude), não de `H_bob H_bob^†`. A conexão formal entre estas duas quantidades nunca é estabelecida. Além disso, a ordem de Loewner definida em `LoewnerOrder.lean` é para matrizes reais, não para matrizes Hermitianas complexas.

**Agravante com G:** Se `G > 0`, então `Y_self = G + jB_self` e `H_bob` tem parte real. Neste caso, `H_bob H_bob^†` tem elementos diagonais `Z₀²(G² + B_self² + B_mut²)` e off-diagonais `Z₀²(2G·B_mut + ...)`. A aproximação `S_bob` com elementos `Z₀²(M_self²+M_mutual²)` e `Z₀²(2·M_self·M_mutual)` não captura os termos cruzados com G.

**Veredicto:** O `ExactChannel.lean` é um exercício matemático válido sobre matrizes reais, mas a sua alegação de modelar o "canal exato" do MaxwellKey não está fundamentada. O teorema `degradedness_exact` é verdadeiro como stated (matrizes reais → matrizes reais), mas a sua interpretação física requer trabalho adicional.

**Impacto no resto do projeto:** Nenhum. `SecrecyCapacity.lean` não importa `ExactChannel.lean`. O teorema principal `secrecy_capacity_pos` não depende do canal exato.

**Correção sugerida:**
1. Adicionar uma nota explícita no início de `ExactChannel.lean` declarando que é um resultado sobre matrizes reais simétricas e que a conexão com o modelo físico completo (Hermitiano) é trabalho futuro.
2. No artigo, qualificar as afirmações sobre o canal exato como "resultado preliminar para matrizes reais" ou "prova de conceito".
3. Para uma versão futura, definir a ordem de Loewner para matrizes Hermitianas complexas e provar a monotonia nesse contexto.

---

### A3 [ALTO] — Discrepância documentação vs implementação

**Ficheiros:** `contexto.md` (linhas 18-22, 78-80) vs `LoewnerOrder.lean`, `Degradedness.lean`

**Documentação (`contexto.md`):**
```
H_bob H_bob^† ⪰ H_eve H_eve^†
```
"onde ⪰ é a ordem de Loewner para matrizes Hermitianas"

**Implementação (`LoewnerOrder.lean`):**
```lean
def Matrix.loewner_le (A B : Matrix (Fin 2) (Fin 2) ℝ) : Prop := ...
```
A ordem de Loewner está definida apenas para matrizes **reais**.

**Implementação (`Degradedness.lean`):**
```lean
def S_bob (p : DegradednessParams) : Matrix (Fin 2) (Fin 2) ℝ := ...
def S_eve_matrix (p : DegradednessParams) : Matrix (Fin 2) (Fin 2) ℝ := ...
```
As matrizes comparadas são **reais**, não Hermitianas complexas.

**Impacto:** A documentação promete um resultado mais forte (matrizes Hermitianas complexas) do que o código realmente prova (matrizes reais). Um revisor atento notará esta discrepância.

**Correção sugerida:** Atualizar `contexto.md` para refletir com precisão o que foi implementado, ou alternativamente expandir `LoewnerOrder.lean` para suportar matrizes Hermitianas complexas.

---

### A4 [MÉDIO] — TwoParallelStrips.lean usa teorema antigo

**Ficheiro:** `Examples/TwoParallelStrips.lean`

O exemplo concreto usa `SecrecyParams` (que estende `DegradednessParams` com `h_f_ge_three`), não `DegradednessParamsGeneral`. Portanto, este exemplo não demonstra a generalização `min_f_sq`, que é uma das contribuições do MaxwellKeyPLUS.

**Correção sugerida:** Criar um exemplo adicional que use `DegradednessParamsGeneral` e `min_f_sq`, ou atualizar o exemplo existente.

---

### A5 [MÉDIO] — Valores "typical" são frações convenientes

**Ficheiro:** `TemplateRealParams.lean` (linhas 42-48)

```lean
noncomputable def typical_M_self : ℝ := 6 / 10      -- 0.6
noncomputable def typical_M_mutual : ℝ := 15 / 100   -- 0.15
noncomputable def typical_f : ℝ := 3
```

Estes valores foram escolhidos como frações simples (6/10, 15/100) que tornam as provas `norm_num` triviais. No entanto:
- O rácio `M_mutual/M_self = 0.25` é o limite máximo permitido pela hipótese de acoplamento fraco (`|M_mutual| < |M_self|/2`). Isto é um "pior caso" artificial.
- Os valores do fallback simulator (M_self=0.21, M_mutual=0.022, rácio=0.10) são muito mais realistas.
- Os valores do TwoParallelStrips (M_self=0.0031, M_mutual=4.15e-6, rácio=0.0013) são ordens de grandeza menores.

**Risco:** Um revisor pode questionar se o valor 0.6/0.15 é fisicamente realista ou se foi escolhido apenas para conveniência da prova.

**Correção sugerida:** Adicionar uma nota explicando que os "typical" são valores de pior caso para demonstrar a robustez da prova, e referenciar os valores do fallback simulator como mais realistas.

---

### A6 [BAIXO] — Código C escrito manualmente

**Ficheiro:** `build/key_generation.c`

O ficheiro C foi escrito manualmente. Não há extração automática a partir do Lean 4. O artigo e o README referem-se a "extração de código", o que pode ser interpretado como extração automática.

**Correção sugerida:** Clarificar no artigo que o código C é uma tradução manual de referência, e que a extração automática é trabalho futuro.

---

### A7 [BAIXO] — Linter warning

**Ficheiro:** `TemplateRealParams.lean:173`

```lean
noncomputable def compute_eve_distance_factor (M_self M_mutual : ℝ)
    (h_weak : |M_mutual| < |M_self| / 2)
    (distance_ratio : ℝ) (h_pos : distance_ratio > 0) : ℝ :=
  |M_self / M_mutual| * distance_ratio^3
```

O parâmetro `h_pos` não é utilizado no corpo da função.

**Correção sugerida:** Remover o parâmetro ou usá-lo (ex: para garantir que distance_ratio^3 > 0).

---

## Verificações de Sanidade

| Verificação | Resultado |
|-------------|-----------|
| `grep "sorry" *.lean` | **0 ocorrências** |
| `grep "axiom" *.lean` | **0 ocorrências** |
| `grep "admit" *.lean` (tática) | **0 ocorrências** |
| `lake build` | **3966 jobs, 0 erros** |
| Consistência ℝ vs ℂ nas matrizes | S_bob e S_eve são ℝ; Y e H são ℂ. Consistente. |
| Simetria de Y | Provada (`admittance_symmetric`) |
| Simetria de S_bob | Por construção (elementos simétricos) |
| Positividade de N₀ | Provada (`N0_pos`) |
| `min_f_sq` bem definido | Denominador positivo provado (`min_f_sq_denom_pos`) |

---

## Análise Específica Solicitada pelo Utilizador

### "A matriz A = Z₀·Y é Hermitiana?"

**Não.** Y é simétrica mas não Hermitiana:
- `Y_self = jωC_self + 1/(jωL_self)` = `j(ωC_self - 1/(ωL_self))` — imaginário puro
- `conj(Y_self) = -Y_self ≠ Y_self` → diagonal não é real → não é Hermitiana

Com G > 0: `Y_self = G + jB_self` → diagonal é complexa (G + jB) → `conj(G+jB) = G-jB ≠ G+jB` → continua a não ser Hermitiana.

H_bob = Z₀·Y herda esta propriedade: é simétrica, não Hermitiana.

### "A prova f_monotone_psd utiliza a hipótese PSD; é satisfeita?"

A prova aplica-se a `S_bob` e `S_eve_sym`, que são matrizes **reais** simétricas. Para matrizes reais simétricas, PSD é equivalente a ter autovalores não-negativos. A prova verifica que `a+b ≥ 0` e `a-b ≥ 0` (os autovalores de `[[a,b],[b,a]]`).

Para `S_bob`: `a = Z₀²(M_self²+M_mutual²)`, `b = Z₀²(2·M_self·M_mutual)`
- `a+b = Z₀²(M_self+M_mutual)² ≥ 0` ✓
- `a-b = Z₀²(M_self-M_mutual)² ≥ 0` ✓

Para `S_eve_sym`: `a = Z₀²(M_self+M_mutual)²/f²`, `b = 0`
- `a+b = a ≥ 0` ✓
- `a-b = a ≥ 0` ✓

Ambas são PSD no sentido real. A prova é válida neste contexto.

### "A aproximação H_bob = Z₀·Y é suficiente?"

Sim. O teorema `secrecy_capacity_pos` não usa o canal exato. Usa a aproximação de primeira ordem S_bob (real). A aproximação é válida sob acoplamento fraco (`|M_mutual| ≪ |M_self|`), que é uma hipótese explícita do teorema.

---

## Conclusão Final

O projeto MaxwellKey está **sólido na sua fundação**. Os teoremas principais (degradedness, secrecy capacity > 0) são provados corretamente dentro do modelo de matrizes reais. Não há `sorry`, `axiom`, ou `admit` no código. O build é limpo (3966 jobs, 0 erros).

**No entanto, há 3 problemas que devem ser corrigidos antes da submissão:**

1. **[CRÍTICO] Remover ou incorporar corretamente o parâmetro fantasma `G`.** Na forma atual, `G` é um parâmetro decorativo que não afeta a matemática. Isto mina a credibilidade do modelo.

2. **[ALTO] Qualificar o ExactChannel.lean como resultado preliminar.** A prova é correta para matrizes reais, mas a alegação de "canal exato" não está fundamentada na física do problema. Adicionar uma nota explícita e ajustar o artigo.

3. **[ALTO] Alinhar documentação com implementação.** O `contexto.md` descreve um modelo mais ambicioso (matrizes Hermitianas) do que o implementado (matrizes reais). Atualizar para refletir a realidade do código.

**Recomendação:** Corrigir estes 3 pontos e o projeto estará pronto para submissão como artefacto de paper e para início da fase experimental. Nenhum destes problemas invalida a demonstração em hardware — o David pode prosseguir com a bancada usando os parâmetros do fallback simulator ou COMSOL.
