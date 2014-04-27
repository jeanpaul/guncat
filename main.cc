#include "main.ih"

int main(int argc, char **argv)
try
{
    Process less(Process::CIN, "/usr/bin/less");
    less.start();

    string line;
    while (getline(cin, line))
    {
        if (line.find("-----BEGIN PGP MESSAGE-----") == 0)
            handleGPG(less, line);
        else
            less << line << endl;
    }

    less << eoi;

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
