/**
 *
 *       @file  Mutex.h
 
 *      @brief  Pthread_mutex wrapper
 *
 *    @version  1.0
 *       @date  10/11/2011 13:40:46
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef MUTEX_H__
#define MUTEX_H__
#include <pthread.h>
class Mutex{
	public:
		Mutex();
		int lock();
		int tryLock();
		int unlock();
		int destroy();

	private:
		pthread_mutex_t *m_mutex;

};

#endif
