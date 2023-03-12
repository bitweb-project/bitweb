0.21.1.2 Release Notes
====================

Bitweb Core version 0.21.1.2 is now available from:

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
- #44941a6 build,boost: update download url. 
- #436489a Turn bitweb github to organization - rename repo link.
- #418d5b9 Fix typo
- #5e66186 Fix another typo
- #9b5b96d Re-style
- #d47e322 add new seed and fix typos
- #9a549c6 fix bip34hash at chainparams.
- #406d6fc Pump version
- #705c30b return fallback fee , for prevent 0 tx fee issue.
- #c9994d9 increase fallback fee.
- #8b49051 fix build issue
- #29986c3 add ""
- #6a449fe drop testnet bin34height to genesis