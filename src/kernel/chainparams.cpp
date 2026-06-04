// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <kernel/chainparams.h>

#include <chainparamsseeds.h>
#include <consensus/amount.h>
#include <consensus/merkle.h>
#include <consensus/params.h>
#include <hash.h>
#include <kernel/messagestartchars.h>
#include <logging.h>
#include <primitives/block.h>
#include <primitives/transaction.h>
#include <script/interpreter.h>
#include <script/script.h>
#include <uint256.h>
#include <util/chaintype.h>
#include <util/strencodings.h>

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <type_traits>

using namespace util::hex_literals;

// Workaround MSVC bug triggering C7595 when calling consteval constructors in
// initializer lists.
// https://developercommunity.visualstudio.com/t/Bogus-C7595-error-on-valid-C20-code/10906093
#if defined(_MSC_VER)
auto consteval_ctor(auto&& input) { return input; }
#else
#define consteval_ctor(input) (input)
#endif

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.version = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "Bitweb Core Blockchain Restart 1775999888";
    const CScript genesisOutputScript = CScript() << "04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f"_hex << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network on which people trade goods and services.
 */
class CMainParams : public CChainParams {
public:
    CMainParams() {
        m_chain_type = ChainType::MAIN;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 420000; // Bitweb Params
        // remove BIP16 and Taproot exception
        /*
        consensus.script_flag_exceptions.emplace( // BIP16 exception
            uint256{"00000000000002dc756eebf4f49723ed8d30cc28a5f108eb94b1ba88ac4f9c22"}, SCRIPT_VERIFY_NONE);
        consensus.script_flag_exceptions.emplace( // Taproot exception
            uint256{"0000000000000000000f14c35b2d841e986ab5441de8c585d5ffe55ea1e395ad"}, SCRIPT_VERIFY_P2SH | SCRIPT_VERIFY_WITNESS);
        */
        consensus.BIP34Height = 1; // Active from the start
        consensus.BIP34Hash = uint256{"06ae146146168b6a9d844df251b9b0eaafbdb1173a9cf29f18014e256d62fb27"};
        consensus.BIP65Height = 1; // Active from the start
        consensus.BIP66Height = 1; // Active from the start
        consensus.CSVHeight = 1; // Active from the start
        consensus.SegwitHeight = 1; // Active from the start
        consensus.MinBIP9WarningHeight = 4032; // don't warn about unknown BIP9 activations below this height
        consensus.powLimit = uint256{"000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
//        consensus.nPowTargetTimespan = 5 * 60; // 5m
        consensus.nPowTargetSpacing = 5 * 60;
        consensus.lwmaAveragingWindow = 576;
//        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 3024; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 4032;

        // Deployment of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 3024; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 4032;

        consensus.nMinimumChainWork = uint256("00000000000000000000000000000000000000000000000000000000158b68cf"); //59782
        consensus.defaultAssumeValid = uint256("b8b609a39fd140217348701382f0b61d2e98a0357eff03177a544f6a24803ab7"); //59782

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0xfe;
        pchMessageStart[1] = 0xae;
        pchMessageStart[2] = 0xd5;
        pchMessageStart[3] = 0xca;
        nDefaultPort = 26333;
        nPruneAfterHeight = 100000;
        m_assumed_blockchain_size = 5;
        m_assumed_chain_state_size = 1;

        genesis = CreateGenesisBlock(1775999888, 199888899, 0x1f0fffff, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256{"111692c1b9b390c407ab74d7f924d4fa0f7589974ab61af96392feca11f209e6"});
        assert(genesis.hashMerkleRoot == uint256{"14dee9b42e7c1893b5c472bd6c8bcb2fe51f797a97369561716d3997b00c08f6"});

        // Note that of those which support the service bits prefix, most only support a subset of
        // possible options.
        // This is fine at runtime as we'll fall back to using them as an addrfetch if they don't support the
        // service bits we want, but we should get them updated to support all service bits wanted by any
        // release ASAP to avoid it where possible.
        vSeeds.emplace_back("seed10.bitwebcore.net.");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,33); // E
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,30); // D
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,128);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        bech32_hrp = "web";

        vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_main), std::end(chainparams_seed_main));

        fDefaultConsistencyChecks = false;
        m_is_mockable_chain = false;

        // Checkpoints restored
        checkpointData = {
            {
                { 0, uint256{"111692c1b9b390c407ab74d7f924d4fa0f7589974ab61af96392feca11f209e6"}},
                { 59782, uint256{"b8b609a39fd140217348701382f0b61d2e98a0357eff03177a544f6a24803ab7"}},
            }
        };
        // Checkpoints restored

        m_assumeutxo_data = {
            {
                .height           = 59782,
                .hash_serialized  = AssumeutxoHash{uint256{"12d31e874fa1f6fb698aabd4121d7f67c794f01b6e14d25368bd6ff6b30bba21"}},
                .m_chain_tx_count = 59864,
                .blockhash        = consteval_ctor(uint256{"b8b609a39fd140217348701382f0b61d2e98a0357eff03177a544f6a24803ab7"}),
            }
        };

        chainTxData = ChainTxData{
            // Data from RPC: getchaintxstats 4096 b8b609a39fd140217348701382f0b61d2e98a0357eff03177a544f6a24803ab7
            .nTime    = 1780502775,
            .tx_count = 59864,
            .dTxRate  = 0.01615854484121918,
        };
    }
};

