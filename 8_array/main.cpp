/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年08月25日 13时33分09秒
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

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

struct cmd_right_check {
	const char* cmd;
	int right;
};

static const struct cmd_right_check g_cmd_right_check[] 
{
	{
		.cmd   = "adb shell",
		.right = 1,
	},
	{
		.cmd   = "adb reboot",
		.right = 2,
	},
	{
		.cmd   = "adb shutdown",
		.right = 3,
	},
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	for (int i=0;i<ARRAY_SIZE(g_cmd_right_check);i++)
	{
		std::cout<<"cmd:"<<g_cmd_right_check[i].cmd<<"  right:"<<g_cmd_right_check[i].right<<std::endl;
	}
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
