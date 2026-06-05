#!/usr/bin/env python3
#
# Copyright (c) 2018-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
#
# Download or build previous releases.
# Needs curl and tar to download a release, or the build dependencies when
# building a release.

import argparse
import contextlib
from fnmatch import fnmatch
import hashlib
import json
import os
from pathlib import Path
import platform
import shutil
import subprocess
import sys
import time
import urllib.request
import zipfile

TAR = os.getenv('TAR', 'tar')

GITHUB_REPO = "bitweb-project/bitweb"

SHA256_SUMS = {
    "3f69ac3312118ba433db7d6e9ae3d3a98f12be3f0378d71eb512d24edd69ef8b": {"tag": "v0.30.2", "archive": "bitweb-0.30.2-aarch64-linux-gnu.tar.gz"},
    "1ac7d58628d2a98ecf3eb2521c6d28a9fcbfba4a46132a67802daa316eaf9f02": {"tag": "v0.30.2", "archive": "bitweb-0.30.2-arm-linux-gnueabihf.tar.gz"},
    "ee0ea0837186d6bd7fd8cfb0925236ca68c3365ab9b2dd0937f25918a6297e18": {"tag": "v0.30.2", "archive": "bitweb-0.30.2-arm64-apple-darwin.tar.gz"},
    "497efe4b0a719108de365598e5eda3a62f903eaed176e92f8db94ae632c59e9a": {"tag": "v0.30.2", "archive": "bitweb-0.30.2-powerpc64-linux-gnu.tar.gz"},
    "79589c1d72849bf094aeb976149df77f5a14db764e973f88a434eb13d98ed9bd": {"tag": "v0.30.2", "archive": "bitweb-0.30.2-riscv64-linux-gnu.tar.gz"},
    "2c9f295df2981b6653c67b3808549de5777e28c0e47f54254c15355ead727ce7": {"tag": "v0.30.2", "archive": "bitweb-0.30.2-x86_64-apple-darwin.tar.gz"},
    "2f6e7a4488fc81904fcc100d7b663855c3784e312ca19b91bde1f1e9dda80d1d": {"tag": "v0.30.2", "archive": "bitweb-0.30.2-x86_64-linux-gnu.tar.gz"},
    "9702d89a407f699e2c177f2e3822910438ded5f3af7e6a553568718353b65072": {"tag": "v0.30.2", "archive": "bitweb-0.30.2-win64.zip"},
}


@contextlib.contextmanager
def pushd(new_dir) -> None:
    previous_dir = os.getcwd()
    os.chdir(new_dir)
    try:
        yield
    finally:
        os.chdir(previous_dir)


def get_latest_tag() -> str:
    """Fetch the tag of the latest release from GitHub API."""
    url = f"https://api.github.com/repos/{GITHUB_REPO}/releases/latest"
    print("Fetching latest release tag from GitHub...")
    try:
        req = urllib.request.Request(url, headers={"User-Agent": "bitweb-downloader"})
        with urllib.request.urlopen(req) as response:
            data = json.loads(response.read().decode())
            tag = data["tag_name"]
            print(f"Latest release: {tag}")
            return tag
    except Exception as e:
        print(f"Failed to fetch latest release: {e}", file=sys.stderr)
        sys.exit(1)


def download_from_url(url, archive):
    last_print_time = time.time()

    def progress_hook(progress_bytes, total_size):
        nonlocal last_print_time
        now = time.time()
        percent = min(100, (progress_bytes * 100) / total_size) if total_size else 0
        bar_length = 40
        filled_length = int(bar_length * percent / 100)
        bar = '#' * filled_length + '-' * (bar_length - filled_length)
        if now - last_print_time >= 1 or percent >= 100:
            print(f'\rDownloading: [{bar}] {percent:.1f}%', flush=True, end="")
            last_print_time = now

    req = urllib.request.Request(url, headers={"User-Agent": "bitweb-downloader"})
    with urllib.request.urlopen(req) as response:
        if response.status != 200:
            raise RuntimeError(f"HTTP request failed with status code: {response.status}")

        total_size = int(response.getheader('Content-Length', 0))
        progress_bytes = 0

        with open(archive, 'wb') as file:
            while True:
                chunk = response.read(8192)
                if not chunk:
                    break
                file.write(chunk)
                progress_bytes += len(chunk)
                progress_hook(progress_bytes, total_size)

    print('\n', flush=True, end="")


