#include "guncat.ih"

void Guncat::processFileArguments()
{
    for (size_t idx = 0, end = d_arg.nArgs(); idx != end; ++idx)
    {
        if (string(d_arg[idx]) == "-")
            processCin();
        else
        {
            ifstream in;
            Exception::open(in, d_arg[idx]);
            process(in);
        }
    }
}
