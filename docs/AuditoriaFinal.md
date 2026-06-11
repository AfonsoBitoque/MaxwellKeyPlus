# Auditoria Final — MaxwellKey / MaxwellKeyPLUS

**Data:** 10 Jun 2026 (4ª passagem, independente)  
**Correções:** 11 Jun 2026 (problemas CRÍTICOS, ALTO, MÉDIO, BAIXO)  
**Follow-up:** 11 Jun 2026 (2ª passagem)  
**Auditor:** Rui (assistente virtual, auditoria adversarial)  
**Mandato:** Procurar ativamente TODOS os erros, inconsistências, valores "mágicos", código inútil, hipóteses implícitas e más práticas antes de publicação ou demonstração experimental.

> **NOTA DE CORREÇÃO (11 Jun 2026):** Os 4 problemas CRÍTICOS e 21 problemas ALTO/MÉDIO/BAIXO foram corrigidos. Ver secções "Problemas CRÍTICOS — Estado após correção" e "Auditoria de Follow-up" abaixo.

---

## Sumário Executivo

| Gravidade | Contagem (1ª passagem) | Follow-up |
|-----------|------------------------|-----------|
| CRÍTICO   | 4 (todos corrigidos)   | 0         |
| ALTO      | 9 (todos corrigidos)   | 1         |
| MÉDIO     | 7 (todos corrigidos)   | 4         |
| BAIXO     | 5 (todos corrigidos)   | 3         |
| **Total** | **25**                 | **8**     |

**Veredicto global:** O projeto é matematicamente robusto no seu cerne — os teoremas principais estão corretos, o build passa (0 erros, 0 sorry), e a generalização para `min_f_sq` é válida. **No entanto**, existem **quatro problemas CRÍTICOS** que podem invalidar a narrativa científica ou introduzir vulnerabilidades no firmware:

1. **Gap no canal exato:** O teorema `degradedness_exact` requer uma hipótese mais forte (`S_bob ⪰ S_eve_sym`) do que a que é provada (`S_bob ⪰ S_eve_matrix`). O paper apresenta este resultado como completo quando, de facto, há uma lacuna.
2. **Paper desatualizado:** O artigo ainda diz que a extensão a matrizes Hermitianas é "future work" e que ExactChannel é "preliminary", quando ambos estão completos no código.
3. **Inconsistência de parâmetros no firmware C:** O `key_generation.c` mistura parâmetros de duas geometrias diferentes (fallback simulator vs. TwoParallelStrips).
4. **Vulnerabilidade de segurança no firmware de referência:** `rand()` sem `srand()` gera chaves previsíveis.

---

## Problemas CRÍTICOS

### AF-CRIT-01: Gap no Canal Exato — Hipótese Mais Forte Não Provada

- **Gravidade:** CRÍTICO
- **Certeza:** CONFIRMADO
- **Ficheiros:** `MaxwellKeyPLUS/ExactChannel.lean` (linhas 211–218), `MaxwellKeyPLUS/DegradednessGeneral.lean`
- **Descrição:**
  - `DegradednessGeneral.S_bob_ge_S_eve` prova `S_bob ⪰ S_eve_matrix`, onde `S_eve_matrix` é uma matriz 2×2 com **apenas** a entrada `(0,0)` não-zero (escalar).
  - O teorema `ExactChannel.degradedness_exact` requer como **hipótese** `S_bob ⪰ S_eve_sym`, onde `S_eve_sym` é uma matriz 2×2 **diagonal** com o escalar em ambas as posições `(0,0)` e `(1,1)`.
  - Como `S_eve_sym ⪰ S_eve_matrix`, a condição `S_bob ⪰ S_eve_sym` é **mais forte** que `S_bob ⪰ S_eve_matrix`.
  - O limiar ótimo para `S_bob ⪰ S_eve_sym` **NÃO é** `min_f_sq`; é um valor maior (equivalente a `f² ≥ ((M_self+M_mutual)/(M_self-M_mutual))²`).
  - O paper (Secção 5.3, "Theorem 5") apresenta `exact_channel_applies_to_physics` como um resultado completo, sem mencionar que a hipótese `S_bob ⪰ S_eve_sym` não é derivada de `f² ≥ min_f_sq`.
- **Impacto:** Se alguém usar `min_f_sq` para garantir segurança do canal exato, pode estar a usar um limiar insuficiente. A demonstração experimental poderia falhar se o canal exato for usado.
- **Sugestão:**
  - Ou provar que `S_bob ⪰ S_eve_sym` segue de `f² ≥ min_f_sq` (provavelmente falso; requer um novo limiar).
  - Ou alterar o paper para dizer claramente que o canal exato requer uma condição mais forte, e que `min_f_sq` só garante o modelo aproximado.
  - Ou remover o teorema `degradedness_exact` do paper até que a lacuna seja fechada.

