#pragma once

/**
 * @file Sha256.hpp
 * @author Adrian Szczepanski
 * @date 27-11-2025
 */

#include <etl/span.h>
#include <etl/array.h>

#include <tinycrypt/sha256.h>

namespace tinycryptpp
{
    class Sha256
    {
    public:
        using Digest = etl::array<uint8_t, TC_SHA256_DIGEST_SIZE>;

        Sha256();

        /**
         * @note Destructor clears the internal state to remove any sensitive data
         */
        ~Sha256();

        Sha256& update(etl::span<const uint8_t> data);
        Digest final();
        
    private:
        struct tc_sha256_state_struct state;
    };
}