# The Informational Electromagnetic Duality Principle (IEDP)
## A Sketch Preprint

**Authors:** Pedro (INOVATION), with formal verification by Carlos & Kimi
**Date:** 10 June 2026
**Status:** Sketch / preprint — not yet submitted

---

### Abstract

The Informational Electromagnetic Duality Principle (IEDP) establishes a formal correspondence between the security properties of electromagnetic communication channels and the structural properties of their governing Maxwell equations. We postulate that the reciprocity structure inherent in Maxwell's equations constrains the information-theoretic security capacity of any physical communication channel, and that this constraint can be made precise through a hierarchy of monadic abstractions. The MaxwellKey physical-layer key generation protocol serves as the first fully verified instance of this principle in the quasi-static regime. This note sketches the theoretical framework, the monad hierarchy, the experimental validation strategy, and the open problems.

---

### 1. The Duality

In classical electromagnetics, the Lorentz reciprocity theorem states that the coupling between two antennas is symmetric: the voltage induced at antenna A by a current at antenna B equals the voltage induced at B by the same current at A. This symmetry is not an approximation — it is a fundamental consequence of the self-adjointness of the Maxwell operator in reciprocal media.

In information theory, the degradedness condition for wiretap channels (Wyner 1975, Csiszar-Korner 1978) requires that the legitimate receiver's channel *dominates* the eavesdropper's channel. For multi-antenna systems, this dominance is naturally expressed via the Loewner order on positive semidefinite matrices: `A ⪰ B` iff `A - B` is PSD.

**The IEDP posits that these two constraints are duals.** The physical reciprocity structure of the Maxwell equations constrains the information-theoretic security capacity. Specifically:

- **Physical side:** The admittance matrix `Y` is symmetric (`Y = Y^T`).
- **Geometric side:** Coupling strength decays with distance (near-field: `~1/d^3`).
- **Information side:** The Loewner order `S_bob ⪰ S_eve` holds whenever the distance ratio `f` satisfies `f^2 >= min_f_sq`.

The IEDP states that this is not a coincidence but a manifestation of a deeper structural duality between electromagnetic propagation and information flow.

---

### 2. The Monad Hierarchy

We propose a hierarchy of monadic abstractions that unify the description of electromagnetic propagation across different regimes. Each monad captures the essential structure of Maxwell's equations at a specific scale, while exposing a common interface for information-theoretic analysis.

#### 2.1 Admittance Matrix Instantiation (AMI) — Quasi-Static Regime

The base of the hierarchy. Valid when the physical dimensions are much smaller than the wavelength (`L << lambda/4`). The channel is fully characterized by the admittance matrix `Y`, which relates port currents to port voltages:

```
I = Y * V
```

The AMI monad encapsulates the linear relationship and its symmetry properties. This is the regime validated by MaxwellKey.

**Status:** Fully formalized in Lean 4 (`AdmittanceMatrix.lean`, `ChannelMatrix.lean`).

#### 2.2 SParameterMonad — Transmission Line Regime

When the quasi-static approximation breaks down (`L ~ lambda/4` or larger), the channel must be described by scattering parameters (S-parameters). The SParameterMonad generalizes AMI by replacing the admittance matrix with the full S-matrix, which captures wave propagation, reflection, and interference effects.

**Status:** Planned. Requires extension of the formalization to complex matrix functions and network theory.

#### 2.3 GreenMonad — Far-Field / Full-Wave Regime

At the highest level, the GreenMonad captures the full solution of Maxwell's equations via dyadic Green's functions. This regime is relevant for far-field communication, antenna arrays, and radar cross-section analysis.

**Status:** Conceptual. Requires substantial theoretical development before formalization.

#### 2.4 NoisyChannelMonad — Integration of Noise

A cross-cutting extension that integrates thermal noise (Johnson-Nyquist) into any of the above monads. The noise is modeled as additive white Gaussian with covariance `N0*I`.

**Status:** Partially formalized (`NoiseModel.lean`). Full integration with the monad hierarchy is future work.

---

### 3. MaxwellKey as the First Validated Instance

The MaxwellKey protocol exploits quasi-static near-field coupling between PCB traces. In this regime:

- The admittance matrix `Y` is symmetric (reciprocity).
- The coupling strength decays rapidly with distance (`~1/d^3` for near-field).
- The legitimate receiver (Bob) is physically close; the eavesdropper (Eve) is farther.

The IEDP states that the physical distance ratio translates directly into an information-theoretic security gap via the Loewner order on covariance matrices.

#### 3.1 Formal Results (Lean 4)

All results below are machine-checked in Lean 4 with **zero `sorry`** and **zero `axiom`**:

| Theorem | Description |
|---------|-------------|
| `admittance_symmetric` | `Y = Y^T` — reciprocity |
| `min_f_sq` | Optimal degradation threshold |
| `min_f_sq_le_five` | Under weak coupling, `min_f_sq <= 5` |
| `S_bob_ge_S_eve` | Generalized degradedness: `f^2 >= min_f_sq => S_bob ⪰ S_eve` |
| `secrecy_capacity_pos` | **Main theorem:** `C_s > 0` |
| `hermitian_to_real_form` | `H_bob H_bob^†` reduces to real `[[a,b],[b,a]]` |
| `exact_channel_applies_to_physics` | `f_monotone_psd` applies to physical channel |

