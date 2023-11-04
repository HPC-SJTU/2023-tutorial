#include <iostream>
#include <time.h>
#include <omp.h>

// C[M, N] = A[M, K] * B[K, N]
void MatMul(const double *A, const int lda,
            const double *B, const int ldb,
            double *C, const int ldc,
            const int M, const int N, const int K) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < K; ++k)
                C[i * ldc + j] += A[i * lda + k] * B[k * ldb + j];
        }
    }
}

int main() {
    
    const int MaxN = 8192;
    const int Ntest = 10;
    struct timespec t1, t2;
    double *A, *B, *C;
    A = new double[MaxN * MaxN];
    B = new double[MaxN * MaxN];
    C = new double[MaxN * MaxN];
    for (int N:{1024, 2048, 4096, 8192}) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i * MaxN + j] = 1;
                B[i * MaxN + j] = 1;
                C[i * MaxN + j] = 0;
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &t1);
        for (int i = 0; i < Ntest;++i)
            MatMul(A, MaxN,
                B, MaxN,
                C, MaxN,
                N, N, N);
        clock_gettime(CLOCK_MONOTONIC, &t2);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                if (C[i * MaxN + j] != C[0]) {
                    printf("Wrong Answer\n");
                    return 0;
                }
            }
        double tv = (t2.tv_sec - t1.tv_sec) * 1e3 + (t2.tv_nsec - t1.tv_nsec) * 1e-6;
        printf("Matrix Size:%4d, Avg Time %8.3lf\n", N, tv / Ntest);
    }
    //std::cout << "The sum is: " << sum << std::endl;
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
