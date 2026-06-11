# [DESATUALIZADO / OBSOLETO]

**AVISO:** Este documento é uma especificação inicial do projeto (2026-06-09)
que **não corresponde ao estado atual do código**. Muitos módulos mencionados
aqui não foram implementados (ex: `Reciprocity.lean`, `EPM.lean`, `AMI.lean`).
A arquitetura real está documentada em `README.md`.

**Não usar este documento como referência para o estado atual do projeto.**
Mantido apenas para histórico.

---

# Documento de Contexto do Projeto MaxwellKey (ESPECIFICAÇÃO INICIAL)
**Data:** 2026-06-09  
**Autores:** Carlos, Pedro, David (INOVATION)  
**Status:** [DESATUALIZADO] — Ver README.md para o estado atual

## 1. O Que É o MaxwellKey

O MaxwellKey é uma biblioteca formal escrita em **Lean 4** que prova, a partir das leis do eletromagnetismo e da teoria da informação, que dois terminais acoplados por um canal físico recíproco podem gerar uma chave secreta partilhada, segura contra um *eavesdropper* passivo. A segurança é *information-theoretic*, baseada exclusivamente na física do canal, e não em pressupostos computacionais.

O projeto representa a primeira vez que um assistente de provas é usado para verificar formalmente uma técnica de **Physical-Layer Security (PLS)**, unindo as equações de Maxwell (na forma de uma matriz de admitâncias quase-estática) com o teorema do *wiretap channel* de Wyner e Csiszár-Körner.

## 2. A Ideia Central

Dois fios condutores paralelos numa PCB (ou duas antenas) exibem acoplamento eletromagnético mútuo: capacidade parasita `C_m` e indutância mútua `M`. Este acoplamento é recíproco — a matriz de admitâncias `Y` que relaciona correntes e tensões é simétrica. Um terminal legítimo (Bob) pode medir este acoplamento exatamente como o outro (Alice), enquanto um espião (Eve) colocado a uma distância maior sente um acoplamento muito mais fraco, com parâmetros `C_m_eve` e `M_eve` ordens de grandeza inferiores.

A física garante que o canal de Eve é uma **versão degradada** do canal de Bob. Em termos formais:

\[
H_{\text{bob}} H_{\text{bob}}^\dagger \succeq H_{\text{eve}} H_{\text{eve}}^\dagger
\]

onde `H_bob` e `H_eve` são as matrizes de canal efetivas derivadas da matriz de admitâncias, e `⪰` é a ordem de Loewner para matrizes Hermitianas. Sob esta condição, a **capacidade de segredo** do canal gaussiano é estritamente positiva, e um protocolo de geração de chave baseado na reciprocidade do canal é formalmente seguro.

O MaxwellKey formaliza todos estes passos em Lean 4 e extrai código executável que implementa o protocolo.

## 3. Porquê Lean 4

O Lean 4 é simultaneamente uma linguagem de programação funcional com tipos dependentes e um assistente de provas interativo. Isto permite-nos:

- **Modelar a física** (matrizes de admitâncias, ruído térmico) como tipos precisos.
- **Provar teoremas** de segurança (secrecy capacity > 0) que dependem de hipóteses físicas explícitas.
- **Extrair código** C ou Rust diretamente das especificações verificadas, ligando a prova formal ao firmware executável em hardware real.

Nenhum trabalho anterior em PLS ou segurança de *side-channel* eletromagnético usou verificação formal neste nível.

## 4. Arquitetura do Sistema

A biblioteca Lean 4 será organizada nos seguintes módulos:

