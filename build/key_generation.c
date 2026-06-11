/* MaxwellKey / build / key_generation.c
 * --------------------------------------
 * Firmware de REFERENCIA para DEMONSTRACAO SIMULADA.
 *
 * AVISO CRITICO: Este ficheiro e uma SIMULACAO didatica. NAO e
 * seguro para producao. Em particular:
 *   1. Usa rand() sem entropia real (previsivel).
 *   2. Os bits sao gerados por um PRNG simples, nao por medicao
 *      fisica do canal.
 *   3. E uma traducao MANUAL das formulas matematicas verificadas
 *      em Lean 4 (nao extraida automaticamente por compilador).
 *
 * Para um firmware de producao, usar:
 *   - MaxwellKeyPLUS/VerifiedFirmware.lean (especificacao verificada)
 *   - build/verified_main.c (extracao automatica Lean -> C)
 *   - TRNG (True Random Number Generator) de hardware para bits.
 *
 * O firmware real do David deve implementar estas operacoes
 * em hardware (MCU/FPGA) e usar os mesmos parametros que o
 * Lean verifica.
 *
 * Compilar: gcc -o keygen key_generation.c -lm
 * Usar:     ./keygen
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

/* ─────────────────────────────────────────────────────────────────────────────
 * Constantes fisicas e parametros do canal
 * (estes valores devem ser configurados a partir da simulacao COMSOL)
 * ───────────────────────────────────────────────────────────────────────────── */

#define Z0_OHM       50.0
#define N0_DEFAULT   4.0038821e-15   /* Densidade espectral de ruido (W/Hz).
                                         Valor sincronizado com TwoParallelStrips.lean:
                                         N0 = k_B * 290 K * 1 MHz = 4.0038821e-15 */
#define F_MHZ        100.0    /* Frequencia de operacao */
#define NUM_BITS     128      /* Comprimento da chave */

/* Parametros normalizados da geometria TwoParallelStrips (PCB fina).
   Sincronizados com VerifiedFirmware.lean e TwoParallelStrips.lean.
   Estes valores representam uma geometria fisica especifica de PCB
   (pistas paralelas, w=1mm, s=2mm, l=100mm, FR-4). */
static const double M_SELF    = 0.003109761664971414;
static const double M_MUTUAL  = 0.000004150620831811415;
static const double F_ATT     = 5.0;
static const double G_COND    = 0.0;  /* Modelo Lean assume G = 0 */

/* ─────────────────────────────────────────────────────────────────────────────
 * Estruturas de dados
 * ───────────────────────────────────────────────────────────────────────────── */

typedef struct {
    double a;  /* entrada (0,0) e (1,1) */
    double b;  /* entrada (0,1) e (1,0) */
} SymmMatrix2x2;

typedef uint8_t KeyBit;

/* ─────────────────────────────────────────────────────────────────────────────
 * Operacoes matriciais (modelo [[a,b],[b,a]])
 * ───────────────────────────────────────────────────────────────────────────── */

SymmMatrix2x2 S_bob(void) {
    double Z0sq = Z0_OHM * Z0_OHM;
    SymmMatrix2x2 S;
    S.a = Z0sq * (M_SELF * M_SELF + M_MUTUAL * M_MUTUAL);
    S.b = Z0sq * (2.0 * M_SELF * M_MUTUAL);
    return S;
}

SymmMatrix2x2 S_eve(void) {
    double Z0sq = Z0_OHM * Z0_OHM;
    SymmMatrix2x2 S;
    S.a = Z0sq * ((M_SELF + M_MUTUAL) * (M_SELF + M_MUTUAL)) / (F_ATT * F_ATT);
    S.b = 0.0;
    return S;
}

/* Forma quadratica x^T S x para matriz simetrica [[a,b],[b,a]] */
double quad_form(const SymmMatrix2x2 *S, double x0, double x1) {
    return S->a * (x0 * x0 + x1 * x1) + 2.0 * S->b * x0 * x1;
}

/* Verifica se A >= B na ordem de Loewner (amostragem em grid) */
bool loewner_le_check(const SymmMatrix2x2 *A, const SymmMatrix2x2 *B, int grid_size) {
    for (int i = 0; i <= grid_size; i++) {
        for (int j = 0; j <= grid_size; j++) {
            double x0 = (double)i / grid_size;
            double x1 = (double)j / grid_size;
            if (quad_form(A, x0, x1) < quad_form(B, x0, x1) - 1e-12) {
                return false;
            }
        }
    }
    return true;
}

/* ─────────────────────────────────────────────────────────────────────────────
 * Canal exacto: f(A) = I - (I + A)^(-1)
 * Para [[a,b],[b,a]], a inversa e [[p,q],[q,p]] com:
 *   p = (1+a)/det,  q = -b/det,  det = (1+a)^2 - b^2
 * Logo f(A) = [[1-p, -q], [-q, 1-p]]
 * ───────────────────────────────────────────────────────────────────────────── */

SymmMatrix2x2 exact_channel(const SymmMatrix2x2 *S) {
    double det = (1.0 + S->a) * (1.0 + S->a) - S->b * S->b;
    if (fabs(det) < 1e-15) {
        fprintf(stderr, "Erro: determinante singular\n");
        exit(1);
    }
    double p = (1.0 + S->a) / det;
    double q = S->b / det;
    SymmMatrix2x2 H;
    H.a = 1.0 - p;
    H.b = q;
    return H;
}

