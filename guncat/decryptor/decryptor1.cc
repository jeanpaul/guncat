#include "decryptor.ih"

Decryptor::Decryptor()
:
    d_arg(Arg::instance()),
    d_gpgOptions(" ")
{
    if (not d_arg.option(&d_gpg, "gpg"))      // override default gpg location
        d_gpg = "/usr/bin/gpg";

    if (not d_arg.option(&d_msgName, 'm'))  // get the name of the message 
        d_msgName = "/dev/null";            // stream

    if (not d_arg.option('t'))                // by default --no-tty is used
        d_gpgOptions += " --no-tty";

    if (not d_arg.option('l'))                // by default missing keys are
        d_gpgOptions += " --no-auto-key-locate";            // searched for

    setVerbosity();                         // set GPG's verbosity

    setRemainingOptions();

    if (not d_arg.option(0, "gpg-no-batch"))
        d_gpgOptions += " --batch";
        
    d_gpgOptions += " --decrypt";

    if (d_arg.option(0, "show-gpg"))
    {
        cout << d_gpg;
        if (not d_passphrase.empty())
            cout << " --passphrase-fd <fd>";
        cout << d_gpgOptions << '\n';
        throw 0;
    }

    if (d_msgName != "-")
        Exception::open(d_msg, d_msgName);
}




