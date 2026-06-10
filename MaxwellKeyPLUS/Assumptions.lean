/-
  MaxwellKeyPLUS / Assumptions.lean
  ----------------------------------
  Manifesto formal das hipoteses fisicas e matematicas
  sob as quais os teoremas do MaxwellKey sao validos.

  ATUALIZACAO (10 Jun 2026): distance_factor_valid agora usa
  o limiar otimo min_f_sq em vez do limiar fixo f^2 >= 5.
-/

import Mathlib.Data.Real.Basic
import Mathlib.Tactic.Linarith
import MaxwellKeyPLUS.DegradednessGeneral

namespace MaxwellKey

namespace Assumptions

/-- 1. REGIME QUASE-ESTATICO
    O comprimento da pista deve ser muito menor que lambda/4.
-/
def quasi_static_valid (frequency_hz : ℝ) (trace_length_m : ℝ) : Prop :=
  trace_length_m < (3e8 / (4 * frequency_hz))

/-- 2. ACOPLAMENTO FRACO
    |M_mutual| < |M_self| / 2.
-/
def weak_coupling (M_self M_mutual : ℝ) : Prop :=
  |M_mutual| < |M_self| / 2

/-- Lema auxiliar: weak_coupling implica |M_mutual| < |M_self|,
    que e a hipotese exigida por min_f_sq. -/
lemma weak_coupling_implies_lt_self {M_self M_mutual : ℝ} (h : weak_coupling M_self M_mutual) :
    |M_mutual| < |M_self| := by
  have h' : |M_mutual| < |M_self| / 2 := h
  nlinarith [h', abs_nonneg M_self]

/-- 3. FATOR DE DISTANCIA (ATUALIZADO — usa limiar otimo)
    No MaxwellKeyPLUS: f^2 >= min_f_sq(M_self, M_mutual), o limiar exato.

    NOTA DE RETROCOMPATIBILIDADE: Sob weak_coupling,
    min_f_sq <= 5 (provado em DegradednessGeneral.min_f_sq_le_five).
    Portanto, f^2 >= 5 e suficiente e todos os exemplos que usam
    f^2 >= 5 continuam validos.
-/
def distance_factor_valid (M_self M_mutual f : ℝ) (h_weak : weak_coupling M_self M_mutual) : Prop :=
  f^2 ≥ min_f_sq M_self M_mutual (weak_coupling_implies_lt_self h_weak)

/-- 4. RUIDO BRANCO E DESCORRELACIONADO
    Matriz de covariancia do ruido e N0*I.
-/
def white_noise (N0 : ℝ) : Prop :=
  N0 > 0

/-- 5. EVE COM CANAL ESCALAR
    Eve tem uma unica antena.

    NOTA: Esta hipotese e um placeholder. No modelo actual,
    Eve recebe um canal escalar H_eve (uma unica saida).
    Uma formalizacao completa exigiria modelar a matriz de
    canal de Eve como um vetor de dimensao 1.
-/
def eve_scalar_channel : Prop :=
  True

/-- 6. LINEARIDADE

    NOTA: Placeholder. O modelo de canal e linear por construcao
    (matrizes de admitancia, matrizes de canal). Uma formalizacao
    completa exigiria definir linearidade como H(a*x + b*y) = a*H(x) + b*H(y).
-/
def linearity : Prop :=
  True

/-- 7. COVARIANCIA DE ENTRADA UNITARIA

    NOTA: Placeholder. O modelo assume potencia de entrada unitaria
    para simplificar as formulas. Uma formalizacao completa exigiria
    modelar a matriz de covariancia da entrada explicitamente.
-/
def unit_input_power : Prop :=
  True

/-- Verificacao: todas as hipoteses do exemplo numerico.
    Requer uma prova explicita de weak_coupling como argumento. -/
def all_assumptions_satisfied (M_self M_mutual f : ℝ) (N0 : ℝ)
    (frequency_hz trace_length_m : ℝ) (h_weak : weak_coupling M_self M_mutual) : Prop :=
  quasi_static_valid frequency_hz trace_length_m ∧
  distance_factor_valid M_self M_mutual f h_weak ∧
  white_noise N0 ∧
  eve_scalar_channel ∧
  linearity ∧
  unit_input_power

end Assumptions

end MaxwellKey
