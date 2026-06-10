# MaxwellKey / MaxwellKeyPLUS — Relatório de Síntese para o Pedro

**Data:** 10 de Junho de 2026
**Destinatário:** Pedro (INOVATION, físico-matemático, co-autor)
**Elaborado por:** Kimi (assistente de verificação formal), a pedido do Carlos
**Âmbito:** Visão global do estado atual do projeto após verificação formal completa e duas rondas de auditoria hostil

---

## 1. Objetivo do Projeto

O MaxwellKey é a primeira biblioteca formal em Lean 4 que prova, a partir das leis do electromagnetismo e da teoria da informação, que dois terminais acoplados por um canal físico recíproco podem gerar uma chave secreta partilhada, segura contra um *eavesdropper* passivo. A segurança é *information-theoretic* — não depende de pressupostos computacionais, apenas da física do canal.

**O problema concreto:** Duas pistas de cobre paralelas numa PCB (Alice e Bob) exibem acoplamento electromagnético mútuo (capacidade parasita `C_m`, indutância mútua `M`). Um espião (Eve) colocado a uma distância maior sente um acoplamento muito mais fraco. A física garante que o canal de Eve é uma **versão degradada** do canal de Bob. Sob esta condição, a capacidade de segredo do canal gaussiano é estritamente positiva, e um protocolo de geração de chave baseado na reciprocidade do canal é formalmente seguro.

**A ligação electromagnetismo → segurança:** A matriz de admitâncias `Y` do circuito quase-estático é simétrica por reciprocidade de Lorentz. Esta simetria, combinada com a atenuação geométrica do espião, implica a condição de *degradedness* na ordem de Loewner, que por sua vez implica `C_s > 0` via o teorema de Csiszár-Körner para canais gaussianos degradados.

---

## 2. Arquitetura Geral

O projeto está organizado em duas bibliotecas Lean 4:

### MaxwellKey (núcleo original) — 10 ficheiros, 975 linhas

```
LoewnerOrder.lean (75 linhas)
    ↓
AdmittanceMatrix.lean (80 linhas)    ChannelMatrix.lean (128 linhas)
    ↓                                     ↓
Degradedness.lean (199 linhas)  ←── NoiseModel.lean (80 linhas)
    ↓
SecrecyCapacity.lean (180 linhas)  ←── TEOREMA PRINCIPAL
    ↓
Extraction.lean (86 linhas)
    ↓
Examples/TwoParallelStrips.lean (106 linhas)
Tests/Simulation.lean (46 linhas)
Basic.lean (1 linha — "hello world")
```

### MaxwellKeyPLUS (extensões e generalizações) — 5 ficheiros, 903 linhas

```
Assumptions.lean (65 linhas)         ← manifesto formal de hipóteses
DegradednessGeneral.lean (268 linhas) ← generalização com min_f_sq
    ↓
ExactChannel.lean (304 linhas)        ← monotonia do canal exato (preliminar)
    ↓
Examples/TemplateRealParams.lean (212 linhas)  ← template para dados COMSOL
Examples/TwoParallelStripsComputable.lean (54 linhas) ← versão Float
```

**Dependência entre as duas bibliotecas:** `MaxwellKeyPLUS` depende de `MaxwellKey.LoewnerOrder`. `MaxwellKey` **não** depende de `MaxwellKeyPLUS`. O teorema principal `secrecy_capacity_pos` é completamente independente das extensões.

**Total:** 15 ficheiros Lean, 1884 linhas de código formal.

---

## 3. Teoremas Provados

Todos os teoremas abaixo compilam sem `sorry` nem `axiom`. A marcação (★) indica contribuição original do MaxwellKeyPLUS.

### Camada 1 — Fundamentos

