/-
  MaxwellKeyPLUS / Examples / TemplateRealParams.lean
  ------------------------------------------------------
  Template para parâmetros reais de PCB tracks (COMSOL/OpenEMS).
  Colaborador: David.

  Instruções de uso:
  1. Correr simulação COMSOL/OpenEMS para obter:
     - C_self, L_self (capacidade e indutância próprias)
     - C_mutual, M_mutual (capacidade e indutância mútuas)
     - Parâmetros equivalentes para Eve (a diferentes distâncias)
  2. Medir ou estimar Z₀ (impedância de entrada do PA).
  3. Estimar f_att (factor de atenuação para a posição de Eve).
  4. Chamar create_params com os valores e as provas de hipóteses.
  5. Usar o resultado para calcular capacity_bob, capacity_eve, secrecy_capacity.
  6. Para o modelo exacto, usar create_params_exact.

  NOTA: A condutância de perdas G nao e usada no modelo atual.
  As perdas no dieletrico (FR-4, tan δ ≈ 0.02) sao desprezaveis
  no regime quase-estatico a 100 MHz e serao incorporadas em trabalho futuro.
-/

import Mathlib.Data.Real.Basic
import Mathlib.Data.Complex.Basic
import MaxwellKeyPLUS.DegradednessGeneral
import MaxwellKeyPLUS.SecrecyCapacityGeneral
import MaxwellKeyPLUS.ExactChannel

namespace MaxwellKey

namespace TemplateRealParams

/-- Exemplo de valores de TESTE FORMAL — NAO representam uma geometria fisica real.

    ATENCAO CRITICA: Estes valores (M_self=0.6, M_mutual=0.15) sao
    escolhidos PURAMENTE para facilitar provas automaticas (norm_num).
    Nao correspondem a nenhuma PCB real. Nao devem ser usados numa
    demonstracao experimental sem substituicao por valores medidos.

    - M_self=0.6, M_mutual=0.15: racio 0.25 = metade do limite de
      weak_coupling. E o PIOR CASO que ainda passa no teorema.
    - typical_f=3: valor conservador que satisfaz f^2 >= min_f_sq (~1.5).
      Num sistema real, f seria calculado a partir da geometria via
      compute_eve_distance_factor (ex: ~108 para ratio=3).

    Valores fisicos realistas tem acoplamento muito mais fraco:
    - Fallback simulator: M_self=0.21, M_mutual=0.022 (racio ~0.10)
    - TwoParallelStrips: M_self=0.0031, M_mutual=4.15e-6 (racio ~0.0013)

    O teorema e robusto: funciona para qualquer racio < 0.5.
-/
noncomputable def typical_M_self : ℝ := 6 / 10

noncomputable def typical_M_mutual : ℝ := 15 / 100

noncomputable def typical_Z₀ : ℝ := 50

noncomputable def typical_f : ℝ := 3

/-- Verificação: |M_mutual| < |M_self| / 2  (acoplamento fraco)
    Para valores típicos: 15/100 < (6/10)/2 = 3/10 ✓
-/
lemma typical_weak_coupling : |typical_M_mutual| < |typical_M_self| / 2 := by
  have h1 : typical_M_mutual ≥ 0 := by unfold typical_M_mutual; norm_num
  have h2 : typical_M_self ≥ 0 := by unfold typical_M_self; norm_num
  rw [abs_of_nonneg h1, abs_of_nonneg h2]
  unfold typical_M_mutual typical_M_self
  norm_num

/-- Verificação: M_self > 0
    Para valores típicos: 6/10 > 0 ✓
-/
lemma typical_M_self_pos : typical_M_self > 0 := by unfold typical_M_self; norm_num

/-- Verificação: Z₀ > 0
    Para valores típicos: 50 > 0 ✓
-/
lemma typical_Z₀_pos : typical_Z₀ > 0 := by unfold typical_Z₀; norm_num

lemma typical_h_mut_lt_self : |typical_M_mutual| < |typical_M_self| := by
  have h1 : |typical_M_mutual| < |typical_M_self| / 2 := typical_weak_coupling
  nlinarith [h1, abs_nonneg typical_M_self]

/-- Verificação: f² ≥ min_f_sq
    Para valores típicos: f² = 9, min_f_sq ≈ 1.5, logo 9 ≥ 1.5 ✓
