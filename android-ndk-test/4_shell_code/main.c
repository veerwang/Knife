#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *buf[] = {"/bin/sh",NULL};

int main (int argc,char** argv)
{
	printf("hack programe start ....\n");
	execve("/bin/sh",buf,0);
	exit(0);
}
