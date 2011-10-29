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
#include <System/Semaphore.h>

Semaphore::Semaphore(char name[], unsigned int val)
{
    sem_unlink(name);
    this->name = name;
    this->sem = sem_open(name, O_CREAT | O_EXCL, 0666, val);
}

int Semaphore::wait()
{
    return sem_wait(sem);
}

int Semaphore::post()
{
    return sem_post(sem);
}

int Semaphore::tryWait()
{
    return sem_trywait(sem);
}

void Semaphore::close()
{
    sem_close(sem);
    sem_unlink(name);
}
