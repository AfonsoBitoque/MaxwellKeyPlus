/-
  MaxwellKey / ChannelMatrix.lean
  ---------------------------------
  Deriva as matrizes de canal efetivas (MIMO 2×2 para Bob, escalar para Eve)
  a partir da matriz de admitâncias do circuito quase-estático.

  Modelo de canal:
  - H_bob = Z₀ • Y  (aproximação de primeira ordem para acoplamento fraco)
  - H_eve = Z₀ • (Y_self + Y_mutual) / eve_distance_factor

  A aproximação H_bob ≈ Z₀ • Y é válida quando o acoplamento mútuo é fraco
  (Y_mutual << Y_self), o que corresponde ao regime quase-estático de duas
  pistas numa PCB com separação pequena.
-/

import Mathlib.Data.Matrix.Basic
import Mathlib.Data.Complex.Basic
import Mathlib.Data.Real.Basic
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Basic
import Mathlib.Data.Fin.VecNotation
import Mathlib.Tactic.FinCases

import MaxwellKey.AdmittanceMatrix

open Real
open scoped Real

namespace MaxwellKey

/-- Modelo de canal que estende o circuito quase-estático com parâmetros
    de terminação e atenuação do espião. -/
structure ChannelModel extends QuasiStaticCircuit where
  /-- Impedância de terminação (Ω) -/
  Z₀ : ℝ
  /-- Impedância de terminação positiva -/
  h_Z₀_pos : Z₀ > 0
  /-- Fator de atenuação para o espião (ex: 5.0 se Eve estiver 5x mais longe) -/
  eve_distance_factor : ℝ
  /-- Fator de atenuação maior que 1 -/
  h_eve_factor_gt_one : eve_distance_factor > 1

namespace ChannelModel

/-- Matriz de canal para o par legítimo (Bob).

    Aproximação de primeira ordem para acoplamento fraco:
    H_bob = Z₀ • Y
-/
noncomputable def channel_matrix_bob (c : ChannelModel) : Matrix (Fin 2) (Fin 2) ℂ :=
  (c.Z₀ : ℂ) • c.toQuasiStaticCircuit.admittance_matrix

/-- Canal do espião (Eve) — escalar complexo.

    H_eve = Z₀ • (Y_self + Y_mutual) / eve_distance_factor
-/
noncomputable def channel_matrix_eve (c : ChannelModel) : ℂ :=
  (c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual) / c.eve_distance_factor

/-- A matriz de canal de Bob é simétrica porque herda a simetria da matriz
    de admitâncias Y (Teorema 1 do MaxwellKey). -/
lemma channel_bob_symmetric (c : ChannelModel) :
    c.channel_matrix_bob = Matrix.transpose c.channel_matrix_bob := by
  ext i j
  simp only [channel_matrix_bob, Matrix.smul_apply, Matrix.transpose_apply]
  have h : c.toQuasiStaticCircuit.admittance_matrix i j
         = c.toQuasiStaticCircuit.admittance_matrix j i := by
    fin_cases i <;> fin_cases j <;> rfl
  rw [h]

/-- Atenuação do canal de Eve: ‖H_eve‖ ≤ ‖Z₀*Y_self‖ + ‖Z₀*Y_mutual‖.

    Como H_eve = Z₀*(Y_self+Y_mutual)/factor e factor > 1, a norma de H_eve
    é no máximo a norma de Z₀*(Y_self+Y_mutual), que por desigualdade triangular
    é menor ou igual à soma das normas das componentes de Bob.
-/
lemma eve_attenuation (c : ChannelModel) :
    ‖c.channel_matrix_eve‖ ≤ ‖(c.Z₀ : ℂ) * c.toQuasiStaticCircuit.Y_self‖
                           + ‖(c.Z₀ : ℂ) * c.toQuasiStaticCircuit.Y_mutual‖ := by
  have hf : c.eve_distance_factor > 1 := c.h_eve_factor_gt_one
  have h_pos : c.eve_distance_factor > 0 := by linarith
  rw [channel_matrix_eve]
  -- Passo 1: ‖z / r‖ = ‖z‖ / r para r real positivo
  have h1 : ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)
             / (c.eve_distance_factor : ℂ)‖
          = ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖
            / c.eve_distance_factor := by
    have h_ne : (c.eve_distance_factor : ℂ) ≠ 0 := by
      exact_mod_cast (ne_of_gt h_pos)
    have h_norm : ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)
                    / (c.eve_distance_factor : ℂ)‖
                = ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖
                  / ‖(c.eve_distance_factor : ℂ)‖ := by
      rw [norm_div]
    have h_abs : ‖(c.eve_distance_factor : ℂ)‖ = c.eve_distance_factor := by
      have h1 : (c.eve_distance_factor : ℂ) = (c.eve_distance_factor : ℝ) := by simp
      rw [h1]
      simp [abs_of_nonneg (le_of_lt h_pos)]
    rw [h_norm, h_abs]
  -- Passo 2: desigualdade triangular
  have h2 : ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖
          ≤ ‖(c.Z₀ : ℂ) * c.toQuasiStaticCircuit.Y_self‖
          + ‖(c.Z₀ : ℂ) * c.toQuasiStaticCircuit.Y_mutual‖ := by
    have h : (c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)
            = (c.Z₀ : ℂ) * c.toQuasiStaticCircuit.Y_self
            + (c.Z₀ : ℂ) * c.toQuasiStaticCircuit.Y_mutual := by ring
    rw [h]
    exact norm_add_le _ _
  -- Passo 3: como factor ≥ 1, dividir não aumenta
  have h3 : ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖
            / c.eve_distance_factor
          ≤ ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖ := by
    have h_nonneg : ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖ ≥ 0 := by
      positivity
    have h1 : c.eve_distance_factor * ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖
            ≥ ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖ := by
      nlinarith [h_nonneg, hf]
    have h2 : ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖
              / c.eve_distance_factor
            ≤ ‖(c.Z₀ : ℂ) * (c.toQuasiStaticCircuit.Y_self + c.toQuasiStaticCircuit.Y_mutual)‖ := by
      apply (div_le_iff₀ h_pos).mpr
      nlinarith [h_nonneg, hf]
    exact h2
  -- Combinar
  linarith [h1, h2, h3]

end ChannelModel

end MaxwellKey
