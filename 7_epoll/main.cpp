/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年06月29日 
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

#include 	<fcntl.h>
#include 	<unistd.h>
#include 	<string.h>
#include 	<errno.h>
#include 	<stdlib.h>
#include 	<sys/epoll.h>
#include 	<sys/types.h>

int main(int argc, const char *argv[]) {
	std::cout << "epoll Test V1.0.0" << std::endl;	

	char buf;
	int fd = 0;
	/* 打开标准输入 */
	if((fd=open("/dev/stdin",O_RDONLY|O_NONBLOCK)) < 0) {
		fprintf(stderr,"open data1 error:%s",strerror(errno));
		return EXIT_FAILURE;
	}

	struct epoll_event ev;
	struct epoll_event events[5];

	int epfd = epoll_create(1);

	/* 注意一定要添加 EPOLLIN */
	ev.events = EPOLLIN;
	ev.data.fd = fd;

	int result = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);
	printf("epoll_ctl returned %d: %s\n", result, strerror(errno));

	while(1) {
		result = epoll_wait(epfd, events, 1, 0);
		for (int i = 0; i < result; i++) {
			if ( events[i].events == EPOLLIN ) {
				result = read(events[i].data.fd, &buf, 1);
				if ( result ) {
					printf("key = %c\n",buf);
					if ( buf == 'q' ) goto Exit;
				}
			}
		}
	}
Exit:
	/* 关闭文件句柄 */
	if ( fd!=0 )
		close(fd);

	return EXIT_SUCCESS;
}
