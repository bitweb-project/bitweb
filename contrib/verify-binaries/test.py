#!/usr/bin/env python3

import json
import sys
import subprocess
from pathlib import Path


def main():
    """Tests ordered roughly from faster to slower."""
    expect_code(run_verify("", "pub", '0.32'), 4, "Nonexistent version should fail")
    expect_code(run_verify("", "pub", '0.32.awefa.12f9h'), 11, "Malformed version should fail")
    expect_code(run_verify('--min-good-sigs 20', "pub", "30.3"), 9, "--min-good-sigs 20 should fail")

    print("- testing verification (30.3-x86_64-linux-gnu.tar.gz)", flush=True)
    _220_x86_64_linux_gnu = run_verify("--json", "pub", "30.3-x86_64-linux-gnu.tar.gz")
    try:
        result = json.loads(_220_x86_64_linux_gnu.stdout.decode())
    except Exception:
        print("failed on 30.3-x86_64-linux-gnu.tar.gz --json:")
        print_process_failure(_220_x86_64_linux_gnu)
        raise

    expect_code(_220_x86_64_linux_gnu, 0, "30.3-x86_64-linux-gnu.tar.gz should succeed")
    v = result['verified_binaries']
    assert result['good_trusted_sigs']
    assert len(v) == 1
    assert v['bitweb-30.3-x86_64-linux-gnu.tar.gz'] == 'b784d0f6e1fe292726cda967bddebd3cc99a63a07f54fce4e45a194b569a6d80'

    print("- testing verification (30.3)", flush=True)
    _220 = run_verify("--json", "pub", "30.3")
    try:
        result = json.loads(_220.stdout.decode())
    except Exception:
        print("failed on 30.3 --json:")
        print_process_failure(_220)
        raise

    expect_code(_220, 0, "30.3 should succeed")
    v = result['verified_binaries']
    assert result['good_trusted_sigs']
    assert v['bitweb-30.3-aarch64-linux-gnu.tar.gz'] == 'bb7e337db7503b20e5961abe8c4a494e8336e63433a0d0d1fb60ec561b73603f'
    assert v['bitweb-30.3-x86_64-apple-darwin.tar.gz'] == '8d29c5b13dba5f3d562474d1b0f1ee5ca3cd4f4fb0f0420fc8c3e03ea99122f3'
    assert v['bitweb-30.3-x86_64-linux-gnu.tar.gz'] == 'b784d0f6e1fe292726cda967bddebd3cc99a63a07f54fce4e45a194b569a6d80'


def run_verify(global_args: str, command: str, command_args: str) -> subprocess.CompletedProcess:
    maybe_here = Path.cwd() / 'verify.py'
    path = maybe_here if maybe_here.exists() else Path.cwd() / 'contrib' / 'verify-binaries' / 'verify.py'

    if command == "pub":
        command += " --cleanup"

    return subprocess.run(
        f"{path} {global_args} {command} {command_args}",
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)


def expect_code(completed: subprocess.CompletedProcess, expected_code: int, msg: str):
    if completed.returncode != expected_code:
        print(f"{msg!r} failed: got code {completed.returncode}, expected {expected_code}")
        print_process_failure(completed)
        sys.exit(1)
    else:
        print(f"✓ {msg!r} passed")


def print_process_failure(completed: subprocess.CompletedProcess):
    print(f"stdout:\n{completed.stdout.decode()}")
    print(f"stderr:\n{completed.stderr.decode()}")


if __name__ == '__main__':
    main()
