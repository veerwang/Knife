#ifndef INCLUDED_OBJECT_H
#define INCLUDED_OBJECT_H

/*
 * =====================================================================================
 *
 *       Filename:  object.h
 *
 *    Description:  类介绍 
 *
 *        Version:  1.0
 *        Created:  2020年07月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "mili/mili.h"

class object {
public:
	object ();
	object (const object&);
	virtual ~object();

private:
	int getid() const;
	void setid(int);

public:
	PROPERTIES {
		mili::PropertyRW<object, int, &object::getid, &object::setid> id;
	};

protected:
	
private:
	/*可以同时使用imple的接口，这样可以通过，变量方便访问控制 */
	int _id;	
};

#endif /* INCLUDED_OBJECT_H */
