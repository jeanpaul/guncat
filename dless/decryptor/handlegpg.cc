#include "decryptor.ih"

void Decryptor::handleGPG(istream &in, string line)
{
    Pipe pipe;
    string passphrase_fd;

    if (not d_passphrase.empty())
    {
        passphrase_fd = " --passphrase-fd " + to_string(pipe.readFd());

        OFdStream pwd(pipe.writeFd());
        pwd << d_passphrase << endl;
    }

    Process gpg(Process::CIN | Process::CERR, 
                    d_gpg + passphrase_fd + d_gpgOptions);

    gpg.start();

    gpg << line << '\n';
    do
    {
        getline(in, line);
        gpg << line << '\n';
    }
    while (line.find("-----END PGP MESSAGE-----") != 0);

    gpg.eoi();

    (d_msgName == "-" ? cerr : d_msg)  << gpg.childErrStream().rdbuf();
}



