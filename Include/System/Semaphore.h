/*
 * =====================================================================================
 *
 *       Filename:  Semaphore.h
 *
 *    Description:  A C++ Semaphore Wrapper
 *
 *        Version:  1.0
 *        Created:  07.06.2011 21:12:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ben D. (BD), dbapps2@gmail.com
 *        Company:  dbapps
 *
 * =====================================================================================
 */
#include <iostream>
#include <semaphore.h>
#include <fcntl.h>

class Semaphore {

public:
	/**
	 * @brief Constructor
	 * @param name: The name of the mutex, must start with '/' on linux systems
	 * @param val the initial value of the semaphore
	 */
    Semaphore(char name[], unsigned int val);

	/**
	 * @brief The semaphor is locked. When calling wait(), if the semaphore's value is zero, the calling thread will block until the lock is
	 *  acquired or until the call is interrupted by a signal. Alternatively, the trywait() function will fail if the semaphore is already locked, rather than
	 *  blocking on the semaphore.
	 *	@return If successful (the lock was acquired), wait() and trywait() will return 0.  Otherwise, -1 is returned and errno is set, and the state 
	 *	of the semaphore is unchanged.
	 */
    int wait();

	/**
	 * @brief The semaphore referenced by sem is unlocked, the value of the semaphore is incremented, and all threads which are waiting on the semaphore are awakened.
	 * @return If successful, post() will return 0.  Otherwise, -1 is returned and errno is set
	 */
    int post();

	/**
	 * @brief If the semaphore is locked wait() will not block and return an error, otherwise it will lock the semaphore
	 * @see wait()
	 */
    int tryWait();
	
	/**
	 * @brief Closes the semaphore
	 */
    void close();
private:
    sem_t *sem;
    char* name;


};
