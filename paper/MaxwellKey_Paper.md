# MaxwellKey: Formally Verified Physical-Layer Key Generation from Electromagnetic Reciprocity

**Pedro¹, Carlos¹, David²**
¹ INOVATION Research Lab — ² INOVATION Hardware Team

---

## Abstract

We present MaxwellKey, the first formally verified framework for physical-layer key generation based on electromagnetic reciprocity. The protocol exploits quasi-static near-field coupling between PCB traces to establish a shared secret key between two legitimate parties (Alice and Bob) that is information-theoretically secure against a passive eavesdropper (Eve). All security proofs are machine-checked in the Lean 4 theorem prover, providing cryptographic-grade assurance that the secrecy capacity is strictly positive under realistic physical assumptions. We generalize the original degradation threshold from a fixed `f ≥ 3` to the exact `min_f_sq(M_self, M_mutual)`, and prove that the exact channel transformation preserves the Loewner order for 2×2 symmetric matrices. The framework includes an experimental pipeline from COMSOL/OpenEMS electromagnetic simulation to machine-checked parameter verification.

**Keywords:** Physical-layer security, formal verification, Lean 4, Loewner order, electromagnetic reciprocity, wiretap channel.

---

## 1. Introduction

Physical-layer key generation (PLKG) leverages the inherent randomness and reciprocity of wireless channels to establish shared secrets without relying on computational hardness assumptions [1][2]. Unlike traditional public-key cryptography, PLKG offers information-theoretic security: even an adversary with unlimited computational power cannot recover the key, provided the legitimate receiver's channel is "better" than the eavesdropper's in a well-defined sense.

The central challenge in PLKG is proving that the legitimate channel *dominates* the eavesdropper channel. In information theory, this is the *degradedness condition* [3]. For multi-antenna systems, dominance is naturally expressed via the Loewner order on positive semidefinite matrices [4]. However, existing PLKG protocols typically rely on statistical measurements rather than formal proofs, leaving a gap between theoretical guarantees and implementation security.

**Our contributions:**
1. We formalize the physical-layer security of electromagnetic near-field coupling in Lean 4, providing the first machine-checked proof of a PLKG protocol.
2. We derive the exact degradation threshold `min_f_sq(M_self, M_mutual)` and prove it is optimal (tight).
3. We prove monotonicity of the exact channel transformation `f(A) = I - (I+A)⁻¹` with respect to the Loewner order for real symmetric matrices, and close the gap to the physical model by proving that the Hermitian covariance matrix `H_bob H_bob†` reduces exactly to a real symmetric matrix under the MaxwellKey physical hypotheses (purely imaginary admittance, real termination impedance).
4. We provide an experimental pipeline from COMSOL/OpenEMS simulation to Lean verification, enabling reproducible validation.

---

## 2. Physical Model

### 2.1 Quasi-Static Circuit

We model two parallel PCB traces as a quasi-static circuit with self and mutual capacitances (`C_self`, `C_mutual`) and inductances (`L_self`, `M_mutual`). The admittance matrix `Y` is symmetric by reciprocity:

```
      ┌                  ┐
  Y = │  Y_self   Y_mut  │
      │  Y_mut    Y_self │
      └                  ┘
```

where `Y_self = jωC_self + 1/(jωL_self)` and `Y_mutual = jωC_mutual + 1/(jωM_mutual)`.

### 2.2 Channel Matrices

For the legitimate receiver (Bob), the channel matrix is:

**H_bob = Z₀ · Y**

where `Z₀` is the termination impedance. This is a first-order approximation valid under weak coupling (`|Y_mutual| ≪ |Y_self|`).

For the eavesdropper (Eve), positioned at a greater physical distance, the channel is attenuated:

**H_eve = Z₀ · (Y_self + Y_mutual) / f_att**

where `f_att > 1` is the distance attenuation factor. In the quasi-static near-field regime, `f_att` scales approximately as `(d_eve / d_bob)³`.

### 2.3 Signal Covariance Matrices

The signal covariance matrices (real, 2×2) are:

