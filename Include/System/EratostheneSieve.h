/**
 *
 *       @file  EratostheneSieve.h
 *
 *      @brief
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

class EratostheneSieve: public PrimeSieve {
public :
    EratostheneSieve(unsigned long n);

    void genPrimes();

};

#endif


