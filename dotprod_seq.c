#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <N> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    long N = atol(argv[1]);
    char *filename = argv[2];

    float *a = malloc(N * sizeof(float));
    float *b = malloc(N * sizeof(float));

    srand(time(NULL));
    for (long i = 0; i < N; i++) {
        a[i] = (float)rand() / RAND_MAX;
        b[i] = (float)rand() / RAND_MAX;
    }

    // Produto interno sequencial
    double dot = 0.0;
    for (long i = 0; i < N; i++) {
        dot += a[i] * b[i];
    }

    // Gravar em arquivo binário
    FILE *f = fopen(filename, "wb");
    fwrite(&N, sizeof(long), 1, f);
    fwrite(a, sizeof(float), N, f);
    fwrite(b, sizeof(float), N, f);
    fwrite(&dot, sizeof(double), 1, f);
    fclose(f);

    printf("Produto interno (sequencial) = %.6f\n", dot);

    free(a);
    free(b);
    return 0;
}