/* ─────────────────────────────────────────────────────────────────────────────
 * Capacidade de segredo
 * C_bob = 0.5 * log2(det(I + S_bob/N0))
 * C_eve = 0.5 * log2(1 + S_eve/N0)
 * ───────────────────────────────────────────────────────────────────────────── */

double capacity_bob(double N0) {
    double alpha = (Z0_OHM * Z0_OHM) / N0;
    double arg = (1.0 + alpha * (M_SELF * M_SELF + M_MUTUAL * M_MUTUAL)) *
                 (1.0 + alpha * (M_SELF * M_SELF + M_MUTUAL * M_MUTUAL))
                 - (alpha * 2.0 * M_SELF * M_MUTUAL) *
                   (alpha * 2.0 * M_SELF * M_MUTUAL);
    return 0.5 * log2(arg);
}

double capacity_eve(double N0) {
    double alpha = (Z0_OHM * Z0_OHM) / N0;
    double S_eve_scalar = alpha * ((M_SELF + M_MUTUAL) * (M_SELF + M_MUTUAL)) / (F_ATT * F_ATT);
    return 0.5 * log2(1.0 + S_eve_scalar);
}

double secrecy_capacity(double N0) {
    return capacity_bob(N0) - capacity_eve(N0);
}

/* ─────────────────────────────────────────────────────────────────────────────
 * Geracao de chave (quantizacao da fase)
 * ───────────────────────────────────────────────────────────────────────────── */

KeyBit quantize(double phase) {
    return (phase > 0.0) ? 1 : 0;
}

/* Simula uma medicao do canal para Bob */
double sample_channel_bob(void) {
    /* Modelo simplificado: fase proporcional a M_mutual */
    return atan2(M_MUTUAL, M_SELF);
}

/* Gera uma chave de num_bits bits */
void generate_key_bob(uint8_t *key, size_t num_bits) {
    double phase = sample_channel_bob();
    for (size_t i = 0; i < num_bits; i++) {
        /* Na implementacao real, cada bit vem de uma medicao independente */
        /* Aqui usamos um PRNG simples para simular variacoes de canal */
        double noise = ((double)rand() / RAND_MAX - 0.5) * 0.1;
        key[i] = quantize(phase + noise);
    }
}

/* ─────────────────────────────────────────────────────────────────────────────
 * Programa principal
 * ───────────────────────────────────────────────────────────────────────────── */

int main(void) {
    /* Inicializar PRNG com tempo atual. NOTA: ainda fraco para producao;
       firmware real deve usar TRNG de hardware. */
    srand((unsigned int)time(NULL));

    printf("=====================================================\n");
    printf("  MaxwellKey — Firmware de Referencia (C)\n");
    printf("  AVISO: SIMULACAO DIDATICA — Nao segura para producao\n");
    printf("=====================================================\n\n");

    /* Parametros do canal */
    printf("Parametros do canal:\n");
    printf("  M_self   = %.6f\n", M_SELF);
    printf("  M_mutual = %.6f\n", M_MUTUAL);
    printf("  Z0       = %.1f Ohm\n", Z0_OHM);
    printf("  f_att    = %.2f\n", F_ATT);
    printf("  G        = %.6e S\n\n", G_COND);

    /* Matrizes de covariancia */
    SymmMatrix2x2 Sbob = S_bob();
    SymmMatrix2x2 Seve = S_eve();
    printf("Matriz S_bob:  a=%.4f, b=%.4f\n", Sbob.a, Sbob.b);
    printf("Matriz S_eve:  a=%.4f, b=%.4f\n\n", Seve.a, Seve.b);

    /* Verificacao da ordem de Loewner (discretizada) */
    bool ok = loewner_le_check(&Sbob, &Seve, 20);
    printf("Verificacao Loewner (grid 20x20): %s\n\n", ok ? "PASSA" : "FALHA");

    /* Canal exacto */
    SymmMatrix2x2 Hbob = exact_channel(&Sbob);
    SymmMatrix2x2 Heve = exact_channel(&Seve);
    printf("Canal exacto H_bob: a=%.6f, b=%.6f\n", Hbob.a, Hbob.b);
    printf("Canal exacto H_eve: a=%.6f, b=%.6f\n\n", Heve.a, Heve.b);

    bool ok_exact = loewner_le_check(&Hbob, &Heve, 20);
    printf("Verificacao Loewner exacta: %s\n\n", ok_exact ? "PASSA" : "FALHA");

    /* Capacidades */
    double N0 = N0_DEFAULT;
    double C_bob = capacity_bob(N0);
    double C_eve = capacity_eve(N0);
    double C_sec = secrecy_capacity(N0);
    printf("Capacidade Bob:  %.6f bits/uso\n", C_bob);
    printf("Capacidade Eve:  %.6f bits/uso\n", C_eve);
    printf("Cap. de segredo: %.6f bits/uso\n\n", C_sec);

    if (C_sec > 0.0) {
        printf("[OK] Capacidade de segredo POSITIVA.\n");
    } else {
        printf("[ERRO] Capacidade de segredo nao positiva!\n");
        return 1;
    }

    /* Geracao de chave */
    uint8_t key[NUM_BITS];
    generate_key_bob(key, NUM_BITS);
    printf("Chave gerada (%zu bits): ", NUM_BITS);
    for (size_t i = 0; i < NUM_BITS; i++) {
        printf("%d", key[i]);
    }
    printf("\n\n");

    printf("=====================================================\n");
    printf("  Simulacao concluida.\n");
    printf("  Para producao: usar verified_main.c + TRNG de hardware.\n");
    printf("=====================================================\n");

    return 0;
}
