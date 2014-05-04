#ifndef INCLUDED_DECRYPTOR_
#define INCLUDED_DECRYPTOR_

#include <string>
#include <fstream>

struct termios;

namespace FBB
{
    class Arg;
    class Process;
    class Pipe;
}

class Decryptor
{
    FBB::Arg &d_arg;
    std::string d_gpg;
    std::string d_gpgOptions;
    std::string d_passphrase;
    std::string d_msgName;
    std::ofstream d_msg;

    public:
        Decryptor();
        ~Decryptor();
                                                // line must contain the
                                                // BEGIN PGP MESSAGE header 
        void handleGPG(std::istream &in, std::string const &pgpHeader);

    private:
        int echo(struct termios *ttySaved, bool reset = false) const;
        void getPassphrase();
        void setVerbosity();
        void setRemainingOptions();

        std::string pipePassphrase(FBB::Pipe &pipe);
        int insertPGPsection(FBB::Process &gpg, std::string const &pgpHeader, 
                                std::istream &in);
};
        
#endif