/**
 * Testnet (v3): public test network which is reset from time to time.
 * Not for use, checkpoint tests require it.
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        m_chain_type = ChainType::TESTNET;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 420000; // Bitweb Params
        // remove BIP16 and Taproot exception
        /*
        consensus.script_flag_exceptions.emplace( // BIP16 exception
            uint256{"00000000dd30457c001f4095d208cc1296b0eed002427aa599874af7a432b105"}, SCRIPT_VERIFY_NONE);
        */
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256{};
        consensus.BIP65Height = 1;
        consensus.BIP66Height = 1;
        consensus.CSVHeight = 1;
        consensus.SegwitHeight = 1;
        consensus.MinBIP9WarningHeight = 4032; // don't warn about unknown BIP9 activations below this height
        consensus.powLimit = uint256{"000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
//        consensus.nPowTargetTimespan = 5 * 60; // 5m
        consensus.nPowTargetSpacing = 5 * 60;
        consensus.lwmaAveragingWindow = 576;
//        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 3024; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 4032;

        // Deployment of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 3024; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 4032;

        consensus.nMinimumChainWork = uint256{};
        consensus.defaultAssumeValid = uint256{};

        pchMessageStart[0] = 0x1b;
        pchMessageStart[1] = 0xcc;
        pchMessageStart[2] = 0x08;
        pchMessageStart[3] = 0x05;
        nDefaultPort = 18333;
        nPruneAfterHeight = 1000;
        m_assumed_blockchain_size = 5;
        m_assumed_chain_state_size = 1;

        genesis = CreateGenesisBlock(1775999889, 38881596, 0x1f0fffff, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256{"d57b558193dd042caa90f3b3b06626cecd47fd0d09ecb7e355ae21f8f64b47b1"});
        assert(genesis.hashMerkleRoot == uint256{"14dee9b42e7c1893b5c472bd6c8bcb2fe51f797a97369561716d3997b00c08f6"});

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
        vSeeds.emplace_back("testnetseed.bitwebcore.net.");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tb";

        vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_test), std::end(chainparams_seed_test));

        fDefaultConsistencyChecks = false;
        m_is_mockable_chain = false;

        // Checkpoints restored
        checkpointData = {
            {
                {2100, uint256{"6c783046dabd145f1e955d29fefe08e19a1d9df0c9a4e24cf3e7b54a421c2607"}},
            }
        };
        // Checkpoints restored

        m_assumeutxo_data = {
        };

        chainTxData = ChainTxData{
            // Data from RPC: getchaintxstats 4096 0000000000000065c6c38258e201971a3fdfcc2ceee0dd6e85a6c022d45dee34
            .nTime    = 0,
            .tx_count = 0,
            .dTxRate  = 0,
        };
    }
};

/**
 * Testnet (v4): public test network which is reset from time to time.
 */
