#include <hashdb.h>
#include <node/blockstorage.h>
#include <fs.h>
#include <util/system.h>

std::unique_ptr<CHashDB> phashdb;

CHashDB::CHashDB(size_t nCacheSize, bool fMemory, bool fWipe) : CDBWrapper(gArgs.GetDataDirNet() / "hashes", nCacheSize, fMemory, fWipe) {
}

uint256 CHashDB::GetHash(const CBlockHeader &block) {
    uint256 hash;
    if (!this->Read(block, hash)) {
        hash = block.GetHash();
        this->Write(block, hash);
    }
    return hash;
}
