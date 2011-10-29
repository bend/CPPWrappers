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

#include <System/EratostheneSieve.h>

EratostheneSieve::EratostheneSieve(unsigned long n):
    PrimeSieve(n, true)
{
}

void EratostheneSieve::genPrimes()
{
    unsigned long i;
    unsigned long j;

    for (i = 2; i* i <= m_limit; ++i)
    {
        if (m_isPrime[i])
        {
            for (j = i + i; j <= m_limit; j += i)
            {
                m_isPrime[j] = false;
            }
        }
    }
}

