/-
  MaxwellKey / Degradedness.lean
  ---------------------------------
  [LEGADO / OBSOLETO]

  Este modulo contem a prova ORIGINAL de degradedness com o limiar
  conservador f >= 3. Foi substituido por DegradednessGeneral.lean
  (MaxwellKeyPLUS), que usa o limiar otimo min_f_sq.

  MANTIDO PARA RETROCOMPATIBILIDADE e como referencia historica.
  Para novos trabalhos, usar DegradednessGeneral.lean.

  Prova que o canal e "degraded" no sentido da ordem de Loewner:
  a matriz de covariancia do sinal de Bob e maior ou igual a matriz
  de covariancia do sinal de Eve (convertida para 2×2).

  Modelo simplificado:
  - S_bob = Z₀² • [[M_self²+M_mutual², 2·M_self·M_mutual],
                   [2·M_self·M_mutual, M_self²+M_mutual²]]
  - S_eve = Z₀² • (M_self+M_mutual)² / f²  (escalar, colocado em (0,0))

  Sob acoplamento fraco |M_mutual| < |M_self|/2 e fator de distancia f >= 3,
  provamos S_bob ≥ₗ S_eve_matrix.
-/

import Mathlib.Data.Matrix.Basic
import Mathlib.Data.Real.Basic
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Ring
import Mathlib.Tactic.FieldSimp
import MaxwellKey.LoewnerOrder

namespace MaxwellKey

/-- Parâmetros para o lema de degradedness. -/
structure DegradednessParams where
  M_self : ℝ
  M_mutual : ℝ
  Z₀ : ℝ
  f : ℝ
  /-- Impedância de terminação positiva. -/
  h_Z₀_pos : Z₀ > 0
  /-- Fator de distância de Eve (>= 3 garante a prova). -/
  h_f_ge_three : f >= 3
  /-- Acoplamento fraco: |M_mutual| < |M_self|/2. -/
  h_weak : |M_mutual| < |M_self| / 2
  /-- Sem perda de generalidade, M_self > 0. -/
  h_M_self_pos : M_self > 0

namespace DegradednessParams

/-- Matriz de covariância do sinal para Bob (real 2×2). -/
def S_bob (p : DegradednessParams) : Matrix (Fin 2) (Fin 2) ℝ :=
  fun i j =>
    if i = j then p.Z₀^2 * (p.M_self^2 + p.M_mutual^2)
    else p.Z₀^2 * (2 * p.M_self * p.M_mutual)

/-- Matriz de covariância do sinal para Eve (escalar em (0,0)). -/
noncomputable def S_eve_matrix (p : DegradednessParams) : Matrix (Fin 2) (Fin 2) ℝ :=
  fun i j =>
    if i = 0 ∧ j = 0 then p.Z₀^2 * (p.M_self + p.M_mutual)^2 / p.f^2
    else 0

/-- O lado esquerdo da forma quadrática de Bob expande para uma soma de quadrados. -/
lemma quad_form_bob_eq (p : DegradednessParams) (x : Fin 2 → ℝ) :
    x 0 * (Matrix.mulVec p.S_bob x) 0 + x 1 * (Matrix.mulVec p.S_bob x) 1
      = p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2
                  + (p.M_mutual * x 0 + p.M_self * x 1)^2) := by
  simp [S_bob, Matrix.mulVec, dotProduct, Finset.sum_fin_eq_sum_range, Finset.sum_range_succ]
  ring

/-- O lado direito da forma quadrática de Eve expande para um único termo. -/
lemma quad_form_eve_eq (p : DegradednessParams) (x : Fin 2 → ℝ) :
    x 0 * (Matrix.mulVec p.S_eve_matrix x) 0 + x 1 * (Matrix.mulVec p.S_eve_matrix x) 1
      = p.Z₀^2 * ((p.M_self + p.M_mutual)^2 / p.f^2) * (x 0)^2 := by
  simp [S_eve_matrix, Matrix.mulVec, dotProduct]
  ring

