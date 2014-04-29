#include "decryptor.ih"

void Decryptor::messagesThread(Process *gpg, ostream *messages)
{
    *messages << gpg->childErrStream().rdbuf();
}
