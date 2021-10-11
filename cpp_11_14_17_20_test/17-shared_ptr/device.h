#ifndef INCLUDED_DEVICE_H
#define INCLUDED_DEVICE_H

/*
 * =============================================================================
 *
 *       Filename:  device.h
 *
 *    Description:  Device类 
 *
 *        Version:  1.0
 *        Created:  2021年10月11日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include "base.h" 
#include <memory>

class Device {
  public:
	Device ();
	Device (const Device&);
	virtual ~Device();

	void Display();
  protected:
	
  private:
	// 没有触发 Base的构造与析函数
	std::shared_ptr<Base> mBase;
	
};

#endif /* INCLUDED_DEVICE_H */
