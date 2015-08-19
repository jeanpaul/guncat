# guncat
       Guncat  was  designed to tackle a problem encountered with (partically)
       PGP encrypted files (which may be  encountered  in,  e.g.,  mailboxes).
       Tools  to  process text-files (like grep(1), or less(1)) may be used to
       process those files, but standard tools like cat(1) leave PGP encrypted
       sections within such files as-is. As a consequence, browsing the `real'
       contents (i.e., clear-text sections and the unencrypted contents of PGP
       encrypted sections) of those files is difficult.

       Guncat  acts like cat, but unencrypts encrypted sections encountered in
       the files processed by guncat, copying the unencrypted  information  to
       guncat's  standard  output  stream, which may thereupon be processed by
       other tools.

For more information about guncat visit https://fbb-git.github.io/guncat/
