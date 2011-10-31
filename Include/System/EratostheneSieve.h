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


#ifndef ERATOSTHENE_H__
#define ERATOSTHENE_H__
#include <System/PrimeSieve.h>

/**
 * @brief Eratosthene sieve implementation
 */
class EratostheneSieve: public PrimeSieve
{
    public :

        /**
         * @brief Eratosthene Sieve constructor
         * @param limit the max length of the prime you need
         */
        EratostheneSieve(unsigned long limit);

        /**
         * @brief Generates all the primes between 0 and limit
         */
        void genPrimes();

};

#endif