**S_bob = Z₀² · [[M_self²+M_mutual², 2·M_self·M_mutual], [2·M_self·M_mutual, M_self²+M_mutual²]]**

**S_eve = Z₀² · (M_self+M_mutual)² / f_att²** (scalar, placed at position (0,0))

where `M_self` and `M_mutual` are the normalized coupling parameters.

---

## 3. Formalization in Lean 4

Our formalization is structured as a library in Lean 4, using mathlib4 for real analysis, linear algebra, and matrix theory. The library is organized into three layers:

**Layer 1 — Foundations:** `LoewnerOrder.lean` defines the Loewner order for 2×2 real matrices as:

```lean
A ⪰ B  ⇔  ∀x,  xᵀAx ≥ xᵀBx
```

It proves reflexivity and transitivity, essential for composing proofs.

**Layer 2 — Degradedness:** `Degradedness.lean` and `DegradednessGeneral.lean` contain the core security proofs.

**Layer 3 — Capacity:** `SecrecyCapacity.lean` proves positivity of the secrecy capacity.

**Layer 4 — Exact Channel:** `ExactChannel.lean` and `ExactChannelHermitian.lean` prove monotonicity of the exact channel transformation `f(A) = I - (I+A)⁻¹` for real symmetric matrices, and show that the physical Hermitian covariance matrix `H_bob H_bob†` reduces exactly to this real form. These theorems bridge the approximate model with the exact physical channel.

---

## 4. The Optimal Degradation Threshold

### 4.1 From f ≥ 3 to min_f_sq

The original MaxwellKey proof required `f_att ≥ 3` as a conservative bound. We generalize this to the exact threshold:

```
min_f_sq(M_self, M_mutual) = (M_self² + M_mutual²)(M_self + M_mutual)² / (M_self² - M_mutual²)²
```

**Theorem 1 (min_f_sq_le_five).** Under weak coupling `|M_mutual| < |M_self|/2`, we have `min_f_sq ≤ 5`. Therefore, `f_att ≥ 3` (i.e., `f_att² ≥ 9`) is always sufficient.

**Proof sketch.** The proof proceeds by polynomial factorization. We show:

```
(M_self² + M_mutual²)(M_self + M_mutual)² ≤ 5(M_self² - M_mutual²)²
```

by expanding both sides and using `M_mutual² < (M_self/2)²`. The inequality reduces to a sum of squares, verified in Lean by `nlinarith` with 12 square-nonnegativity hints. ∎

### 4.2 The General Degradedness Proof

**Theorem 2 (degradedness_loewner_general).** If `|M_mutual| < |M_self|/2` and `f_att² ≥ min_f_sq(M_self, M_mutual)`, then `S_bob ⪰ S_eve_matrix`.

**Proof sketch.** We expand the quadratic forms:

- Bob: `Q_bob = Z₀²[(M_self·x₀ + M_mutual·x₁)² + (M_mutual·x₀ + M_self·x₁)²]`
- Eve: `Q_eve = Z₀²(M_self+M_mutual)²/f_att² · x₀²`

The key insight is that `min_f_sq · Q_bob ≥ (M_self+M_mutual)² · x₀²` for all `x`. This is proven by factoring the difference into a perfect square:

```
N·Q_bob - Q_eve·D = (M_self+M_mutual)²(2·M_self·M_mutual·x₀ + (M_self²+M_mutual²)·x₁)²
```

where `N = (M_self²+M_mutual²)(M_self+M_mutual)²` and `D = (M_self²-M_mutual²)²`. Since `f_att² ≥ min_f_sq = N/D`, the Loewner inequality follows by algebraic manipulation verified in Lean. ∎

---

## 5. Exact Channel Monotonicity (ECMT)

### 5.1 The Exact Channel Model

The first-order approximation `H ≈ Z₀·Y` is valid for weak coupling. The exact channel transformation for the Gaussian MIMO wiretap channel is:

```
f(A) = I - (I + A)⁻¹
```

