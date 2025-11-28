#include "CtrPrng.hpp"

using namespace tinycryptpp::aes;

CtrPrng::CtrPrng(Personalization personalization, Seed entropy)
{
    tc_ctr_prng_init(&state, entropy.data(), static_cast<unsigned int>(entropy.size()),
                     personalization.data(), static_cast<unsigned int>(personalization.size()));
}

CtrPrng::~CtrPrng()
{
    tc_ctr_prng_uninstantiate(&state);
}

bool CtrPrng::reseed(Seed seed, AdditionalInput additionalInput)
{
    return (bool) tc_ctr_prng_reseed(&state, 
                                    seed.data(), 
                                    static_cast<unsigned int>(seed.size()),
                                    additionalInput.data(), 
                                    static_cast<unsigned int>(additionalInput.size()));
}

bool CtrPrng::generate(Output output, AdditionalInput additionalInput)
{
    return (bool) tc_ctr_prng_generate(&state, 
                                    additionalInput.data(),
                                    static_cast<unsigned int>(additionalInput.size()),
                                    output.data(), 
                                    static_cast<unsigned int>(output.size()));
}

int CtrPrng::generate(uint8_t* dest, unsigned int size)
{
    return tc_ctr_prng_generate(&state, 
                               nullptr,
                               0,
                               dest, 
                               size);
}
