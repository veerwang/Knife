#ifndef MAIN_H
#define MAIN_H

/*
 * =====================================================================================
 *
 *       Filename:  main.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年12月02日 10时18分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  LiLin-Tech
 *   Organization:  GNU
 *
 * =====================================================================================
 */
namespace WangV {
const char* get_version();

void LOG_INIT(const char *device);
const char* LOG_SET_COLOR(int level, int is_end);
void LOG_DESTORY();
void LOG_LEVEL();
void LOG_WRITER(int level, const char *file, const char * func, int line, const char *fmt, ...);
}

#endif /* MAIN_H */
