/**
 *
 *       @file  Mutex.cpp
 *
 *      @brief  Pthread_mutex wrapper
 *
 *    @version  1.0
 *       @date  10/11/2011 13:40:46
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#include <System/Mutex.h>

Mutex::Mutex(){
	this->m_mutex = new pthread_mutex_t;
	pthread_mutex_init(m_mutex,NULL);
}

int Mutex::lock(){
	if(pthread_mutex_lock(m_mutex) < 0)
		return -1;
	return 0;
}

int Mutex::unlock(){
	if(pthread_mutex_unlock(m_mutex) < 0)
		return -1;
	return 0;
}

int Mutex::tryLock(){
	if(pthread_mutex_trylock(m_mutex) < 0)
		return -1;
	return 0;
}

int Mutex::destroy(){
	if(pthread_mutex_destroy(m_mutex)< 0)
		return -1;
	return 0;
}
