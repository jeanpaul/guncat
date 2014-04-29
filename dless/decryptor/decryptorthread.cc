#include "decryptor.ih"

void Decryptor::decryptorThread(istream *in, Process *gpg, string *line)
{
    do
    {
        *gpg << *line << '\n';
        getline(*in, *line);
    }
    while (line->find("-----END PGP MESSAGE-----") != 0);

cerr << "SAW END PGP MESSAGE\n";

    *gpg << eoi;
}