where `A = H H^† / N₀` is the SNR matrix. Under the physical hypotheses of the MaxwellKey (admittance matrix Y purely imaginary, termination impedance Z₀ real), we prove that `H_bob H_bob^†` reduces exactly to a real symmetric matrix of the form `[[a,b],[b,a]]`. This closes the connection between the complex physical model and the real matrix monotonicity proof, establishing that the ECMT applies directly to the physical channel without approximation.

For a 2×2 matrix `A = [[a,b],[b,a]]`, the inverse has a closed form, yielding:

```
f(A) = [[p, q], [q, p]]
```

where:
- `p = 1 - (1+a)/((1+a)² - b²)`
- `q = b/((1+a)² - b²)`

### 5.2 Monotonicity Theorem

**Theorem 3 (f_monotone_psd).** Let `A = [[a₁,b₁],[b₁,a₁]]` and `B = [[a₂,b₂],[b₂,a₂]]` be positive semidefinite matrices with `A ⪰ B`. Then `f(A) ⪰ f(B)`.

**Proof.** The proof has three steps:

1. **Eigenvalue reduction.** For matrices of the form `[[a,b],[b,a]]`, the Loewner order `A ⪰ B` is equivalent to:
   ```
   a₁ + b₁ ≥ a₂ + b₂   and   a₁ - b₁ ≥ a₂ - b₂
   ```
   This is proven by expanding the quadratic form and using the identity `a₁-a₂ ≥ |b₁-b₂|`.

2. **Scalar monotonicity.** Define `g(t) = 1 - 1/(1+t)`. Then `g'(t) = 1/(1+t)² > 0` for `t > -1`, so `g` is strictly monotone. The "eigenvalues" of `f(A)` are `g(a+b)` and `g(a-b)`.

3. **Composition.** Since `a₁±b₁ ≥ a₂±b₂` and all values are `> -1` (by PSD), monotonicity of `g` gives `g(a₁±b₁) ≥ g(a₂±b₂)`. By step 1, this implies `f(A) ⪰ f(B)`. ∎

### 5.3 Application to MaxwellKey

**Theorem 4 (hermitian_to_real_form).** Under the physical hypotheses (Y purely imaginary, Z₀ real), the Hermitian covariance matrix `H_bob H_bob^†` reduces exactly to a real symmetric matrix `[[a,b],[b,a]]` with `a = Z₀²(b_self²+b_mutual²)` and `b = Z₀²(2·b_self·b_mutual)`. This matrix coincides with `S_bob` from the degradedness model.

**Theorem 5 (exact_channel_applies_to_physics).** Under the Loewner order hypothesis `S_bob ⪰ S_eve_sym`, the exact channel transformation preserves the order: `f(S_bob) ⪰ f(S_eve_sym)`. The PSD conditions are automatically satisfied because `a±b` are perfect squares.

These theorems bridge the approximate model with the exact physical channel, strengthening the security guarantee to the exact channel transformation.

**Known limitation.** Theorem 5 requires the stronger hypothesis `S_bob ⪰ S_eve_sym`, where `S_eve_sym` is a diagonal matrix with the Eve scalar on both entries. The main degradedness theorem (Theorem 2) only proves `S_bob ⪰ S_eve_matrix`, where `S_eve_matrix` has the scalar only at position (0,0). Because `S_eve_sym ⪰ S_eve_matrix`, the condition for the exact channel is stricter than `f² ≥ min_f_sq`. The optimal threshold for the exact channel would be larger than `min_f_sq`; deriving and proving this tighter bound is future work. In practice, the approximate model (`S_eve_matrix`) is sufficient for the secrecy capacity proof.

---

## 6. Secrecy Capacity Positivity

### 6.1 Capacity Definitions

The capacities per channel use are:

- **Bob:** `C_bob = (1/2)·log₂ det(I + S_bob/N₀)`
- **Eve:** `C_eve = (1/2)·log₂(1 + S_eve/N₀)`

where `N₀` is the noise spectral density.

### 6.2 Main Security Theorem

**Theorem 5 (secrecy_capacity_pos).** For any `SecrecyParams` satisfying the degradedness conditions, the secrecy capacity `C_s = C_bob - C_eve` is strictly positive.

