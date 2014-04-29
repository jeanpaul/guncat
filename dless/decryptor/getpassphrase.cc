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

    echo(true);
}
