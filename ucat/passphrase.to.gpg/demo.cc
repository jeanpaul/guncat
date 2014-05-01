// compile with g++ --std=c++0x -pthread demo.cc -lbobcat 

#include <string>
#include <iostream>
       #include <sys/types.h>
       #include <termios.h>
       #include <unistd.h>
#include <thread>

#include <bobcat/pipe>
#include <bobcat/process>
#include <bobcat/ofdstream>
#include <bobcat/ifdstream>
#include <bobcat/exception>

using namespace std;
using namespace FBB;

string passphrase;

void getPassphrase()
{

    cerr << "passphrase: " << flush;

    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);

    getline(cin, passphrase);

    tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void inStream(Process *gpg, istream *in, int *exitValue)
{
    *gpg << in->rdbuf();
    gpg->close();
    *exitValue = gpg->waitForChild();
}
    
void runPGP(string const &out)
{
    for (size_t attempt = 0; attempt != 3; ++attempt)
    {
        Pipe pipe;
        {
            OFdStream writePwd(pipe.writeFd());
            writePwd << passphrase << endl;
        }
    
        string line = 
                "/usr/bin/gpg --passphrase-fd " + to_string(pipe.readFd()) +
                " --batch --quiet --output " + out + " --decrypt";
    
        Process gpg(Process::CIN, line);
    
        ifstream in("mail");
    
        gpg.start();
    
        int exitValue;
        thread inThread(inStream, &gpg, &in, &exitValue);
        inThread.join();
    
        switch (exitValue)
        {
            default:
            return;

            case 2:         // incorrect passphrase
                cerr << "Incorrect passphrase\n";
                getPassphrase();
            break;
        }
    }
    throw Exception() << 
            "Quitting after three attempts to enter the correct passphrase\n";
}

int main(int argc, char **argv)
try
{
    getPassphrase();


    runPGP("out1");
    runPGP("out2");
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}










