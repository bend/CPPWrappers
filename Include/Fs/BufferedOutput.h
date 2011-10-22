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
#include <Fs/AbstractBufferIO.h>
#include <System/TypeCast.h>
#include <string.h>

class BufferedOutput:public AbstractBufferIO {

public:

    /**
     * @brief Constructor
     * @param f the File object in which we will write
     * @param openMode the open Mode (APPEND or WRITE)
     * @see FileTypes
     * @param buffLen the maximum buffer length to use (default is 1024 bytes)
     */
    BufferedOutput(File& f, const string& openMode, const int &buffLen = 1024);

    /**
     * @brief Destructor
     */
    ~BufferedOutput();

    /**
     * @brief writes the string to the buffer. When the buffer is full, the write function will flush it
     * @param str the string to write
     * @return 0 is success, -1 otherwise
     */
	AbstractBufferIO::Status write(const string &str);

    /**
     * @brief writes the char* to the buffer. When the buffer is full, the write function will flush it
     * @param s the string to write
     * @return 0 is success, -1 otherwise
     */
	AbstractBufferIO::Status write(const char *s);

    /**
     * @brief writes the int to the buffer. The int will be converted to string before being written.  When the buffer is full, the write function will flush it
     * @param i the int to write
     * @return 0 is success, -1 otherwise
     */
	AbstractBufferIO::Status write(const int &i);

    /**
     * @brief writes the char to the buffer. When the buffer is full, the write function will flush it
     * @param c the char to write
     * @return 0 is success, -1 otherwise
     */
	AbstractBufferIO::Status write(const char &c);

    /**
     * @brief writes the float to the buffer. The float will be converted to string before being written. When the buffer is full, the write function will flush it
     * @param f the float to write
     * @return 0 is success, -1 otherwise
     */
	AbstractBufferIO::Status write(const float &f);

    /**
     * @brief writes the string to the buffer. The long will be converted to string before being written. When the buffer is full, the write function will flush it
     * @param l the long to write
     * @return 0 is success, -1 otherwise
     */
	AbstractBufferIO::Status write(const long &l);

    /**
     * @brief writes the string to the buffer. The short will be converted to string before being written. When the buffer is full, the write function will flush it
     * @param s the short to write
     * @return 0 is success, -1 otherwise
     */
	AbstractBufferIO::Status write(const short &s);

    /**
     * @brief flushes the buffer and writes it contents to the file
     * @return 0 is success, -1 otherwise
     */
	AbstractBufferIO::Status flush();

    /**
     * @brief closes the file
     * @return 0 if success, -1 otherwise
     */
	AbstractBufferIO::Status close();

	/**
	 * @brief writes the char 
	 */
	BufferedOutput& operator <<(const char &s);
	
	/**
	 * @brief writes the short
	 */
	BufferedOutput& operator <<(const short &s);
	
	/**
	 * @brief writes the int
	 */
	BufferedOutput& operator <<(const int &s);
	
	/**
	 * @brief writes the long
	 */
	BufferedOutput& operator <<(const long &s);
	
	/**
	 * @brief writes the float
	 */
	BufferedOutput& operator <<(const float &s);

	/**
	 * @brief writes the string
	 */
	BufferedOutput& operator <<(const string &s);
	
	/**
	 * @brief writes the char*
	 */
	BufferedOutput& operator <<(const char *s);

private:

	AbstractBufferIO::Status appendInBuffer(const char* s, int l);

    File m_file;
    char* m_buffer;
    int m_buffLen;
    int m_lastIndex;

};

#endif
