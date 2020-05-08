/*
 * =====================================================================================
 *
 *       Filename:  colorfactory.cpp
 *
 *    Description:  颜色定义的实现 
 *
 *        Version:  1.0
 *        Created:  2020年05月07日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "colorfactory.h"

#include <stdcpphead.h>

#include "graphic.h"

namespace WangV
{

typedef struct colorelement {
	RGBA  color;
	std::string  name;
} COLORELEMENT;

template<>
struct ImplOf<colorfactory> {
	std::list<COLORELEMENT> mlist;

	void init_color_element();
};

#define COLORMACRO(VALUE) { \
		e.name 	= std::string(#VALUE); \
		e.color = graphic::VALUE; \
		mlist.push_back(e); \
		} while( 0 );

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  init_color_element 
 *  Description:  初始化颜色列表 
 * =====================================================================================
 */
void ImplOf<colorfactory>::init_color_element() {
	mlist.clear();
	COLORELEMENT e;
	e.name 	= std::string("Black");
	e.color = graphic::Black;
	mlist.push_back(e);
	e.name  = std::string("Yellow");
	e.color = graphic::Yellow;
	mlist.push_back(e);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  colorfactory
 *  Description:  默认构造函数 
 * =====================================================================================
 */
colorfactory::colorfactory () {
	m_imple->init_color_element();
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ~colorfactory
 *  Description:  默认析构函数 
 * =====================================================================================
 */
colorfactory::~colorfactory () {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  colorfactory  
 *  Description:  拷贝构造函数 
 * =====================================================================================
 */
colorfactory::colorfactory(const colorfactory& theclass) {
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getcolor 
 *  Description:  显示颜色 
 * =====================================================================================
 */
RGBA 
colorfactory::getcolor(std::string name) {
	for( std::list<COLORELEMENT>::iterator element = (m_imple->mlist).begin(); element != (m_imple->mlist).end(); element ++ ) {
		if ( name == element->name )
			return element->color;
	}
	std::cout << "error color name: " << name << std::endl;
	return graphic::Black;
}

}
