# 第二周任务1：Tuning HPL

## 任务描述

HPL (High Performance LINPACK) 是常用的超级计算机基准测试（benchmark）工具，用来衡量超算集群浮点数运算的性能，在 TOP500 等超算算力榜单中被广泛使用。

你需要在思源一号中使用 `gcc` 编译并运行 HPL，然后通过调整 HPL 的参数，使得 HPL 性能达到最大值。

本次使用的 HPL 版本为 2.3，下载链接为 https://www.netlib.org/benchmark/hpl/hpl-2.3.tar.gz .

## 编译步骤

> 本次任务不提供具体的编译步骤，相关依赖的安装可以自行尝试，或者在微信群中提问。

HPL 2.3 的一种可行的编译依赖如下：

- GCC >= 8.2.0
- OpenBLAS-0.3.6 or OpenBLAS-0.3.12
- OpenMPI-4.0.5

注意思源节点中的 `gcc` 套件默认版本较低，高版本的 `gcc` 可以通过 `module load gcc` 加载。

上述依赖的源代码均可以在网络上找到（github.com 或官网），可以通过 `wget` 命令下载源码后编译，不建议采用 `module load` 方式加载。

编译顺序一般为： 先编译 `OpenMPI`，设置恰当的环境变量后编译 `OpenBLAS`，最后编译 `HPL`。

在编译 HPL 时需要可以用 `setup/Make.Linux_PII_CBLAS` 文件作为参考，记得修改其中的 `TOPdir`、`MPdir`、`LAdir` 等参数：

- `TOPdir` 即 HPL 源码所在的路径
- `MPdir` 即 MPI 的安装路径
- `LAdir` 即 BLAS 的安装路径

**💻 注意：出现编译错误是非常常见的事情，编译错误时可以抓住关键的报错信息、上网搜索相关资料，如有疑问也可以在微信群中提出。**

## Tuning HPL

只有为超算集群寻找合适的算例才能发挥出集群的最佳性能，因此需要对 HPL 的参数进行调整。

HPL 的参数文件为 `HPL.dat`，主要调整的参数包括：
- `Ns` 问题规模
- `N` 矩阵大小
- `NB` 分块计算时块的大小
- `Ps`、`Qs` 进程分布

思源一号的 CPU 型号为 `Intel(R) Xeon(R) Platinum 8358 CPU @ 2.60GHz`，可以在 [Intel 官网](https://www.intel.com/content/www/us/en/products/sku/212282/intel-xeon-platinum-8358-processor-48m-cache-2-60-ghz/specifications.html) 找到相关信息。

单节点包含两个 CPU 共 64 核心，512 GB 内存，一般在矩阵大小为内存的 80% 左右时性能较好。

**💻 注意：在优化 HPL 配置文件时可以去网上搜索相关资料，不要在不了解基本优化策略和配置文件格式的情况下闷头尝试。**

## 任务要求

1. 编译并运行 HPL
2. 调整 HPL 参数，使得单节点的 HPL 性能达到最大值

在实际测试中性能可以达到 `3.5 TFLOPS` 左右，希望大家能够超越 `3 TFLOPS`，至少达到 `1 TFLOPS`。

完成后请在微信群中汇报并附上 HPL 的路径（主要是 `HPL.dat` 和 `xhpl` 两个文件所在的路径），会有老队员进行检查。

## 相关链接

- [第一次培训 slides](../slides/00-HPL.pdf)
- [HPL 官网](http://www.netlib.org/benchmark/hpl/)
- [HPL 安装、参数调整参考文档](https://ulhpc-tutorials.readthedocs.io/en/latest/parallel/mpi/HPL/)
- [HPL 参数调整网站](https://www.advancedclustering.com/act_kb/tune-hpl-dat-file/)

## FAQ

### 1. 我无法登录思源一号节点，怎么办？

请在微信群中提出，会有老队员联系你。

### 2. 我找不到依赖的源代码，怎么办？

请在微信群中提出，但考虑到这些源代码均可以在网上找到，建议先行尝试，如果百度找不到的话可以尝试必应或者谷歌。

### 3. 我对 Linux 相关操作不太熟悉，无法正常操作，怎么办？

由于新队员们对 Linux 的熟悉程度并不相同，我们暂不考虑专门介绍如何使用 Linux，你可以通过搜索引擎查找常用的指令，或在视频平台上寻找快速入门方法。

如果是初次接触 Linux，你也可以考虑在本地用虚拟机的方式安装 Ubuntu 或其他 Linux 发行版并将其作为日常使用的操作系统，相信你能很快上手。

如果害怕误操作（指删除其他同学的文件等），可以在本地先尝试编译 HPL，将相关步骤整理成文档，然后再在思源一号操作。

**💻 欢迎在微信群中提出问题，不要害怕问题过于基础，老队员会尽量回答，当然在提问之前最好先找找搜索引擎中有没有答案。**

### 4. 我在编译 HPL 的过程中出现了问题，无法解决，怎么办？

编译过程中可能遇到各种各样的问题，欢迎在微信群中提出并附上尽可能详细的描述，老队员会尽量回答。

### 5. 我有其他问题，怎么办？

请在微信群中提出。
