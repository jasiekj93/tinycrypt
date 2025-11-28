#pragma once

/**
 * @file Ecdsa.hpp
 * @author Adrian Szczepanski
 * @date 28-11-2025
 */

#include <etl/optional.h>
#include <etl/span.h>

#include <tinycrypt/ecc_dsa.h>

#include <tinycryptpp/Rng.hpp>
#include <tinycryptpp/Ecc.hpp>

namespace tinycryptpp
{
    class Ecdsa
    {
    public:
        using Message = etl::span<const uint8_t>;

        Ecdsa() = default;

        etl::optional<ecc::Signature> sign(const ecc::PrivateKey&, const Message&);
        bool verifySignature(const ecc::PublicKey&, const Message&, const ecc::Signature&);
    };
}