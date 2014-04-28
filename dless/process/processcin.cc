#include "process.ih"

void Process::processCin()
{
    switch (d_processedCin)
    {
        case FIRST:
            process(cin);
            d_processCin = DONE;
        break;

        case DONE:
            wmsg << "Multiple stdin (`-') specifications are ignored" << endl;
            d_processedCin = WARNED;
        break;
    
        case WARNED:
        breal;
    }
}





