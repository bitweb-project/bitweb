Bitweb Core version v31.3 Release Notes
=======================================

Bitweb Core version v31.3 is now available from:

  <https://github.com/bitweb-project/bitweb/releases/tag/v31.3>

  <https://bitwebcore.net/en/wallets/full-node/>

This release includes new features, various bug fixes and performance
improvements, as well as updated translations.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/bitweb-project/bitweb/issues>

To receive security and update notifications, please subscribe to:

  <https://github.com/bitweb-project/bitweb/releases>


How to Upgrade
==============

⚠️  BACKUP YOUR WALLET BEFORE UPGRADING

1. Shut down your wallet completely and wait until it has fully closed
   (this might take a few minutes).

2. Back up your wallet.dat file before upgrading.
   Default wallet.dat locations:

     Windows : %APPDATA%\Bitweb\wallet\wallet.dat
     macOS   : ~/Library/Application Support/Bitweb/wallet/wallet.dat
     Linux   : ~/.bitweb/wallet/wallet.dat

   If you configured a custom data directory (-datadir), your wallet.dat
   is located at: <your-custom-datadir>/wallet/wallet.dat

3. Copy wallet.dat to a safe location (external drive, encrypted backup)
   before proceeding with the upgrade.

Then run the installer (on Windows) or just copy over
`/Applications/Bitweb-Qt` (on macOS) or `bitwebd`/`bitweb-qt` (on Linux).


Compatibility
=============

Bitweb Core is supported and tested on operating systems using the
Linux Kernel 3.17+, macOS 13+, and Windows 10+.
Bitweb Core should also work on most other Unix-like systems but is not as
frequently tested on them.


Notable Changes
===============

### doc: update release notes for v31.2 and add history release notes for 30.4

