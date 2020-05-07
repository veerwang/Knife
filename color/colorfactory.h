#ifndef INCLUDED_COLORFACTORY_H
#define INCLUDED_COLORFACTORY_H

/*
 * =====================================================================================
 *
 *       Filename:  colorfactory.h
 *
 *    Description:  根据输入的字符串,获得颜色 
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

#include <pimpltemplate.hpp>
#include <singletontemplate.hpp>

#include "graphic.h"

namespace WangV
{
class colorfactory : public WangV::Singleton<colorfactory> {
public:
	virtual ~colorfactory();

	RGBA getcolor(std::string);
protected:
	
private:
	ENABLE_SINGLETON(colorfactory)

	colorfactory ();
	colorfactory (const colorfactory&);
	
	WangV::PimplOf<colorfactory>::Type	m_imple;
};
}

#endif /* INCLUDED_COLORFACTORY_H */
