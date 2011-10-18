/**
 *
 *       @file  File.cpp
 *
 *      @brief  File class
 *
 *    @version  1.0
 *       @date  10/16/2011 23:28:02
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Fs/File.h>



File::File(Path& p):
    m_path(p)
{
}

int File::open(const string& mode) {
    m_f = fopen(m_path, mode.c_str());

    if(m_f == NULL)
        return -1;

    return 0;
}

bool File::exists() {
    FILE* file;

    if(file = fopen(m_path, "r")) {
        fclose(file);
        return true;
    }

    fclose(file);
    return false;
}

int File::remove() {
    return ::remove(m_path);
}

int File::close() {
    return fclose(m_f);
}

long File::getSize() {
    struct stat file_status;

    if (stat(m_path, &file_status) < 0) {
        return -1;
    }

    return file_status.st_size;
}

FileMode File::getMode() {
    struct stat file_status;

    if (stat(m_path, &file_status) < 0) {
        return FileMode(-1);
    }

    return FileMode(file_status.st_mode);
}

vector<string> File::getList() {
    vector<string> vect;
    DIR *dir = opendir(m_path);
    struct dirent *ent;

    if (dir == NULL)
        return vect;

    while ((ent = readdir (dir)) != NULL) {
        string t;
        t = string(ent->d_name);
		if(t != "." && t != "..")
			vect.push_back(t);
    }

    return vect;
}

Path File::getPath() {
    return m_path;
}

bool File::isFile() {
	struct stat file_status;
	if (stat(m_path, &file_status) < 0) {
		return false;
	}
	if (file_status.st_mode & S_IFREG) {
		return true;
	}
	return false;
}

bool File::isDirectory() {
	struct stat file_status;
	if (stat(m_path, &file_status) < 0) {
		return false;
	}
	if (file_status.st_mode & S_IFDIR) {
		return true;
	}
	return false;
}

int File::mkdir() {
	return ::mkdir(m_path, 0755);
}

int File::setMode(FileMode& mode){
	return chmod(m_path,mode);
}

int File::renameTo(File & f) {
	if(f.exists() || !this->exists())
		return -1;

	return rename( m_path , f.getPath());

}

int File::seek(int offset, int origin){
	return fseek(m_f, offset, origin);
}

int File::copyTo(File &to) {
	char ch;
	this->close();
	this->open(FileTypes::READ);
	to.close();
	to.open(FileTypes::WRITE);
	while(!this->eof()) {
		ch = this->readc();
		if(ch == -1)
			return 0;
		if(!to.eof()) 
			to.writec(ch);
	}

	if(this->close()<0) {
		return -1;
	}

	if(to.close()<0) {
		return -1;
	}
	return 0;
}

int File::readc(){
	char c =fgetc(m_f);
	if(ferror(m_f)) {
		return FileTypes::ENDOFFILE;
	}
	return c;
}

int File::writec(char c){
	fputc(c, m_f);
	if(ferror(m_f)) {
		return FileTypes::ENDOFFILE;
	}
	return 0;
}

bool File::eof(){
	return feof(m_f);
}