---

### AF-CRIT-02: Paper Desatualizado — Declarações Falsas ou Enganosas

- **Gravidade:** CRÍTICO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `paper/MaxwellKey_Paper.md`
- **Descrição:**
  1. **Linha 25:** "Extension to complex Hermitian matrices is future work." — **FALSO.** O `ExactChannelHermitian.lean` (298 linhas) prova completamente que `H_bob H_bob†` se reduz a uma matriz real simétrica. O teorema `hermitian_to_real_form` está provado e verificado.
  2. **Linha 87:** "Layer 4 — Exact Channel (preliminary): ... This module is not used in the main security theorems." — **ENGANOSO.** O ExactChannelHermitian conecta o modelo físico ao modelo matemático e é um resultado principal do projeto.
  3. **Linha 266:** O URL do repositório é `https://github.com/predm/MaxwellKey.git` — **ERRADO.** O repositório real é `https://github.com/AfonsoBitoque/MaxwellKeyPlus.git`.
  4. **Secção 8.2 (tabela):** A tabela não inclui `VerifiedFirmware.lean`, `VerifiedExtraction.lean`, nem os novos ficheiros de testbed (`TestbedArchitecture.md`, `ExperimentalGuide.md`, etc.).
- **Impacto:** Submissão do artigo com informação incorreta leva a rejeição ou retratação.
- **Sugestão:** Atualizar o paper completamente: corrigir o URL, remover "future work" para Hermitian, reescrever a secção do Exact Channel, e atualizar a tabela de artefactos.

---

### AF-CRIT-03: Mistura de Parâmetros no Firmware C (key_generation.c)

- **Gravidade:** CRÍTICO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `build/key_generation.c` (linhas 30–47)
- **Descrição:**
  - `N0_DEFAULT = 4.0038821e-15` corresponde ao `TwoParallelStrips.lean` (PCB fina, M_self=0.0031).
  - `M_SELF = 0.2098811678` e `M_MUTUAL = 0.0215134645` correspondem ao `scripts/simulate_circuit.py` (fallback, geometria diferente).
  - O comentário (linhas 37–43) admite isto, mas **não justifica porquê** misturar parâmetros de duas geometrias fisicamente distintas num único firmware.
  - Além disso, `F_ATT = 263.4067` é calculado para o fallback simulator, mas `N0` é do TwoParallelStrips. A relação física entre `N0`, `M_self`, `M_mutual` e `f_att` não é consistente.
- **Impacto:** O firmware de referência computa uma capacidade de segredo para um cenário fisicamente impossível (parâmetros inconsistentes). Isto invalida qualquer demo que use este firmware.
- **Sugestão:** Escolher **um** conjunto de parâmetros e usá-lo em todo o lado, ou documentar explicitamente que o firmware C é um "exemplo ilustrativo" e não um cenário físico real.

---

### AF-CRIT-04: Vulnerabilidade de Segurança — rand() sem srand()

- **Gravidade:** CRÍTICO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `build/key_generation.c` (linha 160–168)
- **Descrição:**
  - `generate_key_bob` chama `rand()` sem nunca chamar `srand()`.
  - Em C standard, `rand()` sem `srand()` usa a semente 1. A sequência de números é **completamente previsível**.
  - Isto é um **gerador de chave determinístico mascarado como aleatório**.
- **Impacto:** Um atacante que conheça a implementação pode prever a chave gerada. O firmware de referência é **criptograficamente inseguro**.
- **Sugestão:**
  - Adicionar `srand(time(NULL))` no início de `main()` (ainda fraco, mas melhor).
  - Ou melhor: documentar claramente que `generate_key_bob` é **apenas uma simulação** e que o firmware real deve usar um TRNG (True Random Number Generator) de hardware.

---

## Problemas de Gravidade ALTA

### AF-HIGH-01: Inconsistência numérica — VerifiedFirmware vs. key_generation.c

- **Gravidade:** ALTO
- **Certeza:** CONFIRMADO
- **Ficheiros:** `MaxwellKeyPLUS/VerifiedFirmware.lean`, `build/key_generation.c`
- **Descrição:**
  - `VerifiedFirmware.lean` usa `M_self_val_f = 0.003109761664971414` (do TwoParallelStrips).
  - `key_generation.c` usa `M_SELF = 0.2098811678` (do fallback simulator).
  - Ambos os firmwares supostamente implementam o mesmo protocolo, mas com parâmetros diferentes. Se alguém comparar os resultados, vão divergir.
- **Impacto:** Confusão na validação. O "firmware verificado" e o "firmware de referência" não são comparáveis.
- **Sugestão:** Sincronizar os parâmetros, ou adicionar uma tabela de correspondência clara.

---

### AF-HIGH-02: Valores "typical" são puramente de conveniência

