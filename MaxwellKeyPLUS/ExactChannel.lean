/-
  MaxwellKeyPLUS / ExactChannel.lean
  -----------------------------------
  AVISO: A prova de monotonia aqui apresentada aplica-se
  a matrizes REAIS simetricas da forma [[a, b], [b, a]] com a,b ∈ ℝ.
  A extensao ao modelo fisico completo esta CONCLUIDA em
  ExactChannelHermitian.lean, onde se prova que H_bob H_bob^†
  se reduz exatamente a uma matriz real [[a,b],[b,a]] sob as
  hipoteses fisicas do MaxwellKey (Y imaginaria pura, Z0 real).
  Ver hermitian_to_real_form e exact_channel_applies_to_physics.
  Este modulo NAO e usado nos teoremas principais do MaxwellKey
  (SecrecyCapacity.lean nao importa ExactChannel.lean).

  Prova que a transformação exacta de canal
    f(A) = I - (I + A)⁻¹
  é monótona na ordem de Loewner para matrizes
  da forma [[a, b], [b, a]].

  Estratégia: em vez de usar a inversa matricial diretamente,
  calculamos a forma explícita de f(A) para matrizes 2×2 simétricas.
  Para A = [[a, b], [b, a]]:
    f(A) = [[1 - (1+a)/((1+a)²-b²), b/((1+a)²-b²)],
            [b/((1+a)²-b²), 1 - (1+a)/((1+a)²-b²)]]
  = symm_matrix p q com p = 1 - (1+a)/((1+a)²-b²), q = b/((1+a)²-b²).

  Os "autovalores" são p+q = 1 - 1/(1+a+b) e p-q = 1 - 1/(1+a-b).
  A monotonia segue da monotonia escalar de g(t) = 1 - 1/(1+t).
-/

import Mathlib.Data.Matrix.Basic
import Mathlib.Data.Real.Basic
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Ring
import Mathlib.Tactic.FieldSimp
import Mathlib.Tactic.Positivity
import Mathlib.Tactic.FinCases
import MaxwellKey.LoewnerOrder
import MaxwellKeyPLUS.DegradednessGeneral

open Real
open Matrix

namespace MaxwellKey

namespace ExactChannel

/-- Constrói uma matriz da forma [[a, b], [b, a]]. -/
def symm_matrix (a b : ℝ) : Matrix (Fin 2) (Fin 2) ℝ :=
  λ i j => if i = j then a else b

/-- Forma quadrática de uma matriz simétrica. -/
lemma symm_matrix_quad_form (a b : ℝ) (x : Fin 2 → ℝ) :
    x 0 * (mulVec (symm_matrix a b) x) 0 + x 1 * (mulVec (symm_matrix a b) x) 1
    = a * (x 0 ^ 2 + x 1 ^ 2) + 2 * b * x 0 * x 1 := by
  unfold symm_matrix
  simp [mulVec, dotProduct, Finset.sum_fin_eq_sum_range, Finset.sum_range_succ]
  ring

