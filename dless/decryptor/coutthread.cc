#include "decryptor.ih"

void Decryptor::coutThread(Process *gpg)
{
    cout << gpg->childOutStream().rdbuf();
}
