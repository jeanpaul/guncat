#include "decryptor.ih"

void Decryptor::setRemainingOptions()
{
    string option;

    if (size_t nOptions = d_arg.option(&option, "gpg-option"))
    {
        d_gpgOptions += ' ';
        d_gpgOptions += option;

        for (size_t idx = 1; idx != nOptions; ++idx)
        {
            d_arg.option(idx, &option, "gpg-option");
            d_gpgOptions += ' ';
            d_gpgOptions += option;
        }
    }
}
