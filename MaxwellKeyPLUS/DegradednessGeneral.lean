/- Condição ótima para degradedness: f² ≥ min_f_sq(M_self, M_mutual).

  AVISO DE NOMENCLATURA:
  Neste modulo, M_self e M_mutual sao PARAMETROS NORMALIZADOS
  (adimensionais, Z0 * |Y|). NAO sao as indutancias fisicas (Henry).
  Ver AdmittanceMatrix.lean para o modelo fisico completo com
  C_self, L_self, C_mutual, M_mutual (Henry).
-/

import Mathlib.Data.Matrix.Basic
import Mathlib.Data.Real.Basic
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Ring
import Mathlib.Tactic.FieldSimp
import MaxwellKey.LoewnerOrder

namespace MaxwellKey

noncomputable def min_f_sq (M_self M_mutual : ℝ) (h : |M_mutual| < |M_self|) : ℝ :=
  ((M_self^2 + M_mutual^2) * (M_self + M_mutual)^2) / (M_self^2 - M_mutual^2)^2

section MinFSqProperties

lemma min_f_sq_denom_pos {M_self M_mutual : ℝ} (h : |M_mutual| < |M_self|) :
    (M_self^2 - M_mutual^2)^2 > 0 := by
  have h1 : M_self^2 > M_mutual^2 := by apply sq_lt_sq.mpr; exact h
  nlinarith [h1]

/-- min_f_sq > 1 sob acoplamento fraco (LEMA AUXILIAR — NAO USADO).
    Nao e usado atualmente nas provas principais.
    Mantido como resultado matematico independente; pode ser util
    para futuras extensoes (ex: limites inferiores para capacidade). -/
