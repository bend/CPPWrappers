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

#ifndef ATKIN_SIEVE_H__
#define ATKIN_SIEVE_H__

#include <System/PrimeSieve.h>

#include <cmath>

/**
 * @brief Atkin Sieve implementation
 */
class AtkinSieve: public PrimeSieve
{
    public :
        /**
         * @brief Constructor for the Atkin sieve
         * @param limit the maximum length of the prime number that you need
         */
        AtkinSieve(unsigned long limit);

        /**
         * @brief generates all the primes between 2 and limit using the Atkin sieve
         */
        void genPrimes();
};

#endif
