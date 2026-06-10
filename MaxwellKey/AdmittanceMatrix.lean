/-
  MaxwellKey / AdmittanceMatrix.lean
  ---------------------------------
  Define a estrutura de um circuito quase-estático de duas pistas acopladas
  e a matriz de admitâncias 2×2 correspondente.

  NOTA (aproximação quase-estática):
  Supomos que a frequência de operação é suficientemente baixa para que
  o comprimento da pista seja muito menor que λ/4. Para uma PCB típica
  (pista de ~10 cm) a 100 MHz, λ/4 ≈ 75 cm, logo a condição é satisfeita.
  Esta aproximação permite modelar o acoplamento eletromagnético através
  de parâmetros concentrados (C_self, L_self, C_mutual, M_mutual).
-/

import Mathlib.Data.Matrix.Basic
import Mathlib.Data.Complex.Basic
import Mathlib.Data.Real.Basic
import Mathlib.Analysis.SpecialFunctions.Trigonometric.Basic
import Mathlib.Data.Fin.VecNotation
import Mathlib.Tactic.FinCases

open Real
open scoped Real

namespace MaxwellKey

/-- Circuito quase-estático de duas pistas acopladas. -/
structure QuasiStaticCircuit where
  /-- Capacidade própria (F) -/
  C_self : ℝ
  /-- Indutância própria (H) -/
  L_self : ℝ
  /-- Capacidade mútua (F) -/
  C_mutual : ℝ
  /-- Indutância mútua (H).
      NOTA: M_mutual aqui e a indutancia fisica (unidade: Henry).
      No modelo DegradednessGeneral, M_mutual e o parametro
      normalizado (adimensional, Z0 * |Y_mutual|). -/
  M_mutual : ℝ
  /-- Frequência de operação (Hz) -/
  frequency : ℝ
  /-- Todos os parâmetros físicos e a frequência são positivos.
      NOTA: C_mutual > 0 e M_mutual > 0 sao hipoteses implicitas
      necessarias para evitar divisao por zero em Y_mutual. -/
  h_pos : C_self > 0 ∧ L_self > 0 ∧ C_mutual > 0 ∧ M_mutual > 0 ∧ frequency > 0

namespace QuasiStaticCircuit

/-- Frequência angular ω = 2πf (rad/s). -/
noncomputable def omega (c : QuasiStaticCircuit) : ℝ :=
  2 * π * c.frequency

/-- Admitância própria Y_11 = Y_22 = jωC_self + 1/(jωL_self). -/
noncomputable def Y_self (c : QuasiStaticCircuit) : ℂ :=
  Complex.I * c.omega * c.C_self + 1 / (Complex.I * c.omega * c.L_self)

/-- Admitância mútua Y_12 = Y_21 = -jωC_mutual - 1/(jωM_mutual). -/
noncomputable def Y_mutual (c : QuasiStaticCircuit) : ℂ :=
  -Complex.I * c.omega * c.C_mutual - 1 / (Complex.I * c.omega * c.M_mutual)

/-- Matriz de admitâncias 2×2 do circuito quase-estático.

    Y = [ Y_11   Y_12 ]
        [ Y_21   Y_22 ]

    onde Y_11 = Y_22 = Y_self  e  Y_12 = Y_21 = Y_mutual.
-/
noncomputable def admittance_matrix (c : QuasiStaticCircuit) : Matrix (Fin 2) (Fin 2) ℂ :=
  fun i j =>
    match i, j with
    | 0, 0 => c.Y_self
    | 0, 1 => c.Y_mutual
    | 1, 0 => c.Y_mutual
    | 1, 1 => c.Y_self

/-- A matriz de admitâncias é simétrica por construção. -/
theorem admittance_symmetric (c : QuasiStaticCircuit) :
    admittance_matrix c = Matrix.transpose (admittance_matrix c) := by
  funext i j
  rw [Matrix.transpose]
  fin_cases i <;> fin_cases j <;> rfl

end QuasiStaticCircuit

end MaxwellKey
