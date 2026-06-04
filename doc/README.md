Bitweb Core
=============

Setup
---------------------
Bitweb Core is the original Bitweb client and it builds the backbone of the network. It downloads and, by default, stores the entire history of Bitweb transactions, which requires several hundred gigabytes or more of disk space. Depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to several days or more.

To download Bitweb Core, visit [bitwebcore.net](https://bitwebcore.net/en/download/).

Running
---------------------
The following are some helpful notes on how to run Bitweb Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/bitweb-qt` (GUI) or
- `bin/bitwebd` (headless)
- `bin/bitweb` (wrapper command)

The `bitweb` command supports subcommands like `bitweb gui`, `bitweb node`, and `bitweb rpc` exposing different functionality. Subcommands can be listed with `bitweb help`.

### Windows

Unpack the files into a directory, and then run bitweb-qt.exe.

### macOS

Drag Bitweb Core to your applications folder, and then run Bitweb Core.

### Need Help?

* See the documentation at the [Bitcoin Wiki](https://en.bitcoin.it/wiki/Main_Page)
for help and more information.
* Ask for help on [Bitweb discord](https://discord.gg/jQdttwgsJa).
* Ask for help on [Bitweb telegram](https://t.me/bitweb_en).
* Ask for help on the [Bitweb BitcoinTalk Announce Thread](https://bitcointalk.org/index.php?topic=5400649.msg60250609#msg60250609).

Building
---------------------
The following are developer notes on how to build Bitweb Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows-msvc.md)
- [FreeBSD Build Notes](build-freebsd.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)

Development
---------------------
The Bitweb repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Productivity Notes](productivity.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://doxygen.bitwebcore.net/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [JSON-RPC Interface](JSON-RPC-interface.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)
- [Internal Design Docs](design/)

### Resources
* Discuss on the [Bitweb BitcoinTalk Announce Thread](https://bitcointalk.org/index.php?topic=5400649.msg60250609#msg60250609).
* Discuss project-specific development on [Bitweb discord](https://discord.gg/jQdttwgsJa).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [bitweb.conf Configuration File](bitweb-conf.md)
- [CJDNS Support](cjdns.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [I2P Support](i2p.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [Managing Wallets](managing-wallets.md)
- [Multisig Tutorial](multisig-tutorial.md)
- [Offline Signing Tutorial](offline-signing-tutorial.md)
- [P2P bad ports definition and list](p2p-bad-ports.md)
- [PSBT support](psbt.md)
- [Reduce Memory](reduce-memory.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Transaction Relay Policy](policy/README.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
