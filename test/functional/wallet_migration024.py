#!/usr/bin/env python3
# Copyright (c) 2018-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test migratewallet RPC using a pre-built legacy wallet fixture (v0.24).

Fixture file test/functional/data/legacy_wallet_v24.dat was created on a
v0.24 Bitweb mainnet node. The test runs on mainnet chain so the wallet's
genesis hash matches. -noconnect prevents peer connections to real network.
"""

import os
import shutil

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import (
    assert_equal,
    assert_raises_rpc_error,
)

TESTSDIR = os.path.dirname(os.path.realpath(__file__))


class WalletMigration024Test(BitcoinTestFramework):

    def set_test_params(self):
        self.setup_clean_chain = True
        self.chain = ""  # main
        self.num_nodes = 1
        self.extra_args = [["-noconnect", "-walletcrosschain"]]
        self.wallet_names = []

    def skip_test_if_missing_module(self):
        self.skip_if_no_wallet()

    def install_wallet(self, wallet_name, fixture_name):
        """Copy a fixture wallet.dat into the node's wallets directory."""
        dst = self.nodes[0].wallets_path / wallet_name
        dst.mkdir(parents=True, exist_ok=True)
        shutil.copy(
            os.path.join(TESTSDIR, "data", fixture_name),
            dst / "wallet.dat",
        )

    def run_test(self):
        node = self.nodes[0]

        # ------------------------------------------------------------------
        # 1. Migrate a real v0.24 legacy wallet fixture → descriptor wallet.
        # ------------------------------------------------------------------
        self.log.info("Test migrating a v0.24 legacy wallet fixture")
        self.install_wallet("legacy_v24", "legacy_wallet_v24.dat")

        result = node.migratewallet("legacy_v24")

        assert_equal(result["wallet_name"], "legacy_v24")
        assert "backup_path" in result
        assert os.path.exists(result["backup_path"]), \
            f"Backup file missing: {result['backup_path']}"

        wallet_rpc = node.get_wallet_rpc("legacy_v24")
        assert wallet_rpc.getwalletinfo()["descriptors"], \
            "Migrated wallet must be descriptor-based"
        wallet_rpc.unloadwallet()

        # ------------------------------------------------------------------
        # 2. Migrating an already-descriptor wallet must fail with -4.
        # ------------------------------------------------------------------
        self.log.info("Test that migrating a descriptor wallet fails")
        node.createwallet(wallet_name="desc_wallet")
        assert_raises_rpc_error(
            -4,
            "Error: This wallet is already a descriptor wallet",
            node.migratewallet,
            "desc_wallet",
        )
        node.unloadwallet("desc_wallet")

        # ------------------------------------------------------------------
        # 3. Migrating a non-existent wallet must fail with -18.
        # ------------------------------------------------------------------
        self.log.info("Test that migrating a non-existent wallet fails")
        assert_raises_rpc_error(
            -4,
            "Wallet does not exist",
            node.migratewallet,
            "no_such_wallet_xyz",
        )


if __name__ == "__main__":
    WalletMigration024Test(__file__).main()
