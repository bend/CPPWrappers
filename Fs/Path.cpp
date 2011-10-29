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

#include <Fs/Path.h>

Path::Path(string path):
    m_path(path)
{
}

Path Path::getAbsolutePath()
{
    if (m_path[0] == '/')
        return m_path;

    char thePath[256];
    string temp = m_path;
    string res;
    getcwd(thePath, 255);
    int level = 0;
    int i = 0;

    while (temp[0] == '.')
    {
        if (temp[1] == '.')
        {
            temp = temp.substr(2);

            if (temp[0] == '/')
                temp = temp.substr(1);

            level++;
        }

        else
        {
            temp = temp.substr(1);

            if (temp[0] == '/')
                temp = temp.substr(1);
        }
    }

    res = string(thePath);

    while (level != 0 && i < level)
    {
        if (res[res.length() - 1] == '/')
            res = res.substr(0, res.length() - 2);

        string::size_type loc = res.find_last_of("/");

        if (loc != string::npos)
            res = res.substr(0, loc);

        else
            res = "";

        i++;
    }

    res.append("/");
    res.append(temp);
    return  Path(res);
}

string Path::getName()
{
    if (m_path[m_path.length() - 1] == '/')
        m_path = m_path.substr(0, m_path.length() - 2);

    string::size_type loc = m_path.find_last_of("/");

    if (loc == string::npos)
        return m_path;

    return m_path.substr(loc + 1);
}

Path Path::getParent()
{
    string p = getAbsolutePath().toString();

    if (p[p.length() - 1] == '/')
        p = p.substr(0, p.length() - 2);

    string::size_type loc = p.find_last_of("/");

    if (loc == string::npos)
        return p;

    return Path(p.substr(0, loc));
}

string Path::toString()
{
    return m_path;
}

Path::operator const char* ()
{
    return m_path.c_str();
}
