
#include <string>
#include <iostream>
       #include <termios.h>
       #include <unistd.h>

#include <bobcat/pipe>
#include <bobcat/process>
#include <bobcat/ofdstream>
#include <bobcat/ifdstream>

using namespace std;
using namespace FBB;

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

//    cout << "\n"
//            "done. passphrase was: `" << line << "'\n";

    Pipe pwd;
    {
        OFdStream writePwd(pwd.writeFd());
        writePwd << line << endl;
    }

    line = "/usr/bin/gpg --passphrase-fd " + to_string(pwd.readFd()) +
                " --batch --quiet --output out --decrypt hein";

    Process gpg(Process::NONE, line);

    gpg.start();
    gpg.waitForChild();
}






