#pragma once

/**
 * @file Ecdh.hpp
 * @author Adrian Szczepanski
 * @date 28-11-2025
 */

#include <etl/array.h>
#include <etl/optional.h>
#include <etl/utility.h>

#include <tinycrypt/ecc_dh.h>

#include <tinycryptpp/Rng.hpp>
#include <tinycryptpp/Ecc.hpp>

namespace tinycryptpp
{
    class Ecdh
    {
    public:
        Ecdh() = default;

        etl::optional<etl::pair<ecc::PublicKey, ecc::PrivateKey>> generateKeyPair();
        etl::optional<ecc::Secret> computeSharedSecret(const ecc::PublicKey& publicKey, const ecc::PrivateKey& privateKey);
    };
}