/*!
    \file    module.cc
    \brief   模块文件的实现

    \version 2024-02-14, V1.0
	\author	 kevin.wang
	\note    无
*/

#include "module.h"

static int version_prj = 100;

namespace WangV {

/*!
	\brief			返回模块的版本
	\param[in]		无
	\param[out]		无
	\retval			版本号
*/
int module_version(void) {
	return version_prj;
}

} /* namespace WangV */
