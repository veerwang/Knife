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

#include <stdint.h>
#include <mcs51/C8051F920.h>

#include "main.h"

#include "modules/serials/serials.h"
#include "modules/timers//timers.h"

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  main 
 *  Description:  程序的入口 
 * ============================================================================
 */

int main(void)
{
	EA = 0;

	// 关键代码，内部寄存器
	__near uint8_t times = 0;

	asm_delay(1);

	init_frame();
	init_serial();
	init_timer();

	while (1) {
		;
	}
}
