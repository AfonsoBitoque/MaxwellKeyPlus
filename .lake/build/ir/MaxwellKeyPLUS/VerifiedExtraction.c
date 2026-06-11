// Lean compiler output
// Module: MaxwellKeyPLUS.VerifiedExtraction
// Imports: public import Init public meta import Init public import Mathlib.Data.Real.Basic public import Mathlib.Tactic.Ring
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
double l_Float_ofScientific(lean_object*, uint8_t, lean_object*);
lean_object* l_Lean_Name_mkStr3(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr4(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_Lean_Syntax_isOfKind(lean_object*, lean_object*);
lean_object* l_Lean_Syntax_getArg(lean_object*, lean_object*);
lean_object* l_Lean_Name_mkStr1(lean_object*);
uint8_t l_Lean_Syntax_matchesNull(lean_object*, lean_object*);
lean_object* l_Lean_replaceRef(lean_object*, lean_object*);
lean_object* l_Lean_SourceInfo_fromRef(lean_object*, uint8_t);
lean_object* l_Lean_Syntax_node6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* l_String_toRawSubstring_x27(lean_object*);
lean_object* l_Lean_addMacroScope(lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Syntax_node3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Lean_Syntax_node2(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Float_repr(double, lean_object*);
lean_object* l_Repr_addAppParen(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
double lean_float_add(double, double);
double lean_float_sub(double, double);
double lean_float_mul(double, double);
double lean_float_div(double, double);
uint8_t lean_float_beq(double, double);
uint8_t lean_float_decLt(double, double);
uint8_t lean_float_decLe(double, double);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CVar_mk(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CVar_mk___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_lit_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_lit_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_var_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_var_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_add_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_add_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_sub_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_sub_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_mul_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_mul_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_div_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_div_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_eq_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_eq_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_lt_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_lt_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_gt_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_gt_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_le_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_le_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ge_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ge_elim(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.lit"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__0 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__0_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__0_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__1 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__1_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__1_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__2 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__2_value;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.var"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__5 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__5_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__5_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__6 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__6_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__6_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__7 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__7_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.add"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__8 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__8_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__8_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__9 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__9_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__9_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__10 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__10_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.sub"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__11 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__11_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__11_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__12 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__12_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__12_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__13 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__13_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.mul"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__14 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__14_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__14_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__15 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__15_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__15_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__16 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__16_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.div"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__17 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__17_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__17_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__18 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__18_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__18_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__19 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__19_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 39, .m_capacity = 39, .m_length = 38, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.eq"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__20 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__20_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__20_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__21 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__21_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__21_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__22 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__22_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 39, .m_capacity = 39, .m_length = 38, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.lt"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__23 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__23_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__23_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__24 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__24_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__24_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__25 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__25_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 39, .m_capacity = 39, .m_length = 38, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.gt"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__26 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__26_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__26_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__27 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__27_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__27_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__28 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__28_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 39, .m_capacity = 39, .m_length = 38, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.le"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__29 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__29_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__29_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__30 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__30_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__31_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__30_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__31 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__31_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__32_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 39, .m_capacity = 39, .m_length = 38, .m_data = "MaxwellKey.VerifiedExtraction.CExpr.ge"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__32 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__32_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__33_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__32_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__33 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__33_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__34_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__33_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__34 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__34_value;
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr___closed__0 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr___closed__0_value;
LEAN_EXPORT const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr___closed__0_value;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0;
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___boxed(lean_object*);
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_env__update(lean_object*, lean_object*, double, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_env__update___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "MaxwellKey"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__0 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__0_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "VerifiedExtraction"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__1 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__1_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 10, .m_data = "term_[_↦_]"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__2 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__2_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__0_value),LEAN_SCALAR_PTR_LITERAL(165, 166, 112, 216, 253, 22, 190, 83)}};
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3_value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3_value_aux_0),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__1_value),LEAN_SCALAR_PTR_LITERAL(186, 20, 10, 184, 164, 191, 174, 89)}};
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3_value_aux_1),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__2_value),LEAN_SCALAR_PTR_LITERAL(237, 72, 87, 55, 23, 50, 7, 248)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "andthen"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__4 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__4_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__4_value),LEAN_SCALAR_PTR_LITERAL(40, 255, 78, 30, 143, 119, 117, 174)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__5 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__5_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "["};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__6 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__6_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__6_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__7 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__7_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "term"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__8 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__8_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__8_value),LEAN_SCALAR_PTR_LITERAL(187, 230, 181, 162, 253, 146, 122, 119)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__9 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__9_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 7}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__9_value),((lean_object*)(((size_t)(90) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__10 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__10_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__5_value),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__7_value),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__10_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__11 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__11_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 3, .m_data = " ↦ "};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__12 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__12_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__12_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__13 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__13_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__5_value),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__11_value),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__13_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__14 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__14_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__5_value),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__14_value),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__10_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__15 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__15_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "]"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__16 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__16_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__16_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__17 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__17_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 2}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__5_value),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__15_value),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__17_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__18 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__18_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*4 + 0, .m_other = 4, .m_tag = 4}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3_value),((lean_object*)(((size_t)(90) << 1) | 1)),((lean_object*)(((size_t)(90) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__18_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__19 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__19_value;
LEAN_EXPORT const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__19_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Lean"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__0 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__0_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "Parser"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__1 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__1_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "Term"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__2 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__2_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "app"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__3 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__3_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__0_value),LEAN_SCALAR_PTR_LITERAL(70, 193, 83, 126, 233, 67, 208, 165)}};
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4_value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4_value_aux_0),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__1_value),LEAN_SCALAR_PTR_LITERAL(103, 136, 125, 166, 167, 98, 71, 111)}};
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4_value_aux_2 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4_value_aux_1),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__2_value),LEAN_SCALAR_PTR_LITERAL(75, 170, 162, 138, 136, 204, 251, 229)}};
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4_value_aux_2),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__3_value),LEAN_SCALAR_PTR_LITERAL(69, 118, 10, 41, 220, 156, 243, 179)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "env_update"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__5 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__5_value;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__6_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__6;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__5_value),LEAN_SCALAR_PTR_LITERAL(162, 101, 217, 20, 209, 175, 145, 170)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__7 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__7_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__8_value_aux_0 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__0_value),LEAN_SCALAR_PTR_LITERAL(165, 166, 112, 216, 253, 22, 190, 83)}};
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__8_value_aux_1 = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__8_value_aux_0),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__1_value),LEAN_SCALAR_PTR_LITERAL(186, 20, 10, 184, 164, 191, 174, 89)}};
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__8_value_aux_1),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__5_value),LEAN_SCALAR_PTR_LITERAL(55, 213, 188, 159, 87, 129, 202, 205)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__8 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__8_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__8_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__9 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__9_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__9_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__10 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__10_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "null"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__11 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__11_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__11_value),LEAN_SCALAR_PTR_LITERAL(24, 58, 49, 223, 146, 207, 197, 136)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__12 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__12_value;
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "ident"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___closed__0 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___closed__0_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 8, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___closed__0_value),LEAN_SCALAR_PTR_LITERAL(52, 159, 208, 51, 14, 60, 6, 71)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___closed__1 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___closed__1_value;
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___boxed(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___closed__0;
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_alpha__c(lean_object*, lean_object*);
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__0;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__1;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__2;
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__eve__c(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_firmware__env(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_firmware__env___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CVar_mk(lean_object* v_n_1_){
_start:
{
lean_inc(v_n_1_);
return v_n_1_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CVar_mk___boxed(lean_object* v_n_2_){
_start:
{
lean_object* v_res_3_; 
v_res_3_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CVar_mk(v_n_2_);
lean_dec(v_n_2_);
return v_res_3_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorIdx(lean_object* v_x_4_){
_start:
{
switch(lean_obj_tag(v_x_4_))
{
case 0:
{
lean_object* v___x_5_; 
v___x_5_ = lean_unsigned_to_nat(0u);
return v___x_5_;
}
case 1:
{
lean_object* v___x_6_; 
v___x_6_ = lean_unsigned_to_nat(1u);
return v___x_6_;
}
case 2:
{
lean_object* v___x_7_; 
v___x_7_ = lean_unsigned_to_nat(2u);
return v___x_7_;
}
case 3:
{
lean_object* v___x_8_; 
v___x_8_ = lean_unsigned_to_nat(3u);
return v___x_8_;
}
case 4:
{
lean_object* v___x_9_; 
v___x_9_ = lean_unsigned_to_nat(4u);
return v___x_9_;
}
case 5:
{
lean_object* v___x_10_; 
v___x_10_ = lean_unsigned_to_nat(5u);
return v___x_10_;
}
case 6:
{
lean_object* v___x_11_; 
v___x_11_ = lean_unsigned_to_nat(6u);
return v___x_11_;
}
case 7:
{
lean_object* v___x_12_; 
v___x_12_ = lean_unsigned_to_nat(7u);
return v___x_12_;
}
case 8:
{
lean_object* v___x_13_; 
v___x_13_ = lean_unsigned_to_nat(8u);
return v___x_13_;
}
case 9:
{
lean_object* v___x_14_; 
v___x_14_ = lean_unsigned_to_nat(9u);
return v___x_14_;
}
default: 
{
lean_object* v___x_15_; 
v___x_15_ = lean_unsigned_to_nat(10u);
return v___x_15_;
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorIdx___boxed(lean_object* v_x_16_){
_start:
{
lean_object* v_res_17_; 
v_res_17_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorIdx(v_x_16_);
lean_dec_ref(v_x_16_);
return v_res_17_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(lean_object* v_t_18_, lean_object* v_k_19_){
_start:
{
switch(lean_obj_tag(v_t_18_))
{
case 0:
{
double v_v_20_; lean_object* v___x_21_; lean_object* v___x_22_; 
v_v_20_ = lean_ctor_get_float(v_t_18_, 0);
lean_dec_ref_known(v_t_18_, 0);
v___x_21_ = lean_box_float(v_v_20_);
v___x_22_ = lean_apply_1(v_k_19_, v___x_21_);
return v___x_22_;
}
case 1:
{
lean_object* v_x_23_; lean_object* v___x_24_; 
v_x_23_ = lean_ctor_get(v_t_18_, 0);
lean_inc(v_x_23_);
lean_dec_ref_known(v_t_18_, 1);
v___x_24_ = lean_apply_1(v_k_19_, v_x_23_);
return v___x_24_;
}
default: 
{
lean_object* v_e1_25_; lean_object* v_e2_26_; lean_object* v___x_27_; 
v_e1_25_ = lean_ctor_get(v_t_18_, 0);
lean_inc_ref(v_e1_25_);
v_e2_26_ = lean_ctor_get(v_t_18_, 1);
lean_inc_ref(v_e2_26_);
lean_dec_ref(v_t_18_);
v___x_27_ = lean_apply_2(v_k_19_, v_e1_25_, v_e2_26_);
return v___x_27_;
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim(lean_object* v_motive_28_, lean_object* v_ctorIdx_29_, lean_object* v_t_30_, lean_object* v_h_31_, lean_object* v_k_32_){
_start:
{
lean_object* v___x_33_; 
v___x_33_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_30_, v_k_32_);
return v___x_33_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___boxed(lean_object* v_motive_34_, lean_object* v_ctorIdx_35_, lean_object* v_t_36_, lean_object* v_h_37_, lean_object* v_k_38_){
_start:
{
lean_object* v_res_39_; 
v_res_39_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim(v_motive_34_, v_ctorIdx_35_, v_t_36_, v_h_37_, v_k_38_);
lean_dec(v_ctorIdx_35_);
return v_res_39_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_lit_elim___redArg(lean_object* v_t_40_, lean_object* v_lit_41_){
_start:
{
lean_object* v___x_42_; 
v___x_42_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_40_, v_lit_41_);
return v___x_42_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_lit_elim(lean_object* v_motive_43_, lean_object* v_t_44_, lean_object* v_h_45_, lean_object* v_lit_46_){
_start:
{
lean_object* v___x_47_; 
v___x_47_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_44_, v_lit_46_);
return v___x_47_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_var_elim___redArg(lean_object* v_t_48_, lean_object* v_var_49_){
_start:
{
lean_object* v___x_50_; 
v___x_50_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_48_, v_var_49_);
return v___x_50_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_var_elim(lean_object* v_motive_51_, lean_object* v_t_52_, lean_object* v_h_53_, lean_object* v_var_54_){
_start:
{
lean_object* v___x_55_; 
v___x_55_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_52_, v_var_54_);
return v___x_55_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_add_elim___redArg(lean_object* v_t_56_, lean_object* v_add_57_){
_start:
{
lean_object* v___x_58_; 
v___x_58_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_56_, v_add_57_);
return v___x_58_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_add_elim(lean_object* v_motive_59_, lean_object* v_t_60_, lean_object* v_h_61_, lean_object* v_add_62_){
_start:
{
lean_object* v___x_63_; 
v___x_63_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_60_, v_add_62_);
return v___x_63_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_sub_elim___redArg(lean_object* v_t_64_, lean_object* v_sub_65_){
_start:
{
lean_object* v___x_66_; 
v___x_66_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_64_, v_sub_65_);
return v___x_66_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_sub_elim(lean_object* v_motive_67_, lean_object* v_t_68_, lean_object* v_h_69_, lean_object* v_sub_70_){
_start:
{
lean_object* v___x_71_; 
v___x_71_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_68_, v_sub_70_);
return v___x_71_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_mul_elim___redArg(lean_object* v_t_72_, lean_object* v_mul_73_){
_start:
{
lean_object* v___x_74_; 
v___x_74_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_72_, v_mul_73_);
return v___x_74_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_mul_elim(lean_object* v_motive_75_, lean_object* v_t_76_, lean_object* v_h_77_, lean_object* v_mul_78_){
_start:
{
lean_object* v___x_79_; 
v___x_79_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_76_, v_mul_78_);
return v___x_79_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_div_elim___redArg(lean_object* v_t_80_, lean_object* v_div_81_){
_start:
{
lean_object* v___x_82_; 
v___x_82_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_80_, v_div_81_);
return v___x_82_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_div_elim(lean_object* v_motive_83_, lean_object* v_t_84_, lean_object* v_h_85_, lean_object* v_div_86_){
_start:
{
lean_object* v___x_87_; 
v___x_87_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_84_, v_div_86_);
return v___x_87_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_eq_elim___redArg(lean_object* v_t_88_, lean_object* v_eq_89_){
_start:
{
lean_object* v___x_90_; 
v___x_90_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_88_, v_eq_89_);
return v___x_90_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_eq_elim(lean_object* v_motive_91_, lean_object* v_t_92_, lean_object* v_h_93_, lean_object* v_eq_94_){
_start:
{
lean_object* v___x_95_; 
v___x_95_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_92_, v_eq_94_);
return v___x_95_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_lt_elim___redArg(lean_object* v_t_96_, lean_object* v_lt_97_){
_start:
{
lean_object* v___x_98_; 
v___x_98_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_96_, v_lt_97_);
return v___x_98_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_lt_elim(lean_object* v_motive_99_, lean_object* v_t_100_, lean_object* v_h_101_, lean_object* v_lt_102_){
_start:
{
lean_object* v___x_103_; 
v___x_103_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_100_, v_lt_102_);
return v___x_103_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_gt_elim___redArg(lean_object* v_t_104_, lean_object* v_gt_105_){
_start:
{
lean_object* v___x_106_; 
v___x_106_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_104_, v_gt_105_);
return v___x_106_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_gt_elim(lean_object* v_motive_107_, lean_object* v_t_108_, lean_object* v_h_109_, lean_object* v_gt_110_){
_start:
{
lean_object* v___x_111_; 
v___x_111_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_108_, v_gt_110_);
return v___x_111_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_le_elim___redArg(lean_object* v_t_112_, lean_object* v_le_113_){
_start:
{
lean_object* v___x_114_; 
v___x_114_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_112_, v_le_113_);
return v___x_114_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_le_elim(lean_object* v_motive_115_, lean_object* v_t_116_, lean_object* v_h_117_, lean_object* v_le_118_){
_start:
{
lean_object* v___x_119_; 
v___x_119_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_116_, v_le_118_);
return v___x_119_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ge_elim___redArg(lean_object* v_t_120_, lean_object* v_ge_121_){
_start:
{
lean_object* v___x_122_; 
v___x_122_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_120_, v_ge_121_);
return v___x_122_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ge_elim(lean_object* v_motive_123_, lean_object* v_t_124_, lean_object* v_h_125_, lean_object* v_ge_126_){
_start:
{
lean_object* v___x_127_; 
v___x_127_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_CExpr_ctorElim___redArg(v_t_124_, v_ge_126_);
return v___x_127_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3(void){
_start:
{
lean_object* v___x_134_; lean_object* v___x_135_; 
v___x_134_ = lean_unsigned_to_nat(2u);
v___x_135_ = lean_nat_to_int(v___x_134_);
return v___x_135_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4(void){
_start:
{
lean_object* v___x_136_; lean_object* v___x_137_; 
v___x_136_ = lean_unsigned_to_nat(1u);
v___x_137_ = lean_nat_to_int(v___x_136_);
return v___x_137_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(lean_object* v_x_198_, lean_object* v_prec_199_){
_start:
{
switch(lean_obj_tag(v_x_198_))
{
case 0:
{
double v_v_200_; lean_object* v___y_202_; lean_object* v___x_211_; uint8_t v___x_212_; 
v_v_200_ = lean_ctor_get_float(v_x_198_, 0);
lean_dec_ref_known(v_x_198_, 0);
v___x_211_ = lean_unsigned_to_nat(1024u);
v___x_212_ = lean_nat_dec_le(v___x_211_, v_prec_199_);
if (v___x_212_ == 0)
{
lean_object* v___x_213_; 
v___x_213_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_202_ = v___x_213_;
goto v___jp_201_;
}
else
{
lean_object* v___x_214_; 
v___x_214_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_202_ = v___x_214_;
goto v___jp_201_;
}
v___jp_201_:
{
lean_object* v___x_203_; lean_object* v___x_204_; lean_object* v___x_205_; lean_object* v___x_206_; lean_object* v___x_207_; uint8_t v___x_208_; lean_object* v___x_209_; lean_object* v___x_210_; 
v___x_203_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__2));
v___x_204_ = lean_unsigned_to_nat(1024u);
v___x_205_ = l_Float_repr(v_v_200_, v___x_204_);
v___x_206_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_206_, 0, v___x_203_);
lean_ctor_set(v___x_206_, 1, v___x_205_);
lean_inc(v___y_202_);
v___x_207_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_207_, 0, v___y_202_);
lean_ctor_set(v___x_207_, 1, v___x_206_);
v___x_208_ = 0;
v___x_209_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_209_, 0, v___x_207_);
lean_ctor_set_uint8(v___x_209_, sizeof(void*)*1, v___x_208_);
v___x_210_ = l_Repr_addAppParen(v___x_209_, v_prec_199_);
return v___x_210_;
}
}
case 1:
{
lean_object* v_x_215_; lean_object* v___x_217_; uint8_t v_isShared_218_; uint8_t v_isSharedCheck_235_; 
v_x_215_ = lean_ctor_get(v_x_198_, 0);
v_isSharedCheck_235_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_235_ == 0)
{
v___x_217_ = v_x_198_;
v_isShared_218_ = v_isSharedCheck_235_;
goto v_resetjp_216_;
}
else
{
lean_inc(v_x_215_);
lean_dec(v_x_198_);
v___x_217_ = lean_box(0);
v_isShared_218_ = v_isSharedCheck_235_;
goto v_resetjp_216_;
}
v_resetjp_216_:
{
lean_object* v___y_220_; lean_object* v___x_231_; uint8_t v___x_232_; 
v___x_231_ = lean_unsigned_to_nat(1024u);
v___x_232_ = lean_nat_dec_le(v___x_231_, v_prec_199_);
if (v___x_232_ == 0)
{
lean_object* v___x_233_; 
v___x_233_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_220_ = v___x_233_;
goto v___jp_219_;
}
else
{
lean_object* v___x_234_; 
v___x_234_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_220_ = v___x_234_;
goto v___jp_219_;
}
v___jp_219_:
{
lean_object* v___x_221_; lean_object* v___x_222_; lean_object* v___x_224_; 
v___x_221_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__7));
v___x_222_ = l_Nat_reprFast(v_x_215_);
if (v_isShared_218_ == 0)
{
lean_ctor_set_tag(v___x_217_, 3);
lean_ctor_set(v___x_217_, 0, v___x_222_);
v___x_224_ = v___x_217_;
goto v_reusejp_223_;
}
else
{
lean_object* v_reuseFailAlloc_230_; 
v_reuseFailAlloc_230_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_230_, 0, v___x_222_);
v___x_224_ = v_reuseFailAlloc_230_;
goto v_reusejp_223_;
}
v_reusejp_223_:
{
lean_object* v___x_225_; lean_object* v___x_226_; uint8_t v___x_227_; lean_object* v___x_228_; lean_object* v___x_229_; 
v___x_225_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_225_, 0, v___x_221_);
lean_ctor_set(v___x_225_, 1, v___x_224_);
lean_inc(v___y_220_);
v___x_226_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_226_, 0, v___y_220_);
lean_ctor_set(v___x_226_, 1, v___x_225_);
v___x_227_ = 0;
v___x_228_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_228_, 0, v___x_226_);
lean_ctor_set_uint8(v___x_228_, sizeof(void*)*1, v___x_227_);
v___x_229_ = l_Repr_addAppParen(v___x_228_, v_prec_199_);
return v___x_229_;
}
}
}
}
case 2:
{
lean_object* v_e1_236_; lean_object* v_e2_237_; lean_object* v___x_239_; uint8_t v_isShared_240_; uint8_t v_isSharedCheck_260_; 
v_e1_236_ = lean_ctor_get(v_x_198_, 0);
v_e2_237_ = lean_ctor_get(v_x_198_, 1);
v_isSharedCheck_260_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_260_ == 0)
{
v___x_239_ = v_x_198_;
v_isShared_240_ = v_isSharedCheck_260_;
goto v_resetjp_238_;
}
else
{
lean_inc(v_e2_237_);
lean_inc(v_e1_236_);
lean_dec(v_x_198_);
v___x_239_ = lean_box(0);
v_isShared_240_ = v_isSharedCheck_260_;
goto v_resetjp_238_;
}
v_resetjp_238_:
{
lean_object* v___x_241_; lean_object* v___y_243_; uint8_t v___x_257_; 
v___x_241_ = lean_unsigned_to_nat(1024u);
v___x_257_ = lean_nat_dec_le(v___x_241_, v_prec_199_);
if (v___x_257_ == 0)
{
lean_object* v___x_258_; 
v___x_258_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_243_ = v___x_258_;
goto v___jp_242_;
}
else
{
lean_object* v___x_259_; 
v___x_259_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_243_ = v___x_259_;
goto v___jp_242_;
}
v___jp_242_:
{
lean_object* v___x_244_; lean_object* v___x_245_; lean_object* v___x_246_; lean_object* v___x_248_; 
v___x_244_ = lean_box(1);
v___x_245_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__10));
v___x_246_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e1_236_, v___x_241_);
if (v_isShared_240_ == 0)
{
lean_ctor_set_tag(v___x_239_, 5);
lean_ctor_set(v___x_239_, 1, v___x_246_);
lean_ctor_set(v___x_239_, 0, v___x_245_);
v___x_248_ = v___x_239_;
goto v_reusejp_247_;
}
else
{
lean_object* v_reuseFailAlloc_256_; 
v_reuseFailAlloc_256_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_256_, 0, v___x_245_);
lean_ctor_set(v_reuseFailAlloc_256_, 1, v___x_246_);
v___x_248_ = v_reuseFailAlloc_256_;
goto v_reusejp_247_;
}
v_reusejp_247_:
{
lean_object* v___x_249_; lean_object* v___x_250_; lean_object* v___x_251_; lean_object* v___x_252_; uint8_t v___x_253_; lean_object* v___x_254_; lean_object* v___x_255_; 
v___x_249_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_249_, 0, v___x_248_);
lean_ctor_set(v___x_249_, 1, v___x_244_);
v___x_250_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e2_237_, v___x_241_);
v___x_251_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_251_, 0, v___x_249_);
lean_ctor_set(v___x_251_, 1, v___x_250_);
lean_inc(v___y_243_);
v___x_252_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_252_, 0, v___y_243_);
lean_ctor_set(v___x_252_, 1, v___x_251_);
v___x_253_ = 0;
v___x_254_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_254_, 0, v___x_252_);
lean_ctor_set_uint8(v___x_254_, sizeof(void*)*1, v___x_253_);
v___x_255_ = l_Repr_addAppParen(v___x_254_, v_prec_199_);
return v___x_255_;
}
}
}
}
case 3:
{
lean_object* v_e1_261_; lean_object* v_e2_262_; lean_object* v___x_264_; uint8_t v_isShared_265_; uint8_t v_isSharedCheck_285_; 
v_e1_261_ = lean_ctor_get(v_x_198_, 0);
v_e2_262_ = lean_ctor_get(v_x_198_, 1);
v_isSharedCheck_285_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_285_ == 0)
{
v___x_264_ = v_x_198_;
v_isShared_265_ = v_isSharedCheck_285_;
goto v_resetjp_263_;
}
else
{
lean_inc(v_e2_262_);
lean_inc(v_e1_261_);
lean_dec(v_x_198_);
v___x_264_ = lean_box(0);
v_isShared_265_ = v_isSharedCheck_285_;
goto v_resetjp_263_;
}
v_resetjp_263_:
{
lean_object* v___x_266_; lean_object* v___y_268_; uint8_t v___x_282_; 
v___x_266_ = lean_unsigned_to_nat(1024u);
v___x_282_ = lean_nat_dec_le(v___x_266_, v_prec_199_);
if (v___x_282_ == 0)
{
lean_object* v___x_283_; 
v___x_283_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_268_ = v___x_283_;
goto v___jp_267_;
}
else
{
lean_object* v___x_284_; 
v___x_284_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_268_ = v___x_284_;
goto v___jp_267_;
}
v___jp_267_:
{
lean_object* v___x_269_; lean_object* v___x_270_; lean_object* v___x_271_; lean_object* v___x_273_; 
v___x_269_ = lean_box(1);
v___x_270_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__13));
v___x_271_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e1_261_, v___x_266_);
if (v_isShared_265_ == 0)
{
lean_ctor_set_tag(v___x_264_, 5);
lean_ctor_set(v___x_264_, 1, v___x_271_);
lean_ctor_set(v___x_264_, 0, v___x_270_);
v___x_273_ = v___x_264_;
goto v_reusejp_272_;
}
else
{
lean_object* v_reuseFailAlloc_281_; 
v_reuseFailAlloc_281_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_281_, 0, v___x_270_);
lean_ctor_set(v_reuseFailAlloc_281_, 1, v___x_271_);
v___x_273_ = v_reuseFailAlloc_281_;
goto v_reusejp_272_;
}
v_reusejp_272_:
{
lean_object* v___x_274_; lean_object* v___x_275_; lean_object* v___x_276_; lean_object* v___x_277_; uint8_t v___x_278_; lean_object* v___x_279_; lean_object* v___x_280_; 
v___x_274_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_274_, 0, v___x_273_);
lean_ctor_set(v___x_274_, 1, v___x_269_);
v___x_275_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e2_262_, v___x_266_);
v___x_276_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_276_, 0, v___x_274_);
lean_ctor_set(v___x_276_, 1, v___x_275_);
lean_inc(v___y_268_);
v___x_277_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_277_, 0, v___y_268_);
lean_ctor_set(v___x_277_, 1, v___x_276_);
v___x_278_ = 0;
v___x_279_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_279_, 0, v___x_277_);
lean_ctor_set_uint8(v___x_279_, sizeof(void*)*1, v___x_278_);
v___x_280_ = l_Repr_addAppParen(v___x_279_, v_prec_199_);
return v___x_280_;
}
}
}
}
case 4:
{
lean_object* v_e1_286_; lean_object* v_e2_287_; lean_object* v___x_289_; uint8_t v_isShared_290_; uint8_t v_isSharedCheck_310_; 
v_e1_286_ = lean_ctor_get(v_x_198_, 0);
v_e2_287_ = lean_ctor_get(v_x_198_, 1);
v_isSharedCheck_310_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_310_ == 0)
{
v___x_289_ = v_x_198_;
v_isShared_290_ = v_isSharedCheck_310_;
goto v_resetjp_288_;
}
else
{
lean_inc(v_e2_287_);
lean_inc(v_e1_286_);
lean_dec(v_x_198_);
v___x_289_ = lean_box(0);
v_isShared_290_ = v_isSharedCheck_310_;
goto v_resetjp_288_;
}
v_resetjp_288_:
{
lean_object* v___x_291_; lean_object* v___y_293_; uint8_t v___x_307_; 
v___x_291_ = lean_unsigned_to_nat(1024u);
v___x_307_ = lean_nat_dec_le(v___x_291_, v_prec_199_);
if (v___x_307_ == 0)
{
lean_object* v___x_308_; 
v___x_308_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_293_ = v___x_308_;
goto v___jp_292_;
}
else
{
lean_object* v___x_309_; 
v___x_309_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_293_ = v___x_309_;
goto v___jp_292_;
}
v___jp_292_:
{
lean_object* v___x_294_; lean_object* v___x_295_; lean_object* v___x_296_; lean_object* v___x_298_; 
v___x_294_ = lean_box(1);
v___x_295_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__16));
v___x_296_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e1_286_, v___x_291_);
if (v_isShared_290_ == 0)
{
lean_ctor_set_tag(v___x_289_, 5);
lean_ctor_set(v___x_289_, 1, v___x_296_);
lean_ctor_set(v___x_289_, 0, v___x_295_);
v___x_298_ = v___x_289_;
goto v_reusejp_297_;
}
else
{
lean_object* v_reuseFailAlloc_306_; 
v_reuseFailAlloc_306_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_306_, 0, v___x_295_);
lean_ctor_set(v_reuseFailAlloc_306_, 1, v___x_296_);
v___x_298_ = v_reuseFailAlloc_306_;
goto v_reusejp_297_;
}
v_reusejp_297_:
{
lean_object* v___x_299_; lean_object* v___x_300_; lean_object* v___x_301_; lean_object* v___x_302_; uint8_t v___x_303_; lean_object* v___x_304_; lean_object* v___x_305_; 
v___x_299_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_299_, 0, v___x_298_);
lean_ctor_set(v___x_299_, 1, v___x_294_);
v___x_300_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e2_287_, v___x_291_);
v___x_301_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_301_, 0, v___x_299_);
lean_ctor_set(v___x_301_, 1, v___x_300_);
lean_inc(v___y_293_);
v___x_302_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_302_, 0, v___y_293_);
lean_ctor_set(v___x_302_, 1, v___x_301_);
v___x_303_ = 0;
v___x_304_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_304_, 0, v___x_302_);
lean_ctor_set_uint8(v___x_304_, sizeof(void*)*1, v___x_303_);
v___x_305_ = l_Repr_addAppParen(v___x_304_, v_prec_199_);
return v___x_305_;
}
}
}
}
case 5:
{
lean_object* v_e1_311_; lean_object* v_e2_312_; lean_object* v___x_314_; uint8_t v_isShared_315_; uint8_t v_isSharedCheck_335_; 
v_e1_311_ = lean_ctor_get(v_x_198_, 0);
v_e2_312_ = lean_ctor_get(v_x_198_, 1);
v_isSharedCheck_335_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_335_ == 0)
{
v___x_314_ = v_x_198_;
v_isShared_315_ = v_isSharedCheck_335_;
goto v_resetjp_313_;
}
else
{
lean_inc(v_e2_312_);
lean_inc(v_e1_311_);
lean_dec(v_x_198_);
v___x_314_ = lean_box(0);
v_isShared_315_ = v_isSharedCheck_335_;
goto v_resetjp_313_;
}
v_resetjp_313_:
{
lean_object* v___x_316_; lean_object* v___y_318_; uint8_t v___x_332_; 
v___x_316_ = lean_unsigned_to_nat(1024u);
v___x_332_ = lean_nat_dec_le(v___x_316_, v_prec_199_);
if (v___x_332_ == 0)
{
lean_object* v___x_333_; 
v___x_333_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_318_ = v___x_333_;
goto v___jp_317_;
}
else
{
lean_object* v___x_334_; 
v___x_334_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_318_ = v___x_334_;
goto v___jp_317_;
}
v___jp_317_:
{
lean_object* v___x_319_; lean_object* v___x_320_; lean_object* v___x_321_; lean_object* v___x_323_; 
v___x_319_ = lean_box(1);
v___x_320_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__19));
v___x_321_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e1_311_, v___x_316_);
if (v_isShared_315_ == 0)
{
lean_ctor_set(v___x_314_, 1, v___x_321_);
lean_ctor_set(v___x_314_, 0, v___x_320_);
v___x_323_ = v___x_314_;
goto v_reusejp_322_;
}
else
{
lean_object* v_reuseFailAlloc_331_; 
v_reuseFailAlloc_331_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_331_, 0, v___x_320_);
lean_ctor_set(v_reuseFailAlloc_331_, 1, v___x_321_);
v___x_323_ = v_reuseFailAlloc_331_;
goto v_reusejp_322_;
}
v_reusejp_322_:
{
lean_object* v___x_324_; lean_object* v___x_325_; lean_object* v___x_326_; lean_object* v___x_327_; uint8_t v___x_328_; lean_object* v___x_329_; lean_object* v___x_330_; 
v___x_324_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_324_, 0, v___x_323_);
lean_ctor_set(v___x_324_, 1, v___x_319_);
v___x_325_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e2_312_, v___x_316_);
v___x_326_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_326_, 0, v___x_324_);
lean_ctor_set(v___x_326_, 1, v___x_325_);
lean_inc(v___y_318_);
v___x_327_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_327_, 0, v___y_318_);
lean_ctor_set(v___x_327_, 1, v___x_326_);
v___x_328_ = 0;
v___x_329_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_329_, 0, v___x_327_);
lean_ctor_set_uint8(v___x_329_, sizeof(void*)*1, v___x_328_);
v___x_330_ = l_Repr_addAppParen(v___x_329_, v_prec_199_);
return v___x_330_;
}
}
}
}
case 6:
{
lean_object* v_e1_336_; lean_object* v_e2_337_; lean_object* v___x_339_; uint8_t v_isShared_340_; uint8_t v_isSharedCheck_360_; 
v_e1_336_ = lean_ctor_get(v_x_198_, 0);
v_e2_337_ = lean_ctor_get(v_x_198_, 1);
v_isSharedCheck_360_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_360_ == 0)
{
v___x_339_ = v_x_198_;
v_isShared_340_ = v_isSharedCheck_360_;
goto v_resetjp_338_;
}
else
{
lean_inc(v_e2_337_);
lean_inc(v_e1_336_);
lean_dec(v_x_198_);
v___x_339_ = lean_box(0);
v_isShared_340_ = v_isSharedCheck_360_;
goto v_resetjp_338_;
}
v_resetjp_338_:
{
lean_object* v___x_341_; lean_object* v___y_343_; uint8_t v___x_357_; 
v___x_341_ = lean_unsigned_to_nat(1024u);
v___x_357_ = lean_nat_dec_le(v___x_341_, v_prec_199_);
if (v___x_357_ == 0)
{
lean_object* v___x_358_; 
v___x_358_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_343_ = v___x_358_;
goto v___jp_342_;
}
else
{
lean_object* v___x_359_; 
v___x_359_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_343_ = v___x_359_;
goto v___jp_342_;
}
v___jp_342_:
{
lean_object* v___x_344_; lean_object* v___x_345_; lean_object* v___x_346_; lean_object* v___x_348_; 
v___x_344_ = lean_box(1);
v___x_345_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__22));
v___x_346_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e1_336_, v___x_341_);
if (v_isShared_340_ == 0)
{
lean_ctor_set_tag(v___x_339_, 5);
lean_ctor_set(v___x_339_, 1, v___x_346_);
lean_ctor_set(v___x_339_, 0, v___x_345_);
v___x_348_ = v___x_339_;
goto v_reusejp_347_;
}
else
{
lean_object* v_reuseFailAlloc_356_; 
v_reuseFailAlloc_356_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_356_, 0, v___x_345_);
lean_ctor_set(v_reuseFailAlloc_356_, 1, v___x_346_);
v___x_348_ = v_reuseFailAlloc_356_;
goto v_reusejp_347_;
}
v_reusejp_347_:
{
lean_object* v___x_349_; lean_object* v___x_350_; lean_object* v___x_351_; lean_object* v___x_352_; uint8_t v___x_353_; lean_object* v___x_354_; lean_object* v___x_355_; 
v___x_349_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_349_, 0, v___x_348_);
lean_ctor_set(v___x_349_, 1, v___x_344_);
v___x_350_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e2_337_, v___x_341_);
v___x_351_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_351_, 0, v___x_349_);
lean_ctor_set(v___x_351_, 1, v___x_350_);
lean_inc(v___y_343_);
v___x_352_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_352_, 0, v___y_343_);
lean_ctor_set(v___x_352_, 1, v___x_351_);
v___x_353_ = 0;
v___x_354_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_354_, 0, v___x_352_);
lean_ctor_set_uint8(v___x_354_, sizeof(void*)*1, v___x_353_);
v___x_355_ = l_Repr_addAppParen(v___x_354_, v_prec_199_);
return v___x_355_;
}
}
}
}
case 7:
{
lean_object* v_e1_361_; lean_object* v_e2_362_; lean_object* v___x_364_; uint8_t v_isShared_365_; uint8_t v_isSharedCheck_385_; 
v_e1_361_ = lean_ctor_get(v_x_198_, 0);
v_e2_362_ = lean_ctor_get(v_x_198_, 1);
v_isSharedCheck_385_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_385_ == 0)
{
v___x_364_ = v_x_198_;
v_isShared_365_ = v_isSharedCheck_385_;
goto v_resetjp_363_;
}
else
{
lean_inc(v_e2_362_);
lean_inc(v_e1_361_);
lean_dec(v_x_198_);
v___x_364_ = lean_box(0);
v_isShared_365_ = v_isSharedCheck_385_;
goto v_resetjp_363_;
}
v_resetjp_363_:
{
lean_object* v___x_366_; lean_object* v___y_368_; uint8_t v___x_382_; 
v___x_366_ = lean_unsigned_to_nat(1024u);
v___x_382_ = lean_nat_dec_le(v___x_366_, v_prec_199_);
if (v___x_382_ == 0)
{
lean_object* v___x_383_; 
v___x_383_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_368_ = v___x_383_;
goto v___jp_367_;
}
else
{
lean_object* v___x_384_; 
v___x_384_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_368_ = v___x_384_;
goto v___jp_367_;
}
v___jp_367_:
{
lean_object* v___x_369_; lean_object* v___x_370_; lean_object* v___x_371_; lean_object* v___x_373_; 
v___x_369_ = lean_box(1);
v___x_370_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__25));
v___x_371_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e1_361_, v___x_366_);
if (v_isShared_365_ == 0)
{
lean_ctor_set_tag(v___x_364_, 5);
lean_ctor_set(v___x_364_, 1, v___x_371_);
lean_ctor_set(v___x_364_, 0, v___x_370_);
v___x_373_ = v___x_364_;
goto v_reusejp_372_;
}
else
{
lean_object* v_reuseFailAlloc_381_; 
v_reuseFailAlloc_381_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_381_, 0, v___x_370_);
lean_ctor_set(v_reuseFailAlloc_381_, 1, v___x_371_);
v___x_373_ = v_reuseFailAlloc_381_;
goto v_reusejp_372_;
}
v_reusejp_372_:
{
lean_object* v___x_374_; lean_object* v___x_375_; lean_object* v___x_376_; lean_object* v___x_377_; uint8_t v___x_378_; lean_object* v___x_379_; lean_object* v___x_380_; 
v___x_374_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_374_, 0, v___x_373_);
lean_ctor_set(v___x_374_, 1, v___x_369_);
v___x_375_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e2_362_, v___x_366_);
v___x_376_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_376_, 0, v___x_374_);
lean_ctor_set(v___x_376_, 1, v___x_375_);
lean_inc(v___y_368_);
v___x_377_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_377_, 0, v___y_368_);
lean_ctor_set(v___x_377_, 1, v___x_376_);
v___x_378_ = 0;
v___x_379_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_379_, 0, v___x_377_);
lean_ctor_set_uint8(v___x_379_, sizeof(void*)*1, v___x_378_);
v___x_380_ = l_Repr_addAppParen(v___x_379_, v_prec_199_);
return v___x_380_;
}
}
}
}
case 8:
{
lean_object* v_e1_386_; lean_object* v_e2_387_; lean_object* v___x_389_; uint8_t v_isShared_390_; uint8_t v_isSharedCheck_410_; 
v_e1_386_ = lean_ctor_get(v_x_198_, 0);
v_e2_387_ = lean_ctor_get(v_x_198_, 1);
v_isSharedCheck_410_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_410_ == 0)
{
v___x_389_ = v_x_198_;
v_isShared_390_ = v_isSharedCheck_410_;
goto v_resetjp_388_;
}
else
{
lean_inc(v_e2_387_);
lean_inc(v_e1_386_);
lean_dec(v_x_198_);
v___x_389_ = lean_box(0);
v_isShared_390_ = v_isSharedCheck_410_;
goto v_resetjp_388_;
}
v_resetjp_388_:
{
lean_object* v___x_391_; lean_object* v___y_393_; uint8_t v___x_407_; 
v___x_391_ = lean_unsigned_to_nat(1024u);
v___x_407_ = lean_nat_dec_le(v___x_391_, v_prec_199_);
if (v___x_407_ == 0)
{
lean_object* v___x_408_; 
v___x_408_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_393_ = v___x_408_;
goto v___jp_392_;
}
else
{
lean_object* v___x_409_; 
v___x_409_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_393_ = v___x_409_;
goto v___jp_392_;
}
v___jp_392_:
{
lean_object* v___x_394_; lean_object* v___x_395_; lean_object* v___x_396_; lean_object* v___x_398_; 
v___x_394_ = lean_box(1);
v___x_395_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__28));
v___x_396_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e1_386_, v___x_391_);
if (v_isShared_390_ == 0)
{
lean_ctor_set_tag(v___x_389_, 5);
lean_ctor_set(v___x_389_, 1, v___x_396_);
lean_ctor_set(v___x_389_, 0, v___x_395_);
v___x_398_ = v___x_389_;
goto v_reusejp_397_;
}
else
{
lean_object* v_reuseFailAlloc_406_; 
v_reuseFailAlloc_406_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_406_, 0, v___x_395_);
lean_ctor_set(v_reuseFailAlloc_406_, 1, v___x_396_);
v___x_398_ = v_reuseFailAlloc_406_;
goto v_reusejp_397_;
}
v_reusejp_397_:
{
lean_object* v___x_399_; lean_object* v___x_400_; lean_object* v___x_401_; lean_object* v___x_402_; uint8_t v___x_403_; lean_object* v___x_404_; lean_object* v___x_405_; 
v___x_399_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_399_, 0, v___x_398_);
lean_ctor_set(v___x_399_, 1, v___x_394_);
v___x_400_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e2_387_, v___x_391_);
v___x_401_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_401_, 0, v___x_399_);
lean_ctor_set(v___x_401_, 1, v___x_400_);
lean_inc(v___y_393_);
v___x_402_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_402_, 0, v___y_393_);
lean_ctor_set(v___x_402_, 1, v___x_401_);
v___x_403_ = 0;
v___x_404_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_404_, 0, v___x_402_);
lean_ctor_set_uint8(v___x_404_, sizeof(void*)*1, v___x_403_);
v___x_405_ = l_Repr_addAppParen(v___x_404_, v_prec_199_);
return v___x_405_;
}
}
}
}
case 9:
{
lean_object* v_e1_411_; lean_object* v_e2_412_; lean_object* v___x_414_; uint8_t v_isShared_415_; uint8_t v_isSharedCheck_435_; 
v_e1_411_ = lean_ctor_get(v_x_198_, 0);
v_e2_412_ = lean_ctor_get(v_x_198_, 1);
v_isSharedCheck_435_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_435_ == 0)
{
v___x_414_ = v_x_198_;
v_isShared_415_ = v_isSharedCheck_435_;
goto v_resetjp_413_;
}
else
{
lean_inc(v_e2_412_);
lean_inc(v_e1_411_);
lean_dec(v_x_198_);
v___x_414_ = lean_box(0);
v_isShared_415_ = v_isSharedCheck_435_;
goto v_resetjp_413_;
}
v_resetjp_413_:
{
lean_object* v___x_416_; lean_object* v___y_418_; uint8_t v___x_432_; 
v___x_416_ = lean_unsigned_to_nat(1024u);
v___x_432_ = lean_nat_dec_le(v___x_416_, v_prec_199_);
if (v___x_432_ == 0)
{
lean_object* v___x_433_; 
v___x_433_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_418_ = v___x_433_;
goto v___jp_417_;
}
else
{
lean_object* v___x_434_; 
v___x_434_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_418_ = v___x_434_;
goto v___jp_417_;
}
v___jp_417_:
{
lean_object* v___x_419_; lean_object* v___x_420_; lean_object* v___x_421_; lean_object* v___x_423_; 
v___x_419_ = lean_box(1);
v___x_420_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__31));
v___x_421_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e1_411_, v___x_416_);
if (v_isShared_415_ == 0)
{
lean_ctor_set_tag(v___x_414_, 5);
lean_ctor_set(v___x_414_, 1, v___x_421_);
lean_ctor_set(v___x_414_, 0, v___x_420_);
v___x_423_ = v___x_414_;
goto v_reusejp_422_;
}
else
{
lean_object* v_reuseFailAlloc_431_; 
v_reuseFailAlloc_431_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_431_, 0, v___x_420_);
lean_ctor_set(v_reuseFailAlloc_431_, 1, v___x_421_);
v___x_423_ = v_reuseFailAlloc_431_;
goto v_reusejp_422_;
}
v_reusejp_422_:
{
lean_object* v___x_424_; lean_object* v___x_425_; lean_object* v___x_426_; lean_object* v___x_427_; uint8_t v___x_428_; lean_object* v___x_429_; lean_object* v___x_430_; 
v___x_424_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_424_, 0, v___x_423_);
lean_ctor_set(v___x_424_, 1, v___x_419_);
v___x_425_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e2_412_, v___x_416_);
v___x_426_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_426_, 0, v___x_424_);
lean_ctor_set(v___x_426_, 1, v___x_425_);
lean_inc(v___y_418_);
v___x_427_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_427_, 0, v___y_418_);
lean_ctor_set(v___x_427_, 1, v___x_426_);
v___x_428_ = 0;
v___x_429_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_429_, 0, v___x_427_);
lean_ctor_set_uint8(v___x_429_, sizeof(void*)*1, v___x_428_);
v___x_430_ = l_Repr_addAppParen(v___x_429_, v_prec_199_);
return v___x_430_;
}
}
}
}
default: 
{
lean_object* v_e1_436_; lean_object* v_e2_437_; lean_object* v___x_439_; uint8_t v_isShared_440_; uint8_t v_isSharedCheck_460_; 
v_e1_436_ = lean_ctor_get(v_x_198_, 0);
v_e2_437_ = lean_ctor_get(v_x_198_, 1);
v_isSharedCheck_460_ = !lean_is_exclusive(v_x_198_);
if (v_isSharedCheck_460_ == 0)
{
v___x_439_ = v_x_198_;
v_isShared_440_ = v_isSharedCheck_460_;
goto v_resetjp_438_;
}
else
{
lean_inc(v_e2_437_);
lean_inc(v_e1_436_);
lean_dec(v_x_198_);
v___x_439_ = lean_box(0);
v_isShared_440_ = v_isSharedCheck_460_;
goto v_resetjp_438_;
}
v_resetjp_438_:
{
lean_object* v___x_441_; lean_object* v___y_443_; uint8_t v___x_457_; 
v___x_441_ = lean_unsigned_to_nat(1024u);
v___x_457_ = lean_nat_dec_le(v___x_441_, v_prec_199_);
if (v___x_457_ == 0)
{
lean_object* v___x_458_; 
v___x_458_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__3);
v___y_443_ = v___x_458_;
goto v___jp_442_;
}
else
{
lean_object* v___x_459_; 
v___x_459_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__4);
v___y_443_ = v___x_459_;
goto v___jp_442_;
}
v___jp_442_:
{
lean_object* v___x_444_; lean_object* v___x_445_; lean_object* v___x_446_; lean_object* v___x_448_; 
v___x_444_ = lean_box(1);
v___x_445_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___closed__34));
v___x_446_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e1_436_, v___x_441_);
if (v_isShared_440_ == 0)
{
lean_ctor_set_tag(v___x_439_, 5);
lean_ctor_set(v___x_439_, 1, v___x_446_);
lean_ctor_set(v___x_439_, 0, v___x_445_);
v___x_448_ = v___x_439_;
goto v_reusejp_447_;
}
else
{
lean_object* v_reuseFailAlloc_456_; 
v_reuseFailAlloc_456_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v_reuseFailAlloc_456_, 0, v___x_445_);
lean_ctor_set(v_reuseFailAlloc_456_, 1, v___x_446_);
v___x_448_ = v_reuseFailAlloc_456_;
goto v_reusejp_447_;
}
v_reusejp_447_:
{
lean_object* v___x_449_; lean_object* v___x_450_; lean_object* v___x_451_; lean_object* v___x_452_; uint8_t v___x_453_; lean_object* v___x_454_; lean_object* v___x_455_; 
v___x_449_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_449_, 0, v___x_448_);
lean_ctor_set(v___x_449_, 1, v___x_444_);
v___x_450_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_e2_437_, v___x_441_);
v___x_451_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_451_, 0, v___x_449_);
lean_ctor_set(v___x_451_, 1, v___x_450_);
lean_inc(v___y_443_);
v___x_452_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_452_, 0, v___y_443_);
lean_ctor_set(v___x_452_, 1, v___x_451_);
v___x_453_ = 0;
v___x_454_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_454_, 0, v___x_452_);
lean_ctor_set_uint8(v___x_454_, sizeof(void*)*1, v___x_453_);
v___x_455_ = l_Repr_addAppParen(v___x_454_, v_prec_199_);
return v___x_455_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr___boxed(lean_object* v_x_461_, lean_object* v_prec_462_){
_start:
{
lean_object* v_res_463_; 
v_res_463_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_instReprCExpr_repr(v_x_461_, v_prec_462_);
lean_dec(v_prec_462_);
return v_res_463_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0(void){
_start:
{
lean_object* v___x_466_; uint8_t v___x_467_; lean_object* v___x_468_; double v___x_469_; 
v___x_466_ = lean_unsigned_to_nat(1u);
v___x_467_ = 1;
v___x_468_ = lean_unsigned_to_nat(0u);
v___x_469_ = l_Float_ofScientific(v___x_468_, v___x_467_, v___x_466_);
return v___x_469_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env(lean_object* v_x_470_){
_start:
{
double v___x_471_; 
v___x_471_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0);
return v___x_471_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___boxed(lean_object* v_x_472_){
_start:
{
double v_res_473_; lean_object* v_r_474_; 
v_res_473_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env(v_x_472_);
lean_dec(v_x_472_);
v_r_474_ = lean_box_float(v_res_473_);
return v_r_474_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_env__update(lean_object* v_env_475_, lean_object* v_x_476_, double v_v_477_, lean_object* v_y_478_){
_start:
{
uint8_t v___x_479_; 
v___x_479_ = lean_nat_dec_eq(v_y_478_, v_x_476_);
if (v___x_479_ == 0)
{
lean_object* v___x_480_; double v___x_481_; 
v___x_480_ = lean_apply_1(v_env_475_, v_y_478_);
v___x_481_ = lean_unbox_float(v___x_480_);
lean_dec_ref(v___x_480_);
return v___x_481_;
}
else
{
lean_dec(v_y_478_);
lean_dec_ref(v_env_475_);
return v_v_477_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_env__update___boxed(lean_object* v_env_482_, lean_object* v_x_483_, lean_object* v_v_484_, lean_object* v_y_485_){
_start:
{
double v_v_boxed_486_; double v_res_487_; lean_object* v_r_488_; 
v_v_boxed_486_ = lean_unbox_float(v_v_484_);
lean_dec_ref(v_v_484_);
v_res_487_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_env__update(v_env_482_, v_x_483_, v_v_boxed_486_, v_y_485_);
lean_dec(v_x_483_);
v_r_488_ = lean_box_float(v_res_487_);
return v_r_488_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__6(void){
_start:
{
lean_object* v___x_545_; lean_object* v___x_546_; 
v___x_545_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__5));
v___x_546_ = l_String_toRawSubstring_x27(v___x_545_);
return v___x_546_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1(lean_object* v_x_562_, lean_object* v_a_563_, lean_object* v_a_564_){
_start:
{
lean_object* v___x_565_; uint8_t v___x_566_; 
v___x_565_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3));
lean_inc(v_x_562_);
v___x_566_ = l_Lean_Syntax_isOfKind(v_x_562_, v___x_565_);
if (v___x_566_ == 0)
{
lean_object* v___x_567_; lean_object* v___x_568_; 
lean_dec(v_x_562_);
v___x_567_ = lean_box(1);
v___x_568_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_568_, 0, v___x_567_);
lean_ctor_set(v___x_568_, 1, v_a_564_);
return v___x_568_;
}
else
{
lean_object* v_quotContext_569_; lean_object* v_currMacroScope_570_; lean_object* v_ref_571_; lean_object* v___x_572_; lean_object* v___x_573_; lean_object* v___x_574_; lean_object* v___x_575_; lean_object* v___x_576_; lean_object* v___x_577_; uint8_t v___x_578_; lean_object* v___x_579_; lean_object* v___x_580_; lean_object* v___x_581_; lean_object* v___x_582_; lean_object* v___x_583_; lean_object* v___x_584_; lean_object* v___x_585_; lean_object* v___x_586_; lean_object* v___x_587_; lean_object* v___x_588_; lean_object* v___x_589_; 
v_quotContext_569_ = lean_ctor_get(v_a_563_, 1);
v_currMacroScope_570_ = lean_ctor_get(v_a_563_, 2);
v_ref_571_ = lean_ctor_get(v_a_563_, 5);
v___x_572_ = lean_unsigned_to_nat(0u);
v___x_573_ = l_Lean_Syntax_getArg(v_x_562_, v___x_572_);
v___x_574_ = lean_unsigned_to_nat(2u);
v___x_575_ = l_Lean_Syntax_getArg(v_x_562_, v___x_574_);
v___x_576_ = lean_unsigned_to_nat(4u);
v___x_577_ = l_Lean_Syntax_getArg(v_x_562_, v___x_576_);
lean_dec(v_x_562_);
v___x_578_ = 0;
v___x_579_ = l_Lean_SourceInfo_fromRef(v_ref_571_, v___x_578_);
v___x_580_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4));
v___x_581_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__6, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__6_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__6);
v___x_582_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__7));
lean_inc(v_currMacroScope_570_);
lean_inc(v_quotContext_569_);
v___x_583_ = l_Lean_addMacroScope(v_quotContext_569_, v___x_582_, v_currMacroScope_570_);
v___x_584_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__10));
lean_inc_n(v___x_579_, 2);
v___x_585_ = lean_alloc_ctor(3, 4, 0);
lean_ctor_set(v___x_585_, 0, v___x_579_);
lean_ctor_set(v___x_585_, 1, v___x_581_);
lean_ctor_set(v___x_585_, 2, v___x_583_);
lean_ctor_set(v___x_585_, 3, v___x_584_);
v___x_586_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__12));
v___x_587_ = l_Lean_Syntax_node3(v___x_579_, v___x_586_, v___x_573_, v___x_575_, v___x_577_);
v___x_588_ = l_Lean_Syntax_node2(v___x_579_, v___x_580_, v___x_585_, v___x_587_);
v___x_589_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_589_, 0, v___x_588_);
lean_ctor_set(v___x_589_, 1, v_a_564_);
return v___x_589_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___boxed(lean_object* v_x_590_, lean_object* v_a_591_, lean_object* v_a_592_){
_start:
{
lean_object* v_res_593_; 
v_res_593_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1(v_x_590_, v_a_591_, v_a_592_);
lean_dec_ref(v_a_591_);
return v_res_593_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1(lean_object* v_x_597_, lean_object* v_a_598_, lean_object* v_a_599_){
_start:
{
lean_object* v___x_600_; uint8_t v___x_601_; 
v___x_600_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______macroRules__MaxwellKey__VerifiedExtraction__term___x5b___u21a6___x5d__1___closed__4));
lean_inc(v_x_597_);
v___x_601_ = l_Lean_Syntax_isOfKind(v_x_597_, v___x_600_);
if (v___x_601_ == 0)
{
lean_object* v___x_602_; lean_object* v___x_603_; 
lean_dec(v_x_597_);
v___x_602_ = lean_box(0);
v___x_603_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_603_, 0, v___x_602_);
lean_ctor_set(v___x_603_, 1, v_a_599_);
return v___x_603_;
}
else
{
lean_object* v___x_604_; lean_object* v___x_605_; lean_object* v___x_606_; uint8_t v___x_607_; 
v___x_604_ = lean_unsigned_to_nat(0u);
v___x_605_ = l_Lean_Syntax_getArg(v_x_597_, v___x_604_);
v___x_606_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___closed__1));
lean_inc(v___x_605_);
v___x_607_ = l_Lean_Syntax_isOfKind(v___x_605_, v___x_606_);
if (v___x_607_ == 0)
{
lean_object* v___x_608_; lean_object* v___x_609_; 
lean_dec(v___x_605_);
lean_dec(v_x_597_);
v___x_608_ = lean_box(0);
v___x_609_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_609_, 0, v___x_608_);
lean_ctor_set(v___x_609_, 1, v_a_599_);
return v___x_609_;
}
else
{
lean_object* v___x_610_; lean_object* v___x_611_; lean_object* v___x_612_; uint8_t v___x_613_; 
v___x_610_ = lean_unsigned_to_nat(1u);
v___x_611_ = l_Lean_Syntax_getArg(v_x_597_, v___x_610_);
lean_dec(v_x_597_);
v___x_612_ = lean_unsigned_to_nat(3u);
lean_inc(v___x_611_);
v___x_613_ = l_Lean_Syntax_matchesNull(v___x_611_, v___x_612_);
if (v___x_613_ == 0)
{
lean_object* v___x_614_; lean_object* v___x_615_; 
lean_dec(v___x_611_);
lean_dec(v___x_605_);
v___x_614_ = lean_box(0);
v___x_615_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_615_, 0, v___x_614_);
lean_ctor_set(v___x_615_, 1, v_a_599_);
return v___x_615_;
}
else
{
lean_object* v___x_616_; lean_object* v___x_617_; lean_object* v___x_618_; lean_object* v___x_619_; lean_object* v_ref_620_; uint8_t v___x_621_; lean_object* v___x_622_; lean_object* v___x_623_; lean_object* v___x_624_; lean_object* v___x_625_; lean_object* v___x_626_; lean_object* v___x_627_; lean_object* v___x_628_; lean_object* v___x_629_; lean_object* v___x_630_; lean_object* v___x_631_; 
v___x_616_ = l_Lean_Syntax_getArg(v___x_611_, v___x_604_);
v___x_617_ = l_Lean_Syntax_getArg(v___x_611_, v___x_610_);
v___x_618_ = lean_unsigned_to_nat(2u);
v___x_619_ = l_Lean_Syntax_getArg(v___x_611_, v___x_618_);
lean_dec(v___x_611_);
v_ref_620_ = l_Lean_replaceRef(v___x_605_, v_a_598_);
lean_dec(v___x_605_);
v___x_621_ = 0;
v___x_622_ = l_Lean_SourceInfo_fromRef(v_ref_620_, v___x_621_);
lean_dec(v_ref_620_);
v___x_623_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__3));
v___x_624_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__6));
lean_inc_n(v___x_622_, 3);
v___x_625_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_625_, 0, v___x_622_);
lean_ctor_set(v___x_625_, 1, v___x_624_);
v___x_626_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__12));
v___x_627_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_627_, 0, v___x_622_);
lean_ctor_set(v___x_627_, 1, v___x_626_);
v___x_628_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedExtraction_term___x5b___u21a6___x5d___closed__16));
v___x_629_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_629_, 0, v___x_622_);
lean_ctor_set(v___x_629_, 1, v___x_628_);
v___x_630_ = l_Lean_Syntax_node6(v___x_622_, v___x_623_, v___x_616_, v___x_625_, v___x_617_, v___x_627_, v___x_619_, v___x_629_);
v___x_631_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_631_, 0, v___x_630_);
lean_ctor_set(v___x_631_, 1, v_a_599_);
return v___x_631_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1___boxed(lean_object* v_x_632_, lean_object* v_a_633_, lean_object* v_a_634_){
_start:
{
lean_object* v_res_635_; 
v_res_635_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction___aux__MaxwellKeyPLUS__VerifiedExtraction______unexpand__MaxwellKey__VerifiedExtraction__env__update__1(v_x_632_, v_a_633_, v_a_634_);
lean_dec(v_a_633_);
return v_res_635_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___closed__0(void){
_start:
{
lean_object* v___x_636_; uint8_t v___x_637_; lean_object* v___x_638_; double v___x_639_; 
v___x_636_ = lean_unsigned_to_nat(1u);
v___x_637_ = 1;
v___x_638_ = lean_unsigned_to_nat(10u);
v___x_639_ = l_Float_ofScientific(v___x_638_, v___x_637_, v___x_636_);
return v___x_639_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(lean_object* v_env_640_, lean_object* v_x_641_){
_start:
{
switch(lean_obj_tag(v_x_641_))
{
case 0:
{
double v_v_642_; 
lean_dec_ref(v_env_640_);
v_v_642_ = lean_ctor_get_float(v_x_641_, 0);
lean_dec_ref_known(v_x_641_, 0);
return v_v_642_;
}
case 1:
{
lean_object* v_x_643_; lean_object* v___x_644_; double v___x_645_; 
v_x_643_ = lean_ctor_get(v_x_641_, 0);
lean_inc(v_x_643_);
lean_dec_ref_known(v_x_641_, 1);
v___x_644_ = lean_apply_1(v_env_640_, v_x_643_);
v___x_645_ = lean_unbox_float(v___x_644_);
lean_dec_ref(v___x_644_);
return v___x_645_;
}
case 2:
{
lean_object* v_e1_646_; lean_object* v_e2_647_; double v___x_648_; double v___x_649_; double v___x_650_; 
v_e1_646_ = lean_ctor_get(v_x_641_, 0);
lean_inc_ref(v_e1_646_);
v_e2_647_ = lean_ctor_get(v_x_641_, 1);
lean_inc_ref(v_e2_647_);
lean_dec_ref_known(v_x_641_, 2);
lean_inc_ref(v_env_640_);
v___x_648_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e1_646_);
v___x_649_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e2_647_);
v___x_650_ = lean_float_add(v___x_648_, v___x_649_);
return v___x_650_;
}
case 3:
{
lean_object* v_e1_651_; lean_object* v_e2_652_; double v___x_653_; double v___x_654_; double v___x_655_; 
v_e1_651_ = lean_ctor_get(v_x_641_, 0);
lean_inc_ref(v_e1_651_);
v_e2_652_ = lean_ctor_get(v_x_641_, 1);
lean_inc_ref(v_e2_652_);
lean_dec_ref_known(v_x_641_, 2);
lean_inc_ref(v_env_640_);
v___x_653_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e1_651_);
v___x_654_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e2_652_);
v___x_655_ = lean_float_sub(v___x_653_, v___x_654_);
return v___x_655_;
}
case 4:
{
lean_object* v_e1_656_; lean_object* v_e2_657_; double v___x_658_; double v___x_659_; double v___x_660_; 
v_e1_656_ = lean_ctor_get(v_x_641_, 0);
lean_inc_ref(v_e1_656_);
v_e2_657_ = lean_ctor_get(v_x_641_, 1);
lean_inc_ref(v_e2_657_);
lean_dec_ref_known(v_x_641_, 2);
lean_inc_ref(v_env_640_);
v___x_658_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e1_656_);
v___x_659_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e2_657_);
v___x_660_ = lean_float_mul(v___x_658_, v___x_659_);
return v___x_660_;
}
case 5:
{
lean_object* v_e1_661_; lean_object* v_e2_662_; double v___x_663_; double v___x_664_; double v___x_665_; 
v_e1_661_ = lean_ctor_get(v_x_641_, 0);
lean_inc_ref(v_e1_661_);
v_e2_662_ = lean_ctor_get(v_x_641_, 1);
lean_inc_ref(v_e2_662_);
lean_dec_ref_known(v_x_641_, 2);
lean_inc_ref(v_env_640_);
v___x_663_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e1_661_);
v___x_664_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e2_662_);
v___x_665_ = lean_float_div(v___x_663_, v___x_664_);
return v___x_665_;
}
case 6:
{
lean_object* v_e1_666_; lean_object* v_e2_667_; double v___x_668_; double v___x_669_; uint8_t v___x_670_; 
v_e1_666_ = lean_ctor_get(v_x_641_, 0);
lean_inc_ref(v_e1_666_);
v_e2_667_ = lean_ctor_get(v_x_641_, 1);
lean_inc_ref(v_e2_667_);
lean_dec_ref_known(v_x_641_, 2);
lean_inc_ref(v_env_640_);
v___x_668_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e1_666_);
v___x_669_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e2_667_);
v___x_670_ = lean_float_beq(v___x_668_, v___x_669_);
if (v___x_670_ == 0)
{
double v___x_671_; 
v___x_671_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0);
return v___x_671_;
}
else
{
double v___x_672_; 
v___x_672_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___closed__0);
return v___x_672_;
}
}
case 7:
{
lean_object* v_e1_673_; lean_object* v_e2_674_; double v___x_675_; double v___x_676_; uint8_t v___x_677_; 
v_e1_673_ = lean_ctor_get(v_x_641_, 0);
lean_inc_ref(v_e1_673_);
v_e2_674_ = lean_ctor_get(v_x_641_, 1);
lean_inc_ref(v_e2_674_);
lean_dec_ref_known(v_x_641_, 2);
lean_inc_ref(v_env_640_);
v___x_675_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e1_673_);
v___x_676_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e2_674_);
v___x_677_ = lean_float_decLt(v___x_675_, v___x_676_);
if (v___x_677_ == 0)
{
double v___x_678_; 
v___x_678_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0);
return v___x_678_;
}
else
{
lean_object* v___x_679_; lean_object* v___x_680_; double v___x_681_; 
v___x_679_ = lean_unsigned_to_nat(10u);
v___x_680_ = lean_unsigned_to_nat(1u);
v___x_681_ = l_Float_ofScientific(v___x_679_, v___x_677_, v___x_680_);
return v___x_681_;
}
}
case 8:
{
lean_object* v_e1_682_; lean_object* v_e2_683_; double v___x_684_; double v___x_685_; uint8_t v___x_686_; 
v_e1_682_ = lean_ctor_get(v_x_641_, 0);
lean_inc_ref(v_e1_682_);
v_e2_683_ = lean_ctor_get(v_x_641_, 1);
lean_inc_ref(v_e2_683_);
lean_dec_ref_known(v_x_641_, 2);
lean_inc_ref(v_env_640_);
v___x_684_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e2_683_);
v___x_685_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e1_682_);
v___x_686_ = lean_float_decLt(v___x_684_, v___x_685_);
if (v___x_686_ == 0)
{
double v___x_687_; 
v___x_687_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0);
return v___x_687_;
}
else
{
lean_object* v___x_688_; lean_object* v___x_689_; double v___x_690_; 
v___x_688_ = lean_unsigned_to_nat(10u);
v___x_689_ = lean_unsigned_to_nat(1u);
v___x_690_ = l_Float_ofScientific(v___x_688_, v___x_686_, v___x_689_);
return v___x_690_;
}
}
case 9:
{
lean_object* v_e1_691_; lean_object* v_e2_692_; double v___x_693_; double v___x_694_; uint8_t v___x_695_; 
v_e1_691_ = lean_ctor_get(v_x_641_, 0);
lean_inc_ref(v_e1_691_);
v_e2_692_ = lean_ctor_get(v_x_641_, 1);
lean_inc_ref(v_e2_692_);
lean_dec_ref_known(v_x_641_, 2);
lean_inc_ref(v_env_640_);
v___x_693_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e1_691_);
v___x_694_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e2_692_);
v___x_695_ = lean_float_decLe(v___x_693_, v___x_694_);
if (v___x_695_ == 0)
{
double v___x_696_; 
v___x_696_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0);
return v___x_696_;
}
else
{
lean_object* v___x_697_; lean_object* v___x_698_; double v___x_699_; 
v___x_697_ = lean_unsigned_to_nat(10u);
v___x_698_ = lean_unsigned_to_nat(1u);
v___x_699_ = l_Float_ofScientific(v___x_697_, v___x_695_, v___x_698_);
return v___x_699_;
}
}
default: 
{
lean_object* v_e1_700_; lean_object* v_e2_701_; double v___x_702_; double v___x_703_; uint8_t v___x_704_; 
v_e1_700_ = lean_ctor_get(v_x_641_, 0);
lean_inc_ref(v_e1_700_);
v_e2_701_ = lean_ctor_get(v_x_641_, 1);
lean_inc_ref(v_e2_701_);
lean_dec_ref_known(v_x_641_, 2);
lean_inc_ref(v_env_640_);
v___x_702_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e2_701_);
v___x_703_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_640_, v_e1_700_);
v___x_704_ = lean_float_decLe(v___x_702_, v___x_703_);
if (v___x_704_ == 0)
{
double v___x_705_; 
v___x_705_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0);
return v___x_705_;
}
else
{
lean_object* v___x_706_; lean_object* v___x_707_; double v___x_708_; 
v___x_706_ = lean_unsigned_to_nat(10u);
v___x_707_ = lean_unsigned_to_nat(1u);
v___x_708_ = l_Float_ofScientific(v___x_706_, v___x_704_, v___x_707_);
return v___x_708_;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___boxed(lean_object* v_env_709_, lean_object* v_x_710_){
_start:
{
double v_res_711_; lean_object* v_r_712_; 
v_res_711_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote(v_env_709_, v_x_710_);
v_r_712_ = lean_box_float(v_res_711_);
return v_r_712_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_alpha__c(lean_object* v_z0_713_, lean_object* v_n0_714_){
_start:
{
lean_object* v___x_715_; lean_object* v___x_716_; lean_object* v___x_717_; lean_object* v___x_718_; 
v___x_715_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_715_, 0, v_z0_713_);
lean_inc_ref(v___x_715_);
v___x_716_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_716_, 0, v___x_715_);
lean_ctor_set(v___x_716_, 1, v___x_715_);
v___x_717_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_717_, 0, v_n0_714_);
v___x_718_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_718_, 0, v___x_716_);
lean_ctor_set(v___x_718_, 1, v___x_717_);
return v___x_718_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__0(void){
_start:
{
double v___x_719_; lean_object* v___x_720_; 
v___x_719_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_denote___closed__0);
v___x_720_ = lean_alloc_ctor(0, 0, 8);
lean_ctor_set_float(v___x_720_, 0, v___x_719_);
return v___x_720_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__1(void){
_start:
{
lean_object* v___x_721_; uint8_t v___x_722_; lean_object* v___x_723_; double v___x_724_; 
v___x_721_ = lean_unsigned_to_nat(1u);
v___x_722_ = 1;
v___x_723_ = lean_unsigned_to_nat(20u);
v___x_724_ = l_Float_ofScientific(v___x_723_, v___x_722_, v___x_721_);
return v___x_724_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__2(void){
_start:
{
double v___x_725_; lean_object* v___x_726_; 
v___x_725_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__1, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__1_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__1);
v___x_726_ = lean_alloc_ctor(0, 0, 8);
lean_ctor_set_float(v___x_726_, 0, v___x_725_);
return v___x_726_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c(lean_object* v_alpha_727_, lean_object* v_mself_728_, lean_object* v_mmutual_729_){
_start:
{
lean_object* v___x_730_; lean_object* v___x_731_; lean_object* v___x_732_; lean_object* v___x_733_; lean_object* v___x_734_; lean_object* v___x_735_; lean_object* v___x_736_; lean_object* v___x_737_; lean_object* v_a_738_; lean_object* v___x_739_; lean_object* v___x_740_; lean_object* v___x_741_; lean_object* v_b_742_; lean_object* v___x_743_; lean_object* v___x_744_; lean_object* v___x_745_; 
v___x_730_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__0);
v___x_731_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_731_, 0, v_alpha_727_);
v___x_732_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_732_, 0, v_mself_728_);
lean_inc_ref_n(v___x_732_, 2);
v___x_733_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_733_, 0, v___x_732_);
lean_ctor_set(v___x_733_, 1, v___x_732_);
v___x_734_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_734_, 0, v_mmutual_729_);
lean_inc_ref_n(v___x_734_, 2);
v___x_735_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_735_, 0, v___x_734_);
lean_ctor_set(v___x_735_, 1, v___x_734_);
v___x_736_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_736_, 0, v___x_733_);
lean_ctor_set(v___x_736_, 1, v___x_735_);
lean_inc_ref(v___x_731_);
v___x_737_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_737_, 0, v___x_731_);
lean_ctor_set(v___x_737_, 1, v___x_736_);
v_a_738_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v_a_738_, 0, v___x_730_);
lean_ctor_set(v_a_738_, 1, v___x_737_);
v___x_739_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__2, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__2_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__2);
v___x_740_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_740_, 0, v___x_732_);
lean_ctor_set(v___x_740_, 1, v___x_734_);
v___x_741_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_741_, 0, v___x_739_);
lean_ctor_set(v___x_741_, 1, v___x_740_);
v_b_742_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v_b_742_, 0, v___x_731_);
lean_ctor_set(v_b_742_, 1, v___x_741_);
lean_inc_ref(v_a_738_);
v___x_743_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_743_, 0, v_a_738_);
lean_ctor_set(v___x_743_, 1, v_a_738_);
lean_inc_ref(v_b_742_);
v___x_744_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_744_, 0, v_b_742_);
lean_ctor_set(v___x_744_, 1, v_b_742_);
v___x_745_ = lean_alloc_ctor(3, 2, 0);
lean_ctor_set(v___x_745_, 0, v___x_743_);
lean_ctor_set(v___x_745_, 1, v___x_744_);
return v___x_745_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__eve__c(lean_object* v_alpha_746_, lean_object* v_mself_747_, lean_object* v_mmutual_748_, lean_object* v_f_749_){
_start:
{
lean_object* v___x_750_; lean_object* v___x_751_; lean_object* v___x_752_; lean_object* v___x_753_; lean_object* v___x_754_; lean_object* v___x_755_; lean_object* v___x_756_; lean_object* v___x_757_; lean_object* v___x_758_; lean_object* v___x_759_; lean_object* v___x_760_; 
v___x_750_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_arg__bob__c___closed__0);
v___x_751_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_751_, 0, v_alpha_746_);
v___x_752_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_752_, 0, v_mself_747_);
v___x_753_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_753_, 0, v_mmutual_748_);
v___x_754_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_754_, 0, v___x_752_);
lean_ctor_set(v___x_754_, 1, v___x_753_);
lean_inc_ref(v___x_754_);
v___x_755_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_755_, 0, v___x_754_);
lean_ctor_set(v___x_755_, 1, v___x_754_);
v___x_756_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_756_, 0, v___x_751_);
lean_ctor_set(v___x_756_, 1, v___x_755_);
v___x_757_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_757_, 0, v_f_749_);
lean_inc_ref(v___x_757_);
v___x_758_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_758_, 0, v___x_757_);
lean_ctor_set(v___x_758_, 1, v___x_757_);
v___x_759_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_759_, 0, v___x_756_);
lean_ctor_set(v___x_759_, 1, v___x_758_);
v___x_760_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_760_, 0, v___x_750_);
lean_ctor_set(v___x_760_, 1, v___x_759_);
return v___x_760_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedExtraction_firmware__env(lean_object* v_x_761_){
_start:
{
double v___x_762_; 
v___x_762_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedExtraction_empty__env___closed__0);
return v___x_762_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedExtraction_firmware__env___boxed(lean_object* v_x_763_){
_start:
{
double v_res_764_; lean_object* v_r_765_; 
v_res_764_ = lp_MaxwellKey_MaxwellKey_VerifiedExtraction_firmware__env(v_x_763_);
lean_dec(v_x_763_);
v_r_765_ = lean_box_float(v_res_764_);
return v_r_765_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Data_Real_Basic(uint8_t builtin);
lean_object* initialize_mathlib_Mathlib_Tactic_Ring(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_VerifiedExtraction(uint8_t builtin) {
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
res = initialize_mathlib_Mathlib_Tactic_Ring(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
