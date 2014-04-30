#include "decryptor.ih"

void Decryptor::setVerbosity()
{
    string verbosity;
    if (not d_arg.option(&verbosity, "verbose"))
        d_gpgOptions += " --quiet";
    else 
    {
        switch (verbosity[0])
        {
            case '0':
                d_gpgOptions += " --no-verbose";
            return;

            case '2':
                d_gpgOptions += " -verbose";
            // FALLING THRU

            case '1':
                d_gpgOptions += " -verbose";
            return;

            default:
            throw Exception() << "--verbose needs 0, 1 or 2";
        }
    }
}
