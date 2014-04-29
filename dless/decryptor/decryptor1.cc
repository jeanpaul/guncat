#include "decryptor.ih"

Decryptor::Decryptor()
{
    Arg &arg = Arg::instance();

    if (not arg.option(&d_gpg, "gpg"))      // override default gpg location
        d_gpg = "/usr/bin/gpg";

    if (arg.option('p'))
        getPassphrase();

    arg.option(&d_msgName, 'm');            // get the name of the message 
                                            // stream

    if (not arg.option('t'))                // by default --no-tty is used
        d_gpgOptions += " --no-tty";

    if (not arg.option('l'))                // by default missing keys are
        d_gpgOptions += " --no-auto-key-locate";            // searched for

    setVerbosity();                         // set GPG's verbosity

    setRemainingOptions();

    d_gpgOptions += " --decrypt";

    if (arg.option("show-gpg"))
    {
        cout << d_gpg << ' ' << d_gpgOptions << '\n';
        throw 0;
    }
}


