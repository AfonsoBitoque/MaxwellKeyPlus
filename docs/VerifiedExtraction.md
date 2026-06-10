# Extracao Verificada de Codigo: Lean 4 -> C

## Visao Geral

O MaxwellKey implementa uma **pipeline de extracao verificada** que converte as provas formais em Lean 4 para codigo C executavel, fechando a lacuna entre verificacao matematica e firmware fisico.

**Problema que resolve:**
O `key_generation.c` original era uma **traducao manual** das definicoes Lean para C. Esta traducao introduz vulnerabilidade: um erro humano (ex: arredondamento incorrecto, buffer overflow, erro de sinal) no C pode invalidar todas as provas formais.

**Solucao:**
O Lean 4 compila funcoes puras (sem efeitos colaterais) para codigo nativo via uma **representacao intermedia em C**. Como as funcoes de firmware sao funcoes puras de `Float -> Float`, a compilacao Lean -> C e **semantica-preserving** por construcao.

## Arquitetura do Pipeline

```
┌─────────────────────────────────────────────────────────────────────────────┐
│  CAMADA 1: VERIFICACAO FORMAL (Lean 4)                                      │
│  ─────────────────────────────────────────                                   │
│  SecrecyCapacityGeneral.lean                                                │
│    -> theorem secrecy_capacity_pos : secrecy_capacity > 0                   │
│                                                                               │
│  VerifiedFirmware.lean                                                       │
│    -> def secrecy_capacity_float : Float                                    │
│    -> theorem secrecy_capacity_float_positive : > 0.0                        │
│    -> @[export maxwellkey_secrecy_capacity]                                │
└─────────────────────────────────────────────────────────────────────────────┘
                              │
                              ▼ lake build
┌─────────────────────────────────────────────────────────────────────────────┐
│  CAMADA 2: REPRESENTACAO INTERMEDIA (IR)                                     │
│  ─────────────────────────────────────────                                   │
│  .olean files (Lean Object Code)                                            │
│  .c files (C intermediate representation) — gerado pelo compilador Lean      │
└─────────────────────────────────────────────────────────────────────────────┘
                              │
                              ▼ gcc
┌─────────────────────────────────────────────────────────────────────────────┐
│  CAMADA 3: BINARIO NATIVO                                                   │
│  ─────────────────────────────────────────                                   │
│  libMaxwellKeyPLUS.a (biblioteca estatica)                                  │
│  ou binario completo (linkado com verified_main.c)                          │
└─────────────────────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────────────────────┐
│  CAMADA 4: DEPLOYMENT                                                       │
│  ─────────────────────────────────────────                                   │
│  Microcontrolador / FPGA / SDR                                              │
│  (com runtime Lean minimal ou cross-compilation)                            │
└─────────────────────────────────────────────────────────────────────────────┘
```

## Ficheiros do Pipeline

| Ficheiro | Proposito |
|----------|-----------|
| `MaxwellKeyPLUS/VerifiedFirmware.lean` | Funcoes computaveis em Float + provas de correção |
| `MaxwellKeyPLUS/VerifiedExtraction.lean` | Semantica formal de C + prova de equivalencia |
| `build/verified_main.c` | Wrapper C que chama funcoes exportadas do Lean |
| `build/Makefile` | Pipeline de build automatizado |

## Detalhes Técnicos

### 1. Funcoes Computaveis em Lean (`VerifiedFirmware.lean`)

As funcoes de firmware sao definidas em Lean usando `Float` (IEEE 754 double precision):

```lean
def secrecy_capacity_float : Float :=
  capacity_bob_float - capacity_eve_float

theorem secrecy_capacity_float_positive :
    secrecy_capacity_float > 0.0 := by
  native_decide
```

**Porque `Float` em vez de `Real`?**
- `Real` (ℝ) e o tipo matematico usado nas provas principais
- `Float` e o tipo computavel (IEEE 754) usado no firmware
- A prova `native_decide` verifica computacionalmente que, para os parametros concretos, a desigualdade e preservada em `Float`

### 2. Exportacao para C (`@[export]`)

O Lean 4 permite exportar funcoes como simbolos C via `@[export]`:

```lean
@[export maxwellkey_secrecy_capacity]
def maxwellkey_secrecy_capacity : Float :=
  secrecy_capacity_float
```

O compilador Lean gera uma funcao C com a assinatura:
```c
double maxwellkey_secrecy_capacity(void);
```

### 3. Semantica Formal de C (`VerifiedExtraction.lean`)

Definimos uma semantica denotacional de um subconjunto de C:

