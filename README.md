# MaxwellKey: Formally Verified Physical-Layer Key Generation

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)]()
[![Lean 4](https://img.shields.io/badge/Lean-4.30-blue)]()
[![License](https://img.shields.io/badge/license-MIT-green)]()

**MaxwellKey** is a formally verified framework for physical-layer key generation based on electromagnetic reciprocity. The protocol exploits quasi-static near-field coupling between PCB traces to establish a shared secret key between two legitimate parties (Alice and Bob) that is information-theoretically secure against a passive eavesdropper (Eve).

All security proofs are machine-checked in the [Lean 4](https://lean-lang.org) theorem prover, providing cryptographic-grade assurance that the secrecy capacity is strictly positive under realistic physical assumptions.

> **Paper:** See [`paper/MaxwellKey_Paper.md`](paper/MaxwellKey_Paper.md) for the full conference-style article.  
> **Simulation Guide:** See [`docs/SimulationGuide.md`](docs/SimulationGuide.md) for COMSOL/OpenEMS instructions (Portuguese).  
> **Fallback Simulator:** See [`scripts/simulate_circuit.py`](scripts/simulate_circuit.py) for an analytical parameter estimator.

---

## What is MaxwellKey?

Physical-layer key generation leverages the reciprocal nature of electromagnetic wave propagation to establish shared secrets without public-key infrastructure. The MaxwellKey protocol uses the admittance matrix of coupled PCB traces as the source of common randomness.

**Key innovations:**
- **Machine-checked proofs** — every theorem is verified by Lean 4
- **Optimal degradation threshold** — `min_f_sq(M_self, M_mutual)` replaces the conservative `f ≥ 3`
- **Exact channel monotonicity** — the Loewner order is preserved under `f(A) = I - (I+A)⁻¹` (proved for real matrices; extension to physical Hermitian model completed in ExactChannelHermitian.lean)
- **Experimental pipeline** — from COMSOL/OpenEMS simulation → JSON parameters → Lean verification

---

## Quick Start

### Prerequisites

- [Lean 4](https://lean-lang.org/lean4/doc/quickstart.html) (v4.30.0)
- `lake` (build tool, included with Lean)
- Python 3.8+ (for fallback simulator)

### Build the Project

```bash
# Clone the repository
git clone https://github.com/predm/MaxwellKey.git
cd MaxwellKey

# Download mathlib dependencies and build everything
lake build
```

The build compiles ~4000 Lean jobs and should complete without errors in ~2 minutes on a modern machine.

### Run the Fallback Simulator

```bash
python3 scripts/simulate_circuit.py
# Generates scripts/params.json with estimated parameters
```

### Use COMSOL/OpenEMS Parameters

1. Follow [`docs/SimulationGuide.md`](docs/SimulationGuide.md) to extract `C_self`, `L_self`, `C_mutual`, `M_mutual`, `G`, `f_att`.
2. Fill in `scripts/params.json` with your measured values.
3. Open `MaxwellKeyPLUS/Examples/TemplateRealParams.lean` and paste the numeric values.
4. Run `lake build` to verify all physical hypotheses are satisfied.

---

## Repository Structure

```
MaxwellKey/
├── MaxwellKey/                     # Core formalization (original)
│   ├── AdmittanceMatrix.lean       # Quasi-static circuit model
│   ├── ChannelMatrix.lean          # Bob (2×2) and Eve (scalar) channels
│   ├── LoewnerOrder.lean           # Loewner order for 2×2 real matrices
│   ├── Degradedness.lean           # Original proof: f ≥ 3
│   ├── SecrecyCapacity.lean        # Secrecy capacity positivity theorem
│   ├── Extraction.lean             # Key generation protocol sketch
│   └── Examples/
│       └── TwoParallelStrips.lean    # Example PCB geometry
│
├── MaxwellKeyPLUS/                 # Extensions and generalizations
│   ├── Assumptions.lean            # Formal hypotheses manifesto
│   ├── DegradednessGeneral.lean    # Generalized proof with min_f_sq
│   ├── ExactChannel.lean           # Exact channel monotonicity (real matrices)
│   ├── ExactChannelHermitian.lean  # ECMT applied to physical Hermitian model
│   ├── SecrecyCapacityGeneral.lean # Secrecy capacity with min_f_sq
│   ├── VerifiedFirmware.lean       # Verified firmware (Float) + correctness proofs
│   ├── VerifiedExtraction.lean     # Formal C semantics + equivalence proof
│   ├── IEDP_sketch.md              # Informational Electromagnetic Duality Principle
│   └── Examples/
│       ├── TemplateRealParams.lean # Template for experimental parameters
│       └── TwoParallelStripsComputable.lean # Float-based computable example
│
├── docs/
│   ├── SimulationGuide.md          # COMSOL/OpenEMS guide (Portuguese)
│   ├── TestbedArchitecture.md      # Experimental testbed architecture
│   ├── ExperimentalGuide.md      # VNA/SDR measurement protocol
│   ├── AuditoriaFinal.md           # Internal audit reports
│   ├── ValidacaoFinal.md           # Validation checklist
│   └── VerifiedExtraction.md       # Verified code extraction (Lean → C) documentation
│
├── scripts/
│   ├── simulate_circuit.py         # Python fallback circuit simulator
│   ├── vna_capture.py              # VNA/SDR S-parameter capture
│   └── sparams_to_params.py        # Convert S-parameters → MaxwellKey params
│
├── build/
│   ├── key_generation.c            # Reference firmware (manual C translation)
│   ├── verified_main.c             # Verified firmware wrapper (Lean → C)
│   └── Makefile                    # Build pipeline for verified extraction
│
├── paper/
│   └── MaxwellKey_Paper.md         # Full conference paper
│
├── MaxwellKey.lean                 # Root module (core library)
├── MaxwellKeyPLUS.lean             # Root module (extensions)
├── lakefile.toml                   # Lean build configuration
└── README.md                       # This file
```

---

## Module Reference

| Module | Theorem / Definition | Description |
|--------|----------------------|-------------|
| `LoewnerOrder` | `Matrix.loewner_le` | Loewner partial order for 2×2 real matrices |
| `Degradedness` | `S_bob_ge_S_eve` | Original degradedness proof (f ≥ 3) |
| `SecrecyCapacity` | `secrecy_capacity_pos` | **Main theorem:** secrecy capacity > 0 |
| `DegradednessGeneral` | `min_f_sq` | Optimal degradation threshold |
| `DegradednessGeneral` | `S_bob_ge_S_eve` | Generalized degradedness (f² ≥ min_f_sq) |
| `ExactChannel` | `f_monotone_psd` | Exact channel monotonicity (real matrices only) |
| `ExactChannel` | `degradedness_exact` | ECMT applied to MaxwellKey context (preliminary) |
| `Extraction` | `generate_key_bob` | Key generation protocol sketch |
| `Assumptions` | `all_assumptions_satisfied` | Formal hypotheses manifesto |
| `ExactChannelHermitian` | `hermitian_to_real_form` | Physical Hermitian → real symmetric |
| `SecrecyCapacityGeneral` | `arg_bob_gt_arg_eve` | Secrecy capacity with min_f_sq |

---

## The 5 Main Theorems

1. **`channel_bob_symmetric`** — The channel matrix of Bob is symmetric due to electromagnetic reciprocity.
2. **`degradedness_loewner_general`** — Under weak coupling and `f² ≥ min_f_sq`, Bob's signal covariance dominates Eve's in the Loewner order.
3. **`f_monotone_psd`** — The exact channel transformation `f(A) = I - (I+A)⁻¹` preserves the Loewner order for real PSD matrices of the form `[[a,b],[b,a]]`. The extension to the physical Hermitian model is completed in `ExactChannelHermitian.lean`.
4. **`secrecy_capacity_pos`** — The secrecy capacity `C_s = C_bob - C_eve` is strictly positive, guaranteeing information-theoretic security.
5. **`min_f_sq_le_five`** — Under the weak coupling assumption `|M_mutual| < |M_self|/2`, the threshold `min_f_sq ≤ 5`, so `f ≥ 3` is always sufficient.

## Verified Code Extraction (Lean 4 → C)

**Problem:** The original `key_generation.c` was a **manual translation** of Lean proofs into C. Any human error in this translation (rounding error, buffer overflow, sign mistake) invalidates the formal proofs.

**Solution:** `VerifiedFirmware.lean` defines firmware operations in Lean 4 using `Float` (IEEE 754) and proves they preserve security properties. Functions are exported to C via `@[export]`. The Lean 4 compiler generates native code (via C IR) preserving semantics for pure functions.

```
Lean 4 (VerifiedFirmware.lean) -> lake build -> IR -> C -> gcc -> binary
```

**Key files:**
- `MaxwellKeyPLUS/VerifiedFirmware.lean` — Computable firmware + correctness proofs
- `MaxwellKeyPLUS/VerifiedExtraction.lean` — Formal C semantics + equivalence proof skeleton
- `build/verified_main.c` — Minimal C wrapper calling exported Lean functions
- `build/Makefile` — Automated build pipeline
- `docs/VerifiedExtraction.md` — Full documentation

See `docs/VerifiedExtraction.md` for comparison with HACL*, Everest, CompCert, and VST.

---

## Experimental Workflows

### Workflow A: Simulation (Fallback)

```
┌──────────────┐     ┌────────────────────┐     ┌─────────────────┐
│   COMSOL/    │────▶│  scripts/params.   │────▶│ TemplateReal-   │
│   OpenEMS    │     │  json              │     │ Params.lean     │
└──────────────┘     └────────────────────┘     └─────────────────┘
      │                                              │
      │  Extract: C_self, L_self,                    │  Paste values
      │  C_mutual, M_mutual, G, f_att                │  Run lake build
      │                                              ▼
      │                                       ┌─────────────────┐
      └──────────────────────────────────────▶│  Lean verifies  │
                                              │  all hypotheses │
                                              └─────────────────┘
```

1. **Simulate** the PCB geometry in COMSOL or OpenEMS (see [`docs/SimulationGuide.md`](docs/SimulationGuide.md)).
2. **Extract** parameters from the S/Y matrix at 100 MHz.
3. **Fill** `scripts/params.json` or directly edit `TemplateRealParams.lean`.
4. **Verify** with `lake build` — Lean checks `|M_mutual| < |M_self|/2`, `f² ≥ min_f_sq`, and all positivity constraints.

### Workflow B: Real Testbed (VNA / SDR)

```
┌──────────────┐     ┌──────────────┐     ┌──────────────┐     ┌─────────────────┐
│   PCB Real   │────▶│  VNA / SDR   │────▶│  scripts/    │────▶│ TemplateReal-   │
│  (2 pistas)  │     │  S-parameters│     │  sparams_to_ │     │ Params.lean     │
└──────────────┘     └──────────────┘     │  params.py   │     └─────────────────┘
                                           └──────────────┘              │
                                                                          │
                                                                          ▼
                                                                   ┌─────────────────┐
                                                                   │  Lean verifies  │
                                                                   │  all hypotheses │
                                                                   └─────────────────┘
```

1. **Build** the test PCB (see [`docs/TestbedArchitecture.md`](docs/TestbedArchitecture.md)).
2. **Measure** S-parameters with a VNA (NanoVNA, Keysight) or SDR (see [`docs/ExperimentalGuide.md`](docs/ExperimentalGuide.md)).
3. **Process** with `scripts/vna_capture.py` → `scripts/sparams_to_params.py` → `scripts/params.json`.
4. **Verify** with `lake build` — Lean checks the same hypotheses on **real measured data**.

**Key advantage:** Workflow B validates the formal model against empirical physics, closing the simulation-reality gap.

---

## Authors

- **Pedro** — Formal verification, Lean 4 proofs, theorem design
- **Carlos** — Physical model, circuit theory, Loewner order analysis
- **David** — Electromagnetic simulation, experimental validation, firmware (INOVATION)

---

## Citation

```bibtex
@inproceedings{maxwellkey2026,
  title={MaxwellKey: Formally Verified Physical-Layer Key Generation from Electromagnetic Reciprocity},
  author={Pedro and Carlos and David},
  booktitle={Proc. IEEE Int. Conf. on Formal Methods in Security},
  year={2026}
}
```

---

## License

MIT License — See repository for full text.

## Acknowledgments

This work is supported by INOVATION and builds on the Lean 4 theorem prover and the mathlib4 library. The Informational Electromagnetic Duality Principle (IEDP) was developed as part of this project.