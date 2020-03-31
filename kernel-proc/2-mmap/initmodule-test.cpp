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

int main(int argc, const char *argv[]) {
	std::cout << "Programe Version 1.0.0" << std::endl;	
	FILE* fp = NULL;
	if ( (fp = fopen("/dev/eddy0","a+")) == NULL ) {
		perror("open /dev/eddy0 fail");
		return EXIT_SUCCESS;
	}

	unsigned char databuf[5];
	int length = fread((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("length = %d\n",length);
		for ( int i=0;i<length;i++ ) {
			printf("databuf[i] = %x\n",databuf[i]);
		}
	}

	for ( int i=0;i<5;i++ ) {
		databuf[i] = databuf[i] + 0xA0;
	}
	length = fwrite((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("write length = %d\n",length);
	}

	//fseek(fp,0,SEEK_END);

	length = fread((void *)databuf,1,5,fp);
	if ( length != 0 ) {
		printf("length = %d\n",length);
		for ( int i=0;i<length;i++ ) {
			printf("databuf[i] = %x\n",databuf[i]);
		}
	}
	fclose(fp);

	/* --------------- */

	int fd = open("/dev/eddy0",O_RDWR); 
	if(fd < 0) { 
		perror("open dev fail:"); 
		return EXIT_SUCCESS;
	}

	unsigned char *p_map;
	p_map = (unsigned char *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0); 
	if(p_map == MAP_FAILED) { 
		perror("mmap fail:");
		close(fd);
	}
	else {
		for (int i=0;i<10;i++) {
			printf("%x\n",p_map[i]);
		}
	}
	munmap(p_map,4096);
	close(fd);

	return EXIT_SUCCESS;
}
