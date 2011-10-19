/**
 *
 *       @file  AtkinSieve.h
 *
 *      @brief
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

    AtkinSieve(unsigned long n);

    void genPrimes();






};

#endif
