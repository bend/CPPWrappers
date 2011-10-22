/**
 *
 *       @file  BufferedInput.cpp
 *
 *      @brief  Buffered input reader
 *
 *    @version  1.0
 *       @date  10/20/2011 19:21:52
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Fs/BufferedInput.h>

BufferedInput::BufferedInput(File& f):
    m_file(f) {
    m_file.open(FileTypes::READ);
}

BufferedInput::~BufferedInput() {
    close();
}

string BufferedInput::readLine() {
    if(!m_file.isOpenned()) {
        m_status = NotOpen;
        return "";
    }

    string result = "";
    char c;

    if(m_file.eof())
        return result;

    do {
        c = m_file.readc();

        if(m_file.eof() || c == FileTypes::ENDOFFILE )
            return result;

        if(c != '\n')
            result += c;
    } while(c != '\n' && !m_file.eof());

    m_status = Done;
    return result;
}

string BufferedInput::readWord() {
    if(!m_file.isOpenned()) {
        m_status = NotOpen;
        return "";
    }

    string result = "";
    char c;

    if(m_file.eof())
        return result;

    do {
        c = m_file.readc();

        if(m_file.eof() || c == FileTypes::ENDOFFILE )
            return result;

        if(c != ' ' && c != '\n')
            result += c;
    } while(c != ' ' && c != '\n' && !m_file.eof());

    m_status = Done;
    return result;
}

string BufferedInput::read(int nb) {
    if(!m_file.isOpenned()) {
        m_status = NotOpen;
        return "";
    }

    string result = "";
    int i = 0;
    char c;

    if(m_file.eof())
        return result;

    while(i < nb) {
        c = m_file.readc();

        if(m_file.eof() || c == FileTypes::ENDOFFILE )
            return result;

        result += c;
        ++i;
    }

    m_status = Done;
    return result;
}

void BufferedInput::close() {
    m_file.close();
    m_status = Done;
}

bool BufferedInput::eof() {
    return m_file.eof();
}

BufferedInput& BufferedInput::operator >>(string &data) {
    data = readLine();
    return *this;
}

BufferedInput& BufferedInput::operator >>(char* ch) {
    string s = readLine();
    memcpy(ch, s.c_str() , s.length());
    ch[s.length()] = '\0';
    return *this;
}

BufferedInput& BufferedInput::operator >>(int &i) {
    string s = read(sizeof(i));
    i = *reinterpret_cast<const int*>(s.c_str());
    return *this;
}

BufferedInput& BufferedInput::operator >>(char &c) {
    c = read(1).c_str()[0];
    return *this;
}

BufferedInput& BufferedInput::operator >>(float &f) {
    string s = read(sizeof(f));
    f = *reinterpret_cast<const float*>(s.c_str());
    return *this;
}

BufferedInput& BufferedInput::operator >>(short &s) {
    string str = read(sizeof(s));
    s = *reinterpret_cast<const short*>(str.c_str());
    return *this;
}

BufferedInput& BufferedInput::operator >>(long &l) {
    string str = read(sizeof(l));
    l = *reinterpret_cast<const short*>(str.c_str());
    return *this;
}
