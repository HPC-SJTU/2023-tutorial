# HPL with GCC 编译参考教程

## 依赖及链接

- GCC: 使用 module load
- OpenMPI v4.0.5: https://download.open-mpi.org/release/open-mpi/v4.0/openmpi-4.0.5.tar.gz
- OpenBLAS v0.3.12: https://github.com/OpenMathLib/OpenBLAS/releases/download/v0.3.12/OpenBLAS-0.3.12.tar.gz
- HPL: https://www.netlib.org/benchmark/hpl/hpl-2.3.tar.gz

## 编译步骤

### 开始之前

在高性能计算中，我们常常需要安装特定版本的代码库（即依赖）。安装依赖通常为将源码编译为 `.so` 或 `.a` 等动态链接文件，并设置对应的环境变量使我们在编译其他代码时可以找到并使用这些依赖。

一般我们习惯将源码和编译后的产物（即上面说的 `.so` 和 `.a` 文件）放在两个不同的目录下，因此我们可以事先创建好两个目录，一个用来放源码，另一个用来放编译后的产物。

```bash
# 首先切换到自己的目录，记得将后面出现的 your_name 全部换为你自己的名字
cd your_name
# 创建一个目录用于 HPL 编译
mkdir HPL-gcc
cd HPL-gcc
# 分别创建两个目录放置文件，app目录放置编译后的产物，src目录放置源码
mkdir app src
```

申请一个计算节点用于编译和运行：

```bash
salloc -N 1 -p 64c512g -J your-name-HPL-with-gcc --exclusive
# 进入对应的计算节点，请将 nodeXXX 替换为真实的节点名称
ssh nodeXXX
```

随后我们下载所有源码：

```bash
# 切换到 src 目录
cd ~/your-name/HPL-gcc/src
# 下载并解压 OpenMPI
wget https://download.open-mpi.org/release/open-mpi/v4.0/openmpi-4.0.5.tar.gz
tar zxvf openmpi-4.0.5.tar.gz
# 下载并解压 OpenBLAS
wget https://github.com/OpenMathLib/OpenBLAS/releases/download/v0.3.12/OpenBLAS-0.3.12.tar.gz
tar zxvf OpenBLAS-0.3.12.tar.gz
# 切换回来
cd ..
```

记录一下当前目录的绝对路径，后面会用到：

```bash
# 打开记事本或其他工具记录以下命令的输出
pwd
# 样例输出 /dssg/home/acct-hpc/asc/zlzhong/HPL-gcc
```

### 编译 OpenMPI

首先进入源码目录并加载 GCC 编译器：

```bash
# gcc 环境已经加载过了，可以不重新加载
# module load gcc
# 切换到 OpenMPI 源码目录
cd src/openmpi-4.0.5
# 加载 gcc
module load gcc
# 检查编译器版本
gcc --version  # 样例输出 gcc (GCC) 11.2.0
```

