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
#include <vector>

typedef struct panel {
	u_int8_t *mMask;
	int mMaxx;
	int mMaxy;
} structpanel;

class tsmrg {
public:
	tsmrg ();
	tsmrg (const tsmrg&);
	virtual ~tsmrg();

	void initilization(int maxx,int maxy);
	void release();

	void register_obj(int x,int y,int w,int h,u_int8_t id);
	void unregister_obj(int x,int y,int w,int h);
	void reset_mask(structpanel& sp);
	u_int8_t get_mask(int px,int py);

	void up_level();
	void dn_level();
protected:
private:
	bool minitflag;
	/* 考虑到内存利用的关系，只支持3层mask */
	int mlevel;
	std::vector<structpanel> mpanel;
};
#endif /* INCLUDED_TSMRG_H */
