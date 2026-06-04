### TestGen ###

Utilities to generate test vectors for the data-driven Bitweb tests.

To use inside a scripted-diff (or just execute directly):

    ./gen_key_io_test_vectors.py valid 70 > ../../src/test/data/key_io_valid.json
    ./gen_key_io_test_vectors.py invalid 70 > ../../src/test/data/key_io_invalid.json


### gen_validateaddress_vectors.py ###
Regenerates INVALID_DATA and VALID_DATA test vectors in
test/functional/rpc_validateaddress.py for an arbitrary bech32 HRP.

    # Print generated blocks to stdout (inspect before applying):
    chmod +x gen_validateaddress_vectors.py
    ./gen_validateaddress_vectors.py
    ./gen_validateaddress_vectors.py --hrp bte

    # Patch rpc_validateaddress.py in-place (recommended):
    chmod +x gen_validateaddress_vectors.py
    ./gen_validateaddress_vectors.py --apply
    ./gen_validateaddress_vectors.py --hrp bte --apply

### regenerate_test_data.py ###
Regenerates bitweb-tx utility test data (.hex / .json).
Requires a built binary (cmake --build build -j$(nproc)).

    cd contrib/testgen
    python3 regenerate_test_data.py
