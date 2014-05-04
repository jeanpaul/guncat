#include "decryptor.ih"

int Decryptor::echo(struct termios *ttySaved, bool reset) const
{
    int fd = open("/dev/tty", O_RDONLY);
    
    struct termios tty; 

    tcgetattr(fd, &tty);

    if (reset)
        tty = *ttySaved;
    else
    {
        *ttySaved = tty;
        tty.c_lflag &= ~ECHO;
    }

    tcsetattr(fd, TCSANOW, &tty);

    return fd;
}
