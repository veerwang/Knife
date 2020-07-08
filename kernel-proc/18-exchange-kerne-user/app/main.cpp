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
	int fp = 0;
	if ( (fp = open("/dev/miscdev_memory",O_RDWR)) == -1 ) {
		perror("open /dev/miscdev fail");
		return EXIT_SUCCESS;
	}

	unsigned char buf[20];
	for (int i=0;i<20;i++) {
		buf[i] = i + 2;
	}

	int result = write(fp,buf,20);
	if (!result)
		perror("write data fail");

	result = read(fp,buf,20);
	if (!result)
		perror("read data fail");

	for (int i=0;i<20;i++) {
		printf("data[%d] = %d\n",i,buf[i]);
	}

	close(fp);
	return EXIT_SUCCESS;
}
