#include "Ecdh.hpp"

using namespace tinycryptpp;

etl::optional<etl::pair<ecc::PublicKey, ecc::PrivateKey>> Ecdh::generateKeyPair()
{
    if(auto rng = uECC_get_rng(); rng == nullptr)
        return etl::nullopt;

    ecc::PublicKey publicKey;
    ecc::PrivateKey privateKey;

    auto result = uECC_make_key(publicKey.data(), privateKey.data(), uECC_secp256r1());

    if(not result)
        return etl::nullopt;

    return etl::optional<etl::pair<ecc::PublicKey, ecc::PrivateKey>>{ { publicKey, privateKey } };
}

etl::optional<ecc::Secret> Ecdh::computeSharedSecret(const ecc::PublicKey& publicKey, const ecc::PrivateKey& privateKey)
{
    ecc::Secret secret;

    auto result = uECC_shared_secret(publicKey.data(), privateKey.data(), secret.data(), uECC_secp256r1());

    if(not result)
        return etl::nullopt;

    return etl::optional<ecc::Secret>{ secret };
}
