/*!
  \file    testthread.cc
  \brief   test case for thread

  \version 2024-03-01, V1.0
  \author	 kevin.wang
  \note    none
  */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unistd.h>

#include "api.h"
#include "utils/nanothread.hpp"
#include "utils/misce.hpp"

int gTicks = 0;

template<typename T>
class MyTestPolicy
{
	public:
		void Run()
		{
			gTicks ++;
		}
};

int
main(int argc, const char *argv[]) {
	WangV::ThreadBase<MyTestPolicy>* pthreadbase;
	pthreadbase = new WangV::ThreadBase<MyTestPolicy>();
	pthreadbase->Set_Interval_Second(0);
	pthreadbase->Set_Interval_MilliSecond(100);
	pthreadbase->Start();

	sleep(1);

	if ( pthreadbase != NULL )
	{
		pthreadbase->Stop();
		WangV::deletep(pthreadbase);
	}

	if (gTicks != 10)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}
