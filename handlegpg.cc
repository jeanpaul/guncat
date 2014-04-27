#include "main.ih"

void handleGPG(Process &less, string line)
{
    TempStream ts;
    
    do
    {
        ts << line << '\n';
        getline(cin, line);
    }
    while (line.find("-----END PGP MESSAGE-----") != 0);

    ts << line << endl;
    ts.close();

    Process ungpg(Process::COUT, "/usr/bin/gpg --decrypt " + ts.fileName());

    ungpg.start();

    while (getline(ungpg, line))
        less << line << endl;
}
