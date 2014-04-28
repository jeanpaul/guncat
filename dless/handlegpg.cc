#include "main.ih"

void decryptor(Process *gpg, string *line)
{
    do
    {
        *gpg << *line << '\n';
        getline(cin, *line);
    }
    while (line->find("-----END PGP MESSAGE-----") != 0);

    *gpg << eoi;
}

void intoCout(Process *gpg)
{
    cout << gpg->childOutStream().rdbuf();
}

void cerrMessages(Process *gpg)
{
    string line;
    while (getline(gpg->childErrStream(), line))
        ;
}

void handleGPG(string line)
{
    Process gpg(Process::ALL, 
            "/usr/bin/gpg --quiet --no-auto-key-locate --batch --decrypt ");

    thread decrypt(decryptor, &gpg, &line);
    thread toCout(intoCout, &gpg);
    thread msgHandler(cerrMessages, &gpg);

    gpg.start();

    decrypt.join();
    toCout.join();
    msgHandler.join();
}

