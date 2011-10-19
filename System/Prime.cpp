/**
 *
 *       @file  Prime.cpp
 *
 *      @brief  Prime number generator class
 *
 *    @version  1.0
 *       @date  10/19/2011 18:54:33
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <System/Prime.h>

bool Prime::isPrime(long num){
	if(num<=1)
		return false;
	if(num==2)
		return true;
	if(num%2==0)
		return false;
	long sRoot = sqrt(num*1.0);
	int i;
	for(i=3; i<=sRoot; i+=2){
		if(num%i==0)
			return false;
	}
	return true;
}


vector<long> isPrime::getAllPrimes(long min, long max){

}
