// Copyright (c) 2021-2026 The Bitweb Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <bench/bench.h>
#include <crypto/argon2d/argon2.h>
#include <tinyformat.h>
#include <uint256.h>

#include <array>
#include <cassert>
#include <cstdint>

/* Consensus-critical parameters - must match block.cpp exactly */
static constexpr uint32_t ARGON2ID_T       = 3;
static constexpr uint32_t ARGON2ID_M       = 1024;
static constexpr uint32_t ARGON2ID_P       = 1;
static constexpr size_t   ARGON2ID_HASHLEN = 32;
static constexpr size_t   HEADER_LEN       = 80;

/*
 * Run one Argon2id PoW hash of a synthetic 80-byte block header.
 * Unit is "hash" - unlike SHA256, Argon2 is memory-hard so
 * throughput in bytes/s is not a meaningful metric.
 */
static void RunArgon2idHash(benchmark::Bench& bench)
{
    std::array<uint8_t, HEADER_LEN> hdr{};
    hdr[0] = 0x04;

    bench.unit("hash").batch(1).run([&] {
        uint256 out;
        argon2_context context;
        context.out    = out.begin();
        context.outlen = ARGON2ID_HASHLEN;
        context.pwd    = hdr.data();
        context.pwdlen = HEADER_LEN;
        context.salt   = hdr.data();
        context.saltlen = HEADER_LEN;
        context.secret = nullptr; context.secretlen = 0;
        context.ad     = nullptr; context.adlen     = 0;
        context.allocate_cbk = nullptr;
        context.free_cbk     = nullptr;
        context.flags   = ARGON2_DEFAULT_FLAGS;
        context.t_cost  = ARGON2ID_T;
        context.m_cost  = ARGON2ID_M;
        context.lanes   = ARGON2ID_P;
        context.threads = ARGON2ID_P;
        context.version = ARGON2_VERSION_NUMBER;
        const int rc = argon2_ctx(&context, Argon2_id);
        assert(rc == ARGON2_OK);
    });
}

/*
 * One benchmark variant per available ISA, mirroring SHA256_STANDARD /
 * SHA256_SSE4 / SHA256_AVX2 in crypto_hash.cpp.
 * Argon2AutoDetect(impl) selects the implementation exactly as
 * SHA256AutoDetect(impl) does - no #ifdef needed in the bench body.
 * If the requested ISA is unavailable, Argon2AutoDetect silently
 * falls back (to reference on non-x86).
 *
 * ISA variants are compiled in only when the build system detected the
 * required compiler support (HAVE_ARGON2_SSE2 / SSSE3 / AVX2 / AVX512 /
 * NEON in introspection.cmake) and forwarded the matching
 * ENABLE_ARGON2_* definition to this target.  Variants whose
 * ENABLE_ARGON2_* macro is absent are excluded entirely so that
 * bench_bitweb never registers a benchmark it cannot meaningfully run.
 */
static void Argon2id_STANDARD(benchmark::Bench& bench)
{
    bench.name(strprintf("%s using the '%s' Argon2id implementation",
        __func__, Argon2AutoDetect(argon2_implementation::STANDARD)));
    RunArgon2idHash(bench);
    Argon2AutoDetect();
}
BENCHMARK(Argon2id_STANDARD, benchmark::PriorityLevel::HIGH);

#if defined(ENABLE_ARGON2_SSE2)
static void Argon2id_SSE2(benchmark::Bench& bench)
{
    bench.name(strprintf("%s using the '%s' Argon2id implementation",
        __func__, Argon2AutoDetect(argon2_implementation::USE_SSE2)));
    RunArgon2idHash(bench);
    Argon2AutoDetect();
}
BENCHMARK(Argon2id_SSE2, benchmark::PriorityLevel::HIGH);
#endif

#if defined(ENABLE_ARGON2_SSSE3)
static void Argon2id_SSSE3(benchmark::Bench& bench)
{
    bench.name(strprintf("%s using the '%s' Argon2id implementation",
        __func__, Argon2AutoDetect(argon2_implementation::USE_SSSE3)));
    RunArgon2idHash(bench);
    Argon2AutoDetect();
}
BENCHMARK(Argon2id_SSSE3, benchmark::PriorityLevel::HIGH);
#endif

#if defined(ENABLE_ARGON2_AVX2)
static void Argon2id_AVX2(benchmark::Bench& bench)
{
    bench.name(strprintf("%s using the '%s' Argon2id implementation",
        __func__, Argon2AutoDetect(argon2_implementation::USE_AVX2)));
    RunArgon2idHash(bench);
    Argon2AutoDetect();
}
BENCHMARK(Argon2id_AVX2, benchmark::PriorityLevel::HIGH);
#endif

#if defined(ENABLE_ARGON2_AVX512)
static void Argon2id_AVX512(benchmark::Bench& bench)
{
    bench.name(strprintf("%s using the '%s' Argon2id implementation",
        __func__, Argon2AutoDetect(argon2_implementation::USE_AVX512)));
    RunArgon2idHash(bench);
    Argon2AutoDetect();
}
BENCHMARK(Argon2id_AVX512, benchmark::PriorityLevel::HIGH);
#endif

/* NEON: AArch64 / ARMv7+NEON - compiled in only on non-x86 builds where
 * introspection.cmake sets HAVE_ARGON2_NEON.  Mutually exclusive with the
 * x86 ISA variants above because HAVE_GETCPUID (cpuid.h) is absent on ARM,
 * so the SSE2/AVX paths are never compiled there anyway. */
#if defined(ENABLE_ARGON2_NEON)
static void Argon2id_NEON(benchmark::Bench& bench)
{
    bench.name(strprintf("%s using the '%s' Argon2id implementation",
        __func__, Argon2AutoDetect(argon2_implementation::USE_NEON)));
    RunArgon2idHash(bench);
    Argon2AutoDetect();
}
BENCHMARK(Argon2id_NEON, benchmark::PriorityLevel::HIGH);
#endif
