# The Abstract Machine (AM)

## Usage

To test Wenquxing 22A with your own c program on the emu, in path `snn-am/tests/cputest/`use fowlling cammand:

```
$ make ARCH=riscv64-nutshell ALL=filename
```
where the `filename` is your c program source code file in path `snn-am/tests/cputest/tests` without `.c`.

Then you can get the binary file in `snn-am/tests/cputest/build` named `filename-riscv64-nutshell.bin` which can be used as your image file to launch emu. 

If you have set the `NUSHELL_HOME` path, you can launch the emu with:

```
$ make ARCH=riscv64-nutshell ALL=filename run
```

**The following part is description of AM for Nutshell**
---

## 注意

这是一个临时的仓库，仅用于支持NutShell运行一些基本的程序。

AM项目是[南京大学计算机系若干课程实验](https://github.com/NJU-ProjectN/)的一部分，
本仓库将与课程作业相关的若干.c文件替换成.o文件，具体包括
```
libs/klib/src/{stdio,stdlib,string}.o
```

upstream正在重构，预计可在2020/09/01前完成重构，届时再从upstream中fork一个分支来支持NutShell。

## 介绍

抽象计算机：必要的抽象，帮你编写一个完整的计算机系统！

目录组织：

* `am/`：AM头文件、每个体系结构分别实现的AM代码。
* `libs/`：建立在AM上、体系结构无关的运行库，如软件模拟浮点数、基础libc功能等。
* `apps/`：一些运行在AM上应用程序示例。
* `tests/`: 用来测试AM实现的简单测试程序。

## 创建一个AM应用

在任何目录都可以创建运行在AM上的应用程序。程序用C/C++语言编写，除AM之外无法调用其他库函数（但可以引用`stdarg.h`, `limits.h`等包含体系结构相关数据定义的头文件）。

为此你需要在应用程序项目的根目录添加一个Makefile：

```
NAME = app-name
SRCS = src/main.c src/help.c src/lib.cpp
include $(AM_HOME)/Makefile.app
```

一些注意事项：

* `NAME`定义了应用的名字。编译后会在`build/`目录里出现以此命名的应用程序。
* `SRCS`指定了编译应用所需的源文件。可以放在应用目录中的任意位置。

* 应用目录下的`include/`目录会被添加到编译的`-I`选项中。
* 环境变量`AM_HOME`需要包含**nexus-am项目的根目录的绝对路径**。

编译时，首先确保`AM_HOME`正确设置，然后执行`make ARCH=体系结构名`编译。例如`make ARCH=native`将会编译成本地可运行的项目，`make ARCH=mips32-minimal`生成用于仿真的MIPS32程序。`ARCH`缺省时默认编译到本地。
