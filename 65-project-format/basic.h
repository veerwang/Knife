#ifndef INCLUDED_BASIC_H
#define INCLUDED_BASIC_H

/*
 * =============================================================================
 *
 *       Filename:  basic.h
 *
 *    Description:  基本框架类
 *
 *        Version:  1.0
 *        Created:  2021年06月08日
 *       Revision:  1
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang
 *   Organization:
 *
 * =============================================================================
 */
class basic {
  public:
        basic();
        basic(const basic&);
        virtual ~basic();

	void disp_name();
  protected:
  private:
};

#endif /* INCLUDED_BASIC_H */
