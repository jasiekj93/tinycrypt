#include "Sha256.hpp"

using namespace tinycryptpp;

Sha256::Sha256()
{
    tc_sha256_init(&state);
}

Sha256& Sha256::update(etl::span<const uint8_t> data)
{
    tc_sha256_update(&state, data.data(), data.size());
    return *this;
}

Sha256::Digest Sha256::final()
{
    Digest digest;
    tc_sha256_final(digest.data(), &state);
    return digest;
}