#ifndef INCLUDED_GCAT_
#define INCLUDED_GCAT_

#include <iosfwd>

#include "../decryptor/decryptor.h"

namespace FBB
{
    class Arg;
}

class Gcat
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
        Gcat();
        void arguments();

    private:
        void process(std::istream &in);
        void processCin();
        void processFileArguments();
};
        
#endif


