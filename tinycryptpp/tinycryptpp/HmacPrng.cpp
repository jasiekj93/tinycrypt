#include "HmacPrng.hpp"

using namespace tinycryptpp;

HmacPrng::HmacPrng(Personalization personalization)
{
    tc_hmac_prng_init(&state, 
                     personalization.data(), 
                     static_cast<unsigned int>(personalization.size()));
}

bool HmacPrng::reseed(Seed seed, 
                      AdditionalInput additional_input)
{
    return (bool) tc_hmac_prng_reseed(&state, 
                    seed.data(), 
                    static_cast<unsigned int>(seed.size()),
                    additional_input.data(),
                    static_cast<unsigned int>(additional_input.size()));
}

bool HmacPrng::generate(Output output)
{
    return (bool) tc_hmac_prng_generate(output.data(), 
                                        static_cast<unsigned int>(output.size()), 
                                        &state);
}

int HmacPrng::generate(uint8_t* dest, unsigned int size)
{
    return tc_hmac_prng_generate(dest, size, &state);
}
