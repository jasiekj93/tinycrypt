#include "Ecb.hpp"

using namespace tinycryptpp::aes;
using namespace tinycryptpp::aes::ecb;

Base::Base(etl::span<uint8_t> workBuffer)
    : workBuffer(workBuffer)
{
}

Base::~Base()
{
    // Clear sensitive data
    etl::fill(workBuffer.begin(), workBuffer.end(), 0);
    etl::fill(reinterpret_cast<uint8_t*>(&schedule),
              reinterpret_cast<uint8_t*>(&schedule) + sizeof(schedule), 0);
}

etl::optional<Output> Base::operator()(Input input)
{
    if(workBuffer.size() < input.size())
        return etl::nullopt;

    if(input.size() % TC_AES_BLOCK_SIZE != 0)
        return etl::nullopt;

    auto out = workBuffer.begin();
    auto in = input.begin();

    for(auto i = 0; i < input.size(); i += TC_AES_BLOCK_SIZE)
    {
        auto result = execute(etl::next(out, i), 
                            etl::next(in, i));

        if(not result)
            return etl::nullopt;
    }

    return etl::optional<Output>(workBuffer);
}


Encrypt::Encrypt(const Key& key)
    : Base()
{
    tc_aes128_set_encrypt_key(&schedule, key.data());
}

bool Encrypt::execute(Output::iterator out, Input::iterator in)
{
    return (bool) tc_aes_encrypt(out, in, &schedule);
}


Decrypt::Decrypt(const Key& key)
    : Base()
{
    tc_aes128_set_decrypt_key(&schedule, key.data());
}

bool Decrypt::execute(Output::iterator out, Input::iterator in)
{
    return (bool) tc_aes_decrypt(out, in, &schedule);
}

