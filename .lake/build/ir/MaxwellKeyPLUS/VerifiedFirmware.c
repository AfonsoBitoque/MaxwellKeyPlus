// Lean compiler output
// Module: MaxwellKeyPLUS.VerifiedFirmware
// Imports: public import Init public meta import Init public import MaxwellKeyPLUS.SecrecyCapacityGeneral public import MaxwellKeyPLUS.DegradednessGeneral
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
lean_object* lean_nat_to_int(lean_object*);
lean_object* l_Float_repr(double, lean_object*);
lean_object* lean_string_length(lean_object*);
double lean_float_mul(double, double);
double lean_float_div(double, double);
double lean_float_add(double, double);
uint8_t lean_float_decLt(double, double);
double lean_float_sub(double, double);
double log2(double);
uint8_t lean_float_decLe(double, double);
uint8_t lean_float_beq(double, double);
double lean_float_of_nat(lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_List_range(lean_object*);
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float___closed__0;
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float___closed__0;
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float___closed__0;
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "{ "};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__0 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__0_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "M_self"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__1 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__1_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__1_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__2 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__2_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__2_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__3 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__3_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = " := "};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__4 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__4_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__4_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__5 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__5_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 5}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__3_value),((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__5_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__6 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__6_value;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__7;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = ","};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__8 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__8_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__8_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__9 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__9_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "M_mutual"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__10 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__10_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__10_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__11 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__11_value;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__12_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__12;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 2, .m_data = "Z₀"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__13 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__13_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__13_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__14 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__14_value;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__15_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__15;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "eve_factor"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__16 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__16_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__16_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__17 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__17_value;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__18_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__18;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "N0"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__19 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__19_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__19_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__20 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__20_value;
static const lean_string_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = " }"};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__21 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__21_value;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__22_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__22;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__23_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__23;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__0_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__24 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__24_value;
static const lean_ctor_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__21_value)}};
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__25 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__25_value;
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___boxed(lean_object*, lean_object*);
static const lean_closure_object lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams___closed__0 = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams___closed__0_value;
LEAN_EXPORT const lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams = (const lean_object*)&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams___closed__0_value;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__0;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__1;
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise(double, double, double, double);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_alpha__float(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_alpha__float___boxed(lean_object*);
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1;
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___boxed(lean_object*);
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__eve__float(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__eve__float___boxed(lean_object*);
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___closed__0;
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___boxed(lean_object*);
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__eve__float(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__eve__float___boxed(lean_object*);
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_secrecy__capacity__float(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_secrecy__capacity__float___boxed(lean_object*);
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0;
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__gt__arg__eve(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__gt__arg__eve___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__positive(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__positive___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__eve__positive(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__eve__positive___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__secrecy__positive(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__secrecy__positive___boxed(lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_all__security__checks__pass(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_all__security__checks__pass___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__bob__float(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__bob__float___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__eve__float(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__eve__float___boxed(lean_object*);
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_quad__form__float(lean_object*, double, double);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_quad__form__float___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__0(lean_object*, double, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__1(double, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__float(lean_object*);
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__loewner__check(lean_object*);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__loewner__check___boxed(lean_object*);
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__0;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__1;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__2;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__3;
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__4;
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips;
LEAN_EXPORT uint8_t maxwellkey_check_params(double, double, double, double, double);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__check__params___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT double maxwellkey_secrecy_capacity(double, double, double, double, double);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__secrecy__capacity___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t maxwellkey_loewner_check(double, double, double, double, double);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__loewner__check___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t maxwellkey_exact_channel_check(double, double, double, double, double);
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__exact__channel__check___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__init___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__init___closed__0;
LEAN_EXPORT uint8_t maxwellkey_init;
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float___closed__0(void){
_start:
{
lean_object* v___x_1_; uint8_t v___x_2_; lean_object* v___x_3_; double v___x_4_; 
v___x_1_ = lean_unsigned_to_nat(29u);
v___x_2_ = 1;
v___x_3_ = lean_unsigned_to_nat(1380649u);
v___x_4_ = l_Float_ofScientific(v___x_3_, v___x_2_, v___x_1_);
return v___x_4_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float(void){
_start:
{
double v___x_5_; 
v___x_5_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float___closed__0);
return v___x_5_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float___closed__0(void){
_start:
{
lean_object* v___x_6_; uint8_t v___x_7_; lean_object* v___x_8_; double v___x_9_; 
v___x_6_ = lean_unsigned_to_nat(1u);
v___x_7_ = 1;
v___x_8_ = lean_unsigned_to_nat(2900u);
v___x_9_ = l_Float_ofScientific(v___x_8_, v___x_7_, v___x_6_);
return v___x_9_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float(void){
_start:
{
double v___x_10_; 
v___x_10_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float___closed__0);
return v___x_10_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float___closed__0(void){
_start:
{
lean_object* v___x_11_; uint8_t v___x_12_; lean_object* v___x_13_; double v___x_14_; 
v___x_11_ = lean_unsigned_to_nat(5u);
v___x_12_ = 0;
v___x_13_ = lean_unsigned_to_nat(10u);
v___x_14_ = l_Float_ofScientific(v___x_13_, v___x_12_, v___x_11_);
return v___x_14_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float(void){
_start:
{
double v___x_15_; 
v___x_15_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float___closed__0);
return v___x_15_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__7(void){
_start:
{
lean_object* v___x_29_; lean_object* v___x_30_; 
v___x_29_ = lean_unsigned_to_nat(10u);
v___x_30_ = lean_nat_to_int(v___x_29_);
return v___x_30_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__12(void){
_start:
{
lean_object* v___x_37_; lean_object* v___x_38_; 
v___x_37_ = lean_unsigned_to_nat(12u);
v___x_38_ = lean_nat_to_int(v___x_37_);
return v___x_38_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__15(void){
_start:
{
lean_object* v___x_42_; lean_object* v___x_43_; 
v___x_42_ = lean_unsigned_to_nat(6u);
v___x_43_ = lean_nat_to_int(v___x_42_);
return v___x_43_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__18(void){
_start:
{
lean_object* v___x_47_; lean_object* v___x_48_; 
v___x_47_ = lean_unsigned_to_nat(14u);
v___x_48_ = lean_nat_to_int(v___x_47_);
return v___x_48_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__22(void){
_start:
{
lean_object* v___x_53_; lean_object* v___x_54_; 
v___x_53_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__0));
v___x_54_ = lean_string_length(v___x_53_);
return v___x_54_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__23(void){
_start:
{
lean_object* v___x_55_; lean_object* v___x_56_; 
v___x_55_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__22, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__22_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__22);
v___x_56_ = lean_nat_to_int(v___x_55_);
return v___x_56_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg(lean_object* v_x_61_){
_start:
{
double v_M__self_62_; double v_M__mutual_63_; double v_Z_u2080_64_; double v_eve__factor_65_; double v_N0_66_; lean_object* v___x_67_; lean_object* v___x_68_; lean_object* v___x_69_; lean_object* v___x_70_; lean_object* v___x_71_; lean_object* v___x_72_; uint8_t v___x_73_; lean_object* v___x_74_; lean_object* v___x_75_; lean_object* v___x_76_; lean_object* v___x_77_; lean_object* v___x_78_; lean_object* v___x_79_; lean_object* v___x_80_; lean_object* v___x_81_; lean_object* v___x_82_; lean_object* v___x_83_; lean_object* v___x_84_; lean_object* v___x_85_; lean_object* v___x_86_; lean_object* v___x_87_; lean_object* v___x_88_; lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v___x_91_; lean_object* v___x_92_; lean_object* v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; lean_object* v___x_100_; lean_object* v___x_101_; lean_object* v___x_102_; lean_object* v___x_103_; lean_object* v___x_104_; lean_object* v___x_105_; lean_object* v___x_106_; lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; lean_object* v___x_110_; lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v___x_118_; lean_object* v___x_119_; lean_object* v___x_120_; lean_object* v___x_121_; lean_object* v___x_122_; lean_object* v___x_123_; 
v_M__self_62_ = lean_ctor_get_float(v_x_61_, 0);
v_M__mutual_63_ = lean_ctor_get_float(v_x_61_, 8);
v_Z_u2080_64_ = lean_ctor_get_float(v_x_61_, 16);
v_eve__factor_65_ = lean_ctor_get_float(v_x_61_, 24);
v_N0_66_ = lean_ctor_get_float(v_x_61_, 32);
v___x_67_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__5));
v___x_68_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__6));
v___x_69_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__7, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__7_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__7);
v___x_70_ = lean_unsigned_to_nat(0u);
v___x_71_ = l_Float_repr(v_M__self_62_, v___x_70_);
v___x_72_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_72_, 0, v___x_69_);
lean_ctor_set(v___x_72_, 1, v___x_71_);
v___x_73_ = 0;
v___x_74_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_74_, 0, v___x_72_);
lean_ctor_set_uint8(v___x_74_, sizeof(void*)*1, v___x_73_);
v___x_75_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_75_, 0, v___x_68_);
lean_ctor_set(v___x_75_, 1, v___x_74_);
v___x_76_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__9));
v___x_77_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_77_, 0, v___x_75_);
lean_ctor_set(v___x_77_, 1, v___x_76_);
v___x_78_ = lean_box(1);
v___x_79_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_79_, 0, v___x_77_);
lean_ctor_set(v___x_79_, 1, v___x_78_);
v___x_80_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__11));
v___x_81_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_81_, 0, v___x_79_);
lean_ctor_set(v___x_81_, 1, v___x_80_);
v___x_82_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_82_, 0, v___x_81_);
lean_ctor_set(v___x_82_, 1, v___x_67_);
v___x_83_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__12, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__12_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__12);
v___x_84_ = l_Float_repr(v_M__mutual_63_, v___x_70_);
v___x_85_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_85_, 0, v___x_83_);
lean_ctor_set(v___x_85_, 1, v___x_84_);
v___x_86_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_86_, 0, v___x_85_);
lean_ctor_set_uint8(v___x_86_, sizeof(void*)*1, v___x_73_);
v___x_87_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_87_, 0, v___x_82_);
lean_ctor_set(v___x_87_, 1, v___x_86_);
v___x_88_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_88_, 0, v___x_87_);
lean_ctor_set(v___x_88_, 1, v___x_76_);
v___x_89_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_89_, 0, v___x_88_);
lean_ctor_set(v___x_89_, 1, v___x_78_);
v___x_90_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__14));
v___x_91_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_91_, 0, v___x_89_);
lean_ctor_set(v___x_91_, 1, v___x_90_);
v___x_92_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_92_, 0, v___x_91_);
lean_ctor_set(v___x_92_, 1, v___x_67_);
v___x_93_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__15, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__15_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__15);
v___x_94_ = l_Float_repr(v_Z_u2080_64_, v___x_70_);
v___x_95_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_95_, 0, v___x_93_);
lean_ctor_set(v___x_95_, 1, v___x_94_);
v___x_96_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_96_, 0, v___x_95_);
lean_ctor_set_uint8(v___x_96_, sizeof(void*)*1, v___x_73_);
v___x_97_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_97_, 0, v___x_92_);
lean_ctor_set(v___x_97_, 1, v___x_96_);
v___x_98_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_98_, 0, v___x_97_);
lean_ctor_set(v___x_98_, 1, v___x_76_);
v___x_99_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_99_, 0, v___x_98_);
lean_ctor_set(v___x_99_, 1, v___x_78_);
v___x_100_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__17));
v___x_101_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_101_, 0, v___x_99_);
lean_ctor_set(v___x_101_, 1, v___x_100_);
v___x_102_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_102_, 0, v___x_101_);
lean_ctor_set(v___x_102_, 1, v___x_67_);
v___x_103_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__18, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__18_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__18);
v___x_104_ = l_Float_repr(v_eve__factor_65_, v___x_70_);
v___x_105_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_105_, 0, v___x_103_);
lean_ctor_set(v___x_105_, 1, v___x_104_);
v___x_106_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_106_, 0, v___x_105_);
lean_ctor_set_uint8(v___x_106_, sizeof(void*)*1, v___x_73_);
v___x_107_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_107_, 0, v___x_102_);
lean_ctor_set(v___x_107_, 1, v___x_106_);
v___x_108_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_108_, 0, v___x_107_);
lean_ctor_set(v___x_108_, 1, v___x_76_);
v___x_109_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_109_, 0, v___x_108_);
lean_ctor_set(v___x_109_, 1, v___x_78_);
v___x_110_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__20));
v___x_111_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_111_, 0, v___x_109_);
lean_ctor_set(v___x_111_, 1, v___x_110_);
v___x_112_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_112_, 0, v___x_111_);
lean_ctor_set(v___x_112_, 1, v___x_67_);
v___x_113_ = l_Float_repr(v_N0_66_, v___x_70_);
v___x_114_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_114_, 0, v___x_93_);
lean_ctor_set(v___x_114_, 1, v___x_113_);
v___x_115_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_115_, 0, v___x_114_);
lean_ctor_set_uint8(v___x_115_, sizeof(void*)*1, v___x_73_);
v___x_116_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_116_, 0, v___x_112_);
lean_ctor_set(v___x_116_, 1, v___x_115_);
v___x_117_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__23, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__23_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__23);
v___x_118_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__24));
v___x_119_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_119_, 0, v___x_118_);
lean_ctor_set(v___x_119_, 1, v___x_116_);
v___x_120_ = ((lean_object*)(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___closed__25));
v___x_121_ = lean_alloc_ctor(5, 2, 0);
lean_ctor_set(v___x_121_, 0, v___x_119_);
lean_ctor_set(v___x_121_, 1, v___x_120_);
v___x_122_ = lean_alloc_ctor(4, 2, 0);
lean_ctor_set(v___x_122_, 0, v___x_117_);
lean_ctor_set(v___x_122_, 1, v___x_121_);
v___x_123_ = lean_alloc_ctor(6, 1, 1);
lean_ctor_set(v___x_123_, 0, v___x_122_);
lean_ctor_set_uint8(v___x_123_, sizeof(void*)*1, v___x_73_);
return v___x_123_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg___boxed(lean_object* v_x_124_){
_start:
{
lean_object* v_res_125_; 
v_res_125_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg(v_x_124_);
lean_dec_ref(v_x_124_);
return v_res_125_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr(lean_object* v_x_126_, lean_object* v_prec_127_){
_start:
{
lean_object* v___x_128_; 
v___x_128_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___redArg(v_x_126_);
return v___x_128_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr___boxed(lean_object* v_x_129_, lean_object* v_prec_130_){
_start:
{
lean_object* v_res_131_; 
v_res_131_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_instReprFirmwareParams_repr(v_x_129_, v_prec_130_);
lean_dec(v_prec_130_);
lean_dec_ref(v_x_129_);
return v_res_131_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__0(void){
_start:
{
double v___x_134_; double v___x_135_; double v___x_136_; 
v___x_134_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float;
v___x_135_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float;
v___x_136_ = lean_float_mul(v___x_135_, v___x_134_);
return v___x_136_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__1(void){
_start:
{
double v___x_137_; double v___x_138_; double v___x_139_; 
v___x_137_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float;
v___x_138_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__0);
v___x_139_ = lean_float_mul(v___x_138_, v___x_137_);
return v___x_139_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise(double v_M__self_140_, double v_M__mutual_141_, double v_Z_u2080_142_, double v_eve__factor_143_){
_start:
{
double v___x_144_; lean_object* v___x_145_; 
v___x_144_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__1, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__1_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___closed__1);
v___x_145_ = lean_alloc_ctor(0, 0, 40);
lean_ctor_set_float(v___x_145_, 0, v_M__self_140_);
lean_ctor_set_float(v___x_145_, 8, v_M__mutual_141_);
lean_ctor_set_float(v___x_145_, 16, v_Z_u2080_142_);
lean_ctor_set_float(v___x_145_, 24, v_eve__factor_143_);
lean_ctor_set_float(v___x_145_, 32, v___x_144_);
return v___x_145_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise___boxed(lean_object* v_M__self_146_, lean_object* v_M__mutual_147_, lean_object* v_Z_u2080_148_, lean_object* v_eve__factor_149_){
_start:
{
double v_M__self_boxed_150_; double v_M__mutual_boxed_151_; double v_Z_u2080_boxed_152_; double v_eve__factor_boxed_153_; lean_object* v_res_154_; 
v_M__self_boxed_150_ = lean_unbox_float(v_M__self_146_);
lean_dec_ref(v_M__self_146_);
v_M__mutual_boxed_151_ = lean_unbox_float(v_M__mutual_147_);
lean_dec_ref(v_M__mutual_147_);
v_Z_u2080_boxed_152_ = lean_unbox_float(v_Z_u2080_148_);
lean_dec_ref(v_Z_u2080_148_);
v_eve__factor_boxed_153_ = lean_unbox_float(v_eve__factor_149_);
lean_dec_ref(v_eve__factor_149_);
v_res_154_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise(v_M__self_boxed_150_, v_M__mutual_boxed_151_, v_Z_u2080_boxed_152_, v_eve__factor_boxed_153_);
return v_res_154_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_alpha__float(lean_object* v_p_155_){
_start:
{
double v_Z_u2080_156_; double v_N0_157_; double v___x_158_; double v___x_159_; 
v_Z_u2080_156_ = lean_ctor_get_float(v_p_155_, 16);
v_N0_157_ = lean_ctor_get_float(v_p_155_, 32);
v___x_158_ = lean_float_mul(v_Z_u2080_156_, v_Z_u2080_156_);
v___x_159_ = lean_float_div(v___x_158_, v_N0_157_);
return v___x_159_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_alpha__float___boxed(lean_object* v_p_160_){
_start:
{
double v_res_161_; lean_object* v_r_162_; 
v_res_161_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_alpha__float(v_p_160_);
lean_dec_ref(v_p_160_);
v_r_162_ = lean_box_float(v_res_161_);
return v_r_162_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0(void){
_start:
{
lean_object* v___x_163_; uint8_t v___x_164_; lean_object* v___x_165_; double v___x_166_; 
v___x_163_ = lean_unsigned_to_nat(1u);
v___x_164_ = 1;
v___x_165_ = lean_unsigned_to_nat(10u);
v___x_166_ = l_Float_ofScientific(v___x_165_, v___x_164_, v___x_163_);
return v___x_166_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1(void){
_start:
{
lean_object* v___x_167_; uint8_t v___x_168_; lean_object* v___x_169_; double v___x_170_; 
v___x_167_ = lean_unsigned_to_nat(1u);
v___x_168_ = 1;
v___x_169_ = lean_unsigned_to_nat(20u);
v___x_170_ = l_Float_ofScientific(v___x_169_, v___x_168_, v___x_167_);
return v___x_170_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float(lean_object* v_p_171_){
_start:
{
double v_M__self_172_; double v_M__mutual_173_; double v___x_174_; double v___x_175_; double v___x_176_; double v___x_177_; double v___x_178_; double v___x_179_; double v_a_180_; double v___x_181_; double v___x_182_; double v___x_183_; double v_b_184_; double v___x_185_; double v___x_186_; double v___x_187_; 
v_M__self_172_ = lean_ctor_get_float(v_p_171_, 0);
v_M__mutual_173_ = lean_ctor_get_float(v_p_171_, 8);
v___x_174_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0);
v___x_175_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_alpha__float(v_p_171_);
v___x_176_ = lean_float_mul(v_M__self_172_, v_M__self_172_);
v___x_177_ = lean_float_mul(v_M__mutual_173_, v_M__mutual_173_);
v___x_178_ = lean_float_add(v___x_176_, v___x_177_);
v___x_179_ = lean_float_mul(v___x_175_, v___x_178_);
v_a_180_ = lean_float_add(v___x_174_, v___x_179_);
v___x_181_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1);
v___x_182_ = lean_float_mul(v___x_181_, v_M__self_172_);
v___x_183_ = lean_float_mul(v___x_182_, v_M__mutual_173_);
v_b_184_ = lean_float_mul(v___x_175_, v___x_183_);
v___x_185_ = lean_float_mul(v_a_180_, v_a_180_);
v___x_186_ = lean_float_mul(v_b_184_, v_b_184_);
v___x_187_ = lean_float_sub(v___x_185_, v___x_186_);
return v___x_187_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___boxed(lean_object* v_p_188_){
_start:
{
double v_res_189_; lean_object* v_r_190_; 
v_res_189_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float(v_p_188_);
lean_dec_ref(v_p_188_);
v_r_190_ = lean_box_float(v_res_189_);
return v_r_190_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__eve__float(lean_object* v_p_191_){
_start:
{
double v_M__self_192_; double v_M__mutual_193_; double v_eve__factor_194_; double v___x_195_; double v___x_196_; double v___x_197_; double v___x_198_; double v___x_199_; double v___x_200_; double v___x_201_; double v___x_202_; 
v_M__self_192_ = lean_ctor_get_float(v_p_191_, 0);
v_M__mutual_193_ = lean_ctor_get_float(v_p_191_, 8);
v_eve__factor_194_ = lean_ctor_get_float(v_p_191_, 24);
v___x_195_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0);
v___x_196_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_alpha__float(v_p_191_);
v___x_197_ = lean_float_add(v_M__self_192_, v_M__mutual_193_);
v___x_198_ = lean_float_mul(v___x_197_, v___x_197_);
v___x_199_ = lean_float_mul(v___x_196_, v___x_198_);
v___x_200_ = lean_float_mul(v_eve__factor_194_, v_eve__factor_194_);
v___x_201_ = lean_float_div(v___x_199_, v___x_200_);
v___x_202_ = lean_float_add(v___x_195_, v___x_201_);
return v___x_202_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__eve__float___boxed(lean_object* v_p_203_){
_start:
{
double v_res_204_; lean_object* v_r_205_; 
v_res_204_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__eve__float(v_p_203_);
lean_dec_ref(v_p_203_);
v_r_205_ = lean_box_float(v_res_204_);
return v_r_205_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___closed__0(void){
_start:
{
lean_object* v___x_206_; uint8_t v___x_207_; lean_object* v___x_208_; double v___x_209_; 
v___x_206_ = lean_unsigned_to_nat(1u);
v___x_207_ = 1;
v___x_208_ = lean_unsigned_to_nat(5u);
v___x_209_ = l_Float_ofScientific(v___x_208_, v___x_207_, v___x_206_);
return v___x_209_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float(lean_object* v_p_210_){
_start:
{
double v___x_211_; double v___x_212_; double v___x_213_; double v___x_214_; 
v___x_211_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___closed__0);
v___x_212_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float(v_p_210_);
v___x_213_ = log2(v___x_212_);
v___x_214_ = lean_float_mul(v___x_211_, v___x_213_);
return v___x_214_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___boxed(lean_object* v_p_215_){
_start:
{
double v_res_216_; lean_object* v_r_217_; 
v_res_216_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float(v_p_215_);
lean_dec_ref(v_p_215_);
v_r_217_ = lean_box_float(v_res_216_);
return v_r_217_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__eve__float(lean_object* v_p_218_){
_start:
{
double v___x_219_; double v___x_220_; double v___x_221_; double v___x_222_; 
v___x_219_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float___closed__0);
v___x_220_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__eve__float(v_p_218_);
v___x_221_ = log2(v___x_220_);
v___x_222_ = lean_float_mul(v___x_219_, v___x_221_);
return v___x_222_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__eve__float___boxed(lean_object* v_p_223_){
_start:
{
double v_res_224_; lean_object* v_r_225_; 
v_res_224_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__eve__float(v_p_223_);
lean_dec_ref(v_p_223_);
v_r_225_ = lean_box_float(v_res_224_);
return v_r_225_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_secrecy__capacity__float(lean_object* v_p_226_){
_start:
{
double v___x_227_; double v___x_228_; double v___x_229_; 
v___x_227_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__bob__float(v_p_226_);
v___x_228_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_capacity__eve__float(v_p_226_);
v___x_229_ = lean_float_sub(v___x_227_, v___x_228_);
return v___x_229_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_secrecy__capacity__float___boxed(lean_object* v_p_230_){
_start:
{
double v_res_231_; lean_object* v_r_232_; 
v_res_231_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_secrecy__capacity__float(v_p_230_);
lean_dec_ref(v_p_230_);
v_r_232_ = lean_box_float(v_res_231_);
return v_r_232_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0(void){
_start:
{
lean_object* v___x_233_; uint8_t v___x_234_; lean_object* v___x_235_; double v___x_236_; 
v___x_233_ = lean_unsigned_to_nat(1u);
v___x_234_ = 1;
v___x_235_ = lean_unsigned_to_nat(0u);
v___x_236_ = l_Float_ofScientific(v___x_235_, v___x_234_, v___x_233_);
return v___x_236_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive(lean_object* v_p_237_){
_start:
{
double v___x_238_; double v___x_239_; uint8_t v___x_240_; 
v___x_238_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0);
v___x_239_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_alpha__float(v_p_237_);
v___x_240_ = lean_float_decLt(v___x_238_, v___x_239_);
return v___x_240_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___boxed(lean_object* v_p_241_){
_start:
{
uint8_t v_res_242_; lean_object* v_r_243_; 
v_res_242_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive(v_p_241_);
lean_dec_ref(v_p_241_);
v_r_243_ = lean_box(v_res_242_);
return v_r_243_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__gt__arg__eve(lean_object* v_p_244_){
_start:
{
double v___x_245_; double v___x_246_; uint8_t v___x_247_; 
v___x_245_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__eve__float(v_p_244_);
v___x_246_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float(v_p_244_);
v___x_247_ = lean_float_decLt(v___x_245_, v___x_246_);
return v___x_247_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__gt__arg__eve___boxed(lean_object* v_p_248_){
_start:
{
uint8_t v_res_249_; lean_object* v_r_250_; 
v_res_249_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__gt__arg__eve(v_p_248_);
lean_dec_ref(v_p_248_);
v_r_250_ = lean_box(v_res_249_);
return v_r_250_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__positive(lean_object* v_p_251_){
_start:
{
double v___x_252_; double v___x_253_; uint8_t v___x_254_; 
v___x_252_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0);
v___x_253_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float(v_p_251_);
v___x_254_ = lean_float_decLt(v___x_252_, v___x_253_);
return v___x_254_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__positive___boxed(lean_object* v_p_255_){
_start:
{
uint8_t v_res_256_; lean_object* v_r_257_; 
v_res_256_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__positive(v_p_255_);
lean_dec_ref(v_p_255_);
v_r_257_ = lean_box(v_res_256_);
return v_r_257_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__eve__positive(lean_object* v_p_258_){
_start:
{
double v___x_259_; double v___x_260_; uint8_t v___x_261_; 
v___x_259_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0);
v___x_260_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__eve__float(v_p_258_);
v___x_261_ = lean_float_decLt(v___x_259_, v___x_260_);
return v___x_261_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__eve__positive___boxed(lean_object* v_p_262_){
_start:
{
uint8_t v_res_263_; lean_object* v_r_264_; 
v_res_263_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__eve__positive(v_p_262_);
lean_dec_ref(v_p_262_);
v_r_264_ = lean_box(v_res_263_);
return v_r_264_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__secrecy__positive(lean_object* v_p_265_){
_start:
{
double v___x_266_; double v___x_267_; uint8_t v___x_268_; 
v___x_266_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0);
v___x_267_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_secrecy__capacity__float(v_p_265_);
v___x_268_ = lean_float_decLt(v___x_266_, v___x_267_);
return v___x_268_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__secrecy__positive___boxed(lean_object* v_p_269_){
_start:
{
uint8_t v_res_270_; lean_object* v_r_271_; 
v_res_270_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__secrecy__positive(v_p_269_);
lean_dec_ref(v_p_269_);
v_r_271_ = lean_box(v_res_270_);
return v_r_271_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_all__security__checks__pass(lean_object* v_p_272_){
_start:
{
uint8_t v___y_274_; uint8_t v___x_278_; 
v___x_278_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive(v_p_272_);
if (v___x_278_ == 0)
{
v___y_274_ = v___x_278_;
goto v___jp_273_;
}
else
{
uint8_t v___x_279_; 
v___x_279_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__positive(v_p_272_);
v___y_274_ = v___x_279_;
goto v___jp_273_;
}
v___jp_273_:
{
if (v___y_274_ == 0)
{
return v___y_274_;
}
else
{
uint8_t v___x_275_; 
v___x_275_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__eve__positive(v_p_272_);
if (v___x_275_ == 0)
{
return v___x_275_;
}
else
{
uint8_t v___x_276_; 
v___x_276_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__arg__bob__gt__arg__eve(v_p_272_);
if (v___x_276_ == 0)
{
return v___x_276_;
}
else
{
uint8_t v___x_277_; 
v___x_277_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__secrecy__positive(v_p_272_);
return v___x_277_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_all__security__checks__pass___boxed(lean_object* v_p_280_){
_start:
{
uint8_t v_res_281_; lean_object* v_r_282_; 
v_res_281_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_all__security__checks__pass(v_p_280_);
lean_dec_ref(v_p_280_);
v_r_282_ = lean_box(v_res_281_);
return v_r_282_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__bob__float(lean_object* v_p_283_){
_start:
{
double v_M__self_284_; double v_M__mutual_285_; double v_Z_u2080_286_; double v_Z0sq_287_; double v___x_288_; double v___x_289_; double v___x_290_; double v___x_291_; double v___x_292_; double v___x_293_; double v___x_294_; double v___x_295_; lean_object* v___x_296_; 
v_M__self_284_ = lean_ctor_get_float(v_p_283_, 0);
v_M__mutual_285_ = lean_ctor_get_float(v_p_283_, 8);
v_Z_u2080_286_ = lean_ctor_get_float(v_p_283_, 16);
v_Z0sq_287_ = lean_float_mul(v_Z_u2080_286_, v_Z_u2080_286_);
v___x_288_ = lean_float_mul(v_M__self_284_, v_M__self_284_);
v___x_289_ = lean_float_mul(v_M__mutual_285_, v_M__mutual_285_);
v___x_290_ = lean_float_add(v___x_288_, v___x_289_);
v___x_291_ = lean_float_mul(v_Z0sq_287_, v___x_290_);
v___x_292_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1);
v___x_293_ = lean_float_mul(v___x_292_, v_M__self_284_);
v___x_294_ = lean_float_mul(v___x_293_, v_M__mutual_285_);
v___x_295_ = lean_float_mul(v_Z0sq_287_, v___x_294_);
v___x_296_ = lean_alloc_ctor(0, 0, 16);
lean_ctor_set_float(v___x_296_, 0, v___x_291_);
lean_ctor_set_float(v___x_296_, 8, v___x_295_);
return v___x_296_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__bob__float___boxed(lean_object* v_p_297_){
_start:
{
lean_object* v_res_298_; 
v_res_298_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__bob__float(v_p_297_);
lean_dec_ref(v_p_297_);
return v_res_298_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__eve__float(lean_object* v_p_299_){
_start:
{
double v_M__self_300_; double v_M__mutual_301_; double v_Z_u2080_302_; double v_eve__factor_303_; double v_Z0sq_304_; double v___x_305_; double v___x_306_; double v___x_307_; double v___x_308_; double v_scalar_309_; double v___x_310_; lean_object* v___x_311_; 
v_M__self_300_ = lean_ctor_get_float(v_p_299_, 0);
v_M__mutual_301_ = lean_ctor_get_float(v_p_299_, 8);
v_Z_u2080_302_ = lean_ctor_get_float(v_p_299_, 16);
v_eve__factor_303_ = lean_ctor_get_float(v_p_299_, 24);
v_Z0sq_304_ = lean_float_mul(v_Z_u2080_302_, v_Z_u2080_302_);
v___x_305_ = lean_float_add(v_M__self_300_, v_M__mutual_301_);
v___x_306_ = lean_float_mul(v___x_305_, v___x_305_);
v___x_307_ = lean_float_mul(v_Z0sq_304_, v___x_306_);
v___x_308_ = lean_float_mul(v_eve__factor_303_, v_eve__factor_303_);
v_scalar_309_ = lean_float_div(v___x_307_, v___x_308_);
v___x_310_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0);
v___x_311_ = lean_alloc_ctor(0, 0, 16);
lean_ctor_set_float(v___x_311_, 0, v_scalar_309_);
lean_ctor_set_float(v___x_311_, 8, v___x_310_);
return v___x_311_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__eve__float___boxed(lean_object* v_p_312_){
_start:
{
lean_object* v_res_313_; 
v_res_313_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__eve__float(v_p_312_);
lean_dec_ref(v_p_312_);
return v_res_313_;
}
}
LEAN_EXPORT double lp_MaxwellKey_MaxwellKey_VerifiedFirmware_quad__form__float(lean_object* v_S_314_, double v_x0_315_, double v_x1_316_){
_start:
{
double v_a_317_; double v_b_318_; double v___x_319_; double v___x_320_; double v___x_321_; double v___x_322_; double v___x_323_; double v___x_324_; double v___x_325_; double v___x_326_; double v___x_327_; 
v_a_317_ = lean_ctor_get_float(v_S_314_, 0);
v_b_318_ = lean_ctor_get_float(v_S_314_, 8);
v___x_319_ = lean_float_mul(v_x0_315_, v_x0_315_);
v___x_320_ = lean_float_mul(v_x1_316_, v_x1_316_);
v___x_321_ = lean_float_add(v___x_319_, v___x_320_);
v___x_322_ = lean_float_mul(v_a_317_, v___x_321_);
v___x_323_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__1);
v___x_324_ = lean_float_mul(v___x_323_, v_b_318_);
v___x_325_ = lean_float_mul(v___x_324_, v_x0_315_);
v___x_326_ = lean_float_mul(v___x_325_, v_x1_316_);
v___x_327_ = lean_float_add(v___x_322_, v___x_326_);
return v___x_327_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_quad__form__float___boxed(lean_object* v_S_328_, lean_object* v_x0_329_, lean_object* v_x1_330_){
_start:
{
double v_x0_boxed_331_; double v_x1_boxed_332_; double v_res_333_; lean_object* v_r_334_; 
v_x0_boxed_331_ = lean_unbox_float(v_x0_329_);
lean_dec_ref(v_x0_329_);
v_x1_boxed_332_ = lean_unbox_float(v_x1_330_);
lean_dec_ref(v_x1_330_);
v_res_333_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_quad__form__float(v_S_328_, v_x0_boxed_331_, v_x1_boxed_332_);
lean_dec_ref(v_S_328_);
v_r_334_ = lean_box_float(v_res_333_);
return v_r_334_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__0(lean_object* v_i_335_, double v_n_336_, lean_object* v_B_337_, lean_object* v_A_338_, lean_object* v_x_339_){
_start:
{
if (lean_obj_tag(v_x_339_) == 0)
{
uint8_t v___x_340_; 
lean_dec(v_i_335_);
v___x_340_ = 1;
return v___x_340_;
}
else
{
lean_object* v_head_341_; lean_object* v_tail_342_; double v___x_343_; double v_x0_344_; double v___x_345_; double v_x1_346_; double v___x_347_; double v___x_348_; uint8_t v___x_349_; 
v_head_341_ = lean_ctor_get(v_x_339_, 0);
lean_inc(v_head_341_);
v_tail_342_ = lean_ctor_get(v_x_339_, 1);
lean_inc(v_tail_342_);
lean_dec_ref_known(v_x_339_, 2);
lean_inc(v_i_335_);
v___x_343_ = lean_float_of_nat(v_i_335_);
v_x0_344_ = lean_float_div(v___x_343_, v_n_336_);
v___x_345_ = lean_float_of_nat(v_head_341_);
v_x1_346_ = lean_float_div(v___x_345_, v_n_336_);
v___x_347_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_quad__form__float(v_B_337_, v_x0_344_, v_x1_346_);
v___x_348_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_quad__form__float(v_A_338_, v_x0_344_, v_x1_346_);
v___x_349_ = lean_float_decLe(v___x_347_, v___x_348_);
if (v___x_349_ == 0)
{
lean_dec(v_tail_342_);
lean_dec(v_i_335_);
return v___x_349_;
}
else
{
v_x_339_ = v_tail_342_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__0___boxed(lean_object* v_i_351_, lean_object* v_n_352_, lean_object* v_B_353_, lean_object* v_A_354_, lean_object* v_x_355_){
_start:
{
double v_n_boxed_356_; uint8_t v_res_357_; lean_object* v_r_358_; 
v_n_boxed_356_ = lean_unbox_float(v_n_352_);
lean_dec_ref(v_n_352_);
v_res_357_ = lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__0(v_i_351_, v_n_boxed_356_, v_B_353_, v_A_354_, v_x_355_);
lean_dec_ref(v_A_354_);
lean_dec_ref(v_B_353_);
v_r_358_ = lean_box(v_res_357_);
return v_r_358_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__1(double v_n_359_, lean_object* v_B_360_, lean_object* v_A_361_, lean_object* v___x_362_, lean_object* v_x_363_){
_start:
{
if (lean_obj_tag(v_x_363_) == 0)
{
uint8_t v___x_364_; 
lean_dec(v___x_362_);
v___x_364_ = 1;
return v___x_364_;
}
else
{
lean_object* v_head_365_; lean_object* v_tail_366_; uint8_t v___x_367_; 
v_head_365_ = lean_ctor_get(v_x_363_, 0);
lean_inc(v_head_365_);
v_tail_366_ = lean_ctor_get(v_x_363_, 1);
lean_inc(v_tail_366_);
lean_dec_ref_known(v_x_363_, 2);
lean_inc(v___x_362_);
v___x_367_ = lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__0(v_head_365_, v_n_359_, v_B_360_, v_A_361_, v___x_362_);
if (v___x_367_ == 0)
{
lean_dec(v_tail_366_);
lean_dec(v___x_362_);
return v___x_367_;
}
else
{
v_x_363_ = v_tail_366_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__1___boxed(lean_object* v_n_369_, lean_object* v_B_370_, lean_object* v_A_371_, lean_object* v___x_372_, lean_object* v_x_373_){
_start:
{
double v_n_boxed_374_; uint8_t v_res_375_; lean_object* v_r_376_; 
v_n_boxed_374_ = lean_unbox_float(v_n_369_);
lean_dec_ref(v_n_369_);
v_res_375_ = lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__1(v_n_boxed_374_, v_B_370_, v_A_371_, v___x_372_, v_x_373_);
lean_dec_ref(v_A_371_);
lean_dec_ref(v_B_370_);
v_r_376_ = lean_box(v_res_375_);
return v_r_376_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid(lean_object* v_A_377_, lean_object* v_B_378_, lean_object* v_gridSize_379_){
_start:
{
double v_n_380_; lean_object* v___x_381_; lean_object* v___x_382_; lean_object* v___x_383_; uint8_t v___x_384_; 
lean_inc(v_gridSize_379_);
v_n_380_ = lean_float_of_nat(v_gridSize_379_);
v___x_381_ = lean_unsigned_to_nat(1u);
v___x_382_ = lean_nat_add(v_gridSize_379_, v___x_381_);
lean_dec(v_gridSize_379_);
v___x_383_ = l_List_range(v___x_382_);
lean_inc(v___x_383_);
v___x_384_ = lp_MaxwellKey_List_all___at___00MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid_spec__1(v_n_380_, v_B_378_, v_A_377_, v___x_383_, v___x_383_);
return v___x_384_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid___boxed(lean_object* v_A_385_, lean_object* v_B_386_, lean_object* v_gridSize_387_){
_start:
{
uint8_t v_res_388_; lean_object* v_r_389_; 
v_res_388_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float__grid(v_A_385_, v_B_386_, v_gridSize_387_);
lean_dec_ref(v_B_386_);
lean_dec_ref(v_A_385_);
v_r_389_ = lean_box(v_res_388_);
return v_r_389_;
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float(lean_object* v_A_390_, lean_object* v_B_391_){
_start:
{
double v_a_392_; double v_b_393_; double v_a_394_; double v_b_395_; double v_d__a_396_; double v_d__b_397_; lean_object* v___x_398_; lean_object* v___x_399_; double v___x_400_; double v___x_401_; uint8_t v___x_402_; 
v_a_392_ = lean_ctor_get_float(v_A_390_, 0);
v_b_393_ = lean_ctor_get_float(v_A_390_, 8);
v_a_394_ = lean_ctor_get_float(v_B_391_, 0);
v_b_395_ = lean_ctor_get_float(v_B_391_, 8);
v_d__a_396_ = lean_float_sub(v_a_392_, v_a_394_);
v_d__b_397_ = lean_float_sub(v_b_393_, v_b_395_);
v___x_398_ = lean_unsigned_to_nat(0u);
v___x_399_ = lean_unsigned_to_nat(1u);
v___x_400_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0);
v___x_401_ = lean_float_add(v_d__a_396_, v_d__b_397_);
v___x_402_ = lean_float_decLe(v___x_400_, v___x_401_);
if (v___x_402_ == 0)
{
return v___x_402_;
}
else
{
double v___x_403_; double v___x_404_; uint8_t v___x_405_; 
v___x_403_ = l_Float_ofScientific(v___x_398_, v___x_402_, v___x_399_);
v___x_404_ = lean_float_sub(v_d__a_396_, v_d__b_397_);
v___x_405_ = lean_float_decLe(v___x_403_, v___x_404_);
return v___x_405_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float___boxed(lean_object* v_A_406_, lean_object* v_B_407_){
_start:
{
uint8_t v_res_408_; lean_object* v_r_409_; 
v_res_408_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float(v_A_406_, v_B_407_);
lean_dec_ref(v_B_407_);
lean_dec_ref(v_A_406_);
v_r_409_ = lean_box(v_res_408_);
return v_r_409_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__float(lean_object* v_S_410_){
_start:
{
double v_a_411_; double v_b_412_; lean_object* v___x_414_; uint8_t v_isShared_415_; uint8_t v_isSharedCheck_431_; 
v_a_411_ = lean_ctor_get_float(v_S_410_, 0);
v_b_412_ = lean_ctor_get_float(v_S_410_, 8);
v_isSharedCheck_431_ = !lean_is_exclusive(v_S_410_);
if (v_isSharedCheck_431_ == 0)
{
v___x_414_ = v_S_410_;
v_isShared_415_ = v_isSharedCheck_431_;
goto v_resetjp_413_;
}
else
{
lean_dec(v_S_410_);
v___x_414_ = lean_box(0);
v_isShared_415_ = v_isSharedCheck_431_;
goto v_resetjp_413_;
}
v_resetjp_413_:
{
double v___x_416_; double v___x_417_; double v___x_418_; double v___x_419_; double v_det_420_; double v___x_421_; uint8_t v___x_422_; 
v___x_416_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_arg__bob__float___closed__0);
v___x_417_ = lean_float_add(v___x_416_, v_a_411_);
v___x_418_ = lean_float_mul(v___x_417_, v___x_417_);
v___x_419_ = lean_float_mul(v_b_412_, v_b_412_);
v_det_420_ = lean_float_sub(v___x_418_, v___x_419_);
v___x_421_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_check__alpha__positive___closed__0);
v___x_422_ = lean_float_beq(v_det_420_, v___x_421_);
if (v___x_422_ == 0)
{
double v_p_423_; double v_q_424_; double v___x_425_; lean_object* v___x_427_; 
v_p_423_ = lean_float_div(v___x_417_, v_det_420_);
v_q_424_ = lean_float_div(v_b_412_, v_det_420_);
v___x_425_ = lean_float_sub(v___x_416_, v_p_423_);
if (v_isShared_415_ == 0)
{
v___x_427_ = v___x_414_;
goto v_reusejp_426_;
}
else
{
lean_object* v_reuseFailAlloc_429_; 
v_reuseFailAlloc_429_ = lean_alloc_ctor(0, 0, 16);
v___x_427_ = v_reuseFailAlloc_429_;
goto v_reusejp_426_;
}
v_reusejp_426_:
{
lean_object* v___x_428_; 
lean_ctor_set_float(v___x_427_, 0, v___x_425_);
lean_ctor_set_float(v___x_427_, 8, v_q_424_);
v___x_428_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_428_, 0, v___x_427_);
return v___x_428_;
}
}
else
{
lean_object* v___x_430_; 
lean_del_object(v___x_414_);
v___x_430_ = lean_box(0);
return v___x_430_;
}
}
}
}
LEAN_EXPORT uint8_t lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__loewner__check(lean_object* v_p_432_){
_start:
{
lean_object* v___x_433_; lean_object* v___x_434_; 
v___x_433_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__bob__float(v_p_432_);
v___x_434_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__float(v___x_433_);
if (lean_obj_tag(v___x_434_) == 1)
{
lean_object* v_val_435_; lean_object* v___x_436_; lean_object* v___x_437_; 
v_val_435_ = lean_ctor_get(v___x_434_, 0);
lean_inc(v_val_435_);
lean_dec_ref_known(v___x_434_, 1);
v___x_436_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__eve__float(v_p_432_);
v___x_437_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__float(v___x_436_);
if (lean_obj_tag(v___x_437_) == 1)
{
lean_object* v_val_438_; uint8_t v___x_439_; 
v_val_438_ = lean_ctor_get(v___x_437_, 0);
lean_inc(v_val_438_);
lean_dec_ref_known(v___x_437_, 1);
v___x_439_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float(v_val_435_, v_val_438_);
lean_dec(v_val_438_);
lean_dec(v_val_435_);
return v___x_439_;
}
else
{
uint8_t v___x_440_; 
lean_dec(v___x_437_);
lean_dec(v_val_435_);
v___x_440_ = 0;
return v___x_440_;
}
}
else
{
uint8_t v___x_441_; 
lean_dec(v___x_434_);
v___x_441_ = 0;
return v___x_441_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__loewner__check___boxed(lean_object* v_p_442_){
_start:
{
uint8_t v_res_443_; lean_object* v_r_444_; 
v_res_443_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__loewner__check(v_p_442_);
lean_dec_ref(v_p_442_);
v_r_444_ = lean_box(v_res_443_);
return v_r_444_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__0(void){
_start:
{
lean_object* v___x_445_; uint8_t v___x_446_; lean_object* v___x_447_; double v___x_448_; 
v___x_445_ = lean_unsigned_to_nat(18u);
v___x_446_ = 1;
v___x_447_ = lean_cstr_to_nat("3109761664971414");
v___x_448_ = l_Float_ofScientific(v___x_447_, v___x_446_, v___x_445_);
return v___x_448_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__1(void){
_start:
{
lean_object* v___x_449_; uint8_t v___x_450_; lean_object* v___x_451_; double v___x_452_; 
v___x_449_ = lean_unsigned_to_nat(21u);
v___x_450_ = 1;
v___x_451_ = lean_cstr_to_nat("4150620831811415");
v___x_452_ = l_Float_ofScientific(v___x_451_, v___x_450_, v___x_449_);
return v___x_452_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__2(void){
_start:
{
lean_object* v___x_453_; uint8_t v___x_454_; lean_object* v___x_455_; double v___x_456_; 
v___x_453_ = lean_unsigned_to_nat(1u);
v___x_454_ = 1;
v___x_455_ = lean_unsigned_to_nat(500u);
v___x_456_ = l_Float_ofScientific(v___x_455_, v___x_454_, v___x_453_);
return v___x_456_;
}
}
static double _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__3(void){
_start:
{
lean_object* v___x_457_; uint8_t v___x_458_; lean_object* v___x_459_; double v___x_460_; 
v___x_457_ = lean_unsigned_to_nat(1u);
v___x_458_ = 1;
v___x_459_ = lean_unsigned_to_nat(50u);
v___x_460_ = l_Float_ofScientific(v___x_459_, v___x_458_, v___x_457_);
return v___x_460_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__4(void){
_start:
{
double v___x_461_; double v___x_462_; double v___x_463_; double v___x_464_; lean_object* v___x_465_; 
v___x_461_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__3, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__3_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__3);
v___x_462_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__2, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__2_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__2);
v___x_463_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__1, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__1_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__1);
v___x_464_ = lean_float_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__0);
v___x_465_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_FirmwareParams_withThermalNoise(v___x_464_, v___x_463_, v___x_462_, v___x_461_);
return v___x_465_;
}
}
static lean_object* _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips(void){
_start:
{
lean_object* v___x_466_; 
v___x_466_ = lean_obj_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__4, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__4_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips___closed__4);
return v___x_466_;
}
}
LEAN_EXPORT uint8_t maxwellkey_check_params(double v_M__self_467_, double v_M__mutual_468_, double v_Z_u2080_469_, double v_eve__factor_470_, double v_N0_471_){
_start:
{
lean_object* v_p_472_; uint8_t v___x_473_; 
v_p_472_ = lean_alloc_ctor(0, 0, 40);
lean_ctor_set_float(v_p_472_, 0, v_M__self_467_);
lean_ctor_set_float(v_p_472_, 8, v_M__mutual_468_);
lean_ctor_set_float(v_p_472_, 16, v_Z_u2080_469_);
lean_ctor_set_float(v_p_472_, 24, v_eve__factor_470_);
lean_ctor_set_float(v_p_472_, 32, v_N0_471_);
v___x_473_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_all__security__checks__pass(v_p_472_);
lean_dec_ref_known(v_p_472_, 0);
if (v___x_473_ == 0)
{
uint8_t v___x_474_; 
v___x_474_ = 0;
return v___x_474_;
}
else
{
uint8_t v___x_475_; 
v___x_475_ = 1;
return v___x_475_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__check__params___boxed(lean_object* v_M__self_476_, lean_object* v_M__mutual_477_, lean_object* v_Z_u2080_478_, lean_object* v_eve__factor_479_, lean_object* v_N0_480_){
_start:
{
double v_M__self_boxed_481_; double v_M__mutual_boxed_482_; double v_Z_u2080_boxed_483_; double v_eve__factor_boxed_484_; double v_N0_boxed_485_; uint8_t v_res_486_; lean_object* v_r_487_; 
v_M__self_boxed_481_ = lean_unbox_float(v_M__self_476_);
lean_dec_ref(v_M__self_476_);
v_M__mutual_boxed_482_ = lean_unbox_float(v_M__mutual_477_);
lean_dec_ref(v_M__mutual_477_);
v_Z_u2080_boxed_483_ = lean_unbox_float(v_Z_u2080_478_);
lean_dec_ref(v_Z_u2080_478_);
v_eve__factor_boxed_484_ = lean_unbox_float(v_eve__factor_479_);
lean_dec_ref(v_eve__factor_479_);
v_N0_boxed_485_ = lean_unbox_float(v_N0_480_);
lean_dec_ref(v_N0_480_);
v_res_486_ = maxwellkey_check_params(v_M__self_boxed_481_, v_M__mutual_boxed_482_, v_Z_u2080_boxed_483_, v_eve__factor_boxed_484_, v_N0_boxed_485_);
v_r_487_ = lean_box(v_res_486_);
return v_r_487_;
}
}
LEAN_EXPORT double maxwellkey_secrecy_capacity(double v_M__self_488_, double v_M__mutual_489_, double v_Z_u2080_490_, double v_eve__factor_491_, double v_N0_492_){
_start:
{
lean_object* v_p_493_; double v___x_494_; 
v_p_493_ = lean_alloc_ctor(0, 0, 40);
lean_ctor_set_float(v_p_493_, 0, v_M__self_488_);
lean_ctor_set_float(v_p_493_, 8, v_M__mutual_489_);
lean_ctor_set_float(v_p_493_, 16, v_Z_u2080_490_);
lean_ctor_set_float(v_p_493_, 24, v_eve__factor_491_);
lean_ctor_set_float(v_p_493_, 32, v_N0_492_);
v___x_494_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_secrecy__capacity__float(v_p_493_);
lean_dec_ref_known(v_p_493_, 0);
return v___x_494_;
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__secrecy__capacity___boxed(lean_object* v_M__self_495_, lean_object* v_M__mutual_496_, lean_object* v_Z_u2080_497_, lean_object* v_eve__factor_498_, lean_object* v_N0_499_){
_start:
{
double v_M__self_boxed_500_; double v_M__mutual_boxed_501_; double v_Z_u2080_boxed_502_; double v_eve__factor_boxed_503_; double v_N0_boxed_504_; double v_res_505_; lean_object* v_r_506_; 
v_M__self_boxed_500_ = lean_unbox_float(v_M__self_495_);
lean_dec_ref(v_M__self_495_);
v_M__mutual_boxed_501_ = lean_unbox_float(v_M__mutual_496_);
lean_dec_ref(v_M__mutual_496_);
v_Z_u2080_boxed_502_ = lean_unbox_float(v_Z_u2080_497_);
lean_dec_ref(v_Z_u2080_497_);
v_eve__factor_boxed_503_ = lean_unbox_float(v_eve__factor_498_);
lean_dec_ref(v_eve__factor_498_);
v_N0_boxed_504_ = lean_unbox_float(v_N0_499_);
lean_dec_ref(v_N0_499_);
v_res_505_ = maxwellkey_secrecy_capacity(v_M__self_boxed_500_, v_M__mutual_boxed_501_, v_Z_u2080_boxed_502_, v_eve__factor_boxed_503_, v_N0_boxed_504_);
v_r_506_ = lean_box_float(v_res_505_);
return v_r_506_;
}
}
LEAN_EXPORT uint8_t maxwellkey_loewner_check(double v_M__self_507_, double v_M__mutual_508_, double v_Z_u2080_509_, double v_eve__factor_510_, double v_N0_511_){
_start:
{
lean_object* v_p_512_; lean_object* v___x_513_; lean_object* v___x_514_; uint8_t v___x_515_; 
v_p_512_ = lean_alloc_ctor(0, 0, 40);
lean_ctor_set_float(v_p_512_, 0, v_M__self_507_);
lean_ctor_set_float(v_p_512_, 8, v_M__mutual_508_);
lean_ctor_set_float(v_p_512_, 16, v_Z_u2080_509_);
lean_ctor_set_float(v_p_512_, 24, v_eve__factor_510_);
lean_ctor_set_float(v_p_512_, 32, v_N0_511_);
v___x_513_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__bob__float(v_p_512_);
v___x_514_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_S__eve__float(v_p_512_);
lean_dec_ref_known(v_p_512_, 0);
v___x_515_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_loewner__le__check__float(v___x_513_, v___x_514_);
lean_dec_ref(v___x_514_);
lean_dec_ref(v___x_513_);
if (v___x_515_ == 0)
{
uint8_t v___x_516_; 
v___x_516_ = 0;
return v___x_516_;
}
else
{
uint8_t v___x_517_; 
v___x_517_ = 1;
return v___x_517_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__loewner__check___boxed(lean_object* v_M__self_518_, lean_object* v_M__mutual_519_, lean_object* v_Z_u2080_520_, lean_object* v_eve__factor_521_, lean_object* v_N0_522_){
_start:
{
double v_M__self_boxed_523_; double v_M__mutual_boxed_524_; double v_Z_u2080_boxed_525_; double v_eve__factor_boxed_526_; double v_N0_boxed_527_; uint8_t v_res_528_; lean_object* v_r_529_; 
v_M__self_boxed_523_ = lean_unbox_float(v_M__self_518_);
lean_dec_ref(v_M__self_518_);
v_M__mutual_boxed_524_ = lean_unbox_float(v_M__mutual_519_);
lean_dec_ref(v_M__mutual_519_);
v_Z_u2080_boxed_525_ = lean_unbox_float(v_Z_u2080_520_);
lean_dec_ref(v_Z_u2080_520_);
v_eve__factor_boxed_526_ = lean_unbox_float(v_eve__factor_521_);
lean_dec_ref(v_eve__factor_521_);
v_N0_boxed_527_ = lean_unbox_float(v_N0_522_);
lean_dec_ref(v_N0_522_);
v_res_528_ = maxwellkey_loewner_check(v_M__self_boxed_523_, v_M__mutual_boxed_524_, v_Z_u2080_boxed_525_, v_eve__factor_boxed_526_, v_N0_boxed_527_);
v_r_529_ = lean_box(v_res_528_);
return v_r_529_;
}
}
LEAN_EXPORT uint8_t maxwellkey_exact_channel_check(double v_M__self_530_, double v_M__mutual_531_, double v_Z_u2080_532_, double v_eve__factor_533_, double v_N0_534_){
_start:
{
lean_object* v_p_535_; uint8_t v___x_536_; 
v_p_535_ = lean_alloc_ctor(0, 0, 40);
lean_ctor_set_float(v_p_535_, 0, v_M__self_530_);
lean_ctor_set_float(v_p_535_, 8, v_M__mutual_531_);
lean_ctor_set_float(v_p_535_, 16, v_Z_u2080_532_);
lean_ctor_set_float(v_p_535_, 24, v_eve__factor_533_);
lean_ctor_set_float(v_p_535_, 32, v_N0_534_);
v___x_536_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_exact__channel__loewner__check(v_p_535_);
lean_dec_ref_known(v_p_535_, 0);
if (v___x_536_ == 0)
{
uint8_t v___x_537_; 
v___x_537_ = 0;
return v___x_537_;
}
else
{
uint8_t v___x_538_; 
v___x_538_ = 1;
return v___x_538_;
}
}
}
LEAN_EXPORT lean_object* lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__exact__channel__check___boxed(lean_object* v_M__self_539_, lean_object* v_M__mutual_540_, lean_object* v_Z_u2080_541_, lean_object* v_eve__factor_542_, lean_object* v_N0_543_){
_start:
{
double v_M__self_boxed_544_; double v_M__mutual_boxed_545_; double v_Z_u2080_boxed_546_; double v_eve__factor_boxed_547_; double v_N0_boxed_548_; uint8_t v_res_549_; lean_object* v_r_550_; 
v_M__self_boxed_544_ = lean_unbox_float(v_M__self_539_);
lean_dec_ref(v_M__self_539_);
v_M__mutual_boxed_545_ = lean_unbox_float(v_M__mutual_540_);
lean_dec_ref(v_M__mutual_540_);
v_Z_u2080_boxed_546_ = lean_unbox_float(v_Z_u2080_541_);
lean_dec_ref(v_Z_u2080_541_);
v_eve__factor_boxed_547_ = lean_unbox_float(v_eve__factor_542_);
lean_dec_ref(v_eve__factor_542_);
v_N0_boxed_548_ = lean_unbox_float(v_N0_543_);
lean_dec_ref(v_N0_543_);
v_res_549_ = maxwellkey_exact_channel_check(v_M__self_boxed_544_, v_M__mutual_boxed_545_, v_Z_u2080_boxed_546_, v_eve__factor_boxed_547_, v_N0_boxed_548_);
v_r_550_ = lean_box(v_res_549_);
return v_r_550_;
}
}
static uint8_t _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__init___closed__0(void){
_start:
{
lean_object* v___x_551_; uint8_t v___x_552_; 
v___x_551_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips;
v___x_552_ = lp_MaxwellKey_MaxwellKey_VerifiedFirmware_all__security__checks__pass(v___x_551_);
return v___x_552_;
}
}
static uint8_t _init_maxwellkey_init(void){
_start:
{
uint8_t v___x_553_; 
v___x_553_ = lean_uint8_once(&lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__init___closed__0, &lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__init___closed__0_once, _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_maxwellkey__init___closed__0);
if (v___x_553_ == 0)
{
uint8_t v___x_554_; 
v___x_554_ = 0;
return v___x_554_;
}
else
{
uint8_t v___x_555_; 
v___x_555_ = 1;
return v___x_555_;
}
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_SecrecyCapacityGeneral(uint8_t builtin);
lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_MaxwellKey_MaxwellKeyPLUS_VerifiedFirmware(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_SecrecyCapacityGeneral(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_MaxwellKey_MaxwellKeyPLUS_DegradednessGeneral(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float = _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_k__B__float();
lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float = _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_T__float();
lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float = _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_B__float();
lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips = _init_lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips();
lean_mark_persistent(lp_MaxwellKey_MaxwellKey_VerifiedFirmware_two__parallel__strips);
maxwellkey_init = _init_maxwellkey_init();
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
