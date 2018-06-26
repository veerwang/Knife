/*
 * =====================================================================================
 *
 *       Filename:  utils.c
 *
 *    Description:  <Plug>AirlineTablineRefresh<Plug>AirlineTablineRefresh
 *
 *        Version:  1.0
 *        Created:  2018年06月20日 17时18分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  LiLin-Tech
 *   Organization:  GNU
 *
 * =====================================================================================
 */

extern int g_version;

int g_name = 21;

void add_fun()
{
	g_version = g_version + 10;
}

void foo()
{
	g_version = g_version * 10;
}
