#pragma once

/**
 * @file Ecc.hpp
 * @author Adrian Szczepanski
 * @date 28-11-2025
 */

#include <cstdint>

#include <tinycryptpp/SecretArray.hpp>

namespace tinycryptpp::ecc
{
    static constexpr auto PRIVATE_KEY_SIZE = 32;
    static constexpr auto PUBLIC_KEY_SIZE = 64;
    static constexpr auto SECRET_SIZE = 32;
    static constexpr auto SIGNATURE_SIZE = 64;

    using PublicKey = SecretArray<uint8_t, PUBLIC_KEY_SIZE>;
    using PrivateKey = SecretArray<uint8_t, PRIVATE_KEY_SIZE>;
    using Secret = SecretArray<uint8_t, SECRET_SIZE>;
    using Signature = SecretArray<uint8_t, SIGNATURE_SIZE>;
}