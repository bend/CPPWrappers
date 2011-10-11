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
	return 1;
}

int Mutex::unlock(){
	return 1;
}

int Mutex::tryLock(){
	return 1;
}

int Mutex::destroy(){
	return 1;
}
