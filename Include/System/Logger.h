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
#include <fstream>

#include <System/Time.h>
using namespace std;
class Logger{
public:
	Logger(string name);
	virtual ~Logger();
	ofstream& log(string type, int indent=0);
	ofstream m_out;

private:
	string getTimeDate();


};

#endif
