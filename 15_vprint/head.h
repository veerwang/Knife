#if !defined(INCLUDED_HEAD_H)
#define INCLUDED_HEAD_H  1

/*
 * =====================================================================================
 *
 *       Filename:  head.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/2017 11:28:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), wwei@landicorp.com
 *        Company:  Landicorp
 *   Organization:  GNU
 *
 * =====================================================================================
 */

template <typename T>
class Base
{
#define LOG_MAX_MSG_LEN 4098
public:
	Base() {;}
	~Base() {;}

	void Display(const char *fmt, ...)
	{
		va_list ap;
    		char msg[LOG_MAX_MSG_LEN];
		va_start(ap, fmt);
    		vsnprintf(msg, sizeof(msg), fmt, ap);  
		va_end(ap);
	}
};

#endif /* !defined(INCLUDED_HEAD_H) */
