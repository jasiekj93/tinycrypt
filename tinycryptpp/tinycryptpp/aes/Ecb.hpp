#pragma once

#include <etl/optional.h>

#include <tinycrypt/aes.h>

#include <tinycryptpp/aes/Definitions.hpp>

namespace tinycryptpp::aes::ecb
{
    class Base
    {
    public:
        /** 
         * @param workBuffer buffer to store encrypted/decrypted data. Must be at least input.size()
         */
        explicit Base(etl::span<uint8_t> workBuffer);

        /**
         * @note Destructor clears the schedule and workBuffer to remove any sensitive data
         */
        virtual ~Base(); 

        etl::optional<Output> operator()(Input);

    protected:
        Base() = default;

        virtual bool execute(Output::iterator, Input::iterator) = 0;

        struct tc_aes_key_sched_struct schedule;

    private:
        etl::span<uint8_t> workBuffer;
    };

    class Encrypt : public Base
    {
    public:
        explicit Encrypt(const Key& key);
        
    protected:
        bool execute(Output::iterator, Input::iterator) override;
    };

    class Decrypt : public Base
    {
    public:
        explicit Decrypt(const Key& key);

    protected:
        bool execute(Output::iterator, Input::iterator) override;
    };
};
