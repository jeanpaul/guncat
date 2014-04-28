#include "main.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        Arg::LongOption("gpg",          Arg::Required),
        Arg::LongOption("passphrase",   'p'),
        Arg::LongOption("gpg-msg",      'm'),
        Arg::LongOption("gpg-option",   Arg::Required),
        Arg::LongOption("help",         'h'),
        Arg::LongOption("locate-keys",  'l'),
        Arg::LongOption("show-gpg",     Arg::None),
        Arg::LongOption("tty-OK",       't'),
        Arg::LongOption("verbose",      Arg::Required),
        Arg::LongOption("version",      'v'),
    };
    auto longEnd = longOptions + sizeof(longOptions) / sizeof(longOptions[0]);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("m:hlptv", longOptions, longEnd, argc, argv);

    arg.versionHelp(usage, version, 0);

    cout << "# of arugments: " << arg.nArgs() << '\n';
    return 0;

    string line;
    while (getline(cin, line))
    {
        if (line.find("-----BEGIN PGP MESSAGE-----") == 0)
            handleGPG(line);
        else
            cout << line << endl;
    }
}
catch (int x)
{
    return 0;
}
catch (exception const &exc)
{
    cerr << "Exception: " << exc.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Unexpected exception\n";
    return 1;
}
