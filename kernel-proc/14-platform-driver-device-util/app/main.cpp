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
	if ( (fp = fopen("/dev/eddydrv","a+")) == NULL ) {
		perror("open /dev/eddydrv fail");
		return EXIT_SUCCESS;
	}

	fclose(fp);
	return EXIT_SUCCESS;
}
