#include "decryptor.ih"

void Decryptor::echo(bool on) const
{
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);

    if (on)
        tty.c_lflag |= ECHO;
    else
        tty.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