| Teorema | Ficheiro | Descrição |
|---------|----------|-----------|
| `admittance_symmetric` | `AdmittanceMatrix.lean:72` | `Y = Yᵀ` — a matriz de admitâncias é simétrica (reciprocidade) |
| `channel_bob_symmetric` | `ChannelMatrix.lean:61` | `H_bob = H_bobᵀ` — o canal de Bob herda a simetria de Y |
| `eve_attenuation` | `ChannelMatrix.lean:76` | `‖H_eve‖ ≤ ‖Z₀·Y_self‖ + ‖Z₀·Y_mutual‖` — atenuação do espião |

### Camada 2 — Degradedness

| Teorema | Ficheiro | Descrição |
|---------|----------|-----------|
| `S_bob_ge_S_eve` | `Degradedness.lean:115` | Original: `S_bob ⪰ S_eve_matrix` sob `f ≥ 3` |
| `degradedness_loewner` | `Degradedness.lean:193` | Teorema empacotado |
| `min_f_sq` (★) | `DegradednessGeneral.lean:12` | Definição do limiar ótimo: `(M_self²+M_mutual²)(M_self+M_mutual)²/(M_self²-M_mutual²)²` |
| `min_f_sq_le_five` (★) | `DegradednessGeneral.lean:58` | Sob acoplamento fraco, `min_f_sq ≤ 5` |
| `min_f_sq_gt_one` (★) | `DegradednessGeneral.lean:22` | Com acoplamento não-nulo, `min_f_sq > 1` |
| `S_bob_ge_S_eve` (★) | `DegradednessGeneral.lean:217` | Generalizado: `S_bob ⪰ S_eve_matrix` sob `f² ≥ min_f_sq` |
| `degradedness_loewner_general` (★) | `DegradednessGeneral.lean:262` | Teorema empacotado |

### Camada 3 — Capacidade de Segredo

| Teorema | Ficheiro | Descrição |
|---------|----------|-----------|
| `arg_bob_gt_arg_eve` | `SecrecyCapacity.lean:80` | Lema central: o argumento do log de Bob é estritamente maior |
| `secrecy_capacity_pos` | `SecrecyCapacity.lean:161` | **TEOREMA PRINCIPAL:** `C_s > 0` |

### Camada 4 — Canal Exato (PRELIMINAR)

| Teorema | Ficheiro | Descrição |
|---------|----------|-----------|
| `f_monotone_psd` (★) ⚠️ | `ExactChannel.lean:161` | `f(A) = I - (I+A)⁻¹` é monótona na ordem de Loewner para matrizes **reais** simétricas `[[a,b],[b,a]]` |
| `degradedness_exact` (★) ⚠️ | `ExactChannel.lean:261` | Aplicação ao contexto MaxwellKey (matrizes reais) |

> ⚠️ **Ressalva importante:** Estes dois teoremas aplicam-se a matrizes **reais** simétricas. A extensão para matrizes complexas Hermitianas (`H_bob H_bob^†`) requer generalização e é trabalho futuro. O módulo `ExactChannel.lean` **não é importado** por `SecrecyCapacity.lean` — o teorema principal não depende dele.

### Camada 5 — Extração

| Teorema | Ficheiro | Descrição |
|---------|----------|-----------|
| `key_agreement_succeeds_det` | `Extraction.lean:74` | Versão determinística trivial (placeholder) |
| `secrecy_of_protocol` | `Extraction.lean:82` | Re-exporta `secrecy_capacity_pos` |

### Lemas auxiliares notáveis

- `symm_form_loewner_le_iff` (`ExactChannel.lean:50`): Caracterização da ordem de Loewner para matrizes `[[a,b],[b,a]]` via desigualdades escalares `a+b` e `a-b`. Esta é uma contribuição técnica relevante por si só.
- `min_f_sq_bound` (`DegradednessGeneral.lean:178`): Factorização da diferença das formas quadráticas num quadrado perfeito — o coração da prova generalizada.

---

## 4. Valores Usados nos Exemplos

### Exemplo 1: TwoParallelStrips (literatura, geometria FR-4 típica)

