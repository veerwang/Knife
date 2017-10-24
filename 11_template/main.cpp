/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2017 09:14:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kevin (WangWei), wwei@landicorp.com
 *        Company:  Landicorp
 *   Organization:  GNU
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "head.h"

class Device
{
public:
	Device(){ std::cout<<"Device create"<<std::endl; }
	virtual ~Device(){ std::cout<<"Device destroy"<<std::endl; }
};

class Pig
{
public:
	Pig(){ std::cout<<"Pig create"<<std::endl; }
	virtual ~Pig(){ std::cout<<"Pig destroy"<<std::endl; }
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Base<int> base;
	base.m_ID = 20;
	std::cout<<base.m_ID<<std::endl;

	BasePolicy<int> bp;
	bp.Fire();

	Gun<int,MachinePolicy<char>> gun;
	gun.Trigger();
	
	Handle<Device> hd;

	SubHandle<Pig> sh;

	HostClass<> hc;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
