/**
 *
 *       @file  BufferedOutput.h
 *
 *      @brief  Buffered output class
 *
 *    @version  1.0
 *       @date  10/20/2011 16:49:18
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef BUFFERED_OUTPUT_H__
#define BUFFERED_OUTPUT_H__
#include <Fs/File.h>
#include <System/Types.h>
class BufferedOutput{

	public:
		BufferedOutput(File& f, const string& openMode, const int &buffLen = 1024);

		~BufferedOutput();

		int write(string str);

		int write(int i);

		int write(char c);

		int write(float f);

		int write(long l);

		int write(short s);

		int flush();

		int close();

	private:
		int appendInBuffer(const char* s, int l);

		File m_file;
		char* m_buffer;
	   	int m_buffLen;	
		int m_lastIndex;

};
	
#endif
