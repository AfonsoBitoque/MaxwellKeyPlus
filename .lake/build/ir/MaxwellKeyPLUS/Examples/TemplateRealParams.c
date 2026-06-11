// Lean compiler output
// Module: MaxwellKeyPLUS.Examples.TemplateRealParams
// Imports: public import Init public meta import Init public import Mathlib.Data.Real.Basic public import Mathlib.Data.Complex.Basic public import MaxwellKeyPLUS.DegradednessGeneral public import MaxwellKeyPLUS.SecrecyCapacityGeneral public import MaxwellKeyPLUS.ExactChannel
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
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_TemplateRealParams_create__params___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_TemplateRealParams_create__params(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_TemplateRealParams_params__from__json___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_TemplateRealParams_params__from__json(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_TemplateRealParams_create__params___redArg(lean_object* v_M__self_1_, lean_object* v_M__mutual_2_, lean_object* v_Z_u2080_3_, lean_object* v_f_4_){
_start:
{
lean_object* v___x_5_; 
v___x_5_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_5_, 0, v_M__self_1_);
lean_ctor_set(v___x_5_, 1, v_M__mutual_2_);
lean_ctor_set(v___x_5_, 2, v_Z_u2080_3_);
lean_ctor_set(v___x_5_, 3, v_f_4_);
return v___x_5_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_TemplateRealParams_create__params(lean_object* v_M__self_6_, lean_object* v_M__mutual_7_, lean_object* v_Z_u2080_8_, lean_object* v_f_9_, lean_object* v_h__Z_u2080__pos_10_, lean_object* v_h__weak_11_, lean_object* v_h__M__self__pos_12_, lean_object* v_h__f__sq__ge__min_13_){
_start:
{
lean_object* v___x_14_; 
v___x_14_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_14_, 0, v_M__self_6_);
lean_ctor_set(v___x_14_, 1, v_M__mutual_7_);
lean_ctor_set(v___x_14_, 2, v_Z_u2080_8_);
lean_ctor_set(v___x_14_, 3, v_f_9_);
return v___x_14_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_TemplateRealParams_params__from__json___redArg(lean_object* v_M__self_15_, lean_object* v_M__mutual_16_, lean_object* v_Z_u2080_17_, lean_object* v_f_18_){
_start:
{
lean_object* v___x_19_; 
v___x_19_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_19_, 0, v_M__self_15_);
lean_ctor_set(v___x_19_, 1, v_M__mutual_16_);
lean_ctor_set(v___x_19_, 2, v_Z_u2080_17_);
lean_ctor_set(v___x_19_, 3, v_f_18_);
return v___x_19_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_TemplateRealParams_params__from__json(lean_object* v_M__self_20_, lean_object* v_M__mutual_21_, lean_object* v_Z_u2080_22_, lean_object* v_f_23_, lean_object* v_h__Z_u2080__pos_24_, lean_object* v_h__weak_25_, lean_object* v_h__M__self__pos_26_, lean_object* v_h__f__sq__ge__min_27_){
_start:
{
lean_object* v___x_28_; 
v___x_28_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_28_, 0, v_M__self_20_);
lean_ctor_set(v___x_28_, 1, v_M__mutual_21_);
lean_ctor_set(v___x_28_, 2, v_Z_u2080_22_);
lean_ctor_set(v___x_28_, 3, v_f_23_);
return v___x_28_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Real_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Complex_Basic(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_SecrecyCapacityGeneral(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_ExactChannel(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_Examples_TemplateRealParams(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_Real_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_Complex_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_SecrecyCapacityGeneral(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_ExactChannel(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
