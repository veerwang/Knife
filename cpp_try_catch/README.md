该工程用于测试try命令。

core dump 如何导出，并进行调试
1.ulimit -c 如果显示0，说明core dump 被关闭了
2.ulimit -c unlimited 开启导出core dump命令
3.运行程序，如果崩溃，会导出core dump到但前路径下,文件名为core
4.重新编译应用程序，加-g开关，假如为main
5.gdb main core
6.在断点处，运行where 会打印出，函数栈进行分析