```
MaxwellKey/
├── EMInfo/
│   ├── AdmittanceMatrix.lean       -- Definição da matriz Y para circuitos quasi-estáticos
│   ├── Reciprocity.lean            -- Prova de que Y = Yᵀ
│   ├── ChannelMatrix.lean          -- Derivação de H_bob, H_eve a partir de Y e Z₀
│   ├── NoiseModel.lean             -- Ruído térmico gaussiano: N₀·k_B·T·I
│   ├── LoewnerOrder.lean           -- Definição e propriedades de A ⪰ B para matrizes PSD
│   ├── Degradedness.lean           -- Teorema: H_bob H_bob† ⪰ H_eve H_eve†
│   ├── SecrecyCapacity.lean        -- Teorema principal: C_s > 0
│   └── Extraction.lean             -- Extração de código para o protocolo de chave
├── AdmittanceMonad/
│   ├── EPM.lean                    -- Electromagnetic Propagation Monad
│   ├── AMI.lean                    -- Prova de equivalência EPM ≈ matriz Y (regime quasi-estático)
│   └── NoisyChannelMonad.lean      -- Extensão futura com ruído (documentada)
├── Examples/
│   ├── TwoParallelStrips.lean      -- Instanciação para a geometria real (dados do COMSOL)
│   └── KeyExtraction.lean          -- Demonstração do protocolo extraído
└── Tests/
    ├── COMSOL_Validation.lean      -- Validação numérica dos parâmetros
    └── Simulation.lean             -- Simulação Monte Carlo para sanity check
```

## 5. Os Cinco Teoremas do MaxwellKey

Cada teorema é uma peça da fundação. Com exceção do Teorema 5, todos serão provados integralmente no Lean 4.

**Teorema 1 — Reciprocidade da Admitância**  
`theorem admittance_symmetric (c : QuasiStaticCircuit) : c.Y = c.Yᵀ`  
*Responsável:* Pedro.  
*Descrição:* A matriz de admitâncias do circuito de duas pistas é simétrica, uma consequência direta da reciprocidade de Lorentz e da formulação de parâmetros concentrados.

**Teorema 2 — Equivalência da AMI (Admittance Monad Instantiation)**  
`theorem ami_equiv (c : QuasiStaticCircuit) (v : VoltageVector) : EPM.run c v = c.Y⁻¹ * (current_source v)`  
*Responsável:* Pedro.  
*Descrição:* A *Electromagnetic Propagation Monad* de Pedro, quando instanciada no regime quase-estático, reduz-se exatamente à matriz de admitâncias. Isto valida a EPM como uma semântica funcional correta para a propagação de sinais no circuito.

**Teorema 3 — Ordem de Loewner da Degradação**  
`theorem degradedness_loewner (h_geom : geometry_condition) : H_bob_Hermitian ⪰ H_eve_Hermitian`  
*Responsável:* Pedro e Carlos.  
*Descrição:* Sob condições geométricas realistas (o espião está mais longe que a distância de acoplamento legítimo), a matriz de covariância do sinal no recetor de Bob é maior ou igual à de Eve no sentido de Loewner. Isto estabelece formalmente a *degradedness* do canal espião.

**Teorema 4 — Positividade da Capacidade de Segredo**  
`theorem secrecy_capacity_pos (h_geom : geometry_condition) (h_snr : snr > 0) : secrecy_capacity model > 0`  
*Responsável:* Carlos.  
*Descrição:* Usando o Teorema 3 e uma versão do teorema de Csiszár-Körner para canais gaussianos degradados, prova-se que a capacidade de segredo é estritamente positiva. Isto significa que é possível destilar uma chave secreta a uma taxa não nula.

**Teorema 5 — Correção do Protocolo Extraído**  
`theorem extracted_protocol_correct (k : Key) : key_agreement_succeeds k`  
*Responsável:* David (com suporte dos restantes).  
*Descrição:* O código C extraído do Lean 4 implementa corretamente o protocolo de geração de chave, concordando com a especificação formal. Este teorema liga a prova abstrata ao hardware real.

## 6. Modelo Físico e Parâmetros

