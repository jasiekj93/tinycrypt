#pragma once

#include <etl/optional.h>

#include <tinycrypt/ctr_mode.h>

#include <tinycryptpp/aes/Definitions.hpp>

namespace tinycryptpp::aes
{
    class Ctr
    {
    public:
        using Counter = etl::array<uint8_t, TC_AES_BLOCK_SIZE>;

        Ctr(const Key&, const Counter&);
        /** 
         * @note Destructor clears the schedule and counter to remove any sensitive data
         */
        ~Ctr();

        etl::optional<Output> operator()(Input, etl::span<uint8_t> buffer);

    private:
        struct tc_aes_key_sched_struct schedule;
        Counter counter;
    };
};