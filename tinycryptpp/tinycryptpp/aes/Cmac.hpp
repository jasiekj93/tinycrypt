#pragma once

/**
 * @file Cmac.hpp
 * @author Adrian Szczepanski
 * @date 27-11-2025
 */

#include <tinycrypt/cmac_mode.h>

#include <tinycryptpp/aes/Definitions.hpp>

namespace tinycryptpp::aes
{
    class Cmac
    {
    public:
        using Tag = etl::array<uint8_t, TC_AES_BLOCK_SIZE>;

        explicit Cmac(const Key&);

        /** 
         * @note Destructor clears the schedule and state to remove any sensitive data
         */
        ~Cmac();

        Cmac& init();
        Cmac& update(Input);
        Tag final();

                      
    private:
        struct tc_cmac_struct state;
        struct tc_aes_key_sched_struct schedule;
    };
}
