#ifndef INCLUDED_DEVICE_H
#define INCLUDED_DEVICE_H

/*
 * =============================================================================
 *
 *       Filename:  device.h
 *
 *    Description:  类介绍 
 *
 *        Version:  1.0
 *        Created:  2021年09月23日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =============================================================================
 */

#include "base.h"

class Device : public Base {
  public:
	Device ();
	Device (const Device&);
	virtual ~Device();
	
	void Disp();
  protected:
	
  private:
	
};

#endif /* INCLUDED_DEVICE_H */
