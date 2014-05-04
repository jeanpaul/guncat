#include "decryptor.ih"

void Decryptor::getPassphrase()
{
    struct termios ttySaved;

    int fd = echo(&ttySaved);       // switch off echoing, fd to /dev/tty

    cerr << "Enter passphrase: ";   

    IFdStream in(fd);               // get the passphrase from /dev/tty
    getline(in, d_passphrase);

    cerr << '\n';                   // echo the Enter following the passphrase

    echo(&ttySaved, true);          // restore the echoing state
}