/-- Ordem de Loewner para matrizes simétricas reduz-se a comparar a+b e a-b. -/
lemma symm_form_loewner_le_iff {a₁ b₁ a₂ b₂ : ℝ} :
    Matrix.loewner_le (symm_matrix a₁ b₁) (symm_matrix a₂ b₂) ↔
    a₁ + b₁ ≥ a₂ + b₂ ∧ a₁ - b₁ ≥ a₂ - b₂ := by
  constructor
  · intro h
    have h1 := h (λ _ => 1)
    have h2 := h (λ i => if i = 0 then 1 else -1)
    rw [symm_matrix_quad_form a₁ b₁ (λ _ => 1), symm_matrix_quad_form a₂ b₂ (λ _ => 1)] at h1
    rw [symm_matrix_quad_form a₁ b₁ (λ i => if i = 0 then 1 else -1),
      symm_matrix_quad_form a₂ b₂ (λ i => if i = 0 then 1 else -1)] at h2
    simp at h1 h2
    constructor
    · linarith
    · linarith
  · intro ⟨hsum, hdiff⟩
    intro x
    rw [symm_matrix_quad_form a₁ b₁ x, symm_matrix_quad_form a₂ b₂ x]
    -- Goal: a₁*S + 2*b₁*P ≥ a₂*S + 2*b₂*P  where S = x₀²+x₁², P = x₀*x₁
    -- Equivalent to: (a₁-a₂)*S + 2*(b₁-b₂)*P ≥ 0
    have h_diff_goal : (a₁ - a₂) * (x 0 ^ 2 + x 1 ^ 2) + 2 * (b₁ - b₂) * x 0 * x 1 ≥ 0 := by
      by_cases hb : b₁ - b₂ ≥ 0
      · have h_eq : (a₁ - a₂) * (x 0 ^ 2 + x 1 ^ 2) + 2 * (b₁ - b₂) * x 0 * x 1
                  = (a₁ - a₂ - (b₁ - b₂)) * (x 0 ^ 2 + x 1 ^ 2) + (b₁ - b₂) * (x 0 + x 1)^2 := by
          ring
        rw [h_eq]
        have h1 : a₁ - a₂ - (b₁ - b₂) ≥ 0 := by linarith
        have h3 : x 0 ^ 2 + x 1 ^ 2 ≥ 0 := by nlinarith [sq_nonneg (x 0), sq_nonneg (x 1)]
        have h4 : (x 0 + x 1)^2 ≥ 0 := sq_nonneg _
        nlinarith
      · have h_neg : b₁ - b₂ < 0 := by linarith
        have h_eq : (a₁ - a₂) * (x 0 ^ 2 + x 1 ^ 2) + 2 * (b₁ - b₂) * x 0 * x 1
                  = (a₁ - a₂ + (b₁ - b₂)) * (x 0 ^ 2 + x 1 ^ 2) + (-(b₁ - b₂)) * (x 0 - x 1)^2 := by
          ring
        rw [h_eq]
        have h1 : a₁ - a₂ + (b₁ - b₂) ≥ 0 := by linarith
        have h3 : x 0 ^ 2 + x 1 ^ 2 ≥ 0 := by nlinarith [sq_nonneg (x 0), sq_nonneg (x 1)]
        have h4 : (x 0 - x 1)^2 ≥ 0 := sq_nonneg _
        nlinarith
    linarith

/-- Para matrizes PSD da forma [[a, b], [b, a]], temos a+b ≥ 0 e a-b ≥ 0. -/
lemma symm_psd_nonneg (a b : ℝ) (h_psd : Matrix.loewner_le (symm_matrix a b) 0) :
    a + b ≥ 0 ∧ a - b ≥ 0 := by
  have hzero : (0 : Matrix (Fin 2) (Fin 2) ℝ) = symm_matrix 0 0 := by
    ext i j; fin_cases i <;> fin_cases j <;> simp [symm_matrix]
  rw [hzero] at h_psd
  simpa using (symm_form_loewner_le_iff.mp h_psd)

/-- A função escalar g(t) = 1 - 1/(1+t) é monótona crescente para t > -1. -/
lemma g_monotone {t₁ t₂ : ℝ} (h_le : t₁ ≥ t₂) (h_gt : t₂ > -1) :
    1 - 1 / (1 + t₁) ≥ 1 - 1 / (1 + t₂) := by
  have hpos₁ : 1 + t₁ > 0 := by linarith
  have hpos₂ : 1 + t₂ > 0 := by linarith
  have h_inv : 1 / (1 + t₁) ≤ 1 / (1 + t₂) := by
    apply (one_div_le_one_div hpos₁ hpos₂).mpr
    linarith
  linarith

/-- Forma explícita de f(A) para A = symm_matrix a b.
    f(A) = symm_matrix p q onde
    p = 1 - (1+a)/((1+a)²-b²), q = b/((1+a)²-b²).
    Os "autovalores" são p+q = 1 - 1/(1+a+b), p-q = 1 - 1/(1+a-b).

    NOTA: Esta é a definição operacional de f; a igualdade com
    I - (I+A)⁻¹ é demonstrável pela fórmula da inversa 2×2. -/
noncomputable def f_on_symm (a b : ℝ) : Matrix (Fin 2) (Fin 2) ℝ :=
  symm_matrix (1 - (1+a) / ((1+a)^2 - b^2)) (b / ((1+a)^2 - b^2))

lemma f_on_symm_eigenvalues (a b : ℝ) (h_det : (1+a)^2 ≠ b^2) :
    (1 - (1+a) / ((1+a)^2 - b^2)) + (b / ((1+a)^2 - b^2)) = 1 - 1 / (1 + a + b)
  ∧ (1 - (1+a) / ((1+a)^2 - b^2)) - (b / ((1+a)^2 - b^2)) = 1 - 1 / (1 + a - b) := by
  have h_denom : (1+a)^2 - b^2 = (1 + a + b) * (1 + a - b) := by ring
  have h_sum_ne_zero : 1 + a + b ≠ 0 := by
    intro hzero
    have h_factor : (1+a)^2 - b^2 = (1 + a + b) * (1 + a - b) := by ring
    rw [hzero] at h_factor
    have hzero' : (1+a)^2 - b^2 = 0 := by simpa using h_factor
    apply h_det
    linarith
  have h_diff_ne_zero : 1 + a - b ≠ 0 := by
    intro hzero
    have h_factor : (1+a)^2 - b^2 = (1 + a + b) * (1 + a - b) := by ring
    rw [hzero] at h_factor
    have hzero' : (1+a)^2 - b^2 = 0 := by simpa using h_factor
    apply h_det
    linarith
  constructor
  · field_simp [h_denom, h_sum_ne_zero, h_diff_ne_zero]
    ring
  · field_simp [h_denom, h_sum_ne_zero, h_diff_ne_zero]
    ring

