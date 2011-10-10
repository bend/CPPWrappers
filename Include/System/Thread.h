/*
 * =====================================================================================
 *
 *       Filename:  Thread.h
 *
 *    Description:  A C++ Thread Wrapper for the pthread lib
 *
 *        Version:  1.0
 *        Created:  07.06.2011 21:09:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ben D. (BD), dbapps2@gmail.com
 *        Company:  dbapps
 *
 * =====================================================================================
 */


#ifndef Thread_H
#define Thread_H

#include <pthread.h>

class Thread {
public:
    int start();
    void *join(Thread *thread);
    int detach();
    int equals(Thread* t);
    void exit(void* value_ptr);
    int cancel();
    pthread_t getThread();
	static void* go(void* obj);
	virtual void run() = 0;
private:
    pthread_t m_thread;

};

#endif
