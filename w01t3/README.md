# 第一周任务3：Realworld example

## 任务描述

1. 在思源一号集群上编译 [UoB-TeaLeaf](https://github.com/UoB-HPC/TeaLeaf) 项目（使用 `omp` 实现）
2. 以项目根目录的 `tea.in` 作为输入进行测试，验证编译正确性  

## 编译步骤

### 预处理

[UoB-TeaLeaf](https://github.com/UoB-HPC/TeaLeaf) 项目支持多种实现，本任务采用 `OpenMP` 实现，在编译过程中需要依赖 `cmake` 和 `mpich` 等模块。

```bash
# 加载模块
module load gcc cmake mpich
```

### 编译过程

参考 UoB-TeaLeaf 项目的 [README.md](https://github.com/UoB-HPC/TeaLeaf) 文档。

### 测试过程

参考 UoB-TeaLeaf 项目的 `test.sh` 文件。
