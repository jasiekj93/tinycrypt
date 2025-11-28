#include "Cbc.hpp"

using namespace tinycryptpp::aes;
using namespace tinycryptpp::aes::cbc;

Encrypt::Encrypt(const Key& key, const Iv& iv, etl::span<uint8_t> workBuffer)
    : iv(iv)
    , workBuffer(workBuffer)
{
    tc_aes128_set_encrypt_key(&schedule, key.data());
}

Encrypt::~Encrypt()
{
    etl::fill(workBuffer.begin(), workBuffer.end(), 0);
    etl::fill(reinterpret_cast<uint8_t*>(&schedule),
              reinterpret_cast<uint8_t*>(&schedule) + sizeof(schedule), 0);
}

etl::optional<Output> Encrypt::operator()(Input input)
{
    if(workBuffer.size() < input.size() + IV_SIZE)
        return etl::nullopt;
    
    if(input.size() % TC_AES_BLOCK_SIZE != 0)
        return etl::nullopt;

    auto result = tc_cbc_mode_encrypt(
        workBuffer.data(),
        static_cast<unsigned int>(input.size() + IV_SIZE),
        input.data(),
        static_cast<unsigned int>(input.size()),
        iv.data(),
        &schedule);
    
    if(not result)
        return etl::nullopt;

    updateIv(input.size());
    return Output{ workBuffer.begin(), input.size() + IV_SIZE };
}

void Encrypt::updateIv(size_t inputSize)
{
    auto lastBlockStart = etl::next(workBuffer.begin(), inputSize - TC_AES_BLOCK_SIZE);
    auto lastBlockEnd = etl::next(lastBlockStart, TC_AES_BLOCK_SIZE);
    etl::copy(lastBlockStart, lastBlockEnd, iv.begin());
}


Decrypt::Decrypt(const Key& key, etl::span<uint8_t> workBuffer)
    : workBuffer(workBuffer)
{
    tc_aes128_set_decrypt_key(&schedule, key.data());
}

Decrypt::~Decrypt()
{
    etl::fill(workBuffer.begin(), workBuffer.end(), 0);
    etl::fill(reinterpret_cast<uint8_t*>(&schedule),
              reinterpret_cast<uint8_t*>(&schedule) + sizeof(schedule), 0);
}

etl::optional<Output> Decrypt::operator()(Input input)
{
    if(workBuffer.size() < input.size())
        return etl::nullopt;
    
    if(input.size() % TC_AES_BLOCK_SIZE != 0)
        return etl::nullopt;

    auto inputSize =  input.size() - IV_SIZE;
    auto ivPointer = input.begin();
    auto dataPointer = etl::next(input.begin(), IV_SIZE);

    auto result = tc_cbc_mode_decrypt(
        workBuffer.data(),
        inputSize,
        dataPointer,
        inputSize,
        ivPointer,
        &schedule);
    
    if(not result)
        return etl::nullopt;

    return Output{ workBuffer.begin(), inputSize };
}
