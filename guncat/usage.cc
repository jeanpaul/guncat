//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << " [options] [file(s)]\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"

    "     --gpg <path>:  path to the gpg program (default: /usr/bin/gpg)\n"
    "     --gpg-msg (-m) path: specify - to write gpg's messages to "
                                                                "stderr,\n"
    "                  otherwise write messages to `path' (by default "
                                                                "messages\n"
    "                  are suppressed)\n"
    "      --gpg-no-batch: do not use gpg's --batch option (by default "
                                                                "--batch\n"
    "                   is used)\n"
    "      --gpg-option \"spec\": gpg option `spec' is passed to gpg child "
                                                               "processes\n"
    "      --help (-h): provide this help\n"
    "      --locate-keys (-l): locate missing public keys at the "
                                                            "configured key\n"
    "                  server(s) (by default missing keys are not searched "
                                                                "for)\n"
    "      --passphrase (-p): the passphrase is read as the first line from "
                                                               "stdin,\n"
    "                  (without being echoed); otherwise the passphrase is\n"
    "                  handled by gpg itself (e.g., using gpg-agent)\n"
    "      --show-gpg: show the gpg command that would be used, and quit.\n"
    "      --tty-OK (-t): by default gpg's option --no-tty is used.\n"
    "      --verbose [0-2]: gpg's verbosity level (by default: gpg's "
                                                               "--quiet\n"
    "                  option is used)\n"
    "      --version (-v)   - show version information and terminate\n"
    "\n"
    "   [file(s)]   - file(s) to process. If not specified or if specified "
                                                                "as\n"
    "                 - (also within a sequence of file names) the standard "
                                                                "input\n"
    "                 is read.\n"
    "\n";
}