-/
lemma typical_f_sq_ge_min : typical_f^2 ≥ min_f_sq typical_M_self typical_M_mutual typical_h_mut_lt_self := by
  have h1 : min_f_sq typical_M_self typical_M_mutual typical_h_mut_lt_self
          = (typical_M_self^2 + typical_M_mutual^2) * (typical_M_self + typical_M_mutual)^2 / (typical_M_self^2 - typical_M_mutual^2)^2 := by
    simp only [min_f_sq]
  rw [h1]
  have h_pos : (typical_M_self^2 - typical_M_mutual^2)^2 > 0 := by unfold typical_M_self typical_M_mutual; norm_num
  apply (div_le_iff₀ h_pos).mpr
  unfold typical_M_self typical_M_mutual typical_f
  norm_num

/-- Cria os parametros de segredo a partir de valores numericos.
    Requer provas explicitas das hipoteses fisicas.
-/
def create_params (M_self M_mutual Z₀ f : ℝ)
    (h_Z₀_pos : Z₀ > 0)
    (h_weak : |M_mutual| < |M_self| / 2)
    (h_M_self_pos : M_self > 0)
    (h_f_sq_ge_min : f^2 ≥ min_f_sq M_self M_mutual (by
      have h1 : |M_mutual| < |M_self| / 2 := h_weak
      have h2 : |M_mutual| < |M_self| := by nlinarith [h1, abs_nonneg M_self]
      exact h2
    )) : DegradednessParamsGeneral :=
  { M_self := M_self
    M_mutual := M_mutual
    Z₀ := Z₀
    f := f
    h_Z₀_pos := h_Z₀_pos
    h_weak := h_weak
    h_M_self_pos := h_M_self_pos
    h_f_sq_ge_min := h_f_sq_ge_min
  }

/-- Exemplo concreto com valores típicos. -/
noncomputable def typical_params : DegradednessParamsGeneral :=
  create_params typical_M_self typical_M_mutual typical_Z₀ typical_f
    typical_Z₀_pos typical_weak_coupling typical_M_self_pos typical_f_sq_ge_min

/-- Cria os parâmetros para o modelo exacto.
    Verifica que a ordem de Loewner se preserva sob a
    transformação exacta f(A) = I - (I+A)⁻¹.

    NOTA: requer a hipótese adicional S_bob ⪰ S_eve_sym,
    que é mais forte que f² ≥ min_f_sq.
-/
def create_params_exact (M_self M_mutual Z₀ f : ℝ)
    (h_Z₀_pos : Z₀ > 0)
    (h_weak : |M_mutual| < |M_self| / 2)
    (h_M_self_pos : M_self > 0)
    (h_f_sq_ge_min : f^2 ≥ min_f_sq M_self M_mutual (by
      have h1 : |M_mutual| < |M_self| / 2 := h_weak
      have h2 : |M_mutual| < |M_self| := by nlinarith [h1, abs_nonneg M_self]
      exact h2
    ))
    (h_le_sym : Matrix.loewner_le
      (DegradednessParamsGeneral.S_bob (create_params M_self M_mutual Z₀ f
        h_Z₀_pos h_weak h_M_self_pos h_f_sq_ge_min))
      (ExactChannel.S_eve_sym (create_params M_self M_mutual Z₀ f
        h_Z₀_pos h_weak h_M_self_pos h_f_sq_ge_min))) :
    Matrix.loewner_le
      (ExactChannel.f_on_symm (Z₀^2 * (M_self^2 + M_mutual^2)) (Z₀^2 * (2 * M_self * M_mutual)))
      (ExactChannel.f_on_symm (Z₀^2 * (M_self + M_mutual)^2 / f^2) 0) :=
  ExactChannel.degradedness_exact
    (create_params M_self M_mutual Z₀ f h_Z₀_pos h_weak h_M_self_pos h_f_sq_ge_min)
    h_le_sym

/-- Estimativa de f_att a partir de parâmetros de acoplamento,
    assumindo decaimento de campo próximo (near-field ~ 1/d³).

    Para duas faixas paralelas, o acoplamento M_mutual ~ 1/d³,
    logo se M_mutual é medido à distância d_bob,
    o acoplamento à distância d_eve é:
    M_eve ≈ M_mutual · (d_bob / d_eve)³

    O factor f é definido como |M_self / M_eve|,
    logo f ≈ |M_self / M_mutual| · (d_eve / d_bob)³.

    Para d_eve / d_bob = 3: f ≈ (0.6/0.15) · 27 = 4 · 27 = 108.

    INCONSISTENCIA INTENCIONAL (documentada):
    - compute_eve_distance_factor calcula f ≈ 108 para os typical values.
    - typical_f = 3 é um valor ARBITRARIO escolhido apenas para passar
      a prova formal (f^2 = 9 >= min_f_sq ~ 1.5).
    - Estes dois valores NAO sao consistentes entre si.
    - Num workflow real, typical_f seria substituido pelo valor calculado
      a partir da geometria fisica.
