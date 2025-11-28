#include "Hmac.hpp"

using namespace tinycryptpp;

Hmac::Hmac(Key key)
{
    tc_hmac_set_key(&state, 
                    key.data(), 
                    static_cast<unsigned int>(key.size()));
    tc_hmac_init(&state);
}

Hmac& Hmac::update(etl::span<const uint8_t> data)
{
    tc_hmac_update(&state, data.data(), static_cast<unsigned int>(data.size()));
    return *this;
}

Hmac::Tag Hmac::final()
{
    Tag tag;
    tc_hmac_final(tag.data(), tag.size(), &state);
    return tag;
}
