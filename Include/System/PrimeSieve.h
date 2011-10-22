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
class PrimeSieve
{

    public :
        /**
         * @brief destructor of the class
         */
        ~PrimeSieve();

        /**
         * @brief Get the number of primes generated
         * @return the number of primes generated
         */
        long getNumberOfPrimes() const;

        /**
         * @brief puts all the primes generated in a vector
         * @return the vector containing these primes or an empy vector if an error occured
         */
        vector<long> getPrimes();

        /**
         * @brief returns the biggest prime generated
         * @return a long containing the prime
         */
        long getBiggestPrime();

        /**
         * @brief Generates the primes using the choosen sieve
         * @return 0 is success, -1 otherwise
         */
        virtual void genPrimes() = 0;

    protected:
        /**
         * Contructor of the abstract class PrimeSieve
         * @param limit the max length of the prime you need
         * @param fillValue the value with which we will fill the grid at initialization
         */
        PrimeSieve(unsigned long limit, bool fillValue);

        /**
         * @brief fills the grid with the fillValue
         * @param v the fill value
         */
        void fill(bool v);

        const unsigned long m_limit;
        bool* m_isPrime;
};

#endif
