// Copyright (c) 2022 The Bitcoin Core developers
// Copyright (c) 2021-2026 The Bitweb Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <kernel/context.h>

/* Bitweb Params */
#include <crypto/argon2d/argon2.h>
/* Bitweb Params */
#include <crypto/sha256.h>
#include <logging.h>
#include <random.h>

#include <mutex>
#include <string>

namespace kernel {
Context::Context()
{
    static std::once_flag globals_initialized{};
    std::call_once(globals_initialized, []() {
        std::string sha256_algo = SHA256AutoDetect();
        LogInfo("Using the '%s' SHA256 implementation\n", sha256_algo);
        /* Bitweb Params */
        // Bitweb: detect best SIMD implementation for Argon2id PoW hashing
        std::string argon2_algo = Argon2AutoDetect();
        LogInfo("Using the '%s' Argon2id implementation\n", argon2_algo);
        /* Bitweb Params */
        RandomInit();
    });
}

} // namespace kernel
