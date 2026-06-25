Bitweb Core version v30.3.1 Release Notes
=========================================

Bitweb Core version v30.3.1 is now available from:

  <https://github.com/bitweb-project/bitweb/releases/tag/v30.3.1>

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

### Add Bitweb Core v30.3 release notes

> [`46ec67c`](https://github.com/bitweb-project/bitweb/commit/46ec67c7393e33d15805895a5bd0b8c385630328) · 2026-06-05

| File | Lines |
|------|-------|
| [`doc/release-notes.md`](https://github.com/bitweb-project/bitweb/commit/46ec67c7393e33d15805895a5bd0b8c385630328#diff-e04cb1e9f29f76897c6b84334238f621ff45ba13cf180ad1d0d442d50ebe51f7R1-R1099) | [+1-1099](https://github.com/bitweb-project/bitweb/commit/46ec67c7393e33d15805895a5bd0b8c385630328#diff-e04cb1e9f29f76897c6b84334238f621ff45ba13cf180ad1d0d442d50ebe51f7R1-R1099) |

*1 file(s) · 🆕 1 new · +1099 / -0 lines*

---

### Add release notes for v30.3

> [`2a65a6e`](https://github.com/bitweb-project/bitweb/commit/2a65a6ed71a3ac3014facec29a9a29c67103c6b5) · 2026-06-05

| File | Lines |
|------|-------|
| [`doc/release-notes/release-notes-30.3.md`](https://github.com/bitweb-project/bitweb/commit/2a65a6ed71a3ac3014facec29a9a29c67103c6b5#diff-7753d355bf9ec7651c2df7b00e286373469f77d6161a15a5f74249fc99cbe250R1-R1099) | [+1-1099](https://github.com/bitweb-project/bitweb/commit/2a65a6ed71a3ac3014facec29a9a29c67103c6b5#diff-7753d355bf9ec7651c2df7b00e286373469f77d6161a15a5f74249fc99cbe250R1-R1099) |

*1 file(s) · 🆕 1 new · +1099 / -0 lines*

---

### fix nsis-header.bmp

> [`948ba62`](https://github.com/bitweb-project/bitweb/commit/948ba62e0f8b6c7df715cdc7c3b07f912ec01353) · 2026-06-12

| File | Lines |
|------|-------|
| [`share/pixmaps/nsis-header.bmp`](https://github.com/bitweb-project/bitweb/commit/948ba62e0f8b6c7df715cdc7c3b07f912ec01353) | 🔄 binary / full replacement |

*1 file(s) · 🔄 1 binary · +0 / -0 lines*

---

### Fix translation references to bitcoin filenames

> [`9c0d90c`](https://github.com/bitweb-project/bitweb/commit/9c0d90c709bd12feb5f8c8035ad2a8ccb686a93f) · 2026-06-18

| File | Lines |
|------|-------|
| [`src/qt/locale/bitcoin_en.ts`](https://github.com/bitweb-project/bitweb/commit/9c0d90c709bd12feb5f8c8035ad2a8ccb686a93f#diff-f1c140284e6cff64469345346fa556ff65ab02c80652afbf76d429ff904046c3R343) | [+343, 371, 2495, 2714, 5116, 5336](https://github.com/bitweb-project/bitweb/commit/9c0d90c709bd12feb5f8c8035ad2a8ccb686a93f#diff-f1c140284e6cff64469345346fa556ff65ab02c80652afbf76d429ff904046c3R343) |
| [`src/qt/locale/bitcoin_en.xlf`](https://github.com/bitweb-project/bitweb/commit/9c0d90c709bd12feb5f8c8035ad2a8ccb686a93f#diff-8aad1624314c49a1af7ae86b86ddb4acb1846fa4c1d8ec5a11238ffeb98e161aR289) | [+289, 333, 2209, 4498](https://github.com/bitweb-project/bitweb/commit/9c0d90c709bd12feb5f8c8035ad2a8ccb686a93f#diff-8aad1624314c49a1af7ae86b86ddb4acb1846fa4c1d8ec5a11238ffeb98e161aR289) |

*2 file(s) · ✏️ 2 modified · +10 / -10 lines*

---

### fix langs.

> [`e5df40e`](https://github.com/bitweb-project/bitweb/commit/e5df40e35aa65e2c5c7681a59a8456a40f475158) · 2026-06-18

| File | Lines |
|------|-------|
| [`src/qt/locale/bitcoin_ru.ts`](https://github.com/bitweb-project/bitweb/commit/e5df40e35aa65e2c5c7681a59a8456a40f475158#diff-931edc85a8e103653170e316381a0088fcf4ca7c889bba77033535ed066bdcb2R1) | [+1](https://github.com/bitweb-project/bitweb/commit/e5df40e35aa65e2c5c7681a59a8456a40f475158#diff-931edc85a8e103653170e316381a0088fcf4ca7c889bba77033535ed066bdcb2R1) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### Rename bitweb-tidy and gen scripts to bitcoin

> [`d0b5019`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5) · 2026-06-20

| File | Lines |
|------|-------|
| [`.github/workflows/ci.yml`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b803fcb7f17ed9235f1e5cb1fcd2f5d3b2838429d4368ae4c57ce4436577f03fR332) | [+332](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b803fcb7f17ed9235f1e5cb1fcd2f5d3b2838429d4368ae4c57ce4436577f03fR332) |
| [`README.md`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b335630551682c19a781afebcf4d07bf978fb1f8ac04c6bf87428ed5106870f5R7) | [+7](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b335630551682c19a781afebcf4d07bf978fb1f8ac04c6bf87428ed5106870f5R7) |
| [`ci/test/03_test_script.sh`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR202) | [+202, 204, 213](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR202) |
| [`contrib/devtools/README.md`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b339fc9f4c4c3b63dad6a97d5dc4b48f2b8ab743462a36617aecdca024239a90R147) | [+147, 159](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b339fc9f4c4c3b63dad6a97d5dc4b48f2b8ab743462a36617aecdca024239a90R147) |
| `contrib/devtools/bitweb-tidy/CMakeLists.txt` → [`contrib/devtools/bitcoin-tidy/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b2e85ef2990529a0e7fbf71130db9b2b248cb3dda2414ae84ef3300f832454d2R3) | [+3, 28-29, 33, 35-36, 41-42, 47, 49-50, 54, 57, 61-62, 64, 67](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b2e85ef2990529a0e7fbf71130db9b2b248cb3dda2414ae84ef3300f832454d2R3) |
| `contrib/devtools/bitweb-tidy/README.md` → [`contrib/devtools/bitcoin-tidy/README.md`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-a046149efacfed2ef4004219482fd733df97e228b32977b64c989cb831953f90R10) | [+10](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-a046149efacfed2ef4004219482fd733df97e228b32977b64c989cb831953f90R10) |
| `contrib/devtools/bitweb-tidy/bitweb-tidy.cpp` → [`contrib/devtools/bitcoin-tidy/bitcoin-tidy.cpp`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5) | 📝 renamed only |
| `contrib/devtools/bitweb-tidy/example_nontrivial-threadlocal.cpp` → [`contrib/devtools/bitcoin-tidy/example_nontrivial-threadlocal.cpp`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5) | 📝 renamed only |
| `contrib/devtools/bitweb-tidy/nontrivial-threadlocal.cpp` → [`contrib/devtools/bitcoin-tidy/nontrivial-threadlocal.cpp`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5) | 📝 renamed only |
| `contrib/devtools/bitweb-tidy/nontrivial-threadlocal.h` → [`contrib/devtools/bitcoin-tidy/nontrivial-threadlocal.h`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5) | 📝 renamed only |
| `contrib/devtools/gen-bitweb-conf.sh` → [`contrib/devtools/gen-bitcoin-conf.sh`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-cf267b6a4650b608f425b6b49b3644ff185ebd6419c93e20db4a8e1a2569c98cR10) | [+10, 14, 17, 19, 24-25, 37, 52](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-cf267b6a4650b608f425b6b49b3644ff185ebd6419c93e20db4a8e1a2569c98cR10) |
| [`contrib/guix/libexec/build.sh`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b5a81ce4722af8d7ce7cdcedc96e08289c8b5ca680fa5d032feb5f3e5f3e109fR308) | [+308](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b5a81ce4722af8d7ce7cdcedc96e08289c8b5ca680fa5d032feb5f3e5f3e109fR308) |
| [`doc/bitweb-conf.md`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-2bf94402e6d9b638ce2ccc7eeaeabc6bad20fef571675a792646bc388b2c7b18R84) | [+84](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-2bf94402e6d9b638ce2ccc7eeaeabc6bad20fef571675a792646bc388b2c7b18R84) |
| [`doc/files.md`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-583f605f372805d0bc87ebfc893f835b3f66746f560611e682bd917de17586d2R141) | [+141](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-583f605f372805d0bc87ebfc893f835b3f66746f560611e682bd917de17586d2R141) |
| [`doc/release-process.md`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-723b9eeeb819047ef03f827ee8a3ccfef48ce7ef6a340a068a68b551993fe70bR10) | [+10](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-723b9eeeb819047ef03f827ee8a3ccfef48ce7ef6a340a068a68b551993fe70bR10) |
| [`share/examples/bitweb.conf`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R3) | [+3](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R3) |
| [`src/consensus/params.h`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-f5aa51ec54f17eba17214e33d06708d02f073dc9edaa271e05787b43d21a3b73R59) | [+59, 61, 64](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-f5aa51ec54f17eba17214e33d06708d02f073dc9edaa271e05787b43d21a3b73R59) |
| [`test/fuzz/test_runner.py`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b1829436a71d5d787b3a5c51821e7b9fd44eb9df2a989705fd863634a51feeeeR108) | [+108](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-b1829436a71d5d787b3a5c51821e7b9fd44eb9df2a989705fd863634a51feeeeR108) |
| [`test/lint/lint-include-guards.py`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-ece5ec2135e313bc888b43b3fa7cfc867852677738cc8f4f0f023df007e49f87R21) | [+21](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-ece5ec2135e313bc888b43b3fa7cfc867852677738cc8f4f0f023df007e49f87R21) |
| [`test/lint/lint-includes.py`](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-0135df6eccee6b742b45e7145ee3a27f40a3210b022fa9030bb94339638b830cR20) | [+20](https://github.com/bitweb-project/bitweb/commit/d0b50196479658edd18814ebe96b3060de81eba5#diff-0135df6eccee6b742b45e7145ee3a27f40a3210b022fa9030bb94339638b830cR20) |

*20 file(s) · ✏️ 13 modified · 📝 7 renamed · +44 / -45 lines*

---

### fix: set executable permissions for contrib/devtools/gen-bitcoin-conf.sh

> [`ce4b01e`](https://github.com/bitweb-project/bitweb/commit/ce4b01ee2f02e7c4c6dd3f6ff8cce77bec2b7b46) · 2026-06-20

| File | Lines |
|------|-------|
| [``](https://github.com/bitweb-project/bitweb/commit/ce4b01ee2f02e7c4c6dd3f6ff8cce77bec2b7b46) | — |

*1 file(s) · ✏️ 1 modified · +0 / -0 lines*

---

### Add CI cleanup action and minor fixes

> [`87cdad9`](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433) · 2026-06-22

| File | Lines |
|------|-------|
| [`.github/actions/clear-files/action.yml`](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-830f1ea477991051e65282744aefc053ae6f915e576546c10124ad397bb5bb73R1-R12) | [+1-12](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-830f1ea477991051e65282744aefc053ae6f915e576546c10124ad397bb5bb73R1-R12) |
| [`doc/bitcoin-release-notes/release-notes-0.14.0.md`](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-1f17d7aee2cdb9a8b2d8ced12f3fabec2b8e569c1766f66b163614431a7b3ed6R152) | [+152](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-1f17d7aee2cdb9a8b2d8ced12f3fabec2b8e569c1766f66b163614431a7b3ed6R152) |
| [`doc/build-osx.md`](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-e9ba5bd8b63e72aa2d54d02960c9209823938981691cc8786ba323b54de0659cR224) | [+224](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-e9ba5bd8b63e72aa2d54d02960c9209823938981691cc8786ba323b54de0659cR224) |
| [`src/chainparamsseeds.h`](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-1e9d5194ca7ace278b7c721d5588d63830beffaef31ebe6165e6e092ca52d70eR1-R4) | [+1-4](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-1e9d5194ca7ace278b7c721d5588d63830beffaef31ebe6165e6e092ca52d70eR1-R4) |
| [`src/consensus/validation.h`](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-829bb21fff2a0d0648adb348a52928b2227f1cd05a54f44ce78d84091f8060d4R67) | [+67](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-829bb21fff2a0d0648adb348a52928b2227f1cd05a54f44ce78d84091f8060d4R67) |
| [`src/test/pow_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-b1cb474361180a29f16845ed882461d29a203cee4c1e5ea3dd74918e46060516R1752-R1753) | [+1752-1753](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-b1cb474361180a29f16845ed882461d29a203cee4c1e5ea3dd74918e46060516R1752-R1753) |
| [`test/functional/rpc_validateaddress.py`](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-a8c0d83fc9960faf7608a1922ad1c55c7a7c29d9d07c31288d8becc105923048R18-R22) | [+18-22, 48-52, 99-103](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-a8c0d83fc9960faf7608a1922ad1c55c7a7c29d9d07c31288d8becc105923048R18-R22) |
| [`test/functional/wallet_anchor.py`](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-619901a02fef1b7ecf7cd0a57fd58e7e468aacabf7d7249823cdc9c28fed1f95R7) | [+7](https://github.com/bitweb-project/bitweb/commit/87cdad90bf63b58a81e447420c82702cd6a82433#diff-619901a02fef1b7ecf7cd0a57fd58e7e468aacabf7d7249823cdc9c28fed1f95R7) |

*8 file(s) · ✏️ 7 modified · 🆕 1 new · +37 / -8 lines*

---

### Configure Docker action: use GHA cache only

> [`aeba01d`](https://github.com/bitweb-project/bitweb/commit/aeba01dcae93fab2a12e27fa72c00b98aa4f349b) · 2026-06-22

| File | Lines |
|------|-------|
| [`.github/actions/configure-docker/action.yml`](https://github.com/bitweb-project/bitweb/commit/aeba01dcae93fab2a12e27fa72c00b98aa4f349b#diff-fb343e432f60927181ab89952fb0df6f7a0067b0f65727f833efad19b88e5c46R26-R27) | [+26-27, 29-30](https://github.com/bitweb-project/bitweb/commit/aeba01dcae93fab2a12e27fa72c00b98aa4f349b#diff-fb343e432f60927181ab89952fb0df6f7a0067b0f65727f833efad19b88e5c46R26-R27) |

*1 file(s) · ✏️ 1 modified · +4 / -38 lines*

---

### Add checkpoint for height 65200 and update chainparams

> [`fa8c385`](https://github.com/bitweb-project/bitweb/commit/fa8c385c2f589e81636eff236082e52daf685a1f) · 2026-06-23

| File | Lines |
|------|-------|
| [`src/kernel/chainparams.cpp`](https://github.com/bitweb-project/bitweb/commit/fa8c385c2f589e81636eff236082e52daf685a1f#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR104) | [+104, 107, 124-125, 180, 191-196, 201-204, 233, 236, 335, 338, 490, 493, 563, 566](https://github.com/bitweb-project/bitweb/commit/fa8c385c2f589e81636eff236082e52daf685a1f#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR104) |

*1 file(s) · ✏️ 1 modified · +23 / -16 lines*

---

### Merge bitcoin fixes

> [`46d0390`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804) · 2026-06-24

| File | Lines |
|------|-------|
| [`CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR32) | [+32](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR32) |
| [`src/dbwrapper.cpp`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-44bef8fa93d168379ef331d9e11d333be06ce98a8f37ec65f8a987846b90a151R248) | [+248, 294-301, 305](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-44bef8fa93d168379ef331d9e11d333be06ce98a8f37ec65f8a987846b90a151R248) |
| [`src/dbwrapper.h`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-ac5fbeb5de6f28370bc348a579fc465fe7f7b91df0e0483c6edbf10273278c0dR267-R272) | [+267-272](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-ac5fbeb5de6f28370bc348a579fc465fe7f7b91df0e0483c6edbf10273278c0dR267-R272) |
| ~~`src/leveldb/.github/workflows/ci.yml`~~ | 🗑 deleted |
| [`src/leveldb/util/env_posix.cc`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-d43d9cd6b128f1b86c190bf0d923dae5aa47503918cf0cf0146f3c97f71da72fR45-R46) | [+45-46](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-d43d9cd6b128f1b86c190bf0d923dae5aa47503918cf0cf0146f3c97f71da72fR45-R46) |
| [`src/test/coins_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-3d0856e8b7f136c588b229e0cbd3b2e2c309cd097ade0879521daba4e1bb2a33R15) | [+15, 1064-1087](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-3d0856e8b7f136c588b229e0cbd3b2e2c309cd097ade0879521daba4e1bb2a33R15) |
| [`src/test/fuzz/deserialize.cpp`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-259675a17ed61244b5f1f5857285bdab63cc81f41334ed64c74ba623b61cf2a2R45) | [+45](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-259675a17ed61244b5f1f5857285bdab63cc81f41334ed64c74ba623b61cf2a2R45) |
| [`src/txdb.cpp`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-cafbe1353eff6084b73fd3b6c3dee603e0827348fdd2fe12dfad1e01003a84edR15) | [+15, 19, 21-22, 58-67, 73, 177-200](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-cafbe1353eff6084b73fd3b6c3dee603e0827348fdd2fe12dfad1e01003a84edR15) |
| [`src/txdb.h`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-d102b6032635ce90158c1e6e614f03b50e4449aa46ce23370da5387a658342fdR17) | [+17, 20, 44-45, 47, 50, 64, 68-73](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-d102b6032635ce90158c1e6e614f03b50e4449aa46ce23370da5387a658342fdR17) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R116-R122) | [+116-122, 2965-2977](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R116-R122) |
| [`src/wallet/test/fuzz/crypter.cpp`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-75cda45e65a08db48bd706b8b54bfe549eff0cacc7ee3f200a36fc2940dbf44bL14) | [-14, 18](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-75cda45e65a08db48bd706b8b54bfe549eff0cacc7ee3f200a36fc2940dbf44bL14) |
| [`test/lint/test_runner/src/main.rs`](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-36448d1553dbe13d812276cdd0b7d4e24a078a986bd0c9312972aab12d061cd0R213) | [+213](https://github.com/bitweb-project/bitweb/commit/46d03904e6aca365957269235e83af85dced7804#diff-36448d1553dbe13d812276cdd0b7d4e24a078a986bd0c9312972aab12d061cd0R213) |

*12 file(s) · ✏️ 11 modified · 🗑 1 deleted · +118 / -19 lines*

---

### Add Tree-SHA512 commit hook and update trusted keys

> [`78bd7e4`](https://github.com/bitweb-project/bitweb/commit/78bd7e42d328cc12b3640e513796af680bbb24e2) · 2026-06-24

| File | Lines |
|------|-------|
| [`contrib/verify-commits/prepare-commit-msg`](https://github.com/bitweb-project/bitweb/commit/78bd7e42d328cc12b3640e513796af680bbb24e2#diff-133d903848119e7ec8c349badc63858022b45647d6f964da002da64aa7277ed9R1-R58) | [+1-58](https://github.com/bitweb-project/bitweb/commit/78bd7e42d328cc12b3640e513796af680bbb24e2#diff-133d903848119e7ec8c349badc63858022b45647d6f964da002da64aa7277ed9R1-R58) |
| [`contrib/verify-commits/trusted-git-root`](https://github.com/bitweb-project/bitweb/commit/78bd7e42d328cc12b3640e513796af680bbb24e2#diff-67032a25afe299c548ba84b7e8225dbb51359ccc75d199c7ff8a76eac7a8daa1R1) | [+1](https://github.com/bitweb-project/bitweb/commit/78bd7e42d328cc12b3640e513796af680bbb24e2#diff-67032a25afe299c548ba84b7e8225dbb51359ccc75d199c7ff8a76eac7a8daa1R1) |
| [`contrib/verify-commits/trusted-keys`](https://github.com/bitweb-project/bitweb/commit/78bd7e42d328cc12b3640e513796af680bbb24e2#diff-2e5b3785a40a6b771f84e9579774e55bc50db0b1ce13927df8f313b76a1c99eaR1) | [+1](https://github.com/bitweb-project/bitweb/commit/78bd7e42d328cc12b3640e513796af680bbb24e2#diff-2e5b3785a40a6b771f84e9579774e55bc50db0b1ce13927df8f313b76a1c99eaR1) |
| [`contrib/verify-commits/trusted-sha512-root-commit`](https://github.com/bitweb-project/bitweb/commit/78bd7e42d328cc12b3640e513796af680bbb24e2#diff-76bd7f3732eb3027cb667e3ba9b3e7c42561424e8cb382f000e2e2064f92b2adR1) | [+1](https://github.com/bitweb-project/bitweb/commit/78bd7e42d328cc12b3640e513796af680bbb24e2#diff-76bd7f3732eb3027cb667e3ba9b3e7c42561424e8cb382f000e2e2064f92b2adR1) |

*4 file(s) · ✏️ 3 modified · 🆕 1 new · +61 / -7 lines*

---

### fix mac os build and ad-hoc codesign.

> [`7200ea7`](https://github.com/bitweb-project/bitweb/commit/7200ea78fe513385d398e3d66b1a038b349536cd) · 2026-06-25

| File | Lines |
|------|-------|
| [`contrib/guix/libexec/build.sh`](https://github.com/bitweb-project/bitweb/commit/7200ea78fe513385d398e3d66b1a038b349536cd#diff-b5a81ce4722af8d7ce7cdcedc96e08289c8b5ca680fa5d032feb5f3e5f3e109fR265-R268) | [+265-268](https://github.com/bitweb-project/bitweb/commit/7200ea78fe513385d398e3d66b1a038b349536cd#diff-b5a81ce4722af8d7ce7cdcedc96e08289c8b5ca680fa5d032feb5f3e5f3e109fR265-R268) |
| [`depends/hosts/darwin.mk`](https://github.com/bitweb-project/bitweb/commit/7200ea78fe513385d398e3d66b1a038b349536cd#diff-964a007db35da98be548991cbc8815cc400d698508eb4b203921254e5c1bf8baR70) | [+70, 82](https://github.com/bitweb-project/bitweb/commit/7200ea78fe513385d398e3d66b1a038b349536cd#diff-964a007db35da98be548991cbc8815cc400d698508eb4b203921254e5c1bf8baR70) |

*2 file(s) · ✏️ 2 modified · +6 / -2 lines*

---

### guix: fix llvm-strip '-u' error during macOS deploy

> [`3efcdfc`](https://github.com/bitweb-project/bitweb/commit/3efcdfc3366753e4a63f8f2bd4a2c662aecfd90b) · 2026-06-25

| File | Lines |
|------|-------|
| [`contrib/guix/libexec/build.sh`](https://github.com/bitweb-project/bitweb/commit/3efcdfc3366753e4a63f8f2bd4a2c662aecfd90b#diff-b5a81ce4722af8d7ce7cdcedc96e08289c8b5ca680fa5d032feb5f3e5f3e109fR266-R267) | [+266-267](https://github.com/bitweb-project/bitweb/commit/3efcdfc3366753e4a63f8f2bd4a2c662aecfd90b#diff-b5a81ce4722af8d7ce7cdcedc96e08289c8b5ca680fa5d032feb5f3e5f3e109fR266-R267) |

*1 file(s) · ✏️ 1 modified · +2 / -0 lines*

---

### Regenerate man's and bitweb.conf example

> [`fb8df52`](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95) · 2026-06-25

| File | Lines |
|------|-------|
| [`doc/man/bitweb-cli.1`](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-4a1e4af5cfba081018dc40300038923476f40d372540035ae5dac45606c568b6R2) | [+2, 4, 18](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-4a1e4af5cfba081018dc40300038923476f40d372540035ae5dac45606c568b6R2) |
| [`doc/man/bitweb-qt.1`](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-beb107ff531f83f460e550782ab61e94fd03831000fbfc59dbed59854aab4395R2) | [+2, 4, 9, 35, 102-104, 205-209, 226-229, 293, 308-310, 505-506, 595-599, 615, 713-719, 742-743](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-beb107ff531f83f460e550782ab61e94fd03831000fbfc59dbed59854aab4395R2) |
| [`doc/man/bitweb-tx.1`](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-4fa9b0871a18eed1236347afa0d2f0956e835e94d93d9967a3677ea5d18e5a70R2) | [+2, 4, 12](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-4fa9b0871a18eed1236347afa0d2f0956e835e94d93d9967a3677ea5d18e5a70R2) |
| [`doc/man/bitweb-util.1`](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-4bcb5d66f64dc5d368305afad8d63c9a4479c77ca0be32911291fd2e6ea13e2aR2) | [+2, 4, 12](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-4bcb5d66f64dc5d368305afad8d63c9a4479c77ca0be32911291fd2e6ea13e2aR2) |
| [`doc/man/bitweb-wallet.1`](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-c3dccf612b58c78bb9b9abfacbd8f2442733c6ac33c2893657dcd6ebde7ac29bR2) | [+2, 4, 9](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-c3dccf612b58c78bb9b9abfacbd8f2442733c6ac33c2893657dcd6ebde7ac29bR2) |
| [`doc/man/bitweb.1`](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-71c2fd6f489d08b65cb4a5d45152b276a025b7d60bb7176d67aeadf04b2ec941R2) | [+2, 4](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-71c2fd6f489d08b65cb4a5d45152b276a025b7d60bb7176d67aeadf04b2ec941R2) |
| [`doc/man/bitwebd.1`](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-bf91955718ae74b2183c2e8c8bf7d003daa1d2dd6e96d16671abf8ccb3a11744R2) | [+2, 4, 9, 35, 102-104, 205-209, 226-229, 293, 308-310, 505-506, 595-599, 615, 713-719, 742-743](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-bf91955718ae74b2183c2e8c8bf7d003daa1d2dd6e96d16671abf8ccb3a11744R2) |
| [`share/examples/bitweb.conf`](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R26) | [+26, 28, 30, 32, 81-83, 165-168, 183-186, 238, 250-252, 394, 417-418, 495-499, 509, 593-598, 618-619](https://github.com/bitweb-project/bitweb/commit/fb8df52bb0fba6127a47255c8b44c13f3938df95#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R26) |

*8 file(s) · ✏️ 8 modified · +124 / -109 lines*

---

### cmake: fix macOS deploy zip name to match guix build script

> [`a93f14a`](https://github.com/bitweb-project/bitweb/commit/a93f14ab5cc0bba7e7179d03ba676f903f2df85f) · 2026-06-25

| File | Lines |
|------|-------|
| [`ci/test/03_test_script.sh`](https://github.com/bitweb-project/bitweb/commit/a93f14ab5cc0bba7e7179d03ba676f903f2df85f#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR169) | [+169](https://github.com/bitweb-project/bitweb/commit/a93f14ab5cc0bba7e7179d03ba676f903f2df85f#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR169) |
| [`cmake/module/Maintenance.cmake`](https://github.com/bitweb-project/bitweb/commit/a93f14ab5cc0bba7e7179d03ba676f903f2df85f#diff-4ddf0f892dff9d07bedff9d35a6a49720007417fe02a8ece7fc90fcb74df66fcR99) | [+99, 102-103, 108, 111, 116, 131, 133, 137](https://github.com/bitweb-project/bitweb/commit/a93f14ab5cc0bba7e7179d03ba676f903f2df85f#diff-4ddf0f892dff9d07bedff9d35a6a49720007417fe02a8ece7fc90fcb74df66fcR99) |

*2 file(s) · ✏️ 2 modified · +10 / -10 lines*

---

Credits
=======

Thanks to everyone who directly contributed to this release:

- mraksoll4

Bitweb Core is based on Bitcoin Core.
Original Bitcoin Core developers:
  <https://github.com/bitcoin/bitcoin/graphs/contributors>
