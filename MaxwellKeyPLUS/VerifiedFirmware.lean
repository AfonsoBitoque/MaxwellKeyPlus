/-
  MaxwellKeyPLUS / VerifiedFirmware.lean
  ---------------------------------------
  Firmware computavel verificado para o MaxwellKey — GENERICO.

  Este modulo define as operacoes de firmware usando Float (IEEE 754
  double precision) de forma PARAMETRIZADA. Qualquer conjunto de
  parametros fisicos pode ser verificado em runtime.

  Estrutura:
  1. FirmwareParams — estrutura generica com todos os parametros
  2. Operacoes computaveis parametrizadas (alpha, arg_bob, arg_eve, ...)
  3. Verificacoes de seguranca parametrizadas
  4. Secao de TESTE: exemplo TwoParallelStrips (regressao)
  5. Interface C generica (@[export] com parametros Float)

  A prova matematica geral (Real) esta em DegradednessGeneral.lean.
  Aqui provemos apenas que, para parametros concretos validos,
  os calculos Float preservam as desigualdades.
-/

import MaxwellKeyPLUS.SecrecyCapacityGeneral
import MaxwellKeyPLUS.DegradednessGeneral

namespace MaxwellKey

namespace VerifiedFirmware

/- =====================================================================
   1. PARAMETROS DO FIRMWARE (Float, GENERICOS)
   ===================================================================== -/

/-- Constantes fisicas (globais, nao dependem do dispositivo). -/
def k_B_float : Float := 1.380649e-23
def T_float     : Float := 290.0
def B_float     : Float := 1.0e6

/-- Estrutura generica de parametros do firmware.
    Cada instancia representa uma configuracao fisica concreta. -/
structure FirmwareParams where
  /-- Parametro de acoplamento proprio normalizado (adimensional). -/
  M_self  : Float
  /-- Parametro de acoplamento mutuo normalizado (adimensional). -/
  M_mutual : Float
  /-- Impedancia de terminacao (Ohm). -/
  Z₀      : Float
  /-- Fator de distancia de Eve (adimensional, > 1). -/
  eve_factor : Float
  /-- Densidade espectral de ruido (W/Hz). -/
  N0      : Float
  deriving Repr

/-- Construtor com N0 calculado a partir de k_B, T, B. -/
def FirmwareParams.withThermalNoise (M_self M_mutual Z₀ eve_factor : Float) : FirmwareParams :=
  { M_self := M_self, M_mutual := M_mutual, Z₀ := Z₀, eve_factor := eve_factor,
    N0 := k_B_float * T_float * B_float }

/- =====================================================================
   2. OPERACOES COMPUTAVEIS PARAMETRIZADAS (Float)
   ===================================================================== -/

/-- alpha = Z0^2 / N0 (Float) para parametros genericos. -/
def alpha_float (p : FirmwareParams) : Float :=
  p.Z₀ * p.Z₀ / p.N0

/-- Argumento de Bob em Float (parametrizado).
    arg_bob = (1 + alpha*(M_self^2 + M_mutual^2))^2 - (alpha*2*M_self*M_mutual)^2

    NOTA NUMERICA (risco de cancelamento):
    Para parametros onde alpha*M_self^2 ~ alpha*M_mutual^2,
    a subtracao pode perder precisao. Para os parametros validados,
    a desigualdade estrita e preservada com margem de seguranca.
    Em producao, considerar reformular com Float.log1p. -/
def arg_bob_float (p : FirmwareParams) : Float :=
  let a := 1.0 + alpha_float p * (p.M_self * p.M_self + p.M_mutual * p.M_mutual)
  let b := alpha_float p * (2.0 * p.M_self * p.M_mutual)
  a * a - b * b

/-- Argumento de Eve em Float (parametrizado).
    arg_eve = 1 + alpha*(M_self + M_mutual)^2 / f^2 -/
def arg_eve_float (p : FirmwareParams) : Float :=
  1.0 + alpha_float p * ((p.M_self + p.M_mutual) * (p.M_self + p.M_mutual))
          / (p.eve_factor * p.eve_factor)

/-- Capacidade de Bob (bits/uso) em Float. -/
def capacity_bob_float (p : FirmwareParams) : Float :=
  0.5 * Float.log2 (arg_bob_float p)

/-- Capacidade de Eve (bits/uso) em Float. -/
def capacity_eve_float (p : FirmwareParams) : Float :=
  0.5 * Float.log2 (arg_eve_float p)

/-- Capacidade de segredo (bits/uso) em Float. -/
def secrecy_capacity_float (p : FirmwareParams) : Float :=
  capacity_bob_float p - capacity_eve_float p

/- =====================================================================
   3. FUNCOES DE SEGURANCA PARAMETRIZADAS
   ===================================================================== -/

/-- Verificacao de runtime: alpha > 0. -/
def check_alpha_positive (p : FirmwareParams) : Bool :=
  alpha_float p > 0.0

