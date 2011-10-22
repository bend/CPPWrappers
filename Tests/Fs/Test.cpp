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
#include <Fs/FileTypes.h>
#include <Fs/BufferedOutput.h>
#include <Fs/BufferedInput.h>
#include <iostream>
using namespace std;
int main() {
    Path p("../../Tests/Fs/test.txt");
    File f(p);
    f.open(FileTypes::READ);
    cout << "Size          :" << f.getSize() << endl;
    cout << "Absolute Path :" << p.getAbsolutePath() << endl;
    cout << "Name          :" << p.getName() << endl;
    cout << "Parent        :" << p.getParent() << endl;
    cout << "isDir ?       :" << f.isDirectory() << endl;
    cout << "isFile?       :" << f.isFile() << endl;
    cout << "exists ?      :" << f.exists() << endl;
    Path n("test_renamed.txt");
    File newOne(n);
    cout << "exists ?      :" << newOne.exists() << endl;
    cout << "rename:       :" << f.renameTo(newOne) << endl;
    cout << "rename:       :" << newOne.renameTo(f) << endl;
    cout << "copy          :" << f.copyTo(newOne) << endl;
    cout << "remove        :" << newOne.remove() << endl;
    Path p3("/");
    File f3(p3);
    vector<string> paths = f3.getList();

    for(unsigned int i = 0; i < paths.size(); ++i)
        cout << paths[i] << endl;

    FileMode m(FileTypes::RWXU | FileTypes::RWXG);
    f.setMode(m);
    cout << f.getMode() << endl;
    cout << f.getMode().getStringMode() << endl;
    string theS = "hello world\nhow are you ? \n";
    Path pout("out.test.txt");
    File out(pout);
    BufferedOutput b(out, FileTypes::WRITE, 10);
    b.write(theS);
    b.write('a');
    b.write(123);
    long l = 123123123123L;
    b.write(l);
    b << 666;
    b << "this is another string";
    float fff = 0.123;
    b << fff << '\n';
    b << fff << fff;
    b.write('\n');
    short s = 123;
    b.write(s);
    b.write('\n');
    float flo = 123.321f;
    b.write(flo);
    b.write('\n');
    b.flush();
    b.close();
    BufferedInput in2(out);
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    cout << "read word : " << in2.readWord() << endl;
    in2.close();
    BufferedInput in(out);
    cout << "read : " << in.readLine() << endl;
    cout << "read : " << in.readLine() << endl;
    cout << "read : " << in.readLine() << endl;
    cout << "read : " << in.readLine() << endl;
    cout << "read : " << in.readLine() << endl;
    cout << in.eof() << endl;
    cout << "read : " << in.readLine() << endl;
    cout << in.eof() << endl;
    cout << "read : " << in.readLine() << endl;
    cout << "read : " << in.readLine() << endl;
    cout << "read : " << in.readLine() << endl;
    cout << "read : " << in.readLine() << endl;
    in.close();
    Path pp("aze");
    File ff(pp);
    BufferedInput bb(ff);
    cout << bb.eof() << endl;
    cout << "read : " << bb.readLine() << endl;
    cout << "here " << endl;
    BufferedInput in3(out);
    cout << "read : " << in3.read(3) << endl;
    cout << "read : " << in3.read(3) << endl;
    cout << "read : " << in3.read(3) << endl;
    cout << "read : " << in3.read(3) << endl;
    cout << "read : " << in3.read(3) << endl;
    cout << "read : " << in3.read(3) << endl;
    cout << "read : " << in3.read(1000000000) << endl;
    in3.close();
    return 0;
}

