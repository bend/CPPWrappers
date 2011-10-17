/**
 *
 *       @file  FileMode.cpp
 *
 *      @brief  File mode class, represents the file mode
 *
 *    @version  1.0
 *       @date  10/17/2011 15:40:16
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Fs/FileMode.h>

FileMode::FileMode(int mode):
	m_mode(mode)
{
	
}

FileMode::FileMode(string path):
	m_path(path)
{
	
}
