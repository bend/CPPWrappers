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

Logger::Logger(string path)
{
    m_out.open(path.c_str(), ofstream::app | ofstream::out);
}

std::ofstream& Logger::log(string type, int indent)
{
    int i = 0;

    while (i < indent)
    {
        m_out << "\t";
        i++;
    }

    m_out << endl << "[ " << type << " ] " << "[ ON " << getTimeDate() << " ]\t";
    return m_out;
}

string Logger::getTimeDate()
{
    return Time::getTimeDate("dd/MM/YYYY - HH:mm:SS");
}

Logger::~Logger()
{
    m_out << endl;
    m_out.flush();
    m_out.close();
}