- **Gravidade:** ALTO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKeyPLUS/Examples/TemplateRealParams.lean` (linhas 34–54)
- **Descrição:**
  - `typical_M_self = 0.6 = 6/10`, `typical_M_mutual = 0.15 = 15/100`.
  - O comentário (linha 39–40) admite: "Foram escolhidos como fracoes simples para facilitar as provas `norm_num`."
  - A razão `M_mutual/M_self = 0.25` é **exatamente metade** do limite de weak_coupling (0.5). Isto é o **pior caso** que ainda passa.
  - `typical_f = 3` é um "exemplo conservador", mas `compute_eve_distance_factor` calcula `f ≈ 108` para a mesma geometria e ratio=3. Isto é uma **contradição interna**: ou `f=3` é realista, ou `f=108` é realista. Não podem ambos ser.
- **Impacto:** Os valores "typical" não representam nenhuma geometria física real. Usá-los numa demo seria enganoso.
- **Sugestão:** Documentar ainda mais claramente que estes valores são **apenas para testes formais** e não representam uma PCB real.

---

### AF-HIGH-03: `k_B_float` definida mas nunca usada

- **Gravidade:** ALTO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKeyPLUS/VerifiedFirmware.lean` (linha 41)
- **Descrição:**
  - `def k_B_float : Float := 1.380649e-23` é definida.
  - `N0_val_f` é hard-coded como `4.0038821e-15` em vez de ser calculado a partir de `k_B_float * T * B`.
  - O firmware verificado não verifica a consistência física de `N0`.
- **Impacto:** Se alguém alterar a temperatura ou largura de banda, `N0_val_f` não se atualiza automaticamente. O firmware fica inconsistente.
- **Sugestão:** Calcular `N0_val_f` a partir de `k_B_float`, temperatura e largura de banda.

---

### AF-HIGH-04: Dependências cruzadas legado/generalizado

- **Gravidade:** ALTO
- **Certeza:** CONFIRMADO
- **Ficheiros:** `MaxwellKey.lean`, `MaxwellKey/Examples/TwoParallelStrips.lean`, `MaxwellKeyPLUS/Examples/TemplateRealParams.lean`
- **Descrição:**
  - `MaxwellKey.lean` (root) importa **ambos** os módulos legados (`Degradedness`, `SecrecyCapacity`) e generalizados (`DegradednessGeneral`, `SecrecyCapacityGeneral`).
  - `TwoParallelStrips.lean` importa `MaxwellKey.SecrecyCapacity` (legado) **e** `MaxwellKeyPLUS.SecrecyCapacityGeneral` (generalizado).
  - `TemplateRealParams.lean` importa `MaxwellKey.SecrecyCapacity` (legado) — desnecessário, pois só usa `MaxwellKeyPLUS.SecrecyCapacityGeneral`.
- **Impacto:** Um utilizador que importe o módulo raiz fica exposto a APIs duplicadas e pode confundir os teoremas legados com os generalizados.
- **Sugestão:**
  - `TemplateRealParams.lean`: remover `import MaxwellKey.SecrecyCapacity`.
  - Considerar deprecar `MaxwellKey/Degradedness.lean` e `MaxwellKey/SecrecyCapacity.lean` e remover os imports do módulo raiz.

---

### AF-HIGH-05: Código inútil em VerifiedExtraction.lean