#### 3.2 Experimental Pipeline

The MaxwellKey project includes a complete experimental pipeline:

1. **COMSOL/OpenEMS simulation** -> extract `C_self`, `L_self`, `C_mutual`, `M_mutual`
2. **Python fallback simulator** -> analytical estimates (Hammerstad-Jensen)
3. **JSON parameter file** -> bridge between simulation and formal verification
4. **Lean 4 template** -> automatic proof of all physical hypotheses
5. **C firmware reference** -> key generation protocol for hardware deployment

---

### 4. MaxwellKeyPLUS Contributions

The MaxwellKeyPLUS extension advances the IEDP program in four ways:

1. **Optimal threshold:** Replaces the fixed `f^2 >= 5` with the exact `min_f_sq(M_self, M_mutual)`, derived from the determinant of `S_bob - S_eve`. The threshold is proven tight.

2. **Exact channel model:** Proves that `H_bob H_bob^†` reduces exactly to a real symmetric matrix `[[a,b],[b,a]]` under the physical hypotheses (Y purely imaginary, Z0 real). This closes the connection between the complex physical model and the real matrix monotonicity proof `f_monotone_psd`.

3. **Phase extraction:** Uses `Complex.arg` for signal quantization instead of `Re`, exploiting the full complex structure of the admittance matrix.

4. **Computable examples:** Provides `Float`-based numerical evaluation (`TwoParallelStripsComputable.lean`) and a template for COMSOL/OpenEMS parameters (`TemplateRealParams.lean`).

---

### 5. Open Problems

#### 5.1 Theoretical

- **Full spectral theory for `f(A) = I - (I+A)^(-1)`:** The current proof is for 2x2 matrices. Extension to NxN requires the spectral theorem for Hermitian matrices and operator monotonicity theory (Loewner 1934).

- **Extension to N-port networks (N > 2):** The degradedness proof generalizes naturally, but the exact form of `min_f_sq` becomes more complex. The factorization into a perfect square may not hold for N > 2.

- **Noise correlation:** The current model assumes uncorrelated noise (`N0*I`). Real PCBs have correlated noise due to shared ground planes and substrate coupling.

- **Active eavesdropper:** The current proof assumes a passive Eve. An active adversary could inject signals to probe the channel — this requires extending the model to authenticated key exchange.

#### 5.2 Formal Verification

- **Probability theory in Lean 4:** The full probabilistic analysis (BER, achievable rates) requires `MeasureTheory` and `ProbabilityTheory`, which are still under development in mathlib4.

- **Automatic code extraction:** The current C code is a manual translation. True extraction from Lean 4 requires a verified compiler backend.

#### 5.3 Experimental

- **COMSOL/OpenEMS validation:** Parameters must be extracted from full-wave simulation for the target geometry (1 mm width, 2 mm separation, 10 cm length, FR-4, 100 MHz).

- **Hardware demonstration:** SDR-based implementation (RTL-SDR or similar) to measure real channels and generate keys.

- **Distance scaling:** Verify the `~1/d^3` near-field decay experimentally across multiple distances.

---

### 6. Relationship to Existing Work

- **Loewner (1934):** Theory of monotone matrix functions. Our `f_monotone_psd` is a concrete instance for 2x2 matrices.
- **Wyner (1975):** Wiretap channel model. Our `secrecy_capacity_pos` instantiates this for electromagnetic channels.
- **Csiszar-Korner (1978):** General broadcast channels with confidential messages. Our degradedness proof satisfies their condition.
- **Mathur et al. (2008):** Practical PLKG using channel reciprocity. Our work provides the first formal verification of such a protocol.
- **EasyCrypt / CryptoVerif:** Computational security proofs. Our work is information-theoretic, not computational.

---

### 7. Conclusion

The IEDP is a research program, not a single theorem. The MaxwellKey project demonstrates its viability in the simplest regime (quasi-static, 2-port, passive Eve). The monad hierarchy provides a roadmap for extending the principle to more complex electromagnetic environments. Each step up the hierarchy requires new mathematics and new formal proofs, but the structural duality between electromagnetics and information theory suggests that the program is sound.

The MaxwellKey artifact (1884 lines of Lean 4, 3968 build jobs, zero `sorry`) is the first concrete evidence that formal verification of physical-layer security is feasible and that the IEDP is more than a philosophical conjecture.

---

### References

1. MaxwellKey project — Lean 4 formalization. `MaxwellKey/` and `MaxwellKeyPLUS/`.
2. Loewner, K. "Uber monotone Matrixfunktionen." *Mathematische Zeitschrift*, 1934.
3. Wyner, A.D. "The wire-tap channel." *Bell System Technical Journal*, 1975.
4. Csiszar, I. and Korner, J. "Broadcast channels with confidential messages." *IEEE Trans. Info. Theory*, 1978.
5. Mathur, S. et al. "Radio-telepathy: extracting a secret key from an unauthenticated wireless channel." *MobiCom*, 2008.
6. Hammerstad, E. and Jensen, O. "Accurate models for microstrip computer-aided design." *IEEE MTT-S*, 1980.
7. Hassibi, B. and Hochwald, B. "How much training is needed in multiple-antenna wireless links?" *IEEE Trans. Info. Theory*, 2003.
