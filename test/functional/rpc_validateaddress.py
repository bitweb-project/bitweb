#!/usr/bin/env python3
# Copyright (c) 2023 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test validateaddress for main chain"""

from test_framework.test_framework import BitcoinTestFramework

from test_framework.util import assert_equal

INVALID_DATA = [
    # BIP 173
    (
        "tc1qw508d6qejxtdg4y5r3zarvary0c5xw7kg3g4ty",
        "Invalid or unsupported Segwit (Bech32) or Base58 encoding.",  # Invalid hrp
        [],
    ),
    ("web1qw508d6qejxtdg4y5r3zarvary0c5xw7k5rwwqg", "Invalid Bech32 checksum", [41]),
    (
        "WEB13W508D6QEJXTDG4Y5R3ZARVARY0C5XW7KT3G36H",
        "Version 1+ witness address must use Bech32m checksum",
        [],
    ),
    (
        "web1rw50wd4qw",
        "Version 1+ witness address must use Bech32m checksum",  # Invalid program length
        [],
    ),
    (
        "web10w508d6qejxtdg4y5r3zarvary0c5xw7kw508d6qejxtdg4y5r3zarvary0c5xw7kw53wz3mm",
        "Version 1+ witness address must use Bech32m checksum",  # Invalid program length
        [],
    ),
    (
        "WEB1QR508D6QEJXTDG4Y5R3ZARVARYVC9YWEP",
        "Invalid Bech32 v0 address program size (16 bytes), per BIP141",
        [],
    ),
    (
        "tc1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sL5k7",
        "Invalid or unsupported Segwit (Bech32) or Base58 encoding.",  # tb1, Mixed case
        [],
    ),
    ("WEB1QW508D6QEJXTDG4Y5R3ZARVARY0C5XW7K5RWwCG", "Invalid character or mixed case", [40]),  # web1, Mixed case, not in BIP 173 test vectors
    (
        "web1zw508d6qejxtdg4y5r3zarvaryvql80256",
        "Version 1+ witness address must use Bech32m checksum",  # Wrong padding
        [],
    ),
    (
        "tc1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3pjxtptv",
        "Invalid or unsupported Segwit (Bech32) or Base58 encoding.",  # tb1, Non-zero padding in 8-to-5 conversion
        [],
    ),
    (
        "web1ls6jn0",
        "Empty Bech32 data section",
        [],
    ),
    # BIP 350
    (
        "tc1p0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7vq5zuyut",
        "Invalid or unsupported Segwit (Bech32) or Base58 encoding.",  # Invalid human-readable part
        [],
    ),
    (
        "web1p0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7vqx65z6n",
        "Version 1+ witness address must use Bech32m checksum",  # Invalid checksum (Bech32 instead of Bech32m)
        [],
    ),
    (
        "tc1z0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7vqglt7rf",
        "Invalid or unsupported Segwit (Bech32) or Base58 encoding.",  # tb1, Invalid checksum (Bech32 instead of Bech32m)
        [],
    ),
    (
        "WEB1S0XLXVLHEMJA6C4DQV22UAPCTQUPFHLXM9H8Z3K2E72Q4K9HCZ7VQ9979JP",
        "Version 1+ witness address must use Bech32m checksum",  # Invalid checksum (Bech32 instead of Bech32m)
        [],
    ),
    (
        "web1qw508d6qejxtdg4y5r3zarvary0c5xw7kpl7za2",
        "Version 0 witness address must use Bech32 checksum",  # Invalid checksum (Bech32m instead of Bech32)
        [],
    ),
    (
        "tc1q0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7vq24jc47",
        "Invalid or unsupported Segwit (Bech32) or Base58 encoding.",  # tb1, Invalid checksum (Bech32m instead of Bech32)
        [],
    ),
    ("web1p0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7vqnxbwl3", "Invalid Base 32 character", [59]),  # Invalid character in checksum
    (
        "WEB130XLXVLHEMJA6C4DQV22UAPCTQUPFHLXM9H8Z3K2E72Q4K9HCZ7VQ0J7V2A",
        "Invalid Bech32 address witness version",
        [],
    ),
    (
        "web1pw57k0774",
        "Invalid Bech32 address program size (1 byte)",
        [],
    ),
    (
        "web1p0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7v8n0nx0muaewav25rnccrc",
        "Invalid Bech32 address program size (41 bytes)",
        [],
    ),
    (
        "WEB1QR508D6QEJXTDG4Y5R3ZARVARYVC9YWEP",
        "Invalid Bech32 v0 address program size (16 bytes), per BIP141",
        [],
    ),
    (
        "tc1p0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7vq47Zagq",
        "Invalid or unsupported Segwit (Bech32) or Base58 encoding.",  # tb1, Mixed case
        [],
    ),
    (
        "web1p0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7v07qzmw6f8",
        "Invalid padding in Bech32 data section",  # zero padding of more than 4 bits
        [],
    ),
    (
        "tc1p0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7vpggkg4j",
        "Invalid or unsupported Segwit (Bech32) or Base58 encoding.",  # tb1, Non-zero padding in 8-to-5 conversion
        [],
    ),
    (
        "web1ls6jn0",
        "Empty Bech32 data section",
        [],
    ),
]

