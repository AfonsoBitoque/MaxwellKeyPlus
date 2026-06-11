/-
  MaxwellKeyPLUS / Examples / TwoParallelStripsComputable.lean
  -------------------------------------------------------------
  Versão computável do exemplo numérico usando `Float` em vez de `ℝ`.
  Permite `#eval` real e extração de código executável.
-/

namespace MaxwellKey

namespace TwoParallelStripsComputable

/-- Valores físicos pré-calculados como Float. -/
def M_self_val : Float := 0.003109761664971414
def M_mutual_val : Float := 0.000004150620831811415
def Z₀_val : Float := 50.0
def eve_factor : Float := 5.0
def N0_val : Float := 4.0038821e-15

/-- α = Z₀² / N₀. -/
def alpha : Float := Z₀_val * Z₀_val / N0_val

/-- Argumento de Bob: (1 + α·(M_self²+M_mutual²))² - (2·α·M_self·M_mutual)². -/
def arg_bob : Float :=
  (1.0 + alpha * (M_self_val * M_self_val + M_mutual_val * M_mutual_val))^2
  - (alpha * (2.0 * M_self_val * M_mutual_val))^2

/-- Argumento de Eve: 1 + α·(M_self+M_mutual)²/f². -/
def arg_eve : Float :=
  1.0 + alpha * ((M_self_val + M_mutual_val)^2 / (eve_factor * eve_factor))

/-- Capacidade de Bob (bits/canal). -/
def capacity_bob : Float :=
  0.5 * Float.log2 arg_bob

/-- Capacidade de Eve (bits/canal). -/
def capacity_eve : Float :=
  0.5 * Float.log2 arg_eve

/-- Capacidade de segredo (bits/canal). -/
def secrecy_capacity : Float :=
  capacity_bob - capacity_eve

#eval arg_bob
#eval arg_eve
#eval capacity_bob
#eval capacity_eve
#eval secrecy_capacity

end TwoParallelStripsComputable

end MaxwellKey