> [`c25d6fc`](https://github.com/bitweb-project/bitweb/commit/c25d6fcda8e290dcfa0174bbf397bb41b17b5290) · 2026-07-07

| File | Lines |
|------|-------|
| [`doc/release-notes.md`](https://github.com/bitweb-project/bitweb/commit/c25d6fcda8e290dcfa0174bbf397bb41b17b5290#diff-e04cb1e9f29f76897c6b84334238f621ff45ba13cf180ad1d0d442d50ebe51f7R1) | [+1, 4, 6, 59, 61, 65-69, 73, 75, 79-82, 86, 88, 92-94, 98, 100, 104-106, 110, 112, 116-118, 122, 124, 128-131, 135, 137, 141-143, 147, 149, 153-155, 159, 161, 165-194, 198, 200, 204-208, 210, 214, 216, 220-223, 225, 229, 231, 235-251, 253-278, 282, 284, 288, 294, 296, 300-308, 310-321](https://github.com/bitweb-project/bitweb/commit/c25d6fcda8e290dcfa0174bbf397bb41b17b5290#diff-e04cb1e9f29f76897c6b84334238f621ff45ba13cf180ad1d0d442d50ebe51f7R1) |
| [`doc/release-notes/release-notes-30.4.md`](https://github.com/bitweb-project/bitweb/commit/c25d6fcda8e290dcfa0174bbf397bb41b17b5290#diff-7dded439391384c6d71596ff4313fe9cf335f2eb2b2e6ac644f95fea70af3179R1-R326) | [+1-326](https://github.com/bitweb-project/bitweb/commit/c25d6fcda8e290dcfa0174bbf397bb41b17b5290#diff-7dded439391384c6d71596ff4313fe9cf335f2eb2b2e6ac644f95fea70af3179R1-R326) |
| [`doc/release-notes/release-notes-31.2.md`](https://github.com/bitweb-project/bitweb/commit/c25d6fcda8e290dcfa0174bbf397bb41b17b5290#diff-b15120e2cd1ce8541aee770fb1bfe4a78f5f5330acb2c21d11434e9f01889ab1R1-R334) | [+1-334](https://github.com/bitweb-project/bitweb/commit/c25d6fcda8e290dcfa0174bbf397bb41b17b5290#diff-b15120e2cd1ce8541aee770fb1bfe4a78f5f5330acb2c21d11434e9f01889ab1R1-R334) |

*3 file(s) · ✏️ 1 modified · 🆕 2 new · +825 / -940 lines*

---

### fix typo and lang

> [`a2c24a1`](https://github.com/bitweb-project/bitweb/commit/a2c24a1f426cca9a3e3780899ba25c04aa95274c) · 2026-07-15

| File | Lines |
|------|-------|
| [`src/qt/locale/bitcoin_ru.ts`](https://github.com/bitweb-project/bitweb/commit/a2c24a1f426cca9a3e3780899ba25c04aa95274c#diff-931edc85a8e103653170e316381a0088fcf4ca7c889bba77033535ed066bdcb2R4855) | [+4855](https://github.com/bitweb-project/bitweb/commit/a2c24a1f426cca9a3e3780899ba25c04aa95274c#diff-931edc85a8e103653170e316381a0088fcf4ca7c889bba77033535ed066bdcb2R4855) |
| [`test/lint/test_runner/src/util.rs`](https://github.com/bitweb-project/bitweb/commit/a2c24a1f426cca9a3e3780899ba25c04aa95274c#diff-028bce10d97e11a60a611097e55e96f3bcde899f23af207a3d265ae3824ff150R80-R81) | [+80-81](https://github.com/bitweb-project/bitweb/commit/a2c24a1f426cca9a3e3780899ba25c04aa95274c#diff-028bce10d97e11a60a611097e55e96f3bcde899f23af207a3d265ae3824ff150R80-R81) |

*2 file(s) · ✏️ 2 modified · +3 / -3 lines*

---

### Bump version to 31.99

> [`95583e9`](https://github.com/bitweb-project/bitweb/commit/95583e9df68ff6c1603b4ebd6d57075616d6e8e2) · 2026-07-15

| File | Lines |
|------|-------|
| [`CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/95583e9df68ff6c1603b4ebd6d57075616d6e8e2#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR31) | [+31, 34](https://github.com/bitweb-project/bitweb/commit/95583e9df68ff6c1603b4ebd6d57075616d6e8e2#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR31) |

*1 file(s) · ✏️ 1 modified · +2 / -2 lines*

---

### Backport from bitcoin/bitcoin PRs from official 31.x (v31.2 -> v31.3 prep): private broadcast, versionbits, flatfile/sock/net fixes, tx INV dedup, asmap, tests

> [`4e8d941`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94) · 2026-11-19

| File | Lines |
|------|-------|
| [`CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR31) | [+31, 34](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR31) |
| [`ci/test/03_test_script.sh`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR15) | [+15](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR15) |
| [`cmake/introspection.cmake`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a40a3c5438390e95b298aa2f342cb2364380f3d863e34459212d9ca6f97b3e93R11-R13) | [+11-13](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a40a3c5438390e95b298aa2f342cb2364380f3d863e34459212d9ca6f97b3e93R11-R13) |
| [`contrib/init/bitwebd.openrc`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-174d70fdce94dbfcf413b9732bcd494d90fa3412050e034aa6220b253ccfc234R24) | [+24, 33](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-174d70fdce94dbfcf413b9732bcd494d90fa3412050e034aa6220b253ccfc234R24) |
| [`depends/packages/zeromq.mk`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-792003631a2182beb6f3d0a99a295eca8121de7909a5c553f9fd488268455233R14) | [+14, 32-33](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-792003631a2182beb6f3d0a99a295eca8121de7909a5c553f9fd488268455233R14) |
| [`depends/patches/zeromq/add_new_include.patch`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-c1858bdcc51011225a85b33e6aa49f2c77a0432395766bbf8fc3cab31089515bR1-R123) | [+1-123](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-c1858bdcc51011225a85b33e6aa49f2c77a0432395766bbf8fc3cab31089515bR1-R123) |
| [`doc/bips.md`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-c1b79495d2afaf2e9a8effb6fe0117c28a820bf99cff43552ad307d52118ec28R52) | [+52, 82](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-c1b79495d2afaf2e9a8effb6fe0117c28a820bf99cff43552ad307d52118ec28R52) |
| [`doc/build-netbsd.md`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-7d5c6b91f526de15be9457dd7a0b22df3f5e17d01dfc326905e217c20a06b334R15) | [+15](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-7d5c6b91f526de15be9457dd7a0b22df3f5e17d01dfc326905e217c20a06b334R15) |
| [`doc/build-osx.md`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-e9ba5bd8b63e72aa2d54d02960c9209823938981691cc8786ba323b54de0659cR107) | [+107](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-e9ba5bd8b63e72aa2d54d02960c9209823938981691cc8786ba323b54de0659cR107) |
| [`doc/tor.md`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a33b1b15efbc14c65460ef7a883b530ca52144a4f06642e4a188351d959f9894R14-R18) | [+14-18, 47, 59](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a33b1b15efbc14c65460ef7a883b530ca52144a4f06642e4a188351d959f9894R14-R18) |
| [`share/examples/bitweb.conf`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R311) | [+311, 601-606](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R311) |
| [`src/chain.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-05137bf4d07f31a6cc237b1dd772e0b38bc2a60610a7ca86827e98fc126e8407R112) | [+112, 115](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-05137bf4d07f31a6cc237b1dd772e0b38bc2a60610a7ca86827e98fc126e8407R112) |
| [`src/common/messages.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-7b188bfe1d7848ecab9b12fb39fac462d8ea90a2a6d304b2b12a1ba0b95d3cf0R146-R147) | [+146-147](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-7b188bfe1d7848ecab9b12fb39fac462d8ea90a2a6d304b2b12a1ba0b95d3cf0R146-R147) |
| [`src/flatfile.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-da96029cc55b65038e4e824d8ce5876dd4de8227ed0c6ee6966ce285f31fc427R48) | [+48, 62-63, 65-66](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-da96029cc55b65038e4e824d8ce5876dd4de8227ed0c6ee6966ce285f31fc427R48) |
| [`src/flatfile.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-b81ce3d3ee4212c2fe412334d15075fa9003370823822381198baa9f4c2eec7aR17) | [+17, 23](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-b81ce3d3ee4212c2fe412334d15075fa9003370823822381198baa9f4c2eec7aR17) |
| [`src/init.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-b1e19192258d83199d8adaa5ac31f067af98f63554bfdd679bd8e8073815e69dR596) | [+596, 693, 695, 1728, 1750-1760, 2294](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-b1e19192258d83199d8adaa5ac31f067af98f63554bfdd679bd8e8073815e69dR596) |
| [`src/kernel/chain.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-d3d6e652e68e3ef8083f804a2d9bf6bbe6f56d8be131ec27caa2d22aadd26308R10) | [+10, 25](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-d3d6e652e68e3ef8083f804a2d9bf6bbe6f56d8be131ec27caa2d22aadd26308R10) |
| [`src/net.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-00021eed586a482abdb09d6cdada1d90115abe988a91421851960e26658bed02R208) | [+208, 1671-1675, 2064-2074, 2400, 3870, 3875, 4149-4152](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-00021eed586a482abdb09d6cdada1d90115abe988a91421851960e26658bed02R208) |
| [`src/net.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-422879cc8bfac56d4380c865f381b58afeb344bc355bbc7f47c581e4491b6b4bR750-R751) | [+750-751, 1367](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-422879cc8bfac56d4380c865f381b58afeb344bc355bbc7f47c581e4491b6b4bR750-R751) |
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R60) | [+60, 88, 551, 763-764, 1657-1658, 2284, 2287-2288, 2291-2292, 2294-2299, 4168-4169, 4208-4210, 5232-5237, 5250](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R60) |
| [`src/net_processing.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-2a4e846ad2d76a4e7a6f6c46a68b3603de372f435a93b7c0fcabadccc0ed86a5R12) | [+12, 155-156, 158](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-2a4e846ad2d76a4e7a6f6c46a68b3603de372f435a93b7c0fcabadccc0ed86a5R12) |
| [`src/netaddress.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-1ce9cdfdcb1a8474c626ebd0d6eb261d2a91d4c6ac1bbed8feb57a94c61b5701R346-R351) | [+346-351, 443](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-1ce9cdfdcb1a8474c626ebd0d6eb261d2a91d4c6ac1bbed8feb57a94c61b5701R346-R351) |
| [`src/netaddress.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9281caf81406a5c4e11f572f613a4cc9769f39c66579ed75a4c957f30b39d836R165) | [+165](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9281caf81406a5c4e11f572f613a4cc9769f39c66579ed75a4c957f30b39d836R165) |
| [`src/node/blockstorage.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR527-R529) | [+527-529](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR527-R529) |
| [`src/node/blockstorage.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-ed3f90693a242b38b9719af171de8f55183576957676dfa358945bea22276bd5R60-R61) | [+60-61](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-ed3f90693a242b38b9719af171de8f55183576957676dfa358945bea22276bd5R60-R61) |
| [`src/node/data/ip_asn.dat`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94) | 🔄 binary / full replacement |
| [`src/node/transaction.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-54409bbc1a072860afa5d3e2c920ac585b819f1db7ba0d894a4c64d7a66f8464R136) | [+136](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-54409bbc1a072860afa5d3e2c920ac585b819f1db7ba0d894a4c64d7a66f8464R136) |
| [`src/node/types.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-06c43f558c4d0d704cc2b66dcb4b239ca3368201d27b48a30f60d6fdceab3601R37) | [+37](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-06c43f558c4d0d704cc2b66dcb4b239ca3368201d27b48a30f60d6fdceab3601R37) |
| [`src/private_broadcast.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-ad1d5d83183a5facaf06e2b44c42a3e942a261b7506576720588bf6b158e4c3dR6) | [+6, 11-12, 16-22](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-ad1d5d83183a5facaf06e2b44c42a3e942a261b7506576720588bf6b158e4c3dR6) |
| [`src/private_broadcast.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-3ef5e45a5e964dd0121f7f28bf609b2368db3e64370973764a12f2b73b5a21aeR42-R50) | [+42-50, 63-72, 76-77, 79, 215-216](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-3ef5e45a5e964dd0121f7f28bf609b2368db3e64370973764a12f2b73b5a21aeR42-R50) |
| [`src/protocol.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-8e2ffc8fe0e0847a6aac311a93b2faeebd2d76ddb2c81741bb8cf7448287807eR356-R363) | [+356-363](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-8e2ffc8fe0e0847a6aac311a93b2faeebd2d76ddb2c81741bb8cf7448287807eR356-R363) |
| [`src/rpc/mempool.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9c5b83de6dc84af277e352c88b9291aa44340a3c75f572a0b51661eb0a838de9R59-R67) | [+59-67](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9c5b83de6dc84af277e352c88b9291aa44340a3c75f572a0b51661eb0a838de9R59-R67) |
| [`src/rpc/protocol.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-fae33335b72aed238c4755a31e2b3fee0a39a5063209fa384f30c8a0a8f11131R52) | [+52](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-fae33335b72aed238c4755a31e2b3fee0a39a5063209fa384f30c8a0a8f11131R52) |
| [`src/rpc/util.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-647c2f0c4261e4ba2bbfc487178f54f4702ad284b52c1ed2dbbd30a53a5ad487R398-R399) | [+398-399](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-647c2f0c4261e4ba2bbfc487178f54f4702ad284b52c1ed2dbbd30a53a5ad487R398-R399) |
| [`src/streams.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-6d04aca71dd4079e13471cd3c1699c3e55314fb04c5c6de062ffbdcc8db42024R16) | [+16, 38, 46, 134](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-6d04aca71dd4079e13471cd3c1699c3e55314fb04c5c6de062ffbdcc8db42024R16) |
| [`src/streams.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-4020c723bb55e114bdc7ff769086a765dcc7ccfb61da2047a315db16c0c7a8b4R447) | [+447](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-4020c723bb55e114bdc7ff769086a765dcc7ccfb61da2047a315db16c0c7a8b4R447) |
| [`src/test/denialofservice_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a4c9875091483bafb92d8ccaa035dff408a7a5c44e5b4eb55ff51fb0e5112ed2R320) | [+320, 390-403, 412-430](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a4c9875091483bafb92d8ccaa035dff408a7a5c44e5b4eb55ff51fb0e5112ed2R320) |
| [`src/test/fuzz/cluster_linearize.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-19de5751410d99240288e48827f7d39f60c2a9964d3d844117c795e3c6a2d702L614) | [-614](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-19de5751410d99240288e48827f7d39f60c2a9964d3d844117c795e3c6a2d702L614) |
| [`src/test/fuzz/deserialize.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-259675a17ed61244b5f1f5857285bdab63cc81f41334ed64c74ba623b61cf2a2R98) | [+98](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-259675a17ed61244b5f1f5857285bdab63cc81f41334ed64c74ba623b61cf2a2R98) |
| [`src/test/fuzz/locale.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-f853082b5c9feaba950e18b83e8918bf70d138bf4406a95248336771b4a1fdfaL48) | [-48](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-f853082b5c9feaba950e18b83e8918bf70d138bf4406a95248336771b4a1fdfaL48) |
| [`src/test/fuzz/netaddress.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-29b48f78026724e573923833c9850c99ef3594d5c2e65a29b277076ffca485bdR58) | [+58, 74-76, 88-90](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-29b48f78026724e573923833c9850c99ef3594d5c2e65a29b277076ffca485bdR58) |
| [`src/test/fuzz/p2p_transport_serialization.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-e13d8784c65eb3b2a33c476cc7c3979aca851a0a3d37407f35f49e9bd48b8ea5L89) | [-89](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-e13d8784c65eb3b2a33c476cc7c3979aca851a0a3d37407f35f49e9bd48b8ea5L89) |
| [`src/test/fuzz/versionbits.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9d9666c59ca32aafe83a1c878315423bb67503d30a5f7b18e522ff48486a3a06R17) | [+17, 35, 130](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9d9666c59ca32aafe83a1c878315423bb67503d30a5f7b18e522ff48486a3a06R17) |
| [`src/test/kernel/test_kernel.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-f638e65d9278276b2a6ac42ffbbd26d079c3dba752feed5038a25a1ee565d320R9-R10) | [+9-10](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-f638e65d9278276b2a6ac42ffbbd26d079c3dba752feed5038a25a1ee565d320R9-R10) |
| [`src/test/main.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-2a6d01acd80c98b39ca7a5aa6ab9e0eb56b878109378fa9c1bdbc5049c2925dcR8-R9) | [+8-9](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-2a6d01acd80c98b39ca7a5aa6ab9e0eb56b878109378fa9c1bdbc5049c2925dcR8-R9) |
| [`src/test/netbase_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-1d804b435c22c29ffc21022ad3a88a8b7d3bd44ae451c3d50e4700344ffef60dR62-R64) | [+62-64, 79](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-1d804b435c22c29ffc21022ad3a88a8b7d3bd44ae451c3d50e4700344ffef60dR62-R64) |
| [`src/test/private_broadcast_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-b9dee9539db2b41a3765f60d067d5274d3c0e775ba8c31ec058cee7c5d9b5eb9R46-R47) | [+46-47, 54, 148, 160-211](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-b9dee9539db2b41a3765f60d067d5274d3c0e775ba8c31ec058cee7c5d9b5eb9R46-R47) |
| [`src/test/rbf_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-d9ce07e92ef38a0cbd88468433545d25cc124d34382f62ad8077249eef6e929fL124-L128) | [-124-128](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-d9ce07e92ef38a0cbd88468433545d25cc124d34382f62ad8077249eef6e929fL124-L128) |
| [`src/test/txgraph_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a8bfda03bd9f3006fee9126c386e398eeb3d6d176881cb96708018c081bda5d1R293) | [+293](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a8bfda03bd9f3006fee9126c386e398eeb3d6d176881cb96708018c081bda5d1R293) |
| [`src/test/util/time.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9cfd7a9bb9f935e8e172e5c156189b38611051801a53264766ce81ed539c4e2aR40) | [+40](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9cfd7a9bb9f935e8e172e5c156189b38611051801a53264766ce81ed539c4e2aR40) |
| [`src/test/util/versionbits.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-be612cc2d8d6ada8b2cdde3fb7d2ccb7b466a2e46bbb232e89d06c6ea7d5132cR1-R13) | [+1-13](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-be612cc2d8d6ada8b2cdde3fb7d2ccb7b466a2e46bbb232e89d06c6ea7d5132cR1-R13) |
| [`src/test/versionbits_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-f0697aa70d82dc886876d2b62b6c4d1c27d584c2001e1bf605f74d28a06b4d8dR11) | [+11, 458-459, 462-470](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-f0697aa70d82dc886876d2b62b6c4d1c27d584c2001e1bf605f74d28a06b4d8dR11) |
| [`src/util/fs_helpers.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-c24fd5f39e56e513a81d84b494862608c1620c194e5a7efbded93953b6ef43e2R144) | [+144, 147, 181, 216](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-c24fd5f39e56e513a81d84b494862608c1620c194e5a7efbded93953b6ef43e2R144) |
| [`src/util/fs_helpers.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-bc3aba4e856660600a446395d094882ea164e3becc663ac57fae8f7841d4685eR46-R77) | [+46-77, 79](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-bc3aba4e856660600a446395d094882ea164e3becc663ac57fae8f7841d4685eR46-R77) |
| [`src/util/sock.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-76b083bb360dbbd34a65d8f15dfcf143acb02061f55b4f35d99ad1607016d8dbR217) | [+217, 222-224](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-76b083bb360dbbd34a65d8f15dfcf143acb02061f55b4f35d99ad1607016d8dbR217) |
| [`src/versionbits.h`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-73b381667b1bb315180fc7e7a66992e79ad742972de5d0d2c1b8404d3d67e1b0R24-R25) | [+24-25, 75-76](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-73b381667b1bb315180fc7e7a66992e79ad742972de5d0d2c1b8404d3d67e1b0R24-R25) |
| [`src/wallet/test/coinselector_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-36ddaeb9e3a5c1aaaccd6b1ed6c770e8344e33dbfd4876b5f0726d84ab47cbabL172) | [-172](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-36ddaeb9e3a5c1aaaccd6b1ed6c770e8344e33dbfd4876b5f0726d84ab47cbabL172) |
| [`src/wallet/test/util.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-de599d9a8f1ba87b441fa95ddb92737eef323ec968f0a9f3c38ec5a3b374045cL69) | [-69, 93](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-de599d9a8f1ba87b441fa95ddb92737eef323ec968f0a9f3c38ec5a3b374045cL69) |
| [`src/wallet/test/wallet_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-157f588a09ff1da05b8c74acfcfb4da21917b6a97ed5d2e702228d621d23e66dL701) | [-701](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-157f588a09ff1da05b8c74acfcfb4da21917b6a97ed5d2e702228d621d23e66dL701) |
| [`test/functional/feature_config_args.py`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-2babd91c181a89aaeb4a2bd610c8b6bcab0f0b4f5dd20251a3ad0e1742b56380R435) | [+435](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-2babd91c181a89aaeb4a2bd610c8b6bcab0f0b4f5dd20251a3ad0e1742b56380R435) |
| [`test/functional/feature_proxy.py`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-156fee7ba1e072ea2ff94156a03c2c8b5e4885ee2181ecff97d3c772723802fbR441-R445) | [+441-445, 452-456, 472-473, 489-497](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-156fee7ba1e072ea2ff94156a03c2c8b5e4885ee2181ecff97d3c772723802fbR441-R445) |
| [`test/functional/feature_prune_stale_fork.py`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a3ca99b0ca0c130d916075778b9707628d25d3cad59268537c6b5105a4cb3953R1-R39) | [+1-39](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-a3ca99b0ca0c130d916075778b9707628d25d3cad59268537c6b5105a4cb3953R1-R39) |
| [`test/functional/feature_versionbits_warning.py`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9e3633264f902259b109a626591ca55ce37ac3501da1f962e499a742d2ae28b5R21-R24) | [+21-24, 26-27, 84, 86, 89-96, 98-101](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9e3633264f902259b109a626591ca55ce37ac3501da1f962e499a742d2ae28b5R21-R24) |
| [`test/functional/p2p_ibd_txrelay.py`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-b08a5f65b8749b135c81cca38dcb3dbcce49471a761023fc133607ae480c029eR16-R22) | [+16-22, 25-28, 57-59](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-b08a5f65b8749b135c81cca38dcb3dbcce49471a761023fc133607ae480c029eR16-R22) |
| [`test/functional/p2p_private_broadcast_cap.py`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-fa2124c12d0163244dfb558bf978c3e310ffdbe2c9d35b13de6753a5d8b1f57bR1-R103) | [+1-103](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-fa2124c12d0163244dfb558bf978c3e310ffdbe2c9d35b13de6753a5d8b1f57bR1-R103) |
| [`test/functional/p2p_tx_download.py`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-d5657ef7092f5ab95d162966ae1e3e96e0f669d81fe4cde90caa523f8bdfa56cR19) | [+19, 322-387, 459](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-d5657ef7092f5ab95d162966ae1e3e96e0f669d81fe4cde90caa523f8bdfa56cR19) |
| [`test/functional/rpc_net.py`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-355d4500a3163e554fc3c3051b21b6bc9a97bcb35b146bff17d5fc1b4e4fd650R331) | [+331, 336-337](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-355d4500a3163e554fc3c3051b21b6bc9a97bcb35b146bff17d5fc1b4e4fd650R331) |
| [`test/functional/test_runner.py`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-437d7f6e9f2229879b60aae574a8217f14c643bbf3cfa9225d8011d6d52df00cR317) | [+317, 376](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-437d7f6e9f2229879b60aae574a8217f14c643bbf3cfa9225d8011d6d52df00cR317) |
| [`test/sanitizer_suppressions/lsan`](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9e2a7f9fadfcd9477fd39d4365571cbc62a82bc2c1d8523425decfe92a79229bR2-R3) | [+2-3](https://github.com/bitweb-project/bitweb/commit/4e8d941491bee8e458acd4bcb0dac9450969ae94#diff-9e2a7f9fadfcd9477fd39d4365571cbc62a82bc2c1d8523425decfe92a79229bR2-R3) |

*69 file(s) · ✏️ 64 modified · 🆕 4 new · 🔄 1 binary · +770 / -187 lines*

---

### Permisions: set executable permissions

> [`dd15918`](https://github.com/bitweb-project/bitweb/commit/dd15918c428d88f7607fc465d9f8ad0e36f1180a) · 2026-11-19

| File | Lines |
|------|-------|
| [``](https://github.com/bitweb-project/bitweb/commit/dd15918c428d88f7607fc465d9f8ad0e36f1180a) | — |
| [``](https://github.com/bitweb-project/bitweb/commit/dd15918c428d88f7607fc465d9f8ad0e36f1180a) | — |

*2 file(s) · ✏️ 2 modified · +0 / -0 lines*

---

### fuzz: adapt private_broadcast harness to PrivateBroadcast::AddResult

> [`3b947fe`](https://github.com/bitweb-project/bitweb/commit/3b947fe465b386cf4f3612c52f0653e59e0c3ccd) · 2026-11-19

| File | Lines |
|------|-------|
| [`src/test/fuzz/private_broadcast.cpp`](https://github.com/bitweb-project/bitweb/commit/3b947fe465b386cf4f3612c52f0653e59e0c3ccd#diff-39006601e729061e5f79a8962b584937a2a57743b222e6b3a75205c2603de537R81) | [+81](https://github.com/bitweb-project/bitweb/commit/3b947fe465b386cf4f3612c52f0653e59e0c3ccd#diff-39006601e729061e5f79a8962b584937a2a57743b222e6b3a75205c2603de537R81) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### Handle CMake 4.5 warning category in CI

> [`166446f`](https://github.com/bitweb-project/bitweb/commit/166446fa2e9202cf762315ac35200e4f69c4d409) · 2026-11-19

| File | Lines |
|------|-------|
| [`.github/ci-test-each-commit-exec.py`](https://github.com/bitweb-project/bitweb/commit/166446fa2e9202cf762315ac35200e4f69c4d409#diff-3db8f8c36e425c8a0e717f585382f08c6632394e9adb3ebb48364c176d069a35R6) | [+6, 21-32, 40-42, 48](https://github.com/bitweb-project/bitweb/commit/166446fa2e9202cf762315ac35200e4f69c4d409#diff-3db8f8c36e425c8a0e717f585382f08c6632394e9adb3ebb48364c176d069a35R6) |
| [`.github/ci-windows.py`](https://github.com/bitweb-project/bitweb/commit/166446fa2e9202cf762315ac35200e4f69c4d409#diff-4e6c0a55a7b89305e553d45b51e79624225dfdbe82b906b29f711200717f3599R8) | [+8, 69-80, 87-91](https://github.com/bitweb-project/bitweb/commit/166446fa2e9202cf762315ac35200e4f69c4d409#diff-4e6c0a55a7b89305e553d45b51e79624225dfdbe82b906b29f711200717f3599R8) |
| [`ci/test/03_test_script.sh`](https://github.com/bitweb-project/bitweb/commit/166446fa2e9202cf762315ac35200e4f69c4d409#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR98-R105) | [+98-105](https://github.com/bitweb-project/bitweb/commit/166446fa2e9202cf762315ac35200e4f69c4d409#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR98-R105) |

*3 file(s) · ✏️ 3 modified · +43 / -0 lines*

---

### Update chain sync metadata to height 107900

> [`d6ac8bb`](https://github.com/bitweb-project/bitweb/commit/d6ac8bbd19576ad8a5e41341681e20509a0e5049) · 2026-11-19

| File | Lines |
|------|-------|
| [`src/kernel/chainparams.cpp`](https://github.com/bitweb-project/bitweb/commit/d6ac8bbd19576ad8a5e41341681e20509a0e5049#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR120-R121) | [+120-121, 178, 201-206, 211-214](https://github.com/bitweb-project/bitweb/commit/d6ac8bbd19576ad8a5e41341681e20509a0e5049#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR120-R121) |

*1 file(s) · ✏️ 1 modified · +13 / -6 lines*

---

### doc: update manual pages and bitweb.conf example for v31.3

> [`ce66ff6`](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942) · 2026-11-19

| File | Lines |
|------|-------|
| [`doc/man/bitweb-cli.1`](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-4a1e4af5cfba081018dc40300038923476f40d372540035ae5dac45606c568b6R2) | [+2, 4, 18](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-4a1e4af5cfba081018dc40300038923476f40d372540035ae5dac45606c568b6R2) |
| [`doc/man/bitweb-qt.1`](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-beb107ff531f83f460e550782ab61e94fd03831000fbfc59dbed59854aab4395R2) | [+2, 4, 9, 35, 381, 724-729](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-beb107ff531f83f460e550782ab61e94fd03831000fbfc59dbed59854aab4395R2) |
| [`doc/man/bitweb-tx.1`](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-4fa9b0871a18eed1236347afa0d2f0956e835e94d93d9967a3677ea5d18e5a70R2) | [+2, 4, 12](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-4fa9b0871a18eed1236347afa0d2f0956e835e94d93d9967a3677ea5d18e5a70R2) |
| [`doc/man/bitweb-util.1`](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-4bcb5d66f64dc5d368305afad8d63c9a4479c77ca0be32911291fd2e6ea13e2aR2) | [+2, 4, 12](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-4bcb5d66f64dc5d368305afad8d63c9a4479c77ca0be32911291fd2e6ea13e2aR2) |
| [`doc/man/bitweb-wallet.1`](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-c3dccf612b58c78bb9b9abfacbd8f2442733c6ac33c2893657dcd6ebde7ac29bR2) | [+2, 4, 9](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-c3dccf612b58c78bb9b9abfacbd8f2442733c6ac33c2893657dcd6ebde7ac29bR2) |
| [`doc/man/bitweb.1`](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-71c2fd6f489d08b65cb4a5d45152b276a025b7d60bb7176d67aeadf04b2ec941R2) | [+2, 4](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-71c2fd6f489d08b65cb4a5d45152b276a025b7d60bb7176d67aeadf04b2ec941R2) |
| [`doc/man/bitwebd.1`](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-bf91955718ae74b2183c2e8c8bf7d003daa1d2dd6e96d16671abf8ccb3a11744R2) | [+2, 4, 9, 35, 381, 724-729](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-bf91955718ae74b2183c2e8c8bf7d003daa1d2dd6e96d16671abf8ccb3a11744R2) |
| [`share/examples/bitweb.conf`](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R26) | [+26](https://github.com/bitweb-project/bitweb/commit/ce66ff622681863f7cdb2096ad92f90b7b472942#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R26) |

*8 file(s) · ✏️ 8 modified · +37 / -33 lines*

---

### Backport 3 bitcoin/bitcoin PRs from official 31.x: disconnect only the misbehaving peer, cmake non-target directive cleanup, memusage Clang 24 fix; revert CMake 4.5 CI workaround

> [`c079176`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0) · 2026-11-19

| File | Lines |
|------|-------|
| [`.github/ci-test-each-commit-exec.py`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-3db8f8c36e425c8a0e717f585382f08c6632394e9adb3ebb48364c176d069a35L6) | [-6, 21-32, 40-42, 48](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-3db8f8c36e425c8a0e717f585382f08c6632394e9adb3ebb48364c176d069a35L6) |
| [`.github/ci-windows.py`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-4e6c0a55a7b89305e553d45b51e79624225dfdbe82b906b29f711200717f3599L8) | [-8, 69-80, 87-91](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-4e6c0a55a7b89305e553d45b51e79624225dfdbe82b906b29f711200717f3599L8) |
| [`CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aL699-L701) | [-699-701](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aL699-L701) |
| [`ci/test/03_test_script.sh`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dL98-L105) | [-98-105](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dL98-L105) |
| ~~`cmake/module/WarnAboutGlobalProperties.cmake`~~ | 🗑 deleted |
| [`src/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-148715d6ea0c0ea0a346af3f6bd610d010d490eca35ac6a9b408748f7ca9e3f4R8-R11) | [+8-11](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-148715d6ea0c0ea0a346af3f6bd610d010d490eca35ac6a9b408748f7ca9e3f4R8-R11) |
| [`src/memusage.h`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-33f5ad9ae321c77fe0cd7e467ced4221209f9d6edb18e0d843c637295517789dL71) | [-71, 168, 183](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-33f5ad9ae321c77fe0cd7e467ced4221209f9d6edb18e0d843c637295517789dL71) |
| [`src/net.cpp`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-00021eed586a482abdb09d6cdada1d90115abe988a91421851960e26658bed02R3870) | [+3870, 3875](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-00021eed586a482abdb09d6cdada1d90115abe988a91421851960e26658bed02R3870) |
| [`src/net.h`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-422879cc8bfac56d4380c865f381b58afeb344bc355bbc7f47c581e4491b6b4bR1367) | [+1367](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-422879cc8bfac56d4380c865f381b58afeb344bc355bbc7f47c581e4491b6b4bR1367) |
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R5247) | [+5247, 5250](https://github.com/bitweb-project/bitweb/commit/c0791768dab96cbfe3a8bf0b517b7854e7ad31c0#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R5247) |

*10 file(s) · ✏️ 9 modified · 🗑 1 deleted · +9 / -55 lines*

---

Credits
=======

Thanks to everyone who directly contributed to this release:

- mraksoll4

Bitweb Core is based on Bitcoin Core.
Original Bitcoin Core developers:
  <https://github.com/bitcoin/bitcoin/graphs/contributors>
