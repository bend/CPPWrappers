/**
 *
 *       @file  AbstractBufferIO.h
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/22/2011 18:43:28
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#ifndef ABSTRACT_BUFFER_IO
#define ABSTRACT_BUFFER_IO

#include <errno.h>

#include <Fs/File.h>
#include <Fs/FileTypes.h>
class AbstractBufferIO{
	public:
		enum Status {
			NotReady,
			Done,     
			Error,
			FileNotFound,
			Eof,
			NotOpen
		};
	
		AbstractBufferIO::Status getBufferStatus();
	protected:
		Status m_status;

};

#endif
