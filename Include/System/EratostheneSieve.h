/**
 *
 *       @file  EratostheneSieve.h
 *
 *      @brief Eratosthene sieve prime generation class
 *
 *    @version  1.0
 *       @date  10/19/2011 23:13:32
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef ERATOSTHENE_H__
#define ERATOSTHENE_H__
#include <System/PrimeSieve.h>

class EratostheneSieve: public PrimeSieve
{
    public :

        /**
         * @brief Eratosthene Sieve constructor
         * @param limit the max length of the prime you need
         */
        EratostheneSieve(unsigned long limit);

        /**
         * @brief Generates all the primes between 0 and limit
         */
        void genPrimes();

};

#endif