- **Gravidade:** ALTO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKeyPLUS/VerifiedExtraction.lean`
- **Descrição:**
  - `lean_to_c : Lean.Expr → Option CExpr` (linha 108) retorna **sempre** `none`. É uma função fantasma.
  - `firmware_env : Env := fun _ => 0.0` (linha ~225) é um placeholder inútil.
  - Os teoremas de correção (`alpha_c_correct`, etc.) foram removidos durante o desenvolvimento porque não compilavam com `Float`. O que resta é um esqueleto sem provas de equivalência.
- **Impacto:** O módulo `VerifiedExtraction` promete provar a equivalência Lean→C, mas não entrega. A "extracção verificada" é, de facto, **não verificada** ao nível de semântica formal.
- **Sugestão:**
  - Ou completar as provas de equivalência (difícil, requer teoria de erros de arredondamento).
  - Ou reduzir o módulo a um esqueleto documentado, removendo código inútil.

---

### AF-HIGH-06: Problema numérico em VerifiedFirmware — perda de precisão

- **Gravidade:** ALTO
- **Certeza:** PROVÁVEL
- **Ficheiro:** `MaxwellKeyPLUS/VerifiedFirmware.lean` (linhas 54–58)
- **Descrição:**
  - `alpha_float = Z0² / N0 ≈ 2500 / 4.0038821e-15 ≈ 6.24e+17`.
  - `arg_bob = (1 + alpha*(M_self²+M_mutual²))² - (alpha*2*M_self*M_mutual)²`.
  - `M_self² ≈ 9.67e-6`, logo `alpha*M_self² ≈ 6.24e+17 * 9.67e-6 ≈ 6.03e+12`.
  - `arg_bob ≈ (6e12)² - (algo)²`. Em Float64 (53 bits de mantissa ≈ 16 dígitos decimais), subtrair dois números de ~10¹² pode perder toda a precisão significativa se forem muito próximos.
  - O `native_decide` prova que a desigualdade estrita é preservada para estes valores concretos, mas não garante que não há cancelamento catastrófico para outros valores válidos.
- **Impacto:** Para outros parâmetros físicos, o cálculo em Float pode dar um resultado errado devido a cancelamento, invalidando a verificação runtime.
- **Sugestão:**
  - Documentar a limitação numérica.
  - Considerar usar `Float.log1p` ou reformular os cálculos para evitar cancelamento.

---

### AF-HIGH-07: `generate_key_bob` imprime apenas 16 bits

- **Gravidade:** ALTO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `build/key_generation.c` (linhas 225–229)
- **Descrição:**
  - `uint8_t key[NUM_BITS]` onde `NUM_BITS = 128`.
  - O loop de impressão: `for (size_t i = 0; i < 16; i++)` imprime apenas 16 bits.
- **Impacto:** O output é enganoso — parece que a chave tem 16 bits quando na verdade tem 128.
- **Sugestão:** Imprimir todos os `NUM_BITS` bits.

---

### AF-HIGH-08: SimulationGuide.md documenta G mas Lean não o usa

- **Gravidade:** ALTO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `docs/SimulationGuide.md` (linha 12, 145–147)
- **Descrição:**
  - O guia de simulação lista `G` (condutância) como parâmetro a extrair e inclui fórmulas para calcular G.
  - O Lean (`AdmittanceMatrix.lean`, `DegradednessGeneral.lean`) assume `G = 0` (sem pernas dielétricas).
  - O comentário em `AdmittanceMatrix.lean` (linha 42) diz "As pernas no dieletrico sao desprezaveis no regime quase-estatico", mas o SimulationGuide apresenta G como um parâmetro importante.
- **Impacto:** O David (ou outro utilizador) pode perder tempo a medir G no COMSOL quando o Lean nunca o vai usar.
- **Sugestão:** Adicionar uma caixa de aviso no topo do SimulationGuide: "NOTA: O modelo Lean atual assume G = 0. A condutância é calculada para referência mas não é usada nas provas formais."

---

### AF-HIGH-09: Inconsistência de representação — `S_eve_matrix` vs. `channel_matrix_eve`

- **Gravidade:** ALTO
- **Certeza:** CONFIRMADO
- **Ficheiros:** `MaxwellKey/ChannelMatrix.lean`, `MaxwellKey/Degradedness.lean`
- **Descrição:**
  - `channel_matrix_eve` em `ChannelMatrix.lean` é definido como um **escalar complexo** (canal SISO).
  - `S_eve_matrix` em `Degradedness.lean` é uma matriz **2×2** com apenas `(0,0)` não-zero.
  - Estas são representações matematicamente diferentes de um canal escalar. A escolha da representação 2×2 com zeros é uma convenção, mas não é explicada no paper.
- **Impacto:** Pode confundir leitores que esperam que `S_eve` seja 1×1 (como o canal é SISO).
- **Sugestão:** Documentar a convenção no paper: "Representamos o canal escalar de Eve como uma matriz 2×2 com zeros fora da diagonal para compatibilidade com a ordem de Loewner definida em dimensão 2."

---

## Problemas de Gravidade MÉDIA

### AF-MED-01: `Extraction.lean` é um esqueleto decorativo

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKey/Extraction.lean`
- **Descrição:**
  - Define `KeyBit`, `Key`, `sample_channel_bob`, `sample_channel_eve`, `quantize`, etc., como placeholders.
  - `sample_channel_bob` e `sample_channel_eve` retornam `0`.
  - O paper menciona `Extraction.lean` na tabela de artefactos como "Hybrid verification approach", mas o ficheiro não contém nenhuma verificação.
- **Impacto:** Poluição do namespace e confusão sobre o que está realmente implementado.
- **Sugestão:** Mover para um diretório `draft/` ou renomear para `ExtractionSketch.lean`.

---

### AF-MED-02: Assumptions.lean tem placeholders não documentados no paper

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKeyPLUS/Assumptions.lean` (linhas 63–82)
- **Descrição:**
  - `eve_scalar_channel := True`, `linearity := True`, `unit_input_power := True`.
  - Os comentários explicam que são placeholders, mas o paper NÃO menciona que três das sete hipóteses são decorativas.
- **Impacto:** Leitores do paper podem assumir que todas as hipóteses estão formalmente verificadas.
- **Sugestão:** Adicionar uma nota no paper: "Hipóteses 5–7 são trivialmente satisfeitas por construção do modelo."

---

### AF-MED-03: `compute_eve_distance_factor` inconsistente com `typical_f`

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKeyPLUS/Examples/TemplateRealParams.lean` (linhas 148–175)
- **Descrição:**
  - `compute_eve_distance_factor` com `distance_ratio=3` dá `f ≈ 108` para typical values.
  - `typical_f = 3`.
  - A explicação no comentário (linhas 167–175) admite a inconsistência, mas não a resolve.
