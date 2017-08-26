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
#include <unistd.h>

#include <sys/types.h>  
#include <sys/socket.h>  
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
	std::cout<<"cleint starting ..... V1.0.0"<<std::endl;

	int connect_fd;  
	int ret;  
	char snd_buf[1024];  
	int i;  
	static struct sockaddr_un srv_addr;  
	//creat unix socket  
	connect_fd=socket(PF_UNIX,SOCK_STREAM,0);  
	if(connect_fd<0)  
	{  
		perror("cannot create communication socket");  
		return 1;  
	}     
	srv_addr.sun_family=AF_UNIX;  
	strcpy(srv_addr.sun_path,UNIX_DOMAIN);  
	//connect server  
	ret=connect(connect_fd,(struct sockaddr*)&srv_addr,sizeof(srv_addr));  
	if(ret==-1)  
	{  
		perror("cannot connect to the server");  
		close(connect_fd);  
		return 1;  
	}  

	int key = 0;
	WangV::InitKey();

	while( key != KEY_ESC  )
	{
		key = WangV::GetPCKey();

		switch ( key ) 
		{
			case KEY_BOTTOM1:
			{
				memset(snd_buf,0,1024);  
				strcpy(snd_buf,"message from client: key 1");  
				write(connect_fd,snd_buf,sizeof(snd_buf));  
			}
			break;
			case KEY_BOTTOM2:
			{
				memset(snd_buf,0,1024);  
				strcpy(snd_buf,"message from client: key 2");  
				write(connect_fd,snd_buf,sizeof(snd_buf));  
			}
			break;
			case KEY_BOTTOM3:
			{
				memset(snd_buf,0,1024);  
				strcpy(snd_buf,"message from client: key 3");  
				write(connect_fd,snd_buf,sizeof(snd_buf));  
			}
			break;

			default:	
				break;
		}				/* -----  end switch  ----- */

		usleep(1000);
	}

	close(connect_fd);  
	WangV::RestoreKey();

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */