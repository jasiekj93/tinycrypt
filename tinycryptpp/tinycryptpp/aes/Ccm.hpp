#pragma once

/**
 * @file Ccm.hpp
 * @author Adrian Szczepanski
 * @date 27-11-2025
 */

#include <etl/optional.h>

#include <tinycrypt/ccm_mode.h>

#include <tinycryptpp/aes/Definitions.hpp>

namespace tinycryptpp::aes
{
    enum MacLength : size_t
    {
        MAC32 = 4,
        MAC48 = 6,
        MAC64 = 8,
        MAC80 = 10,
        MAC96 = 12,
        MAC112 = 14,
        MAC128 = 16
    };

    template<MacLength MLEN>
    class Ccm
    {
    public:
        static constexpr size_t NONCE_LENGTH = 13;

        using Nonce = etl::array<uint8_t, NONCE_LENGTH>;
        using AssociatedData = etl::span<const uint8_t>;

        Ccm(const Key& key, const Nonce& nonce);

        /** 
         * @note Destructor clears the schedule and state to remove any sensitive data
         */
        ~Ccm(); 

        etl::optional<Output> encrypt(AssociatedData, Input, etl::span<uint8_t> buffer);
        etl::optional<Output> decrypt(AssociatedData, Input, etl::span<uint8_t> buffer);

    private:
        struct tc_ccm_mode_struct state;
        struct tc_aes_key_sched_struct schedule;
    };

}


namespace tinycryptpp::aes
{
    template <MacLength MLEN>
    inline Ccm<MLEN>::Ccm(const Key& key, const Nonce& nonce)
    {
        tc_aes128_set_encrypt_key(&schedule, key.data());
        tc_ccm_config(&state, &schedule, const_cast<uint8_t*>(nonce.data()), 
                      static_cast<unsigned int>(nonce.size()), 
                      static_cast<unsigned int>(MLEN));
    }

    template <MacLength MLEN>
    inline Ccm<MLEN>::~Ccm()
    {
        etl::fill(reinterpret_cast<uint8_t*>(&schedule),
                  reinterpret_cast<uint8_t*>(&schedule) + sizeof(schedule), 0);
        etl::fill(reinterpret_cast<uint8_t*>(&state),
                  reinterpret_cast<uint8_t*>(&state) + sizeof(state), 0);
    }

    template <MacLength MLEN>
    inline etl::optional<Output> Ccm<MLEN>::encrypt(AssociatedData, Input, etl::span<uint8_t> buffer)
    {
        if (buffer.size() < (input.size() + MLEN))
            return etl::nullopt;

        auto result = tc_ccm_generation_encryption(buffer.data(), 
                                                  static_cast<unsigned int>(buffer.size()), 
                                                  associated_data.data(), 
                                                  static_cast<unsigned int>(associated_data.size()), 
                                                  input.data(), 
                                                  static_cast<unsigned int>(input.size()), 
                                                  &state);
        if (not result)
            return etl::nullopt;
        else
            return Output(buffer.data(), (input.size() + MLEN));
    }

    template <MacLength MLEN>
    inline etl::optional<Output> Ccm<MLEN>::decrypt(AssociatedData, Input, etl::span<uint8_t> buffer)
    {
        if( buffer.size() < (input.size() - MLEN))
            return etl::nullopt;

        auto result = tc_ccm_decryption_verification(buffer.data(), 
                                                     static_cast<unsigned int>(buffer.size()), 
                                                     associated_data.data(), 
                                                     static_cast<unsigned int>(associated_data.size()), 
                                                     input.data(), 
                                                     static_cast<unsigned int>(input.size()), 
                                                     &state);
        if (not result)
            return etl::nullopt;
        else
            return Output(buffer.data(), (input.size() - MLEN));
    }
}