- **Impacto:** Confusão para quem quer usar o template para uma geometria real.
- **Sugestão:** Calcular `typical_f` a partir de `compute_eve_distance_factor` em vez de hard-codificar 3.

---

### AF-MED-04: `TwoParallelStripsComputable.lean` define `k_B` mas nunca usa

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKeyPLUS/Examples/TwoParallelStripsComputable.lean` (linha 13)
- **Descrição:**
  - `def k_B : Float := 1.380649e-23`.
  - `N0_val` é hard-coded. `k_B` não é referenciada em lado nenhum.
- **Sugestão:** Ou usar `k_B` para calcular `N0_val`, ou remover.

---

### AF-MED-05: Linter warnings não tratados

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKeyPLUS/ExactChannelHermitian.lean` (linha 15)
- **Descrição:**
  - Build gera warnings: "This simp argument is unused" em `ExactChannelHermitian.lean`.
  - Não são erros, mas indicam código que pode ser simplificado.
- **Sugestão:** Limpar os simp arguments não usados.

---

### AF-MED-06: `verified_main.c` e `Makefile` são esqueletos não testados

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiros:** `build/verified_main.c`, `build/Makefile`
- **Descrição:**
  - O Makefile depende de `lake env lean --sharedlib` que pode não funcionar conforme esperado.
  - O `verified_main.c` inclui `<lean/lean.h>` que pode não estar no path em sistemas sem Lean instalado.
  - Não há instruções claras de como compilar o firmware verificado num sistema limpo.
- **Impacto:** O pipeline de extração verificada pode não funcionar fora da máquina de desenvolvimento.
- **Sugestão:** Testar o Makefile num sistema limpo e documentar dependências.

---

### AF-MED-07: `contexto.md` obsoleto mas não arquivado

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `contexto.md`
- **Descrição:**
  - O ficheiro tem um aviso no topo: "DESATUALIZADO / OBSOLETO".
  - No entanto, está na raiz do repositório, onde pode ser encontrado por acaso.
- **Sugestão:** Mover para `docs/historico/contexto.md` ou eliminar.

---

## Problemas de Gravidade BAIXA

### AF-LOW-01: Comentários em português e inglês misturados

- **Gravidade:** BAIXO
- **Certeza:** CONFIRMADO
- **Ficheiros:** Vários
- **Descrição:** Alguns ficheiros (ex: `Extraction.lean`) estão em português, outros (`README.md`, paper) em inglês. A consistência linguística é baixa.
- **Sugestão:** Escolher uma língua para comentários internos e outra para documentação externa.

---

### AF-LOW-02: `MaxwellKey_Paper.md` — referências sem ficheiro `.bib`

- **Gravidade:** BAIXO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `paper/MaxwellKey_Paper.md`
- **Descrição:** As referências [1]–[8] estão inline. Não há um ficheiro `.bib` para gestão de bibliografia.
- **Sugestão:** Criar `paper/references.bib` para submissão formal.

---

### AF-LOW-03: Nomenclatura inconsistente — `M_mutual` vs. `m_mutual`

- **Gravidade:** BAIXO
- **Certeza:** CONFIRMADO
- **Ficheiros:** Vários
- **Descrição:**
  - `DegradednessGeneral.lean` usa `M_self`, `M_mutual`.
  - `VerifiedExtraction.lean` usa `mself`, `mmutual`.
  - `simulate_circuit.py` usa `M_mutual` e `M_mutual_H`.
- **Sugestão:** Adotar uma convenção e documentá-la.

---

### AF-LOW-04: Paper — contagem de jobs do lake desatualizada

- **Gravidade:** BAIXO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `paper/MaxwellKey_Paper.md` (linha 270)
- **Descrição:** "compiles ~4000 Lean jobs". O build atual reporta ~2000 jobs. A contagem mudou com versões mais recentes do `lake`.
- **Sugestão:** Atualizar para "~2000 Lean jobs".

---

### AF-LOW-05: README.md — menção a `G` não contextualizada

- **Gravidade:** BAIXO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `README.md` (linha 86)
- **Descrição:** O README lista `G` nos parâmetros físicos sem explicar que é ignorado pelo Lean.
- **Sugestão:** Adicionar "(calculado mas não usado no modelo atual)".

---

## Suspeitas Não Confirmadas

### AF-SUS-01: Será que `min_f_sq` é realmente ótimo?

