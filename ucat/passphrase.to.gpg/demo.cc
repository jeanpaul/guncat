
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

using namespace std;
using namespace FBB;

void inStream(Process *gpg, istream *in)
{
    *gpg << in->rdbuf();
    *gpg << eoi;
}
    
void runPGP(string const &out, string line)
{
    
    Pipe pipe;
    {
        OFdStream writePwd(pipe.writeFd());
        writePwd << line << endl;
    }

    line = "/usr/bin/gpg --passphrase-fd " + to_string(pipe.readFd()) +
                " --batch --quiet --output " + out + " --decrypt";

    Process gpg(Process::CIN, line);

    ifstream in("hein");

    gpg.start();

    thread inThread(inStream, &gpg, &in);
    inThread.join();
}

int main(int argc, char **argv)
{
    cout << "passphrase: " << flush;

    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);

    string line;
    getline(cin, line);

    tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);


    runPGP("out1", line);
    runPGP("out2", line);

//    gpg.waitForChild();
}











