#include "decryptor.ih"

void Decryptor::decryptorThread(istream *in, Process *gpg, string *line)
{
    TempStream tmp;

    tmp << *line << '\n';

    do
    {
        getline(*in, *line);
        tmp << *line << '\n';
    }
    while (line->find("-----END PGP MESSAGE-----") != 0);

    tmp.seekg(0);

    *gpg << tmp.rdbuf() << eoi;


//    string contents;
//    contents += *line;
//    contents += '\n';
//
//    do
//    {
//        getline(*in, *line);
//        contents += *line;
//        contents += '\n';
//    }
//    while (line->find("-----END PGP MESSAGE-----") != 0);
//
//    *gpg << contents << eoi;


cerr << "GPG: " << *line << endl;
}

