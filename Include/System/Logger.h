/**
 *
 *       @file  Logger.h
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/12/2011 16:31:37
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef LOGGER_H__
#define LOGGER_H__

#include <iostream>
#include <sstream>

#include <sys/time.h>

using namespace std;
class Logger{
public:
	Logger();
	virtual ~Logger();
	ostringstream& log();
    ostringstream os;



private:
	string getTimeDate();



};

#endif
