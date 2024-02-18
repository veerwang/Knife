/*!
    \file    module.cc
    \brief   模块文件的实现

    \version 2024-02-14, V1.0
	\author	 kevin.wang
	\note    无
*/

#include "module.h"

static int version_prj = 100;

/*!
	\brief			返回模块的版本
	\param[in]		无
	\param[out]		无
	\retval			版本号
*/
int module_version(void) {
	return version_prj;
}

/*!
	\brief			将字符串转换数字类型
	\param[in]		x 待转换的字符串
	\param[out]		无
	\retval			返回值
*/
long long string_to_number(std::string &x) {
    long long sum = 0;
    for (int i = 0; i < x.size(); i++) {
        sum *= 10;
        sum += (x[i]-'0');
    }
    return sum;
}

