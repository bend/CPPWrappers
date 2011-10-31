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


#ifndef RANDOM_H__
#define RANDOM_H__

#include <System/Time.h>
#include <System/Prime.h>

#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * @brief Random number generator. There are 3 algorithm implemented.
 * @see Random::RandomType
 */
class Random
{
    public:

        /**
         * @brief Algorythm types enumeration
         */
        enum RandomType
        {
            /** Multiply with carry algorithm */
            MultiplyWCarry,
            /** Blum Blum Shub algorithm **/
            BlumBlumShub,
            /** Unix Algorithm **/
            Unix
        };

        /**
         * @brief Constructor of the class$
         * @param algo The algorithm to use to generate the random numbers. Default is Multiply with carry algorithm
         * @see RandomType
         */
        Random(RandomType algo = MultiplyWCarry);

        /**
         * @brief Initializes the value of the PRG choosen
         * @return 0 if success, -1 otherwise
         */
        int init();

        /**
         * @brief generates the next random number using the choosen algorithm
         * @return the generated number
         */
        unsigned long random();

        /**
         * @brief Generated the next random number using the choosen algorithm. The genrated number will be in the [min,max] interal.
         * @param min the lower bound of the interval
         * @param max the upper bound of the interval
         * @return the generated number
         */
        unsigned long random(int min, int max);

    private:

        int initDefault();

        unsigned long defaultRand();

        int initMultiplyWithCarry();

        unsigned long multiplyWithCarryRand();

        int  initBlumBlum();

        unsigned long blumBlumRand();

        RandomType m_algo;

        /* multiply with carry vars to init */
        int m_q[4096];
        int m_c;

        /* blum blum */
        long xn;
        long m;

};

#endif
