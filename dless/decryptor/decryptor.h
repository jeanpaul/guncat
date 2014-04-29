#ifndef INCLUDED_DECRYPTOR_
#define INCLUDED_DECRYPTOR_

#include <string>
#include <fstream>

namespace FBB
{
    class Arg;
    class Process;
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
                                                // line must contain the
                                                // BEGIN PGP MESSAGE header 
        void handleGPG(std::istream &in, std::string line);

    private:
        void echo(bool trueIsOn) const;
        void getPassphrase();
        void setVerbosity();
        void setRemainingOptions();

        static void decryptorThread(std::istream *in, 
                                    FBB::Process *gpg, std::string *line);
        static void coutThread(FBB::Process *gpg);
        static void messagesThread(FBB::Process *gpg, std::ostream *messages);

};
        
#endif
