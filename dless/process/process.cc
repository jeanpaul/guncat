#include "process.ih"

void Process::process(istream &in)
{
    string line;

    while (getline(cin, line))
    {
        if (line.find("-----BEGIN PGP MESSAGE-----") == 0)
            decryptor.handleGPG(line);
        else
            cout << line << endl;
    }
}





