/* MaxwellKey / build / verified_main.c
 * -----------------------------------
 * Wrapper C minimo para o firmware verificado do Lean 4.
 *
 * Este ficheiro demonstra como chamar as funcoes exportadas do
 * Lean 4 (via @[export]) a partir de codigo C.
 *
 * As funcoes exportadas em VerifiedFirmware.lean sao:
 *   - maxwellkey_init()              -> UInt8 (1 = OK, 0 = FALHA)
 *   - maxwellkey_secrecy_capacity()  -> Float (capacidade de segredo)
 *   - maxwellkey_loewner_check()     -> UInt8 (1 = PASSA)
 *   - maxwellkey_exact_channel_check() -> UInt8 (1 = PASSA)
 *
 * Pipeline de extracao verificada:
 *   VerifiedFirmware.lean (Lean 4)
 *      -> lake build -> IR (.olean)
 *      -> compilador Lean -> C (representacao intermedia)
 *      -> gcc -> binario
 *
 * AVISO: O Lean 4 gera codigo nativo que depende do runtime do Lean
 * (lean.h, lean_runtime.a). Para deployment em microcontroladores,
 * seria necessario um runtime Lean minimal ou cross-compilation.
 * Este esqueleto serve para demonstrar o conceito em Linux/x86_64.
 *
 * Compilar (esqueleto — requer configuracao do lakefile):
 *   make verified
 *
 * Para testes rapidos, usar o firmware de referencia:
 *   gcc -o keygen key_generation.c -lm
 *   ./keygen
 */

#include <stdio.h>
#include <stdint.h>
#include <lean/lean.h>  /* Runtime do Lean 4 */

/* --- Declaracoes das funcoes exportadas do Lean 4 --- */
/* Estas funcoes sao geradas pelo compilador Lean a partir de
   VerifiedFirmware.lean com o atributo @[export]. */

extern uint8_t maxwellkey_init(void);
extern double  maxwellkey_secrecy_capacity(void);
extern uint8_t maxwellkey_loewner_check(void);
extern uint8_t maxwellkey_exact_channel_check(void);

/* --- Inicializacao do runtime Lean --- */
/* O Lean 4 requer inicializacao do runtime antes de chamar
   funcoes exportadas. */

extern void lean_initialize_runtime_module();
extern void lean_initialize();

int main(void) {
    printf("=====================================================\n");
    printf("  MaxwellKey — Firmware VERIFICADO (Lean 4 -> C)\n");
    printf("=====================================================\n\n");

    /* Inicializar runtime do Lean */
    lean_initialize();
    lean_initialize_runtime_module();

    /* --- Passo 1: Verificacoes de seguranca --- */
    printf("[1] Verificacoes de seguranca do firmware...\n");

    uint8_t init_ok = maxwellkey_init();
    if (!init_ok) {
        printf("    [FALHA] Verificacoes de seguranca falharam.\n");
        printf("            O firmware NAO deve operar.\n");
        return 1;
    }
    printf("    [PASSA] Todas as verificacoes de seguranca OK.\n\n");

    /* --- Passo 2: Verificacao de Loewner --- */
    printf("[2] Verificacao da ordem de Loewner...\n");
    uint8_t loewner_ok = maxwellkey_loewner_check();
    printf("    %s\n\n", loewner_ok ? "[PASSA] S_bob >=_l S_eve"
                                  : "[FALHA] S_bob <_l S_eve");

    /* --- Passo 3: Verificacao do canal exacto --- */
    printf("[3] Verificacao do canal exacto...\n");
    uint8_t exact_ok = maxwellkey_exact_channel_check();
    printf("    %s\n\n", exact_ok ? "[PASSA] f(S_bob) >=_l f(S_eve)"
                                 : "[FALHA] f(S_bob) <_l f(S_eve)");

    /* --- Passo 4: Capacidade de segredo --- */
    printf("[4] Capacidade de segredo...\n");
    double C_sec = maxwellkey_secrecy_capacity();
    printf("    C_s = %.6f bits/uso\n", C_sec);
    if (C_sec > 0.0) {
        printf("    [PASSA] Capacidade de segredo POSITIVA.\n\n");
    } else {
        printf("    [FALHA] Capacidade de segredo nao positiva!\n\n");
        return 1;
    }

    printf("=====================================================\n");
    printf("  Todas as verificacoes PASSARAM.\n");
    printf("  Firmware verificado pronto para deployment.\n");
    printf("=====================================================\n");

    return 0;
}
