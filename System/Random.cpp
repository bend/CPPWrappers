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

#include <System/Random.h>


Random::Random(RandomType algo):
    m_algo(algo)
{
}

int Random::init()
{
    switch (m_algo)
    {
        case MultiplyWCarry:
            return initMultiplyWithCarry();
            break;

        case BlumBlumShub:
            return initBlumBlum();
            break;

        case Unix:
            return initDefault();
            break;

        default:
            return -1;
    }
}

unsigned long Random::random()
{
    switch (m_algo)
    {
        case MultiplyWCarry:
            return multiplyWithCarryRand();
            break;

        case BlumBlumShub:
            return blumBlumRand();
            break;

        case Unix:
            return defaultRand();
            break;

        default:
            return -1;
    }
}

unsigned long Random::random(int min, int max)
{
    unsigned long rand;

    switch (m_algo)
    {
        case MultiplyWCarry:
            rand = multiplyWithCarryRand();
            break;

        case BlumBlumShub:
            rand = blumBlumRand();
            break;

        case Unix:
            rand = defaultRand();
            break;

        default:
            return -1;
    }

    int val = rand % (max - min + 1) + min;
    return val;
}

int Random::initDefault()
{
    srand ( time(NULL) );
}

unsigned long Random::defaultRand()
{
    return rand();
}

int Random::initMultiplyWithCarry()
{
    int x  = Time::getTimeMilliseconds();
    m_c = 362436;
    int i;
    m_q[0] = x;
    m_q[1] = x + 0x9e3779b9;
    m_q[2] = x + 0x9e3779b9 + 0x9e3779b9;

    for (i = 3; i < 4096; i++)
        m_q[i] = m_q[i - 3] ^ m_q[i - 2] ^ 0x9e3779b9 ^ i;
}

unsigned long Random::multiplyWithCarryRand()
{
    long t, a = 18782LL;
    static int i = 4095;
    int x, r = 0xfffffffe;
    i = (i + 1) & 4095;
    t = a * m_q[i] + m_c;
    m_c = (t >> 32);
    x = t + m_c;

    if (x < m_c)
    {
        x++;
        m_c++;
    }

    if ((m_q[i] = r - x) < 0)
        return -(m_q[i] = r - x);

    else return (m_q[i] = r - x);
}

int Random::initBlumBlum()
{
    long p, q;
    Prime pr(Time::getTimeMilliseconds() % 100000000);
    pr.genPrimes();
    p = pr.getBiggestPrime();
    Prime pr2((Time::getTimeMilliseconds() % 100000000) / ((Time::getTimeMilliseconds() % 20) + 1));
    pr2.genPrimes();
    q = pr2.getBiggestPrime();
    xn = Time::getTimeMilliseconds();
    m = p * q;
}

unsigned long Random::blumBlumRand()
{
    xn = (xn * xn) % m;

    if (xn < 0)
    {
        return -xn;
    }

    return xn;
}

