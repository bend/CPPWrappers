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
#include <vector>
using namespace std;
#include <System/AtkinSieve.h>
#include <System/EratostheneSieve.h>

class Prime {
public:
	static const int ERATOSTHENE_SIEVE;
	static const int ATKIN_SIEVE;
	
	Prime(unsigned long limit, const int& type=0);

	int genPrimes();

	long getBiggestPrime();

	vector<long> getPrimes();

	long getNumberOfPrimes();

    static bool isPrime(long num);

private:
	PrimeSieve *m_sieve;
	unsigned long m_limit;
	int m_type;


};

#endif
