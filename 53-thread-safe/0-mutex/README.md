1.最最基础的多线程的同步方式

a.
static std::mutex mtx;           	 // mutex for critical section
mtx.lock();
mtx.unlock();

mtx.try_lock();
mtx.unlock();
二者成对出现

b.static std::mutex mtx;           	 // mutex for critical section
mtx.lock();
mtx.try_lock();区别在于try_lock()函数,如果没有锁住，那么就立即返回，
，如果锁住了，就返回true。
总之，就是非阻塞方式的
