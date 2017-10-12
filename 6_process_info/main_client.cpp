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

#include "processcommunication.h"

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

	ProcessCommunicationClient<> pc;
	if ( pc.init() )
		std::cout<<"server init OK"<<std::endl;

	pc.connect_server();

	char snd_buf[1024];

	int key = 0;
	WangV::InitKey();

	while( key != KEY_ESC  )
	{
		key = WangV::GetPCKey();

		switch ( key ) 
		{
			case KEY_BOTTOM1:
			{
				std::cout<<"KEY BOTTOM 1 push"<<std::endl;
				memset(snd_buf,0,1024);  
				strcpy(snd_buf,"message from client: key 1");  
				pc.doprocess(snd_buf);
			}
			break;
			case KEY_BOTTOM2:
			{
				std::cout<<"KEY BOTTOM 2 push"<<std::endl;
				memset(snd_buf,0,1024);  
				strcpy(snd_buf,"message from client: key 2");  
				pc.doprocess(snd_buf);
			}
			break;
			case KEY_BOTTOM3:
			{
				std::cout<<"KEY BOTTOM 3 push"<<std::endl;
				memset(snd_buf,0,1024);  
				strcpy(snd_buf,"message from client: key 3");  
				pc.doprocess(snd_buf);
			}
			break;

			default:	
				break;
		}				/* -----  end switch  ----- */

		usleep(1000);
	}

	pc.release();

	WangV::RestoreKey();

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
