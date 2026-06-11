// Lean compiler output
// Module: MaxwellKeyPLUS.ExactChannel
// Imports: public import Init public meta import Init public import Mathlib.Data.Matrix.Basic public import Mathlib.Data.Real.Basic public import Mathlib.Tactic.Linarith public import Mathlib.Tactic.Ring public import Mathlib.Tactic.FieldSimp public import Mathlib.Tactic.Positivity public import Mathlib.Tactic.FinCases public import MaxwellKey.LoewnerOrder public import MaxwellKeyPLUS.DegradednessGeneral
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
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_ExactChannel_symm__matrix(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_ExactChannel_symm__matrix___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_ExactChannel_symm__matrix(lean_object* v_a_1_, lean_object* v_b_2_, lean_object* v_i_3_, lean_object* v_j_4_){
_start:
{
uint8_t v___x_5_; 
v___x_5_ = lean_nat_dec_eq(v_i_3_, v_j_4_);
if (v___x_5_ == 0)
{
lean_inc(v_b_2_);
return v_b_2_;
}
else
{
lean_inc(v_a_1_);
return v_a_1_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_ExactChannel_symm__matrix___boxed(lean_object* v_a_6_, lean_object* v_b_7_, lean_object* v_i_8_, lean_object* v_j_9_){
_start:
{
lean_object* v_res_10_; 
v_res_10_ = lp_MaxwellKey_MaxwellKey_ExactChannel_symm__matrix(v_a_6_, v_b_7_, v_i_8_, v_j_9_);
lean_dec(v_j_9_);
lean_dec(v_i_8_);
lean_dec(v_b_7_);
lean_dec(v_a_6_);
return v_res_10_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Matrix_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Real_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Linarith(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Ring(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_FieldSimp(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Positivity(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_FinCases(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKey_LoewnerOrder(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_ExactChannel(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_Matrix_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_Real_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Tactic_Linarith(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Tactic_Ring(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Tactic_FieldSimp(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Tactic_Positivity(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Tactic_FinCases(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKey_LoewnerOrder(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