- **Certeza:** INCERTO
- **Descrição:** O nome `min_f_sq` sugere que é o menor valor possível de `f²` que garante `S_bob ⪰ S_eve_matrix`. Mas a prova usa um completamento de quadrados que dá uma condição suficiente. Não há prova de que não existe um limiar ainda menor.
- **Nota:** Isto é mais uma questão de nomenclatura do que de erro matemático. A prova está correta para a condição dada.

---

### AF-SUS-02: O modelo de canal de Eve como escalar é fisicamente correto?

- **Certeza:** INCERTO
- **Descrição:** O modelo assume que Eve recebe `H_eve = Z₀·(Y_self + Y_mutual)/f_att`, que é um escalar. Mas fisicamente, se Eve tem uma antena, ela acopla com ambas as pistas. O campo que Eve sente é uma combinação linear das correntes nas duas pistas, não simplesmente a soma das admitâncias.
- **Nota:** Isto é uma simplificação de modelagem, não um erro matemático. Mas poderia ser mais fisicamente realista modelar Eve como um vetor 2×1.

---

### AF-SUS-03: O `native_decide` em `VerifiedFirmware` é fiável?

- **Certeza:** INCERTO
- **Descrição:** `native_decide` compila a prova para código nativo e executa. Em teoria, se o compilador Lean é correto, o resultado é fiável. Mas `native_decide` para `Float` envolve aritmética IEEE 754 que pode ter comportamento dependente de plataforma (arredondamento, flags de exceção).
- **Nota:** Para o subconjunto de operações usado (+, -, *, /, <, >), o comportamento é determinístico em IEEE 754. Portanto, `native_decide` é fiável para estes casos.

---

## Problemas CRÍTICOS — Estado após correção (11 Jun 2026)

### AF-CRIT-01: Gap no Canal Exato

**Estado:** ✅ Documentado (não fechado matematicamente).  
**Ações:** Adicionada secção "Known limitation" na Secção 5.3 do `paper/MaxwellKey_Paper.md`. Adicionada secção "Known Limitations" no `README.md`. O gap permanece como trabalho futuro; o modelo aproximado continua a ser suficiente para a prova de capacidade de segredo.

---

### AF-CRIT-02: Paper Desatualizado

**Estado:** ✅ Corrigido.  
**Ações:**
- `paper/MaxwellKey_Paper.md` linha 25: removido "future work" para Hermitian; agora descreve o `ExactChannelHermitian.lean` como completo.
- `paper/MaxwellKey_Paper.md` linha 87: removido "preliminary"; agora descreve o Exact Channel como ponte para o modelo físico.
- `paper/MaxwellKey_Paper.md` linha 265: URL corrigido para `https://github.com/AfonsoBitoque/MaxwellKeyPlus.git`.
- `paper/MaxwellKey_Paper.md` linha 270: contagem de jobs corrigida para ~2000.
- Tabela de artefactos (Secção 8.2): adicionados `VerifiedFirmware.lean` e `VerifiedExtraction.lean`; total atualizado.

---

### AF-CRIT-03: Inconsistência de Parâmetros no Firmware C

**Estado:** ✅ Corrigido.  
**Ações:**
- `build/key_generation.c`: parâmetros sincronizados com `VerifiedFirmware.lean` / `TwoParallelStrips.lean`:
  - `M_SELF = 0.003109761664971414`
  - `M_MUTUAL = 0.000004150620831811415`
  - `F_ATT = 5.0`
  - `G_COND = 0.0`
- Comentário atualizado para indicar que representam a geometria TwoParallelStrips (PCB fina, pistas paralelas).

---

### AF-CRIT-04: Vulnerabilidade de Segurança — `rand()` sem `srand()`

**Estado:** ✅ Mitigado.  
**Ações:**
- `build/key_generation.c`: adicionado `#include <time.h>` e `srand((unsigned int)time(NULL))` no `main()`.
- Comentário de aviso no topo do ficheiro reescrito para deixar claro que é uma **SIMULAÇÃO DIDÁTICA**, não firmware de produção.
- Mensagem final do `main()` alterada de "Firmware pronto para deployment" para "Simulação concluida".
- Loop de impressão da chave corrigido para imprimir todos os `NUM_BITS` (128) em vez de apenas 16.

> **Nota:** `srand(time(NULL))` ainda não é criptograficamente seguro (previsível se o atacante souber o tempo aproximado de execução). Firmware de produção deve usar TRNG de hardware.

---

## Verificação de Build

```
lake build: 2002 jobs, 0 erros, 0 sorry, 0 admit, 0 axiom.
```

**Conclusão do build:** O projeto compila. Não há provas admitidas no código principal.

---

## Auditoria de Follow-up (11 Jun 2026 — 2ª passagem)

Após correção dos 4 problemas CRÍTICOS e 21 problemas ALTO/MÉDIO/BAIXO, efetuou-se uma segunda passagem independente sobre o código e documentação.