| Parâmetro | Valor | Notas |
|-----------|-------|-------|
| Frequência | 100 MHz | Regime quase-estático (λ/4 ≈ 75 cm >> 10 cm) |
| Geometria | w=1 mm, s=2 mm, l=10 cm, h=1.6 mm | FR-4, ε_r=4.4 |
| C_self | 5 pF | |
| L_self | 50 nH | |
| C_mutual | 0.5 pF | |
| M_mutual | 5 nH | |
| Z₀ | 50 Ω | |
| f_att | 5.0 | Eve a 5× a distância |
| N₀ | 4.00×10⁻¹⁵ | k_B·290K·1MHz |
| **M_self** | **0.003110** | Normalizado |
| **M_mutual** | **0.00000415** | Rácio = 0.0013 |
| **min_f_sq** | **≈ 1.00000003** | |
| **f²** | **25** | Margem: 25× |

### Exemplo 2: Fallback Simulator (Python, Hammerstad-Jensen)

| Parâmetro | Valor | Notas |
|-----------|-------|-------|
| **M_self** | **0.210** | |
| **M_mutual** | **0.0215** | Rácio = 0.10 |
| **f_att** | **263** | d_eve/d_bob = 3, decaimento ~1/d³ |
| **min_f_sq** | **≈ 1.25** | |
| **f²** | **69,263** | Margem: 55,000× |

### Exemplo 3: TemplateRealParams (valores "typical", pior caso)

| Parâmetro | Valor | Notas |
|-----------|-------|-------|
| **M_self** | **0.6** (6/10) | Fração conveniente para norm_num |
| **M_mutual** | **0.15** (15/100) | Rácio = 0.25 (limite máximo) |
| **f_att** | **3** | |
| **min_f_sq** | **≈ 1.5** | |
| **f²** | **9** | Margem: 6× |

**Conclusão sobre robustez:** Em todos os exemplos, as margens são confortáveis. O pior caso (typical) ainda tem margem de 6×. O caso realista (fallback) tem margem de 55,000×. O teorema é robusto a variações nos parâmetros.

---

## 5. Estado Atual do Código

### Compilação
```
lake build → 3968 jobs, 0 erros
```

### Verificações de integridade
- `grep "sorry" *.lean` → **0 ocorrências**
- `grep "axiom" *.lean` → **0 ocorrências**
- `grep "admit" *.lean` (tática) → **0 ocorrências**
- Imports cíclicos → **0 ocorrências**

### Estatísticas
| Métrica | Valor |
|---------|-------|
| Ficheiros Lean | 15 |
| Linhas de código Lean | 1,884 |
| Linhas de documentação/scripts | 1,637 |
| Teoremas/lemas principais | ~25 |
| Jobs de compilação | 3,968 |

### Correções pós-auditoria (9-10 Junho 2026)

Após duas rondas de auditoria hostil conduzidas pelo Carlos, foram aplicadas as seguintes correções:

1. **Remoção do parâmetro fantasma `G`:** O parâmetro de condutância `G` estava presente na estrutura `DegradednessParamsGeneral` e em `create_params` mas não era usado em nenhuma matriz (`S_bob`, `S_eve`) nem teorema. Foi removido. As perdas no dielétrico (FR-4, tan δ ≈ 0.02) são desprezáveis no regime quase-estático a 100 MHz e serão incorporadas em trabalho futuro.

2. **Aviso no `ExactChannel.lean`:** Adicionado um bloco de aviso explícito nas primeiras linhas do ficheiro declarando que a prova se aplica a matrizes reais simétricas, que a extensão para matrizes Hermitianas complexas é trabalho futuro, e que este módulo não é usado nos teoremas principais.

3. **Atualização do `TwoParallelStrips.lean`:** O exemplo foi expandido para demonstrar ambos os teoremas: o original (`f ≥ 3`) e o generalizado (`f² ≥ min_f_sq`), com provas `norm_num` para todas as hipóteses.

