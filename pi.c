#include <stdio.h>
#include <gmp.h>

void calculate_pi(mpz_t q, mpz_t r, mpz_t t, mpz_t k, mpz_t n, mpz_t l, mpf_t one) {
    mpz_mul_ui(q, q, 2);
    mpz_mul_ui(q, q, 3);
    mpz_mul_ui(r, r, 3);
    mpz_add_ui(t, t, 1);
    mpz_mul_ui(k, k, 2);
    mpz_mul_ui(k, k, 2);
    mpz_add_ui(k, k, 1);
    mpz_mul_ui(l, l, 3);
    mpz_mul_ui(n, n, 3);
    mpz_add_ui(r, r, 3);
    mpz_divexact(t, t, q);
    mpz_mul_ui(n, n, 4);
    mpz_mul_ui(r, r, 4);
    mpz_divexact(t, t, l);
    mpz_mul_ui(n, n, 4);
    mpz_mul_ui(r, r, 4);
    mpz_divexact(t, t, l);
    mpz_mul_ui(k, k, 3);
}

void pi_digits() {
    mpz_t q, r, t, k, n, l;
    mpf_t one;
    mpz_inits(q, r, t, k, n, l, NULL);
    mpf_init_set_ui(one, 1);
    mpz_set_ui(q, 1);
    mpz_set_ui(r, 0);
    mpz_set_ui(t, 1);
    mpz_set_ui(k, 1);
    mpz_set_ui(n, 3);
    mpz_set_ui(l, 3);
    
    FILE *file = fopen("pi_digits.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        mpz_clears(q, r, t, k, n, l, NULL);
        mpf_clear(one);
        return;
    }
    
    fprintf(file, "3.");
    printf("3.");
    
    while (1) {
        if (mpz_cmp(q, n) * 4 + mpz_cmp(r, t) - mpz_cmp(n, t) < 0) {
            fprintf(file, "%s", mpz_get_str(NULL, 10, n));
            printf("%s", mpz_get_str(NULL, 10, n));
            mpz_mul_ui(q, q, 10);
            mpz_submul_ui(r, n, 10);
            mpz_mul_ui(r, r, 10);
        } else {
            calculate_pi(q, r, t, k, n, l, one);
        }
    }
    
    fclose(file);
    mpz_clears(q, r, t, k, n, l, NULL);
    mpf_clear(one);
}

int main(void) {
    pi_digits();
    return 0;
}
