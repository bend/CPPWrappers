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
	/**
	 * @brief Use the Eratosthene sieve
	 */
    static const int ERATOSTHENE_SIEVE;

	/**
	 * @brief Use the Atkin sieve
	 */
    static const int ATKIN_SIEVE;
	
	/**
	 * @brief Constructor of the prime class
	 * @param limit the max length of the prime you need
	 * @param type  the type of sieve to use (default is Eratosthene Sieve)
	 * @see ERATOSTHENE_SIEVE
	 * @see ATKIN_SIEVE
	 */
    Prime(unsigned long limit, const int& type = 0);
	
	/**
	 * @brief Generates the primes using the choosen sieve
	 * @return 0 is success, -1 otherwise
	 */
    int genPrimes();
	
	/**
	 * @brief returns the biggest prime generated
	 * @return a long containing the prime
	 */
    long getBiggestPrime();
	
	/**
	 * @brief puts all the primes generated in a vector
	 * @return the vector containing these primes or an empy vector if an error occured
	 */
    vector<long> getPrimes();
	
	/**
	 * @brief Get the number of primes generated
	 * @return the number of primes generated
	 */
    long getNumberOfPrimes();
	
	/**
	 * @brief checks if the number is a prime or not
	 * @param num the number to check
	 * @return true if prime number, false otherwise
	 */
    static bool isPrime(long num);

private:
    PrimeSieve *m_sieve;
    unsigned long m_limit;
    int m_type;

};

#endif
