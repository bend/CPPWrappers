/**
 *
 *       @file  AtkinSieve.h
 *
 *      @brief Atkin sieve prime generation class
 *
 *    @version  1.0
 *       @date  10/19/2011 23:21:59
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#ifndef ATKIN_SIEVE_H__
#define ATKIN_SIEVE_H__
#include <System/PrimeSieve.h>
#include <cmath>

class AtkinSieve: public PrimeSieve {
public :
    /**
     * @brief Constructor for the Atkin sieve
     * @param limit the maximum length of the prime number that you need
     */
    AtkinSieve(unsigned long limit);

    /**
     * @brief generates all the primes between 2 and limit using the Atkin sieve
     */
    void genPrimes();
};

#endif
