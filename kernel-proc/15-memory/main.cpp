/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年07月03日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

#include <sys/mman.h> 
#include <sys/ioctl.h> 
#include <fcntl.h> 
#include <unistd.h>

int main(int argc, const char *argv[]) {
	std::cout << "memory test V1.0.0" << std::endl;	
	int fp = 0;
	if ( (fp = open("/dev/miscdev_memory",O_RDWR)) == 0 ) {
		perror("open /dev/miscdev_memory fail");
		return EXIT_SUCCESS;
	}

	unsigned char *p_map;
	p_map = (unsigned char *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED,fp, 0); 
	if(p_map == MAP_FAILED) { 
		perror("mmap fail:");
		close(fp);
		return EXIT_SUCCESS;
	}

	for ( int i=0;i<256;i++ )
		printf("x[%d] = %02x\n",i,p_map[i]);
	munmap(p_map,4096);
	close(fp);
	return EXIT_SUCCESS;
}
