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



File::File(Path& p, string mode):
    m_path(p),
    m_mode(mode) {
}

int File::open() {
    f = fopen(m_path, m_mode.c_str());

    if(f == NULL)
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
    return fclose(f);
}

long File::getSize() {
    struct stat file_status;

    if (stat(m_path, &file_status) < 0) {
        return -1;
    }

    return file_status.st_size;
}

FileMode* File::getMode() {
    struct stat file_status;

    if (stat(m_path, &file_status) < 0) {
        return new FileMode(-1);
    }

    return new FileMode(file_status.st_mode);
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
        vect.push_back(t);
    }

    return vect;
}

Path File::getPath() {
    return m_path;
}

bool File::isFile() {
}

bool File::isDirectory() {
}

int File::mkdir() {
}

int File::renameTo(string name) {
}

int File::copyTo(string name) {
}
