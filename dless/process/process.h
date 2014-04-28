#ifndef INCLUDED_PROCESS_
#define INCLUDED_PROCESS_

#include "../decryptor/decryptor.h"

namespace FBB
{
    class Arg;
}

class Process
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
        Process();
        void arguments();

    private:
        process(istream &in);
        processCin();
        processFileArguments();
};
        
#endif


