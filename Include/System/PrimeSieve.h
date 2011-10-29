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
