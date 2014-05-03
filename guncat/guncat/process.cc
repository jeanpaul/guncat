#include "guncat.ih"

void Guncat::process(istream &in)
{
    string line;

    while (getline(in, line))
    {
        if (line.find("-----BEGIN PGP MESSAGE-----") == 0)
            d_decryptor.handleGPG(in, line);
        else
            cout << line << endl;
    }
}