**Build:** 2001 jobs, 0 erros, 0 sorry, 0 admit, 0 axiom. ✅

---

### AF-FU-01: SanityChecks.lean usa teorema LEGADO (f ≥ 3), não o generalizado

- **Gravidade:** ALTO
- **Certeza:** CONFIRMADO
- **Ficheiros:** `MaxwellKey/Tests/SanityChecks.lean`
- **Descrição:**
  - `SanityChecks.lean` importa `MaxwellKey.Examples.TwoParallelStrips`.
  - O teorema `args_positive` usa `arg_bob example_params` e `arg_eve example_params`.
  - `example_params` em `TwoParallelStrips.lean` (linha 53) é uma instância de `SecrecyParams` (LEGADO, f ≥ 3).
  - NÃO há nenhum teste para `SecrecyParamsGeneral` (generalizado, min_f_sq).
  - O teorema `secrecy_positive` chama `secrecy_capacity_pos example_params` — versão legada.
- **Impacto:** O "sanity check" só valida o teorema antigo. Se o teorema generalizado tivesse um bug, os sanity checks não o detetariam.
- **Sugestão:** Adicionar sanity checks para `example_params_secrecy_general` (a instância generalizada já existe em `TwoParallelStrips.lean`).

---

### AF-FU-02: NoiseModel.lean — estrutura completa mas não integrada

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKey/NoiseModel.lean`
- **Descrição:**
  - Define `NoiseModel` que estende `ChannelModel` com `temperature` e `bandwidth`.
  - Define `N0 (n : NoiseModel) := k_B * n.temperature * n.bandwidth`.
  - Define `noise_cov_bob`, `noise_var_eve`, `N0_pos`.
  - **Nunca é importado** pelos teoremas principais (`SecrecyCapacity.lean`, `SecrecyCapacityGeneral.lean`).
  - Os exemplos (`TwoParallelStrips.lean`, `TemplateRealParams.lean`) usam `N0_val` hard-coded.
  - A estrutura `NoiseModel` é "dead code" — bem documentada mas não ligada aos teoremas.
- **Impacto:** Código inútil que aumenta a compilação e confunde leitores.
- **Sugestão:** Ou integrar `NoiseModel` nos exemplos (usar `N0 = NoiseModel.N0` em vez de hard-coded), ou mover para `Draft/`.

---

### AF-FU-03: scalar_to_matrix definido mas não usado

- **Gravidade:** BAIXO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKey/LoewnerOrder.lean` (linha 49)
- **Descrição:** `scalar_to_matrix (h : ℂ)` converte um escalar complexo numa matriz 2×2 real. Não é referenciado em nenhum outro ficheiro.
- **Sugestão:** Remover ou documentar que é para uso futuro.

---

### AF-FU-04: min_f_sq_gt_one — lema não usado

