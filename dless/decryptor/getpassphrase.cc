#include "decryptor.ih"

void Decryptor::getPassphrase()
{
    echo(false);

    bool interactive;

    if ((interactive = isatty(STDIN_FILENO)))
        cout << "Enter passphrase: " << flush;

    getline(cin, d_passphrase);

    if (interactive)
        cout << endl;

    d_gpgOptions += " --passphrase-fd " + to_string(d_pipe.readFd());

    OFdStream pwd(d_pipe.writeFd());
    pwd << d_passphrase << endl;

    echo(true);
}
