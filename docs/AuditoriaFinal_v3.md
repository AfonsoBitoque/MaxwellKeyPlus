# Auditoria Final Independente — MaxwellKey / MaxwellKeyPLUS (v3)

**Data:** 10 de Junho de 2026  
**Tipo:** Auditoria hostil independente — olhos novos, tudo suspeito  
**Build:** ✅ 2000 jobs, 0 erros  
**Classificação de certeza:** CONFIRMADO (verificável), PROVÁVEL (fortes indícios), POSSÍVEL (suspeita), INCERTO (intuição)

---

## Sumário Executivo

| Gravidade | Quantidade | IDs |
|-----------|-----------|-----|
| CRÍTICO | 1 | AF-CORE-01 |
| ALTO | 2 | AF-CORE-02, AF-CORE-03 |
| MÉDIO | 3 | AF-CORE-04, AF-CORE-05, AF-CORE-06 |
| BAIXO | 2 | AF-CORE-07, AF-CORE-08 |

**Conclusão:** A auditoria anterior (v2) concentrou-se em problemas superficiais (N₀ inconsistente, README desatualizado) e ignorou um problema **estrutural e matemático grave**: o **teorema principal da biblioteca core (`secrecy_capacity_pos`) ainda usa o limiar conservador `f ≥ 3`**, não o limiar ótimo `min_f_sq`. O `SecrecyCapacityGeneral.lean` existe como módulo separado mas nunca substituiu o teorema principal. O `contexto.md` é uma especificação fantasista que não corresponde ao projeto real. O build passa, mas a arquitetura formal está quebrada.

---

## Problema CRÍTICO

### AF-CORE-01 [CRÍTICO] [CONFIRMADO] — O teorema principal `secrecy_capacity_pos` usa o limiar antigo `f ≥ 3`, não `min_f_sq`

**Localização:** `MaxwellKey/SecrecyCapacity.lean:22,27,103`

**Descrição detalhada:**

O ficheiro `SecrecyCapacity.lean` é o módulo que contém o **teorema principal** do projeto:

```lean
-- Linha 22: importa o módulo ANTIGO (f >= 3)
import MaxwellKey.Degradedness

-- Linha 27: estende a estrutura ANTIGA
structure SecrecyParams extends DegradednessParams where

-- Linha 103: usa a hipótese antiga na prova
have hf2 : p.f^2 ≥ 9 := by nlinarith [p.h_f_ge_three]
```

O `DegradednessParams` (definido em `Degradedness.lean`) contém `h_f_ge_three : f >= 3`. O teorema `secrecy_capacity_pos` depende desta hipótese para provar `arg_bob > arg_eve`.

**Existe `SecrecyCapacityGeneral.lean`** (em `MaxwellKeyPLUS/`) que define `SecrecyParamsGeneral extends DegradednessParamsGeneral` e prova `secrecy_capacity_pos` com `min_f_sq`. Mas:
- **Não é importado por `MaxwellKey.lean`** (raiz da biblioteca core)
- **Não é usado por `TwoParallelStrips.lean`** no exemplo principal de capacidade de segredo
- **O README lista `SecrecyCapacity` como o módulo do "Main theorem"**, não `SecrecyCapacityGeneral`
- **O paper afirma que o projeto usa `min_f_sq`**, mas o teorema principal da biblioteca ainda usa `f ≥ 3`

**Impacto:** A afirmação central do projeto — "generalizamos o limiar de f ≥ 3 para min_f_sq" — é **falsa para o teorema principal**. O `SecrecyCapacityGeneral` existe mas é um módulo órfão que nunca substituiu o teorema principal. Um revisor que compile o projeto e verifique `secrecy_capacity_pos` verá que ele ainda requer `f ≥ 3`.

**Correção obrigatória:**
1. `MaxwellKey.lean` deve importar `SecrecyCapacityGeneral` em vez de `SecrecyCapacity` (ou ambos, com documentação clara)
2. `TwoParallelStrips.lean` deve criar um `example_params_general_secrecy` (SecrecyParamsGeneral) e verificar `secrecy_capacity_pos` generalizado
3. O README deve listar `SecrecyCapacityGeneral` como o módulo do teorema principal
4. Idealmente: `SecrecyCapacity.lean` deve ser marcado como `[LEGADO]` e `SecrecyCapacityGeneral.lean` como o módulo principal

---

## Problemas ALTOS