/-- Como f >= 3, o termo de Eve é limitado superiormente. -/
lemma eve_bound (p : DegradednessParams) (x : Fin 2 → ℝ) :
    p.Z₀^2 * ((p.M_self + p.M_mutual)^2 / p.f^2) * (x 0)^2
      ≤ p.Z₀^2 * ((p.M_self + p.M_mutual)^2 / 9) * (x 0)^2 := by
  have hf : p.f^2 ≥ 9 := by nlinarith [p.h_f_ge_three]
  have h_pos : p.f^2 > 0 := by nlinarith [p.h_f_ge_three]
  have h_nonneg : (p.M_self + p.M_mutual)^2 ≥ 0 := sq_nonneg (p.M_self + p.M_mutual)
  have h_div : (p.M_self + p.M_mutual)^2 / p.f^2 ≤ (p.M_self + p.M_mutual)^2 / 9 := by
    have h1 : (p.M_self + p.M_mutual)^2 * 9 ≤ (p.M_self + p.M_mutual)^2 * p.f^2 := by
      nlinarith [hf, h_nonneg]
    have h2 : (p.M_self + p.M_mutual)^2 / p.f^2 - (p.M_self + p.M_mutual)^2 / 9 ≤ 0 := by
      have h_ne : p.f ≠ 0 := by nlinarith [p.h_f_ge_three]
      have h3 : (p.M_self + p.M_mutual)^2 / p.f^2 - (p.M_self + p.M_mutual)^2 / 9
              = ((p.M_self + p.M_mutual)^2 * 9 - (p.M_self + p.M_mutual)^2 * p.f^2) / (p.f^2 * 9) := by
        field_simp [h_ne]
      rw [h3]
      have h4 : (p.M_self + p.M_mutual)^2 * 9 - (p.M_self + p.M_mutual)^2 * p.f^2 ≤ 0 := by
        nlinarith [h1]
      have h5 : p.f^2 * 9 > 0 := by positivity
      apply div_nonpos_of_nonpos_of_nonneg
      · linarith [h4]
      · nlinarith [h5]
    linarith
  have h_le : p.Z₀^2 * ((p.M_self + p.M_mutual)^2 / p.f^2)
              ≤ p.Z₀^2 * ((p.M_self + p.M_mutual)^2 / 9) := by
    apply mul_le_mul_of_nonneg_left h_div
    positivity
  have h_x2 : (x 0)^2 ≥ 0 := sq_nonneg (x 0)
  nlinarith [h_le, h_x2]

/-- De |M_mutual| < |M_self|/2 e M_self > 0 obtém-se M_mutual² < (M_self/2)². -/
lemma mut_sq_bound (p : DegradednessParams) :
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

