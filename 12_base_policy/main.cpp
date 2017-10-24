/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  这个项目用于实验 基于policy的模板编程
 *
 *        Version:  1.0
 *        Created:  10/24/2017 09:17:13 PM
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	std::cout<<"Programe V1.0.0"<<std::endl;

	std::cout<<"-----"<<std::endl;
	Weapon<SharkMissile> wp;
	wp.Trigger();
	std::cout<<"-----"<<std::endl;
	typedef Weapon<SharkMissile,PigFly> SDWeapon;		// 注意用法
	SDWeapon sdwp;
	sdwp.Trigger();
	std::cout<<"-----"<<std::endl;
	typedef Weapon<ArmyMissile,PigFly> ADWeapon;		// 注意用法
	ADWeapon adwp;
	adwp.Trigger();
	std::cout<<"-----"<<std::endl;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
