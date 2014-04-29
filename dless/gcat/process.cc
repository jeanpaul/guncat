#include "gcat.ih"

void Gcat::process(istream &in)
{
    string line;

    while (getline(cin, line))
    {
        if (line.find("-----BEGIN PGP MESSAGE-----") == 0)
            d_decryptor.handleGPG(cin, line);
        else
            cout << line << endl;
    }
}





