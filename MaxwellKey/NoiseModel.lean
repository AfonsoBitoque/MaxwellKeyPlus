/-
  MaxwellKey / NoiseModel.lean
  ---------------------------------
  Modelo de ruído térmico gaussiano para o canal de comunicação.

  O ruído térmico é modelado como branco e descorrelacionado em cada porta,
  com densidade espectral N₀ = k_B · T · B.
-/

import Mathlib.Data.Matrix.Basic
import Mathlib.Data.Real.Basic
import Mathlib.Data.Fin.VecNotation
import Mathlib.Tactic.FinCases

import MaxwellKey.ChannelMatrix

open Real

namespace MaxwellKey

/-- Modelo de ruído que estende o modelo de canal com temperatura e largura de banda. -/
structure NoiseModel extends ChannelModel where
  /-- Temperatura do ruído (K) -/
  temperature : ℝ
  /-- Largura de banda do sistema (Hz) -/
  bandwidth : ℝ
  /-- Temperatura positiva -/
  h_temp_pos : temperature > 0
  /-- Largura de banda positiva -/
  h_bw_pos : bandwidth > 0

namespace NoiseModel

/-- Constante de Boltzmann (J/K). -/
def k_B : ℝ := 1.380649e-23

/-- Densidade espectral de ruído N₀ = k_B · T · B (W/Hz). -/
def N0 (n : NoiseModel) : ℝ :=
  k_B * n.temperature * n.bandwidth

/-- Matriz de covariância do ruído para Bob (diagonal com N₀). -/
def noise_cov_bob (n : NoiseModel) : Matrix (Fin 2) (Fin 2) ℝ :=
  n.N0 • (1 : Matrix (Fin 2) (Fin 2) ℝ)

/-- Variância do ruíno para Eve (escalar). -/
def noise_var_eve (n : NoiseModel) : ℝ :=
  n.N0

/-- N₀ é estritamente positivo porque k_B > 0, T > 0 e B > 0. -/
lemma N0_pos (n : NoiseModel) : n.N0 > 0 := by
  have h1 : k_B > 0 := by norm_num [k_B]
  have h2 : n.temperature > 0 := n.h_temp_pos
  have h3 : n.bandwidth > 0 := n.h_bw_pos
  simp [N0]
  positivity

/-- A matriz de covariância de Bob é positiva semi-definida:
    para qualquer vetor x, xᵀ (N₀·I) x = N₀ · (x₀² + x₁²) ≥ 0.
-/
lemma noise_cov_bob_nonneg (n : NoiseModel) :
    ∀ x : Fin 2 → ℝ, x 0 * (Matrix.mulVec n.noise_cov_bob x) 0 + x 1 * (Matrix.mulVec n.noise_cov_bob x) 1 ≥ 0 := by
  intro x
  simp [noise_cov_bob, Matrix.mulVec]
  have h_pos : n.N0 > 0 := n.N0_pos
  have h_sq1 : x 0 ^ 2 ≥ 0 := sq_nonneg (x 0)
  have h_sq2 : x 1 ^ 2 ≥ 0 := sq_nonneg (x 1)
  nlinarith [h_pos, h_sq1, h_sq2]

/-- A matriz de covariância de Bob é diagonal com entradas positivas. -/
lemma noise_cov_bob_diagonal_pos (n : NoiseModel) :
    n.noise_cov_bob 0 0 > 0 ∧ n.noise_cov_bob 1 1 > 0 := by
  constructor
  · simp [noise_cov_bob]
    exact n.N0_pos
  · simp [noise_cov_bob]
    exact n.N0_pos

end NoiseModel

end MaxwellKey
