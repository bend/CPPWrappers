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
	/**
	 * @brief Constructor
	 * @param name the path to the log file.
	 * If the file does not exist, it will be created, otherwise, it will be openned in append mode
	 */
	Logger(string name);
	virtual ~Logger();
	/**
	 * @brief Log the stream input
	 * @param type: the Type of data to log (i.e. DEBUG, ERROR, ...)
	 * @param indent the indent level
	 */
	ofstream& log(string type, int indent=0);
	ofstream m_out;

private:
	string getTimeDate();


};

#endif
