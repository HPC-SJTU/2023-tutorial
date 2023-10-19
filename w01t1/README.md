# 第一周任务1：Hello, slurm

本文件夹中包含一个 `main.c` 程序，请尝试编写一个 slurm 脚本，使得该程序在 slurm 集群上编译、运行。

## 代码编译与运行

> ⚠️ 请注意，本节内容为在本机上编译程序的流程，你需要将编译和运行过程整理为 slurm 脚本而非直接运行。

```bash
# 编译
make
# 运行
./main 
```

## 运行结果参考

在 16 核的机器下运行结果如下：

```text
(00/16) calculation done, current totalSum: 500500
(08/16) calculation done, current totalSum: 1001000
(09/16) calculation done, current totalSum: 1501500
(14/16) calculation done, current totalSum: 2002000
(13/16) calculation done, current totalSum: 2502500
(12/16) calculation done, current totalSum: 3003000
(03/16) calculation done, current totalSum: 3503500
(11/16) calculation done, current totalSum: 4004000
(10/16) calculation done, current totalSum: 4504500
(04/16) calculation done, current totalSum: 5005000
(06/16) calculation done, current totalSum: 5505500
(02/16) calculation done, current totalSum: 6006000
(01/16) calculation done, current totalSum: 6506500
(07/16) calculation done, current totalSum: 7007000
(15/16) calculation done, current totalSum: 7507500
(05/16) calculation done, current totalSum: 8008000
Total Sum: 8008000
```

如果运行环境为思源一号中的 `64c512g` 环境，输出应有 65 行，每行（最后一行除外）输出类似于 `(00/64) calculation done, current totalSum: 500500` 的内容。
