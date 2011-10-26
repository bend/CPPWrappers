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
#include <System/Logger.h>

int main()
{
    Logger l("log.txt");

    for (int i = 0; i < 5; i++)
    {
        l.log("INFO", 0) << "Hello";
    }
}
