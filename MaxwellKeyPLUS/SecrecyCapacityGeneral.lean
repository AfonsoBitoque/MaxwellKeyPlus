/-
  MaxwellKeyPLUS / SecrecyCapacityGeneral.lean
  --------------------------------------------
  Teorema principal generalizado: a capacidade de segredo
  e estritamente positiva sob a condicao f^2 >= min_f_sq
  (o limiar otimo), em vez do conservador f >= 3.

  Estende SecrecyCapacity.lean com a hipotese generalizada.
-/

import Mathlib.Data.Real.Basic
import Mathlib.Analysis.SpecialFunctions.Log.Base
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Ring
import Mathlib.Tactic.FieldSimp
import MaxwellKeyPLUS.DegradednessGeneral

namespace MaxwellKey

/-- Parametros para o teorema de capacidade de segredo generalizado. -/
structure SecrecyParamsGeneral extends DegradednessParamsGeneral where
  N0 : ℝ
  h_N0_pos : N0 > 0

namespace SecrecyParamsGeneral

/-- S_eve escalar (para calculo de capacidade). -/
noncomputable def S_eve_scalar (p : SecrecyParamsGeneral) : ℝ :=
  p.Z₀^2 * (p.M_self + p.M_mutual)^2 / p.f^2

/-- Argumento do logaritmo para a capacidade de Bob. -/
noncomputable def arg_bob (p : SecrecyParamsGeneral) : ℝ :=
  (1 + (p.Z₀^2 / p.N0) * (p.M_self^2 + p.M_mutual^2))^2
  - ((p.Z₀^2 / p.N0) * (2 * p.M_self * p.M_mutual))^2

/-- Argumento do logaritmo para a capacidade de Eve. -/
noncomputable def arg_eve (p : SecrecyParamsGeneral) : ℝ :=
  1 + p.S_eve_scalar / p.N0

/-- Capacidade de Bob (por uso do canal). -/
noncomputable def capacity_bob (p : SecrecyParamsGeneral) : ℝ :=
  (1 / 2) * Real.logb 2 p.arg_bob

/-- Capacidade de Eve (por uso do canal). -/
noncomputable def capacity_eve (p : SecrecyParamsGeneral) : ℝ :=
  (1 / 2) * Real.logb 2 p.arg_eve

/-- Capacidade de segredo C_s = C_bob - C_eve. -/
noncomputable def secrecy_capacity (p : SecrecyParamsGeneral) : ℝ :=
  p.capacity_bob - p.capacity_eve

/-- Expande o argumento de Bob para a forma simplificada. -/
lemma arg_bob_eq (p : SecrecyParamsGeneral) :
    p.arg_bob = 1 + 2 * (p.Z₀^2 / p.N0) * (p.M_self^2 + p.M_mutual^2)
                + (p.Z₀^2 / p.N0)^2 * (p.M_self^2 - p.M_mutual^2)^2 := by
  simp [arg_bob]
  field_simp
  ring

/-- O argumento de Eve expande para: 1 + (Z0^2/N0)*(M_self+M_mutual)^2/f^2. -/
lemma arg_eve_eq (p : SecrecyParamsGeneral) :
    p.arg_eve = 1 + (p.Z₀^2 / p.N0) * ((p.M_self + p.M_mutual)^2 / p.f^2) := by
  simp [arg_eve, S_eve_scalar]
  field_simp

/-- O argumento de Bob e estritamente maior que o argumento de Eve,
    usando a hipotese generalizada f^2 >= min_f_sq. -/