随后我们开始编译 OpenMPI，OpenMPI 的默认安装路径在 `/usr/local/`，但我们需要安装在自己的 app 目录下，参考 `INSTALL` 文件和 [OpenMPI 官方文档](https://www.open-mpi.org/faq/?category=building#easy-build)，安装命令参考如下：

```bash
# 新建 build 目录便于构建
mkdir build
cd build
# 通过 prefix 选项指定安装的路径
../configure --prefix=/dssg/home/acct-hpc/asc/zlzhong/HPL-gcc/app/openmpi-4.0.5
# 此时应有一长串的输出，耐心等待即可
```

许多 C 语言或 Fortran 语言的大型项目会提供一个 `configure` 脚本用于配置安装路径等选项，`--prefix` 选项通常（并不总是）用于指定安装路径，一般通过查阅文档或使用 `./configure --help` 命令可以查看所有可用的选项。

```bash
# 编译，等待编译完成需要一段时间
make all  # 可以尝试加上 -j$(nproc) 开启多线程编译
# 安装
make install
# 验证安装
ls ../../../app/openmpi-4.0.5
# 参考输出： bin  etc  include  lib  share
# 退回到 HPL-gcc/src 目录
cd ../..
```

### 安装 OpenBLAS

OpenBLAS 是一个算术运算库，可以提供高效的 BLAS 和 LAPACK 接口。

```bash
# 切换到 OpenBLAS 源码目录
cd OpenBLAS-0.3.12
```

思源一号使用的处理器为 `Intel(R) Xeon(R) Platinum 8358 CPU @ 2.60GHz`，属于 `IceLake` 架构，但 OpenBLAS 默认不支持 `IceLake` 架构，因此我们需要手动指定架构：

```bash
# 参考 TargetList.txt
make TARGET=SKYLAKEX  # 可以尝试加上 -j$(nproc) 开启多线程编译
# 编译完成后进行安装，注意替换一下路径
make TARGET=SKYLAKEX PREFIX=/dssg/home/acct-hpc/asc/zlzhong/HPL-gcc/app/OpenBLAS-0.3.12 install
# 退回到 HPL-gcc 目录
cd ../..
```

至此，HPL 的所有依赖已经安装完毕，我们可以开始编译 HPL 了。

### 编译 HPL

编译 HPL 的环节与 OneAPI 的大致相同，不同的地方如下：

- HPL 需要用到的 `mpicc` 及相关命令是刚刚安装的 `OpenMPI` 提供的，不能直接使用 `module load`
- HPL 的 MPI 库（即 `MPdir`）需要指定为 `OpenMPI` 的安装路径
- HPL 的 BLAS 库（即 `LAdir`）需要指定为 `OpenBLAS` 的安装路径

由于 `mpirun`、`mpicc` 等命令在运行 HPL 时也会用到，因此我们将其加入 `PATH` 环境变量中：

```bash
# 记得将下面的地址换为你自己的地址
export PATH=/dssg/home/acct-hpc/asc/zlzhong/HPL-gcc/app/openmpi-4.0.5/bin:$PATH
```

> PATH 是一个特殊的环境变量，它的含义是告诉 SHELL 在执行命令时需要在哪些目录中查找可执行文件。例如在执行 `mpirun` 时，SHELL 会在 `PATH` 中的每个目录中查找 `mpirun`，如果找到了就执行，否则报错。

```bash
# 测试一下是否能否找到 mpirun
which mpirun
# 参考输出：~/zlzhong/HPL-gcc/app/openmpi-4.0.5/bin/mpicc
```

随后我们开始编译 HPL，首先下载并解压 HPL 源码：

```bash
# 下载并解压
wget https://www.netlib.org/benchmark/hpl/hpl-2.3.tar.gz
tar zxvf hpl-2.3.tar.gz
# 进入 HPL 源码目录
cd hpl-2.3
```

然后我们需要修改 `setup/Make.Linux_PII_CBLAS` 文件，将其中的 `TOPdir`、`MPdir`、`LAdir` 等参数修改为我们的安装路径：

```bash
cp setup/Make.Linux_PII_CBLAS Make.Linux_PII_CBLAS
```

使用 `nano` 或其他编辑器修改对应参数，参考如下：

```
# 修改 TOPdir
TOPdir       = /dssg/home/acct-hpc/asc/zlzhong/HPL-gcc/hpl-2.3

# 修改 MPdir 及相关参数
MPdir        = /dssg/home/acct-hpc/asc/zlzhong/HPL-gcc/app/openmpi-4.0.5
MPinc        = -I$(MPdir)/include
MPlib        = $(MPdir)/lib/libmpi.so

# 修改 LAdir 及相关参数
LAdir        = /dssg/home/acct-hpc/asc/zlzhong/HPL-gcc/app/OpenBLAS-0.3.12
LAinc        = -I$(LAdir)/include
LAlib        = $(LAdir)/lib/libopenblas.so

# 修改编译器和链接器
CC           = $(MPdir)/bin/mpicc
LINKER       = $(MPdir)/bin/mpif77
```

> 注意，除了上述需要修改的变量外其他变量保持不变

```bash
# 编译
make arch=Linux_PII_CBLAS
# 在编译出现错误时，可以通过以下命令清除已编译的文件，然后重新编译，使用时去除最前面的井号
# make arch=Linux_PII_CBLAS clean_arch_all
# 检验是否已经编译完成
ls bin/Linux_PII_CBLAS
# 参考输出：HPL.dat  xhpl
```

至此，HPL 已经编译完成，我们可以开始运行 HPL 了。

```bash
# 进入 HPL 目录
cd bin/Linux_PII_CBLAS
# 运行 HPL
mpirun -np 64 ./xhpl
```

此时会提示找不到 `libopenblas.so.0` 文件，因此我们将 `libopenblas.so.0` 所在的路径加入 `LD_LIBRARY_PATH` 环境变量中：

```bash
# 记得将下面的地址换为你自己的地址
export LD_LIBRARY_PATH=/dssg/home/acct-hpc/asc/zlzhong/HPL-gcc/app/OpenBLAS-0.3.12/lib:$LD_LIBRARY_PATH
```

> LD_LIBRARY_PATH 是一个特殊的环境变量，它的含义是告诉 SHELL 在执行命令时需要在哪些目录中查找动态链接库。例如在执行 `xhpl` 时，SHELL 会在 `LD_LIBRARY_PATH` 中的每个目录中查找 `libopenblas.so.0`，如果找到了就执行，否则报错。

```bash
# 重新运行
mpirun -np 64 ./xhpl
```

**注意：环境变量会在 SHELL 退出时恢复原状，因此下一次通过 SSH 进入计算节点（准确来说是下一次运行 bash 命令）时需要重新设置环境变量。**

参考命令如下：

```bash
# 记得将下面的地址换为你自己的地址
export PATH=/dssg/home/acct-hpc/asc/zlzhong/HPL-gcc/app/openmpi-4.0.5/bin:$PATH
export LD_LIBRARY_PATH=/dssg/home/acct-hpc/asc/zlzhong/HPL-gcc/app/OpenBLAS-0.3.12/lib:$LD_LIBRARY_PATH
```