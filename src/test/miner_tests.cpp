// Copyright (c) 2011-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <addresstype.h>
#include <coins.h>
#include <common/system.h>
#include <consensus/consensus.h>
#include <consensus/merkle.h>
#include <consensus/tx_verify.h>
#include <interfaces/mining.h>
#include <node/miner.h>
#include <policy/policy.h>
#include <test/util/random.h>
#include <test/util/transaction_utils.h>
#include <test/util/txmempool.h>
#include <txmempool.h>
#include <uint256.h>
#include <util/check.h>
#include <util/feefrac.h>
#include <util/strencodings.h>
#include <util/time.h>
#include <util/translation.h>
#include <validation.h>
#include <versionbits.h>
#include <pow.h>

#include <test/util/setup_common.h>

#include <memory>
#include <vector>

#include <boost/test/unit_test.hpp>

using namespace util::hex_literals;
using interfaces::BlockTemplate;
using interfaces::Mining;
using node::BlockAssembler;

namespace miner_tests {
struct MinerTestingSetup : public TestingSetup {
    void TestPackageSelection(const CScript& scriptPubKey, const std::vector<CTransactionRef>& txFirst) EXCLUSIVE_LOCKS_REQUIRED(::cs_main);
    void TestBasicMining(const CScript& scriptPubKey, const std::vector<CTransactionRef>& txFirst, int baseheight) EXCLUSIVE_LOCKS_REQUIRED(::cs_main);
    void TestPrioritisedMining(const CScript& scriptPubKey, const std::vector<CTransactionRef>& txFirst) EXCLUSIVE_LOCKS_REQUIRED(::cs_main);
    bool TestSequenceLocks(const CTransaction& tx, CTxMemPool& tx_mempool) EXCLUSIVE_LOCKS_REQUIRED(::cs_main)
    {
        CCoinsViewMemPool view_mempool{&m_node.chainman->ActiveChainstate().CoinsTip(), tx_mempool};
        CBlockIndex* tip{m_node.chainman->ActiveChain().Tip()};
        const std::optional<LockPoints> lock_points{CalculateLockPointsAtTip(tip, view_mempool, tx)};
        return lock_points.has_value() && CheckSequenceLocksAtTip(tip, *lock_points);
    }
    CTxMemPool& MakeMempool()
    {
        // Delete the previous mempool to ensure with valgrind that the old
        // pointer is not accessed, when the new one should be accessed
        // instead.
        m_node.mempool.reset();
        bilingual_str error;
        m_node.mempool = std::make_unique<CTxMemPool>(MemPoolOptionsForTest(m_node), error);
        Assert(error.empty());
        return *m_node.mempool;
    }
    std::unique_ptr<Mining> MakeMining()
    {
        return interfaces::MakeMining(m_node);
    }
};
} // namespace miner_tests

BOOST_FIXTURE_TEST_SUITE(miner_tests, MinerTestingSetup)

static CFeeRate blockMinFeeRate = CFeeRate(DEFAULT_BLOCK_MIN_TX_FEE);

constexpr static struct {
    unsigned int extranonce;
    unsigned int nonce;
} BLOCKINFO[]{{0, 3552710532},   {500, 37511146},   {1000, 949017974}, {400, 524771889},  {800, 258532269},  {300, 102317106},
              {1300, 54370737},  {600, 1107756570}, {1000, 203099643}, {900, 391192332},  {800, 381184324},  {600, 87200886},
              {0, 66534949},     {800, 874962060},  {1000, 89240281},  {400, 312655606},  {400, 66273984},   {500, 924661281},
              {400, 369925090},  {500, 47657628},   {500, 115050496},  {100, 277039896},  {1100, 809635146}, {700, 155360873},
              {800, 943593865},  {400, 28221796},   {900, 77230802},   {0, 105979012},    {400, 698737686},  {500, 111118097},
              {1300, 445420124}, {500, 621878981},  {1400, 56015364},  {1100, 370685627}, {1200, 380325767}, {1200, 110670025},
              {400, 213799797},  {1500, 120046967}, {1200, 835031015}, {1500, 624837942}, {900, 1412901},    {400, 189434794},
              {400, 293196088},  {1100, 15405422},  {600, 396776054},  {800, 1387079311}, {800, 199370963},  {700, 111503878},
              {100, 129767358},  {200, 536590684},  {500, 125910757},  {500, 101073559},  {1200, 471609330}, {900, 86973436},
              {1200, 179616424}, {600, 68671249},   {1000, 203317788}, {500, 139624459},  {900, 233709931},  {300, 153235787},
              {0, 27643027},     {1200, 9861729},   {100, 220398119},  {200, 66290998},   {1100, 145506104}, {1300, 37869862},
              {400, 5841881},    {1200, 215768702}, {1400, 32374207},  {1400, 6541086},   {500, 143347775},  {800, 905196},
              {700, 159306781},  {400, 123216924},  {700, 44013360},   {300, 304248842},  {700, 214800837},  {1100, 274164931},
              {400, 285641942},  {1100, 923461543}, {600, 12827986},   {1200, 736297744}, {1000, 246690227}, {600, 92966554},
              {1400, 29236012},  {1000, 841340617}, {700, 174322116},  {1400, 214040366}, {1000, 7003628},   {1200, 278241063},
              {700, 540232934},  {400, 93682477},   {1100, 152355301}, {1500, 464197142}, {1300, 333874650}, {600, 258321583},
              {600, 90207043},   {1000, 33638740},  {1500, 332878484}, {100, 204722789},  {1000, 463172903}, {800, 303262510},
              {600, 88120417},   {0, 137487060},    {1200, 195529138}, {300, 704120152},  {900, 292098063},  {1400, 758690433},
              {1300, 163502811}, {1200, 53169014}};

