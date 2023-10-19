# 第一周任务2：Oh my password

## 说明

仲菜同学正在做超算队的迎新文案，但是他突然忘记了加密后的文案内容，更糟糕的是他忘记密码了！请你帮帮他找回丢失的密码，解密文案。

## 运行方式

### 文件简介

- `secret.bin` 加密后的文件
- `exploit.py` 密码破解程序

### 安装依赖

为了保证依赖不影响其他项目，我们使用 Python 的虚拟环境来运行程序。这里给出两种构建虚拟环境的办法，选择其中一个即可。

#### 1. 使用 conda

```bash
# 激活 conda 环境
source ~/scripts/conda.sh
# 创建虚拟环境，记得将 your-name 换成自己的名字
conda create -n your-name python=3.11
# 激活虚拟环境
conda activate your-name
# 安装依赖
pip install -r requirements.txt
```

#### 2. 使用 `venv` 模块

```bash
# 切换到自己的目录
cd your_name/
# 创建虚拟环境
python -m venv ./venv
# 激活虚拟环境
source ./venv/bin/activate
# 安装依赖
pip install -r requirements.txt
```

### 运行

> ⚠️ 请注意，本节内容为在本机上运行程序的流程，你需要编写一个 slurm 脚本在计算节点上执行密码破解程序而非直接运行。

```bash
# 运行
python exploit.py
```

**提醒**：如果需要在 slurm 脚本中使用自己的虚拟环境，请在脚本中添加激活环境需要的命令。