/-- Verificacao de runtime: arg_bob > arg_eve (condicao de seguranca). -/
def check_arg_bob_gt_arg_eve (p : FirmwareParams) : Bool :=
  arg_bob_float p > arg_eve_float p

/-- Verificacao de runtime: arg_bob > 0. -/
def check_arg_bob_positive (p : FirmwareParams) : Bool :=
  arg_bob_float p > 0.0

/-- Verificacao de runtime: arg_eve > 0. -/
def check_arg_eve_positive (p : FirmwareParams) : Bool :=
  arg_eve_float p > 0.0

/-- Verificacao de runtime: capacidade de segredo > 0. -/
def check_secrecy_positive (p : FirmwareParams) : Bool :=
  secrecy_capacity_float p > 0.0

/-- Todas as verificacoes combinadas.
    O firmware so deve operar se todas passarem. -/
def all_security_checks_pass (p : FirmwareParams) : Bool :=
  check_alpha_positive p &&
  check_arg_bob_positive p &&
  check_arg_eve_positive p &&
  check_arg_bob_gt_arg_eve p &&
  check_secrecy_positive p

/- =====================================================================
   4. MATRIZ DE COVARIANCIA DO SINAL (Float)
   ===================================================================== -/

/-- Matriz simetrica [[a,b],[b,a]] em Float. -/
structure SymmMatrix2x2F where
  a : Float
  b : Float

/-- Matriz S_bob = Z0^2 * [[M_self^2+M_mutual^2, 2*M_self*M_mutual],
                            [2*M_self*M_mutual, M_self^2+M_mutual^2]] -/
def S_bob_float (p : FirmwareParams) : SymmMatrix2x2F :=
  let Z0sq := p.Z₀ * p.Z₀
  { a := Z0sq * (p.M_self * p.M_self + p.M_mutual * p.M_mutual)
    b := Z0sq * (2.0 * p.M_self * p.M_mutual) }

/-- Matriz S_eve = Z0^2 * (M_self+M_mutual)^2/f^2 * [[1,0],[0,1]]. -/
def S_eve_float (p : FirmwareParams) : SymmMatrix2x2F :=
  let Z0sq := p.Z₀ * p.Z₀
  let scalar := Z0sq * ((p.M_self + p.M_mutual) * (p.M_self + p.M_mutual))
                / (p.eve_factor * p.eve_factor)
  { a := scalar
    b := 0.0 }

/-- Forma quadratica x^T S x para matriz simetrica [[a,b],[b,a]]. -/
def quad_form_float (S : SymmMatrix2x2F) (x0 x1 : Float) : Float :=
  S.a * (x0 * x0 + x1 * x1) + 2.0 * S.b * x0 * x1

/-- Verificacao da ordem de Loewner por amostragem (grid).
    LEGADO: Aproximacao computacional por grid finito.
    Mantida para comparacao e testes de regressao. -/
def loewner_le_check_float_grid (A B : SymmMatrix2x2F) (gridSize : Nat) : Bool :=
  let n := Float.ofNat gridSize
  (List.range (gridSize + 1)).all fun i =>
    (List.range (gridSize + 1)).all fun j =>
      let x0 := Float.ofNat i / n
      let x1 := Float.ofNat j / n
      quad_form_float A x0 x1 >= quad_form_float B x0 x1

/-- Verificacao ANALITICA da ordem de Loewner para matrizes [[a,b],[b,a]].

    Para matrizes simetricas 2x2 da forma [[a,b],[b,a]], a diferenca D = A - B
    e [[d_a, d_b],[d_b, d_a]] com d_a = A.a - B.a e d_b = A.b - B.b.

    Os autovalores de D sao: λ₁ = d_a + d_b  e  λ₂ = d_a - d_b.

    A condicao de Loewner A ≥ₗ B e equivalente a D ser semidefinida positiva,
    i.e., ambos os autovalores >= 0:
        d_a + d_b >= 0  AND  d_a - d_b >= 0
    que e equivalente a: d_a >= |d_b| (desde que d_a >= 0).

    Esta verificacao e EXATA para esta familia de matrizes, ao contrario
    da amostragem por grid que e apenas uma aproximacao. -/
def loewner_le_check_float (A B : SymmMatrix2x2F) : Bool :=
  let d_a := A.a - B.a
  let d_b := A.b - B.b
  -- Semidefinida positiva: ambos os autovalores >= 0
  (d_a + d_b >= 0.0) && (d_a - d_b >= 0.0)

/- =====================================================================
   5. CANAL EXATO (Float)
   ===================================================================== -/

/-- Aplica o canal exacto a uma matriz simetrica [[a,b],[b,a]]. -/
def exact_channel_float (S : SymmMatrix2x2F) : Option SymmMatrix2x2F :=
  let det := (1.0 + S.a) * (1.0 + S.a) - S.b * S.b
  if det == 0.0 then
    none
  else
    let p := (1.0 + S.a) / det
    let q := S.b / det
    some { a := 1.0 - p, b := q }

/-- Verifica se canal exacto preserva ordem de Loewner (parametrizado).
    Usa verificacao ANALITICA (autovalores), nao grid. -/