lemma arg_bob_gt_arg_eve (p : SecrecyParamsGeneral) :
    p.arg_bob > p.arg_eve := by
  rw [arg_bob_eq, arg_eve_eq]
  let α := p.Z₀^2 / p.N0
  have h_α_pos : α > 0 := by
    apply div_pos
    · have h : p.Z₀^2 > 0 := by nlinarith [p.h_Z₀_pos]
      linarith [h]
    · exact p.h_N0_pos
  -- Subtrai 1 de ambos os lados e divide por alpha (> 0).
  suffices 2 * (p.M_self^2 + p.M_mutual^2) + α * (p.M_self^2 - p.M_mutual^2)^2
         > (p.M_self + p.M_mutual)^2 / p.f^2 by
    have h : 1 + 2 * α * (p.M_self^2 + p.M_mutual^2) + α^2 * (p.M_self^2 - p.M_mutual^2)^2
           > 1 + α * ((p.M_self + p.M_mutual)^2 / p.f^2) := by
      have h1 : α * (2 * (p.M_self^2 + p.M_mutual^2) + α * (p.M_self^2 - p.M_mutual^2)^2)
              > α * ((p.M_self + p.M_mutual)^2 / p.f^2) := by
        apply mul_lt_mul_of_pos_left
        · exact this
        · exact h_α_pos
      ring_nf at h1 ⊢
      linarith [h1]
    exact h
  -- Usa f^2 >= min_f_sq para majorar o termo de Eve.
  have h_lt : |p.M_mutual| < |p.M_self| := by
    have h := p.h_weak
    nlinarith [h, abs_nonneg p.M_self]
  have h_min_sq_pos : min_f_sq p.M_self p.M_mutual h_lt > 0 := by
    have h_denom_pos := min_f_sq_denom_pos h_lt
    have h_num_pos : (p.M_self^2 + p.M_mutual^2) * (p.M_self + p.M_mutual)^2 > 0 := by
      have h1 : p.M_self^2 + p.M_mutual^2 > 0 := by
        nlinarith [sq_nonneg p.M_self, sq_nonneg p.M_mutual, p.h_M_self_pos]
      have h2 : (p.M_self + p.M_mutual)^2 > 0 := by
        by_contra hle
        have hzero : p.M_self + p.M_mutual = 0 := by nlinarith [sq_nonneg (p.M_self + p.M_mutual)]
        have h_eq : p.M_mutual = -p.M_self := by linarith
        rw [h_eq] at h_lt
        have : |-p.M_self| = |p.M_self| := abs_neg _
        rw [this] at h_lt
        linarith [h_lt]
      nlinarith
    apply div_pos
    · exact h_num_pos
    · nlinarith [h_denom_pos]
  have h_f_sq_pos : p.f^2 > 0 := by nlinarith [p.h_f_sq_ge_min, h_min_sq_pos]
  have h_bound : (p.M_self + p.M_mutual)^2 / p.f^2 ≤ (p.M_self + p.M_mutual)^2 / min_f_sq p.M_self p.M_mutual h_lt := by
    have h_sq_nonneg : (p.M_self + p.M_mutual)^2 ≥ 0 := sq_nonneg _
    have h_inv : 1 / p.f^2 ≤ 1 / min_f_sq p.M_self p.M_mutual h_lt :=
      (one_div_le_one_div h_f_sq_pos h_min_sq_pos).mpr p.h_f_sq_ge_min
    calc
      (p.M_self + p.M_mutual)^2 / p.f^2 = (p.M_self + p.M_mutual)^2 * (1 / p.f^2) := by ring
      _ ≤ (p.M_self + p.M_mutual)^2 * (1 / min_f_sq p.M_self p.M_mutual h_lt) := by
        nlinarith [h_inv, h_sq_nonneg]
      _ = (p.M_self + p.M_mutual)^2 / min_f_sq p.M_self p.M_mutual h_lt := by ring
  -- Agora basta provar a desigualdade com min_f_sq no denominador.
  suffices 2 * (p.M_self^2 + p.M_mutual^2) + α * (p.M_self^2 - p.M_mutual^2)^2
         > (p.M_self + p.M_mutual)^2 / min_f_sq p.M_self p.M_mutual h_lt by
    nlinarith [this, h_bound]
  -- O termo alpha*(...) e nao negativo.
  have h_extra : α * (p.M_self^2 - p.M_mutual^2)^2 ≥ 0 := by
    apply mul_nonneg
    · linarith [h_α_pos]
    · apply sq_nonneg
  -- Portanto basta provar a desigualdade base sem o termo alpha.
  suffices 2 * (p.M_self^2 + p.M_mutual^2) > (p.M_self + p.M_mutual)^2 / min_f_sq p.M_self p.M_mutual h_lt by
    nlinarith [this, h_extra]
  -- Substitui min_f_sq = N/D e simplifica.
  have h_min_def : min_f_sq p.M_self p.M_mutual h_lt
    = (p.M_self^2 + p.M_mutual^2) * (p.M_self + p.M_mutual)^2 / (p.M_self^2 - p.M_mutual^2)^2 := by
    simp only [min_f_sq]
  rw [h_min_def]
  -- RHS = (M_self+M_mutual)^2 * (M_self^2-M_mutual^2)^2 / ((M_self^2+M_mutual^2)*(M_self+M_mutual)^2)
  --     = (M_self^2-M_mutual^2)^2 / (M_self^2+M_mutual^2)
  have h_denom_pos : (p.M_self^2 - p.M_mutual^2)^2 > 0 := min_f_sq_denom_pos h_lt
  have h_num_pos : p.M_self^2 + p.M_mutual^2 > 0 := by
    nlinarith [sq_nonneg p.M_self, sq_nonneg p.M_mutual, p.h_M_self_pos]
  have h_rhs_simp : (p.M_self + p.M_mutual)^2 / ((p.M_self^2 + p.M_mutual^2) * (p.M_self + p.M_mutual)^2 / (p.M_self^2 - p.M_mutual^2)^2)
                 = (p.M_self^2 - p.M_mutual^2)^2 / (p.M_self^2 + p.M_mutual^2) := by
    have hA : (p.M_self + p.M_mutual)^2 ≠ 0 := by
      intro hzero
      have hsum_zero : p.M_self + p.M_mutual = 0 := by nlinarith [sq_nonneg (p.M_self + p.M_mutual)]
      have h_eq : p.M_mutual = -p.M_self := by linarith
      rw [h_eq] at h_lt
      have : |-p.M_self| = |p.M_self| := abs_neg _
      rw [this] at h_lt
      linarith [h_lt]
    have hB : p.M_self^2 + p.M_mutual^2 ≠ 0 := by nlinarith [sq_nonneg p.M_self, sq_nonneg p.M_mutual, p.h_M_self_pos]
    have hC : (p.M_self^2 - p.M_mutual^2)^2 ≠ 0 := by nlinarith [sq_pos_of_pos (min_f_sq_denom_pos h_lt)]
    have h_cancelamento (a b c : ℝ) (ha : a ≠ 0) (hb : b ≠ 0) (hc : c ≠ 0) :
        a / (b * a / c) = c / b := by
      field_simp
    exact h_cancelamento ((p.M_self + p.M_mutual)^2) (p.M_self^2 + p.M_mutual^2) ((p.M_self^2 - p.M_mutual^2)^2) hA hB hC
  rw [h_rhs_simp]
  -- Desigualdade final: 2*(M_self^2+M_mutual^2) > (M_self^2-M_mutual^2)^2 / (M_self^2+M_mutual^2)
  -- Multiplica ambos os lados por (M_self^2+M_mutual^2) > 0:
  -- 2*(M_self^2+M_mutual^2)^2 > (M_self^2-M_mutual^2)^2
  have h_sq_lt : (p.M_self^2 - p.M_mutual^2)^2 < 2 * (p.M_self^2 + p.M_mutual^2)^2 := by
    have h_diff_pos : p.M_self^2 - p.M_mutual^2 > 0 := by
      have h_sq : p.M_self^2 > p.M_mutual^2 := sq_lt_sq.mpr h_lt
      nlinarith [h_sq]
    nlinarith [sq_nonneg (p.M_self^2 + p.M_mutual^2), h_diff_pos]
  -- 2*(M^2+m^2) > (M^2-m^2)^2/(M^2+m^2)  iff  2*(M^2+m^2)^2 > (M^2-m^2)^2
  apply (div_lt_iff₀ h_num_pos).mpr
  nlinarith [h_sq_lt]

