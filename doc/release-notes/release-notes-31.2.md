Bitweb Core version v31.2 Release Notes
=======================================

Bitweb Core version v31.2 is now available from:

  <https://github.com/bitweb-project/bitweb/releases/tag/v31.2>

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

### Add release notes Bitweb Core 31.1

> [`3c4e7e2`](https://github.com/bitweb-project/bitweb/commit/3c4e7e22d3d2a4181cbcbb6401b41fb172a91756) · 2026-06-26

| File | Lines |
|------|-------|
| [`doc/release-notes.md`](https://github.com/bitweb-project/bitweb/commit/3c4e7e22d3d2a4181cbcbb6401b41fb172a91756#diff-e04cb1e9f29f76897c6b84334238f621ff45ba13cf180ad1d0d442d50ebe51f7R1-R2) | [+1-2, 4, 6-8, 15, 19-20, 25-44, 48-53, 56, 59-534, 536, 538, 540, 542, 544-617, 619, 621, 623, 625, 627-793, 795, 797, 799, 801, 803-986, 988, 990-1098, 1105-1109](https://github.com/bitweb-project/bitweb/commit/3c4e7e22d3d2a4181cbcbb6401b41fb172a91756#diff-e04cb1e9f29f76897c6b84334238f621ff45ba13cf180ad1d0d442d50ebe51f7R1-R2) |
| [`doc/release-notes/release-notes-30.3.1.md`](https://github.com/bitweb-project/bitweb/commit/3c4e7e22d3d2a4181cbcbb6401b41fb172a91756#diff-32dbb8cbc0763cf72e340d8cd011b16d1dca6f50ea9d18c2bfa74bdbca4f2474R1-R310) | [+1-310](https://github.com/bitweb-project/bitweb/commit/3c4e7e22d3d2a4181cbcbb6401b41fb172a91756#diff-32dbb8cbc0763cf72e340d8cd011b16d1dca6f50ea9d18c2bfa74bdbca4f2474R1-R310) |
| [`doc/release-notes/release-notes-31.1.md`](https://github.com/bitweb-project/bitweb/commit/3c4e7e22d3d2a4181cbcbb6401b41fb172a91756#diff-390c8c7074f8e3b70c3ce99b3fbdd99abc7edd7b1ab8c016415714af4cf7e386R1-R1109) | [+1-1109](https://github.com/bitweb-project/bitweb/commit/3c4e7e22d3d2a4181cbcbb6401b41fb172a91756#diff-390c8c7074f8e3b70c3ce99b3fbdd99abc7edd7b1ab8c016415714af4cf7e386R1-R1109) |

*3 file(s) · ✏️ 1 modified · 🆕 2 new · +2483 / -58 lines*

---

### Update address formats to BitWeb

> [`08c2bef`](https://github.com/bitweb-project/bitweb/commit/08c2befbdcb4744c8f0923b50a9253617b0ae107) · 2026-06-27

| File | Lines |
|------|-------|
| [`src/qt/forms/receiverequestdialog.ui`](https://github.com/bitweb-project/bitweb/commit/08c2befbdcb4744c8f0923b50a9253617b0ae107#diff-922feaa8d4fa6c0e3e860ed79ae9b454be10bb1bf98226e09b1079da17b84b19R100) | [+100](https://github.com/bitweb-project/bitweb/commit/08c2befbdcb4744c8f0923b50a9253617b0ae107#diff-922feaa8d4fa6c0e3e860ed79ae9b454be10bb1bf98226e09b1079da17b84b19R100) |
| [`src/qt/guiutil.cpp`](https://github.com/bitweb-project/bitweb/commit/08c2befbdcb4744c8f0923b50a9253617b0ae107#diff-f2c7d602216ecc4b5d3980a81ebc57d56fb77ff0af5dd5dccdc3c06dba0a9ba6R114) | [+114](https://github.com/bitweb-project/bitweb/commit/08c2befbdcb4744c8f0923b50a9253617b0ae107#diff-f2c7d602216ecc4b5d3980a81ebc57d56fb77ff0af5dd5dccdc3c06dba0a9ba6R114) |

*2 file(s) · ✏️ 2 modified · +2 / -2 lines*

---

### Update qrencode download source to GitHub mirror

> [`38450c8`](https://github.com/bitweb-project/bitweb/commit/38450c8580116ba4f828c3387f596254ad9e0724) · 2026-06-27

| File | Lines |
|------|-------|
| [`depends/packages/qrencode.mk`](https://github.com/bitweb-project/bitweb/commit/38450c8580116ba4f828c3387f596254ad9e0724#diff-f2215c893b0f7d9d6b790a04afcd5e3887c46ce2d774b60db65fe0c17caf0dcdR3) | [+3](https://github.com/bitweb-project/bitweb/commit/38450c8580116ba4f828c3387f596254ad9e0724#diff-f2215c893b0f7d9d6b790a04afcd5e3887c46ce2d774b60db65fe0c17caf0dcdR3) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### Update security report link in bug template

> [`df0a296`](https://github.com/bitweb-project/bitweb/commit/df0a296fc7632564d8a0ccf34f1be340496477dd) · 2026-06-28

| File | Lines |
|------|-------|
| [`.github/ISSUE_TEMPLATE/bug.yml`](https://github.com/bitweb-project/bitweb/commit/df0a296fc7632564d8a0ccf34f1be340496477dd#diff-45b5634e925b86895feee745ec5650893bae0d56e11b379745e506fd9a6b81bdR11) | [+11](https://github.com/bitweb-project/bitweb/commit/df0a296fc7632564d8a0ccf34f1be340496477dd#diff-45b5634e925b86895feee745ec5650893bae0d56e11b379745e506fd9a6b81bdR11) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### Update release announcement URL

> [`ee48dd9`](https://github.com/bitweb-project/bitweb/commit/ee48dd9b4cddaa1062a1c9300e3a04e4299057f4) · 2026-06-28

| File | Lines |
|------|-------|
| [`doc/release-process.md`](https://github.com/bitweb-project/bitweb/commit/ee48dd9b4cddaa1062a1c9300e3a04e4299057f4#diff-723b9eeeb819047ef03f827ee8a3ccfef48ce7ef6a340a068a68b551993fe70bR226) | [+226](https://github.com/bitweb-project/bitweb/commit/ee48dd9b4cddaa1062a1c9300e3a04e4299057f4#diff-723b9eeeb819047ef03f827ee8a3ccfef48ce7ef6a340a068a68b551993fe70bR226) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### fix default HRP to web

> [`3413030`](https://github.com/bitweb-project/bitweb/commit/3413030e8823cb87764ffa07153538c03391d11a) · 2026-06-28

| File | Lines |
|------|-------|
| [`contrib/testgen/README.md`](https://github.com/bitweb-project/bitweb/commit/3413030e8823cb87764ffa07153538c03391d11a#diff-d8df83d12b208f8ce8ab14593be760c0713da0795c1d2a3bc40ac263f1cf2039R18) | [+18, 23](https://github.com/bitweb-project/bitweb/commit/3413030e8823cb87764ffa07153538c03391d11a#diff-d8df83d12b208f8ce8ab14593be760c0713da0795c1d2a3bc40ac263f1cf2039R18) |
| [`contrib/testgen/gen_validateaddress_vectors.py`](https://github.com/bitweb-project/bitweb/commit/3413030e8823cb87764ffa07153538c03391d11a#diff-79ee210143bb88501460cca7424eca4ff3b786303400d7a964210115cff99b2dR10) | [+10, 14, 77](https://github.com/bitweb-project/bitweb/commit/3413030e8823cb87764ffa07153538c03391d11a#diff-79ee210143bb88501460cca7424eca4ff3b786303400d7a964210115cff99b2dR10) |

*2 file(s) · ✏️ 2 modified · +5 / -5 lines*

---

### Update example addresses in signmessage RPC help

> [`e76a52d`](https://github.com/bitweb-project/bitweb/commit/e76a52d05c50e07fbbf1b10da2f4151e658b3371) · 2026-06-29

| File | Lines |
|------|-------|
| [`src/rpc/signmessage.cpp`](https://github.com/bitweb-project/bitweb/commit/e76a52d05c50e07fbbf1b10da2f4151e658b3371#diff-5919c1cbf46eb27881c22816a1d4e8285140b8cf4762d60376f8822528c3a09cR33) | [+33, 35, 37, 78](https://github.com/bitweb-project/bitweb/commit/e76a52d05c50e07fbbf1b10da2f4151e658b3371#diff-5919c1cbf46eb27881c22816a1d4e8285140b8cf4762d60376f8822528c3a09cR33) |

*1 file(s) · ✏️ 1 modified · +4 / -4 lines*

---

### fuzz: add accepted-socket node creation case

> [`8883bb8`](https://github.com/bitweb-project/bitweb/commit/8883bb84d9cd6160625abeabaf3324d80a15b8e3) · 2026-06-29

| File | Lines |
|------|-------|
| [`src/test/fuzz/connman.cpp`](https://github.com/bitweb-project/bitweb/commit/8883bb84d9cd6160625abeabaf3324d80a15b8e3#diff-d80b7546ab6ca6e446434e1bbb261c3846faf540a3ca6b8a548617f2a93af26fR190-R198) | [+190-198](https://github.com/bitweb-project/bitweb/commit/8883bb84d9cd6160625abeabaf3324d80a15b8e3#diff-d80b7546ab6ca6e446434e1bbb261c3846faf540a3ca6b8a548617f2a93af26fR190-R198) |

*1 file(s) · ✏️ 1 modified · +9 / -0 lines*

---

### Fix Taproot deployment on mainnet

> [`7d53aea`](https://github.com/bitweb-project/bitweb/commit/7d53aeaf5a1531688570865065df76c8d417a06c) · 2026-06-29

| File | Lines |
|------|-------|
| [`src/kernel/chainparams.cpp`](https://github.com/bitweb-project/bitweb/commit/7d53aeaf5a1531688570865065df76c8d417a06c#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR114) | [+114, 250](https://github.com/bitweb-project/bitweb/commit/7d53aeaf5a1531688570865065df76c8d417a06c#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR114) |

*1 file(s) · ✏️ 1 modified · +2 / -2 lines*

---

### Add header PoW verification cache (pow_cache)

> [`9320cc4`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00) · 2026-07-05

| File | Lines |
|------|-------|
| [`src/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-148715d6ea0c0ea0a346af3f6bd610d010d490eca35ac6a9b408748f7ca9e3f4R126) | [+126](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-148715d6ea0c0ea0a346af3f6bd610d010d490eca35ac6a9b408748f7ca9e3f4R126) |
| [`src/init.cpp`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-b1e19192258d83199d8adaa5ac31f067af98f63554bfdd679bd8e8073815e69dR66) | [+66, 508-510, 1342-1349](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-b1e19192258d83199d8adaa5ac31f067af98f63554bfdd679bd8e8073815e69dR66) |
| [`src/kernel/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-833a13a4d795b3e5e25ccc9bfc3f62b8639cf21ef66d028499bf9bb26a65387aR45) | [+45](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-833a13a4d795b3e5e25ccc9bfc3f62b8639cf21ef66d028499bf9bb26a65387aR45) |
| [`src/kernel/chainstatemanager_opts.h`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-72bfc3c331430d65bff7edb3e7fe4c622e1eac412a84e378f58c8d40e33f1824R12) | [+12, 54-59](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-72bfc3c331430d65bff7edb3e7fe4c622e1eac412a84e378f58c8d40e33f1824R12) |
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3L3023-L3047) | [-3023-3047, 3131-3141](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3L3023-L3047) |
| [`src/node/blockstorage.cpp`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR19) | [+19, 1085-1090](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR19) |
| [`src/node/chainstatemanager_args.cpp`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-810d8474f5c6aeb8f854258e357a32f5d60cc38c12327745648bc6d979cff63eR74-R83) | [+74-83](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-810d8474f5c6aeb8f854258e357a32f5d60cc38c12327745648bc6d979cff63eR74-R83) |
| [`src/pow_cache.cpp`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-61cd82042cb3c4237cadc306df26b7a24f2161477a242661b30988ba95ed378fR1-R39) | [+1-39](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-61cd82042cb3c4237cadc306df26b7a24f2161477a242661b30988ba95ed378fR1-R39) |
| [`src/pow_cache.h`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-75b762488a3922139a476445631fb7ce25a22daa6a2835de53d9842e78874339R1-R182) | [+1-182](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-75b762488a3922139a476445631fb7ce25a22daa6a2835de53d9842e78874339R1-R182) |
| [`src/test/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-921b2054f6bf380eb08d5c3c21cf8d1c7cfee3736227d611400ae1a13ab3d187R83) | [+83](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-921b2054f6bf380eb08d5c3c21cf8d1c7cfee3736227d611400ae1a13ab3d187R83) |
| [`src/test/fuzz/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-b937c829d4a0cf9a653f5361656ea8196b6ecef40fd033aa41a6da945e987bcdR96-R97) | [+96-97](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-b937c829d4a0cf9a653f5361656ea8196b6ecef40fd033aa41a6da945e987bcdR96-R97) |
| [`src/test/fuzz/pow_cache.cpp`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-5f2f56e12902d67139e63bba525063c7476324c4f0b3e5a93d12aa9e79744cb9R1-R83) | [+1-83](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-5f2f56e12902d67139e63bba525063c7476324c4f0b3e5a93d12aa9e79744cb9R1-R83) |
| [`src/test/fuzz/pow_cache_check.cpp`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-21e326ea4bd9439f8532024d2c106e7fb33fa180f3625b4d9fe0b6ff59417858R1-R99) | [+1-99](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-21e326ea4bd9439f8532024d2c106e7fb33fa180f3625b4d9fe0b6ff59417858R1-R99) |
| [`src/test/pow_cache_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-98c7d65736a2775597ff0ec57343e3c59c37f0f3c6bf7eb5bbddfb5c56aa3b04R1-R304) | [+1-304](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-98c7d65736a2775597ff0ec57343e3c59c37f0f3c6bf7eb5bbddfb5c56aa3b04R1-R304) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R40) | [+40, 77, 3931-3941, 3945-3947, 3949, 4140-4171, 4174-4190](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R40) |
| [`src/validation.h`](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR420-R460) | [+420-460](https://github.com/bitweb-project/bitweb/commit/9320cc42bf2122d4f32faea492e56057dd150d00#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR420-R460) |

*16 file(s) · ✏️ 11 modified · 🆕 5 new · +855 / -44 lines*

---

### Backport net assert-crash + m_blocks_unlinked UB fixes from bitcoin/bitcoin

> [`ce3b1a6`](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f) · 2026-07-05

| File | Lines |
|------|-------|
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R1967-R1976) | [+1967-1976](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R1967-R1976) |
| [`src/node/blockstorage.cpp`](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR271-R284) | [+271-284, 527-531](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR271-R284) |
| [`src/node/blockstorage.h`](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-ed3f90693a242b38b9719af171de8f55183576957676dfa358945bea22276bd5R354-R358) | [+354-358](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-ed3f90693a242b38b9719af171de8f55183576957676dfa358945bea22276bd5R354-R358) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R3258-R3264) | [+3258-3264, 3931-3933, 5537-5540, 5543-5546](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R3258-R3264) |
| [`test/functional/feature_pruning.py`](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-f15bffeef80285cc29f5d73fc6c0b4e0df7f967a36ffdecf41b123b113cc3af4R295-R342) | [+295-342, 357-365, 380, 390-401, 509-517, 525-526](https://github.com/bitweb-project/bitweb/commit/ce3b1a6a7fa16b81c6a966bcb3f18f22264c083f#diff-f15bffeef80285cc29f5d73fc6c0b4e0df7f967a36ffdecf41b123b113cc3af4R295-R342) |

*5 file(s) · ✏️ 5 modified · +133 / -24 lines*

---

### Fix typos and Doxygen comment formatting

> [`d5db1bc`](https://github.com/bitweb-project/bitweb/commit/d5db1bc546157128742d49184474482e21c3abe6) · 2026-07-05

| File | Lines |
|------|-------|
| [`src/index/coinstatsindex.cpp`](https://github.com/bitweb-project/bitweb/commit/d5db1bc546157128742d49184474482e21c3abe6#diff-f1b8261031c7f062025f97106824d80601e5247ba0b68ffe608285eeaecceed2R130) | [+130, 363](https://github.com/bitweb-project/bitweb/commit/d5db1bc546157128742d49184474482e21c3abe6#diff-f1b8261031c7f062025f97106824d80601e5247ba0b68ffe608285eeaecceed2R130) |
| [`src/rpc/blockchain.cpp`](https://github.com/bitweb-project/bitweb/commit/d5db1bc546157128742d49184474482e21c3abe6#diff-decae4be02fb8a47ab4557fe74a9cb853bdfa3ec0fa1b515c0a1e5de91f4ad0bR2098) | [+2098](https://github.com/bitweb-project/bitweb/commit/d5db1bc546157128742d49184474482e21c3abe6#diff-decae4be02fb8a47ab4557fe74a9cb853bdfa3ec0fa1b515c0a1e5de91f4ad0bR2098) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/d5db1bc546157128742d49184474482e21c3abe6#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R2239) | [+2239, 2250, 2264, 2452, 2483, 2522, 6369](https://github.com/bitweb-project/bitweb/commit/d5db1bc546157128742d49184474482e21c3abe6#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R2239) |
| [`src/validation.h`](https://github.com/bitweb-project/bitweb/commit/d5db1bc546157128742d49184474482e21c3abe6#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR134-R137) | [+134-137, 1441](https://github.com/bitweb-project/bitweb/commit/d5db1bc546157128742d49184474482e21c3abe6#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR134-R137) |

*4 file(s) · ✏️ 4 modified · +15 / -15 lines*

---

### Backport 5 unmerged bitcoin/bitcoin fixes: BIP152 sendcmpct validation, private-broadcast hardening, mempool package cleanup

> [`b28eb3b`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0) · 2026-07-06

| File | Lines |
|------|-------|
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R1857) | [+1857, 1872-1873, 3919-3921, 3925-3931](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R1857) |
| [`src/net_processing.h`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-2a4e846ad2d76a4e7a6f6c46a68b3603de372f435a93b7c0fcabadccc0ed86a5R74-R78) | [+74-78](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-2a4e846ad2d76a4e7a6f6c46a68b3603de372f435a93b7c0fcabadccc0ed86a5R74-R78) |
| [`src/private_broadcast.cpp`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-ad1d5d83183a5facaf06e2b44c42a3e942a261b7506576720588bf6b158e4c3dR24) | [+24, 35-42, 46, 49-50, 100, 102-107, 120, 122-123, 126, 150-151](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-ad1d5d83183a5facaf06e2b44c42a3e942a261b7506576720588bf6b158e4c3dR24) |
| [`src/private_broadcast.h`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-3ef5e45a5e964dd0121f7f28bf609b2368db3e64370973764a12f2b73b5a21aeR33-R46) | [+33-46, 55, 82-84, 198-205, 207](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-3ef5e45a5e964dd0121f7f28bf609b2368db3e64370973764a12f2b73b5a21aeR33-R46) |
| [`src/rpc/mempool.cpp`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-9c5b83de6dc84af277e352c88b9291aa44340a3c75f572a0b51661eb0a838de9R146-R147) | [+146-147, 159, 180-185, 194, 221-222, 249-255](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-9c5b83de6dc84af277e352c88b9291aa44340a3c75f572a0b51661eb0a838de9R146-R147) |
| [`src/test/fuzz/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-b937c829d4a0cf9a653f5361656ea8196b6ecef40fd033aa41a6da945e987bcdR100) | [+100](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-b937c829d4a0cf9a653f5361656ea8196b6ecef40fd033aa41a6da945e987bcdR100) |
| [`src/test/fuzz/private_broadcast.cpp`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-39006601e729061e5f79a8962b584937a2a57743b222e6b3a75205c2603de537R1-R209) | [+1-209](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-39006601e729061e5f79a8962b584937a2a57743b222e6b3a75205c2603de537R1-R209) |
| [`src/test/fuzz/util.h`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-bcbe4978aa0ddb19ebfb5825aedefd3f2c4f1f2f5df5bd072835d3ac9071a8acR47) | [+47, 49, 51-57](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-bcbe4978aa0ddb19ebfb5825aedefd3f2c4f1f2f5df5bd072835d3ac9071a8acR47) |
| [`src/test/private_broadcast_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-b9dee9539db2b41a3765f60d067d5274d3c0e775ba8c31ec058cee7c5d9b5eb9R93-R99) | [+93-99, 112, 118, 124-126, 142-159](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-b9dee9539db2b41a3765f60d067d5274d3c0e775ba8c31ec058cee7c5d9b5eb9R93-R99) |
| [`src/test/util/time.h`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-9cfd7a9bb9f935e8e172e5c156189b38611051801a53264766ce81ed539c4e2aR37-R61) | [+37-61](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-9cfd7a9bb9f935e8e172e5c156189b38611051801a53264766ce81ed539c4e2aR37-R61) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R1304-R1313) | [+1304-1313](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R1304-R1313) |
| [`test/functional/p2p_compactblocks.py`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-3d0d1b84c608319965e0c2675eefadc6820103793bf5a9d671562bc24dcbc3eaR266-R277) | [+266-277, 1034-1036](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-3d0d1b84c608319965e0c2675eefadc6820103793bf5a9d671562bc24dcbc3eaR266-R277) |
| [`test/functional/p2p_private_broadcast.py`](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-5e0f9b2acd7402cef49727e77fc1216ff54a11309243673e57a08da7b01820c1R226-R231) | [+226-231](https://github.com/bitweb-project/bitweb/commit/b28eb3bb113518dca3e07bef35c05112ca850da0#diff-5e0f9b2acd7402cef49727e77fc1216ff54a11309243673e57a08da7b01820c1R226-R231) |

*13 file(s) · ✏️ 12 modified · 🆕 1 new · +394 / -37 lines*

---

### Use Argon2id PoW hash in tests

> [`6b36958`](https://github.com/bitweb-project/bitweb/commit/6b36958cfcc71b50f0fe6d26345230b1ed32f458) · 2026-07-07

| File | Lines |
|------|-------|
| [`src/test/headers_sync_chainwork_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/6b36958cfcc71b50f0fe6d26345230b1ed32f458#diff-46faf106e779941e78de61d061d7817f9dd7b1f12a4157e6991417c7f0a7e9d3R109) | [+109](https://github.com/bitweb-project/bitweb/commit/6b36958cfcc71b50f0fe6d26345230b1ed32f458#diff-46faf106e779941e78de61d061d7817f9dd7b1f12a4157e6991417c7f0a7e9d3R109) |
| [`src/test/miner_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/6b36958cfcc71b50f0fe6d26345230b1ed32f458#diff-b12066a688b85bea440eb38f079fb8ecc1984318470631bca7e3547a98effaa9R805) | [+805](https://github.com/bitweb-project/bitweb/commit/6b36958cfcc71b50f0fe6d26345230b1ed32f458#diff-b12066a688b85bea440eb38f079fb8ecc1984318470631bca7e3547a98effaa9R805) |

*2 file(s) · ✏️ 2 modified · +2 / -2 lines*

---

### Move header PoW check queue into ChainstateManager

> [`30516a6`](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d) · 2026-07-07

| File | Lines |
|------|-------|
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R2633-R2634) | [+2633-2634](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R2633-R2634) |
| [`src/test/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-921b2054f6bf380eb08d5c3c21cf8d1c7cfee3736227d611400ae1a13ab3d187R52) | [+52](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-921b2054f6bf380eb08d5c3c21cf8d1c7cfee3736227d611400ae1a13ab3d187R52) |
| [`src/test/header_pow_queue_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-5313ba7db8cc3abc746441e256396eaaf4fb9393993ffda0e575f50a106e5715R1-R343) | [+1-343](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-5313ba7db8cc3abc746441e256396eaaf4fb9393993ffda0e575f50a106e5715R1-R343) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R4165-R4173) | [+4165-4173, 4177, 4180, 4191, 6317](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R4165-R4173) |
| [`src/validation.h`](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR456-R460) | [+456-460, 1023-1032, 1421-1428](https://github.com/bitweb-project/bitweb/commit/30516a68fab2ae0d9bc1afddc8f150b6bf08105d#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR456-R460) |

*5 file(s) · ✏️ 4 modified · 🆕 1 new · +382 / -24 lines*

---

### build: bump version to v31.2

> [`410f8f0`](https://github.com/bitweb-project/bitweb/commit/410f8f0016124e503247544c308787fbdcbd6da8) · 2026-07-07

| File | Lines |
|------|-------|
| [`CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/410f8f0016124e503247544c308787fbdcbd6da8#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR31) | [+31](https://github.com/bitweb-project/bitweb/commit/410f8f0016124e503247544c308787fbdcbd6da8#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR31) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### Update mainnet chainparams for block 69000

> [`8a9eb7f`](https://github.com/bitweb-project/bitweb/commit/8a9eb7f9e5a51d999689df28ed0a8bc34a8fdc9c) · 2026-07-07

| File | Lines |
|------|-------|
| [`src/kernel/chainparams.cpp`](https://github.com/bitweb-project/bitweb/commit/8a9eb7f9e5a51d999689df28ed0a8bc34a8fdc9c#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR120-R121) | [+120-121, 177, 194-199, 204-207](https://github.com/bitweb-project/bitweb/commit/8a9eb7f9e5a51d999689df28ed0a8bc34a8fdc9c#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR120-R121) |

*1 file(s) · ✏️ 1 modified · +13 / -6 lines*

---

### doc: update manual pages and bitweb.conf example for v31.2

> [`8437722`](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5) · 2026-07-07

| File | Lines |
|------|-------|
| [`doc/man/bitweb-cli.1`](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-4a1e4af5cfba081018dc40300038923476f40d372540035ae5dac45606c568b6R2) | [+2, 4, 18](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-4a1e4af5cfba081018dc40300038923476f40d372540035ae5dac45606c568b6R2) |
| [`doc/man/bitweb-qt.1`](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-beb107ff531f83f460e550782ab61e94fd03831000fbfc59dbed59854aab4395R2) | [+2, 4, 9, 35, 112-120](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-beb107ff531f83f460e550782ab61e94fd03831000fbfc59dbed59854aab4395R2) |
| [`doc/man/bitweb-tx.1`](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-4fa9b0871a18eed1236347afa0d2f0956e835e94d93d9967a3677ea5d18e5a70R2) | [+2, 4, 12](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-4fa9b0871a18eed1236347afa0d2f0956e835e94d93d9967a3677ea5d18e5a70R2) |
| [`doc/man/bitweb-util.1`](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-4bcb5d66f64dc5d368305afad8d63c9a4479c77ca0be32911291fd2e6ea13e2aR2) | [+2, 4, 12](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-4bcb5d66f64dc5d368305afad8d63c9a4479c77ca0be32911291fd2e6ea13e2aR2) |
| [`doc/man/bitweb-wallet.1`](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-c3dccf612b58c78bb9b9abfacbd8f2442733c6ac33c2893657dcd6ebde7ac29bR2) | [+2, 4, 9](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-c3dccf612b58c78bb9b9abfacbd8f2442733c6ac33c2893657dcd6ebde7ac29bR2) |
| [`doc/man/bitweb.1`](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-71c2fd6f489d08b65cb4a5d45152b276a025b7d60bb7176d67aeadf04b2ec941R2) | [+2, 4](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-71c2fd6f489d08b65cb4a5d45152b276a025b7d60bb7176d67aeadf04b2ec941R2) |
| [`doc/man/bitwebd.1`](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-bf91955718ae74b2183c2e8c8bf7d003daa1d2dd6e96d16671abf8ccb3a11744R2) | [+2, 4, 9, 35, 112-120](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-bf91955718ae74b2183c2e8c8bf7d003daa1d2dd6e96d16671abf8ccb3a11744R2) |
| [`share/examples/bitweb.conf`](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R26) | [+26, 91-98](https://github.com/bitweb-project/bitweb/commit/84377222df9f74f11d8250d422e470e5e6e113c5#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R26) |

*8 file(s) · ✏️ 8 modified · +49 / -23 lines*

---

Credits
=======

Thanks to everyone who directly contributed to this release:

- mraksoll4

Bitweb Core is based on Bitcoin Core.
Original Bitcoin Core developers:
  <https://github.com/bitcoin/bitcoin/graphs/contributors>