VALID_DATA = [
    # BIP 350
    (
        "WEB1QW508D6QEJXTDG4Y5R3ZARVARY0C5XW7K5RWWCG",
        "0014751e76e8199196d454941c45d1b3a323f1433bd6",
    ),
    # (
    #   "tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7",
    #   "00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262",
    # ),
    (
        "web1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3qfge8p0",
        "00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262",
    ),
    (
        "web1pw508d6qejxtdg4y5r3zarvary0c5xw7kw508d6qejxtdg4y5r3zarvary0c5xw7k080pzc",
        "5128751e76e8199196d454941c45d1b3a323f1433bd6751e76e8199196d454941c45d1b3a323f1433bd6",
    ),
    (
        "WEB1SW50QYPXM26",
        "6002751e",
    ),
    (
        "web1zw508d6qejxtdg4y5r3zarvaryvqy2ays",
        "5210751e76e8199196d454941c45d1b3a323",
    ),
    # (
    #   "tb1qqqqqp399et2xygdj5xreqhjjvcmzhxw4aywxecjdzew6hylgvsesrxh6hy",
    #   "0020000000c4a5cad46221b2a187905e5266362b99d5e91c6ce24d165dab93e86433",
    # ),
    (
        "web1qqqqqp399et2xygdj5xreqhjjvcmzhxw4aywxecjdzew6hylgvses973fq4",
        "0020000000c4a5cad46221b2a187905e5266362b99d5e91c6ce24d165dab93e86433",
    ),
    # (
    #   "tb1pqqqqp399et2xygdj5xreqhjjvcmzhxw4aywxecjdzew6hylgvsesf3hn0c",
    #   "5120000000c4a5cad46221b2a187905e5266362b99d5e91c6ce24d165dab93e86433",
    # ),
    (
        "web1pqqqqp399et2xygdj5xreqhjjvcmzhxw4aywxecjdzew6hylgvses0f3qcf",
        "5120000000c4a5cad46221b2a187905e5266362b99d5e91c6ce24d165dab93e86433",
    ),
    (
        "web1p0xlxvlhemja6c4dqv22uapctqupfhlxm9h8z3k2e72q4k9hcz7vqnxywl3",
        "512079be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798",
    ),
    # PayToAnchor(P2A)
    (
        "web1pfeesu0elkp",
        "51024e73",
    ),
]


class ValidateAddressMainTest(BitcoinTestFramework):
    def set_test_params(self):
        self.setup_clean_chain = True
        self.chain = ""  # main
        self.num_nodes = 1
        self.extra_args = [["-prune=899"]] * self.num_nodes

    def check_valid(self, addr, spk):
        info = self.nodes[0].validateaddress(addr)
        assert_equal(info["isvalid"], True)
        assert_equal(info["scriptPubKey"], spk)
        assert "error" not in info
        assert "error_locations" not in info

    def check_invalid(self, addr, error_str, error_locations):
        res = self.nodes[0].validateaddress(addr)
        assert_equal(res["isvalid"], False)
        assert_equal(res["error"], error_str)
        assert_equal(res["error_locations"], error_locations)

    def test_validateaddress(self):
        for (addr, error, locs) in INVALID_DATA:
            self.check_invalid(addr, error, locs)
        for (addr, spk) in VALID_DATA:
            self.check_valid(addr, spk)

    def run_test(self):
        self.test_validateaddress()


if __name__ == "__main__":
    ValidateAddressMainTest(__file__).main()
