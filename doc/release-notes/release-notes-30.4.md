Bitweb Core version v30.4 Release Notes
=======================================

Bitweb Core version v30.4 is now available from:

  <https://github.com/bitweb-project/bitweb/releases/tag/v30.4>

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

### Add Bitweb Release noted 30.3.1

> [`0dd1369`](https://github.com/bitweb-project/bitweb/commit/0dd136924cd8b183d22194d1c2b63ed27d325e7c) · 2026-06-25

| File | Lines |
|------|-------|
| [`doc/release-notes.md`](https://github.com/bitweb-project/bitweb/commit/0dd136924cd8b183d22194d1c2b63ed27d325e7c#diff-e04cb1e9f29f76897c6b84334238f621ff45ba13cf180ad1d0d442d50ebe51f7R1-R2) | [+1-2, 4, 6, 8, 59, 61, 65-67, 71, 73, 77, 79, 83, 85, 89-91, 95, 97, 101-104, 108, 110, 114-116, 120, 122, 126-147, 151, 153, 157-159, 163, 165, 169-178, 182, 184, 188-190, 194, 196, 200, 202, 206, 208, 212-225, 229, 231, 235-240, 244, 246, 250-251, 253, 257, 259, 263, 265, 269, 271, 275-282, 284, 288, 290, 294-297](https://github.com/bitweb-project/bitweb/commit/0dd136924cd8b183d22194d1c2b63ed27d325e7c#diff-e04cb1e9f29f76897c6b84334238f621ff45ba13cf180ad1d0d442d50ebe51f7R1-R2) |
| [`doc/release-notes/release-notes-30.3.1.md`](https://github.com/bitweb-project/bitweb/commit/0dd136924cd8b183d22194d1c2b63ed27d325e7c#diff-32dbb8cbc0763cf72e340d8cd011b16d1dca6f50ea9d18c2bfa74bdbca4f2474R1-R310) | [+1-310](https://github.com/bitweb-project/bitweb/commit/0dd136924cd8b183d22194d1c2b63ed27d325e7c#diff-32dbb8cbc0763cf72e340d8cd011b16d1dca6f50ea9d18c2bfa74bdbca4f2474R1-R310) |

*2 file(s) · ✏️ 1 modified · 🆕 1 new · +440 / -919 lines*

---

### Update address formats to BitWeb

> [`84dff1f`](https://github.com/bitweb-project/bitweb/commit/84dff1f85b04e7ae4391a24b93ad7eeb33b180a9) · 2026-06-27

| File | Lines |
|------|-------|
| [`src/qt/forms/receiverequestdialog.ui`](https://github.com/bitweb-project/bitweb/commit/84dff1f85b04e7ae4391a24b93ad7eeb33b180a9#diff-922feaa8d4fa6c0e3e860ed79ae9b454be10bb1bf98226e09b1079da17b84b19R100) | [+100](https://github.com/bitweb-project/bitweb/commit/84dff1f85b04e7ae4391a24b93ad7eeb33b180a9#diff-922feaa8d4fa6c0e3e860ed79ae9b454be10bb1bf98226e09b1079da17b84b19R100) |
| [`src/qt/guiutil.cpp`](https://github.com/bitweb-project/bitweb/commit/84dff1f85b04e7ae4391a24b93ad7eeb33b180a9#diff-f2c7d602216ecc4b5d3980a81ebc57d56fb77ff0af5dd5dccdc3c06dba0a9ba6R114) | [+114](https://github.com/bitweb-project/bitweb/commit/84dff1f85b04e7ae4391a24b93ad7eeb33b180a9#diff-f2c7d602216ecc4b5d3980a81ebc57d56fb77ff0af5dd5dccdc3c06dba0a9ba6R114) |

*2 file(s) · ✏️ 2 modified · +2 / -2 lines*

---

### Update qrencode download source to GitHub mirror

> [`afa3ca9`](https://github.com/bitweb-project/bitweb/commit/afa3ca90ab8cdaa3569f077df243bf0f2506519f) · 2026-06-27

| File | Lines |
|------|-------|
| [`depends/packages/qrencode.mk`](https://github.com/bitweb-project/bitweb/commit/afa3ca90ab8cdaa3569f077df243bf0f2506519f#diff-f2215c893b0f7d9d6b790a04afcd5e3887c46ce2d774b60db65fe0c17caf0dcdR3) | [+3](https://github.com/bitweb-project/bitweb/commit/afa3ca90ab8cdaa3569f077df243bf0f2506519f#diff-f2215c893b0f7d9d6b790a04afcd5e3887c46ce2d774b60db65fe0c17caf0dcdR3) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### Increase CI timeout values

> [`39b796c`](https://github.com/bitweb-project/bitweb/commit/39b796c2c35631020ebf9a3d5ad0ab642931756d) · 2026-06-28

| File | Lines |
|------|-------|
| [`.github/workflows/ci.yml`](https://github.com/bitweb-project/bitweb/commit/39b796c2c35631020ebf9a3d5ad0ab642931756d#diff-b803fcb7f17ed9235f1e5cb1fcd2f5d3b2838429d4368ae4c57ce4436577f03fR120) | [+120, 201, 384, 473, 486, 492, 498, 510, 516, 522, 528, 574](https://github.com/bitweb-project/bitweb/commit/39b796c2c35631020ebf9a3d5ad0ab642931756d#diff-b803fcb7f17ed9235f1e5cb1fcd2f5d3b2838429d4368ae4c57ce4436577f03fR120) |
| [`ci/test/00_setup_env.sh`](https://github.com/bitweb-project/bitweb/commit/39b796c2c35631020ebf9a3d5ad0ab642931756d#diff-2129087e5fb708bbdcb59673b7fc336d48a9473a11802be991231e993c12b7d4R48) | [+48](https://github.com/bitweb-project/bitweb/commit/39b796c2c35631020ebf9a3d5ad0ab642931756d#diff-2129087e5fb708bbdcb59673b7fc336d48a9473a11802be991231e993c12b7d4R48) |
| [`ci/test/00_setup_env_native_msan.sh`](https://github.com/bitweb-project/bitweb/commit/39b796c2c35631020ebf9a3d5ad0ab642931756d#diff-532397784bcebab79ab7f8f75f0ce51d6bcf459ec2c0fcb75b618e3f0f223592R32) | [+32](https://github.com/bitweb-project/bitweb/commit/39b796c2c35631020ebf9a3d5ad0ab642931756d#diff-532397784bcebab79ab7f8f75f0ce51d6bcf459ec2c0fcb75b618e3f0f223592R32) |
| [`ci/test/03_test_script.sh`](https://github.com/bitweb-project/bitweb/commit/39b796c2c35631020ebf9a3d5ad0ab642931756d#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR183) | [+183](https://github.com/bitweb-project/bitweb/commit/39b796c2c35631020ebf9a3d5ad0ab642931756d#diff-028c14f389228331dc3d0f95a570e19f06cf17112556a164109a51609c3a4c2dR183) |

*4 file(s) · ✏️ 4 modified · +15 / -15 lines*

---

### Update security report link in bug template

> [`dae5b18`](https://github.com/bitweb-project/bitweb/commit/dae5b18df879b0283c470512d95b85a37cf94640) · 2026-06-28

| File | Lines |
|------|-------|
| [`.github/ISSUE_TEMPLATE/bug.yml`](https://github.com/bitweb-project/bitweb/commit/dae5b18df879b0283c470512d95b85a37cf94640#diff-45b5634e925b86895feee745ec5650893bae0d56e11b379745e506fd9a6b81bdR11) | [+11](https://github.com/bitweb-project/bitweb/commit/dae5b18df879b0283c470512d95b85a37cf94640#diff-45b5634e925b86895feee745ec5650893bae0d56e11b379745e506fd9a6b81bdR11) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### Update release announcement URL

> [`043b55b`](https://github.com/bitweb-project/bitweb/commit/043b55b55bc7992a0749ec6528bdc84e49452a39) · 2026-06-28

| File | Lines |
|------|-------|
| [`doc/release-process.md`](https://github.com/bitweb-project/bitweb/commit/043b55b55bc7992a0749ec6528bdc84e49452a39#diff-723b9eeeb819047ef03f827ee8a3ccfef48ce7ef6a340a068a68b551993fe70bR206) | [+206](https://github.com/bitweb-project/bitweb/commit/043b55b55bc7992a0749ec6528bdc84e49452a39#diff-723b9eeeb819047ef03f827ee8a3ccfef48ce7ef6a340a068a68b551993fe70bR206) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### fix default HRP to web

> [`64d425a`](https://github.com/bitweb-project/bitweb/commit/64d425a6fa384c8128b0f0d8576387b99cda6f2c) · 2026-06-28

| File | Lines |
|------|-------|
| [`contrib/testgen/README.md`](https://github.com/bitweb-project/bitweb/commit/64d425a6fa384c8128b0f0d8576387b99cda6f2c#diff-d8df83d12b208f8ce8ab14593be760c0713da0795c1d2a3bc40ac263f1cf2039R18) | [+18, 23](https://github.com/bitweb-project/bitweb/commit/64d425a6fa384c8128b0f0d8576387b99cda6f2c#diff-d8df83d12b208f8ce8ab14593be760c0713da0795c1d2a3bc40ac263f1cf2039R18) |
| [`contrib/testgen/gen_validateaddress_vectors.py`](https://github.com/bitweb-project/bitweb/commit/64d425a6fa384c8128b0f0d8576387b99cda6f2c#diff-79ee210143bb88501460cca7424eca4ff3b786303400d7a964210115cff99b2dR10) | [+10, 14, 77](https://github.com/bitweb-project/bitweb/commit/64d425a6fa384c8128b0f0d8576387b99cda6f2c#diff-79ee210143bb88501460cca7424eca4ff3b786303400d7a964210115cff99b2dR10) |

*2 file(s) · ✏️ 2 modified · +5 / -5 lines*

---

### Update example addresses in signmessage RPC help

> [`314582d`](https://github.com/bitweb-project/bitweb/commit/314582d2d15a5080e7b4347d7baccad6d2dee093) · 2026-06-29

| File | Lines |
|------|-------|
| [`src/rpc/signmessage.cpp`](https://github.com/bitweb-project/bitweb/commit/314582d2d15a5080e7b4347d7baccad6d2dee093#diff-5919c1cbf46eb27881c22816a1d4e8285140b8cf4762d60376f8822528c3a09cR33) | [+33, 35, 37, 80](https://github.com/bitweb-project/bitweb/commit/314582d2d15a5080e7b4347d7baccad6d2dee093#diff-5919c1cbf46eb27881c22816a1d4e8285140b8cf4762d60376f8822528c3a09cR33) |
| [`src/wallet/rpc/signmessage.cpp`](https://github.com/bitweb-project/bitweb/commit/314582d2d15a5080e7b4347d7baccad6d2dee093#diff-d8414081a519d180f5b945fea0fe88bf77e5955d648fcda4e7cf6ab2f763515eR31) | [+31, 33, 35](https://github.com/bitweb-project/bitweb/commit/314582d2d15a5080e7b4347d7baccad6d2dee093#diff-d8414081a519d180f5b945fea0fe88bf77e5955d648fcda4e7cf6ab2f763515eR31) |

*2 file(s) · ✏️ 2 modified · +7 / -7 lines*

---

### Fix Taproot deployment on mainnet

> [`2a413f0`](https://github.com/bitweb-project/bitweb/commit/2a413f0da58de1679e615fc7ea460e9fa5a23c90) · 2026-06-29

| File | Lines |
|------|-------|
| [`src/kernel/chainparams.cpp`](https://github.com/bitweb-project/bitweb/commit/2a413f0da58de1679e615fc7ea460e9fa5a23c90#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR118) | [+118, 247](https://github.com/bitweb-project/bitweb/commit/2a413f0da58de1679e615fc7ea460e9fa5a23c90#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR118) |

*1 file(s) · ✏️ 1 modified · +2 / -2 lines*

---

### Add header PoW verification cache (pow_cache)

> [`5f8cbf1`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62) · 2026-07-05

| File | Lines |
|------|-------|
| [`src/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-148715d6ea0c0ea0a346af3f6bd610d010d490eca35ac6a9b408748f7ca9e3f4R127) | [+127](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-148715d6ea0c0ea0a346af3f6bd610d010d490eca35ac6a9b408748f7ca9e3f4R127) |
| [`src/init.cpp`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-b1e19192258d83199d8adaa5ac31f067af98f63554bfdd679bd8e8073815e69dR65) | [+65, 502-504, 1278-1285](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-b1e19192258d83199d8adaa5ac31f067af98f63554bfdd679bd8e8073815e69dR65) |
| [`src/kernel/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-833a13a4d795b3e5e25ccc9bfc3f62b8639cf21ef66d028499bf9bb26a65387aR46) | [+46](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-833a13a4d795b3e5e25ccc9bfc3f62b8639cf21ef66d028499bf9bb26a65387aR46) |
| [`src/kernel/chainstatemanager_opts.h`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-72bfc3c331430d65bff7edb3e7fe4c622e1eac412a84e378f58c8d40e33f1824R12) | [+12, 54-59](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-72bfc3c331430d65bff7edb3e7fe4c622e1eac412a84e378f58c8d40e33f1824R12) |
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3L2886-L2910) | [-2886-2910, 2989-2999](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3L2886-L2910) |
| [`src/node/blockstorage.cpp`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR19) | [+19, 1049-1054](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR19) |
| [`src/node/chainstatemanager_args.cpp`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-810d8474f5c6aeb8f854258e357a32f5d60cc38c12327745648bc6d979cff63eR74-R83) | [+74-83](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-810d8474f5c6aeb8f854258e357a32f5d60cc38c12327745648bc6d979cff63eR74-R83) |
| [`src/pow_cache.cpp`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-61cd82042cb3c4237cadc306df26b7a24f2161477a242661b30988ba95ed378fR1-R39) | [+1-39](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-61cd82042cb3c4237cadc306df26b7a24f2161477a242661b30988ba95ed378fR1-R39) |
| [`src/pow_cache.h`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-75b762488a3922139a476445631fb7ce25a22daa6a2835de53d9842e78874339R1-R182) | [+1-182](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-75b762488a3922139a476445631fb7ce25a22daa6a2835de53d9842e78874339R1-R182) |
| [`src/test/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-921b2054f6bf380eb08d5c3c21cf8d1c7cfee3736227d611400ae1a13ab3d187R80) | [+80](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-921b2054f6bf380eb08d5c3c21cf8d1c7cfee3736227d611400ae1a13ab3d187R80) |
| [`src/test/fuzz/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-b937c829d4a0cf9a653f5361656ea8196b6ecef40fd033aa41a6da945e987bcdR94-R95) | [+94-95](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-b937c829d4a0cf9a653f5361656ea8196b6ecef40fd033aa41a6da945e987bcdR94-R95) |
| [`src/test/fuzz/pow_cache.cpp`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-5f2f56e12902d67139e63bba525063c7476324c4f0b3e5a93d12aa9e79744cb9R1-R83) | [+1-83](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-5f2f56e12902d67139e63bba525063c7476324c4f0b3e5a93d12aa9e79744cb9R1-R83) |
| [`src/test/fuzz/pow_cache_check.cpp`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-21e326ea4bd9439f8532024d2c106e7fb33fa180f3625b4d9fe0b6ff59417858R1-R99) | [+1-99](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-21e326ea4bd9439f8532024d2c106e7fb33fa180f3625b4d9fe0b6ff59417858R1-R99) |
| [`src/test/pow_cache_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-98c7d65736a2775597ff0ec57343e3c59c37f0f3c6bf7eb5bbddfb5c56aa3b04R1-R304) | [+1-304](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-98c7d65736a2775597ff0ec57343e3c59c37f0f3c6bf7eb5bbddfb5c56aa3b04R1-R304) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R41) | [+41, 77, 3996-4005, 4009-4011, 4013, 4207-4238, 4241-4257](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R41) |
| [`src/validation.h`](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR415-R455) | [+415-455](https://github.com/bitweb-project/bitweb/commit/5f8cbf19baf67c1661f4d8181525e8eb75f41f62#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR415-R455) |

*16 file(s) · ✏️ 11 modified · 🆕 5 new · +854 / -43 lines*

---

### Backport net assert-crash + m_blocks_unlinked UB fixes from bitcoin/bitcoin

> [`7d2773c`](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac) · 2026-07-05

| File | Lines |
|------|-------|
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R1847-R1856) | [+1847-1856](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R1847-R1856) |
| [`src/node/blockstorage.cpp`](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR253-R266) | [+253-266, 487-491](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-114c2880ec1ff2c5293ac65ceda0637bf92c05745b74b58410585a549464a33fR253-R266) |
| [`src/node/blockstorage.h`](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-ed3f90693a242b38b9719af171de8f55183576957676dfa358945bea22276bd5R299-R303) | [+299-303](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-ed3f90693a242b38b9719af171de8f55183576957676dfa358945bea22276bd5R299-R303) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R3331-R3337) | [+3331-3337, 3996-3998, 5579-5582, 5585-5588](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R3331-R3337) |
| [`test/functional/feature_pruning.py`](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-f15bffeef80285cc29f5d73fc6c0b4e0df7f967a36ffdecf41b123b113cc3af4R214-R261) | [+214-261, 358-366, 381, 391-402](https://github.com/bitweb-project/bitweb/commit/7d2773cc1e0470b3b21ca34f868c087a357df4ac#diff-f15bffeef80285cc29f5d73fc6c0b4e0df7f967a36ffdecf41b123b113cc3af4R214-R261) |

*5 file(s) · ✏️ 5 modified · +122 / -17 lines*

---

### Fix typos and Doxygen comment formatting

> [`2f8ff99`](https://github.com/bitweb-project/bitweb/commit/2f8ff99e4faedd2d9b76b6db3db18319d22b0fa5) · 2026-07-05

| File | Lines |
|------|-------|
| [`src/index/coinstatsindex.cpp`](https://github.com/bitweb-project/bitweb/commit/2f8ff99e4faedd2d9b76b6db3db18319d22b0fa5#diff-f1b8261031c7f062025f97106824d80601e5247ba0b68ffe608285eeaecceed2R154) | [+154, 428](https://github.com/bitweb-project/bitweb/commit/2f8ff99e4faedd2d9b76b6db3db18319d22b0fa5#diff-f1b8261031c7f062025f97106824d80601e5247ba0b68ffe608285eeaecceed2R154) |
| [`src/rpc/blockchain.cpp`](https://github.com/bitweb-project/bitweb/commit/2f8ff99e4faedd2d9b76b6db3db18319d22b0fa5#diff-decae4be02fb8a47ab4557fe74a9cb853bdfa3ec0fa1b515c0a1e5de91f4ad0bR2061) | [+2061](https://github.com/bitweb-project/bitweb/commit/2f8ff99e4faedd2d9b76b6db3db18319d22b0fa5#diff-decae4be02fb8a47ab4557fe74a9cb853bdfa3ec0fa1b515c0a1e5de91f4ad0bR2061) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/2f8ff99e4faedd2d9b76b6db3db18319d22b0fa5#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R2325) | [+2325, 2337, 2351, 2531, 2561, 2600, 6480](https://github.com/bitweb-project/bitweb/commit/2f8ff99e4faedd2d9b76b6db3db18319d22b0fa5#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R2325) |
| [`src/validation.h`](https://github.com/bitweb-project/bitweb/commit/2f8ff99e4faedd2d9b76b6db3db18319d22b0fa5#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR129-R132) | [+129-132, 1404, 1411](https://github.com/bitweb-project/bitweb/commit/2f8ff99e4faedd2d9b76b6db3db18319d22b0fa5#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR129-R132) |

*4 file(s) · ✏️ 4 modified · +16 / -16 lines*

---

### Backport: BIP152 sendcmpct validation, mempool package cleanup

> [`d1aed80`](https://github.com/bitweb-project/bitweb/commit/d1aed805750054bdfd7d7cea0659235f42b31581) · 2026-07-06

| File | Lines |
|------|-------|
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/d1aed805750054bdfd7d7cea0659235f42b31581#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R3730-R3734) | [+3730-3734, 3738-3744](https://github.com/bitweb-project/bitweb/commit/d1aed805750054bdfd7d7cea0659235f42b31581#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R3730-R3734) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/d1aed805750054bdfd7d7cea0659235f42b31581#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R1419-R1428) | [+1419-1428](https://github.com/bitweb-project/bitweb/commit/d1aed805750054bdfd7d7cea0659235f42b31581#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R1419-R1428) |
| [`test/functional/p2p_compactblocks.py`](https://github.com/bitweb-project/bitweb/commit/d1aed805750054bdfd7d7cea0659235f42b31581#diff-3d0d1b84c608319965e0c2675eefadc6820103793bf5a9d671562bc24dcbc3eaR266-R277) | [+266-277, 1034-1036](https://github.com/bitweb-project/bitweb/commit/d1aed805750054bdfd7d7cea0659235f42b31581#diff-3d0d1b84c608319965e0c2675eefadc6820103793bf5a9d671562bc24dcbc3eaR266-R277) |

*3 file(s) · ✏️ 3 modified · +37 / -2 lines*

---

### Use Argon2id PoW hash in tests

> [`1ac0255`](https://github.com/bitweb-project/bitweb/commit/1ac0255e20287d140118c33178ca493f34d8ddfa) · 2026-07-07

| File | Lines |
|------|-------|
| [`src/test/miner_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/1ac0255e20287d140118c33178ca493f34d8ddfa#diff-b12066a688b85bea440eb38f079fb8ecc1984318470631bca7e3547a98effaa9R742) | [+742](https://github.com/bitweb-project/bitweb/commit/1ac0255e20287d140118c33178ca493f34d8ddfa#diff-b12066a688b85bea440eb38f079fb8ecc1984318470631bca7e3547a98effaa9R742) |

*1 file(s) · ✏️ 1 modified · +1 / -1 lines*

---

### Move header PoW check queue into ChainstateManager

> [`172711d`](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704) · 2026-07-07

| File | Lines |
|------|-------|
| [`src/net_processing.cpp`](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R2494-R2495) | [+2494-2495](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-6875de769e90cec84d2e8a9c1b962cdbcda44d870d42e4215827e599e11e90e3R2494-R2495) |
| [`src/test/CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-921b2054f6bf380eb08d5c3c21cf8d1c7cfee3736227d611400ae1a13ab3d187R50) | [+50](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-921b2054f6bf380eb08d5c3c21cf8d1c7cfee3736227d611400ae1a13ab3d187R50) |
| [`src/test/header_pow_queue_tests.cpp`](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-5313ba7db8cc3abc746441e256396eaaf4fb9393993ffda0e575f50a106e5715R1-R343) | [+1-343](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-5313ba7db8cc3abc746441e256396eaaf4fb9393993ffda0e575f50a106e5715R1-R343) |
| [`src/validation.cpp`](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R4232-R4240) | [+4232-4240, 4244, 4247, 4258, 6432](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-97c3a52bc5fad452d82670a7fd291800bae20c7bc35bb82686c2c0a4ea7b5b98R4232-R4240) |
| [`src/validation.h`](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR451-R455) | [+451-455, 1025-1034, 1393-1400](https://github.com/bitweb-project/bitweb/commit/172711de87fb7b00b94151da2e269a3ba07fc704#diff-d3c243938494b10666b44404a27af7d84b44a72b85a27431e0c89e181462ca6eR451-R455) |

*5 file(s) · ✏️ 4 modified · 🆕 1 new · +382 / -24 lines*

---

### build: bump version to v30.4

> [`7f054ef`](https://github.com/bitweb-project/bitweb/commit/7f054ef5c43f1cbcfc3c2fd32b9782a488de35be) · 2026-07-07

| File | Lines |
|------|-------|
| [`CMakeLists.txt`](https://github.com/bitweb-project/bitweb/commit/7f054ef5c43f1cbcfc3c2fd32b9782a488de35be#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR31-R32) | [+31-32](https://github.com/bitweb-project/bitweb/commit/7f054ef5c43f1cbcfc3c2fd32b9782a488de35be#diff-1e7de1ae2d059d21e1dd75d5812d5a34b0222cef273b7c3a2af62eb747f9d20aR31-R32) |

*1 file(s) · ✏️ 1 modified · +2 / -2 lines*

---

### Update mainnet chainparams for block 69000

> [`0a044c9`](https://github.com/bitweb-project/bitweb/commit/0a044c9c8b03bab28a8f7f9ee5f14ebe9eb854f6) · 2026-07-07

| File | Lines |
|------|-------|
| [`src/kernel/chainparams.cpp`](https://github.com/bitweb-project/bitweb/commit/0a044c9c8b03bab28a8f7f9ee5f14ebe9eb854f6#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR124-R125) | [+124-125, 181, 198-203, 208-211](https://github.com/bitweb-project/bitweb/commit/0a044c9c8b03bab28a8f7f9ee5f14ebe9eb854f6#diff-e20339c384d6f19b519ea2de7f4ba4fed92a36d66a80f0339b09927c3fa38d6dR124-R125) |

*1 file(s) · ✏️ 1 modified · +13 / -6 lines*

---

### doc: update manual pages and bitweb.conf example for v30.4

> [`aa3da85`](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4) · 2026-07-07

| File | Lines |
|------|-------|
| [`doc/man/bitweb-cli.1`](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-4a1e4af5cfba081018dc40300038923476f40d372540035ae5dac45606c568b6R2) | [+2, 4, 18](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-4a1e4af5cfba081018dc40300038923476f40d372540035ae5dac45606c568b6R2) |
| [`doc/man/bitweb-qt.1`](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-beb107ff531f83f460e550782ab61e94fd03831000fbfc59dbed59854aab4395R2) | [+2, 4, 9, 35, 102-104, 112-120, 138-141, 234-236, 300-301, 316, 501-505, 516-517, 606-610, 626, 746-747](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-beb107ff531f83f460e550782ab61e94fd03831000fbfc59dbed59854aab4395R2) |
| [`doc/man/bitweb-tx.1`](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-4fa9b0871a18eed1236347afa0d2f0956e835e94d93d9967a3677ea5d18e5a70R2) | [+2, 4, 12](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-4fa9b0871a18eed1236347afa0d2f0956e835e94d93d9967a3677ea5d18e5a70R2) |
| [`doc/man/bitweb-util.1`](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-4bcb5d66f64dc5d368305afad8d63c9a4479c77ca0be32911291fd2e6ea13e2aR2) | [+2, 4, 12](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-4bcb5d66f64dc5d368305afad8d63c9a4479c77ca0be32911291fd2e6ea13e2aR2) |
| [`doc/man/bitweb-wallet.1`](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-c3dccf612b58c78bb9b9abfacbd8f2442733c6ac33c2893657dcd6ebde7ac29bR2) | [+2, 4, 9](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-c3dccf612b58c78bb9b9abfacbd8f2442733c6ac33c2893657dcd6ebde7ac29bR2) |
| [`doc/man/bitweb.1`](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-71c2fd6f489d08b65cb4a5d45152b276a025b7d60bb7176d67aeadf04b2ec941R2) | [+2, 4](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-71c2fd6f489d08b65cb4a5d45152b276a025b7d60bb7176d67aeadf04b2ec941R2) |
| [`doc/man/bitwebd.1`](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-bf91955718ae74b2183c2e8c8bf7d003daa1d2dd6e96d16671abf8ccb3a11744R2) | [+2, 4, 9, 35, 102-104, 112-120, 138-141, 234-236, 300-301, 316, 501-505, 516-517, 606-610, 626, 746-747](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-bf91955718ae74b2183c2e8c8bf7d003daa1d2dd6e96d16671abf8ccb3a11744R2) |
| [`share/examples/bitweb.conf`](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R26) | [+26, 81-83, 91-98, 109-111, 190-192, 244-245, 257, 416-419, 426-427, 504-508, 518, 621-622](https://github.com/bitweb-project/bitweb/commit/aa3da851d8257d418285c4874719e9cab76357c4#diff-ed60f23362b78cf8917d765a5d66706af8c46d6cc1cf7261e1d81161d1c97af6R26) |

*8 file(s) · ✏️ 8 modified · +131 / -120 lines*

---

Credits
=======

Thanks to everyone who directly contributed to this release:

- mraksoll4

Bitweb Core is based on Bitcoin Core.
Original Bitcoin Core developers:
  <https://github.com/bitcoin/bitcoin/graphs/contributors>
