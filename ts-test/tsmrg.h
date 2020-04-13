#ifndef INCLUDED_TSMRG_H
#define INCLUDED_TSMRG_H

/*
 * =====================================================================================
 *
 *       Filename:  tsmrg.h
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

#include <cstdlib>

class tsmrg {
public:
	tsmrg ();
	tsmrg (const tsmrg&);
	virtual ~tsmrg();

	void initilization(int maxx,int maxy);
	void release();

	void register_obj(int x,int y,int w,int h,u_int8_t id);
	void unregister_obj(int x,int y,int w,int h);
	void reset_mask();
	u_int8_t get_mask(int px,int py);
protected:
private:
	bool minitflag;
	u_int8_t *mMask;
	int mMaxx;
	int mMaxy;
};
#endif /* INCLUDED_TSMRG_H */