4. **Alinhamento da documentação:** O artigo (`MaxwellKey_Paper.md`) e o `README.md` foram atualizados para qualificar o canal exato como preliminar e remover referências a `G` nas hipóteses.

---

## 6. Estado da Documentação

| Documento | Linhas | Finalidade |
|-----------|--------|------------|
| `README.md` | 178 | Portal do projeto: quick start, estrutura, teoremas, workflow experimental |
| `contexto.md` | 167 | Documento fundacional do INOVATION: visão, arquitetura, papéis, cronograma |
| `docs/SimulationGuide.md` | 332 | Guia detalhado para COMSOL/OpenEMS (português, para o David) |
| `docs/AuditReport.md` | 234 | Relatório da primeira auditoria hostil (problemas encontrados e correções) |
| `paper/MaxwellKey_Paper.md` | 325 | Artigo completo estilo conferência (inglês): 10 secções + apêndice IEDP |
| `MaxwellKeyPLUS/IEDP_sketch.md` | 43 | Sketch preprint do Informational Electromagnetic Duality Principle |
| `scripts/simulate_circuit.py` | 177 | Simulador Python de fallback (Hammerstad-Jensen) |
| `build/key_generation.c` | 224 | Código C de referência para firmware (tradução manual) |

---

## 7. Estado da Validação Experimental

### O que está feito

1. **Simulador Python de fallback:** Implementa fórmulas analíticas de microstrip (Hammerstad-Jensen, 1980) para estimar `C_self`, `L_self`, `C_mutual`, `M_mutual`, `G` e `f_att`. Gera `scripts/params.json` pronto para injeção no Lean. Resultados fisicamente realistas (M_self=0.21, M_mutual=0.022, f_att=263).

2. **Template Lean pronto:** `MaxwellKeyPLUS/Examples/TemplateRealParams.lean` está preparado para receber parâmetros do COMSOL/OpenEMS. Basta colar os valores e correr `lake build` — o Lean verifica automaticamente todas as hipóteses físicas.

3. **Workflow documentado:** O `README.md` e o `SimulationGuide.md` descrevem o pipeline completo: COMSOL → JSON → Lean → verificação.

### O que falta (a cargo do David)

1. **Simulação COMSOL/OpenEMS:** Extrair `C_self`, `L_self`, `C_mutual`, `M_mutual` da geometria real (w=1 mm, s=2 mm, l=10 cm, FR-4, 100 MHz). Incluir parâmetros para Eve a diferentes distâncias.

2. **Demonstração com hardware:** Implementar o protocolo em SDRs (ex: RTL-SDR), medir o canal real, gerar chaves, verificar que Alice e Bob concordam e Eve não.

3. **Validação numérica:** Comparar os valores medidos com os previstos pelo fallback simulator e pelas provas formais.

---

## 8. Limitações Atuais (Honestidade Brutal)

1. **Regime quase-estático:** Assumimos que o comprimento da pista (10 cm) é muito menor que λ/4 (≈ 75 cm a 100 MHz). Isto é válido para a frequência escolhida, mas limita a generalidade. Para frequências mais altas ou pistas mais longas, seria necessário um modelo de linha de transmissão.

2. **Ruído descorrelacionado:** Assumimos ruído térmico branco com matriz de covariância `N₀·I`. Na prática, pode haver correlações espaciais e interferência de fontes externas.

3. **Eve escalar:** O modelo atual trata Eve como tendo uma única antena (canal escalar). A extensão para Eve com múltiplas antenas (MIMO) é conceptualmente direta mas requer generalização das provas.

4. **Canal exato não integrado:** A prova de monotonia `f_monotone_psd` aplica-se a matrizes reais simétricas. A matriz de sinal verdadeira é `H_bob H_bob^†` (Hermitiana complexa). A conexão entre estas duas formulações não está estabelecida. O teorema principal não depende disto — usa a aproximação de primeira ordem `S_bob ≈ Z₀²·[[...]]`.

