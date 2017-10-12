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
	int coreprocess(char *buf) 
	{
		std::cout<<"ServerInfo:"<<buf<<std::endl;
		return 0;
	}
};

	int
main ( int argc, char *argv[] )
{
	std::cout<<"server starting ..... V1.0.0"<<std::endl;

	ProcessCommunicationServer<DoProcess> pc;
	if ( pc.init() )
		std::cout<<"server init OK"<<std::endl;

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
