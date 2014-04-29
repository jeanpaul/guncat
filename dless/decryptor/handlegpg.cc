#include "decryptor.ih"

void Decryptor::handleGPG(istream &in, string line)
{
    Process gpg(Process::ALL, d_gpg + d_gpgOptions);

    ofstream gpgMessages;

    if (d_msgName != "-")
        Exception::open(gpgMessages, d_msgName);

    thread decrypt(decryptorThread, &in, &gpg, &line);
    thread toCout(coutThread, &gpg);
    thread msgHandler(messagesThread, &gpg, 
                      d_msgName.empty() ? &cerr : &gpgMessages);

    gpg.start();

    decrypt.join();
    toCout.join();
    msgHandler.join();
}
