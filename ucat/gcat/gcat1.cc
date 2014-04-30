#include "gcat.ih"

Gcat::Gcat()
:
    d_arg(Arg::instance())
{
    wmsg.reset(cerr);
}