/-- A matriz de covariância de Bob é maior ou igual à de Eve na ordem de Loewner. -/
lemma S_bob_ge_S_eve (p : DegradednessParams) :
    Matrix.loewner_le p.S_bob p.S_eve_matrix := by
  intro x
  have h_lhs := quad_form_bob_eq p x
  have h_rhs := quad_form_eve_eq p x
  rw [h_lhs, h_rhs]
  have h_pos : p.f^2 > 0 := by nlinarith [p.h_f_ge_three]
  have h_eq : p.Z₀^2 * ((p.M_self + p.M_mutual)^2 / p.f^2) * (x 0)^2
            = (p.Z₀^2 * (p.M_self + p.M_mutual)^2 * (x 0)^2) / p.f^2 := by
    have h_ne : p.f ≠ 0 := by nlinarith [p.h_f_ge_three]
    field_simp [h_ne]
  have hf2 : p.f^2 ≥ 9 := by nlinarith [p.h_f_ge_three]
  -- Prova primeiro para o caso limite f^2 = 9 (mais difícil).
  have h_strong : p.M_self^2 - 4 * p.M_mutual^2 > 0 := by
    nlinarith [mut_sq_bound p, p.h_M_self_pos]
  have h_base : 9 * (p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2
                             + (p.M_mutual * x 0 + p.M_self * x 1)^2))
              ≥ p.Z₀^2 * (p.M_self + p.M_mutual)^2 * (x 0)^2 := by
    -- Completamento do quadrado: expr = a*x0^2 + 2*b*x0*x1 + c*x1^2
    let a := 9 * (p.M_self^2 + p.M_mutual^2) - (p.M_self + p.M_mutual)^2
    let b := 18 * p.M_self * p.M_mutual
    let c := 9 * (p.M_self^2 + p.M_mutual^2)
    have h_a_pos : a > 0 := by
      nlinarith [h_strong, sq_nonneg (p.M_self - p.M_mutual)]
    have h_det : a * c - b^2 ≥ 0 := by
      nlinarith [h_strong, sq_nonneg (p.M_self^2 - p.M_mutual^2),
                 sq_nonneg (p.M_self * p.M_mutual),
                 sq_nonneg (p.M_self - p.M_mutual),
                 sq_nonneg (p.M_self + p.M_mutual),
                 sq_nonneg (p.M_self^2 + p.M_mutual^2),
                 sq_nonneg (p.M_self * (p.M_self - p.M_mutual)),
                 sq_nonneg (p.M_self * (p.M_self + p.M_mutual)),
                 sq_nonneg (p.M_mutual * (p.M_self - p.M_mutual)),
                 sq_nonneg (p.M_mutual * (p.M_self + p.M_mutual)),
                 sq_nonneg (p.M_self^2 - p.M_self * p.M_mutual),
                 sq_nonneg (p.M_mutual^2 - p.M_self * p.M_mutual)]
    have h_eq : 9 * ((p.M_self * x 0 + p.M_mutual * x 1)^2 + (p.M_mutual * x 0 + p.M_self * x 1)^2)
                - (p.M_self + p.M_mutual)^2 * (x 0)^2
              = (a * x 0 + b * x 1)^2 / a + (a * c - b^2) * (x 1)^2 / a := by
      field_simp
      ring
    have h_nonneg : (a * x 0 + b * x 1)^2 / a + (a * c - b^2) * (x 1)^2 / a ≥ 0 := by
      have h1 : (a * x 0 + b * x 1)^2 / a ≥ 0 := by
        apply div_nonneg
        · apply sq_nonneg
        · linarith [h_a_pos]
      have h2 : (a * c - b^2) * (x 1)^2 / a ≥ 0 := by
        apply div_nonneg
        · apply mul_nonneg
          · linarith [h_det]
          · apply sq_nonneg
        · linarith [h_a_pos]
      linarith [h1, h2]
    nlinarith [h_eq, h_nonneg, p.h_Z₀_pos]
  -- Para f^2 >= 9, o LHS só aumenta porque a soma de quadrados é não negativa.
  have h_term : (p.M_self * x 0 + p.M_mutual * x 1)^2 + (p.M_mutual * x 0 + p.M_self * x 1)^2 ≥ 0 := by
    nlinarith [sq_nonneg (p.M_self * x 0 + p.M_mutual * x 1),
               sq_nonneg (p.M_mutual * x 0 + p.M_self * x 1)]
  have h_prod : p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2
                         + (p.M_mutual * x 0 + p.M_self * x 1)^2) ≥ 0 := by
    nlinarith [h_term, p.h_Z₀_pos]
  have h_incr : p.f^2 * (p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2
                                  + (p.M_mutual * x 0 + p.M_self * x 1)^2))
              ≥ 9 * (p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2
                              + (p.M_mutual * x 0 + p.M_self * x 1)^2)) := by
    nlinarith [hf2, h_prod]
  -- Converte a desigualdade multiplicada de volta para a forma com divisão.
  have h_mul : p.f^2 * (p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2 + (p.M_mutual * x 0 + p.M_self * x 1)^2))
             ≥ p.Z₀^2 * (p.M_self + p.M_mutual)^2 * (x 0)^2 := by
    linarith [h_base, h_incr]
  have h_div : (p.Z₀^2 * (p.M_self + p.M_mutual)^2 * (x 0)^2) / p.f^2
             ≤ p.Z₀^2 * ((p.M_self * x 0 + p.M_mutual * x 1)^2 + (p.M_mutual * x 0 + p.M_self * x 1)^2) := by
    rw [div_le_iff₀ h_pos]
    linarith [h_mul]
  rw [h_eq]
  exact h_div

/-- Teorema principal: o canal é degraded na ordem de Loewner. -/
theorem degradedness_loewner (p : DegradednessParams) :
    Matrix.loewner_le p.S_bob p.S_eve_matrix :=
  S_bob_ge_S_eve p

end DegradednessParams

end MaxwellKey
