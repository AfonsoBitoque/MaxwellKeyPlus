import Mathlib.Data.Matrix.Basic
import Mathlib.Data.Real.Basic
import Mathlib.Data.Fin.VecNotation
import Mathlib.Tactic.FinCases
import Mathlib.Tactic.Linarith
import Mathlib.Tactic.Ring

namespace MaxwellKey

/-- Ordem de Loewner para matrizes reais 2×2. -/
def Matrix.loewner_le (A B : Matrix (Fin 2) (Fin 2) ℝ) : Prop :=
  ∀ x : Fin 2 → ℝ,
    x 0 * (Matrix.mulVec A x) 0 + x 1 * (Matrix.mulVec A x) 1 >=
    x 0 * (Matrix.mulVec B x) 0 + x 1 * (Matrix.mulVec B x) 1

namespace LoewnerOrder

/-- Reflexividade. -/
lemma refl (A : Matrix (Fin 2) (Fin 2) ℝ) : Matrix.loewner_le A A := by
  intro x
  simp

/-- Transitividade. -/
lemma trans {A B C : Matrix (Fin 2) (Fin 2) ℝ}
    (h1 : Matrix.loewner_le A B) (h2 : Matrix.loewner_le B C) :
    Matrix.loewner_le A C := by
  intro x
  have h1' := h1 x
  have h2' := h2 x
  linarith

/-- Matriz diagonal com entradas positivas é >=l 0. -/
lemma diagonal_pos_ge_zero (d1 d2 : ℝ) (hd1 : d1 > 0) (hd2 : d2 > 0) :
    Matrix.loewner_le
      (Matrix.of fun i j : Fin 2 => if i = j then (if i = 0 then d1 else d2) else 0)
      (0 : Matrix (Fin 2) (Fin 2) ℝ) := by
  intro x
  have hD0 : Matrix.mulVec (Matrix.of fun i j : Fin 2 => if i = j then (if i = 0 then d1 else d2) else 0) x 0 = d1 * x 0 := by
    simp [Matrix.mulVec, dotProduct]
  have hD1 : Matrix.mulVec (Matrix.of fun i j : Fin 2 => if i = j then (if i = 0 then d1 else d2) else 0) x 1 = d2 * x 1 := by
    simp [Matrix.mulVec, dotProduct]
  have h00 : Matrix.mulVec (0 : Matrix (Fin 2) (Fin 2) ℝ) x 0 = 0 := by simp
  have h01 : Matrix.mulVec (0 : Matrix (Fin 2) (Fin 2) ℝ) x 1 = 0 := by simp
  rw [hD0, hD1, h00, h01]
  nlinarith [sq_nonneg (x 0), sq_nonneg (x 1), hd1, hd2]

end LoewnerOrder

end MaxwellKey
