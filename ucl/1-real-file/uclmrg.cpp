/*
 * =====================================================================================
 *
 *       Filename:  uclmrg.cpp
 *
 *    Description:  类介绍 
 *
 *        Version:  1.0
 *        Created:  2020年08月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "uclmrg.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uclmrg
 *  Description:  默认构造函数 
 * =====================================================================================
 */
uclmrg::uclmrg () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~uclmrg
 *  Description:  默认析构函数 
 * =====================================================================================
 */
uclmrg::~uclmrg () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uclmrg  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
uclmrg::uclmrg(const uclmrg& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  init 
 *  Description:  初始化库文件 
 * =====================================================================================
 */
bool uclmrg::init() {
	if (ucl_init() != UCL_E_OK) {
		std::cout << "init ucl library fail" << std::endl;
		return false;
	}
	return true;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  release 
 *  Description:  释放相关资源 
 * =====================================================================================
 */
void uclmrg::release() {
	if ( outbuf != nullptr )
		delete[] outbuf;
	outbuf = nullptr;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  config 
 *  Description:  配置数据 
 * =====================================================================================
 */
void uclmrg::compress_config(u_int8_t* inb,u_int32_t length) {
	inbuf = inb;
	in_length = length;

	out_length = length + ( length >> 3 ) + 256;
	if ( outbuf != nullptr )
		delete[] outbuf;
	outbuf = nullptr;

	outbuf = new u_int8_t[out_length];
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  compress 
 *  Description:  进行数据压缩 
 * =====================================================================================
 */
bool uclmrg::compress() {
	int r = ucl_nrv2b_99_compress(inbuf,in_length,outbuf,&out_length,NULL,5,NULL,NULL);
	if (r == UCL_E_OUT_OF_MEMORY) {
		printf("out of memory in compress\n");
		return false;
	}

	if (r != UCL_E_OK) {
		/* this should NEVER happen */
		printf("internal error - compression failed: %d\n", r);
		return false;
	}
	return true;
}
