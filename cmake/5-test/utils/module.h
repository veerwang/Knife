#ifndef INCLUDED_MODULE_H
#define INCLUDED_MODULE_H

/*!
    \file    module.h
    \brief   模块文件

    \version 2024-02-14, V1.0
	\author	 kevin.wang
	\note    无
*/

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

#include	"misce.hpp"
#include	"singleton.hpp"

namespace WangV {

// 模块相关的API函数
int module_version(void);

} /* namespace WangV */

#endif /* INCLUDED_MODULE_H */
