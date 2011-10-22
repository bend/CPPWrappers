/**
 *
 *       @file  EratostheneSieve.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/19/2011 23:13:32
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <System/EratostheneSieve.h>

EratostheneSieve::EratostheneSieve(unsigned long n):
    PrimeSieve(n, true)
{
}

void EratostheneSieve::genPrimes()
{
    unsigned long i;
    unsigned long j;

    for (i = 2; i* i <= m_limit; ++i)
    {
        if (m_isPrime[i])
        {
            for (j = i + i; j <= m_limit; j += i)
            {
                m_isPrime[j] = false;
            }
        }
    }
}

