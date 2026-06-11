/-
  MaxwellKey / Examples / TwoParallelStrips.lean
  -----------------------------------------------
  Instanciacao concreta para duas pistas paralelas
  numa PCB FR-4 a 100 MHz.

  Parametros tipicos (literatura):
  - C_self = 5 pF, L_self = 50 nH
  - C_mutual = 0.5 pF, M_mutual = 5 nH
  - f = 100 MHz, Z0 = 50 Ohm
  - Eve a 5x a distancia, T = 290 K, B = 1 MHz

  Valores calculados para omega = 2pi*100e6:
  - M_self ~ 0.003109761664971414
  - M_mutual ~ 0.000004150620831811415
  - N0 ~ 4.0038821e-15

  NOTA: Estes valores correspondem a uma geometria PCB especifica
  (pistas finas, separacao pequena). Sao DIFERENTES dos valores do
  fallback simulator (scripts/params.json: M_self=0.21, M_mutual=0.022)
  e dos valores "typical" de teste (TemplateRealParams: M_self=0.6).
  Cada conjunto serve para um proposito diferente; o teorema e robusto
  para qualquer geometria que satisfaca weak_coupling.

  Este ficheiro demonstra AMBOS os teoremas:
  1. O teorema original (f >= 3) via SecrecyParams
  2. O teorema generalizado (f^2 >= min_f_sq) via DegradednessParamsGeneral
-/

import Mathlib.Data.Real.Basic
import Mathlib.Analysis.SpecialFunctions.Log.Base
import Mathlib.Tactic.NormNum
import Mathlib.Tactic.Linarith
import MaxwellKey.SecrecyCapacity
import MaxwellKeyPLUS.DegradednessGeneral
import MaxwellKeyPLUS.SecrecyCapacityGeneral

namespace MaxwellKey

namespace TwoParallelStrips

open SecrecyParams

/-- Valores fisicos (calculados previamente para evitar noncomputability com Real.pi). -/
def M_self_val : ℝ := 0.003109761664971414
def M_mutual_val : ℝ := 0.000004150620831811415
def Z₀_val : ℝ := 50.0
def eve_factor : ℝ := 5.0
def N0_val : ℝ := 4.0038821e-15

/-- Instancia concreta de SecrecyParams (teorema original, f >= 3). -/
def example_params : SecrecyParams where
  M_self := M_self_val
  M_mutual := M_mutual_val
  Z₀ := Z₀_val
  f := eve_factor
  h_Z₀_pos := by norm_num [Z₀_val]
  h_f_ge_three := by norm_num [eve_factor]
  h_weak := by norm_num [M_self_val, M_mutual_val]
  h_M_self_pos := by norm_num [M_self_val]
  N0 := N0_val
  h_N0_pos := by norm_num [N0_val]

/-- Verificacao: o teorema de capacidade de segredo positiva aplica-se. -/
lemma secrecy_pos_applies :
    secrecy_capacity example_params > 0 :=
  secrecy_capacity_pos example_params

/-- Prova auxiliar: |M_mutual| < |M_self| (condicao mais fraca que weak coupling). -/
lemma h_mut_lt_self : |M_mutual_val| < |M_self_val| := by
  have h_weak : |M_mutual_val| < |M_self_val| / 2 := by
    unfold M_self_val M_mutual_val; norm_num
  nlinarith [h_weak, abs_nonneg M_self_val]

/-- Verificacao: f^2 >= min_f_sq para os valores do exemplo.
    f^2 = 25, min_f_sq ~ 1.00000003, logo 25 >= 1.00000003 OK. -/
lemma f_sq_ge_min : eve_factor^2 ≥ min_f_sq M_self_val M_mutual_val h_mut_lt_self := by
  have h_min_eq : min_f_sq M_self_val M_mutual_val h_mut_lt_self
    = (M_self_val^2 + M_mutual_val^2) * (M_self_val + M_mutual_val)^2
      / (M_self_val^2 - M_mutual_val^2)^2 := by
    simp only [min_f_sq]
  rw [h_min_eq]
  have h_denom_pos : (M_self_val^2 - M_mutual_val^2)^2 > 0 := by
    have h_sq : M_self_val^2 > M_mutual_val^2 := by
      apply sq_lt_sq.mpr
      exact h_mut_lt_self
    nlinarith
  apply (div_le_iff₀ h_denom_pos).mpr
  unfold M_self_val M_mutual_val eve_factor
  norm_num

/-- Instancia concreta de DegradednessParamsGeneral (teorema generalizado, min_f_sq). -/
def example_params_general : DegradednessParamsGeneral where
  M_self := M_self_val
  M_mutual := M_mutual_val
  Z₀ := Z₀_val
  f := eve_factor
  h_Z₀_pos := by unfold Z₀_val; norm_num
  h_weak := by unfold M_self_val M_mutual_val; norm_num
  h_M_self_pos := by unfold M_self_val; norm_num
  h_f_sq_ge_min := f_sq_ge_min

/-- Verificacao: o teorema generalizado de degradedness aplica-se.
    S_bob >=_L S_eve_matrix sob a condicao f^2 >= min_f_sq. -/
lemma degradedness_general_applies :
    Matrix.loewner_le
      (DegradednessParamsGeneral.S_bob example_params_general)
      (DegradednessParamsGeneral.S_eve_matrix example_params_general) :=
  DegradednessParamsGeneral.degradedness_loewner_general example_params_general

/-- Instancia concreta de SecrecyParamsGeneral (teorema principal generalizado). -/
def example_params_secrecy_general : SecrecyParamsGeneral :=
  { toDegradednessParamsGeneral := example_params_general
    N0 := N0_val
    h_N0_pos := by unfold N0_val; norm_num }

/-- Verificacao: a capacidade de segredo generalizada e positiva.
    Este e o teorema principal com o limiar otimo min_f_sq. -/
lemma secrecy_pos_general_applies :
    SecrecyParamsGeneral.secrecy_capacity example_params_secrecy_general > 0 :=
  SecrecyParamsGeneral.secrecy_capacity_pos example_params_secrecy_general

end TwoParallelStrips

end MaxwellKey
