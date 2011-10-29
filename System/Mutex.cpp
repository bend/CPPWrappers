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
#include <System/Mutex.h>

Mutex::Mutex()
{
    this->m_mutex = new pthread_mutex_t;
    pthread_mutex_init(m_mutex, NULL);
}

int Mutex::lock()
{
    if (pthread_mutex_lock(m_mutex) < 0)
        return -1;

    return 0;
}

int Mutex::unlock()
{
    if (pthread_mutex_unlock(m_mutex) < 0)
        return -1;

    return 0;
}

int Mutex::tryLock()
{
    if (pthread_mutex_trylock(m_mutex) < 0)
        return -1;

    return 0;
}

int Mutex::destroy()
{
    if (pthread_mutex_destroy(m_mutex) < 0)
        return -1;

    return 0;
}
