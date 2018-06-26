/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年12月13日 19时31分09秒
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

#include <ncurses.h>

static int min_rows = 17, min_cols = 60;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	initscr();
	noecho();
	curs_set(0);
	if(ncresize(min_rows, min_cols));
		min_rows = min_cols = 0;


	erase();
	refresh();
	endwin();
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
