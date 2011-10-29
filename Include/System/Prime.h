/*
*   Copyright © Ben D.
*   dbapps2@gmail.com
*
*   This is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef PRIME_H__
#define PRIME_H__
#include <cmath>
#include <vector>
using namespace std;
#include <System/AtkinSieve.h>
#include <System/EratostheneSieve.h>

class Prime
{
    public:
        /**
         * @brief Enum of the different Sieve types to generate primes
         */
        enum SieveType
        {
            /** Eratosthene sieve **/
            Eratosthene,
            /** Atkin Sieve **/
            Atkin
        };

        /**
         * @brief Constructor of the prime class
         * @param limit the max length of the prime you need
         * @param type the SieveType to use default Eratosthene
         * @see SieveType
         */
        Prime(unsigned long limit, Prime::SieveType type = Eratosthene);

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
        PrimeSieve* m_sieve;
        unsigned long m_limit;
        SieveType m_type;

};

#endif