class CTestNet4Params : public CChainParams {
public:
    CTestNet4Params() {
        m_chain_type = ChainType::TESTNET4;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 420000; // Bitweb Params
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256{};
        consensus.BIP65Height = 1;
        consensus.BIP66Height = 1;
        consensus.CSVHeight = 1;
        consensus.SegwitHeight = 1;
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256{"000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
//        consensus.nPowTargetTimespan = 5 * 60; // 5m
        consensus.nPowTargetSpacing = 5 * 60;
        consensus.lwmaAveragingWindow = 288;
//        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;

        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 3024; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 4032;

        // Deployment of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 3024; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 4032;

        consensus.nMinimumChainWork = uint256{};
        consensus.defaultAssumeValid = uint256{};

        pchMessageStart[0] = 0x2c;
        pchMessageStart[1] = 0x22;
        pchMessageStart[2] = 0x3c;
        pchMessageStart[3] = 0xad;
        nDefaultPort = 48333;
        nPruneAfterHeight = 1000;
        m_assumed_blockchain_size = 5;
        m_assumed_chain_state_size = 1;

        const char* testnet4_genesis_msg = "1775999890 TestNet4 Genesis";
        const CScript testnet4_genesis_script = CScript() << "000000000000000000000000000000000000000000000000000000000000000000"_hex << OP_CHECKSIG;
        genesis = CreateGenesisBlock(testnet4_genesis_msg,
                testnet4_genesis_script,
                1775999890,
                99880088,
                0x1f0fffff,
                1,
                50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256{"b80f3f587edbe596c082d4f28a2b3590c10723822b6ff100726e37eac83510a3"});
        assert(genesis.hashMerkleRoot == uint256{"45dc81c6f9bd42e76a06fa810a9704e9a0e0415c50850b68d55a0648f6880616"});

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
        vSeeds.emplace_back("testnet4seed.bitwebcore.net.");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tb";

        vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_testnet4), std::end(chainparams_seed_testnet4));

        fDefaultConsistencyChecks = false;
        m_is_mockable_chain = false;
        // Checkpoints restored
        checkpointData = {
            {
                {0, uint256{"b80f3f587edbe596c082d4f28a2b3590c10723822b6ff100726e37eac83510a3"}},
            }
        };
        // Checkpoints restored

        m_assumeutxo_data = {
        };

        chainTxData = ChainTxData{
            // Data from RPC: getchaintxstats 4096 000000000000000180a58e7fa3b0db84b5ea76377524894f53660d93ac839d9b
            .nTime    = 0,
            .tx_count = 0,
            .dTxRate  = 0,
        };
    }
};

/**
 * Signet: test network with an additional consensus parameter (see BIP325).
 */
class SigNetParams : public CChainParams {
public:
    explicit SigNetParams(const SigNetOptions& options)
    {
        std::vector<uint8_t> bin;
        vFixedSeeds.clear();
        vSeeds.clear();

        if (!options.challenge) {
            bin = "51210289344323689631739c2da6c9c1a31c442289e8dc0b00fd60d7bc041c967522b351ae"_hex_v_u8;
            vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_signet), std::end(chainparams_seed_signet));
            vSeeds.emplace_back("signetseed.bitwebcore.net.");

            consensus.nMinimumChainWork = uint256{};
            consensus.defaultAssumeValid = uint256{};
            m_assumed_blockchain_size = 5;
            m_assumed_chain_state_size = 1;
            chainTxData = ChainTxData{
                // Data from RPC: getchaintxstats 4096 000000128586e26813922680309f04e1de713c7542fee86ed908f56368aefe2e
                .nTime    = 0,
                .tx_count = 0,
                .dTxRate  = 0,
            };
        } else {
            bin = *options.challenge;
            consensus.nMinimumChainWork = uint256{};
            consensus.defaultAssumeValid = uint256{};
            m_assumed_blockchain_size = 0;
            m_assumed_chain_state_size = 0;
            chainTxData = ChainTxData{
                0,
                0,
                0,
            };
            LogInfo("Signet with challenge %s", HexStr(bin));
        }

        if (options.seeds) {
            vSeeds = *options.seeds;
        }

        m_chain_type = ChainType::SIGNET;
        consensus.signet_blocks = true;
        consensus.signet_challenge.assign(bin.begin(), bin.end());
        consensus.nSubsidyHalvingInterval = 420000; // Bitweb Params
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256{};
        consensus.BIP65Height = 1;
        consensus.BIP66Height = 1;
        consensus.CSVHeight = 1;
        consensus.SegwitHeight = 1;