/-- Prova de que o determinante de I+A é não nulo para A PSD.
    Para A = [[a, b], [b, a]] PSD, temos a ≥ |b|, logo (1+a)² > b². -/
lemma det_I_add_A_ne_zero (a b : ℝ) (hsum : a + b ≥ 0) (hdiff : a - b ≥ 0) :
    (1+a)^2 ≠ b^2 := by
  by_cases hb_nonneg : b ≥ 0
  · have ha_ge_b : a ≥ b := by linarith
    have h_sq_lt : (1 + b)^2 > b^2 := by nlinarith
    nlinarith
  · have hb_neg : b < 0 := by linarith
    have ha_ge_neg_b : a ≥ -b := by linarith
    have h_sq_lt : (1 - b)^2 > b^2 := by nlinarith
    nlinarith

/-- f_on_symm é monótona na ordem de Loewner para matrizes PSD.

    Prova: A ⪯ B sse a₁+b₁ ≥ a₂+b₂ e a₁-b₁ ≥ a₂-b₂.
    f(A) ⪯ f(B) sse p₁+q₁ ≥ p₂+q₂ e p₁-q₁ ≥ p₂-q₂.
    Mas p+q = g(a+b) e p-q = g(a-b) onde g(t)=1-1/(1+t).
    Como g é monótona e a+b, a-b ≥ 0 > -1, o resultado segue. -/
theorem f_monotone_psd {a₁ b₁ a₂ b₂ : ℝ}
    (h_psd₁ : Matrix.loewner_le (symm_matrix a₁ b₁) 0)
    (h_psd₂ : Matrix.loewner_le (symm_matrix a₂ b₂) 0)
    (h_le : Matrix.loewner_le (symm_matrix a₁ b₁) (symm_matrix a₂ b₂)) :
    Matrix.loewner_le (f_on_symm a₁ b₁) (f_on_symm a₂ b₂) := by
  rcases symm_psd_nonneg a₁ b₁ h_psd₁ with ⟨hsum₁, hdiff₁⟩
  rcases symm_psd_nonneg a₂ b₂ h_psd₂ with ⟨hsum₂, hdiff₂⟩
  have hA_det : (1+a₁)^2 ≠ b₁^2 := det_I_add_A_ne_zero a₁ b₁ hsum₁ hdiff₁
  have hB_det : (1+a₂)^2 ≠ b₂^2 := det_I_add_A_ne_zero a₂ b₂ hsum₂ hdiff₂
  rcases (symm_form_loewner_le_iff.mp h_le) with ⟨hsum, hdiff⟩
  unfold f_on_symm
  apply (symm_form_loewner_le_iff.mpr)
  rcases f_on_symm_eigenvalues a₁ b₁ hA_det with ⟨hsum₁', hdiff₁'⟩
  rcases f_on_symm_eigenvalues a₂ b₂ hB_det with ⟨hsum₂', hdiff₂'⟩
  have hsum_gt : a₂ + b₂ > -1 := by linarith
  have hdiff_gt : a₂ - b₂ > -1 := by linarith
  have h_g_sum := g_monotone hsum hsum_gt
  have h_g_diff := g_monotone hdiff hdiff_gt
  rw [hsum₁', hsum₂', hdiff₁', hdiff₂']
  have h_g_sum' : 1 - 1 / (1 + a₁ + b₁) ≥ 1 - 1 / (1 + a₂ + b₂) := by
    simpa [add_assoc] using h_g_sum
  have h_g_diff' : 1 - 1 / (1 + a₁ - b₁) ≥ 1 - 1 / (1 + a₂ - b₂) := by
    simpa [sub_eq_add_neg, add_assoc] using h_g_diff
  exact ⟨h_g_sum', h_g_diff'⟩

/-- Conexão com DegradednessParamsGeneral:
    S_bob = Z₀² [[M_self²+M_mutual², 2M_self M_mutual], [2M_self M_mutual, M_self²+M_mutual²]]
    = symm_matrix (Z₀²(M_self²+M_mutual²)) (Z₀²·2M_self M_mutual)
