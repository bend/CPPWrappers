/**
 *
 *       @file  Prime.h
 *
 *      @brief  Prime number generator class
 *
 *    @version  1.0
 *       @date  10/19/2011 18:54:33
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef PRIME_H__
#define PRIME_H__
#include <cmath>

class Prime{
	public:
		static bool isPrime(long num);
		
		static vector<long> getAllPrimes(long min, long max);



};

#endif
