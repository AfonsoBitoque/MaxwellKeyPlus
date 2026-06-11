// Lean compiler output
// Module: MaxwellKeyPLUS
// Imports: public import Init public meta import Init public import MaxwellKeyPLUS.Assumptions public import MaxwellKeyPLUS.DegradednessGeneral public import MaxwellKeyPLUS.ExactChannel public import MaxwellKeyPLUS.ExactChannelHermitian public import MaxwellKeyPLUS.SecrecyCapacityGeneral public import MaxwellKeyPLUS.VerifiedFirmware public import MaxwellKeyPLUS.VerifiedExtraction public import MaxwellKeyPLUS.Examples.TemplateRealParams public import MaxwellKeyPLUS.Examples.TwoParallelStripsComputable
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
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_Assumptions(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_ExactChannel(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_ExactChannelHermitian(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_SecrecyCapacityGeneral(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_VerifiedFirmware(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_VerifiedExtraction(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_Examples_TemplateRealParams(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_Examples_TwoParallelStripsComputable(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_MaxwellKey_MaxwellKeyPLUS(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_Assumptions(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_ExactChannel(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_ExactChannelHermitian(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_SecrecyCapacityGeneral(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_VerifiedFirmware(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_VerifiedExtraction(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_Examples_TemplateRealParams(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_Examples_TwoParallelStripsComputable(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