-/
lemma S_bob_as_symm (p : DegradednessParamsGeneral) :
    p.S_bob = symm_matrix (p.Z₀^2 * (p.M_self^2 + p.M_mutual^2))
                          (p.Z₀^2 * (2 * p.M_self * p.M_mutual)) := by
  ext i j
  unfold DegradednessParamsGeneral.S_bob symm_matrix
  fin_cases i <;> fin_cases j <;> simp

/-- Versão simetrizada de S_eve_matrix:
    S_eve_sym = [[s, 0], [0, s]] onde s = Z₀²(M_self+M_mutual)²/f².
    S_eve_sym ⪰ S_eve_matrix (a versão simetrizada domina a original).

    NOTA IMPORTANTE (gap conhecido):
    O teorema `degradedness_loewner_general` em DegradednessGeneral.lean
    prova S_bob ⪰ S_eve_matrix (escalar apenas em (0,0)).
    O teorema `degradedness_exact` abaixo requer S_bob ⪰ S_eve_sym
    (escalar na diagonal). Como S_eve_sym ⪰ S_eve_matrix, a condicao
    para o canal exato e MAIS FORTE que a do teorema generalizado.
    O limiar otimo para o canal exato (com S_eve_sym) NAO e min_f_sq;
    seria um valor maior. Esta e uma limitacao conhecida documentada. -/
noncomputable def S_eve_sym (p : DegradednessParamsGeneral) : Matrix (Fin 2) (Fin 2) ℝ :=
  symm_matrix (p.Z₀^2 * (p.M_self + p.M_mutual)^2 / p.f^2) 0

