/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年03月31日 09时03分33秒
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

#include <cstring> 

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	std::cout<<"cstring programe v1.0.0"<<std::endl;
	/*
	 * strstr 获取某个字符串的首地址
	 */
	char title[] = "this is good idea";
	printf("title = %s\n",title);
	char *point = strstr(title,"good");
	strncpy(point,"bad ",4);
	printf("title = %s\n",title);

	/*
	 * strchr 获取某个字符的首地址
	 */
	point = strchr(title,'i');
	strncpy(point,"a",1);
	printf("title = %s\n",title);

	/*
	 * 比较字符串 
	 */
	char board[]    = "Computer Help";
	char myboard[]  = "Computer Help";
	std::size_t len = strlen(board);
	if (strncmp(board,myboard,len))
		printf ( "BAD\n" );
	else 
		printf ( "GOOD\n" );

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
