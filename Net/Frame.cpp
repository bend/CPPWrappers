
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

#include <Net/Frame.h>

Frame::Frame(uint32 size):
    m_allocSize(size),
    m_realSize(0),
    m_currentSeek(0)
{
    if (m_allocSize == 0)
        m_allocSize = 1;

    m_contents = new char[m_allocSize];
}

Frame::~Frame()
{
    delete[] m_contents;
}

void Frame::reallocateDouble()
{
    /* Reallocate 2 * size of m_contents */
    char* newContents = new char[m_allocSize * 2];
    memcpy(newContents, m_contents, m_allocSize);
    m_allocSize *= 2;
    delete m_contents;
    m_contents = newContents;
}

void Frame::append(const void* data, size_t size)
{
    /* Test if the m_contents array is too small to store the new char* */
    while (m_realSize + size > m_allocSize)
        reallocateDouble();

    /* Now we got the mem space, let's put the data in it */
    memcpy(&m_contents[m_realSize], data, size);
    m_realSize += size;
}

int Frame::read(void* data, size_t size)
{
    if (!data)
        return -1;

    if (m_currentSeek + size > m_realSize)
        return -1;

    memcpy(data, &m_contents[m_currentSeek], size);
    m_currentSeek += size;
}

Frame& Frame::operator << (const bool& b)
{
    append(&b, sizeof(bool));
    return *this;
}

Frame& Frame::operator << (const int8& i)
{
    append(&i, sizeof(i));
    return *this;
}

Frame& Frame::operator << (const int16& i)
{
    int16 n = htons(i);
    append(&n, sizeof(n));
    return *this;
}

Frame& Frame::operator << (const int32& i)
{
    int32 n = htonl(i);
    append(&n, sizeof(n));
    return *this;
}

Frame& Frame::operator << (const uint8& i)
{
    append(&i, sizeof(i));
    return *this;
}

Frame& Frame::operator << (const uint16& i)
{
    int16 n = htons(i);
    append(&n, sizeof(n));
    return *this;
}

Frame& Frame::operator << (const uint32& i)
{
    int32 n = htonl(i);
    append(&n, sizeof(n));
    return *this;
}

Frame& Frame::operator << (const char* c)
{
    int32 size = strlen(c);
    *this << size;
    append(c, size);
    return *this;
}

Frame& Frame::operator << (const float& f)
{
    append(&f, sizeof(f));
    return *this;
}

Frame& Frame::operator << (const double& d)
{
    append(&d, sizeof(d));
    return *this;
}

Frame& Frame::operator << (const string& s)
{
    int32 size = s.length();
    *this << size;
    append(s.c_str(), size);
    return *this;
}

Frame& Frame::operator >> (bool& b)
{
    read(&b, sizeof(b));
    return *this;
}

Frame& Frame::operator >> (int8& i)
{
    read(&i, sizeof(i));
    return *this;
}

Frame& Frame::operator >> (int16& i)
{
    read(&i, sizeof(i));
    i = ntohs(i);
    return *this;
}

Frame& Frame::operator >> (int32& i)
{
    read(&i, sizeof(i));
    i = ntohl(i);
    return *this;
}

Frame& Frame::operator >> (uint8& i)
{
    read(&i, sizeof(i));
    return *this;
}

Frame& Frame::operator >> (uint16& i)
{
    read(&i, sizeof(i));
    i = ntohs(i);
    return *this;
}

Frame& Frame::operator >> (uint32& i)
{
    read(&i, sizeof(i));
    i = ntohl(i);
    return *this;
}

Frame& Frame::operator >> (char* c)
{
    int32 size;
    *this >> size;
    read(c, size);
    return *this;
}

Frame& Frame::operator >> (float& f)
{
    read(&f, sizeof(f));
    return *this;
}

Frame& Frame::operator >> (double& d)
{
    read(&d, sizeof(d));
    return *this;
}

Frame& Frame::operator >> (string& s)
{
    int32 size;
    *this >> size;
    char* c = new char[size + 1];
    read(c, size);
    c[size] = '\0';
    s = string(c);
    delete[] c;
    return *this;
}

void Frame::setPosition(const uint32& pos)
{
    m_currentSeek = pos > m_realSize ? m_realSize : pos;
}

char* Frame::getData()
{
    return m_contents;
}