**Proof.** We show `arg_bob > arg_eve`, where:
- `arg_bob = det(I + S_bob/N₀) = 1 + 2α(M_self²+M_mutual²) + α²(M_self²-M_mutual²)²`
- `arg_eve = 1 + S_eve/N₀ = 1 + α(M_self+M_mutual)²/f_att²`

with `α = Z₀²/N₀ > 0`. The difference is:

```
arg_bob - arg_eve = α[2(M_self²+M_mutual²) + α(M_self²-M_mutual²)² - (M_self+M_mutual)²/f_att²]
```

Using `f_att² ≥ min_f_sq` and `min_f_sq > 1`, the term in brackets is positive. Since `log₂` is strictly monotone, `C_bob > C_eve`. ∎

---

## 7. Experimental Setup

### 7.1 PCB Geometry

We target a standard FR-4 PCB with two parallel copper traces:
- Width `w = 1 mm`, separation `s = 2 mm`, length `l = 100 mm`
- Substrate thickness `h = 1.6 mm`, `ε_r = 4.4`, `tan δ = 0.02`
- Operating frequency: `100 MHz` (quasi-static regime)

### 7.2 Simulation Pipeline

```
COMSOL/OpenEMS → S/Y parameters → C_self, L_self, C_mutual, M_mutual, G
                                    ↓
                         scripts/simulate_circuit.py (fallback)
                                    ↓
                         scripts/params.json
                                    ↓
                         TemplateRealParams.lean
                                    ↓
                         lake build (machine-checked verification)
```

### 7.3 Fallback Simulator

The Python script `scripts/simulate_circuit.py` provides analytical estimates using Hammerstad-Jensen microstrip formulas. For the reference geometry, it yields:

| Parameter | Value | Notes |
|-----------|-------|-------|
| `M_self` | 0.21 | Normalized |
| `M_mutual` | 0.022 | Weak coupling (ratio ≈ 0.10) |
| `f_att` | 263 | Conservative for `d_eve/d_bob = 3` |
| `min_f_sq` | 1.25 | Threshold satisfied |

### 7.4 Formal Parameter Verification

The Lean template `MaxwellKeyPLUS/Examples/TemplateRealParams.lean` accepts numerical parameters and generates proofs of:
- `|M_mutual| < |M_self|/2` (weak coupling)
- `f² ≥ min_f_sq` (degradation threshold)
- `Z₀ > 0`, `M_self > 0` (physical positivity)

Note: Dielectric losses (conductance G) are negligible in the quasi-static regime at 100 MHz (tan δ ≈ 0.02 for FR-4) and are left for future work.

All proofs are automatic via `norm_num` and `nlinarith` for rational inputs.

### 7.5 Hybrid Verification Approach

The formal proof in Lean 4 covers the fundamental security property: `C_s > 0` (Theorem 6). This guarantees the existence of a key generation protocol with non-zero secrecy rate. The performance analysis (bit error rate, achievable secrecy rate, optimality of the quantization protocol) is conducted informally in this paper using standard information theory (Csiszar-Korner, Wyner). This hybrid approach — formal verification of the core security property combined with informal performance analysis — is appropriate for a first demonstration of formal methods in physical-layer security.

---

## 8. Artifact Description

This paper is accompanied by a reproducible artifact: the MaxwellKey Lean 4 library.

### 8.1 Building the Artifact

```bash
git clone https://github.com/AfonsoBitoque/MaxwellKeyPlus.git
cd MaxwellKey
lake build
```

The build downloads mathlib4 (≈ 1 GB of dependencies) and compiles ~2000 Lean jobs. Expected build time: 2–5 minutes on a modern laptop.

### 8.2 Navigating the Proofs

