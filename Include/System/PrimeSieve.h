/**
 *
 *       @file  PrimeSieve.h
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/19/2011 22:56:17
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef PRIME_SIEVE_H__
#define PRIME_SIEVE_H__
#include <vector>
using namespace std;
class PrimeSieve {

protected:
    const unsigned long m_limit;
    bool *m_isPrime;

    void fill(bool v);
public :
    PrimeSieve(unsigned long n, bool fillValue);

    ~PrimeSieve();

    long getNumberOfPrimes() const;

    vector<long> getPrimes();

    long getBiggestPrime();

    virtual void genPrimes() = 0;
};

#endif
