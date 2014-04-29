#include "gcat.ih"

void Gcat::processCin()
{
    switch (d_processedCin)
    {
        case FIRST:
            process(cin);
            d_processedCin = DONE;
        break;

        case DONE:
            wmsg << "Multiple stdin (`-') specifications are ignored" << endl;
            d_processedCin = WARNED;
        break;
    
        case WARNED:
        break;
    }
}





