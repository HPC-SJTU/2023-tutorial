### 第三周任务2：optimizing the Matrix Multiplication

**任务内容**：优化以下矩阵乘法代码，计时代码已经写好，无需修改。

```c++
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
```

**编译运行**

1. 进入项目目录。
2. 使用make命令进行编译。

**允许修改的部分**

1. MatMul函数内部的代码。
2. Makefile的内容。

**禁止使用**

1. 外部的矩阵乘法库。
2. 针对数据的优化（这个数据已经很水了

**提交要求**

需要提供完整的源代码，编译脚本以及运行时间。可以通过微信告诉我们，老队员会进行相应检查。

**提示**

矩阵乘法的优化不仅仅只有OpenMP并行这一种，可以去网络上进行搜索，尝试多种优化策略，也可以在编译选项上做出一些调整。