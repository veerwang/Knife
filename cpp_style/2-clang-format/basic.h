#ifndef INCLUDED_BASIC_H
#define INCLUDED_BASIC_H

/*
 * =============================================================================
 *
 *       Filename:  basic.h
 *
 *    Description:  测试使用的类的头文件
 *
 *        Version:  1.0
 *        Created:  2021年08月03日
 *       Revision:  1
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang
 *   Organization:
 *
 * =============================================================================
 */

class Basic {
    public:
        Basic();
        Basic(const Basic &);
        virtual ~Basic();

	void Display();
    protected:
    private:
};

#endif /* INCLUDED_BASIC_H */