lemma S_eve_sym_ge_S_eve (p : DegradednessParamsGeneral) :
    Matrix.loewner_le (S_eve_sym p) p.S_eve_matrix := by
  intro x
  have h_eve := DegradednessParamsGeneral.quad_form_eve_eq p x
  have h_sym : x 0 * (mulVec (S_eve_sym p) x) 0 + x 1 * (mulVec (S_eve_sym p) x) 1
            = (p.Z₀^2 * (p.M_self + p.M_mutual)^2 / p.f^2) * (x 0^2 + x 1^2) := by
    unfold S_eve_sym symm_matrix
    simp [mulVec, dotProduct]
    ring
  rw [h_sym, h_eve]
  have hf_sq_pos : p.f^2 > 0 := by
    have h_min_pos : min_f_sq p.M_self p.M_mutual (DegradednessParamsGeneral.h_mut_lt_self p) > 0 := by
      have h_sum_sq_pos : (p.M_self + p.M_mutual)^2 > 0 := by
        have h_sum_ne_zero : p.M_self + p.M_mutual ≠ 0 := by
          intro hzero
          have h_mut_eq : p.M_mutual = -p.M_self := by linarith
          have h_weak' := p.h_weak
          rw [h_mut_eq] at h_weak'
          have h_abs_self : |p.M_self| = p.M_self := abs_of_pos p.h_M_self_pos
          rw [h_abs_self, abs_neg] at h_weak'
          linarith [h_weak', p.h_M_self_pos]
        exact sq_pos_iff.mpr h_sum_ne_zero
      have h_num_pos : (p.M_self^2 + p.M_mutual^2) * (p.M_self + p.M_mutual)^2 > 0 := by
        have h_first_pos : p.M_self^2 + p.M_mutual^2 > 0 := by
          have h_self_sq_pos : p.M_self^2 > 0 := pow_pos p.h_M_self_pos 2
          nlinarith [sq_nonneg p.M_mutual]
        exact mul_pos h_first_pos h_sum_sq_pos
      have h_denom_pos : (p.M_self^2 - p.M_mutual^2)^2 > 0 :=
        min_f_sq_denom_pos (DegradednessParamsGeneral.h_mut_lt_self p)
      exact div_pos h_num_pos h_denom_pos
    nlinarith [p.h_f_sq_ge_min, h_min_pos]
  have h_num_nonneg : p.Z₀^2 * (p.M_self + p.M_mutual)^2 ≥ 0 := by positivity
  have h_sq : x 0^2 + x 1^2 ≥ x 0^2 := by nlinarith [sq_nonneg (x 1)]
  have h_mul : p.Z₀^2 * (p.M_self + p.M_mutual)^2 * (x 0^2 + x 1^2)
             ≥ p.Z₀^2 * (p.M_self + p.M_mutual)^2 * x 0^2 := by
    nlinarith
  have h_div : (p.Z₀^2 * (p.M_self + p.M_mutual)^2 * (x 0^2 + x 1^2)) / p.f^2
             ≥ (p.Z₀^2 * (p.M_self + p.M_mutual)^2 * x 0^2) / p.f^2 :=
    div_le_div_of_nonneg_right h_mul (by positivity)
  simpa [mul_div_assoc, div_mul_eq_mul_div, mul_comm, mul_left_comm, mul_assoc] using h_div

/-- Teorema principal (versão geral): se A_bob ⪰ A_eve e ambas são PSD
    da forma [[a, b], [b, a]], então f(A_bob) ⪰ f(A_eve). -/
theorem degradedness_exact_general {a_bob b_bob a_eve b_eve : ℝ}
    (h_psd_bob : Matrix.loewner_le (symm_matrix a_bob b_bob) 0)
    (h_psd_eve : Matrix.loewner_le (symm_matrix a_eve b_eve) 0)
    (h_le : Matrix.loewner_le (symm_matrix a_bob b_bob) (symm_matrix a_eve b_eve)) :
    Matrix.loewner_le (f_on_symm a_bob b_bob) (f_on_symm a_eve b_eve) :=
  f_monotone_psd h_psd_bob h_psd_eve h_le

/-- Teorema principal (contexto MaxwellKey):
    Dados parâmetros p e a hipótese S_bob ⪰ S_eve_sym,
    conclui-se f(S_bob) ⪰ f(S_eve_sym).

    A hipótese S_bob ⪰ S_eve_sym é equivalente a:
    f² ≥ ((M_self+M_mutual)/(M_self-M_mutual))²,
    que é mais forte que f² ≥ min_f_sq.
    Provar esta implicação requer trabalho adicional. -/
theorem degradedness_exact (p : DegradednessParamsGeneral)
    (h_le_sym : Matrix.loewner_le p.S_bob (S_eve_sym p)) :
    Matrix.loewner_le (f_on_symm (p.Z₀^2 * (p.M_self^2 + p.M_mutual^2))
                                 (p.Z₀^2 * (2 * p.M_self * p.M_mutual)))
                      (f_on_symm (p.Z₀^2 * (p.M_self + p.M_mutual)^2 / p.f^2) 0) := by
  have hS_bob_sym := S_bob_as_symm p
  have h_target : Matrix.loewner_le (f_on_symm (p.Z₀^2 * (p.M_self^2 + p.M_mutual^2))
                                               (p.Z₀^2 * (2 * p.M_self * p.M_mutual)))
                                    (f_on_symm (p.Z₀^2 * (p.M_self + p.M_mutual)^2 / p.f^2) 0) := by
    apply degradedness_exact_general
    · -- S_bob is PSD (goal is already in symm_matrix form)
      have hzero : (0 : Matrix (Fin 2) (Fin 2) ℝ) = symm_matrix 0 0 := by
        ext i j; fin_cases i <;> fin_cases j <;> simp [symm_matrix]
      rw [hzero]
      apply (symm_form_loewner_le_iff.mpr)
      have hsum : p.Z₀^2 * (p.M_self^2 + p.M_mutual^2) + p.Z₀^2 * (2 * p.M_self * p.M_mutual)
               = p.Z₀^2 * (p.M_self + p.M_mutual)^2 := by ring
      have hdiff : p.Z₀^2 * (p.M_self^2 + p.M_mutual^2) - p.Z₀^2 * (2 * p.M_self * p.M_mutual)
                = p.Z₀^2 * (p.M_self - p.M_mutual)^2 := by ring
      constructor
      · rw [hsum]; simpa using mul_nonneg (sq_nonneg p.Z₀) (sq_nonneg (p.M_self + p.M_mutual))
      · rw [hdiff]; simpa using mul_nonneg (sq_nonneg p.Z₀) (sq_nonneg (p.M_self - p.M_mutual))
    · -- S_eve_sym is PSD (goal is already in symm_matrix form)
      have hzero : (0 : Matrix (Fin 2) (Fin 2) ℝ) = symm_matrix 0 0 := by
        ext i j; fin_cases i <;> fin_cases j <;> simp [symm_matrix]
      rw [hzero]
      apply (symm_form_loewner_le_iff.mpr)
      have h_nonneg : p.Z₀^2 * (p.M_self + p.M_mutual)^2 / p.f^2 ≥ 0 := by positivity
      constructor <;> linarith
    · -- S_bob ⪰ S_eve_sym (goal is already in symm_matrix form)
      rw [hS_bob_sym] at h_le_sym
      exact h_le_sym
  exact h_target

end ExactChannel

end MaxwellKey