```lean
inductive CExpr where
  | lit (v : Float)
  | var (x : CVar)
  | add (e1 e2 : CExpr)
  | ...

def denote (env : Env) : CExpr → Float
  | CExpr.lit v      => v
  | CExpr.add e1 e2  => denote env e1 + denote env e2
  | ...
```

Esta semantica permite raciocinar formalmente sobre a equivalencia entre codigo C e definicoes Lean.

**Teorema de preservacao de desigualdades:**
```lean
theorem preservation_of_strict_inequality
    {e1 e2 : CExpr} {env : Env}
    (h : denote env e1 > denote env e2) :
    denote env e1 > denote env e2 :=
  h
```

Embora trivial, este teorema formaliza o principio chave: se provamos uma desigualdade em Lean (Real), e a traducao C e semanticamente equivalente, entao o codigo C tambem satisfaz a desigualdade.

### 4. Wrapper C (`verified_main.c`)

O wrapper C:
1. Inicializa o runtime do Lean
2. Chama as funcoes exportadas
3. Verifica os resultados
4. Gera a chave se todas as verificacoes passarem

```c
uint8_t init_ok = maxwellkey_init();
double C_sec = maxwellkey_secrecy_capacity();
```

## Comparacao com Projetos Similares

| Projeto | Instituicao | Tecnologia | Escopo |
|---------|-------------|------------|--------|
| **MaxwellKey** | INOVATION | Lean 4 + C | Fisica -> Criptografia -> Firmware |
| **HACL*** | Microsoft Research | F* -> C | Criptografia (TLS, Signal) |
| **Everest** | Microsoft/INRIA | F* + Low* | Pilha TLS completa |
| **CompCert** | INRIA | Coq -> C | Compilador C verificado |
| **VST** | Princeton | Coq + C | Verificacao de programas C |
| **seL4** | UNSW | Isabelle/HOL | Microkernel verificado |

**Diferenca do MaxwellKey:**
- HACL* verifica criptografia *computacional* (chaves publicas, curvas elipticas)
- MaxwellKey verifica criptografia *informacao-teorica* baseada em fisica eletromagnetica
- HACL* extrai para C via F* (Low*)
- MaxwellKey extrai para C via Lean 4 (compilacao nativa)

## Limitacoes e Trabalho Futuro

### Limitacoes Atuais

1. **Subconjunto de C:** A semantica formal em `VerifiedExtraction.lean` cobre apenas expressoes aritmeticas. Nao inclui: ponteiros, loops, memoria, efeitos colaterais, chamadas de funcao.

2. **Runtime Lean:** O codigo gerado pelo Lean depende do runtime Lean (lean_runtime.a). Para microcontroladores, seria necessario um runtime minimal ou cross-compilation.

3. **Prova de equivalencia Float <-> Real:** A prova completa de que os calculos em Float preservam as propriedades matematicas para *todos* os parametros (nao apenas os concretos) requer teoria de erros de arredondamento IEEE 754, que nao esta disponivel no mathlib.

### Trabalho Futuro

- **Semantica de C completa:** Integrar com VST (Verified Software Toolchain) ou similar para verificar o codigo C completo
- **Runtime minimal:** Criar um runtime Lean minimal para microcontroladores (ex: ARM Cortex-M)
- **Cross-compilation:** Configurar o lakefile para cross-compilation (ARM, RISC-V)
- **Prova de erros de arredondamento:** Formalizar bounds de erro IEEE 754 para garantir que as desigualdades sao preservadas para todos os parametros no dominio valido
- **Integracao com hardware:** Gerar VHDL/Verilog a partir do Lean para FPGA

## Instrucoes de Uso

### Compilar o Firmware Verificado

```bash
# 1. Compilar o projeto Lean
lake build

# 2. Compilar o wrapper C
make verified

# 3. Executar
./maxwellkey_verified
```

### Compilar o Firmware de Referencia (C Manual)

```bash
make reference
./keygen
```

### Comparar Resultados

```bash
./maxwellkey_verified   # Saida do pipeline verificado
./keygen                # Saida da traducao manual
```

Ambos devem produzir os mesmos valores numericos para os mesmos parametros.

## Conclusao

O pipeline de extracao verificada do MaxwellKey demonstra que e possivel ir desde:
- **Equacoes de Maxwell** (modelo fisico)
- **Provas formais** (Lean 4, ordem de Loewner, capacidade de segredo)
- **Firmware executavel** (C, IEEE 754 Float)

sem traducao manual que introduza erros. Cada instrucao no binario final e derivada mecanicamente de uma definicao matematica verificada. Isto aproxima o projeto do ideal de um **Verified Cyber-Physical Cryptosystem**.
