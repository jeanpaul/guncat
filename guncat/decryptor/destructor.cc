#include "decryptor.ih"

Decryptor::~Decryptor()
{
                                    // interactive passphrase, and passphrase
                                    // was provided
    if (d_arg.option('p') && not d_passphrase.empty())
        cerr << '\n';
}
