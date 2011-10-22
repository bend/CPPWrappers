/**
 *
 *       @file  Prime.cpp
 *
 *      @brief  Prime number generator class
 *
 *    @version  1.0
 *       @date  10/19/2011 18:54:33
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#include <System/Prime.h>


Prime::Prime(unsigned long limit, Prime::SieveType type):
    m_limit(limit),
    m_type(type)
{
}

int Prime::genPrimes()
{
    switch (m_type)
    {
        case Eratosthene:
            m_sieve = new EratostheneSieve(m_limit);
            break;

        case Atkin:
            m_sieve = new AtkinSieve(m_limit);
            break;

        default:
            return -1;
    }

    m_sieve->genPrimes();
    return 0;
}

long Prime::getBiggestPrime()
{
    if (m_sieve != NULL)
        return m_sieve->getBiggestPrime();

    return -1;
}

vector<long> Prime::getPrimes()
{
    if (m_sieve != NULL)
        return m_sieve->getPrimes();

    return vector<long>();
}

long Prime::getNumberOfPrimes()
{
    if (m_sieve != NULL)
        return m_sieve->getNumberOfPrimes();

    return -1;
}

bool Prime::isPrime(long num)
{
    if (num <= 1)
        return false;

    if (num == 2)
        return true;

    if (num % 2 == 0)
        return false;

    long sRoot = sqrt(num * 1.0);
    int i;

    for (i = 3; i <= sRoot; i += 2)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}


