#if !defined(INCLUDED_LOGCATDISPLAY_H)
#define INCLUDED_LOGCATDISPLAY_H  1

/*
 * =====================================================================================
 *
 *       Filename:  logcatdisplay.h
 *
 *    Description:  用于编写日志显示功能
 *
 *        Version:  1.0
 *        Created:  2017年11月01日 19时34分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), kevin.wang2004@hotmail.com
 *        Company:  Landicorp 
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <standard.h>
#include "wangvlib.h"

namespace WangV
{
static const char* FG_WHITE  		= 	"\x1B[0;m"	;   /* white */
static const char* FG_RED    		= 	"\033[0;31m"	;   /* 0 -> normal ; 31 -> red */
static const char* FG_RED_BOLD  	=	"\033[1;31m" 	;   /* 1 -> bold ; 31 -> red */
static const char* FG_GREEN    		=	"\033[0;32m"  	;   /* 4 -> underline ; 32 -> green */
static const char* FG_GREEN_BOLD	=       "\033[1;32m"	;
static const char* FG_YELLOW 		=       "\033[0;33m"  	;   /* 0 -> normal ; 33 -> yellow */
static const char* FG_YELLOW_BOLD	=	"\033[1;33m"	;
static const char* FG_BLUE     		=	"\033[0;34m"  	;   /* 9 -> strike ; 34 -> blue */
static const char* FG_BLUE_BOLD    	=	"\033[1;34m"	;
static const char* FG_CYAN     		=	"\033[0;36m"    ;   /* 0 -> normal ; 36 -> cyan */
static const char* FG_CYAN_BOLD		=	"\033[0;36m"	;
static const char* FG_DEFAULT  		=	"\033[39m"	;
static const char* BG_RED      		=	"\033[41m"	;
static const char* BG_GREEN    		=	"\033[42m"	;
static const char* BG_BLUE     		=	"\033[44m"	;
static const char* BG_DEFAULT  		= 	"\033[49m"	;
static const char* RESET_COLOR    	=	"\033[0m" 	;/* to flush the previous property */

/*
static const int LOG_ALL 		= 	1		;
static const int LOG_ERROR		= 	2		;
static const int LOG_WARN		= 	3		;
static const int LOG_DEBUG		= 	4		;
static const int LOG_INFO		= 	5		;
*/

template <typename T>
class LogcatDisplay 
{
public:
	LogcatDisplay() 
	{ 
		log_device_fp = NULL; 
		log_level = 5; 
	}
	~LogcatDisplay() {;}

	void log_module_init(const char *device)
	{
		log_device_fp = !device ? stdout : fopen((const char *)device, "a+");
	}

	void log_module_destroy()
	{
		if (log_device_fp != stdout) fclose(log_device_fp);
	}

	void log_module_level(int level)
	{
		log_level = level;
	}

	void log_add(int level, const char *file, const char * func, int line, const char *msg)
	{
		const char *c = "IWEDX";
		const char *datetime_format = "%Y-%m-%d %H:%M:%S";
		time_t meow = time( NULL );
		char buf[64];
		int cl = 0;

		if ( level < log_level ) return;	
		switch (level) {
			case LOG_INFO : cl = 4; break;
			case LOG_WARN : cl = 3; break;
			case LOG_ERROR : cl = 2; break;
			case LOG_DEBUG : cl = 1; break;
			default : cl = 0; break;
		}	

		strftime( buf, sizeof(buf), datetime_format, localtime(&meow) );
		fprintf(log_device_fp, "%s%s[%d][%s(%s):%d] %c, %s%s\n",log_set_color(level, 0) , buf, (int)getpid(), file, func, line, c[cl], msg ,log_set_color(level, 1));
	}

	void log_module_write(int level, const char *file, const char * func, int line, const char *fmt, ...);

	const char* log_set_color(int level, int is_end)
	{
		if (log_device_fp == stdout) {
			if (is_end) {
				return RESET_COLOR;
			} else {
				switch (level) {
					case LOG_INFO : return FG_DEFAULT; break;
					case LOG_WARN : return FG_YELLOW; break;
					case LOG_ERROR : return FG_RED; break;
					case LOG_DEBUG : return FG_BLUE; break;
					default : return FG_WHITE; break;
				}
			}
		}
		return "";
	}

private:
	FILE *log_device_fp  ;
	int   log_level      ;
	static const int LOG_MAX_MSG_LEN;
};

template <typename T>
const int LogcatDisplay<T>::LOG_MAX_MSG_LEN = 4096; 

template <typename T>
void LogcatDisplay<T>::log_module_write(int level, const char *file, const char * func, int line, const char *fmt, ...)
{ 
	return;
}

template <typename T>
void LogcatDisplay<int>::log_module_write(int level, const char *file, const char * func, int line, const char *fmt, ...)
{ 
	va_list ap;
	char msg[LOG_MAX_MSG_LEN];

	va_start(ap, fmt);
	vsnprintf(msg, sizeof(msg), fmt, ap);  
	log_add(level, file, func, line, msg);    
	va_end(ap);
}

}

#endif /* !defined(INCLUDED_LOGCATDISPLAY_H) */
