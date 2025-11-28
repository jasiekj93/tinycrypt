#include "Cmac.hpp"

using namespace tinycryptpp::aes;

Cmac::Cmac(const Key& key)
{
    tc_cmac_setup(&state, key.data(), &schedule);
}

Cmac::~Cmac()
{
    tc_cmac_erase(&state);

    etl::fill(reinterpret_cast<uint8_t*>(&schedule),
              reinterpret_cast<uint8_t*>(&schedule) + sizeof(schedule), 0);
}

Cmac& Cmac::init()
{
    tc_cmac_init(&state);
    return *this;
}

Cmac& Cmac::update(Input input)
{
    tc_cmac_update(&state, input.data(), input.size());
    return *this;
}

Cmac::Tag Cmac::final()
{
    Tag tag;
    tc_cmac_final(tag.data(), &state);
    return tag;
}
