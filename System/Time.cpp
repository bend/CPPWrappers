/**
 *
 *       @file  Time.cpp
 *
 *      @brief  Get the system time
 *
 *    @version  1.0
 *       @date  10/12/2011 19:35:59
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#include <System/Time.h>

long Time::getTimeMilliseconds(){
	timeval time;
	gettimeofday(&time, 0);
	long millis = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return millis;
}

string Time::getTimeDate(){
	time_t lt;
	lt = time(NULL);
	string s(ctime(&lt));
	return s;
}

string Time::getTimeDate(string format){
	time_t now;
	struct tm* tm;
	string result = "";
	unsigned int i = 0;
	now = time(0);
	tm = localtime(&now);
	
	while(i < format.length()){
		switch(format[i]){
			case 'd': /* day */
				if(tm->tm_mday < 10)
					result.append("0");
				result.append(Types::toString(tm->tm_mday));
				i+=2;
				break;
			case 'M': /* Month */
				if(tm->tm_mon < 9)
					result.append("0");
				result.append(Types::toString(tm->tm_mon+1));
				i+=2;
				break;
			case 'Y': /* year */
				result.append(Types::toString((tm->tm_year+1900)));
				i+=4;
				break;
			case 'H': /* Hour */
				if(tm->tm_hour < 10)
					result.append("0");
				result.append(Types::toString(tm->tm_hour));
				i+=2;
				break;
			case 'm': /* Minutes */
				if(tm->tm_min < 10)
					result.append("0");
				result.append(Types::toString(tm->tm_min));
				i+=2;
				break;
			case 'S': /* Seconds */ 
				if(tm->tm_sec < 10)
					result.append("0");
				result.append(Types::toString(tm->tm_sec));
				i+=2;
				break;
			default:
				result.append(Types::toString(format[i]));
				i+=1;
				break;
		}
	}
	return result;
}

