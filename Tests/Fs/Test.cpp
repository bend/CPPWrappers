/**
 *
 *       @file  Test.cpp
 *
 *      @brief  
 *
 *    @version  1.0
 *       @date  10/12/2011 19:04:44
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */
#include <Fs/File.h>
#include <iostream>
#include <Fs/FileTypes.h>
using namespace std;
int main(){
	Path p("../../Tests/Fs/test.txt");
	File f(p, FileTypes::READ);
	f.open();
	cout<<f.getSize()<<endl;
	cout<<p.getAbsolutePath()<<endl;
	cout<<p.getName()<<endl;
	cout<<p.getParent()<<endl;
}

