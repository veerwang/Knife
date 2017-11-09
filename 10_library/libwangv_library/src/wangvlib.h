#if !defined(INCLUDED_WANGVLIB_H)
#define INCLUDED_WANGVLIB_H  1

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

/*　模块信息功能  */
const char* get_version();

/* log日志功能 */
const int LOG_ALL   = 1;
const int LOG_ERROR = 2;
const int LOG_WARN  = 3;
const int LOG_DEBUG = 4;
const int LOG_INFO  = 5;

void log_module_init(const char *device);
void log_module_destroy();
void log_module_level(int);
//void log_module_write(int level, const char *file, const char * func, int line, const char *fmt, ...);

/* key按键检测功能 */
void InitKey();
void RestoreKey();
char GetPCKey();

/* encrypt加密解密功能 */
int rename_file(const char* src,const char* des);
int copy_file(const char* src,const char* des);
int unlink_file(const char* file);
void encrypt_file(const char* src,const char* des);
void decrypt_file(const char* src,const char* des);

}

#endif /* !defined(INCLUDED_WANGVLIB_H) */
