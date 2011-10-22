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

AbstractBufferIO::Status BufferedOutput::write(const string &str) {
    if(!m_file.isOpenned()){
		m_status = NotOpen;
        return NotOpen;
	}

    const char* s = str.c_str();
    return this->appendInBuffer(s, str.length());
}

AbstractBufferIO::Status BufferedOutput::write(const char* str) {
    if(!m_file.isOpenned()){
		m_status = NotOpen;
        return NotOpen;
	}
	int size = strlen(str);
    return this->appendInBuffer(str, size);
}

AbstractBufferIO::Status BufferedOutput::write(const int &i) {
    if(!m_file.isOpenned()){
		m_status = NotOpen;
        return NotOpen;
	}

    string str = TypeCast::toString(i);
    const char* s =  str.c_str();
    return this->appendInBuffer(s, str.length());
}

AbstractBufferIO::Status BufferedOutput::write(const char &c) {
    if(!m_file.isOpenned()){
		m_status = NotOpen;
        return NotOpen;
	}

    char temp[1];
    temp[0] = c;
    return this->appendInBuffer(temp, 1);
}

AbstractBufferIO::Status BufferedOutput::write(const float &f) {
    if(!m_file.isOpenned()){
		m_status = NotOpen;
        return NotOpen;
	}

    string str = TypeCast::toString(f);
    const char* s =  str.c_str();
    return this->appendInBuffer(s, str.length());
}

AbstractBufferIO::Status BufferedOutput::write(const long &l) {
    if(!m_file.isOpenned()){
		m_status = NotOpen;
        return NotOpen;
	}

    string str = TypeCast::toString(l);
    const char* s =  str.c_str();
    return this->appendInBuffer(s, str.length());
}

AbstractBufferIO::Status BufferedOutput::write(const short &s) {
    if(!m_file.isOpenned()){
		m_status = NotOpen;
        return NotOpen;
	}

    string str = TypeCast::toString(s);
    const char* ch =  str.c_str();
    return this->appendInBuffer(ch, str.length());
}

AbstractBufferIO::Status BufferedOutput::flush() {
    if(!m_file.isOpenned()){
		m_status = NotOpen;
        return NotOpen;
	}

    int i = 0;

    while(i < m_buffLen && i < m_lastIndex) {
		if( m_file.writec(m_buffer[i])<0)
			return getBufferStatus();
        i++;
    }

    m_lastIndex = 0;
	m_status = Done;
	return Done;
}

AbstractBufferIO::Status BufferedOutput::close() {
    return flush();
}   

BufferedOutput& BufferedOutput::operator <<(const char &s){
	write(s);
	return *this;
}

BufferedOutput& BufferedOutput::operator <<(const short &s){
	write(s);
	return *this;
}

BufferedOutput& BufferedOutput::operator <<(const int &s){
	write(s);
	return *this;
}

BufferedOutput& BufferedOutput::operator <<(const long &s){
	write(s);
	return *this;
}

BufferedOutput& BufferedOutput::operator <<(const float &s){
	write(s);
	return *this;
}

BufferedOutput& BufferedOutput::operator <<(const string &s){
	write(s);
	return *this;
}

BufferedOutput& BufferedOutput::operator <<(const char *s){
	write(s);
	return *this;
}

AbstractBufferIO::Status BufferedOutput::appendInBuffer(const char* s, int l) {
    if(!m_file.isOpenned()){
		m_status = NotOpen;
        return NotOpen;
	}

    int i = 0;

    while(i < l) {
        while(m_lastIndex < m_buffLen && i < l) {
            m_buffer[m_lastIndex] = s[i];
            ++i;
            m_lastIndex++;
        }

        if(m_lastIndex >= m_buffLen)
            if(flush() != Done)
				return getBufferStatus();
    }
	m_status = Done;
    return Done;
}
