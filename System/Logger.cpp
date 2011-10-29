/*
*   Copyright © Ben D.
*   dbapps2@gmail.com
*
*   This is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

