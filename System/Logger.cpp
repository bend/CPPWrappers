/**
 *
 *       @file  Logger.cpp
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/12/2011 16:31:37
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include<System/Logger.h>

Logger::Logger(){
}
std::ostringstream& Logger::log()
{
	os << "- " << getTimeDate()<< "-\t";
	return os;
}

string Logger::getTimeDate()
{
    char buffer[11];
    time_t t;
    time(&t);
    tm r = {0};
    strftime(buffer, sizeof(buffer), "%X", localtime_r(&t, &r));
    struct timeval tv;
    gettimeofday(&tv, 0);
    char result[100] = {0};
    std::sprintf(result, "%s.%03ld", buffer, (long)tv.tv_usec / 1000); 
    return result;
}

Logger::~Logger(){
    os << std::endl;
    fprintf(stdout, "%s", os.str().c_str());
    fflush(stdout);
}


