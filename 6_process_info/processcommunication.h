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
	int process(int fd) { return 0;}
};

template< template<typename T> class Process = DefaultProcess >
class ProcessCommunication : public Process<class T>
{
public:
	ProcessCommunication() { init_flag = false;}
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

	bool oneaccept()
	{
		clt_addr_len = sizeof(clt_addr);
		com_fd=accept(listen_fd,(struct sockaddr*)&clt_addr,&clt_addr_len);
		if( com_fd < 0 )
		{  
			perror("cannot accept client connect request");  
			close(listen_fd);  
			unlink(UNIX_DOMAIN);  
			return false;
		}
		return true;
	}

	void doprocess()
	{
		this->process(listen_fd);
	}

private:
	int listen_fd;
	int com_fd;  
	struct sockaddr_un srv_addr;  
	struct sockaddr_un clt_addr;  
    	socklen_t clt_addr_len;  
	static const char* UNIX_DOMAIN;
	bool init_flag;
};

template< template<typename T> class Process >
const char* ProcessCommunication<Process>::UNIX_DOMAIN = "/tmp/UNIX.domain";

#endif /* !defined(INCLUDED_PROCESSCOMMUNICATION_H) */
