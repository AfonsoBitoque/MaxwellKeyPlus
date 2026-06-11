// Lean compiler output
// Module: MaxwellKey
// Imports: public import Init public meta import Init public import MaxwellKey.AdmittanceMatrix public import MaxwellKey.ChannelMatrix public import MaxwellKey.LoewnerOrder public import MaxwellKeyPLUS.DegradednessGeneral public import MaxwellKeyPLUS.SecrecyCapacityGeneral public import MaxwellKeyPLUS.Assumptions public import MaxwellKeyPLUS.VerifiedFirmware public import MaxwellKey.Examples.TwoParallelStrips public import MaxwellKey.Tests.SanityChecks
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKey_AdmittanceMatrix(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKey_ChannelMatrix(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKey_LoewnerOrder(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_SecrecyCapacityGeneral(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_Assumptions(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_VerifiedFirmware(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKey_Examples_TwoParallelStrips(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKey_Tests_SanityChecks(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_MaxwellKey_MaxwellKey(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKey_AdmittanceMatrix(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKey_ChannelMatrix(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKey_LoewnerOrder(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_SecrecyCapacityGeneral(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_Assumptions(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_VerifiedFirmware(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKey_Examples_TwoParallelStrips(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKey_Tests_SanityChecks(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
