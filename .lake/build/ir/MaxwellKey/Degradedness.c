// Lean compiler output
// Module: MaxwellKey.Degradedness
// Imports: public import Init public meta import Init public import Mathlib.Data.Matrix.Basic public import Mathlib.Data.Real.Basic public import Mathlib.Tactic.Linarith public import Mathlib.Tactic.Ring public import Mathlib.Tactic.FieldSimp public import MaxwellKey.LoewnerOrder
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
extern lean_object* lp_mathlib_Real_definition_00___x40_Mathlib_Data_Real_Basic_1279875089____hygCtx___hyg_8_;
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lp_mathlib_Real_definition___lam__0_00___x40_Mathlib_Data_Real_Basic_4214226450____hygCtx___hyg_8_(lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* l_Rat_ofInt(lean_object*);
lean_object* lp_mathlib_Real_definition___lam__0_00___x40_Mathlib_Data_Real_Basic_1138242547____hygCtx___hyg_8_(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__3(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1(lean_object*);
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob___closed__0;
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5___redArg___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5___redArg___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0(lean_object* v_x_1_, lean_object* v_x_2_){
_start:
{
lean_object* v_zero_3_; uint8_t v_isZero_4_; 
v_zero_3_ = lean_unsigned_to_nat(0u);
v_isZero_4_ = lean_nat_dec_eq(v_x_1_, v_zero_3_);
if (v_isZero_4_ == 1)
{
lean_object* v___x_5_; 
lean_dec(v_x_2_);
v___x_5_ = lp_mathlib_Real_definition_00___x40_Mathlib_Data_Real_Basic_1279875089____hygCtx___hyg_8_;
return v___x_5_;
}
else
{
lean_object* v_one_6_; lean_object* v_n_7_; lean_object* v___x_8_; lean_object* v___f_9_; 
v_one_6_ = lean_unsigned_to_nat(1u);
v_n_7_ = lean_nat_sub(v_x_1_, v_one_6_);
lean_inc(v_x_2_);
v___x_8_ = lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0(v_n_7_, v_x_2_);
lean_dec(v_n_7_);
v___f_9_ = lean_alloc_closure((void*)(lp_mathlib_Real_definition___lam__0_00___x40_Mathlib_Data_Real_Basic_4214226450____hygCtx___hyg_8_), 3, 2);
lean_closure_set(v___f_9_, 0, v___x_8_);
lean_closure_set(v___f_9_, 1, v_x_2_);
return v___f_9_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0___boxed(lean_object* v_x_10_, lean_object* v_x_11_){
_start:
{
lean_object* v_res_12_; 
v_res_12_ = lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0(v_x_10_, v_x_11_);
lean_dec(v_x_10_);
return v_res_12_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__3(lean_object* v_a_13_){
_start:
{
lean_object* v___x_14_; lean_object* v___x_15_; 
v___x_14_ = lean_nat_to_int(v_a_13_);
v___x_15_ = l_Rat_ofInt(v___x_14_);
return v___x_15_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2___lam__0(lean_object* v___x_16_, lean_object* v_x_17_){
_start:
{
lean_inc_ref(v___x_16_);
return v___x_16_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2___lam__0___boxed(lean_object* v___x_18_, lean_object* v_x_19_){
_start:
{
lean_object* v_res_20_; 
v_res_20_ = lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2___lam__0(v___x_18_, v_x_19_);
lean_dec(v_x_19_);
lean_dec_ref(v___x_18_);
return v_res_20_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2(lean_object* v_a_21_){
_start:
{
lean_object* v___x_22_; lean_object* v___f_23_; 
v___x_22_ = lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__3(v_a_21_);
v___f_23_ = lean_alloc_closure((void*)(lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2___lam__0___boxed), 2, 1);
lean_closure_set(v___f_23_, 0, v___x_22_);
return v___f_23_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1(lean_object* v_a_24_){
_start:
{
lean_object* v___x_25_; 
v___x_25_ = lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2(v_a_24_);
return v___x_25_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1(lean_object* v_a_26_){
_start:
{
lean_object* v___x_27_; 
v___x_27_ = lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2(v_a_26_);
return v___x_27_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob___closed__0(void){
_start:
{
lean_object* v___x_28_; lean_object* v___x_29_; 
v___x_28_ = lean_unsigned_to_nat(2u);
v___x_29_ = lp_MaxwellKey_Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2(v___x_28_);
return v___x_29_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob(lean_object* v_p_30_, lean_object* v_i_31_, lean_object* v_j_32_){
_start:
{
lean_object* v___x_33_; uint8_t v___x_34_; 
v___x_33_ = lean_unsigned_to_nat(2u);
v___x_34_ = lean_nat_dec_eq(v_i_31_, v_j_32_);
if (v___x_34_ == 0)
{
lean_object* v_M__self_35_; lean_object* v_M__mutual_36_; lean_object* v_Z_u2080_37_; lean_object* v___x_38_; lean_object* v___x_39_; lean_object* v___f_40_; lean_object* v___f_41_; lean_object* v___f_42_; 
v_M__self_35_ = lean_ctor_get(v_p_30_, 0);
lean_inc(v_M__self_35_);
v_M__mutual_36_ = lean_ctor_get(v_p_30_, 1);
lean_inc(v_M__mutual_36_);
v_Z_u2080_37_ = lean_ctor_get(v_p_30_, 2);
lean_inc(v_Z_u2080_37_);
lean_dec_ref(v_p_30_);
v___x_38_ = lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0(v___x_33_, v_Z_u2080_37_);
v___x_39_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob___closed__0, &lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob___closed__0);
v___f_40_ = lean_alloc_closure((void*)(lp_mathlib_Real_definition___lam__0_00___x40_Mathlib_Data_Real_Basic_4214226450____hygCtx___hyg_8_), 3, 2);
lean_closure_set(v___f_40_, 0, v___x_39_);
lean_closure_set(v___f_40_, 1, v_M__self_35_);
v___f_41_ = lean_alloc_closure((void*)(lp_mathlib_Real_definition___lam__0_00___x40_Mathlib_Data_Real_Basic_4214226450____hygCtx___hyg_8_), 3, 2);
lean_closure_set(v___f_41_, 0, v___f_40_);
lean_closure_set(v___f_41_, 1, v_M__mutual_36_);
v___f_42_ = lean_alloc_closure((void*)(lp_mathlib_Real_definition___lam__0_00___x40_Mathlib_Data_Real_Basic_4214226450____hygCtx___hyg_8_), 3, 2);
lean_closure_set(v___f_42_, 0, v___x_38_);
lean_closure_set(v___f_42_, 1, v___f_41_);
return v___f_42_;
}
else
{
lean_object* v_M__self_43_; lean_object* v_M__mutual_44_; lean_object* v_Z_u2080_45_; lean_object* v___x_46_; lean_object* v___x_47_; lean_object* v___x_48_; lean_object* v___f_49_; lean_object* v___f_50_; 
v_M__self_43_ = lean_ctor_get(v_p_30_, 0);
lean_inc(v_M__self_43_);
v_M__mutual_44_ = lean_ctor_get(v_p_30_, 1);
lean_inc(v_M__mutual_44_);
v_Z_u2080_45_ = lean_ctor_get(v_p_30_, 2);
lean_inc(v_Z_u2080_45_);
lean_dec_ref(v_p_30_);
v___x_46_ = lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0(v___x_33_, v_Z_u2080_45_);
v___x_47_ = lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0(v___x_33_, v_M__self_43_);
v___x_48_ = lp_MaxwellKey_npowRec___at___00MaxwellKey_DegradednessParams_S__bob_spec__0(v___x_33_, v_M__mutual_44_);
v___f_49_ = lean_alloc_closure((void*)(lp_mathlib_Real_definition___lam__0_00___x40_Mathlib_Data_Real_Basic_1138242547____hygCtx___hyg_8_), 3, 2);
lean_closure_set(v___f_49_, 0, v___x_47_);
lean_closure_set(v___f_49_, 1, v___x_48_);
v___f_50_ = lean_alloc_closure((void*)(lp_mathlib_Real_definition___lam__0_00___x40_Mathlib_Data_Real_Basic_4214226450____hygCtx___hyg_8_), 3, 2);
lean_closure_set(v___f_50_, 0, v___x_46_);
lean_closure_set(v___f_50_, 1, v___f_49_);
return v___f_50_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob___boxed(lean_object* v_p_51_, lean_object* v_i_52_, lean_object* v_j_53_){
_start:
{
lean_object* v_res_54_; 
v_res_54_ = lp_MaxwellKey_MaxwellKey_DegradednessParams_S__bob(v_p_51_, v_i_52_, v_j_53_);
lean_dec(v_j_53_);
lean_dec(v_i_52_);
return v_res_54_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5___redArg___lam__0(lean_object* v_x_55_, lean_object* v_x_56_){
_start:
{
lean_inc_ref(v_x_55_);
return v_x_55_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5___redArg___lam__0___boxed(lean_object* v_x_57_, lean_object* v_x_58_){
_start:
{
lean_object* v_res_59_; 
v_res_59_ = lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5___redArg___lam__0(v_x_57_, v_x_58_);
lean_dec(v_x_58_);
lean_dec_ref(v_x_57_);
return v_res_59_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5___redArg(lean_object* v_x_60_){
_start:
{
lean_object* v___f_61_; 
v___f_61_ = lean_alloc_closure((void*)(lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5___redArg___lam__0___boxed), 2, 1);
lean_closure_set(v___f_61_, 0, v_x_60_);
return v___f_61_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5(lean_object* v_inst_62_, lean_object* v_inst_63_, lean_object* v_x_64_){
_start:
{
lean_object* v___f_65_; 
v___f_65_ = lean_alloc_closure((void*)(lp_MaxwellKey_CauSeq_const___at___00CauSeq_Completion_ofRat___at___00Real_definition_00___x40_Mathlib_Data_Real_Basic_1850581184____hygCtx___hyg_8__spec__2_spec__3___at___00Nat_cast___at___00Nat_cast___at___00Nat_cast___at___00MaxwellKey_DegradednessParams_S__bob_spec__1_spec__1_spec__2_spec__5___redArg___lam__0___boxed), 2, 1);
lean_closure_set(v___f_65_, 0, v_x_64_);
return v___f_65_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Matrix_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Real_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Linarith(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Ring(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_FieldSimp(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKey_LoewnerOrder(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_MaxwellKey_MaxwellKey_Degradedness(uint8_t builtin) {
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
res = initialize_MaxwellKey_MaxwellKey_LoewnerOrder(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