def download_binary(tag, args) -> int:
    if Path(tag).is_dir():
        if not args.remove_dir:
            print('Using cached {}'.format(tag))
            return 0
        shutil.rmtree(tag)

    host = args.host
    if tag < "v23" and host in ["x86_64-apple-darwin", "arm64-apple-darwin"]:
        host = "osx64"

    archive_format = 'tar.gz'
    if host == 'win64':
        archive_format = 'zip'

    archive = f'bitweb-{tag[1:]}-{host}.{archive_format}'

    # GitHub Releases download URL
    archive_url = f'https://github.com/{GITHUB_REPO}/releases/download/{tag}/{archive}'

    print(f'Fetching: {archive_url}')

    try:
        download_from_url(archive_url, archive)
    except Exception as e:
        print(f"\nDownload failed: {e}", file=sys.stderr)
        return 1

    hasher = hashlib.sha256()
    with open(archive, "rb") as afile:
        hasher.update(afile.read())
    archiveHash = hasher.hexdigest()

    if archiveHash not in SHA256_SUMS or SHA256_SUMS[archiveHash]['archive'] != archive:
        if archive in [v['archive'] for v in SHA256_SUMS.values()]:
            print(f"Checksum {archiveHash} did not match", file=sys.stderr)
        else:
            print("Checksum for given version doesn't exist", file=sys.stderr)
        return 1

    print("Checksum matched")
    Path(tag).mkdir()

    if host == 'win64':
        try:
            with zipfile.ZipFile(archive, 'r') as zip_file:
                zip_file.extractall(tag)
            extracted_items = os.listdir(tag)
            top_level_dir = os.path.join(tag, extracted_items[0])
            for item in os.listdir(top_level_dir):
                shutil.move(os.path.join(top_level_dir, item), tag)
            os.rmdir(top_level_dir)
        except Exception as e:
            print(f"Zip extraction failed: {e}", file=sys.stderr)
            return 1
    else:
        ret = subprocess.run([TAR, '-zxf', archive, '-C', tag,
                              '--strip-components=1',
                              'bitweb-{tag}'.format(tag=tag[1:])]).returncode
        if ret != 0:
            print(f"Failed to extract the {tag} tarball", file=sys.stderr)
            return ret

    Path(archive).unlink()

    if tag >= "v23" and tag < "v28.2" and args.host == "arm64-apple-darwin":
        binary_path = f'{os.getcwd()}/{tag}/bin/'
        for arm_binary in os.listdir(binary_path):
            ret = subprocess.run(
                ['codesign', '-v', binary_path + arm_binary],
                stderr=subprocess.DEVNULL,
            ).returncode
            if ret == 1:
                ret = subprocess.run(
                    ['codesign', '-s', '-', binary_path + arm_binary]
                ).returncode
                if ret != 0:
                    print(f"Failed to self-sign {tag} {arm_binary} arm64 binary", file=sys.stderr)
                    return 1
                ret = subprocess.run(
                    ['codesign', '-v', binary_path + arm_binary]
                ).returncode
                if ret != 0:
                    print(f"Failed to verify the self-signed {tag} {arm_binary} arm64 binary", file=sys.stderr)
                    return 1

    return 0


def set_host(args) -> int:
    if platform.system().lower() == 'windows':
        if platform.machine() != 'AMD64':
            print('Only 64bit Windows supported', file=sys.stderr)
            return 1
        args.host = 'win64'
        return 0

    host = os.environ.get('HOST', subprocess.check_output(
        './depends/config.guess').decode())

    platforms = {
        'aarch64-*-linux*': 'aarch64-linux-gnu',
        'powerpc64le-*-linux-*': 'powerpc64le-linux-gnu',
        'riscv64-*-linux*': 'riscv64-linux-gnu',
        'x86_64-*-linux*': 'x86_64-linux-gnu',
        'x86_64-apple-darwin*': 'x86_64-apple-darwin',
        'aarch64-apple-darwin*': 'arm64-apple-darwin',
    }

    args.host = ''
    for pattern, target in platforms.items():
        if fnmatch(host, pattern):
            args.host = target

    if not args.host:
        print('Not sure which binary to download for {}'.format(host), file=sys.stderr)
        return 1

    return 0


def main(args) -> int:
    if args.latest:
        args.tags = [get_latest_tag()]

    Path(args.target_dir).mkdir(exist_ok=True, parents=True)
    print("Releases directory: {}".format(args.target_dir))

    ret = set_host(args)
    if ret:
        return ret

    with pushd(args.target_dir):
        for tag in args.tags:
            ret = download_binary(tag, args)
            if ret:
                return ret

    return 0


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
        epilog=f'Downloads binaries from GitHub Releases: https://github.com/{GITHUB_REPO}',
    )
    parser.add_argument('-r', '--remove-dir', action='store_true',
                        help='remove existing directory and re-download.')
    parser.add_argument('-t', '--target-dir', action='store',
                        help='target directory.', default='releases')
    parser.add_argument('--latest', action='store_true',
                        help='automatically download the latest release from GitHub.')
    all_tags = sorted([*set([v['tag'] for v in SHA256_SUMS.values()])])
    parser.add_argument('tags', nargs='*', default=all_tags,
                        help='release tags, e.g.: v0.30.x v0.31.0 '
                        '(if not specified, all tags from SHA256_SUMS are used)')
    args = parser.parse_args()
    sys.exit(main(args))
