#pragma once

/**
 * @file Hmac.hpp
 * @author Adrian Szczepanski
 * @date 27-11-2025
 */

#include <etl/span.h>
#include <etl/array.h>

#include <tinycrypt/hmac.h>

namespace tinycryptpp
{
    class Hmac
    {
    public:
        using Tag = etl::array<uint8_t, TC_SHA256_DIGEST_SIZE>;
        using Key = etl::span<const uint8_t>;

        explicit Hmac(Key);

        Hmac& update(etl::span<const uint8_t> data);
        Tag final();
        
    private:
        struct tc_hmac_state_struct state;
    };
}