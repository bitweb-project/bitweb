Release Process
====================

## Branch updates

### Before every release candidate

* Update release candidate version in `CMakeLists.txt` (`CLIENT_VERSION_RC`).
* Update manpages (after rebuilding the binaries), see [gen-manpages.py](/contrib/devtools/README.md#gen-manpagespy).
* Update bitweb.conf and commit changes if they exist, see [gen-bitweb-conf.sh](/contrib/devtools/README.md#gen-bitweb-confsh).

### Before every major and minor release

* Update [bips.md](bips.md) to account for changes since the last release.
* Update version in `CMakeLists.txt` (don't forget to set `CLIENT_VERSION_RC` to `0`).
* Update manpages (see previous section)
* Write release notes (see "Write the release notes" below) in doc/release-notes.md. If necessary,
  archive the previous release notes as doc/release-notes/release-notes-${VERSION}.md.

### Before every major release

* On both the master branch and the new release branch:
  - update `CLIENT_VERSION_MAJOR` in [`CMakeLists.txt`](../CMakeLists.txt)
* On the new release branch in [`CMakeLists.txt`](../CMakeLists.txt)(see [this commit](https://github.com/bitcoin/bitcoin/commit/742f7dd)):
  - set `CLIENT_VERSION_MINOR` to `0`
  - set `CLIENT_VERSION_BUILD` to `0`
  - set `CLIENT_VERSION_IS_RELEASE` to `true`

#### Before branch-off

* Update hardcoded [seeds](/contrib/seeds/README.md), see [this pull request](https://github.com/bitcoin/bitcoin/pull/27488) for an example.
* Update the following variables in [`src/kernel/chainparams.cpp`](/src/kernel/chainparams.cpp) for mainnet, testnet, and signet:
  - `m_assumed_blockchain_size` and `m_assumed_chain_state_size` with the current size plus some overhead (see
    [this](#how-to-calculate-assumed-blockchain-and-chain-state-size) for information on how to calculate them).
  - The following updates should be reviewed with `reindex-chainstate` and `assumevalid=0` to catch any defect
    that causes rejection of blocks in the past history.
  - `chainTxData` with statistics about the transaction count and rate. Use the output of the `getchaintxstats` RPC with an
    `nBlocks` of 8192 (28 days) and a `bestblockhash` of RPC `getbestblockhash`; see
    [this pull request](https://github.com/bitcoin/bitcoin/pull/28591) for an example. Reviewers can verify the results by running
    `getchaintxstats <window_block_count> <window_final_block_hash>` with the `window_block_count` and `window_final_block_hash` from your output.
  - `defaultAssumeValid` with the output of RPC `getblockhash` using the `height` of `window_final_block_height` above
    (and update the block height comment with that height), taking into account the following:
    - On mainnet, the selected value must not be orphaned, so it may be useful to set the height two blocks back from the tip.
    - Testnet should be set with a height some tens of thousands back from the tip, due to reorgs there.
  - `nMinimumChainWork` with the "chainwork" value of RPC `getblockheader` using the same height as that selected for the previous step.
  - `m_assumeutxo_data` array should be appended to with the values returned by calling `bitweb-cli -rpcclienttimeout=0 -named dumptxoutset utxo.dat rollback=<height or hash>`
    The same height considerations for `defaultAssumeValid` apply.
* Consider updating the headers synchronization tuning parameters to account for the chainparams updates.
  The optimal values change very slowly, so this isn't strictly necessary every release, but doing so doesn't hurt.
  - Update configuration variables in [`contrib/devtools/headerssync-params.py`](/contrib/devtools/headerssync-params.py):
    - Set `TIME` to the software's expected supported lifetime -- after this time, its ability to defend against a high bandwidth timewarp attacker will begin to degrade.
    - Set `MINCHAINWORK_HEADERS` to the height used for the `nMinimumChainWork` calculation above.
    - Check that the other variables still look reasonable.
  - Run the script. It works fine in CPython, but PyPy is much faster (seconds instead of minutes): `pypy3 contrib/devtools/headerssync-params.py`.
  - Paste the output defining `HEADER_COMMITMENT_PERIOD` and `REDOWNLOAD_BUFFER_SIZE` into the top of [`src/headerssync.cpp`](/src/headerssync.cpp).
- Clear the release notes and move them to the wiki (see "Write the release notes" below).

#### After branch-off (on the major release branch)

- Update the versions.
- Clear the release notes: `cp doc/release-notes-empty-template.md doc/release-notes.md`
- Prune inputs from the qa-assets repo (See [pruning
  inputs](https://github.com/bitweb-project/qa-assets#pruning-inputs)).

#### Before final release

- Ensure the "Needs release note" label is removed from all relevant pull
  requests and issues:
  https://github.com/bitweb-project/bitweb/issues?q=label%3A%22Needs+release+note%22

#### Tagging a release (candidate)

To tag the version (or release candidate) in git, use the `make-tag.py` script from [bitweb-maintainer-tools](https://github.com/bitweb-project/bitweb-maintainer-tools). From the root of the repository run:

    ../bitcoin-maintainer-tools/make-tag.py v(new version, e.g. 25.0)

This will perform a few last-minute consistency checks in the build system files, and if they pass, create a signed tag.

## Building

### First time / New builders

Install Guix using one of the installation methods detailed in
[contrib/guix/INSTALL.md](/contrib/guix/INSTALL.md).

Check out the source code in the following directory hierarchy.

    cd /path/to/your/toplevel/build
    git clone https://github.com/bitweb-project/guix.sigs.git
    git clone https://github.com/bitweb-project/bitweb.git

### Write the release notes

For the period during which the notes are being edited on the wiki, the version on the branch should be wiped and replaced with a link to the wiki which should be used for all announcements until `-final`.

Generate list of authors:

    git log --format='- %aN' v(current version, e.g. 29.0)..v(new version, e.g. 30.0) | grep -v 'merge-script' | sort -fiu

### Setup and perform Guix builds

Checkout the Bitweb Core version you'd like to build:

```sh
pushd ./bitweb
SIGNER='(your builder key, ie bluematt, sipa, etc)'
VERSION='(new version without v-prefix, e.g. 25.0)'
git fetch origin "v${VERSION}"
git checkout "v${VERSION}"
popd
```

Ensure your guix.sigs are up-to-date if you wish to `guix-verify` your builds
against other `guix-attest` signatures.

```sh
git -C ./guix.sigs pull
```

### Create the macOS SDK tarball (first time, or when SDK version changes)

Create the macOS SDK tarball, see the [macdeploy
instructions](/contrib/macdeploy/README.md#sdk-extraction) for
details.

### Build and attest to build outputs

Follow the relevant Guix README.md sections:
- [Building](/contrib/guix/README.md#building)
- [Attesting to build outputs](/contrib/guix/README.md#attesting-to-build-outputs)

### Verify other builders' signatures to your own (optional)

- [Verifying build output attestations](/contrib/guix/README.md#verifying-build-output-attestations)

### Commit your non codesigned signature to guix.sigs

```sh
pushd ./guix.sigs
git add "${VERSION}/${SIGNER}"/noncodesigned.SHA256SUMS{,.asc}
git commit -m "Add attestations by ${SIGNER} for ${VERSION} non-codesigned"
popd
```

Then open a Pull Request to the [guix.sigs repository](https://github.com/bitweb-project/guix.sigs).

## After 6 or more people have guix-built and their results match

After verifying signatures, combine the `all.SHA256SUMS.asc` file from all signers into `SHA256SUMS.asc`:

```bash
cat "$VERSION"/*/all.SHA256SUMS.asc > SHA256SUMS.asc
```

- Upload to the bitwebcore.net server:
    1. The contents of each `./bitweb/guix-build-${VERSION}/output/${HOST}/` directory.

       Guix will output all of the results into host subdirectories, but the SHA256SUMS
       file does not include these subdirectories. In order for downloads via torrent
       to verify without directory structure modification, all of the uploaded files
       need to be in the same directory as the SHA256SUMS file.

       Wait until all of these files have finished uploading before uploading the SHA256SUMS(.asc) files.

    2. The `SHA256SUMS` file

    3. The `SHA256SUMS.asc` combined signature file you just created.

- After uploading release candidate binaries, notify the
  [Bitweb Discord](https://discord.gg/uC6wEVu6FR) and
  [Bitweb Telegram](https://t.me/bitweb_en) that a release candidate is available for testing.
  Include a link to the release notes draft.

- The server will automatically create an OpenTimestamps file and torrent of the directory.

- Optionally help seed this torrent. To get the `magnet:` URI use:

  ```sh
  transmission-show -m <torrent file>
  ```

  Insert the magnet URI into the announcement sent to mailing lists. This permits
  people without access to `bitwebcore.net` to download the binary distribution.
  Also put it into the `optional_magnetlink:` slot in the YAML file for
  bitwebcore.net.

- Archive the release notes for the new version to `doc/release-notes/release-notes-${VERSION}.md`
  (branch `master` and branch of the release).

- Update the bitwebcore.net website

  - RPC documentation update

      - See https://github.com/bitweb-project/bitwebcore.net/blob/master/contrib/doc-gen/

- Update repositories

  - Delete post-EOL [release branches](https://github.com/bitweb-project/bitweb/branches/all) and create a tag `v${branch_name}-final`.

  - Delete ["Needs backport" labels](https://github.com/bitweb-project/bitweb/labels?q=backport) for non-existing branches.

  - Create a [new GitHub release](https://github.com/bitweb-project/bitweb/releases/new) with a link to the archived release notes

- Announce the release:

  - Bitweb Core release list https://bitwebcore.net/en/releases/

  - Bitweb Core X https://x.com/Bitweb_Project

  - Bitweb Core Telegram https://t.me/bitweb_news_en

### Additional information

#### <a name="how-to-calculate-assumed-blockchain-and-chain-state-size"></a>How to calculate `m_assumed_blockchain_size` and `m_assumed_chain_state_size`

Both variables are used as a guideline for how much space the user needs on their drive in total, not just strictly for the blockchain.
Note that all values should be taken from a **fully synced** node and have an overhead of 5-10% added on top of its base value.

To calculate `m_assumed_blockchain_size`, take the size in GiB of these directories:
- For `mainnet` -> the data directory, excluding the `/testnet3`, `/testnet4`, `/signet`, and `/regtest` directories and any overly large files, e.g. a huge `debug.log`
- For `testnet` -> `/testnet3`
- For `testnet4` -> `/testnet4`
- For `signet` -> `/signet`

To calculate `m_assumed_chain_state_size`, take the size in GiB of these directories:
- For `mainnet` -> `/chainstate`
- For `testnet` -> `/testnet3/chainstate`
- For `testnet4` -> `/testnet4/chainstate`
- For `signet` -> `/signet/chainstate`

Notes:
- When taking the size for `m_assumed_blockchain_size`, there's no need to exclude the `/chainstate` directory since it's a guideline value and an overhead will be added anyway.
- The expected overhead for growth may change over time. Consider whether the percentage needs to be changed in response; if so, update it here in this section.
