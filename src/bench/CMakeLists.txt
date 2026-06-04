# Copyright (c) 2023-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.

add_executable(bench_bitweb
  bench_bitcoin.cpp
  bench.cpp
  nanobench.cpp
# Benchmarks:
  addrman.cpp
  base58.cpp
  bech32.cpp
  bip324_ecdh.cpp
  block_assemble.cpp
  blockencodings.cpp
  ccoins_caching.cpp
  chacha20.cpp
  checkblock.cpp
  checkblockindex.cpp
  checkqueue.cpp
  cluster_linearize.cpp
  connectblock.cpp
  crypto_argon2.cpp
  crypto_hash.cpp
  descriptors.cpp
  disconnected_transactions.cpp
  duplicate_inputs.cpp
  ellswift.cpp
  examples.cpp
  gcs_filter.cpp
  hashpadding.cpp
  index_blockfilter.cpp
  load_external.cpp
  lockedpool.cpp
  logging.cpp
  mempool_ephemeral_spends.cpp
  mempool_eviction.cpp
  mempool_stress.cpp
  merkle_root.cpp
  obfuscation.cpp
  parse_hex.cpp
  peer_eviction.cpp
  poly1305.cpp
  pool.cpp
  prevector.cpp
  random.cpp
  readwriteblock.cpp
  rollingbloom.cpp
  rpc_blockchain.cpp
  rpc_mempool.cpp
  sign_transaction.cpp
  streams_findbyte.cpp
  strencodings.cpp
  txgraph.cpp
  txorphanage.cpp
  util_time.cpp
  verify_script.cpp
)

include(TargetDataSources)
target_raw_data_sources(bench_bitweb NAMESPACE benchmark::data
  data/block59769.raw
)

target_link_libraries(bench_bitweb
  core_interface
  test_util
  bitcoin_node
  Boost::headers
)

if(ENABLE_WALLET)
  target_sources(bench_bitweb
    PRIVATE
      coin_selection.cpp
      wallet_balance.cpp
      wallet_create.cpp
      wallet_create_tx.cpp
      wallet_loading.cpp
      wallet_ismine.cpp
      wallet_migration.cpp
  )
  target_link_libraries(bench_bitweb bitcoin_wallet)
endif()

# Argon2id ISA availability - forward the same HAVE_ARGON2_* cache variables
# that introspection.cmake sets to ENABLE_ARGON2_* compile definitions on
# bench_bitweb, mirroring what test_bitweb does.  This ensures that
# crypto_argon2.cpp only registers benchmark variants that were actually
# compiled into the argon2 library and can run on the target CPU.
if(HAVE_ARGON2_SSE2)
  target_compile_definitions(bench_bitweb PRIVATE ENABLE_ARGON2_SSE2)
endif()
if(HAVE_ARGON2_SSSE3)
  target_compile_definitions(bench_bitweb PRIVATE ENABLE_ARGON2_SSSE3)
endif()
if(HAVE_ARGON2_AVX2)
  target_compile_definitions(bench_bitweb PRIVATE ENABLE_ARGON2_AVX2)
endif()
if(HAVE_ARGON2_AVX512)
  target_compile_definitions(bench_bitweb PRIVATE ENABLE_ARGON2_AVX512)
endif()
if(HAVE_ARGON2_NEON)
  target_compile_definitions(bench_bitweb PRIVATE ENABLE_ARGON2_NEON)
endif()

add_test(NAME bench_sanity_check
  COMMAND bench_bitweb -sanity-check
)

install_binary_component(bench_bitweb INTERNAL)
