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

class BufferedInput{
	public:
		BufferedInput(File &f);

		readLine();

		readWord();

		read(int nb);
		
		close();

};

#endif
