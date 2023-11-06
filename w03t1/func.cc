#include <iostream>
#include <time.h>
#include <omp.h>

double func(double *A, const int lda,
            double *B, const int ldb, const int N) {
    double ret = 0;
    for (int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            ret += A[i * lda + j] * B[i * ldb + j];
    return ret;
}

int main() {
    
    const int MaxN = 8192;
    const int Ntest = 10;
    struct timespec t1, t2;
    double *A, *B, C;
    A = new double[MaxN * MaxN];
    B = new double[MaxN * MaxN];
    for (int N:{1024, 2048, 4096, 8192}) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i * MaxN + j] = i;
                B[i * MaxN + j] = j;
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &t1);
        for (int i = 0; i < Ntest;++i)
            func(A, MaxN,
                B, MaxN, N);
        clock_gettime(CLOCK_MONOTONIC, &t2);
        double tv = (t2.tv_sec - t1.tv_sec) * 1e3 + (t2.tv_nsec - t1.tv_nsec) * 1e-6;
        printf("Task Size:%4d, Avg Time %8.3lf\n", N, tv / Ntest);
    }
    delete[] A;
    delete[] B;
    return 0;
}
