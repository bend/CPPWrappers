/*
 *
 *       	@file  Semaphore.cpp
 *
 *    	   @brief  A C++ Semaphore Wrapper
 *
 *       @version  1.0
 *        @date  07.06.2011 21:09:48
 *        @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <System/Semaphore.h>

Semaphore::Semaphore(char name[], unsigned int val) {
    sem_unlink(name);
    this->name = name;
    this->sem = sem_open(name, O_CREAT | O_EXCL, 0666, val);
}

int Semaphore::wait() {
    return sem_wait(sem);
}

int Semaphore::post() {
    return sem_post(sem);
}

int Semaphore::tryWait() {
    return sem_trywait(sem);
}

void Semaphore::close() {
    sem_close(sem);
    sem_unlink(name);
}
