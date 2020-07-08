/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年07月02日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <sys/mman.h> 
#include <sys/ioctl.h> 
#include <fcntl.h> 
#include <unistd.h>

int main(int argc, const char *argv[]) {
	std::cout << "driver test" << std::endl;	
	FILE* fp = NULL;
	if ( (fp = fopen("/dev/miscdev_memory","a+")) == NULL ) {
		perror("open /dev/miscdev fail");
		return EXIT_SUCCESS;
	}

	unsigned char buf[20];
	for (int i=0;i<20;i++) {
		buf[i] = i;
	}

	result = fwrite(buf,1,20,fp);
	if (!result)
		perror("write data fail");

	int result = fread(buf,1,20,fp);
	if (!result)
		perror("read data fail");

	fclose(fp);
	return EXIT_SUCCESS;
}
