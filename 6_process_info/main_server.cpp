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

int process_communication(int com_fd)
{
	if ( !com_fd ) return 0;
	static char recv_buf[1024];   
	struct timeval m_tv;
	m_tv.tv_sec  = 0;
	m_tv.tv_usec = 1;
	fd_set	m_RDfd;

	FD_ZERO(&m_RDfd);
	FD_SET(com_fd,&m_RDfd);

	if ( select(com_fd+1,&m_RDfd,NULL,NULL,&m_tv) <= 0 )
		usleep(1000);
	else
	{
		if ( !FD_ISSET(com_fd,&m_RDfd) )
			usleep(1000);
		else
		{
			memset(recv_buf,0,1024);
			int num=read(com_fd,recv_buf,sizeof(recv_buf));  
			if ( num == 0 )
			{
				std::cout<<"ServerInfo: client close"<<std::endl;
				perror("ServerInfo: client bad:");
				close(com_fd);
				return 1; 
			}
			else
				std::cout<<"ServerInfo:"<<recv_buf<<std::endl;
		}
	}
	return 0;
}

	int
main ( int argc, char *argv[] )
{
	std::cout<<"server starting ..... V1.0.0"<<std::endl;

	struct sockaddr_un clt_addr;  
	struct sockaddr_un srv_addr;  
    	socklen_t clt_addr_len;  
	int com_fd;  
	int ret;  

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

	char key = 0;
	WangV::InitKey();

	while( key != KEY_ESC )
	{
		if ( process_communication(com_fd) ) key = KEY_ESC;
		else key = WangV::GetPCKey();
	}

	close(listen_fd);
	unlink(UNIX_DOMAIN);

	WangV::RestoreKey();

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
