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
class Semaphore{

	public:
		Semaphore(char* name, unsigned int val);
		int wait();
		int post();
		void close();
	private:
		sem_t *sem;
		char* name;


};