-/
noncomputable def compute_eve_distance_factor (M_self M_mutual distance_ratio : ℝ) : ℝ :=
  |M_self / M_mutual| * distance_ratio^3

/- NOTA sobre o factor f:
   Os valores `typical_M_self = 0.6` e `typical_M_mutual = 0.15` foram
   escolhidos como fracoes simples para facilitar as provas `norm_num`.
   Nao representam uma geometria fisica especifica.

   O valor `f = 3` e usado como exemplo conservador que satisfaz
   `f^2 >= min_f_sq` para estes valores (min_f_sq ~ 1.5).
   Num sistema real, f seria calculado a partir da geometria fisica
   via `compute_eve_distance_factor`. -/

/-- Injeta parametros a partir de um ficheiro JSON.

    NOTA: Lean 4 nao suporta leitura de ficheiros JSON diretamente
    no modo de verificacao de provas. O workflow e:

    Workflow A (Simulacao):
    1. Correr `python3 scripts/simulate_circuit.py` (ou COMSOL)
    2. Abrir `scripts/params.json` e copiar os valores numericos
    3. Colar nesta funcao e chamar `lake build`

    Workflow B (Testbed Real — VNA/SDR):
    1. Montar PCB, calibrar VNA, medir S-parameters
    2. Correr `python3 scripts/vna_capture.py --vna nanovna ...`
    3. Correr `python3 scripts/sparams_to_params.py --s2p measured.s2p`
    4. Abrir `scripts/params.json` e copiar os valores MEDIDOS
    5. Colar nesta funcao e chamar `lake build`

    Exemplo:
    ```
    def my_params := params_from_json
      (M_self := 0.003112)   -- valor medido do VNA
      (M_mutual := 0.000004) -- valor medido do VNA
      (Z0 := 50.0)
      (f := 263.41)          -- estimado da posicao de Eve
    ```
-/
def params_from_json (M_self M_mutual Z₀ f : ℝ)
    (h_Z₀_pos : Z₀ > 0)
    (h_weak : |M_mutual| < |M_self| / 2)
    (h_M_self_pos : M_self > 0)
    (h_f_sq_ge_min : f^2 ≥ min_f_sq M_self M_mutual (by
      have h1 : |M_mutual| < |M_self| / 2 := h_weak
      have h2 : |M_mutual| < |M_self| := by nlinarith [h1, abs_nonneg M_self]
      exact h2
    )) : DegradednessParamsGeneral :=
  create_params M_self M_mutual Z₀ f
    h_Z₀_pos h_weak h_M_self_pos h_f_sq_ge_min

/-- Exemplo de SecrecyParamsGeneral usando os valores typical.
    Demonstra que o teorema generalizado (com min_f_sq) pode ser
    instanciado e verificado numericamente. -/
noncomputable def example_secrecy_general : SecrecyParamsGeneral :=
  { toDegradednessParamsGeneral := typical_params
    N0 := 4.0038821e-15
    h_N0_pos := by norm_num }

/- NOTA: Para usar valores do scripts/params.json, definir:

    noncomputable def my_params : DegradednessParamsGeneral :=
      params_from_json
        (M_self := ...)  -- valor do JSON
        (M_mutual := ...)  -- valor do JSON
        (Z₀ := ...)  -- valor do JSON
        (f := ...)  -- valor do JSON
        (by norm_num) (by norm_num) (by norm_num) (by norm_num)

    Se norm_num falhar em h_f_sq_ge_min, usar field_simp e nlinarith. -/

/-- Verificacao: a capacidade de segredo do exemplo generalizado e positiva. -/
theorem example_secrecy_positive :
    SecrecyParamsGeneral.secrecy_capacity example_secrecy_general > 0 := by
  apply SecrecyParamsGeneral.secrecy_capacity_pos

end TemplateRealParams

end MaxwellKey
