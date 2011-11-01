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

#include <Fs/FileMode.h>

FileMode::FileMode(FileTypes::FilePermission mode):
    m_mode(mode)
{
}

FileMode::FileMode(int mode):
	m_mode(mode)
{
}

FileMode::operator int()
{
    return m_mode;
}

int FileMode::getMode()
{
    return m_mode;
}

string FileMode::getStringMode()
{
    char temp[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '\0'};

    if (m_mode & FileTypes::RU) temp[0] = 'r';

    if (m_mode & FileTypes::WU) temp[1] = 'w';

    if (m_mode &  FileTypes::XU) temp[2] = 'x';

    if (m_mode &  FileTypes::RG) temp[3] = 'r';

    if (m_mode &  FileTypes::WG) temp[4] = 'w';

    if (m_mode &  FileTypes::XG) temp[5] = 'x';

    if (m_mode &  FileTypes::RO) temp[6] = 'r';

    if (m_mode &  FileTypes::WO) temp[7] = 'w';

    if (m_mode &  FileTypes::XO) temp[8] = 'x';

    return string(temp);
}
