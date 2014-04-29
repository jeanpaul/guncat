#include "decryptor.ih"

void Decryptor::decryptorThread(istream *in, Process *gpg, string *line)
{
    do
    {
        *gpg << *line << '\n';
        getline(*in, *line);
    }
    while (line->find("-----END PGP MESSAGE-----") != 0);

    *gpg << eoi;
}