static std::unique_ptr<CBlockIndex> CreateBlockIndex(int nHeight, CBlockIndex* active_chain_tip) EXCLUSIVE_LOCKS_REQUIRED(cs_main)
{
    auto index{std::make_unique<CBlockIndex>()};
    index->nHeight = nHeight;
    index->pprev = active_chain_tip;
    return index;
}

// Test suite for ancestor feerate transaction selection.
// Implemented as an additional function, rather than a separate test case,
// to allow reusing the blockchain created in CreateNewBlock_validity.
void MinerTestingSetup::TestPackageSelection(const CScript& scriptPubKey, const std::vector<CTransactionRef>& txFirst)
{
    CTxMemPool& tx_mempool{MakeMempool()};
    auto mining{MakeMining()};
    BlockAssembler::Options options;
    options.coinbase_output_script = scriptPubKey;

    LOCK(tx_mempool.cs);
    BOOST_CHECK(tx_mempool.size() == 0);

    // Block template should only have a coinbase when there's nothing in the mempool
    std::unique_ptr<BlockTemplate> block_template = mining->createNewBlock(options);
    BOOST_REQUIRE(block_template);
    CBlock block{block_template->getBlock()};
    BOOST_REQUIRE_EQUAL(block.vtx.size(), 1U);

    // waitNext() on an empty mempool should return nullptr because there is no better template
    auto should_be_nullptr = block_template->waitNext({.timeout = MillisecondsDouble{0}, .fee_threshold = 1});
    BOOST_REQUIRE(should_be_nullptr == nullptr);

    // Unless fee_threshold is 0
    block_template = block_template->waitNext({.timeout = MillisecondsDouble{0}, .fee_threshold = 0});
    BOOST_REQUIRE(block_template);

    // Test the ancestor feerate transaction selection.
    TestMemPoolEntryHelper entry;

    // Test that a medium fee transaction will be selected after a higher fee
    // rate package with a low fee rate parent.
    CMutableTransaction tx;
    tx.vin.resize(1);
    tx.vin[0].scriptSig = CScript() << OP_1;
    tx.vin[0].prevout.hash = txFirst[0]->GetHash();
    tx.vin[0].prevout.n = 0;
    tx.vout.resize(1);
    tx.vout[0].nValue = 5000000000LL - 1000;
    // This tx has a low fee: 1000 satoshis
    Txid hashParentTx = tx.GetHash(); // save this txid for later use
    const auto parent_tx{entry.Fee(1000).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx)};
    AddToMempool(tx_mempool, parent_tx);

    // This tx has a medium fee: 10000 satoshis
    tx.vin[0].prevout.hash = txFirst[1]->GetHash();
    tx.vout[0].nValue = 5000000000LL - 10000;
    Txid hashMediumFeeTx = tx.GetHash();
    const auto medium_fee_tx{entry.Fee(10000).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx)};
    AddToMempool(tx_mempool, medium_fee_tx);

    // This tx has a high fee, but depends on the first transaction
    tx.vin[0].prevout.hash = hashParentTx;
    tx.vout[0].nValue = 5000000000LL - 1000 - 50000; // 50k satoshi fee
    Txid hashHighFeeTx = tx.GetHash();
    const auto high_fee_tx{entry.Fee(50000).Time(Now<NodeSeconds>()).SpendsCoinbase(false).FromTx(tx)};
    AddToMempool(tx_mempool, high_fee_tx);

    block_template = mining->createNewBlock(options);
    BOOST_REQUIRE(block_template);
    block = block_template->getBlock();
    BOOST_REQUIRE_EQUAL(block.vtx.size(), 4U);
    BOOST_CHECK(block.vtx[1]->GetHash() == hashParentTx);
    BOOST_CHECK(block.vtx[2]->GetHash() == hashHighFeeTx);
    BOOST_CHECK(block.vtx[3]->GetHash() == hashMediumFeeTx);

    // Test the inclusion of package feerates in the block template and ensure they are sequential.
    const auto block_package_feerates = BlockAssembler{m_node.chainman->ActiveChainstate(), &tx_mempool, options}.CreateNewBlock()->m_package_feerates;
    BOOST_CHECK(block_package_feerates.size() == 2);

    // parent_tx and high_fee_tx are added to the block as a package.
    const auto combined_txs_fee = parent_tx.GetFee() + high_fee_tx.GetFee();
    const auto combined_txs_size = parent_tx.GetTxSize() + high_fee_tx.GetTxSize();
    FeeFrac package_feefrac{combined_txs_fee, combined_txs_size};
    // The package should be added first.
    BOOST_CHECK(block_package_feerates[0] == package_feefrac);

    // The medium_fee_tx should be added next.
    FeeFrac medium_tx_feefrac{medium_fee_tx.GetFee(), medium_fee_tx.GetTxSize()};
    BOOST_CHECK(block_package_feerates[1] == medium_tx_feefrac);

    // Test that a package below the block min tx fee doesn't get included
    tx.vin[0].prevout.hash = hashHighFeeTx;
    tx.vout[0].nValue = 5000000000LL - 1000 - 50000; // 0 fee
    Txid hashFreeTx = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(0).FromTx(tx));
    size_t freeTxSize = ::GetSerializeSize(TX_WITH_WITNESS(tx));

    // Calculate a fee on child transaction that will put the package just
    // below the block min tx fee (assuming 1 child tx of the same size).
    CAmount feeToUse = blockMinFeeRate.GetFee(2*freeTxSize) - 1;

    tx.vin[0].prevout.hash = hashFreeTx;
    tx.vout[0].nValue = 5000000000LL - 1000 - 50000 - feeToUse;
    Txid hashLowFeeTx = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(feeToUse).FromTx(tx));

    // waitNext() should return nullptr because there is no better template
    should_be_nullptr = block_template->waitNext({.timeout = MillisecondsDouble{0}, .fee_threshold = 1});
    BOOST_REQUIRE(should_be_nullptr == nullptr);

    block = block_template->getBlock();
    // Verify that the free tx and the low fee tx didn't get selected
    for (size_t i=0; i<block.vtx.size(); ++i) {
        BOOST_CHECK(block.vtx[i]->GetHash() != hashFreeTx);
        BOOST_CHECK(block.vtx[i]->GetHash() != hashLowFeeTx);
    }

    // Test that packages above the min relay fee do get included, even if one
    // of the transactions is below the min relay fee
    // Remove the low fee transaction and replace with a higher fee transaction
    tx_mempool.removeRecursive(CTransaction(tx), MemPoolRemovalReason::REPLACED);
    tx.vout[0].nValue -= 2; // Now we should be just over the min relay fee
    hashLowFeeTx = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(feeToUse + 2).FromTx(tx));

    // waitNext() should return if fees for the new template are at least 1 sat up
    block_template = block_template->waitNext({.fee_threshold = 1});
    BOOST_REQUIRE(block_template);
    block = block_template->getBlock();
    BOOST_REQUIRE_EQUAL(block.vtx.size(), 6U);
    BOOST_CHECK(block.vtx[4]->GetHash() == hashFreeTx);
    BOOST_CHECK(block.vtx[5]->GetHash() == hashLowFeeTx);

    // Test that transaction selection properly updates ancestor fee
    // calculations as ancestor transactions get included in a block.
    // Add a 0-fee transaction that has 2 outputs.
    tx.vin[0].prevout.hash = txFirst[2]->GetHash();
    tx.vout.resize(2);
    tx.vout[0].nValue = 5000000000LL - 100000000;
    tx.vout[1].nValue = 100000000; // 1BTC output
    // Increase size to avoid rounding errors: when the feerate is extremely small (i.e. 1sat/kvB), evaluating the fee
    // at smaller sizes gives us rounded values that are equal to each other, which means we incorrectly include
    // hashFreeTx2 + hashLowFeeTx2.
    BulkTransaction(tx, 4000);
    Txid hashFreeTx2 = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(0).SpendsCoinbase(true).FromTx(tx));

    // This tx can't be mined by itself
    tx.vin[0].prevout.hash = hashFreeTx2;
    tx.vout.resize(1);
    feeToUse = blockMinFeeRate.GetFee(freeTxSize);
    tx.vout[0].nValue = 5000000000LL - 100000000 - feeToUse;
    Txid hashLowFeeTx2 = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(feeToUse).SpendsCoinbase(false).FromTx(tx));
    block_template = mining->createNewBlock(options);
    BOOST_REQUIRE(block_template);
    block = block_template->getBlock();

    // Verify that this tx isn't selected.
    for (size_t i=0; i<block.vtx.size(); ++i) {
        BOOST_CHECK(block.vtx[i]->GetHash() != hashFreeTx2);
        BOOST_CHECK(block.vtx[i]->GetHash() != hashLowFeeTx2);
    }

    // This tx will be mineable, and should cause hashLowFeeTx2 to be selected
    // as well.
    tx.vin[0].prevout.n = 1;
    tx.vout[0].nValue = 100000000 - 10000; // 10k satoshi fee
    AddToMempool(tx_mempool, entry.Fee(10000).FromTx(tx));
    block_template = mining->createNewBlock(options);
    BOOST_REQUIRE(block_template);
    block = block_template->getBlock();
    BOOST_REQUIRE_EQUAL(block.vtx.size(), 9U);
    BOOST_CHECK(block.vtx[8]->GetHash() == hashLowFeeTx2);
}

