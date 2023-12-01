/*!
    \file    main.c
    \brief   文件的描述

    \version 2023年12月01日, V1.0
	\author	 kevin.wang
	\note    备注的描述
*/


#include <cstdlib>
#include <cstdio>
#include <iostream>

// 关键语句
#define MCU_DEBUG(msg) printf("%s \r\n", #msg);

int
main(int argc, const char *argv[]) {
	MCU_DEBUG(HELLO)
	return EXIT_SUCCESS;
}
