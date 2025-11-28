#pragma once

/**
 * @file Cbc.hpp
 * @author Adrian Szczepanski
 * @date 28-11-2025
 */

#include <etl/optional.h>

#include <tinycrypt/cbc_mode.h>

#include <tinycryptpp/aes/Definitions.hpp>

namespace tinycryptpp::aes::cbc
{
    static constexpr size_t IV_SIZE = TC_AES_BLOCK_SIZE;

    using Iv = etl::array<uint8_t, IV_SIZE>;
    using IvPointer = Iv::iterator;

    class Encrypt
    {
    public:
        /**
         * @param workBuffer buffer to store IV + encrypted data. Must be at least input.size() + IV_SIZE
         */
        Encrypt(const Key& key, const Iv& iv, etl::span<uint8_t> workBuffer);

        /**
         * @note Destructor clears the schedule and workBuffer to remove any sensitive data
         */
        ~Encrypt();

        /**
         * @param outputBuffer buffer to store IV + encrypted data. Must be at least input.size() + IV_SIZE
         * @param input data to encrypt. Must be multiple of block size (16 bytes) - no padding is performed.
         * @return etl::optional<Output> - if requirements are met. Output = iv + ciphertext
         */
        etl::optional<Output> operator()(Input input);

    protected:
        void updateIv(size_t inputSize);

    private:
        struct tc_aes_key_sched_struct schedule;
        Iv iv;
        etl::span<uint8_t> workBuffer;
    };

    class Decrypt
    {
    public:
        /**
         * @param workBuffer buffer to store IV + encrypted data. Must be at least input.size() + IV_SIZE
         */
        Decrypt(const Key& key, etl::span<uint8_t> workBuffer);

        /**
         * @note Destructor clears the schedule and workBuffer to remove any sensitive data
         */
        ~Decrypt();

        /**
         * @note Assumes:- input == iv + ciphertext, i.e. the iv and the ciphertext are
         *                  contiguous buffer.
         * @param outBuffer buffer to store decrypted data. Must be equal input.size()
         * @param input data to decrypt. Must be multiple of block size (16 bytes) - no padding is performed.
         * @return etl::optional<Output> - if requirements are met.
         */
        etl::optional<Output> operator()(Input);

    private:
        struct tc_aes_key_sched_struct schedule;
        etl::span<uint8_t> workBuffer;
    };
}