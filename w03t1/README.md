### 第三周任务1：Parallelizing a function

**任务内容**：

利用OpenMP对以下函数进行并行优化，并记录在使用**不同线程数**时的优化加速比。

```c++
double func(double *A, const int lda,
            double *B, const int ldb, const int N) {
    double ret = 0;
    for (int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            ret += A[i * lda + j] * B[i + ldb + j];
    return ret;
}
```

**编译运行**

1. 进入项目目录。
2. 使用make命令进行编译。

**允许修改的部分**

1. func函数内部的代码。
2. Makefile的内容。

**提交要求**

需要提供完整的源代码，编译脚本以及在不同线程数目下函数的运行时间。通过微信告诉老队员，老队员会进行相应检查。