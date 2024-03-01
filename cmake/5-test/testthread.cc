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
		void run()
		{
			gTicks ++;
		}
};

int
main(int argc, const char *argv[]) {
	WangV::ThreadBase<MyTestPolicy>* pthreadbase = new WangV::ThreadBase<MyTestPolicy>();
	pthreadbase->set_interval_second(0);
	pthreadbase->set_interval_millisecond(100);
	pthreadbase->start();

	sleep(1);

	if ( pthreadbase != NULL )
	{
		pthreadbase->stop();
		WangV::deletep(pthreadbase);
	}

	if (gTicks != 10)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}
