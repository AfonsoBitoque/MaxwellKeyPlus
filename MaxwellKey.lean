-- Root of the `MaxwellKey` library.
-- For PROOFS and CITATIONS, use MaxwellKeyPLUS (min_f_sq).
-- The base MaxwellKey modules are legacy (f ≥ 3, conservative).
import MaxwellKey.AdmittanceMatrix
import MaxwellKey.ChannelMatrix
import MaxwellKey.LoewnerOrder

-- Generalized theorems (min_f_sq) — USE THESE for new work and citations
import MaxwellKeyPLUS.DegradednessGeneral
import MaxwellKeyPLUS.SecrecyCapacityGeneral
import MaxwellKeyPLUS.Assumptions
import MaxwellKeyPLUS.VerifiedFirmware

-- Examples and tests (use PLUS theorems)
import MaxwellKey.Examples.TwoParallelStrips
import MaxwellKey.Tests.SanityChecks
