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

void intoLess(Process *less, Process *gpg)
{
    *less << gpg->childOutStream().rdbuf();
}

void cerrMessages(Process *gpg)
{
    string line;
    while (getline(gpg->childErrStream(), line))
        ;
}

void handleGPG(Process &less, string line)
{
    Process gpg(Process::ALL, 
            "/usr/bin/gpg --no-auto-key-locate --batch --decrypt ");

    thread decrypt(decryptor, &gpg, &line);
    thread toLess(intoLess, &less, &gpg);
    thread msgHandler(cerrMessages, &gpg);

    gpg.start();

    decrypt.join();
    toLess.join();
    msgHandler.join();
}
