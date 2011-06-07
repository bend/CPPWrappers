/*
 * =====================================================================================
 *
 *       Filename:  Semaphore.cpp
 *
 *    Description:  A C++ Semaphore Wrapper 
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

#include "Semaphore.h"

Semaphore::Semaphore(char* name, unsigned int val){
	sem_unlink(name);
	this->name = name;
	this->sem = sem_open(name, O_CREAT|O_EXCL, 0666, val);
}

int Semaphore::wait(){
	return sem_wait(sem);
}

int Semaphore::post(){
	return sem_post(sem);
}

void Semaphore::close(){
	sem_close(sem);
	sem_unlink(name);
}