- **Geometria alvo:** Duas pistas paralelas numa PCB FR-4 (substrato de 1.6 mm, εᵣ ≈ 4.4). Largura de pista `w = 1 mm`, separação `d = 2 mm`, comprimento `L = 10 cm`.
- **Frequência de operação:** 100 MHz (regime quase-estático válido porque `L ≈ 10 cm << λ/4 ≈ 75 cm`).
- **Parâmetros concentrados (por unidade de comprimento ou totais):** Capacidade própria `C`, indutância própria `L`, capacidade mútua `C_m`, indutância mútua `M`. O David vai extrair estes valores de uma simulação COMSOL ou OpenEMS, e também os parâmetros equivalentes para o espião (`C_eve`, `M_eve`).
- **Ruído:** Térmico branco aditivo, descorrelacionado em cada porta, com densidade espectral `N₀ = k_B·T·B`, onde `T = 290 K` e `B` a largura de banda escolhida.
- **Terminações:** Impedâncias idênticas `Z₀ = 50 Ω` nos três terminais.

Com estes números, o modelo do canal é completamente determinado. O Lean 4 não recebe valores numéricos arbitrários; recebe uma instância de `QuasiStaticCircuit` que inclui os parâmetros e uma prova de que `C_m > C_eve` e `M > M_eve` (a condição geométrica). A positividade da capacidade de segredo será então uma consequência automática.

## 7. Papéis e Responsabilidades (os Três Motores do INOVATION)

**Pedro (Físico-Matemático, o Visionário)**  
- Formaliza a matriz de admitâncias e a sua simetria.  
- Desenvolve a EPM e prova a equivalência AMI.  
- Prova o Teorema 3 (degradedness de Loewner) com base na geometria e na estrutura da matriz.  
- Escreve o preprint do *Informational Electromagnetic Duality Principle (IEDP)* como investigação paralela, usando o MaxwellKey como primeiro exemplo validado.

**Carlos (Físico-Cético, o Arquiteto de Rigor)**  
- Define a estrutura dos canais gaussianos MIMO e o modelo de ruído.  
- Formaliza a ordem de Loewner e as suas propriedades necessárias.  
- Prova o Teorema 4 (secrecy capacity > 0) a partir do Teorema 3 e do teorema de Csiszár-Körner.  
- Verifica cada hipótese física para garantir que não há *cherry-picking*: a linearidade, o regime quase-estático, o ruído descorrelacionado, a condição de espião passivo.  
- Atua como revisor interno de cada `theorem` escrito pelo Pedro.

**David (Engenheiro-Programador, o Pragmático)**  
- Executa a simulação eletromagnética (COMSOL/OpenEMS) para extrair os parâmetros `C, L, C_m, M` da geometria real.  
- Alimenta esses valores no módulo `TwoParallelStrips.lean`, gerando uma instância verificada da condição geométrica.  
- Implementa a extração de código e o protocolo de geração de chave.  
- Testa o código extraído em hardware real (dois SDRs, por exemplo RTL-SDR), demonstrando que as chaves geradas são iguais para Alice e Bob e aleatórias para Eve.  
- Ajuda a construir o Teorema 5 (correção da extração) e valida a *secrecy capacity* numericamente com simulações Monte Carlo.

## 8. Cronograma (3 Meses)

| Mês | Pedro | Carlos | David |
|-----|-------|--------|-------|
| **Mês 1** | `AdmittanceMatrix.lean`, `Reciprocity.lean`, início da `AMI.lean` | `ChannelMatrix.lean`, `NoiseModel.lean`, `LoewnerOrder.lean` | Simulação COMSOL, extração dos parâmetros C, L, C_m, M e dos parâmetros do espião; validação numérica do modelo |
| **Mês 2** | `EPM.lean` completo, prova da equivalência AMI, esboço do Teorema 3 | Finalização de `Degradedness.lean` com a prova de Loewner; início do `SecrecyCapacity.lean` com a formalização do teorema de Csiszár-Körner | Preenchimento do `TwoParallelStrips.lean`, testes de sanidade com os parâmetros reais, início da preparação do hardware |
| **Mês 3** | Apoio na revisão do Teorema 3, redação do preprint do IEDP, documentação da MDI e da NoisyChannelMonad como extensões futuras | Conclusão de `SecrecyCapacity.lean` (Teorema 4), revisão de todo o código, redação do artigo principal do MaxwellKey | Extração de código (`Extraction.lean`), implementação do protocolo nos SDRs, demonstração experimental, redação da secção de resultados práticos |

