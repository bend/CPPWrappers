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

#include <System/PrimeSieve.h>

PrimeSieve::PrimeSieve(unsigned long n, bool fillValue):
    m_limit(n)
{
    m_isPrime = new bool[m_limit + 1];
    this->fill(fillValue);
}

PrimeSieve::~PrimeSieve()
{
    delete[] m_isPrime;
}

void PrimeSieve::fill(bool v)
{
    unsigned long i;

    for (i = 2; i <= m_limit; ++i)
    {
        m_isPrime[i] = v;
    }
}

long PrimeSieve::getNumberOfPrimes() const
{
    long numberOfPrimes = 0;
    unsigned long i;

    for (i = 2; i < m_limit; ++i)
    {
        if (m_isPrime[i])
        {
            numberOfPrimes++;
        }
    }

    return numberOfPrimes;
}


vector<long> PrimeSieve::getPrimes()
{
    vector<long> v;
    unsigned long i;

    for (i = 2; i < m_limit; ++i)
    {
        if (m_isPrime[i])
        {
            v.push_back(i);
        }
    }

    return v;
}

long PrimeSieve::getBiggestPrime()
{
    unsigned long i;

    for (i = m_limit; i > 0; --i)
        if (m_isPrime[i])
            return i;
}
