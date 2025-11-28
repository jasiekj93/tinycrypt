#pragma once

/**
 * @file HmacPrng.hpp
 * @author Adrian Szczepanski
 * @date 27-11-2025
 */

#include <etl/span.h>

#include <tinycrypt/hmac_prng.h>

#include <tinycryptpp/Rng.hpp>

namespace tinycryptpp
{
    class HmacPrng : public Rng
    {
    public:
        using Personalization = etl::span<const uint8_t>;
        using Seed = etl::span<const uint8_t>;
        using AdditionalInput = etl::span<const uint8_t>;
        using Output = etl::span<uint8_t>;

        explicit HmacPrng(Personalization);

        bool reseed(Seed, AdditionalInput = AdditionalInput());

        bool generate(Output) override;

        template <class T>
        void generate(T& container)
        {
            generate(etl::span<uint8_t>(reinterpret_cast<uint8_t*>(container.data()),
                                        container.size() * sizeof(typename T::value_type)));
        }
                      
    private:
        struct tc_hmac_prng_struct state;
    };
}