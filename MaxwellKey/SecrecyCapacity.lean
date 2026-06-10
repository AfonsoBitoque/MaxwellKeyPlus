/-
  MaxwellKey / SecrecyCapacity.lean
  ---------------------------------
  Teorema principal: a capacidade de segredo do canal
  eletromagnético é estritamente positiva.

  Modelo:
  - Bob: canal 2×2 com matriz de sinal S_bob e ruído N₀·I.
  - Eve: canal escalar com sinal S_eve e ruído N₀.
  - C_bob = (1/2)·log₂ det(I + S_bob/N₀)
  - C_eve = (1/2)·log₂(1 + S_eve/N₀)

  Sob acoplamento fraco e fator de distância f ≥ 3,
  provamos C_bob > C_eve, logo C_s > 0.
-/

import Mathlib.Data.Real.Basic
import Mathlib.Analysis.SpecialFunctions.Log.Base
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Ring
import Mathlib.Tactic.FieldSimp
import MaxwellKey.Degradedness

namespace MaxwellKey

/-- Parâmetros para o teorema de capacidade de segredo. -/
structure SecrecyParams extends DegradednessParams where
  /-- Densidade espectral de ruído (positiva). -/
  N0 : ℝ
  h_N0_pos : N0 > 0

namespace SecrecyParams

/-- Valor escalar do sinal de Eve. -/
noncomputable def S_eve_scalar (p : SecrecyParams) : ℝ :=
  p.Z₀^2 * (p.M_self + p.M_mutual)^2 / p.f^2

/-- Argumento do logaritmo para a capacidade de Bob.
    det(I + S_bob/N₀) calculado explicitamente:
    (1 + α·(M_self²+M_mutual²))² - (2·α·M_self·M_mutual)²
    = 1 + 2·α·(M_self²+M_mutual²) + α²·(M_self² - M_mutual²)²
    com α = Z₀²/N₀.
-/
noncomputable def arg_bob (p : SecrecyParams) : ℝ :=
  (1 + (p.Z₀^2 / p.N0) * (p.M_self^2 + p.M_mutual^2))^2
  - ((p.Z₀^2 / p.N0) * (2 * p.M_self * p.M_mutual))^2

/-- Argumento do logaritmo para a capacidade de Eve: 1 + S_eve/N₀. -/
noncomputable def arg_eve (p : SecrecyParams) : ℝ :=
  1 + p.S_eve_scalar / p.N0

/-- Capacidade de Bob (por uso do canal). -/
noncomputable def capacity_bob (p : SecrecyParams) : ℝ :=
  (1 / 2) * Real.logb 2 (p.arg_bob)

/-- Capacidade de Eve (por uso do canal). -/
noncomputable def capacity_eve (p : SecrecyParams) : ℝ :=
  (1 / 2) * Real.logb 2 (p.arg_eve)

/-- Capacidade de segredo C_s = C_bob - C_eve. -/
noncomputable def secrecy_capacity (p : SecrecyParams) : ℝ :=
  p.capacity_bob - p.capacity_eve

/-- Expande o argumento de Bob para a forma simplificada. -/
lemma arg_bob_eq (p : SecrecyParams) :
    p.arg_bob = 1 + 2 * (p.Z₀^2 / p.N0) * (p.M_self^2 + p.M_mutual^2)
                + (p.Z₀^2 / p.N0)^2 * (p.M_self^2 - p.M_mutual^2)^2 := by
  simp [arg_bob]
  field_simp
  ring

/-- O argumento de Eve expande para: 1 + (Z₀²/N₀)·(M_self+M_mutual)²/f². -/
lemma arg_eve_eq (p : SecrecyParams) :
    p.arg_eve = 1 + (p.Z₀^2 / p.N0) * ((p.M_self + p.M_mutual)^2 / p.f^2) := by
  simp [arg_eve, S_eve_scalar]
  field_simp

/-- O argumento de Bob é estritamente maior que o argumento de Eve.
    Isto é a desigualdade algébrica central do teorema. -/
