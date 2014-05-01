#include "decryptor.ih"

void Decryptor::handleGPG(istream &in, string const &pgpHeader)
{
    off_t offset = in.tellg();

    for (size_t attempt = 0; attempt != 3; ++attempt)
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
    
        gpg << pgpHeader << '\n';
        string line;
        do
        {
            getline(in, line);
            gpg << line << '\n';
        }
        while (line.find("-----END PGP MESSAGE-----") != 0);
    
        gpg.close();
        int exitValue = gpg.waitForChild();
    
        (d_msgName == "-" ? cerr : d_msg)  << gpg.childErrStream().rdbuf();
    
        if (exitValue != 2)     // exitValue 2 means: incorrect passphrase
            return;
    
        if (not isatty(STDIN_FILENO))
            throw Exception() << "Incorrect passphrase, cannot continue\n";

        if (not in.seekg(offset, ios::begin))
            throw Exception() << "File cannot be repositioned "
                                        "following incorrect passphrase\n";

        getPassphrase();
    }

    throw Exception() << 
            "Quitting after three attempts to enter the correct passphrase\n";
}






