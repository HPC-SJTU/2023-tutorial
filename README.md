# 2023 XFlops 培训文档

## 说明

本项目是 2023 SJTU 超算队入门教程，包含一些简单的练习。如果对练习有任何想法，欢迎提交一个新的 issue。在练习过程中如果遇到问题可以在微信群提问，或在 discussion 中提出。

每周任务的命名方式为 `w<周数>t<任务编号>`，如第一周的第一次任务为 `w01t1`。每个任务文件夹中均包含一个 `README.md` 文件，文件中有具体的任务需求。

## 目录

- [第一周任务1：Hello, slurm](./w01t1/)
- [第一周任务2：Oh my password](./w01t2/)
- [第一周任务3：Realworld example（选做）](./w01t3/)

- [第一次培训课件](./slides/00-HPL.pdf)
- [第二周任务1：Tuning HPL](./w02t1)

- [第二次培训课件](./slides/01-parallel_compute.pptx)
- [第三周任务1：Parallelizing a function](./w03t1/)
- [第三周任务2：Optimizing the Matrix Multiplication](./w03t2)
- [第三次培训课件](./slides/02-MPI.pptx)
- [第三次培训示例](./w04example/)
- [第四次培训课件](./slides/03-Compile.pdf)
- [第四次培训示例](./w05example/)
- [第五次培训课件](./slides/04-CUDA.pptx)
## 如何使用本文档

如果你已经安装了 Git，可以直接使用 `git clone` 命令将本项目克隆到本地。如果你还没有安装 Git，可以参考 [Git 官方文档](https://git-scm.com/book/zh/v2/起步-安装-Git) 安装。

> 思源一号及 pi 集群均已安装 Git，可以直接使用。

```bash
cd your-name # 切换到自己的目录
git clone https://github.com/HPC-SJTU/2023-tutorial.git
```

在本文档更新时可以使用以下命令拉取更新：

```bash
git pull
```
