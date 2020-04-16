/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  模块测试程序 
 *
 *        Version:  1.0
 *        Created:  2020年03月30日 
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

/* cat /proc/interrupts 查看各个中断号情况  */

int main(int argc, const char *argv[]) {
	std::cout << "Programe Version 1.0.0" << std::endl;	

	int fd = open("/dev/interruptdev",O_RDWR); 
	if(fd < 0) { 
		perror("open dev fail:"); 
		return EXIT_SUCCESS;
	}

	close(fd);
	return EXIT_SUCCESS;
}