/-- Os argumentos sao estritamente positivos (necessario para os logaritmos). -/
lemma arg_bob_pos (p : SecrecyParamsGeneral) : p.arg_bob > 0 := by
  rw [arg_bob_eq]
  have h1 : p.Z₀^2 / p.N0 > 0 := by
    apply div_pos
    · have h : p.Z₀^2 > 0 := by nlinarith [p.h_Z₀_pos]
      linarith [h]
    · exact p.h_N0_pos
  have h2 : (p.M_self^2 - p.M_mutual^2)^2 ≥ 0 := sq_nonneg _
  nlinarith [h1, h2, sq_nonneg p.M_self, sq_nonneg p.M_mutual]

lemma arg_eve_pos (p : SecrecyParamsGeneral) : p.arg_eve > 0 := by
  rw [arg_eve_eq]
  have h1 : p.Z₀^2 / p.N0 > 0 := by
    apply div_pos
    · have h : p.Z₀^2 > 0 := by nlinarith [p.h_Z₀_pos]
      linarith [h]
    · exact p.h_N0_pos
  have h2 : (p.M_self + p.M_mutual)^2 / p.f^2 ≥ 0 := by
    apply div_nonneg
    · apply sq_nonneg
    · nlinarith [sq_nonneg p.f]
  nlinarith [h1, h2]

/-- Teorema principal generalizado: a capacidade de segredo e estritamente positiva
    sob a condicao f^2 >= min_f_sq. -/
theorem secrecy_capacity_pos (p : SecrecyParamsGeneral) :
    p.secrecy_capacity > 0 := by
  have h_arg : p.arg_bob > p.arg_eve := arg_bob_gt_arg_eve p
  have h_bob_pos : p.arg_bob > 0 := arg_bob_pos p
  have h_eve_pos : p.arg_eve > 0 := arg_eve_pos p
  have h_log : Real.logb 2 p.arg_bob > Real.logb 2 p.arg_eve := by
    apply Real.logb_lt_logb
    all_goals nlinarith [h_arg, h_bob_pos, h_eve_pos]
  dsimp [secrecy_capacity, capacity_bob, capacity_eve]
  linarith

end SecrecyParamsGeneral

end MaxwellKey
