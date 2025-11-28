#include "Ecdsa.hpp"

using namespace tinycryptpp;

etl::optional<ecc::Signature> Ecdsa::sign(const ecc::PrivateKey& privateKey, const Message& message)
{
    if(auto rng = uECC_get_rng(); rng == nullptr)
        return etl::nullopt;

    ecc::Signature signature;

    auto result = uECC_sign(privateKey.data(), message.data(), 
        static_cast<unsigned>(message.size()), signature.data(), uECC_secp256r1());

    if(not result)
        return etl::nullopt;

    return etl::optional<ecc::Signature>{ signature };
}

bool Ecdsa::verifySignature(const ecc::PublicKey& publicKey, const Message& message, const ecc::Signature& signature)
{
    auto result = uECC_verify(publicKey.data(), message.data(),
        static_cast<unsigned>(message.size()), signature.data(), uECC_secp256r1());

    return static_cast<bool>(result);
}