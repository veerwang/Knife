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

#include "processcommunication.h"

template< typename T >
class DoProcess 
{
public:
	int times;
	int process(int com_fd) 
	{
		times ++;
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
};

	int
main ( int argc, char *argv[] )
{
	std::cout<<"server starting ..... V1.0.0"<<std::endl;

	ProcessCommunication<DoProcess> pc;
	if ( pc.init() )
		std::cout<<"server init OK"<<std::endl;

	if ( pc.oneaccept() )
		std::cout<<"server accept OK"<<std::endl;

	char key = 0;
	WangV::InitKey();

	while( key != KEY_ESC )
	{
		key = WangV::GetPCKey();
		pc.doprocess();
	}

	WangV::RestoreKey();
	pc.release();

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
