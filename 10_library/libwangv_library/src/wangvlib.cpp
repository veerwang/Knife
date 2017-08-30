/*
 * =====================================================================================
 *
 *       Filename:  wangvlib.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年12月02日 09时21分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  LiLin-Tech
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include "wangvlib.h"

#include <cstdlib>
#include <cstdio>

namespace WangV {
static const char PROJ_VERSION[] = {"V1.01"};

/* module function  */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_version 
 *  Description:  获得模块的版本信息 
 * =====================================================================================
 */
const char* get_version()
{
	return PROJ_VERSION;
}

void __attribute__ ((constructor)) init_module()
{
	WangV::log_module_init(NULL);
	WangV::log_module_level(4);
	WangV::log_module_write(4,__FILE__,__FUNCTION__,__LINE__,"init module %s","kevin");
}

void __attribute__ ((destructor)) release_module()
{
	WangV::log_module_write((4),__FILE__,__FUNCTION__,__LINE__,"destruct module %s","kevin");
	WangV::log_module_destroy();
}

}
