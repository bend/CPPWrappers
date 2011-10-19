/**
 *
 *       @file  Test.cpp
 *
 *      @brief
 *
 *    @version  1.0
 *       @date  10/12/2011 19:04:44
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#include <System/Prime.h>
#include <iostream>
using namespace std;

int main() {
	//cout<<Prime::isPrime( 18014398241046527)<<endl;
	long i;
	while(++i<1000000000000)
		cout<<"Is prime : "<<i<<" : "<<Prime::isPrime(i)<<endl;
}