void MinerTestingSetup::TestBasicMining(const CScript& scriptPubKey, const std::vector<CTransactionRef>& txFirst, int baseheight)
{
    Txid hash;
    CMutableTransaction tx;
    TestMemPoolEntryHelper entry;
    entry.nFee = 11;
    entry.nHeight = 11;

    const CAmount BLOCKSUBSIDY = 50 * COIN;
    const CAmount LOWFEE = CENT;
    const CAmount HIGHFEE = COIN;
    const CAmount HIGHERFEE = 4 * COIN;

    auto mining{MakeMining()};
    BOOST_REQUIRE(mining);

    BlockAssembler::Options options;
    options.coinbase_output_script = scriptPubKey;

    {
        CTxMemPool& tx_mempool{MakeMempool()};
        LOCK(tx_mempool.cs);

        // Just to make sure we can still make simple blocks
        auto block_template{mining->createNewBlock(options)};
        BOOST_REQUIRE(block_template);
        CBlock block{block_template->getBlock()};

        // block sigops > limit: 1000 CHECKMULTISIG + 1
        tx.vin.resize(1);
        // NOTE: OP_NOP is used to force 20 SigOps for the CHECKMULTISIG
        tx.vin[0].scriptSig = CScript() << OP_0 << OP_0 << OP_0 << OP_NOP << OP_CHECKMULTISIG << OP_1;
        tx.vin[0].prevout.hash = txFirst[0]->GetHash();
        tx.vin[0].prevout.n = 0;
        tx.vout.resize(1);
        tx.vout[0].nValue = BLOCKSUBSIDY;
        for (unsigned int i = 0; i < 1001; ++i) {
            tx.vout[0].nValue -= LOWFEE;
            hash = tx.GetHash();
            bool spendsCoinbase = i == 0; // only first tx spends coinbase
            // If we don't set the # of sig ops in the CTxMemPoolEntry, template creation fails
            AddToMempool(tx_mempool, entry.Fee(LOWFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(spendsCoinbase).FromTx(tx));
            tx.vin[0].prevout.hash = hash;
        }

        BOOST_CHECK_EXCEPTION(mining->createNewBlock(options), std::runtime_error, HasReason("bad-blk-sigops"));
    }

    {
        CTxMemPool& tx_mempool{MakeMempool()};
        LOCK(tx_mempool.cs);

        tx.vin[0].prevout.hash = txFirst[0]->GetHash();
        tx.vout[0].nValue = BLOCKSUBSIDY;
        for (unsigned int i = 0; i < 1001; ++i) {
            tx.vout[0].nValue -= LOWFEE;
            hash = tx.GetHash();
            bool spendsCoinbase = i == 0; // only first tx spends coinbase
            // If we do set the # of sig ops in the CTxMemPoolEntry, template creation passes
            AddToMempool(tx_mempool, entry.Fee(LOWFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(spendsCoinbase).SigOpsCost(80).FromTx(tx));
            tx.vin[0].prevout.hash = hash;
        }
        BOOST_REQUIRE(mining->createNewBlock(options));
    }

    {
        CTxMemPool& tx_mempool{MakeMempool()};
        LOCK(tx_mempool.cs);

        // block size > limit
        tx.vin[0].scriptSig = CScript();
        // 18 * (520char + DROP) + OP_1 = 9433 bytes
        std::vector<unsigned char> vchData(520);
        for (unsigned int i = 0; i < 18; ++i) {
            tx.vin[0].scriptSig << vchData << OP_DROP;
        }
        tx.vin[0].scriptSig << OP_1;
        tx.vin[0].prevout.hash = txFirst[0]->GetHash();
        tx.vout[0].nValue = BLOCKSUBSIDY;
        for (unsigned int i = 0; i < 128; ++i) {
            tx.vout[0].nValue -= LOWFEE;
            hash = tx.GetHash();
            bool spendsCoinbase = i == 0; // only first tx spends coinbase
            AddToMempool(tx_mempool, entry.Fee(LOWFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(spendsCoinbase).FromTx(tx));
            tx.vin[0].prevout.hash = hash;
        }
        BOOST_REQUIRE(mining->createNewBlock(options));
    }

    {
        CTxMemPool& tx_mempool{MakeMempool()};
        LOCK(tx_mempool.cs);

        // orphan in tx_mempool, template creation fails
        hash = tx.GetHash();
        AddToMempool(tx_mempool, entry.Fee(LOWFEE).Time(Now<NodeSeconds>()).FromTx(tx));
        BOOST_CHECK_EXCEPTION(mining->createNewBlock(options), std::runtime_error, HasReason("bad-txns-inputs-missingorspent"));
    }

    {
        CTxMemPool& tx_mempool{MakeMempool()};
        LOCK(tx_mempool.cs);

        // child with higher feerate than parent
        tx.vin[0].scriptSig = CScript() << OP_1;
        tx.vin[0].prevout.hash = txFirst[1]->GetHash();
        tx.vout[0].nValue = BLOCKSUBSIDY - HIGHFEE;
        hash = tx.GetHash();
        AddToMempool(tx_mempool, entry.Fee(HIGHFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx));
        tx.vin[0].prevout.hash = hash;
        tx.vin.resize(2);
        tx.vin[1].scriptSig = CScript() << OP_1;
        tx.vin[1].prevout.hash = txFirst[0]->GetHash();
        tx.vin[1].prevout.n = 0;
        tx.vout[0].nValue = tx.vout[0].nValue + BLOCKSUBSIDY - HIGHERFEE; // First txn output + fresh coinbase - new txn fee
        hash = tx.GetHash();
        AddToMempool(tx_mempool, entry.Fee(HIGHERFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx));
        BOOST_REQUIRE(mining->createNewBlock(options));
    }

    {
        CTxMemPool& tx_mempool{MakeMempool()};
        LOCK(tx_mempool.cs);

        // coinbase in tx_mempool, template creation fails
        tx.vin.resize(1);
        tx.vin[0].prevout.SetNull();
        tx.vin[0].scriptSig = CScript() << OP_0 << OP_1;
        tx.vout[0].nValue = 0;
        hash = tx.GetHash();
        // give it a fee so it'll get mined
        AddToMempool(tx_mempool, entry.Fee(LOWFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(false).FromTx(tx));
        // Should throw bad-cb-multiple
        BOOST_CHECK_EXCEPTION(mining->createNewBlock(options), std::runtime_error, HasReason("bad-cb-multiple"));
    }

    {
        CTxMemPool& tx_mempool{MakeMempool()};
        LOCK(tx_mempool.cs);

        // double spend txn pair in tx_mempool, template creation fails
        tx.vin[0].prevout.hash = txFirst[0]->GetHash();
        tx.vin[0].scriptSig = CScript() << OP_1;
        tx.vout[0].nValue = BLOCKSUBSIDY - HIGHFEE;
        tx.vout[0].scriptPubKey = CScript() << OP_1;
        hash = tx.GetHash();
        AddToMempool(tx_mempool, entry.Fee(HIGHFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx));
        tx.vout[0].scriptPubKey = CScript() << OP_2;
        hash = tx.GetHash();
        AddToMempool(tx_mempool, entry.Fee(HIGHFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx));
        BOOST_CHECK_EXCEPTION(mining->createNewBlock(options), std::runtime_error, HasReason("bad-txns-inputs-missingorspent"));
    }

    {
        CTxMemPool& tx_mempool{MakeMempool()};
        LOCK(tx_mempool.cs);

        // subsidy changing
        int nHeight = m_node.chainman->ActiveChain().Height();
        // Create an actual 209999-long block chain (without valid blocks).
        while (m_node.chainman->ActiveChain().Tip()->nHeight < 419999) {
            CBlockIndex* prev = m_node.chainman->ActiveChain().Tip();
            CBlockIndex* next = new CBlockIndex();
            next->phashBlock = new uint256(m_rng.rand256());
            m_node.chainman->ActiveChainstate().CoinsTip().SetBestBlock(next->GetBlockHash());
            next->pprev = prev;
            next->nHeight = prev->nHeight + 1;
            next->BuildSkip();
            m_node.chainman->ActiveChain().SetTip(*next);
        }
        BOOST_REQUIRE(mining->createNewBlock(options));
        // Extend to a 210000-long block chain.
        while (m_node.chainman->ActiveChain().Tip()->nHeight < 420000) {
            CBlockIndex* prev = m_node.chainman->ActiveChain().Tip();
            CBlockIndex* next = new CBlockIndex();
            next->phashBlock = new uint256(m_rng.rand256());
            m_node.chainman->ActiveChainstate().CoinsTip().SetBestBlock(next->GetBlockHash());
            next->pprev = prev;
            next->nHeight = prev->nHeight + 1;
            next->BuildSkip();
            m_node.chainman->ActiveChain().SetTip(*next);
        }
        BOOST_REQUIRE(mining->createNewBlock(options));

        // invalid p2sh txn in tx_mempool, template creation fails
        tx.vin[0].prevout.hash = txFirst[0]->GetHash();
        tx.vin[0].prevout.n = 0;
        tx.vin[0].scriptSig = CScript() << OP_1;
        tx.vout[0].nValue = BLOCKSUBSIDY - LOWFEE;
        CScript script = CScript() << OP_0;
        tx.vout[0].scriptPubKey = GetScriptForDestination(ScriptHash(script));
        hash = tx.GetHash();
        AddToMempool(tx_mempool, entry.Fee(LOWFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx));
        tx.vin[0].prevout.hash = hash;
        tx.vin[0].scriptSig = CScript() << std::vector<unsigned char>(script.begin(), script.end());
        tx.vout[0].nValue -= LOWFEE;
        hash = tx.GetHash();
        AddToMempool(tx_mempool, entry.Fee(LOWFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(false).FromTx(tx));
        BOOST_CHECK_EXCEPTION(mining->createNewBlock(options), std::runtime_error, HasReason("block-script-verify-flag-failed"));

        // Delete the dummy blocks again.
        while (m_node.chainman->ActiveChain().Tip()->nHeight > nHeight) {
            CBlockIndex* del = m_node.chainman->ActiveChain().Tip();
            m_node.chainman->ActiveChain().SetTip(*Assert(del->pprev));
            m_node.chainman->ActiveChainstate().CoinsTip().SetBestBlock(del->pprev->GetBlockHash());
            delete del->phashBlock;
            delete del;
        }
    }

    CTxMemPool& tx_mempool{MakeMempool()};
    LOCK(tx_mempool.cs);

    // non-final txs in mempool
    SetMockTime(m_node.chainman->ActiveChain().Tip()->GetMedianTimePast() + 1);
    const int flags{LOCKTIME_VERIFY_SEQUENCE};
    // height map
    std::vector<int> prevheights;

    // Guard: BIP68/CSV must be active from block 1. If CSVHeight is not 1,
    // createNewBlock will NOT throw bad-txns-nonfinal in the check below and
    // Boost will only print "exception expected but not raised" with no context.
    // This message tells the developer exactly what chainparam is misconfigured.
    const auto& consensus{m_node.chainman->GetParams().GetConsensus()};
    BOOST_REQUIRE_MESSAGE(consensus.CSVHeight <= 1,
        strprintf("CSVHeight must be 1 for this test (got %d). "
                  "BIP68/CSV must be active from block 1 so that "
                  "createNewBlock rejects a non-BIP68-final transaction with "
                  "bad-txns-nonfinal at current tip height %d.",
                  consensus.CSVHeight,
                  m_node.chainman->ActiveChain().Tip()->nHeight));

    // relative height locked
    tx.version = 2;
    tx.vin.resize(1);
    prevheights.resize(1);
    tx.vin[0].prevout.hash = txFirst[0]->GetHash(); // only 1 transaction
    tx.vin[0].prevout.n = 0;
    tx.vin[0].scriptSig = CScript() << OP_1;
    tx.vin[0].nSequence = m_node.chainman->ActiveChain().Tip()->nHeight + 1; // txFirst[0] is the 2nd block
    prevheights[0] = baseheight + 1;
    tx.vout.resize(1);
    tx.vout[0].nValue = BLOCKSUBSIDY-HIGHFEE;
    tx.vout[0].scriptPubKey = CScript() << OP_1;
    tx.nLockTime = 0;
    hash = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(HIGHFEE).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx));
    BOOST_CHECK(CheckFinalTxAtTip(*Assert(m_node.chainman->ActiveChain().Tip()), CTransaction{tx})); // Locktime passes
    BOOST_CHECK(!TestSequenceLocks(CTransaction{tx}, tx_mempool)); // Sequence locks fail

    {
        CBlockIndex* active_chain_tip = m_node.chainman->ActiveChain().Tip();
        BOOST_CHECK(SequenceLocks(CTransaction(tx), flags, prevheights, *CreateBlockIndex(active_chain_tip->nHeight + 2, active_chain_tip))); // Sequence locks pass on 2nd block
    }

    // relative time locked
    tx.vin[0].prevout.hash = txFirst[1]->GetHash();
    tx.vin[0].nSequence = CTxIn::SEQUENCE_LOCKTIME_TYPE_FLAG | (((m_node.chainman->ActiveChain().Tip()->GetMedianTimePast()+1-m_node.chainman->ActiveChain()[1]->GetMedianTimePast()) >> CTxIn::SEQUENCE_LOCKTIME_GRANULARITY) + 1); // txFirst[1] is the 3rd block
    prevheights[0] = baseheight + 2;
    hash = tx.GetHash();
    AddToMempool(tx_mempool, entry.Time(Now<NodeSeconds>()).FromTx(tx));
    BOOST_CHECK(CheckFinalTxAtTip(*Assert(m_node.chainman->ActiveChain().Tip()), CTransaction{tx})); // Locktime passes
    BOOST_CHECK(!TestSequenceLocks(CTransaction{tx}, tx_mempool)); // Sequence locks fail

    const int SEQUENCE_LOCK_TIME = 512; // Sequence locks pass 512 seconds later
    for (int i = 0; i < CBlockIndex::nMedianTimeSpan; ++i)
        m_node.chainman->ActiveChain().Tip()->GetAncestor(m_node.chainman->ActiveChain().Tip()->nHeight - i)->nTime += SEQUENCE_LOCK_TIME; // Trick the MedianTimePast
    {
        CBlockIndex* active_chain_tip = m_node.chainman->ActiveChain().Tip();
        BOOST_CHECK(SequenceLocks(CTransaction(tx), flags, prevheights, *CreateBlockIndex(active_chain_tip->nHeight + 1, active_chain_tip)));
    }

    for (int i = 0; i < CBlockIndex::nMedianTimeSpan; ++i) {
        CBlockIndex* ancestor{Assert(m_node.chainman->ActiveChain().Tip()->GetAncestor(m_node.chainman->ActiveChain().Tip()->nHeight - i))};
        ancestor->nTime -= SEQUENCE_LOCK_TIME; // undo tricked MTP
    }

    // absolute height locked
    tx.vin[0].prevout.hash = txFirst[2]->GetHash();
    tx.vin[0].nSequence = CTxIn::MAX_SEQUENCE_NONFINAL;
    prevheights[0] = baseheight + 3;
    tx.nLockTime = m_node.chainman->ActiveChain().Tip()->nHeight + 1;
    hash = tx.GetHash();
    AddToMempool(tx_mempool, entry.Time(Now<NodeSeconds>()).FromTx(tx));
    BOOST_CHECK(!CheckFinalTxAtTip(*Assert(m_node.chainman->ActiveChain().Tip()), CTransaction{tx})); // Locktime fails
    BOOST_CHECK(TestSequenceLocks(CTransaction{tx}, tx_mempool)); // Sequence locks pass
    BOOST_CHECK(IsFinalTx(CTransaction(tx), m_node.chainman->ActiveChain().Tip()->nHeight + 2, m_node.chainman->ActiveChain().Tip()->GetMedianTimePast())); // Locktime passes on 2nd block

    // ensure tx is final for a specific case where there is no locktime and block height is zero
    tx.nLockTime = 0;
    BOOST_CHECK(IsFinalTx(CTransaction(tx), /*nBlockHeight=*/0, m_node.chainman->ActiveChain().Tip()->GetMedianTimePast()));

    // absolute time locked
    tx.vin[0].prevout.hash = txFirst[3]->GetHash();
    tx.nLockTime = m_node.chainman->ActiveChain().Tip()->GetMedianTimePast();
    prevheights.resize(1);
    prevheights[0] = baseheight + 4;
    hash = tx.GetHash();
    AddToMempool(tx_mempool, entry.Time(Now<NodeSeconds>()).FromTx(tx));
    BOOST_CHECK(!CheckFinalTxAtTip(*Assert(m_node.chainman->ActiveChain().Tip()), CTransaction{tx})); // Locktime fails
    BOOST_CHECK(TestSequenceLocks(CTransaction{tx}, tx_mempool)); // Sequence locks pass
    BOOST_CHECK(IsFinalTx(CTransaction(tx), m_node.chainman->ActiveChain().Tip()->nHeight + 2, m_node.chainman->ActiveChain().Tip()->GetMedianTimePast() + 1)); // Locktime passes 1 second later

    // mempool-dependent transactions (not added)
    tx.vin[0].prevout.hash = hash;
    prevheights[0] = m_node.chainman->ActiveChain().Tip()->nHeight + 1;
    tx.nLockTime = 0;
    tx.vin[0].nSequence = 0;
    BOOST_CHECK(CheckFinalTxAtTip(*Assert(m_node.chainman->ActiveChain().Tip()), CTransaction{tx})); // Locktime passes
    BOOST_CHECK(TestSequenceLocks(CTransaction{tx}, tx_mempool)); // Sequence locks pass
    tx.vin[0].nSequence = 1;
    BOOST_CHECK(!TestSequenceLocks(CTransaction{tx}, tx_mempool)); // Sequence locks fail
    tx.vin[0].nSequence = CTxIn::SEQUENCE_LOCKTIME_TYPE_FLAG;
    BOOST_CHECK(TestSequenceLocks(CTransaction{tx}, tx_mempool)); // Sequence locks pass
    tx.vin[0].nSequence = CTxIn::SEQUENCE_LOCKTIME_TYPE_FLAG | 1;
    BOOST_CHECK(!TestSequenceLocks(CTransaction{tx}, tx_mempool)); // Sequence locks fail

    // BIP68 enforcement check (locked state): BlockAssembler includes the two
    // relative-locked txs via stale LockPoints (lp.height=0 <= tip=110 passes
    // TestLockPointValidity). TestBlockValidity then detects they are BIP68-non-final
    // at the current height and rejects the block. The two absolute-locked txs are
    // already excluded by IsFinalTx before reaching BIP68 checks.
    // Regression signal: if this exception stops being thrown, BIP68 is broken.
    BOOST_CHECK_EXCEPTION(mining->createNewBlock(options), std::runtime_error, HasReason("bad-txns-nonfinal"));

    // Advance height by 1 and MTP by SEQUENCE_LOCK_TIME so all four locked txs
    // become final. The relative-locked txs are already in the mempool from the
    // AddToMempool calls above and do not need to be re-added.
    // At new tip height 111 (next block = 112):
    //   relHeight : prevheight(1) + nSequence(111) = 112 <= 112  -> BIP68-final
    //   relTime   : MTP advanced by SEQUENCE_LOCK_TIME            -> BIP68-final
    //   absHeight : nLockTime=111 < 112                           -> IsFinalTx passes
    //   absTime   : nLockTime <= new MTP                          -> IsFinalTx passes
    for (int i = 0; i < CBlockIndex::nMedianTimeSpan; ++i) {
        CBlockIndex* ancestor{Assert(m_node.chainman->ActiveChain().Tip()->GetAncestor(m_node.chainman->ActiveChain().Tip()->nHeight - i))};
        ancestor->nTime += SEQUENCE_LOCK_TIME; // Trick the MedianTimePast
    }
    m_node.chainman->ActiveChain().Tip()->nHeight++;
    SetMockTime(m_node.chainman->ActiveChain().Tip()->GetMedianTimePast() + 1);

    // Unlocked state: all four txs are now final and must appear in the template.
    auto block_template = mining->createNewBlock(options);
    BOOST_REQUIRE(block_template);
    CBlock block{block_template->getBlock()};
    BOOST_CHECK_EQUAL(block.vtx.size(), 5U);
}

void MinerTestingSetup::TestPrioritisedMining(const CScript& scriptPubKey, const std::vector<CTransactionRef>& txFirst)
{
    auto mining{MakeMining()};
    BOOST_REQUIRE(mining);

    BlockAssembler::Options options;
    options.coinbase_output_script = scriptPubKey;

    CTxMemPool& tx_mempool{MakeMempool()};
    LOCK(tx_mempool.cs);

    TestMemPoolEntryHelper entry;

    // Test that a tx below min fee but prioritised is included
    CMutableTransaction tx;
    tx.vin.resize(1);
    tx.vin[0].prevout.hash = txFirst[0]->GetHash();
    tx.vin[0].prevout.n = 0;
    tx.vin[0].scriptSig = CScript() << OP_1;
    tx.vout.resize(1);
    tx.vout[0].nValue = 5000000000LL; // 0 fee
    Txid hashFreePrioritisedTx = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(0).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx));
    tx_mempool.PrioritiseTransaction(hashFreePrioritisedTx, 5 * COIN);

    tx.vin[0].prevout.hash = txFirst[1]->GetHash();
    tx.vin[0].prevout.n = 0;
    tx.vout[0].nValue = 5000000000LL - 1000;
    // This tx has a low fee: 1000 satoshis
    Txid hashParentTx = tx.GetHash(); // save this txid for later use
    AddToMempool(tx_mempool, entry.Fee(1000).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx));

    // This tx has a medium fee: 10000 satoshis
    tx.vin[0].prevout.hash = txFirst[2]->GetHash();
    tx.vout[0].nValue = 5000000000LL - 10000;
    Txid hashMediumFeeTx = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(10000).Time(Now<NodeSeconds>()).SpendsCoinbase(true).FromTx(tx));
    tx_mempool.PrioritiseTransaction(hashMediumFeeTx, -5 * COIN);

    // This tx also has a low fee, but is prioritised
    tx.vin[0].prevout.hash = hashParentTx;
    tx.vout[0].nValue = 5000000000LL - 1000 - 1000; // 1000 satoshi fee
    Txid hashPrioritsedChild = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(1000).Time(Now<NodeSeconds>()).SpendsCoinbase(false).FromTx(tx));
    tx_mempool.PrioritiseTransaction(hashPrioritsedChild, 2 * COIN);

    // Test that transaction selection properly updates ancestor fee calculations as prioritised
    // parents get included in a block. Create a transaction with two prioritised ancestors, each
    // included by itself: FreeParent <- FreeChild <- FreeGrandchild.
    // When FreeParent is added, a modified entry will be created for FreeChild + FreeGrandchild
    // FreeParent's prioritisation should not be included in that entry.
    // When FreeChild is included, FreeChild's prioritisation should also not be included.
    tx.vin[0].prevout.hash = txFirst[3]->GetHash();
    tx.vout[0].nValue = 5000000000LL; // 0 fee
    Txid hashFreeParent = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(0).SpendsCoinbase(true).FromTx(tx));
    tx_mempool.PrioritiseTransaction(hashFreeParent, 10 * COIN);

    tx.vin[0].prevout.hash = hashFreeParent;
    tx.vout[0].nValue = 5000000000LL; // 0 fee
    Txid hashFreeChild = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(0).SpendsCoinbase(false).FromTx(tx));
    tx_mempool.PrioritiseTransaction(hashFreeChild, 1 * COIN);

    tx.vin[0].prevout.hash = hashFreeChild;
    tx.vout[0].nValue = 5000000000LL; // 0 fee
    Txid hashFreeGrandchild = tx.GetHash();
    AddToMempool(tx_mempool, entry.Fee(0).SpendsCoinbase(false).FromTx(tx));

    auto block_template = mining->createNewBlock(options);
    BOOST_REQUIRE(block_template);
    CBlock block{block_template->getBlock()};
    BOOST_REQUIRE_EQUAL(block.vtx.size(), 6U);
    BOOST_CHECK(block.vtx[1]->GetHash() == hashFreeParent);
    BOOST_CHECK(block.vtx[2]->GetHash() == hashFreePrioritisedTx);
    BOOST_CHECK(block.vtx[3]->GetHash() == hashParentTx);
    BOOST_CHECK(block.vtx[4]->GetHash() == hashPrioritsedChild);
    BOOST_CHECK(block.vtx[5]->GetHash() == hashFreeChild);
    for (size_t i=0; i<block.vtx.size(); ++i) {
        // The FreeParent and FreeChild's prioritisations should not impact the child.
        BOOST_CHECK(block.vtx[i]->GetHash() != hashFreeGrandchild);
        // De-prioritised transaction should not be included.
        BOOST_CHECK(block.vtx[i]->GetHash() != hashMediumFeeTx);
    }
}

