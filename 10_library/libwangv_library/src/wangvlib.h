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

#define LOG_ALL		1
#define LOG_ERROR	2
#define LOG_WARN	3 
#define LOG_DEBUG	4
#define LOG_INFO	5

void log_module_init(const char *device);
void log_module_destroy();
void log_module_level(int);
void log_module_write(int level, const char *file, const char * func, int line, const char *fmt, ...);
}

#endif /* MAIN_H */
