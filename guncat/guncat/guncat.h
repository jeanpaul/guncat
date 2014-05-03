#ifndef INCLUDED_GUNCAT_
#define INCLUDED_GUNCAT_

#include <iosfwd>

#include "../decryptor/decryptor.h"

namespace FBB
{
    class Arg;
}

class Guncat
{
    enum CinSpec
    {
        FIRST,
        DONE,
        WARNED
    };

    CinSpec d_processedCin = FIRST;
    
    FBB::Arg &d_arg;
    Decryptor d_decryptor;

    public:
        Guncat();
        void arguments();

    private:
        void process(std::istream &in);
        void processCin();
        void processFileArguments();
};
        
#endif