// NOTE: These tests rely on CreateNewBlock doing its own self-validation!
BOOST_AUTO_TEST_CASE(CreateNewBlock_validity)
{
    auto mining{MakeMining()};
    BOOST_REQUIRE(mining);

    // Note that by default, these tests run with size accounting enabled.
    CScript scriptPubKey = CScript() << "04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f"_hex << OP_CHECKSIG;
    BlockAssembler::Options options;
    options.coinbase_output_script = scriptPubKey;

    // Create and check a simple template
    std::unique_ptr<BlockTemplate> block_template = mining->createNewBlock(options);
    BOOST_REQUIRE(block_template);
    {
        CBlock block{block_template->getBlock()};
        {
            std::string reason;
            std::string debug;
            BOOST_REQUIRE(!mining->checkBlock(block, {.check_pow = false}, reason, debug));
            BOOST_REQUIRE_EQUAL(reason, "bad-txnmrklroot");
            BOOST_REQUIRE_EQUAL(debug, "hashMerkleRoot mismatch");
        }

        block.hashMerkleRoot = BlockMerkleRoot(block);

        {
            std::string reason;
            std::string debug;
            BOOST_REQUIRE(mining->checkBlock(block, {.check_pow = false}, reason, debug));
            BOOST_REQUIRE_EQUAL(reason, "");
            BOOST_REQUIRE_EQUAL(debug, "");
        }

        {
            // A block template does not have proof-of-work, but it might pass
            // verification by coincidence. Grind the nonce if needed:
            while (CheckProofOfWork(block.GetArgon2idPoWHash(), block.nBits, Assert(m_node.chainman)->GetParams().GetConsensus())) {
                block.nNonce++;
            }

            std::string reason;
            std::string debug;
            BOOST_REQUIRE(!mining->checkBlock(block, {.check_pow = true}, reason, debug));
            BOOST_REQUIRE_EQUAL(reason, "high-hash");
            BOOST_REQUIRE_EQUAL(debug, "proof of work failed");
        }
    }

    // We can't make transactions until we have inputs
    // Therefore, load 110 blocks :)
    static_assert(std::size(BLOCKINFO) == 110, "Should have 110 blocks to import");
    int baseheight = 0;
    std::vector<CTransactionRef> txFirst;
    for (const auto& bi : BLOCKINFO) {
        const int current_height{mining->getTip()->height};

        /**
         * Simple block creation, nothing special yet.
         * If current_height is odd, block_template will have already been
         * set at the end of the previous loop.
         */
        if (current_height % 2 == 0) {
            block_template = mining->createNewBlock(options);
            BOOST_REQUIRE(block_template);
        }

        CBlock block{block_template->getBlock()};
        CMutableTransaction txCoinbase(*block.vtx[0]);
        {
            LOCK(cs_main);
            block.nVersion = VERSIONBITS_TOP_BITS;
            block.nTime = Assert(m_node.chainman)->ActiveChain().Tip()->GetMedianTimePast()+1;
            txCoinbase.version = 1;
            txCoinbase.vin[0].scriptSig = CScript{} << (current_height + 1) << bi.extranonce;
            txCoinbase.vout.resize(1); // Ignore the (optional) segwit commitment added by CreateNewBlock (as the hardcoded nonces don't account for this)
            txCoinbase.vout[0].scriptPubKey = CScript();
            block.vtx[0] = MakeTransactionRef(txCoinbase);
            if (txFirst.size() == 0)
                baseheight = current_height;
            if (txFirst.size() < 4)
                txFirst.push_back(block.vtx[0]);
            block.hashMerkleRoot = BlockMerkleRoot(block);
            block.nNonce = bi.nonce;
            // code for regenerate BLOCKINFO
            /*
            while (!CheckProofOfWork(block.GetArgon2idPoWHash(), block.nBits, Assert(m_node.chainman)->GetParams().GetConsensus())) {
               ++block.nNonce;
            }
            FILE* f = fopen("/tmp/blockinfo.txt", "a");
            fprintf(f, "{%u, %u},\n", bi.extranonce, block.nNonce);
            fclose(f);
            */
        }
        std::shared_ptr<const CBlock> shared_pblock = std::make_shared<const CBlock>(block);
        // Alternate calls between Chainman's ProcessNewBlock and submitSolution
        // via the Mining interface. The former is used by net_processing as well
        // as the submitblock RPC.
        if (current_height % 2 == 0) {
            BOOST_REQUIRE(Assert(m_node.chainman)->ProcessNewBlock(shared_pblock, /*force_processing=*/true, /*min_pow_checked=*/true, nullptr));
        } else {
            BOOST_REQUIRE(block_template->submitSolution(block.nVersion, block.nTime, block.nNonce, MakeTransactionRef(txCoinbase)));
        }
        {
            LOCK(cs_main);
            // The above calls don't guarantee the tip is actually updated, so
            // we explicitly check this.
            auto maybe_new_tip{Assert(m_node.chainman)->ActiveChain().Tip()};
            BOOST_REQUIRE_EQUAL(maybe_new_tip->GetBlockHash(), block.GetHash());
        }
        if (current_height % 2 == 0) {
            block_template = block_template->waitNext();
            BOOST_REQUIRE(block_template);
        } else {
            // This just adds coverage
            mining->waitTipChanged(block.hashPrevBlock);
        }
    }

    LOCK(cs_main);

    TestBasicMining(scriptPubKey, txFirst, baseheight);

    m_node.chainman->ActiveChain().Tip()->nHeight--;
    SetMockTime(0);

    TestPackageSelection(scriptPubKey, txFirst);

    m_node.chainman->ActiveChain().Tip()->nHeight--;
    SetMockTime(0);

    TestPrioritisedMining(scriptPubKey, txFirst);
}

BOOST_AUTO_TEST_SUITE_END()
