-- This module serves as the root of the `MaxwellKey` library.
-- Import modules here that should be built as part of the library.
import MaxwellKey.AdmittanceMatrix
import MaxwellKey.ChannelMatrix
-- LEGACY (f ≥ 3): kept for backward compatibility; prefer DegradednessGeneral (min_f_sq)
import MaxwellKey.Degradedness
-- LEGACY (f ≥ 3): kept for backward compatibility; prefer SecrecyCapacityGeneral (min_f_sq)
import MaxwellKey.SecrecyCapacity
import MaxwellKey.Examples.TwoParallelStrips
import MaxwellKey.Tests.SanityChecks

-- Generalized theorems (min_f_sq) — RECOMMENDED for new work
import MaxwellKeyPLUS.DegradednessGeneral
import MaxwellKeyPLUS.SecrecyCapacityGeneral
