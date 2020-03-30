/*
 * =====================================================================================
 *
 *       Filename:  
 *
 *    Description:  模块测试程序 
 *
 *        Version:  1.0
 *        Created:  2020年03月30日 
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

int main(int argc, const char *argv[])
{
	std::cout << "Programe Version 1.0.0" << std::endl;	
	FILE* fp = NULL;
	if ( (fp = fopen("/dev/eddy0","r")) == NULL ) {
		perror("open /dev/eddy0 fail");
		return EXIT_SUCCESS;
	}


	fclose(fp);
	return EXIT_SUCCESS;
}
