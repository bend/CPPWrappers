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
    if(!m_file.isOpenned())
        return "";

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

    return result;
}

string BufferedInput::readWord() {
    if(!m_file.isOpenned())
        return "";

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

    return result;
}

string BufferedInput::read(int nb) {
    if(!m_file.isOpenned())
        return "";

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

    return result;
}

int BufferedInput::close() {
    m_file.close();
}

bool BufferedInput::eof() {
    return m_file.eof();
}


