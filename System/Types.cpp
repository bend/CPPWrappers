/**
 *
 *       @file  Types.cpp
 *
 *      @brief  Types class
 *
 *    @version  1.0
 *       @date  10/13/2011 09:28:55
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <System/Types.h>


string Types::toString(int i){
	stringstream oss;
	oss << i;
	return oss.str();
}

string Types::toString(char c){
	stringstream oss;
	oss << c;
	return oss.str();
}
