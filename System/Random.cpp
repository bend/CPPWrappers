/**
 *
 *       @file  Random.cpp
 *
 *      @brief  Random number generator class
 *
 *    @version  1.0
 *       @date  10/19/2011 00:44:20
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <System/Random.h>

const int Random::MULT_CARRY = 0;
const int Random::BLUM_BLUM = 1;
const int Random::UNIX = 2;

Random::Random(const int& algo):
	m_algo(algo)
{
}

int Random::init(){
	switch (m_algo){
		case MULT_CARRY:
			return initMultiplyWithCarry();
			break;
		case BLUM_BLUM:
			return initBlumBlum();
			break;
		case UNIX:
			return initDefault();
			break;
		default:
			return -1;
	}
}

int Random::random(){
	switch(m_algo){
		case MULT_CARRY:
			return multiplyWithCarryRand();
			break;
		case BLUM_BLUM:
			return blumBlumRand();
			break;
		case UNIX:
			return defaultRand();
			break;
		default:
			return -1;
	}
}

int Random::random(int min, int max){
	int rand;
	switch(m_algo){
		case MULT_CARRY:
			rand = multiplyWithCarryRand();
			break;
		case BLUM_BLUM:
			rand = blumBlumRand();
			break;
		case UNIX:
			rand = defaultRand();
			break;
		default:
			return -1;
	}
	int val = rand % (max-min+1)+min;
	return val;
}

int Random::initDefault(){
	srand ( time(NULL) );
}

int Random::defaultRand(){
	return rand();
}

int Random::initMultiplyWithCarry(){
	int x  = Time::getTimeMilliseconds();
	m_c = 362436;
	int i;

	m_q[0] = x;
	m_q[1] = x + 0x9e3779b9;
	m_q[2] = x + 0x9e3779b9 + 0x9e3779b9;

	for (i = 3; i < 4096; i++)
		m_q[i] = m_q[i - 3] ^ m_q[i - 2] ^ 0x9e3779b9 ^ i;
}

int Random::multiplyWithCarryRand(){
	long t, a = 18782LL;
	static int i = 4095;
	int x, r = 0xfffffffe;
	i = (i + 1) & 4095;
	t = a * m_q[i] + m_c;
	m_c = (t >> 32);
	x = t + m_c;
	if (x < m_c) {
		x++;
		m_c++;
	}
	if((m_q[i] = r - x)<0)
		return -(m_q[i] = r-x);
	else return (m_q[i] = r-x);
}


int Random::initBlumBlum(){
}

int Random::blumBlumRand(){
}