//        consensus.nPowTargetTimespan = 5 * 60; // 5m
        consensus.nPowTargetSpacing = 5 * 60;
        consensus.lwmaAveragingWindow = 576;
//        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256{"00377ae000000000000000000000000000000000000000000000000000000000"};
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 3024; // 90%
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 4032;

        // Activation of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 3024; // 90%
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 4032;

        // message start is defined as the first 4 bytes of the sha256d of the block script
        HashWriter h{};
        h << consensus.signet_challenge;
        uint256 hash = h.GetHash();
        std::copy_n(hash.begin(), 4, pchMessageStart.begin());

        nDefaultPort = 38333;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1775999891, 188999590, 0x1f377ae0, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256{"45d5638308d778ffaed43da140464c7e8c730ef1446d7ed6053ca211be70b35f"});
        assert(genesis.hashMerkleRoot == uint256{"14dee9b42e7c1893b5c472bd6c8bcb2fe51f797a97369561716d3997b00c08f6"});

        m_assumeutxo_data = {
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tb";

        fDefaultConsistencyChecks = false;
        m_is_mockable_chain = false;
    }
};

/**
 * Regression test: intended for private networks only. Has minimal difficulty to ensure that
 * blocks can be found instantly.
 */
class CRegTestParams : public CChainParams
{
public:
    explicit CRegTestParams(const RegTestOptions& opts)
    {
        m_chain_type = ChainType::REGTEST;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 150;
        consensus.BIP34Height = 1; // Always active unless overridden
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 1;  // Always active unless overridden
        consensus.BIP66Height = 1;  // Always active unless overridden
        consensus.CSVHeight = 1;    // Always active unless overridden
        consensus.SegwitHeight = 0; // Always active unless overridden
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256{"7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
//        consensus.nPowTargetTimespan = 5 * 60; // 5m
        consensus.nPowTargetSpacing = 5 * 60;
        consensus.lwmaAveragingWindow = 144;
//        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;

        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 108; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 144; // Faster than normal for regtest (144 instead of 4032)

        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 108; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 144;

        consensus.nMinimumChainWork = uint256{};
        consensus.defaultAssumeValid = uint256{};

        pchMessageStart[0] = 0xea;
        pchMessageStart[1] = 0xb1;
        pchMessageStart[2] = 0xa5;
        pchMessageStart[3] = 0xde;
        nDefaultPort = 18444;
        nPruneAfterHeight = opts.fastprune ? 100 : 1000;
        m_assumed_blockchain_size = 0;
        m_assumed_chain_state_size = 0;

        for (const auto& [dep, height] : opts.activation_heights) {
            switch (dep) {
            case Consensus::BuriedDeployment::DEPLOYMENT_SEGWIT:
                consensus.SegwitHeight = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_HEIGHTINCB:
                consensus.BIP34Height = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_DERSIG:
                consensus.BIP66Height = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_CLTV:
                consensus.BIP65Height = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_CSV:
                consensus.CSVHeight = int{height};
                break;
            }
        }

        for (const auto& [deployment_pos, version_bits_params] : opts.version_bits_parameters) {
            consensus.vDeployments[deployment_pos].nStartTime = version_bits_params.start_time;
            consensus.vDeployments[deployment_pos].nTimeout = version_bits_params.timeout;
            consensus.vDeployments[deployment_pos].min_activation_height = version_bits_params.min_activation_height;
        }

        // The regtest genesis date is set ~5 months before the mainnet date so tests pass.
        // This avoids modifying test logic and does not affect regtest functionality.
        // Otherwise, tests may fail with "time-too-new" errors because they assume
        // a very old genesis block (as in Bitcoin regtest).
        // This is only required when creating a new network from scratch;
        // for existing networks older than 4 months, this step can be skipped.
        genesis = CreateGenesisBlock(1761888888, 999888667, 0x207fffff, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256{"fff478736711da54031b170a3a95739bb06bd0f66518eb82876d1a4b39a261b6"});
        assert(genesis.hashMerkleRoot == uint256{"14dee9b42e7c1893b5c472bd6c8bcb2fe51f797a97369561716d3997b00c08f6"});

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();
        vSeeds.emplace_back("dummySeed.invalid.");

        fDefaultConsistencyChecks = true;
        m_is_mockable_chain = true;

        // Checkpoints restored
        checkpointData = {
            {
                {0, uint256{"fff478736711da54031b170a3a95739bb06bd0f66518eb82876d1a4b39a261b6"}},
            }
        };
        // Checkpoints restored

        m_assumeutxo_data = {
            {   // For use by unit tests
                .height = 110,
                .hash_serialized = AssumeutxoHash{uint256{"b952555c8ab81fec46f3d4253b7af256d766ceb39fb7752b9d18cdf4a0141327"}},
                .m_chain_tx_count = 111,
                .blockhash = consteval_ctor(uint256{"7972426e93174a03b6ead1d7ca13e2b5980a333be9849ef392e57dd4491a8fe6"}),
            },
            {
                // For use by fuzz target src/test/fuzz/utxo_snapshot.cpp
                .height = 200,
                .hash_serialized = AssumeutxoHash{uint256{"17dcc016d188d16068907cdeb38b75691a118d43053b8cd6a25969419381d13a"}},
                .m_chain_tx_count = 201,
                .blockhash = consteval_ctor(uint256{"9740ec10ef5b98d2d86f0ed31df52069f010f1c53bac292c8956d394ccf6c213"}),
            },
            {
                // For use by test/functional/feature_assumeutxo.py
                .height = 299,
                .hash_serialized = AssumeutxoHash{uint256{"d2b051ff5e8eef46520350776f4100dd710a63447a8e01d917e92e79751a63e2"}},
                .m_chain_tx_count = 334,
                .blockhash = consteval_ctor(uint256{"712ff8077413527f5186a1d467bd0ea597f21495dc0b06285623f44195fcb14e"}),
            },
        };

        chainTxData = ChainTxData{
            .nTime = 0,
            .tx_count = 0,
            .dTxRate = 0.001, // Set a non-zero rate to make it testable
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "bcrt";
    }
};

std::unique_ptr<const CChainParams> CChainParams::SigNet(const SigNetOptions& options)
{
    return std::make_unique<const SigNetParams>(options);
}

std::unique_ptr<const CChainParams> CChainParams::RegTest(const RegTestOptions& options)
{
    return std::make_unique<const CRegTestParams>(options);
}

std::unique_ptr<const CChainParams> CChainParams::Main()
{
    return std::make_unique<const CMainParams>();
}

std::unique_ptr<const CChainParams> CChainParams::TestNet()
{
    return std::make_unique<const CTestNetParams>();
}

std::unique_ptr<const CChainParams> CChainParams::TestNet4()
{
    return std::make_unique<const CTestNet4Params>();
}

std::vector<int> CChainParams::GetAvailableSnapshotHeights() const
{
    std::vector<int> heights;
    heights.reserve(m_assumeutxo_data.size());

    for (const auto& data : m_assumeutxo_data) {
        heights.emplace_back(data.height);
    }
    return heights;
}

std::optional<ChainType> GetNetworkForMagic(const MessageStartChars& message)
{
    const auto mainnet_msg = CChainParams::Main()->MessageStart();
    const auto testnet_msg = CChainParams::TestNet()->MessageStart();
    const auto testnet4_msg = CChainParams::TestNet4()->MessageStart();
    const auto regtest_msg = CChainParams::RegTest({})->MessageStart();
    const auto signet_msg = CChainParams::SigNet({})->MessageStart();

    if (std::ranges::equal(message, mainnet_msg)) {
        return ChainType::MAIN;
    } else if (std::ranges::equal(message, testnet_msg)) {
        return ChainType::TESTNET;
    } else if (std::ranges::equal(message, testnet4_msg)) {
        return ChainType::TESTNET4;
    } else if (std::ranges::equal(message, regtest_msg)) {
        return ChainType::REGTEST;
    } else if (std::ranges::equal(message, signet_msg)) {
        return ChainType::SIGNET;
    }
    return std::nullopt;
}
