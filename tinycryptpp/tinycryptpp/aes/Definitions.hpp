#pragma once

/**
 * @file Definitions.hpp
 * @author Adrian Szczepanski
 * @date 27-11-2025
 */

#include <etl/span.h>

#include <tinycrypt/aes.h>

#include <tinycryptpp/SecretArray.hpp>

namespace tinycryptpp::aes
{
    using Key = SecretArray<uint8_t, TC_AES_KEY_SIZE>;
    using Input = etl::span<const uint8_t>;
    using Output = etl::span<uint8_t>;
}