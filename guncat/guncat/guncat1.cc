#include "guncat.ih"

Guncat::Guncat()
:
    d_arg(Arg::instance())
{
    wmsg.reset(cerr);
}