lemma min_f_sq_gt_one {M_self M_mutual : ℝ} (h : |M_mutual| < |M_self|)
    (h_same_sign : M_self * M_mutual > 0) :
    min_f_sq M_self M_mutual h > 1 := by
  simp only [min_f_sq]
  have h_denom_pos := min_f_sq_denom_pos h
  have h_num : (M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 > (M_self^2 - M_mutual^2)^2 := by
    have h_eq : (M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 - (M_self^2 - M_mutual^2)^2
              = 2 * M_self * M_mutual * (M_self + M_mutual)^2 := by ring
    have h_pos : 2 * M_self * M_mutual * (M_self + M_mutual)^2 > 0 := by
      have h1 : M_self * M_mutual > 0 := h_same_sign
      nlinarith [h1, sq_nonneg (M_self + M_mutual)]
    nlinarith [h_eq, h_pos]
  have h_pos : (M_self^2 - M_mutual^2)^2 > 0 := h_denom_pos
  have h_le : (M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 / (M_self^2 - M_mutual^2)^2 > 1 := by
    have h_eq : (M_self^2 - M_mutual^2)^2 / (M_self^2 - M_mutual^2)^2 = 1 := by
      have h_ne : (M_self^2 - M_mutual^2)^2 ≠ 0 := by nlinarith [h_denom_pos]
      exact div_self h_ne
    rw [←h_eq]
    have h_eq2 : (M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 / (M_self^2 - M_mutual^2)^2
               - (M_self^2 - M_mutual^2)^2 / (M_self^2 - M_mutual^2)^2
               = ((M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 - (M_self^2 - M_mutual^2)^2) / (M_self^2 - M_mutual^2)^2 := by
      rw [sub_div]
    have h_pos2 : ((M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 - (M_self^2 - M_mutual^2)^2) / (M_self^2 - M_mutual^2)^2 > 0 := by
      apply div_pos
      · nlinarith [h_num]
      · nlinarith [h_denom_pos]
    nlinarith [h_eq2, h_pos2]
  exact h_le

lemma min_f_sq_tends_to_one {M_self : ℝ} (h_ms : M_self ≠ 0) :
    min_f_sq M_self 0 (by simp [h_ms]) = 1 := by
  simp [min_f_sq]
  have h1 : M_self^2 ≠ 0 := pow_ne_zero 2 h_ms
  field_simp [h1]

lemma min_f_sq_le_five {M_self M_mutual : ℝ} (h_weak : |M_mutual| < |M_self| / 2) :
    let h : |M_mutual| < |M_self| := by nlinarith [h_weak, abs_nonneg M_self]
    min_f_sq M_self M_mutual h ≤ 5 := by
  intro h
  have h_cases : M_self > 0 ∨ M_self < 0 := by
    by_contra h_contra
    push_neg at h_contra
    have h_ms_zero : M_self = 0 := by linarith [h_contra.1, h_contra.2]
    rw [h_ms_zero] at h_weak
    norm_num at h_weak
    all_goals nlinarith [abs_nonneg M_mutual]
  cases h_cases with
  | inl h_ms_pos =>
    have h_abs_ms : |M_self| = M_self := abs_of_pos h_ms_pos
    have h1 : M_mutual^2 < (M_self / 2)^2 := by
      have h_pos2 : M_self / 2 > 0 := by linarith [h_ms_pos]
      have h2 : |M_mutual| < M_self / 2 := by rw [h_abs_ms] at h_weak; linarith [h_weak]
      have h3 : M_mutual^2 < (M_self / 2)^2 := by
        apply sq_lt_sq.mpr
        rw [abs_of_pos h_pos2]
        exact h2
      exact h3
    have h_strong : M_self^2 - 4 * M_mutual^2 > 0 := by nlinarith [h1, h_ms_pos]
    have h_denom_pos : (M_self^2 - M_mutual^2)^2 > 0 := by nlinarith [h_ms_pos, h1]
    have h_num : (M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 ≤ 5 * (M_self^2 - M_mutual^2)^2 := by
      nlinarith [sq_nonneg (M_self^2 - M_mutual^2), sq_nonneg (M_self * M_mutual),
                 sq_nonneg (M_self - 2 * M_mutual), sq_nonneg (2 * M_self - M_mutual),
                 sq_nonneg (M_self * (M_self - M_mutual)), sq_nonneg (M_self * (M_self + M_mutual)),
                 sq_nonneg (M_mutual * (M_self - M_mutual)), sq_nonneg (M_mutual * (M_self + M_mutual)),
                 sq_nonneg (M_self^2 - M_self * M_mutual), sq_nonneg (M_self^2 - 4 * M_mutual^2),
                 sq_nonneg (M_mutual^2 - M_self * M_mutual), h_strong]
    have h_le : (M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 / (M_self^2 - M_mutual^2)^2 ≤ 5 := by
      have h_pos : (M_self^2 - M_mutual^2)^2 > 0 := h_denom_pos
      apply (div_le_iff₀ h_pos).mpr
      nlinarith [h_num]
    exact h_le
  | inr h_ms_neg =>
    have h_abs_ms : |M_self| = -M_self := abs_of_neg h_ms_neg
    have h1 : M_mutual^2 < (-M_self / 2)^2 := by
      have h_pos2 : -M_self / 2 > 0 := by linarith [h_ms_neg]
      have h2 : |M_mutual| < -M_self / 2 := by rw [h_abs_ms] at h_weak; linarith [h_weak]
      have h3 : M_mutual^2 < (-M_self / 2)^2 := by
        apply sq_lt_sq.mpr
        rw [abs_of_pos h_pos2]
        exact h2
      exact h3
    have h_strong : M_self^2 - 4 * M_mutual^2 > 0 := by nlinarith [h1, h_ms_neg]
    have h_denom_pos : (M_self^2 - M_mutual^2)^2 > 0 := by nlinarith [show M_self^2 > 0 by nlinarith [h_ms_neg], h1]
    have h_num : (M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 ≤ 5 * (M_self^2 - M_mutual^2)^2 := by
      nlinarith [sq_nonneg (M_self^2 - M_mutual^2), sq_nonneg (M_self * M_mutual),
                 sq_nonneg (M_self - 2 * M_mutual), sq_nonneg (2 * M_self - M_mutual),
                 sq_nonneg (M_self * (M_self - M_mutual)), sq_nonneg (M_self * (M_self + M_mutual)),
                 sq_nonneg (M_mutual * (M_self - M_mutual)), sq_nonneg (M_mutual * (M_self + M_mutual)),
                 sq_nonneg (M_self^2 - M_self * M_mutual), sq_nonneg (M_self^2 - 4 * M_mutual^2),
                 sq_nonneg (M_mutual^2 - M_self * M_mutual), h_strong]
    have h_le : (M_self^2 + M_mutual^2) * (M_self + M_mutual)^2 / (M_self^2 - M_mutual^2)^2 ≤ 5 := by
      have h_pos : (M_self^2 - M_mutual^2)^2 > 0 := h_denom_pos
      apply (div_le_iff₀ h_pos).mpr
      nlinarith [h_num]
    exact h_le

end MinFSqProperties

/-- Lema auxiliar: acoplamento fraco implica |M_mutual| < |M_self|.
    Usado para simplificar a condição de min_f_sq na estrutura. -/
lemma weak_coupling_implies_lt_self (M_self M_mutual : ℝ)
    (h_weak : |M_mutual| < |M_self| / 2) : |M_mutual| < |M_self| := by
  nlinarith [h_weak, abs_nonneg M_self]

structure DegradednessParamsGeneral where
  /-- Parametro de acoplamento proprio normalizado (adimensional).
      Relacionado com a indutancia fisica via M_self = Z0 * |b_self|,
      onde b_self e a susceptancia propria (|Y_self|/omega).
      Ver AdmittanceMatrix.lean para o modelo fisico completo.
      Ver ExactChannelHermitian.lean para a ponte ao canal exato. -/
  M_self : ℝ
  /-- Parametro de acoplamento mutuo normalizado (adimensional).
      NOTA: NAO e a indutancia mutua fisica (que tem unidade Henry).
      E o parametro Z0 * |b_mutual|, onde b_mutual e a susceptancia mutua.
      Ver AdmittanceMatrix.lean para o modelo fisico completo. -/
  M_mutual : ℝ
  Z₀ : ℝ
  f : ℝ
  h_Z₀_pos : Z₀ > 0
  h_weak : |M_mutual| < |M_self| / 2
  h_M_self_pos : M_self > 0
  h_f_sq_ge_min : f^2 ≥ min_f_sq M_self M_mutual
    (weak_coupling_implies_lt_self M_self M_mutual h_weak)

namespace DegradednessParamsGeneral

lemma h_mut_lt_self (p : DegradednessParamsGeneral) : |p.M_mutual| < |p.M_self| := by
  have h1 : |p.M_mutual| < |p.M_self| / 2 := p.h_weak
  nlinarith [h1, abs_nonneg p.M_self]

def S_bob (p : DegradednessParamsGeneral) : Matrix (Fin 2) (Fin 2) ℝ :=
  fun i j =>
    if i = j then p.Z₀^2 * (p.M_self^2 + p.M_mutual^2)
    else p.Z₀^2 * (2 * p.M_self * p.M_mutual)

noncomputable def S_eve_matrix (p : DegradednessParamsGeneral) : Matrix (Fin 2) (Fin 2) ℝ :=
  fun i j =>
    if i = 0 ∧ j = 0 then p.Z₀^2 * (p.M_self + p.M_mutual)^2 / p.f^2
    else 0

lemma quad_form_bob_eq (p : DegradednessParamsGeneral) (x : Fin 2 → ℝ) :
    x 0 * (Matrix.mulVec p.S_bob x) 0 + x 1 * (Matrix.mulVec p.S_bob x) 1
      = p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2
                  + (p.M_mutual * x 0 + p.M_self * x 1)^2) := by
  simp [S_bob, Matrix.mulVec, dotProduct, Finset.sum_fin_eq_sum_range, Finset.sum_range_succ]
  ring

lemma quad_form_eve_eq (p : DegradednessParamsGeneral) (x : Fin 2 → ℝ) :
    x 0 * (Matrix.mulVec p.S_eve_matrix x) 0 + x 1 * (Matrix.mulVec p.S_eve_matrix x) 1
      = p.Z₀^2 * ((p.M_self + p.M_mutual)^2 / p.f^2) * (x 0)^2 := by
  simp [S_eve_matrix, Matrix.mulVec, dotProduct]
  ring

lemma mut_sq_bound (p : DegradednessParamsGeneral) :
    p.M_mutual^2 < (p.M_self / 2)^2 := by
  have h_abs : |p.M_self| = p.M_self := abs_of_pos p.h_M_self_pos
  have h_weak' := p.h_weak
  rw [h_abs] at h_weak'
  have h1 : |p.M_mutual| < p.M_self / 2 := by linarith [h_weak']
  have h_pos2 : p.M_self / 2 > 0 := by linarith [p.h_M_self_pos]
  have h2 : p.M_mutual^2 < (p.M_self / 2)^2 := by
    apply sq_lt_sq.mpr
    rw [abs_of_pos h_pos2]
    exact h1
  exact h2

/-- min_f_sq garante forma quadrática de Bob domina Eve.
    Prova via factorização: o numerador é um quadrado perfeito. -/
lemma min_f_sq_bound (p : DegradednessParamsGeneral) (x : Fin 2 → ℝ) :
    let h_lt := h_mut_lt_self p
    min_f_sq p.M_self p.M_mutual h_lt
      * ((p.M_self * x 0 + p.M_mutual * x 1)^2 + (p.M_mutual * x 0 + p.M_self * x 1)^2)
    ≥ (p.M_self + p.M_mutual)^2 * (x 0)^2 := by
  intro h_lt
  have h_denom_pos := min_f_sq_denom_pos h_lt
  let Q_bob := (p.M_self * x 0 + p.M_mutual * x 1)^2 + (p.M_mutual * x 0 + p.M_self * x 1)^2
  let Q_eve := (p.M_self + p.M_mutual)^2 * (x 0)^2
  let D := (p.M_self^2 - p.M_mutual^2)^2
  let N := (p.M_self^2 + p.M_mutual^2) * (p.M_self + p.M_mutual)^2
  have h_poly : N * Q_bob ≥ Q_eve * D := by
    have h_eq : N * Q_bob - Q_eve * D
              = (p.M_self + p.M_mutual)^2 * (2 * p.M_self * p.M_mutual * x 0
                                              + (p.M_self^2 + p.M_mutual^2) * x 1)^2 := by
      ring
    have h_nonneg : N * Q_bob - Q_eve * D ≥ 0 := by
      rw [h_eq]
      apply mul_nonneg
      · apply sq_nonneg
      · apply sq_nonneg
    linarith [h_nonneg]
  have h1 : min_f_sq p.M_self p.M_mutual h_lt * Q_bob ≥ Q_eve := by
    have h_def : min_f_sq p.M_self p.M_mutual h_lt
               = (p.M_self^2 + p.M_mutual^2) * (p.M_self + p.M_mutual)^2 / (p.M_self^2 - p.M_mutual^2)^2 := by
      simp only [min_f_sq]
    rw [h_def]
    rw [ge_iff_le]
    have h_pos : (p.M_self^2 - p.M_mutual^2)^2 > 0 := by nlinarith [h_denom_pos]
    have h_ne : (p.M_self^2 - p.M_mutual^2)^2 ≠ 0 := by nlinarith [h_denom_pos]
    have h3 : ((p.M_self^2 + p.M_mutual^2) * (p.M_self + p.M_mutual)^2 / (p.M_self^2 - p.M_mutual^2)^2) * Q_bob
            = ((p.M_self^2 + p.M_mutual^2) * (p.M_self + p.M_mutual)^2 * Q_bob) / (p.M_self^2 - p.M_mutual^2)^2 := by
      field_simp [h_ne]
    rw [h3]
    apply (le_div_iff₀ h_pos).mpr
    nlinarith [h_poly]
  nlinarith [h1]

lemma S_bob_ge_S_eve (p : DegradednessParamsGeneral) :
    Matrix.loewner_le p.S_bob p.S_eve_matrix := by
  intro x
  have h_lhs := quad_form_bob_eq p x
  have h_rhs := quad_form_eve_eq p x
  rw [h_lhs, h_rhs]
  have h_pos : p.f^2 > 0 := by
    have hf2 := p.h_f_sq_ge_min
    have h_min_pos : min_f_sq p.M_self p.M_mutual (h_mut_lt_self p) > 0 := by
      simp only [min_f_sq]
      have h_denom_pos := min_f_sq_denom_pos (h_mut_lt_self p)
      have h_num_pos : (p.M_self^2 + p.M_mutual^2) * (p.M_self + p.M_mutual)^2 > 0 := by
        nlinarith [sq_nonneg p.M_self, sq_nonneg p.M_mutual, p.h_M_self_pos]
      apply div_pos
      · exact h_num_pos
      · nlinarith [h_denom_pos]
    nlinarith [hf2, h_min_pos]
  have h_eq : p.Z₀^2 * ((p.M_self + p.M_mutual)^2 / p.f^2) * (x 0)^2
            = (p.Z₀^2 * (p.M_self + p.M_mutual)^2 * (x 0)^2) / p.f^2 := by
    have h_ne : p.f ≠ 0 := by nlinarith [h_pos]
    field_simp [h_ne]
  have h_min := p.h_f_sq_ge_min
  have h_base := min_f_sq_bound p x
  have h_term : (p.M_self * x 0 + p.M_mutual * x 1)^2 + (p.M_mutual * x 0 + p.M_self * x 1)^2 ≥ 0 := by
    nlinarith [sq_nonneg (p.M_self * x 0 + p.M_mutual * x 1),
               sq_nonneg (p.M_mutual * x 0 + p.M_self * x 1)]
  have h_prod : p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2
                         + (p.M_mutual * x 0 + p.M_self * x 1)^2) ≥ 0 := by
    nlinarith [h_term, p.h_Z₀_pos]
  have h_incr : p.f^2 * (p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2
                                  + (p.M_mutual * x 0 + p.M_self * x 1)^2))
              ≥ min_f_sq p.M_self p.M_mutual (h_mut_lt_self p) * (p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2
                                                          + (p.M_mutual * x 0 + p.M_self * x 1)^2)) := by
    nlinarith [h_min, h_prod]
  have h_mul : p.f^2 * (p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2 + (p.M_mutual * x 0 + p.M_self * x 1)^2))
             ≥ p.Z₀^2 * (p.M_self + p.M_mutual)^2 * (x 0)^2 := by
    nlinarith [h_base, h_incr]
  have h_div : (p.Z₀^2 * (p.M_self + p.M_mutual)^2 * (x 0)^2) / p.f^2
             ≤ p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2 + (p.M_mutual * x 0 + p.M_self * x 1)^2) := by
    rw [div_le_iff₀ (by nlinarith [h_pos])]
    linarith [h_mul]
  rw [h_eq]
  nlinarith [h_div, p.h_Z₀_pos]

theorem degradedness_loewner_general (p : DegradednessParamsGeneral) :
    Matrix.loewner_le p.S_bob p.S_eve_matrix :=
  S_bob_ge_S_eve p

end DegradednessParamsGeneral

end MaxwellKey