## 9. Relação com o IEDP e Extensões Futuras

O MaxwellKey é a primeira instância validada do *Informational Electromagnetic Duality Principle* de Pedro. Enquanto o IEDP na sua forma integral ainda é uma conjetura em investigação, o regime quase-estático permite uma derivação exata: a capacidade de canal reduz-se a uma expressão que depende da matriz de admitâncias, uma manifestação discreta do princípio de dualidade.

Após o sucesso do MaxwellKey, estão planeadas as seguintes extensões (não incluídas no protótipo de 3 meses):

- **NoisyChannelMonad:** Integração formal do ruído na estrutura monádica, permitindo modelar canais ruidosos de forma composicional.
- **Matriz de Dissipação Informacional (MDI):** Decomposição da degradação do canal em modos de perda, baseada na decomposição de Cholesky da diferença de covariâncias.
- **Regimes superiores:** Extensão para o regime de linha de transmissão (SParameterMonad) e, eventualmente, campo distante (GreenMonad), mantendo a mesma arquitetura de mónada.
- **Generalização para N dispositivos e aplicações OSINT/anti-OSINT:** Prova de segurança para redes de sensores e verificação de imunidade a triangulação por assinatura RF.

## 10. Significado e Impacto Esperado

O MaxwellKey será o primeiro sistema de geração de chave secreta cuja segurança está garantida por uma prova formal que parte das leis de Maxwell. Não há suposições sobre a capacidade computacional do adversário, nem *cherry-picking* de parâmetros. A segurança é uma consequência matemática da geometria do circuito e da termodinâmica do ruído.

Com este artefacto, abrimos caminho para:

- **Dispositivos IoT verdadeiramente seguros na camada física**, sem necessidade de pré-distribuição de chaves.
- **Um novo padrão de verificação de segurança eletromagnética**, onde um *proof term* substitui as simulações empíricas.
- **A primeira biblioteca formal de teoria da informação eletromagnética**, reutilizável para uma vasta gama de problemas em PLS e *side-channel security*.

## 11. O Que Precisamos de Ti, David (Agora)

1. **Até ao final da semana:** Resultados da simulação COMSOL para a geometria especificada (1 mm largura, 2 mm separação, 10 cm comprimento, FR-4 de 1.6 mm, 100 MHz). Preciso de valores numéricos para `C`, `L`, `C_m`, `M` (por unidade de comprimento ou totais) e os correspondentes `C_eve`, `M_eve` para um espião a 10 cm de distância.
2. **Assim que possível:** Um esboço da estrutura de hardware que vais usar (SDRs, antenas, acopladores) para começarmos a alinhar a extração de código.
3. **Durante o Mês 1:** Validação de que os valores simulados satisfazem a condição `C_m > C_eve` e `M > M_eve` de forma robusta, e que a aproximação quase-estática é válida até 100 MHz.

Pedro e eu já estamos a escrever código. Quando tiveres os números, eles entram diretamente nos tipos do Lean 4 e a magia começa.

## 12. Uma Nota Final, de Carlos para David

David, tu pediste-me contexto. Eu dei-te a arquitetura completa, sem omissões. Este projeto não é um sonho. É a primeira vez que eu, o cético, olho para uma ideia do Pedro e vejo uma máquina que funciona, um teorema que pode ser compilado, e um impacto que não depende de marketing. O teu papel é vital: sem os teus parâmetros reais, o MaxwellKey é uma teoria bonita; com eles, é um protocolo que funciona em hardware e que ninguém pode escutar.

Bem-vindo ao projeto que nos vai definir como INOVATION.

Carlos  
*INOVATION*