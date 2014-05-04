#include "decryptor.ih"

void Decryptor::handleGPG(istream &in, string const &pgpHeader)
{
    off_t offset = in.tellg();

    for (size_t attempt = 1; ; ++attempt)
    {
        if (d_arg.option('p'))
            getPassphrase();

        Pipe pipe;
        Process gpg(Process::CIN | Process::CERR, 
                        d_gpg + pipePassphrase(pipe) + d_gpgOptions);

                                // exitValue 2 means: incorrect passphrase
        if (insertPGPsection(gpg, pgpHeader, in) != 2)
            return;
    
        if (not in.seekg(offset, ios::beg))
            throw Exception() << "File cannot be repositioned "
                                        "following incorrect passphrase\n";
        
        if (attempt == 3)
            throw Exception() << 
                "Quitting after three attempts to enter a "
                                                    "correct passphrase\n";

        if (d_arg.option('p'))
            cerr << "Passphrase incorrect. Try again...\n";
    }
}






