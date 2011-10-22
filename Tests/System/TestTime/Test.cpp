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
#include <System/Time.h>
#include <iostream>
using namespace std;
int main()
{
    cout << "Time ms " << Time::getTimeMilliseconds() << endl;
    cout << "Time date : " << Time::getTimeDate();
    cout << "Time date : " << Time::getTimeDate("dd/MM/YYYY - HH:mm::SS") << endl;
    cout << "Time date : " << Time::getTimeDate("dd - MM - YYYY @ HH_mm_SS") << endl;
}
