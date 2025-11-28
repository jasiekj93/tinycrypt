#pragma once

/**
 * @file CtrPrng.hpp
 * @author Adrian Szczepanski
 * @date 27-11-2025
 */

#include <etl/span.h>

#include <tinycrypt/ctr_prng.h>

#include <tinycryptpp/Rng.hpp>

namespace tinycryptpp::aes
{
    class CtrPrng : public Rng
    {
    public:
        using Personalization = etl::span<const uint8_t>;
        using Seed = etl::span<const uint8_t>;
        using AdditionalInput = etl::span<const uint8_t>;
        using Output = etl::span<uint8_t>;

        CtrPrng(Personalization, Seed);

        /** 
         * @note Destructor clears the internal state to remove any sensitive data
         */
        ~CtrPrng();

        bool reseed(Seed, AdditionalInput = AdditionalInput());

        bool generate(Output, AdditionalInput);
        bool generate(Output) override;

        template <class T>
        void generate(T& container, AdditionalInput additionalInput = AdditionalInput())
        {
            generate(etl::span<uint8_t>(reinterpret_cast<uint8_t*>(container.data()),
                                        container.size() * sizeof(typename T::value_type)),
                     additionalInput);
        }
                      
    private:
        TCCtrPrng_t state;
    };
}