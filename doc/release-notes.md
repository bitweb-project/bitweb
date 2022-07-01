0.21.2 Release Notes
====================

Bitweb Core version 0.21.2 is now available from:

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
- #3d29ce4 fix qt.mk download link
- #8a65c05 Rename Examples.cpp to examples.cpp
- #27b6465 Update README.md
- #8d3193e Fix incorect block consensus rule.
- #61d9296 Update dns seeds
- #df59448 Correct assumed blockchain size.
- #b207bb5 fix MAX_BLOCK_SIGOPS_COST
- #660afd4 Update domain at sources.
- #b7799d6 Correct twitter.
- #91097be move btc release notes , and add old bitweb release notes.
- #11f506f Pump version
- #0a72ce0 Update release-notes.md
- #8c1fa66 Update old domain to new.
- #53cedd3 fix "
- #304396b Update checkpoints.
- #2ac5058 Merge branch 'master' of https://github.com/bitweb-project/bitweb
