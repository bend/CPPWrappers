/**
 *
 *       @file  BufferedOutput.cpp
 *
 *      @brief  Buffered output class
 *
 *    @version  1.0
 *       @date  10/20/2011 16:49:18
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Fs/BufferedOutput.h>


BufferedOutput::BufferedOutput(File& f, const string& openMode, const int& buffLen):
    m_file(f),
    m_buffLen(buffLen),
    m_lastIndex(0) {
    if(openMode == FileTypes::APPEND || openMode == FileTypes::WRITE) {
        m_file.open(openMode);
        m_buffer = new char[buffLen];
    }
}

BufferedOutput::~BufferedOutput() {
    flush();
    delete[] m_buffer;
    m_file.close();
}

int BufferedOutput::write(const string &str) {
    if(!m_file.isOpenned())
        return -1;

    const char* s = str.c_str();
    return this->appendInBuffer(s, str.length());
}

int BufferedOutput::write(const char* str) {
    if(!m_file.isOpenned())
        return -1;
	int size = strlen(str);
    return this->appendInBuffer(str, size);
}

int BufferedOutput::write(const int &i) {
    if(!m_file.isOpenned())
        return -1;

    string str = TypeCast::toString(i);
    const char* s =  str.c_str();
    return this->appendInBuffer(s, str.length());
}

int BufferedOutput::write(const char &c) {
    if(!m_file.isOpenned())
        return -1;

    char temp[1];
    temp[0] = c;
    return this->appendInBuffer(temp, 1);
}

int BufferedOutput::write(const float &f) {
    if(!m_file.isOpenned())
        return -1;

    string str = TypeCast::toString(f);
    const char* s =  str.c_str();
    return this->appendInBuffer(s, str.length());
}

int BufferedOutput::write(const long &l) {
    if(!m_file.isOpenned())
        return -1;

    string str = TypeCast::toString(l);
    const char* s =  str.c_str();
    return this->appendInBuffer(s, str.length());
}

int BufferedOutput::write(const short &s) {
    if(!m_file.isOpenned())
        return -1;

    string str = TypeCast::toString(s);
    const char* ch =  str.c_str();
    return this->appendInBuffer(ch, str.length());
}

int BufferedOutput::flush() {
    if(!m_file.isOpenned())
        return -1;

    int i = 0;

    while(i < m_buffLen && i < m_lastIndex) {
        m_file.writec(m_buffer[i]);
        i++;
    }

    m_lastIndex = 0;
}

int BufferedOutput::close() {
    flush();
    return m_file.close();
}

int BufferedOutput::operator <<(const char &s){
	return write(s);
}

int BufferedOutput::operator <<(const short &s){
	return write(s);
}

int BufferedOutput::operator <<(const int &s){
	return write(s);
}

int BufferedOutput::operator <<(const long &s){
	return write(s);
}

int BufferedOutput::operator <<(const float &s){
	return write(s);
}

int BufferedOutput::operator <<(const string &s){
	return write(s);
}

int BufferedOutput::operator <<(const char *s){
	return write(s);
}

int BufferedOutput::appendInBuffer(const char* s, int l) {
    if(!m_file.isOpenned())
        return -1;

    int i = 0;

    while(i < l) {
        while(m_lastIndex < m_buffLen && i < l) {
            m_buffer[m_lastIndex] = s[i];
            ++i;
            m_lastIndex++;
        }

        if(m_lastIndex >= m_buffLen)
            flush();
    }

    return 0;
}