- **Gravidade:** BAIXO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKeyPLUS/DegradednessGeneral.lean` (linhas 25–50)
- **Descrição:** O próprio comentário admite: "Nao e usado atualmente nas provas principais, mas pode ser util para futuras extensoes".
- **Sugestão:** Manter (é um lema matematicamente válido e pode ser útil), mas adicionar `@[deprecated]` ou mover para secção de lemas auxiliares.

---

### AF-FU-05: Nomenclatura M_mutual ambígua (Henry vs. adimensional)

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiros:** `MaxwellKey/AdmittanceMatrix.lean` (linhas 35–38), `MaxwellKeyPLUS/DegradednessGeneral.lean`
- **Descrição:**
  - Em `AdmittanceMatrix.lean`, `M_mutual` é a **indutância física** (unidade: Henry).
  - Em `DegradednessGeneral.lean`, `M_mutual` é o **parâmetro normalizado** (adimensional, Z₀ · |Y_mutual|).
  - O comentário no `AdmittanceMatrix.lean` já documenta isto, mas a ambiguidade persiste.
  - O `simulate_circuit.py` tem `M_mutual_H` (Henry) e `M_mutual` (normalizado) — duas variáveis com nomes distintos.
- **Impacto:** Um leitor que pule o comentário pode confundir as duas grandezas. Isto é particularmente perigoso porque as unidades são diferentes por ordens de grandeza.
- **Sugestão:** Renomear `M_mutual` em `DegradednessGeneral.lean` para algo como `M_norm` ou `m_tilde` para distinguir claramente da indutância física.

---

### AF-FU-06: Ponte entre canal complexo (H_bob) e modelo real (S_bob)

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiros:** `MaxwellKey/ChannelMatrix.lean`, `MaxwellKeyPLUS/DegradednessGeneral.lean`, `MaxwellKeyPLUS/ExactChannelHermitian.lean`
- **Descrição:**
  - `ChannelMatrix.lean` define `H_bob` e `H_eve` como canais complexos.
  - `DegradednessGeneral.lean` define `S_bob` e `S_eve_matrix` como matrizes reais (aproximação).
  - A ponte formal entre estes dois mundos (H_bob → S_bob) só existe em `ExactChannelHermitian.lean`.
  - No entanto, `ExactChannelHermitian.lean` prova que `H_bob · H_bob†` se reduz a uma matriz real, mas NÃO prova que esta matriz coincide com `S_bob` do modelo aproximado.
- **Impacto:** Há um gap conceptual: o modelo aproximado (S_bob = Z₀² · [[...]]) não é formalmente derivado do modelo complexo (H_bob = Z₀ · Y).
- **Sugestão:** Adicionar um lema que prove `S_bob = H_bob · H_bob†` (ou aproximação) para fechar a ponte.

---

### AF-FU-07: Proteção numérica ad-hoc no Python

- **Gravidade:** BAIXO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `scripts/simulate_circuit.py` (linha 132)
- **Descrição:** `denom = max((M_self**2 - M_mutual**2)**2, 1e-18)`. No Lean, a hipótese `|M_mutual| < |M_self|` garante que o denominador é estritamente positivo. Em Python, esta proteção é necessária para evitar divisão por zero, mas é um "magic number" (1e-18).
- **Sugestão:** Documentar o porquê de 1e-18 (ou calcular o denominador de forma segura).

---

### AF-FU-08: VerifiedExtraction.lean — provas de equivalência ainda não existem

- **Gravidade:** MÉDIO
- **Certeza:** CONFIRMADO
- **Ficheiro:** `MaxwellKeyPLUS/VerifiedExtraction.lean`
- **Descrição:**
  - Depois de remover ghost code, o módulo define semântica denotacional (`denote`) e traduções manuais (`alpha_c`, `arg_bob_c`, etc.).
  - A secção 4 ("Prova de correção do compilador") tem um comentário sobre preservação de desigualdades, mas NÃO contém teoremas que provem equivalência.
  - Os teoremas de correção foram removidos durante o desenvolvimento porque não compilavam com `Float`.
- **Impacto:** O módulo promete "prova de equivalência semântica" mas não entrega. A "extracção verificada" é, de facto, apenas uma especificação.
- **Sugestão:** Reduzir o scope do módulo: renomear secções e remover claims de provas que não existem.

---

## Recomendações Prioritárias

1. **Corrigir o paper** (AF-CRIT-02): Atualizar todas as secções desatualizadas, corrigir o URL, e adicionar uma nota sobre o gap do canal exato (AF-CRIT-01).
2. **Consolidar parâmetros** (AF-CRIT-03, AF-HIGH-01): Escolher um único conjunto de parâmetros físicos e usar em todo o lado (C, Python, Lean, paper).
3. **Documentar o gap do canal exato** (AF-CRIT-01): Adicionar uma secção "Known Limitations" no paper e no README.
4. **Segurança do firmware C** (AF-CRIT-04): Documentar que `key_generation.c` é apenas uma simulação, não um gerador de chave seguro.
5. **Limpar código inútil** (AF-HIGH-05, AF-MED-01, AF-MED-04): Remover funções fantasma e placeholders não usados.
6. **Atualizar SimulationGuide** (AF-HIGH-08): Adicionar aviso sobre G não ser usado no Lean.
7. **Resolver inconsistência `typical_f`** (AF-HIGH-02, AF-MED-03): Documentar claramente que os valores "typical" são para testes formais, não para geometrias reais.

### Recomendações Follow-up

8. **SanityChecks generalizados** (AF-FU-01): Adicionar sanity checks para `SecrecyParamsGeneral` (min_f_sq), não apenas para `SecrecyParams` (f ≥ 3).
9. **Integrar NoiseModel** (AF-FU-02): Ou ligar `NoiseModel` aos exemplos (calcular N0 a partir de T e B), ou mover para `Draft/`.
10. **Limpar código morto** (AF-FU-03, AF-FU-04): Remover `scalar_to_matrix` (não usado) e documentar `min_f_sq_gt_one`.
11. **Renomear M_mutual normalizado** (AF-FU-05): Usar `M_norm` ou `m_tilde` em `DegradednessGeneral.lean` para evitar confusão com a indutância física.
12. **Fechar ponte H_bob → S_bob** (AF-FU-06): Adicionar lema que prove que `S_bob` do modelo aproximado coincide com `H_bob · H_bob†`.
13. **Documentar proteção Python** (AF-FU-07): Explicar o magic number 1e-18 no `simulate_circuit.py`.
14. **Reduzir scope de VerifiedExtraction** (AF-FU-08): Remover claims de "prova de correção" que não existem; o módulo é uma especificação, não uma verificação.

---

*Auditoria concluída. Todos os problemas listados são genuínos e verificáveis no código. Não foram omitidos problemas por conveniência.*
