/*
 * =============================================================================
 *
 *       Filename:  base.cc
 *
 *    Description:  类介绍 
 *
 *        Version:  1.0
 *        Created:  2021年09月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include <iostream>
#include "base.h"

const int Base::MAXACCOUNT = 5;

typedef struct Opt {
	int Version[Base::MAXACCOUNT];
} OPT;


/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  Base
 *  Description:  默认构造函数 
 * =============================================================================
 */
Base::Base () {
}

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ~Base
 *  Description:  默认析构函数 
 * =============================================================================
 */
Base::~Base () {
}

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  Base 
 *  Description:  拷贝构造函数 
 * =============================================================================
 */
Base::Base(const Base& theclass) {
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  Disp
 *  Description:  显示内容 
 * ============================================================================
 */
void Base::Disp() {
	// 关键点
	int Infop[Base::MAXACCOUNT];
	for (int i = 0; i < Base::MAXACCOUNT; i++) {
		Infop[i] = 2;
	}
	std::cout << Infop[1] << std::endl;
}
