#ifndef INCLUDED_NANOTHREAD_HPP
#define INCLUDED_NANOTHREAD_HPP

/*!
  \file    nanothread.hpp
  \brief   nanothread template declare

  \version 2024-03-01, V1.0
  \author	 kevin.wang
  \note    none
  */

#include 	<thread>
#include    <atomic>
#include    <mutex>
#include 	<functional>

namespace WangV
{
	template<typename T>
		class DefaultNanoThreadPolicy
		{
			public:
				void run()
				{
					//			std::cout<<"... "<<std::endl;
				}
		};

	struct PImple
	{
		std::thread*			body;
		std::atomic<bool>       runflag;
		std::atomic<bool>       stopflag;
		std::atomic<bool>       pauseflag;
		std::mutex  			lock;

		int                     interval_second;          // 在 RUN 中调度的间隔参数
		int						interval_millisecond;
	};

	template<template <typename T > class baseclass=DefaultNanoThreadPolicy>
		class ThreadBase : public baseclass<class T>
	{
		public:
			ThreadBase() : mImple( new struct PImple )
		{
			mImple->body 	     = new std::thread(std::bind(&ThreadBase::ThreadLoop,this));
			mImple->runflag              = false;
			mImple->stopflag             = false;
			mImple->pauseflag            = false;
			mImple->interval_second      = 0;
			mImple->interval_millisecond = 0;
		}

			~ThreadBase()
			{
				if ( mImple->body->joinable() )
				{
					mImple->body->join();
					delete mImple->body;
				}
			}

			void start()
			{
				mImple->runflag = true;
			}

			void stop()
			{
				mImple->stopflag = true;
			}

			void pause()
			{
				mImple->pauseflag = true;
			}

			void resume()
			{
				mImple->pauseflag = false;
			}

			void set_interval_second(const int& v)
			{
				mImple->interval_second = v;
			}

			void set_interval_millisecond(const int& v)
			{
				mImple->interval_millisecond = v;
			}

		protected:
			void ThreadLoop()
			{
				while ( !mImple->runflag )
					std::this_thread::yield();

				while ( !mImple->stopflag )
				{
					while ( mImple->pauseflag )
						std::this_thread::yield();
					// 注意此地的用法
					this->run();

					std::this_thread::sleep_for(std::chrono::seconds(mImple->interval_second)+std::chrono::milliseconds(mImple->interval_millisecond));
				}
			}

		protected:
			friend struct PImple;
			std::unique_ptr<struct PImple> mImple;
	};

}
#endif /* INCLUDED_NANOTHREAD_HPP */
