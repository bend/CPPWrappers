/**
 *
 *       @file  TypeCast.cpp
 *
 *      @brief  TypeCast class
 *
 *    @version  1.0
 *       @date  10/13/2011 09:28:55
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <System/TypeCast.h>


string TypeCast::toString(int i)
{
    stringstream oss;
    oss << i;
    return oss.str();
}

string TypeCast::toString(long i)
{
    stringstream oss;
    oss << i;
    return oss.str();
}

string TypeCast::toString(float i)
{
    stringstream oss;
    oss << i;
    return oss.str();
}

string TypeCast::toString(char c)
{
    stringstream oss;
    oss << c;
    return oss.str();
}

