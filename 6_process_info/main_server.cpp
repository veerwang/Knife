/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年08月21日 10时11分20秒
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
#include <netinet/in.h>    
#include <sys/socket.h>    
#include <arpa/inet.h>    
#include <unistd.h>    
#include <string.h>    
#include <sys/un.h>

#include "globalkey.h"

#define UNIX_DOMAIN "/tmp/UNIX.domain"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	std::cout<<"server starting ..... V1.0.0"<<std::endl;

	struct sockaddr_un clt_addr;  
	struct sockaddr_un srv_addr;  
    	socklen_t clt_addr_len;  
	int com_fd;  
	int ret;  
	int i;  
	static char recv_buf[1024];   
	int len;  

	int listen_fd = socket(PF_UNIX, SOCK_STREAM, 0); 

	if ( listen_fd  < 0 )
	{
		std::cout<<"server sock create fail"<<std::endl;
	}

	//set server addr_param  
	srv_addr.sun_family = AF_UNIX;
	strncpy(srv_addr.sun_path,UNIX_DOMAIN,sizeof(srv_addr.sun_path)-1);  
	//bind sockfd & addr  
	unlink(UNIX_DOMAIN);  
	ret = bind(listen_fd,(struct sockaddr*)&srv_addr,sizeof(srv_addr));  
	if ( ret == -1 )  
	{  
		perror("cannot bind server socket");  
		close(listen_fd);  
		unlink(UNIX_DOMAIN);  
		return EXIT_FAILURE;  
	}

	//listen sockfd   
	ret = listen(listen_fd,1);
	if ( ret==-1 )  
	{  
		perror("cannot listen the client connect request");  
		close(listen_fd);  
		unlink(UNIX_DOMAIN);  
		return 1;  
	}  

	//have connect request use accept  
	clt_addr_len = sizeof(clt_addr);
	com_fd=accept(listen_fd,(struct sockaddr*)&clt_addr,&clt_addr_len);
	if( com_fd < 0 )
	{  
		perror("cannot accept client connect request");  
		close(listen_fd);  
		unlink(UNIX_DOMAIN);  
		return 1;  
	}
	//read and printf sent client info  
	printf("/n=====info=====/n");  
	for(i=0;i<4;i++)  
	{  
		memset(recv_buf,0,1024);  
		int num=read(com_fd,recv_buf,sizeof(recv_buf));  
		printf("Message from client (%d)) :%s/n",num,recv_buf);    
	}  
	close(com_fd);  
	close(listen_fd);  
	unlink(UNIX_DOMAIN);  

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
