/**
 *
 *       @file  BufferedInput.h
 *
 *      @brief  Buffered input reader
 *
 *    @version  1.0
 *       @date  10/20/2011 19:21:52
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef BUFFERED_INPUT_H__
#define BUFFERED_INPUT_H__
#include <Fs/File.h>
#include <Fs/FileTypes.h>
class BufferedInput{
	public:
		BufferedInput(File &f);

		~BufferedInput();

		string readLine();

		string readWord();

		string read(int nb);

		bool eof();
		
		int close();
	
	private:
		File m_file;

};

#endif