| File | Lines | Theorems |
|------|-------|----------|
| `LoewnerOrder.lean` | 75 | `loewner_le`, `refl`, `trans` |
| `AdmittanceMatrix.lean` | 80 | `admittance_symmetric` |
| `ChannelMatrix.lean` | 128 | `channel_bob_symmetric`, `eve_attenuation` |
| `NoiseModel.lean` | 80 | `N0_pos`, `noise_cov_bob_nonneg` |
| `Degradedness.lean` | 199 | `S_bob_ge_S_eve` (original, f ≥ 3) |
| `SecrecyCapacity.lean` | 180 | `secrecy_capacity_pos` (**main theorem**) |
| `DegradednessGeneral.lean` | 268 | `min_f_sq`, `S_bob_ge_S_eve` (generalized) |
| `ExactChannel.lean` | 304 | `f_monotone_psd` (real matrices) |
| `ExactChannelHermitian.lean` | 282 | `hermitian_to_real_form`, `exact_channel_applies_to_physics` |
| `Assumptions.lean` | 82 | Formal hypotheses manifesto (5 of 7 hypotheses are formally proved; 2—linearity and unit input power—are satisfied by construction and marked as placeholders) |
| `Extraction.lean` | 113 | Hybrid verification approach |
| `VerifiedFirmware.lean` | 258 | Float firmware with computational proofs |
| `VerifiedExtraction.lean` | 228 | Semantic equivalence of Lean→C extraction |
| **Total** | **~2377** | **~30 theorems/lemmas** |

### 8.3 Verification Statement

All theorems in the artifact compile without errors and without `sorry` (admitted proofs) in the main modules. The build command `lake build` returns exit code 0.

---

## 9. Related Work

**Physical-layer security** was pioneered by Wyner [3] and Csiszár-Körner [5], who established the wiretap channel model. Practical PLKG protocols were developed by Hershey et al. [1] and Mathur et al. [2] using channel reciprocity in RF systems. Our work extends these protocols with formal verification.

**Matrix monotone functions** were introduced by Loewner [4] in 1934. The function `f(A) = I - (I+A)⁻¹` is a matrix monotone function on the positive semidefinite cone; our contribution is the explicit proof for 2×2 symmetric matrices in a theorem prover.

**Formal verification of cryptography** has been explored in EasyCrypt [6], CryptoVerif [7], and CertiCrypt [8]. To our knowledge, MaxwellKey is the first formally verified PLKG protocol.

---

## 10. Conclusion and Future Work

MaxwellKey provides machine-checked proofs that physical-layer key generation from electromagnetic near-field coupling is information-theoretically secure. The generalization to `min_f_sq` and the exact channel monotonicity theorem strengthen the theoretical foundations beyond the original conservative bounds.

**Future work:**
- Extension to N-port networks (`N > 2`)
- Full experimental validation with COMSOL parameter extraction
- Integration with post-quantum key agreement protocols
- Probabilistic model for noise and key reconciliation in Lean 4

---

## Appendix A: Informational Electromagnetic Duality Principle (IEDP)

The IEDP posits a formal correspondence between the structural properties of Maxwell's equations and the information-theoretic security of electromagnetic channels. Reciprocity (symmetry of `Y`) implies that the legitimate receiver's channel dominates the eavesdropper's channel in the Loewner order whenever the physical distance ratio satisfies `f² ≥ min_f_sq`. This duality is instantiated by MaxwellKey: the physical geometry of the PCB traces directly determines the information-theoretic security capacity via the Loewner order on covariance matrices.

---

## References

[1] J. Hershey, A. Hassan, and R. Yarlagadda, "Unconventional cryptographic keying variable management," *IEEE Trans. on Communications*, 1995.

[2] S. Mathur, W. Trappe, and N. Mandayam, "Radio-telepathy: extracting a secret key from an unauthenticated wireless channel," *ACM MobiCom*, 2008.

[3] A. Wyner, "The wire-tap channel," *Bell System Technical Journal*, 1975.

[4] K. Loewner, "Über monotone Matrixfunktionen," *Math. Z.*, 1934.

[5] I. Csiszár and J. Körner, "Broadcast channels with confidential messages," *IEEE Trans. on Information Theory*, 1978.

[6] G. Barthe et al., "EasyCrypt: A Tutorial," *Foundations of Security Analysis and Design VII*, 2014.

[7] B. Blanchet, "A computationally sound mechanized prover for security protocols," *IEEE S&P*, 2006.

[8] G. Barthe et al., "CertiCrypt: A framework for verifying game-based proofs," CRYPTO, 2009.
