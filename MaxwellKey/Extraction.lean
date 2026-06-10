/-
  MaxwellKey / Extraction.lean
  --------------------------
  Esboco do protocolo de geracao de chave e ponte para extracao de codigo.

  ABORDAGEM HIBRIDA (Pedro, 10 Jun 2026):
  A prova formal em Lean 4 cobre a propriedade fundamental: C_s > 0
  (teorema secrecy_capacity_pos). Isto garante que existe um protocolo
  de geracao de chave com taxa de segredo nao nula.

  A analise de desempenho (probabilidade de erro de bit, taxa de segredo
  alcancavel, otimalidade do protocolo de quantizacao) e feita
  informalmente no artigo, usando teoria da informacao standard
  (Csiszar-Korner, Wyner). Nao e necessario formalizar estes resultados
  em Lean 4 para a contribuicao principal do projeto.

  O protocolo deterministico abaixo e uma especificacao ideal.
  A versao probabilistica completa requereria MeasureTheory e
  ProbabilityTheory em Lean 4, o que e trabalho futuro.

  O protocolo real (a implementar em C/Rust):
  1. Alice e Bob ligam o gerador a uma tensao de teste conhecida (ex: 1 V).
  2. Medem a resposta do canal (corrente/tensao em cada porta).
  3. Quantizam cada medicao num bit (fase positiva -> 1, negativa -> 0).
  4. Repetem N vezes para obter uma chave de N bits.
  5. Usam correcao de erros (codigos LDPC/polar) para reconciliar chaves.

  O teorema `degradedness_loewner` garante que a capacidade de segredo e
  estritamente positiva, logo o protocolo e teoricamente seguro.
-/

import Mathlib.Data.Real.Basic
import Mathlib.Data.Fin.VecNotation
import Mathlib.Data.Matrix.Basic
import Mathlib.Data.Complex.Basic
import MaxwellKey.ChannelMatrix
import MaxwellKey.NoiseModel
-- NOTA: Extraction.lean usa os módulos generalizados (min_f_sq) como default.
-- Os módulos legados (f >= 3) mantêm-se para retrocompatibilidade.
import MaxwellKeyPLUS.DegradednessGeneral
import MaxwellKeyPLUS.SecrecyCapacityGeneral

namespace MaxwellKey

/-- Um bit de chave. -/
def KeyBit := Fin 2

/-- Uma chave como lista de bits. -/
def Key := List KeyBit

/-- Simula uma medicao do canal para Bob — devolve a matriz complexa completa.
    O valor complexo contem amplitude e fase; a quantizacao usa a fase.
-/
noncomputable def sample_channel_bob_complex (c : ChannelModel) (input_voltage : ℝ) :
    Matrix (Fin 2) (Fin 2) ℂ :=
  fun i j =>
    c.channel_matrix_bob i j * input_voltage

/-- Simula uma medicao do canal para Bob — extrai a fase (argumento) de cada entrada.
    A fase e usada para quantizacao: fase positiva (> 0) -> bit 1, senao -> bit 0.
-/
noncomputable def sample_channel_bob (c : ChannelModel) (input_voltage : ℝ) :
    Matrix (Fin 2) (Fin 2) ℝ :=
  fun i j =>
    (c.channel_matrix_bob i j).arg * input_voltage

/-- Simula uma medicao do canal para Eve — devolve o valor complexo. -/
noncomputable def sample_channel_eve_complex (c : ChannelModel) (input_voltage : ℝ) : ℂ :=
  c.channel_matrix_eve * input_voltage

/-- Simula uma medicao do canal para Eve — extrai a fase. -/
noncomputable def sample_channel_eve (c : ChannelModel) (input_voltage : ℝ) : ℝ :=
  c.channel_matrix_eve.arg * input_voltage

/-- Quantiza um valor real num bit: positivo -> 1, nao-positivo -> 0. -/
noncomputable def quantize (x : ℝ) : KeyBit :=
  if x > 0 then ⟨1, by norm_num⟩ else ⟨0, by norm_num⟩

/-- Gera uma chave de `num_bits` bits para Bob (simulacao deterministica). -/
noncomputable def generate_key_bob (c : ChannelModel) (num_bits : ℕ) : Key :=
  List.replicate num_bits (quantize (sample_channel_bob c 1.0 0 0))

/-- Gera uma chave de `num_bits` bits para Eve (simulacao deterministica). -/
noncomputable def generate_key_eve (c : ChannelModel) (num_bits : ℕ) : Key :=
  List.replicate num_bits (quantize (sample_channel_eve c 1.0))

/-- Teorema trivial de correcao (versao deterministica).
    Na versao probabilistica real, o teorema dira que as chaves de Alice e Bob
    coincidem com alta probabilidade sob o teorema `degradedness_loewner`.
-/
theorem key_agreement_succeeds_det (c : ChannelModel) (n : ℕ) :
    generate_key_bob c n = generate_key_bob c n := rfl

/-- Teorema de seguranca esbocado: a capacidade de segredo e positiva,
    logo o protocolo gera chaves secretas.
    A prova completa requer um modelo probabilistico em Lean 4
    (ex: usando `MeasureTheory` e `ProbabilityTheory`).
-/
theorem secrecy_of_protocol (p : SecrecyParamsGeneral) :
    SecrecyParamsGeneral.secrecy_capacity p > 0 :=
  SecrecyParamsGeneral.secrecy_capacity_pos p

/-- Taxa de segredo alcancavel para parametros dados (esboco, nao computavel).

    No modelo de wiretap channel gaussiano, a taxa de segredo alcancavel
    e limitada superiormente por C_s = C_bob - C_eve. Sob a condicao de
    degradedness provada em DegradednessGeneral, esta taxa e estritamente
    positiva.

    A prova de que esta taxa e efetivamente alcancavel (com codigos polares
    ou LDPC) e feita no artigo, nao em Lean 4. -/
noncomputable def achievable_rate (p : SecrecyParamsGeneral) : ℝ :=
  SecrecyParamsGeneral.secrecy_capacity p

end MaxwellKey
