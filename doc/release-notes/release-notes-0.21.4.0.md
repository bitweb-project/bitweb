0.21.4 Release Notes
====================

Bitweb Core version 0.21.4 is now available from:

  <https://bitwebcore.net/wallet>

This minor release includes various bug fixes and performance
improvements, as well as updated translations.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/bitweb-project/bitweb/issues>


How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes in some cases), then run the
installer (on Windows) or just copy over `/Applications/Bitweb-Qt` (on Mac)
or `bitwebd`/`bitweb-qt` (on Linux).

Upgrading directly from a version of Bitweb Core that has reached its EOL is
possible, but it might take some time if the data directory needs to be migrated. Old
wallet versions of Bitweb Core are generally supported.

Compatibility
==============

Bitweb Core is supported and extensively tested on operating systems
using the Linux kernel, macOS 10.12+, and Windows 7 and newer.  Bitweb
Core should also work on most other Unix-like systems but is not as
frequently tested on them.  It is not recommended to use Bitweb Core on
unsupported systems.

macOS versions earlier than 10.12 are no supported. 
Additionally, Bitweb Core does not yet change appearance
when macOS "dark mode" is activated.

Notable changes
===============
- #0f1509c fix time settings and allow connect to node old protocol version nodes ( this need for support  software like bitcore , etc. )
- #663e8d1 Correct time settings.
