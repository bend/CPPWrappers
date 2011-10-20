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
	m_lastIndex(0){
	m_file.open(openMode);
	m_buffer = new char[buffLen];
}

BufferedOutput::~BufferedOutput(){
	flush();
	delete[] m_buffer;
	m_file.close();
}

int BufferedOutput::write(string str){
	const char* s = str.c_str();
	return this->appendInBuffer(s, str.length());
}

int BufferedOutput::write(int i){
}

int BufferedOutput::write(char c){
	char temp[1];
	temp[0] = c;
	return this->appendInBuffer(temp,1);
}

int BufferedOutput::write(float f){
	
}

int BufferedOutput::write(long l){

}

int BufferedOutput::write(short s){

}

int BufferedOutput::flush(){
	cout<<"flushing"<<endl;
	int i = 0;
	while(i<m_buffLen && i<m_lastIndex){
		m_file.writec(m_buffer[i]);
		cout<<"m_buffer["<<i<<"]"<<m_buffer[i]<<endl;
		i++;
	}
	m_lastIndex = 0;
}

int BufferedOutput::appendInBuffer(const char* s,int l){
	int i = 0;
	while(i<l){
		while(m_lastIndex<m_buffLen && i<l){
			m_buffer[m_lastIndex] = s[i];
			cout<<"added s["<<i<<"]"<<s[i]<<endl;
			++i;
			m_lastIndex++;
		}
		if(m_lastIndex >= m_buffLen)
			flush();
	}
	return 0;
}
