// Copyright (c) 2026-present The Bitweb Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <consensus/params.h>
#include <pow.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <util/chaintype.h>

#include <cstdint>

void initialize_permitted_difficulty()
{
    SelectParams(ChainType::MAIN);
}

FUZZ_TARGET(permitted_difficulty_transition, .init = initialize_permitted_difficulty)
{
    FuzzedDataProvider fdp(buffer.data(), buffer.size());
    const Consensus::Params& params = Params().GetConsensus();

    const int64_t  height    = fdp.ConsumeIntegral<int64_t>();
    const uint32_t old_nbits = fdp.ConsumeIntegral<uint32_t>();
    const uint32_t new_nbits = fdp.ConsumeIntegral<uint32_t>();

    // Must never crash on any input combination.
    (void)PermittedDifficultyTransition(params, height, old_nbits, new_nbits);
}
