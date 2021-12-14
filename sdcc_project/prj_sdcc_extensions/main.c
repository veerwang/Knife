/*
 * =============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  8051单片机框架程序
 *
 *        Version:  1.0
 *        Created:  2021年12月13日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include <mcs51/C8051F920.h>

#include "main.h"

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  程序的入口
 *  Description:   
 * ============================================================================
 */

int main(void)
{
	// 关键代码，内部寄存器
	__near unsigned char times = 0;

	init_frame();
	device_init();
	while (1) {
		;
	}
}
