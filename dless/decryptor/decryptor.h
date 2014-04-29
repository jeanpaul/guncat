#ifndef INCLUDED_DECRYPTOR_
#define INCLUDED_DECRYPTOR_

#include <string>

class Decryptor
{
    std::string d_gpg;
    std::string d_gpgOptions;
    std::string d_passphrase;
    std::string d_msgName;

    public:
        Decryptor();

    private:
        void echo(bool trueIsOn) const;
        void getPassphrase();
        void setVerbosity();
};
        
#endif