### AF-CORE-02 [ALTO] [CONFIRMADO] — `contexto.md` é uma especificação fantasista que não corresponde ao projeto real

**Localização:** `contexto.md` (raiz do projeto)

**Descrição detalhada:**

O ficheiro `contexto.md` descreve uma arquitetura de projeto que **não existe**:

| O que `contexto.md` diz | O que existe realmente |
|-------------------------|------------------------|
| `EMInfo/Reciprocity.lean` | ❌ Não existe |
| `AdmittanceMonad/EPM.lean` | ❌ Não existe |
| `AdmittanceMonad/AMI.lean` | ❌ Não existe |
| `AdmittanceMonad/NoisyChannelMonad.lean` | ❌ Não existe |
| `Examples/KeyExtraction.lean` | ❌ Não existe |
| `Tests/COMSOL_Validation.lean` | ❌ Não existe |
| `Tests/Simulation.lean` | ❌ Renomeado para `SanityChecks.lean` |
| "Extrai código executável" | ❌ É tradução manual |
| Teorema 2 (`ami_equiv`) | ❌ Não existe |
| Teorema 5 (`extracted_protocol_correct`) | ❌ Não existe |
| `Degradedness.lean` → `H_bob H_bob† ⪰ H_eve H_eve†` | ❌ Prova `S_bob ⪰ S_eve_matrix`, não `H_bob H_bob†` |

**Impacto:** Este ficheiro é enganador. Alguém que o leia pensará que o projeto tem módulos que não existem e capacidades que não foram implementadas.

**Correção sugerida:** Renomear para `contexto.md.ANTIGO` ou reescrever completamente para refletir o estado real do projeto.

---

### AF-CORE-03 [ALTO] [CONFIRMADO] — `TwoParallelStrips.lean` verifica o teorema antigo como "principal"

**Localização:** `MaxwellKey/Examples/TwoParallelStrips.lean:52-67`

**Descrição:**

O ficheiro contém:
```lean
def example_params : SecrecyParams where   -- usa o ANTIGO (f >= 3)
  ...

lemma secrecy_pos_applies :
    secrecy_capacity example_params > 0 :=   -- verifica o ANTIGO
  secrecy_capacity_pos example_params
```

Embora exista `example_params_general` (DegradednessParamsGeneral, linha 93), **não existe** um exemplo de `SecrecyParamsGeneral` que verifique a capacidade de segredo com o limiar `min_f_sq`.

**Impacto:** O exemplo principal do projeto demonstra o teorema obsoleto. Não há um exemplo concreto que mostre a capacidade de segredo positiva com o limiar ótimo `min_f_sq`.

**Correção sugerida:** Adicionar `example_params_secrecy_general : SecrecyParamsGeneral` e `secrecy_pos_general_applies` em `TwoParallelStrips.lean`.

---

## Problemas MÉDIOS

### AF-CORE-04 [MÉDIO] [CONFIRMADO] — `ExactChannelHermitian.lean` é um módulo isolado não integrado

**Localização:** `MaxwellKeyPLUS/ExactChannelHermitian.lean`

**Descrição:** O ficheiro prova que `H_bob H_bob†` reduz-se a uma matriz real simétrica. A prova está completa e correta. No entanto:
- Nunca é usado para provar `degradedness_loewner` ou `secrecy_capacity_pos`
- A cadeia de provas que leva ao teorema principal não passa por este módulo
- O teorema `exact_channel_applies_to_physics` requer a hipótese `h_le` (ordem de Loewner) como argumento, mas não há um teorema que prove esta hipótese a partir do modelo físico

**Impacto:** A conexão entre o modelo físico complexo e a prova de monotonia é formalmente provada, mas não integrada na cadeia de provas que leva à segurança.

---

### AF-CORE-05 [MÉDIO] [CONFIRMADO] — `MaxwellKey.lean` (raiz) ainda importa o módulo legado `Degradedness`

**Localização:** `MaxwellKey.lean:6`

**Descrição:**
```lean
import MaxwellKey.Degradedness
import MaxwellKey.SecrecyCapacity
```

A raiz da biblioteca core importa os módulos legados (`Degradedness`, `SecrecyCapacity`) em vez dos generalizados (`DegradednessGeneral`, `SecrecyCapacityGeneral`). Embora o `MaxwellKeyPLUS.lean` importe os módulos PLUS, o core não os referencia.

