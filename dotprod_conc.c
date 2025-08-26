#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct {
    float *a;
    float *b;
    long start;
    long end;
    double partial;
} ThreadData;

void *thread_func(void *arg) {
    ThreadData *data = (ThreadData*) arg;
    double sum = 0.0;
    for (long i = data->start; i < data->end; i++) {
        sum += data->a[i] * data->b[i];
    }
    data->partial = sum;
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <num_threads> <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    int T = atoi(argv[1]);
    char *filename = argv[2];

    // Ler arquivo binário
    long N;
    double vs;
    FILE *f = fopen(filename, "rb");
    fread(&N, sizeof(long), 1, f);

    float *a = malloc(N * sizeof(float));
    float *b = malloc(N * sizeof(float));
    fread(a, sizeof(float), N, f);
    fread(b, sizeof(float), N, f);
    fread(&vs, sizeof(double), 1, f);
    fclose(f);

    // Threads
    pthread_t threads[T];
    ThreadData data[T];

    long chunk = N / T;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < T; i++) {
        data[i].a = a;
        data[i].b = b;
        data[i].start = i * chunk;
        data[i].end = (i == T-1) ? N : (i+1) * chunk;
        data[i].partial = 0.0;
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    double vc = 0.0;
    for (int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
        vc += data[i].partial;
    }

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1e6;

    double error = (vs - vc) / vs;

    printf("Produto interno (sequencial) = %.6f\n", vs);
    printf("Produto interno (concorrente) = %.6f\n", vc);
    printf("Erro relativo = %.6e\n", error);
    printf("Tempo concorrente = %.6f segundos\n", elapsed);

    free(a);
    free(b);
    return 0;
}
