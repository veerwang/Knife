/*
 * =====================================================================================
 *
 *       Filename:  tsmrg.cpp
 *
 *    Description:  触摸屏管理类 
 *
 *        Version:  1.0
 *        Created:  2020年04月13日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "tsmrg.h"
#include <iostream> 

#define MAXLEVEL 3
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  tsmrg
 *  Description:  默认构造函数 
 * =====================================================================================
 */
tsmrg::tsmrg () : minitflag(false), mlevel(0) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~tsmrg
 *  Description:  默认析构函数 
 * =====================================================================================
 */
tsmrg::~tsmrg () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  tsmrg  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
tsmrg::tsmrg(const tsmrg& theclass) : minitflag(false), mlevel(0) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  initilization 
 *  Description:  初始化变量 
 * =====================================================================================
 */
void tsmrg::initilization(int maxx,int maxy) {
	u_int8_t *mMask;
	int mMaxx;
	int mMaxy;

	for ( int i=0;i<MAXLEVEL;i++ ) {
		mMask = new u_int8_t[maxx * maxy];

		mMaxx = maxx;
		mMaxy = maxy;

		structpanel sp;
		sp.mMask = mMask;
		sp.mMaxx = mMaxx;
		sp.mMaxy = mMaxy;

		/* 初始化掩码 */
		reset_mask(sp);

		mpanel.push_back(sp);
	}
	minitflag = true;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  reset_mask 
 *  Description:  如果进入新的页面，需要进行界面掩码的清除 
 * =====================================================================================
 */
void tsmrg::reset_mask(structpanel& sp) {
	int length = ( (sp.mMaxx) * (sp.mMaxy) ) >> 2;
	int *m = (int *)(sp.mMask);
	for ( int i=0;i<length;i++ )
		 m[i]= 0;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  release 
 *  Description:  释放 
 * =====================================================================================
 */
void tsmrg::release() {
	if ( !minitflag ) {
		std::cout << "pls init first" << std::endl;
		return ;
	}

	for ( std::vector<structpanel>::iterator p=mpanel.begin();p!=mpanel.end();p++ ) {
		delete[] p->mMask;
		p->mMask = NULL;
	}
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  register_obj 
 *  Description:  将某个 界面控件的范围进行申请
 * =====================================================================================
 */
void tsmrg::register_obj (int x,int y,int w,int h,u_int8_t id) {
	for ( int j=0;j<h;j++ ) {
		for ( int i=0;i<w;i++ ) {
			mpanel[mlevel].mMask[x+i+(y+j) * mpanel[mlevel].mMaxx] = id;
		}
	}
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  unregister_obj 
 *  Description:  如果某个控件清除了，需要删除相关掩码位置 
 * =====================================================================================
 */
void tsmrg::unregister_obj (int x,int y,int w,int h) {
	for ( int j=0;j<h;j++ ) {
		for ( int i=0;i<w;i++ ) {
			mpanel[mlevel].mMask[x+i+(y+w) * mpanel[mlevel].mMaxx] = 0;
		}
	}
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_mask 
 *  Description:  将掩码的数值返还 
 * =====================================================================================
 */
u_int8_t tsmrg::get_mask(int px,int py) {
	return mpanel[mlevel].mMask[px + py * mpanel[mlevel].mMaxx];
}
	
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  up_level 
 *  Description:  增加层数 
 * =====================================================================================
 */
void tsmrg::up_level() {
	if ( mlevel + 1 < MAXLEVEL ) {
		mlevel ++;
		reset_mask(mpanel[mlevel]);
	}
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  dn_level 
 *  Description:  减少层数 
 *  		  减小层数的时候，无需清除
 * =====================================================================================
 */
void tsmrg::dn_level() {
	if ( mlevel - 1 >= 0 ) {
		mlevel --;
	}
}
