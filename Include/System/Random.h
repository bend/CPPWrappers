/**
 *
 *       @file  Random.h
 *
 *      @brief  Random number generator class
 *
 *    @version  1.0
 *       @date  10/19/2011 00:55:50
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef RANDOM_H__
#define RANDOM_H__
#include <iostream>
#include <stdlib.h>
using namespace std;
#include <System/Time.h>
#include <System/Prime.h>
class Random {
public:
    /**
     * @brief Multiply with carry algorithm variable
     */
    static const int MULT_CARRY;

    /**
     * @brief Blum Blum Shub  algorithm variable
     */
    static const int BLUM_BLUM;

    /**
     * @brief default unix random gen
     */
    static const int UNIX;

    Random(const int& algo = 0);

    int init();

    unsigned long random();

    unsigned long random(int min, int max);

private:

    int initDefault();

    unsigned long defaultRand();

    int initMultiplyWithCarry();

    unsigned long multiplyWithCarryRand();

    int  initBlumBlum();

    unsigned long blumBlumRand();

    int m_algo;

    /* multiply with carry vars to init */
    int m_q[4096];
    int m_c;

    /* blum blum */
    long xn;
    long m;

};

#endif
