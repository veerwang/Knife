#if !defined(INCLUDED_HEAD_H)
#define INCLUDED_HEAD_H  1

/*
 * =====================================================================================
 *
 *       Filename:  head.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/24/2017 09:18:50 PM
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

/* Missile policy  */
template<typename T>
class SharkMissile
{
public:
	void trigger() { std::cout<<"SharkMissile honhonghong ......."<<std::endl; }
};

template<typename T>
class ArmyMissile
{
public:
	void trigger() { std::cout<<"ArmyMissile honhonghong ......."<<std::endl; }
};
/* Missile policy  */


/* fly policy  */

template<typename T>
class PigFly 
{
public:
	void go() { std::cout<<"PigFly huhuhuhu ......."<<std::endl; }
};

template<typename T>
class DogFly 
{
public:
	void go() { std::cout<<"DogFly huhuhuhu ......."<<std::endl; }
};

/* fly policy  */



/* Host class  */

template< template<typename> class Missile = ArmyMissile, template<typename> class Fly = DogFly >  // 注意T可以省略
class Weapon : public Missile<class T>,Fly<class T>						   // 注意只能用class
{
public:
	Weapon() { std::cout<<"Weapon create"<<std::endl;}
	~Weapon() { std::cout<<"Weapon destroy"<<std::endl;}

	void Trigger()
	{
		this->go();
		this->trigger();
	}
};

/* Host class  */

#endif /* !defined(INCLUDED_HEAD_H) */
