#include "decryptor.ih"

int Decryptor::insertPGPsection(Process &gpg, string const &pgpHeader, 
                                istream &in)
{
    gpg.start();

    gpg << pgpHeader << '\n';
    string line;
    do
    {
        getline(in, line);
        gpg << line << '\n';
    }
    while (line.find("-----END PGP MESSAGE-----") != 0);

    gpg.close();
    int ret = gpg.waitForChild();

    (d_msgName == "-" ? cerr : d_msg)  << gpg.childErrStream().rdbuf();

    return ret;
}
