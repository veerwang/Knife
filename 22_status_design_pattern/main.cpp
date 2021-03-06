/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019年06月10日 
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

#include 	"status.h"
#include 	"context.h"

int main(int argc, const char *argv[]) 
{
	std::cout << "status pattern test" << std::endl;	

	Context context;
	context.InitAllStatus();

	context.SetStatus((Status *)context.mStopStatus);
	context.Run();
	context.Stop();

	context.ReleaseAllStatus();
	return EXIT_SUCCESS;
}
