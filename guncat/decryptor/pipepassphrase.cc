#include "decryptor.ih"

string Decryptor::pipePassphrase(Pipe &pipe)
{
    string ret;

    if (not d_passphrase.empty())
    {
        ret = " --passphrase-fd " + to_string(pipe.readFd());

        OFdStream pwd(pipe.writeFd());
        pwd << d_passphrase << endl;
    }

    return ret;
}