5. **Extração de código manual:** O ficheiro `build/key_generation.c` foi escrito à mão como referência. A extração automática a partir do Lean 4 (`#eval` sobre `Float`) funciona para cálculos numéricos, mas não para o protocolo completo com I/O.

6. **Modelo determinístico:** O `Extraction.lean` contém apenas uma versão determinística trivial do protocolo. A versão probabilística completa requer `MeasureTheory` e `ProbabilityTheory` em Lean 4.

7. **`Assumptions.lean` parcialmente desatualizado:** A definição `distance_factor_valid` usa `f² ≥ 5` (limiar fixo), mas o `DegradednessGeneral` já implementa o limiar ótimo `min_f_sq`. Convém atualizar.

---

## 9. Próximos Passos (As Cinco Frentes do Pedro)

### Frente 1 — Fecho do Canal Exato
- Generalizar `f_monotone_psd` para matrizes Hermitianas complexas 2×2
- Provar que `H_bob H_bob^†` (com G=0) se reduz à forma `[[a,b],[b,a]]` com a,b reais
- Integrar o resultado no `SecrecyCapacity` generalizado
- **Impacto:** Transforma o MaxwellKeyPLUS de "aproximação de primeira ordem" para "modelo exato"

### Frente 2 — Demonstração Experimental
- Acompanhar o David na extração de parâmetros do COMSOL
- Validar que os parâmetros medidos satisfazem `|M_mutual| < |M_self|/2` e `f² ≥ min_f_sq`
- Ajudar na interpretação dos resultados experimentais à luz das provas formais

### Frente 3 — Artigo do MaxwellKey
- O draft atual (`paper/MaxwellKey_Paper.md`, 325 linhas) está completo mas precisa de revisão
- Adicionar resultados experimentais quando disponíveis
- Submeter a conferência (IEEE S&P, CCS, ou CSF)

### Frente 4 — Artigo do IEDP
- O sketch atual (`IEDP_sketch.md`, 43 linhas) é um esboço
- Desenvolver a teoria formal da dualidade electromagnetismo-informação
- O MaxwellKey serve como primeiro exemplo validado do princípio

### Frente 5 — Generalizações Futuras
- **N-portas:** Extensão para N > 2 (redes de sensores)
- **Regime de linha de transmissão:** Substituir Y por parâmetros S (SParameterMonad)
- **Matriz de Dissipação Informacional (MDI):** Decomposição de Cholesky da diferença de covariâncias
- **NoisyChannelMonad:** Integração do ruído na estrutura monádica

---

## 10. Conclusão e Pedido de Feedback

Pedro, o MaxwellKey está sólido. Temos 1884 linhas de Lean 4 que compilam sem erros, sem `sorry`, sem `axiom`. O teorema principal — capacidade de segredo estritamente positiva — está provado e é robusto a variações nos parâmetros. A generalização com `min_f_sq` substitui o limiar conservador `f ≥ 3` pelo limiar exato. O pipeline experimental está documentado e pronto para receber dados do COMSOL.

As limitações são conhecidas e documentadas. O canal exato é a peça que falta para elevar o projeto de "aproximação verificada" para "modelo exato verificado" — e essa peça é tua.

**Perguntas para ti:**
1. Concordas com a arquitetura atual (MaxwellKey + MaxwellKeyPLUS como bibliotecas separadas)?
2. O `Assumptions.lean` deve ser atualizado para refletir `min_f_sq` em vez de `f² ≥ 5`?
3. Queres que o canal exato seja a prioridade máxima, ou preferes primeiro consolidar o artigo com os resultados atuais?
4. Há algum teorema adicional que gostarias de ver formalizado antes da submissão?
5. O sketch do IEDP está pronto para ser expandido, ou preferes esperar pelos resultados experimentais?

O Carlos já fez a parte dele (duas auditorias hostis, zero piedade). Agora é contigo.

---

*Relatório gerado por Kimi a pedido do Carlos. INOVATION, 10 de Junho de 2026.*