**Impacto:** O build do core produz teoremas com o limiar antigo. Um utilizador que faça `import MaxwellKey` terá acesso ao teorema obsoleto, não ao generalizado.

---

### AF-CORE-06 [MÉDIO] [CONFIRMADO] — Código C mistura parâmetros de duas geometrias diferentes

**Localização:** `build/key_generation.c:31-44`

**Descrição:**
- `N0_DEFAULT = 4.0038821e-15` — vem de `TwoParallelStrips.lean` (geometria fina)
- `M_SELF = 0.2098811678`, `M_MUTUAL = 0.0215134645` — vêm do fallback simulator (`params.json`, geometria diferente)

**Impacto:** O firmware usa N0 de uma geometria e M_self/M_mutual de outra. Embora o teorema seja robusto, isto significa que o exemplo do C não corresponde a nenhuma geometria física específica — é uma mistura.

---

## Problemas BAIXOS

### AF-CORE-07 [BAIXO] [CONFIRMADO] — Nomenclatura `M_mutual` ambígua entre Lean e Python

**Localização:** `scripts/simulate_circuit.py:124` vs `MaxwellKey/DegradednessGeneral.lean`

**Descrição:**
- No Python: `M_mutual_H` é a indutância mútua em Henry
- No Lean: `M_mutual` é o parâmetro normalizado (adimensional, `Z0 * |Y_mutual|`)

A documentação não clarifica suficientemente esta distinção. O `SimulationGuide.md` menciona a normalização, mas os comentários no código não são explícitos.

---

### AF-CORE-08 [BAIXO] [CONFIRMADO] — `Degradedness.lean` é importado pelo core apesar de ser "legado"

**Localização:** `MaxwellKey.lean:6`

**Descrição:** Embora o ficheiro tenha sido marcado como `[LEGADO / OBSOLETO]` no topo, continua a ser importado e compilado pela raiz da biblioteca. A única forma de verdadeiramente deprecá-lo seria removê-lo do `MaxwellKey.lean` e movê-lo para uma pasta `Legacy/`.

---

## Verificações de Rotina

| Verificação | Resultado |
|-------------|-----------|
| `grep "sorry" *.lean` | 0 ocorrências ✅ |
| `grep "axiom" *.lean` | 0 ocorrências ✅ |
| `grep "admit" *.lean` (tática) | 0 ocorrências ✅ |
| `lake build` | ✅ 2000 jobs, 0 erros |
| `ExactChannelHermitian.lean` compila? | ✅ Sim |
| `SecrecyCapacityGeneral.lean` compila? | ✅ Sim |
| Teorema principal usa `min_f_sq`? | ❌ NÃO — usa `f ≥ 3` |

---

## Veredicto Final

**O projeto compila sem erros, mas a arquitetura formal está quebrada.**

O problema mais grave (**AF-CORE-01**) é que o **teorema principal `secrecy_capacity_pos`** (em `MaxwellKey/SecrecyCapacity.lean`) ainda usa o limiar conservador `f ≥ 3`. O módulo `SecrecyCapacityGeneral.lean` (com `min_f_sq`) existe mas nunca substituiu o teorema principal. Isto significa que:

1. A afirmação "generalizamos o limiar" é verdadeira para `DegradednessGeneral.lean` mas **falsa para o teorema principal de capacidade de segredo**.
2. O `TwoParallelStrips.lean` demonstra o teorema obsoleto como exemplo principal.
3. O `MaxwellKey.lean` (raiz) exporta o teorema obsoleto.

**Recomendações para publicação (por ordem de prioridade):**

1. **🔴 URGENTE:** Integrar `SecrecyCapacityGeneral.lean` como módulo principal. Adicionar `example_params_secrecy_general` em `TwoParallelStrips.lean`.
2. **🟠 ALTO:** Marcar `contexto.md` como desatualizado ou reescrevê-lo. Remove-lo da raiz para evitar confusão.
3. **🟡 MÉDIO:** Unificar os parâmetros no C (ou usar N0 correspondente aos M_SELF/M_MUTUAL do fallback, ou vice-versa).
4. **🟢 BAIXO:** Considerar mover `Degradedness.lean` e `SecrecyCapacity.lean` para uma pasta `Legacy/` e remover os imports do core.

**O build passa, mas a contribuição matemática principal não está integrada na biblioteca core.**

---

*Auditoria independente conduzida por Kimi. INOVATION, 10 de Junho de 2026.*
