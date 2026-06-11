// Lean compiler output
// Module: MaxwellKeyPLUS.ExactChannelHermitian
// Imports: public import Init public meta import Init public import Mathlib.Data.Matrix.Basic public import Mathlib.Data.Complex.Basic public import Mathlib.Data.Real.Basic public import Mathlib.Tactic.FinCases public import Mathlib.Tactic.Ring public import Mathlib.Tactic.FieldSimp public import Mathlib.Tactic.Positivity public import MaxwellKey.AdmittanceMatrix public import MaxwellKey.ChannelMatrix public import MaxwellKeyPLUS.ExactChannel
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
lean_object* lean_nat_sub(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter___redArg(lean_object* v_i_1_, lean_object* v_j_2_, lean_object* v_h__1_3_, lean_object* v_h__2_4_, lean_object* v_h__3_5_, lean_object* v_h__4_6_){
_start:
{
lean_object* v_zero_7_; uint8_t v_isZero_8_; 
v_zero_7_ = lean_unsigned_to_nat(0u);
v_isZero_8_ = lean_nat_dec_eq(v_i_1_, v_zero_7_);
if (v_isZero_8_ == 1)
{
uint8_t v_isZero_9_; 
lean_dec(v_h__4_6_);
lean_dec(v_h__3_5_);
v_isZero_9_ = lean_nat_dec_eq(v_j_2_, v_zero_7_);
if (v_isZero_9_ == 1)
{
lean_object* v___x_10_; lean_object* v___x_11_; 
lean_dec(v_h__2_4_);
v___x_10_ = lean_box(0);
v___x_11_ = lean_apply_1(v_h__1_3_, v___x_10_);
return v___x_11_;
}
else
{
lean_object* v_one_12_; lean_object* v_n_13_; uint8_t v_isZero_14_; lean_object* v___x_15_; lean_object* v___x_16_; 
lean_dec(v_h__1_3_);
v_one_12_ = lean_unsigned_to_nat(1u);
v_n_13_ = lean_nat_sub(v_j_2_, v_one_12_);
v_isZero_14_ = lean_nat_dec_eq(v_n_13_, v_zero_7_);
lean_dec(v_n_13_);
v___x_15_ = lean_box(0);
v___x_16_ = lean_apply_1(v_h__2_4_, v___x_15_);
return v___x_16_;
}
}
else
{
lean_object* v_one_17_; lean_object* v_n_18_; uint8_t v_isZero_19_; uint8_t v_isZero_20_; 
lean_dec(v_h__2_4_);
lean_dec(v_h__1_3_);
v_one_17_ = lean_unsigned_to_nat(1u);
v_n_18_ = lean_nat_sub(v_i_1_, v_one_17_);
v_isZero_19_ = lean_nat_dec_eq(v_n_18_, v_zero_7_);
lean_dec(v_n_18_);
v_isZero_20_ = lean_nat_dec_eq(v_j_2_, v_zero_7_);
if (v_isZero_20_ == 1)
{
lean_object* v___x_21_; lean_object* v___x_22_; 
lean_dec(v_h__4_6_);
v___x_21_ = lean_box(0);
v___x_22_ = lean_apply_1(v_h__3_5_, v___x_21_);
return v___x_22_;
}
else
{
lean_object* v_n_23_; uint8_t v_isZero_24_; lean_object* v___x_25_; lean_object* v___x_26_; 
lean_dec(v_h__3_5_);
v_n_23_ = lean_nat_sub(v_j_2_, v_one_17_);
v_isZero_24_ = lean_nat_dec_eq(v_n_23_, v_zero_7_);
lean_dec(v_n_23_);
v___x_25_ = lean_box(0);
v___x_26_ = lean_apply_1(v_h__4_6_, v___x_25_);
return v___x_26_;
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter___redArg___boxed(lean_object* v_i_27_, lean_object* v_j_28_, lean_object* v_h__1_29_, lean_object* v_h__2_30_, lean_object* v_h__3_31_, lean_object* v_h__4_32_){
_start:
{
lean_object* v_res_33_; 
v_res_33_ = lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter___redArg(v_i_27_, v_j_28_, v_h__1_29_, v_h__2_30_, v_h__3_31_, v_h__4_32_);
lean_dec(v_j_28_);
lean_dec(v_i_27_);
return v_res_33_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter(lean_object* v_motive_34_, lean_object* v_i_35_, lean_object* v_j_36_, lean_object* v_h__1_37_, lean_object* v_h__2_38_, lean_object* v_h__3_39_, lean_object* v_h__4_40_){
_start:
{
lean_object* v_zero_41_; uint8_t v_isZero_42_; 
v_zero_41_ = lean_unsigned_to_nat(0u);
v_isZero_42_ = lean_nat_dec_eq(v_i_35_, v_zero_41_);
if (v_isZero_42_ == 1)
{
uint8_t v_isZero_43_; 
lean_dec(v_h__4_40_);
lean_dec(v_h__3_39_);
v_isZero_43_ = lean_nat_dec_eq(v_j_36_, v_zero_41_);
if (v_isZero_43_ == 1)
{
lean_object* v___x_44_; lean_object* v___x_45_; 
lean_dec(v_h__2_38_);
v___x_44_ = lean_box(0);
v___x_45_ = lean_apply_1(v_h__1_37_, v___x_44_);
return v___x_45_;
}
else
{
lean_object* v_one_46_; lean_object* v_n_47_; uint8_t v_isZero_48_; lean_object* v___x_49_; lean_object* v___x_50_; 
lean_dec(v_h__1_37_);
v_one_46_ = lean_unsigned_to_nat(1u);
v_n_47_ = lean_nat_sub(v_j_36_, v_one_46_);
v_isZero_48_ = lean_nat_dec_eq(v_n_47_, v_zero_41_);
lean_dec(v_n_47_);
v___x_49_ = lean_box(0);
v___x_50_ = lean_apply_1(v_h__2_38_, v___x_49_);
return v___x_50_;
}
}
else
{
lean_object* v_one_51_; lean_object* v_n_52_; uint8_t v_isZero_53_; uint8_t v_isZero_54_; 
lean_dec(v_h__2_38_);
lean_dec(v_h__1_37_);
v_one_51_ = lean_unsigned_to_nat(1u);
v_n_52_ = lean_nat_sub(v_i_35_, v_one_51_);
v_isZero_53_ = lean_nat_dec_eq(v_n_52_, v_zero_41_);
lean_dec(v_n_52_);
v_isZero_54_ = lean_nat_dec_eq(v_j_36_, v_zero_41_);
if (v_isZero_54_ == 1)
{
lean_object* v___x_55_; lean_object* v___x_56_; 
lean_dec(v_h__4_40_);
v___x_55_ = lean_box(0);
v___x_56_ = lean_apply_1(v_h__3_39_, v___x_55_);
return v___x_56_;
}
else
{
lean_object* v_n_57_; uint8_t v_isZero_58_; lean_object* v___x_59_; lean_object* v___x_60_; 
lean_dec(v_h__3_39_);
v_n_57_ = lean_nat_sub(v_j_36_, v_one_51_);
v_isZero_58_ = lean_nat_dec_eq(v_n_57_, v_zero_41_);
lean_dec(v_n_57_);
v___x_59_ = lean_box(0);
v___x_60_ = lean_apply_1(v_h__4_40_, v___x_59_);
return v___x_60_;
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter___boxed(lean_object* v_motive_61_, lean_object* v_i_62_, lean_object* v_j_63_, lean_object* v_h__1_64_, lean_object* v_h__2_65_, lean_object* v_h__3_66_, lean_object* v_h__4_67_){
_start:
{
lean_object* v_res_68_; 
v_res_68_ = lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_QuasiStaticCircuit_admittance__matrix_match__1_splitter(v_motive_61_, v_i_62_, v_j_63_, v_h__1_64_, v_h__2_65_, v_h__3_66_, v_h__4_67_);
lean_dec(v_j_63_);
lean_dec(v_i_62_);
return v_res_68_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter___redArg(lean_object* v_i_69_, lean_object* v_j_70_, lean_object* v_h__1_71_, lean_object* v_h__2_72_, lean_object* v_h__3_73_, lean_object* v_h__4_74_){
_start:
{
lean_object* v_zero_75_; uint8_t v_isZero_76_; 
v_zero_75_ = lean_unsigned_to_nat(0u);
v_isZero_76_ = lean_nat_dec_eq(v_i_69_, v_zero_75_);
if (v_isZero_76_ == 1)
{
uint8_t v_isZero_77_; 
lean_dec(v_h__4_74_);
lean_dec(v_h__3_73_);
v_isZero_77_ = lean_nat_dec_eq(v_j_70_, v_zero_75_);
if (v_isZero_77_ == 1)
{
lean_object* v___x_78_; lean_object* v___x_79_; 
lean_dec(v_h__2_72_);
v___x_78_ = lean_box(0);
v___x_79_ = lean_apply_1(v_h__1_71_, v___x_78_);
return v___x_79_;
}
else
{
lean_object* v_one_80_; lean_object* v_n_81_; uint8_t v_isZero_82_; lean_object* v___x_83_; lean_object* v___x_84_; 
lean_dec(v_h__1_71_);
v_one_80_ = lean_unsigned_to_nat(1u);
v_n_81_ = lean_nat_sub(v_j_70_, v_one_80_);
v_isZero_82_ = lean_nat_dec_eq(v_n_81_, v_zero_75_);
lean_dec(v_n_81_);
v___x_83_ = lean_box(0);
v___x_84_ = lean_apply_1(v_h__2_72_, v___x_83_);
return v___x_84_;
}
}
else
{
lean_object* v_one_85_; lean_object* v_n_86_; uint8_t v_isZero_87_; uint8_t v_isZero_88_; 
lean_dec(v_h__2_72_);
lean_dec(v_h__1_71_);
v_one_85_ = lean_unsigned_to_nat(1u);
v_n_86_ = lean_nat_sub(v_i_69_, v_one_85_);
v_isZero_87_ = lean_nat_dec_eq(v_n_86_, v_zero_75_);
lean_dec(v_n_86_);
v_isZero_88_ = lean_nat_dec_eq(v_j_70_, v_zero_75_);
if (v_isZero_88_ == 1)
{
lean_object* v___x_89_; lean_object* v___x_90_; 
lean_dec(v_h__4_74_);
v___x_89_ = lean_box(0);
v___x_90_ = lean_apply_1(v_h__3_73_, v___x_89_);
return v___x_90_;
}
else
{
lean_object* v_n_91_; uint8_t v_isZero_92_; lean_object* v___x_93_; lean_object* v___x_94_; 
lean_dec(v_h__3_73_);
v_n_91_ = lean_nat_sub(v_j_70_, v_one_85_);
v_isZero_92_ = lean_nat_dec_eq(v_n_91_, v_zero_75_);
lean_dec(v_n_91_);
v___x_93_ = lean_box(0);
v___x_94_ = lean_apply_1(v_h__4_74_, v___x_93_);
return v___x_94_;
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter___redArg___boxed(lean_object* v_i_95_, lean_object* v_j_96_, lean_object* v_h__1_97_, lean_object* v_h__2_98_, lean_object* v_h__3_99_, lean_object* v_h__4_100_){
_start:
{
lean_object* v_res_101_; 
v_res_101_ = lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter___redArg(v_i_95_, v_j_96_, v_h__1_97_, v_h__2_98_, v_h__3_99_, v_h__4_100_);
lean_dec(v_j_96_);
lean_dec(v_i_95_);
return v_res_101_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter(lean_object* v_motive_102_, lean_object* v_i_103_, lean_object* v_j_104_, lean_object* v_h__1_105_, lean_object* v_h__2_106_, lean_object* v_h__3_107_, lean_object* v_h__4_108_){
_start:
{
lean_object* v_zero_109_; uint8_t v_isZero_110_; 
v_zero_109_ = lean_unsigned_to_nat(0u);
v_isZero_110_ = lean_nat_dec_eq(v_i_103_, v_zero_109_);
if (v_isZero_110_ == 1)
{
uint8_t v_isZero_111_; 
lean_dec(v_h__4_108_);
lean_dec(v_h__3_107_);
v_isZero_111_ = lean_nat_dec_eq(v_j_104_, v_zero_109_);
if (v_isZero_111_ == 1)
{
lean_object* v___x_112_; lean_object* v___x_113_; 
lean_dec(v_h__2_106_);
v___x_112_ = lean_box(0);
v___x_113_ = lean_apply_1(v_h__1_105_, v___x_112_);
return v___x_113_;
}
else
{
lean_object* v_one_114_; lean_object* v_n_115_; uint8_t v_isZero_116_; lean_object* v___x_117_; lean_object* v___x_118_; 
lean_dec(v_h__1_105_);
v_one_114_ = lean_unsigned_to_nat(1u);
v_n_115_ = lean_nat_sub(v_j_104_, v_one_114_);
v_isZero_116_ = lean_nat_dec_eq(v_n_115_, v_zero_109_);
lean_dec(v_n_115_);
v___x_117_ = lean_box(0);
v___x_118_ = lean_apply_1(v_h__2_106_, v___x_117_);
return v___x_118_;
}
}
else
{
lean_object* v_one_119_; lean_object* v_n_120_; uint8_t v_isZero_121_; uint8_t v_isZero_122_; 
lean_dec(v_h__2_106_);
lean_dec(v_h__1_105_);
v_one_119_ = lean_unsigned_to_nat(1u);
v_n_120_ = lean_nat_sub(v_i_103_, v_one_119_);
v_isZero_121_ = lean_nat_dec_eq(v_n_120_, v_zero_109_);
lean_dec(v_n_120_);
v_isZero_122_ = lean_nat_dec_eq(v_j_104_, v_zero_109_);
if (v_isZero_122_ == 1)
{
lean_object* v___x_123_; lean_object* v___x_124_; 
lean_dec(v_h__4_108_);
v___x_123_ = lean_box(0);
v___x_124_ = lean_apply_1(v_h__3_107_, v___x_123_);
return v___x_124_;
}
else
{
lean_object* v_n_125_; uint8_t v_isZero_126_; lean_object* v___x_127_; lean_object* v___x_128_; 
lean_dec(v_h__3_107_);
v_n_125_ = lean_nat_sub(v_j_104_, v_one_119_);
v_isZero_126_ = lean_nat_dec_eq(v_n_125_, v_zero_109_);
lean_dec(v_n_125_);
v___x_127_ = lean_box(0);
v___x_128_ = lean_apply_1(v_h__4_108_, v___x_127_);
return v___x_128_;
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter___boxed(lean_object* v_motive_129_, lean_object* v_i_130_, lean_object* v_j_131_, lean_object* v_h__1_132_, lean_object* v_h__2_133_, lean_object* v_h__3_134_, lean_object* v_h__4_135_){
_start:
{
lean_object* v_res_136_; 
v_res_136_ = lp_MaxwellKey___private_MaxwellKeyPLUS_ExactChannelHermitian_0__MaxwellKey_ExactChannelHermitian_B__matrix_match__1_splitter(v_motive_129_, v_i_130_, v_j_131_, v_h__1_132_, v_h__2_133_, v_h__3_134_, v_h__4_135_);
lean_dec(v_j_131_);
lean_dec(v_i_130_);
return v_res_136_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Matrix_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Complex_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Real_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_FinCases(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Ring(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_FieldSimp(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Positivity(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKey_AdmittanceMatrix(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKey_ChannelMatrix(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_ExactChannel(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_ExactChannelHermitian(uint8_t builtin) {
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
res = initialize_mathlib_Mathlib_Data_Complex_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Data_Real_Basic(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_mathlib_Mathlib_Tactic_FinCases(builtin);
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
res = initialize_MaxwellKey_MaxwellKey_AdmittanceMatrix(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKey_ChannelMatrix(builtin);
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
