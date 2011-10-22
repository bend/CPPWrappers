/**
 *
 *       @file  PrimeSieve.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/19/2011 22:56:17
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <System/PrimeSieve.h>

PrimeSieve::PrimeSieve(unsigned long n, bool fillValue):
    m_limit(n)
{
    m_isPrime = new bool[m_limit + 1];
    this->fill(fillValue);
}

PrimeSieve::~PrimeSieve()
{
    delete[] m_isPrime;
}

void PrimeSieve::fill(bool v)
{
    unsigned long i;

    for (i = 2; i <= m_limit; ++i)
    {
        m_isPrime[i] = v;
    }
}

long PrimeSieve::getNumberOfPrimes() const
{
    long numberOfPrimes = 0;
    unsigned long i;

    for (i = 2; i < m_limit; ++i)
    {
        if (m_isPrime[i])
        {
            numberOfPrimes++;
        }
    }

    return numberOfPrimes;
}


vector<long> PrimeSieve::getPrimes()
{
    vector<long> v;
    unsigned long i;

    for (i = 2; i < m_limit; ++i)
    {
        if (m_isPrime[i])
        {
            v.push_back(i);
        }
    }

    return v;
}

long PrimeSieve::getBiggestPrime()
{
    unsigned long i;

    for (i = m_limit; i > 0; --i)
        if (m_isPrime[i])
            return i;
}
