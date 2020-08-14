#ifndef INCLUDED_UCLMRG_H
#define INCLUDED_UCLMRG_H

/*
 * =====================================================================================
 *
 *       Filename:  uclmrg.h
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

#include 	<ucl/ucl.h>

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

class uclmrg {
public:
	uclmrg ();
	uclmrg (const uclmrg&);
	virtual ~uclmrg();

	bool init();
	void release();

	/*
	 * 配置程序，输入数据的缓冲区,缓冲区长度
	 */
	void config(u_int8_t* inbuf,u_int32_t length);
	bool compress();
	bool deprocess();

	u_int32_t out_length;
	u_int8_t* outbuf;

	u_int32_t in_length;
	u_int8_t* inbuf;
protected:
	
private:
	
};

#endif /* INCLUDED_UCLMRG_H */
