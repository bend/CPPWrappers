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
#include <assert.h>
using namespace std;
int main()
{
    {
        /** Files Test **/
        Path p1("test.txt");
        Path p2("temp.txt");
        File f1(p1);
        File f2(p2);
        assert(f1.open(FileTypes::Read) == 0);
        assert(f1.exists() == true);
        assert(f1.close() == 0);
        cout << "Mode of f1 " << f1.getMode().getStringMode() << endl;
        cout << "Path of f1 " << f1.getPath().getAbsolutePath() << endl;
        cout << "Size of f1 " << f1.getSize() << endl;
        cout << "HR Size of f1 KB" << f1.getHumanReadableSize(FileTypes::Kbyte) << endl;
        cout << "HR Size of f1 MB" << f1.getHumanReadableSize(FileTypes::Mbyte) << endl;
        cout << "HR Size of f1 GB" << f1.getHumanReadableSize(FileTypes::Gbyte) << endl;
        cout << "HR Size of f1 TB" << f1.getHumanReadableSize(FileTypes::Tbyte) << endl;
        assert(f2.exists() == false);
        assert(f1.copyTo(f2) == 0);
        assert(f2.exists() == true);
        assert(f1.getSize() == f2.getSize());
        assert(f2.remove() == 0);
        assert(f1.renameTo(f2) == 0);
        assert(f2.renameTo(f1) == 0);
        assert(f1.renameTo(f1) != 0);
        FileMode m(0700);
        FileMode oldM = f1.getMode();
        assert(f1.setMode(m) == 0);
        assert(f1.getMode().getStringMode() == "rwx------");
        assert(f1.setMode(oldM) == 0);
    }
    {
        /** BufferInput Test **/
        Path p1("test.txt");
        File f1(p1);
        BufferedInput b1(f1);

        while (!b1.eof())
        {
            cout << b1.readLine() << endl;
        }

        b1.close();
        BufferedInput b2(f1);

        while (!b2.eof())
        {
            cout << b2.readWord() << endl;
        }

        b2.close();
        BufferedInput b3(f1);

        while (!b3.eof())
        {
            string s;
            b3 >> s;
            cout << s << endl;
        }

        b3.close();
        BufferedInput b4(f1);

        while (!b4.eof())
        {
            char c;
            b4 >> c;
            cout << c;
        }
    }
    {
        /** Buffered Input and BufferedOutput **/
        Path p1("test_temp");
        File f1(p1);
        BufferedOutput b1(f1, FileTypes::Write);
        b1 << "hello world" << " how are you ?" << '\n';
        b1 << "This will append number 123 " << 123 << '\n';
        b1 << "This will append PI " << 3.1416f << '\n';
        b1 << "This is the end of file " << '\n';
        b1.close();
        cout << "End writing" << endl;
        BufferedInput in(f1);

        while (!in.eof())
        {
            cout << in.readLine() << endl;
            assert(in.getStatus() == AbstractBufferIO::Done);
        }

        assert(f1.remove() == 0);
    }
    {
        Path p("testDir");
        File f(p);
        assert(!f.exists());
        assert(f.mkdir() == 0);
        assert(f.isDirectory());
        assert(!f.isFile());
        assert(f.remove() == 0);
    }
    cout << "All tests succeded" << endl;
    return 0;
}

