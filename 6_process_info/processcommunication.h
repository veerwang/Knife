#if !defined(INCLUDED_PROCESSCOMMUNICATION_H)
#define INCLUDED_PROCESSCOMMUNICATION_H  1

/*
 * =====================================================================================
 *
 *       Filename:  processcommunication.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年10月11日 15时24分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  LiLin-Tech
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <sys/types.h>    
#include <netinet/in.h>    
#include <sys/socket.h>    
#include <arpa/inet.h>    
#include <unistd.h>    
#include <string.h>    
#include <sys/un.h>

template< typename T >
class DefaultProcess 
{
public:
	int coreprocess(int num,char* buf) { return 0; }
};

template< template<typename T> class Process = DefaultProcess >
class ProcessCommunication : public Process<class T>
{
public:
	ProcessCommunication() { init_flag = false; accept_flag = false; }
	~ProcessCommunication() {;}

public:
	bool init()
	{
		srv_addr.sun_family = AF_UNIX;
		strncpy(srv_addr.sun_path,UNIX_DOMAIN,sizeof(srv_addr.sun_path)-1);  
		listen_fd = socket(PF_UNIX, SOCK_STREAM, 0); 
		if ( listen_fd  < 0 )
		{
			std::cout<<"server sock create fail"<<std::endl;
		}
		unlink(UNIX_DOMAIN);
		int ret = bind(listen_fd,(struct sockaddr*)&srv_addr,sizeof(srv_addr));
		if ( ret == -1 )
		{
			perror("cannot bind server socket");
			close(listen_fd);
			unlink(UNIX_DOMAIN);
			return false;
		}

		//listen sockfd   
		ret = listen(listen_fd,1);
		if ( ret==-1 )
		{  
			perror("cannot listen the client connect request");  
			close(listen_fd);  
			unlink(UNIX_DOMAIN);  
			return false;  
		}

		init_flag = true;
		return true;
	}

	void release()
	{
		if ( init_flag == false ) return;
		close(listen_fd);
		unlink(UNIX_DOMAIN);
	}

	void doprocess()
	{
		if ( accept_flag )
		{
			if ( !com_fd ) return ;
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
					}
					else
					{
						this->coreprocess(num,recv_buf);
					}
				}
			}
		}
		else
		{
			struct timeval m_tv;
			m_tv.tv_sec  = 0;
			m_tv.tv_usec = 1;
			fd_set	m_RDfd;
			FD_ZERO(&m_RDfd);
			FD_SET(listen_fd,&m_RDfd);

			if ( select(listen_fd+1,&m_RDfd,NULL,NULL,&m_tv) <= 0 )
				usleep(1000);
			else
			{
				if ( !FD_ISSET(listen_fd,&m_RDfd) )
					usleep(1000);
				else
				{
					clt_addr_len = sizeof(clt_addr);
					com_fd=accept(listen_fd,(struct sockaddr*)&clt_addr,&clt_addr_len);
					if( com_fd < 0 )
					{  
						perror("cannot accept client connect request");  
						close(listen_fd);  
						unlink(UNIX_DOMAIN);  
						accept_flag = false;
						init_flag = false;
					}
					accept_flag = true;
				}
			}
		}
	}

private:
	int listen_fd;
	int com_fd;  
	struct sockaddr_un srv_addr;  
	struct sockaddr_un clt_addr;  
    	socklen_t clt_addr_len;  
	static const char* UNIX_DOMAIN;
	bool init_flag;
	bool accept_flag;
};

template< template<typename T> class Process >
const char* ProcessCommunication<Process>::UNIX_DOMAIN = "/tmp/UNIX.domain";

#endif /* !defined(INCLUDED_PROCESSCOMMUNICATION_H) */