def exact_channel_loewner_check (p : FirmwareParams) : Bool :=
  match exact_channel_float (S_bob_float p), exact_channel_float (S_eve_float p) with
  | some Hbob, some Heve =>
      loewner_le_check_float Hbob Heve
  | _, _ => false

/- =====================================================================
   6. EXEMPLO CONCRETO: TwoParallelStrips (REGRESSAO)
   =====================================================================
   As provas native_decide abaixo verificam que, para o exemplo
   TwoParallelStrips, os calculos Float preservam seguranca.
   Este e um teste de regressao, nao o modulo principal. -/

def two_parallel_strips : FirmwareParams :=
  FirmwareParams.withThermalNoise
    0.003109761664971414   -- M_self
    0.000004150620831811415 -- M_mutual
    50.0                    -- Z₀
    5.0                     -- eve_factor

#eval all_security_checks_pass two_parallel_strips  -- true

/-- Teste de regressao: seguranca para TwoParallelStrips. -/
theorem two_parallel_strips_safe :
    all_security_checks_pass two_parallel_strips := by
  native_decide

/-- Teste de regressao: capacidade de segredo positiva. -/
theorem two_parallel_strips_capacity_positive :
    secrecy_capacity_float two_parallel_strips > 0.0 := by
  native_decide

/-- Teste de regressao: Loewner analitico passa para TwoParallelStrips. -/
theorem two_parallel_strips_loewner :
    loewner_le_check_float (S_bob_float two_parallel_strips) (S_eve_float two_parallel_strips) := by
  native_decide

/-- Teste de regressao: verificacao analitica e grid coincidem
    para TwoParallelStrips (valida que a aproximacao grid e correta
    para este exemplo concreto). -/
theorem two_parallel_strips_loewner_grid_agrees :
    loewner_le_check_float (S_bob_float two_parallel_strips) (S_eve_float two_parallel_strips)
      = loewner_le_check_float_grid (S_bob_float two_parallel_strips) (S_eve_float two_parallel_strips) 20 := by
  native_decide

/-- Teste de regressao: canal exacto preserva Loewner. -/
theorem two_parallel_strips_exact_channel :
    exact_channel_loewner_check two_parallel_strips := by
  native_decide

/- =====================================================================
   7. INTERFACE C GENERICA (@[export])
   =====================================================================
   As funcoes exportadas aceitam parametros Float como argumentos,
   permitindo que o firmware C passe os valores medidos em runtime. -/

/-- Verifica seguranca para parametros arbitrarios.
    Chamada pelo firmware C apos medicao.
    Retorna: 1 = PASSA, 0 = FALHA. -/
@[export maxwellkey_check_params]
def maxwellkey_check_params (M_self M_mutual Z₀ eve_factor N0 : Float) : UInt8 :=
  let p := { M_self := M_self, M_mutual := M_mutual, Z₀ := Z₀,
             eve_factor := eve_factor, N0 := N0 }
  if all_security_checks_pass p then 1 else 0

/-- Calcula a capacidade de segredo para parametros arbitrarios. -/
@[export maxwellkey_secrecy_capacity]
def maxwellkey_secrecy_capacity (M_self M_mutual Z₀ eve_factor N0 : Float) : Float :=
  let p := { M_self := M_self, M_mutual := M_mutual, Z₀ := Z₀,
             eve_factor := eve_factor, N0 := N0 }
  secrecy_capacity_float p

/-- Verifica ordem de Loewner ANALITICAMENTE para parametros arbitrarios.
    Usa autovalores da diferenca (EXATO para matrizes [[a,b],[b,a]]).
    Retorna: 1 = PASSA, 0 = FALHA. -/
@[export maxwellkey_loewner_check]
def maxwellkey_loewner_check (M_self M_mutual Z₀ eve_factor N0 : Float) : UInt8 :=
  let p := { M_self := M_self, M_mutual := M_mutual, Z₀ := Z₀,
             eve_factor := eve_factor, N0 := N0 }
  if loewner_le_check_float (S_bob_float p) (S_eve_float p) then 1 else 0

/-- Verifica canal exacto para parametros arbitrarios.
    Retorna: 1 = PASSA, 0 = FALHA. -/
@[export maxwellkey_exact_channel_check]
def maxwellkey_exact_channel_check (M_self M_mutual Z₀ eve_factor N0 : Float) : UInt8 :=
  let p := { M_self := M_self, M_mutual := M_mutual, Z₀ := Z₀,
             eve_factor := eve_factor, N0 := N0 }
  if exact_channel_loewner_check p then 1 else 0

/-- Versao legada (hardcoded) — DEPRECATED.
    Mantida para retrocompatibilidade com codigo C existente.
    Usa os parametros de TwoParallelStrips. -/
@[export maxwellkey_init]
def maxwellkey_init : UInt8 :=
  if all_security_checks_pass two_parallel_strips then 1 else 0

end VerifiedFirmware

end MaxwellKey
