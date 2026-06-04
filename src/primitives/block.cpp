// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2019 The Bitcoin Core developers
// Copyright (c) 2021-2026 The Bitweb Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <primitives/block.h>

/* Bitweb Params */
#include <crypto/argon2d/argon2.h>
/* Bitweb Params */
#include <hash.h>
#include <streams.h>
#include <tinyformat.h>

uint256 CBlockHeader::GetHash() const
{
    return (HashWriter{} << *this).GetHash();
}

/* Bitweb Params */
/*
 * Compute the Argon2id proof-of-work hash of this block header.
 *
 * The serialized 80-byte block header is used as both the password and
 * the salt input to argon2id_hash_raw. Using the header for both roles
 * keeps the construction simple and self-contained: the salt is fully
 * determined by the header itself, requiring no additional hash or
 * pre-processing step.
 *
 * CDataStream is used to produce the canonical little-endian serialization
 * of the block header. Direct struct casting is avoided as it depends on
 * ABI layout and is not safe across compilers.
 *
 * Parameters (consensus-critical, must not be changed):
 *   t (time cost)   = 3        -- number of passes over memory
 *   m (memory cost) = 1024 KiB -- fits in CPU L2 cache, penalises GPU
 *   p (parallelism) = 1        -- single-threaded per hash attempt
 */
uint256 CBlockHeader::GetArgon2idPoWHash() const
{
    // Serialize the block header (80 bytes: version, hashPrevBlock,
    // hashMerkleRoot, nTime, nBits, nNonce).
    DataStream ss{};
    ss << *this;
    assert(ss.size() == 80);


    // Compute Argon2id hash. The serialized header serves as both the
    // password and the salt. argon2id_hash_raw requires salt >= 8 bytes;
    // the 80-byte header satisfies this with ample margin.
    uint256 hash;
    argon2_context context;
    context.out    = hash.begin();
    context.outlen = 32;
    context.pwd    = const_cast<uint8_t*>((const uint8_t*)ss.data());
    context.pwdlen = 80;
    context.salt   = const_cast<uint8_t*>((const uint8_t*)ss.data());
    context.saltlen = 80;
    context.secret = nullptr; context.secretlen = 0;
    context.ad     = nullptr; context.adlen     = 0;
    context.allocate_cbk = nullptr;
    context.free_cbk     = nullptr;
    context.flags   = ARGON2_DEFAULT_FLAGS;
    context.t_cost  = 3;
    context.m_cost  = 1024;
    context.lanes   = 1;
    context.threads = 1;
    context.version = ARGON2_VERSION_NUMBER;

    // argon2id_hash_raw must not fail for well-formed parameters.
    // Any failure here indicates a programming error or memory exhaustion
    // and is treated as a fatal condition.

    const int rc = argon2_ctx(&context, Argon2_id);
    assert(rc == ARGON2_OK);
    return hash;
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=0x%08x, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u)\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,
        vtx.size());
    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
