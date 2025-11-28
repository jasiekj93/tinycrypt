#include "Ctr.hpp"

using namespace tinycryptpp::aes;

Ctr::Ctr(const Key& key, const Counter& counter)
{
    tc_aes128_set_encrypt_key(&schedule, key.data());
    this->counter = counter;
}

Ctr::~Ctr()
{
    etl::fill(reinterpret_cast<uint8_t*>(&schedule),
              reinterpret_cast<uint8_t*>(&schedule) + sizeof(schedule), 0);
    etl::fill(counter.begin(), counter.end(), 0);
}

etl::optional<Output> Ctr::operator()(Input input, etl::span<uint8_t> buffer)
{
    if (input.size() < buffer.size())
        return etl::nullopt;

    auto result = tc_ctr_mode(buffer.data(), static_cast<unsigned int>(input.size()),
                    input.data(), static_cast<unsigned int>(input.size()),
                    counter.data(), &schedule);
    
    if (not result)
        return etl::nullopt;

    return buffer;
}