lemma arg_bob_gt_arg_eve (p : SecrecyParams) :
    p.arg_bob > p.arg_eve := by
  rw [arg_bob_eq, arg_eve_eq]
  let α := p.Z₀^2 / p.N0
  have h_α_pos : α > 0 := by
    apply div_pos
    · have h : p.Z₀^2 > 0 := by nlinarith [p.h_Z₀_pos]
      linarith [h]
    · exact p.h_N0_pos
  -- Subtrai 1 de ambos os lados e divide por α (> 0).
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
  -- Agora basta provar a desigualdade sem o factor α.
  have hf2 : p.f^2 ≥ 9 := by nlinarith [p.h_f_ge_three]
  have h_rhs : (p.M_self + p.M_mutual)^2 / p.f^2 ≤ (p.M_self + p.M_mutual)^2 / 9 := by
    have h1 : (p.M_self + p.M_mutual)^2 * 9 ≤ (p.M_self + p.M_mutual)^2 * p.f^2 := by
      nlinarith [hf2, sq_nonneg (p.M_self + p.M_mutual)]
    have h2 : (p.M_self + p.M_mutual)^2 / p.f^2 - (p.M_self + p.M_mutual)^2 / 9 ≤ 0 := by
      have h_ne : p.f ≠ 0 := by nlinarith [p.h_f_ge_three]
      have h3 : (p.M_self + p.M_mutual)^2 / p.f^2 - (p.M_self + p.M_mutual)^2 / 9
              = ((p.M_self + p.M_mutual)^2 * 9 - (p.M_self + p.M_mutual)^2 * p.f^2) / (p.f^2 * 9) := by
        field_simp [h_ne]
      rw [h3]
      have h4 : (p.M_self + p.M_mutual)^2 * 9 - (p.M_self + p.M_mutual)^2 * p.f^2 ≤ 0 := by
        nlinarith [h1]
      have h5 : p.f^2 * 9 > 0 := by nlinarith [sq_nonneg p.f]
      apply div_nonpos_of_nonpos_of_nonneg
      · linarith [h4]
      · nlinarith [h5]
    linarith
  suffices 2 * (p.M_self^2 + p.M_mutual^2) + α * (p.M_self^2 - p.M_mutual^2)^2
         > (p.M_self + p.M_mutual)^2 / 9 by
    nlinarith [this, h_rhs]
  -- O termo α·(M_self² - M_mutual²)² é não negativo.
  have h_extra : α * (p.M_self^2 - p.M_mutual^2)^2 ≥ 0 := by
    apply mul_nonneg
    · linarith [h_α_pos]
    · apply sq_nonneg
  -- Portanto basta provar a desigualdade base.
  have h_base : 2 * (p.M_self^2 + p.M_mutual^2) > (p.M_self + p.M_mutual)^2 / 9 := by
    have h_pos : p.M_self^2 > 0 := by nlinarith [p.h_M_self_pos]
    nlinarith [sq_nonneg (p.M_self - p.M_mutual), sq_nonneg (p.M_self + p.M_mutual),
               sq_nonneg (p.M_self - 3 * p.M_mutual), sq_nonneg (3 * p.M_self - p.M_mutual),
               h_pos]
  nlinarith [h_base, h_extra]

/-- Os argumentos são estritamente positivos (necessário para os logaritmos). -/
lemma arg_bob_pos (p : SecrecyParams) : p.arg_bob > 0 := by
  rw [arg_bob_eq]
  have h1 : p.Z₀^2 / p.N0 > 0 := by
    apply div_pos
    · have h : p.Z₀^2 > 0 := by nlinarith [p.h_Z₀_pos]
      linarith [h]
    · exact p.h_N0_pos
  have h2 : (p.M_self^2 - p.M_mutual^2)^2 ≥ 0 := sq_nonneg (p.M_self^2 - p.M_mutual^2)
  nlinarith [h1, h2, sq_nonneg (p.M_self), sq_nonneg (p.M_mutual)]

lemma arg_eve_pos (p : SecrecyParams) : p.arg_eve > 0 := by
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

/-- Teorema principal: a capacidade de segredo é estritamente positiva. -/
theorem secrecy_capacity_pos (p : SecrecyParams) :
    p.secrecy_capacity > 0 := by
  have h_arg : p.arg_bob > p.arg_eve := arg_bob_gt_arg_eve p
  have h_bob_pos : p.arg_bob > 0 := arg_bob_pos p
  have h_eve_pos : p.arg_eve > 0 := arg_eve_pos p
  -- log₂ é estritamente monótona, logo arg_bob > arg_eve implica log₂(arg_bob) > log₂(arg_eve).
  have h_log : Real.logb 2 p.arg_bob > Real.logb 2 p.arg_eve := by
    apply Real.logb_lt_logb
    all_goals nlinarith [h_arg, h_bob_pos, h_eve_pos]
  -- Multiplica por 1/2 (> 0) para obter a desigualdade nas capacidades.
  have h_cap : p.capacity_bob > p.capacity_eve := by
    simp [capacity_bob, capacity_eve]
    nlinarith [h_log]
  -- A capacidade de segredo é a diferença.
  simp [secrecy_capacity]
  linarith [h_cap]

end SecrecyParams

end MaxwellKey
