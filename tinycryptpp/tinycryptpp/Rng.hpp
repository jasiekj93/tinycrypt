#pragma once

/**
 * @file Rng.hpp
 * @author Adrian Szczepanski
 * @date 28-11-2025
 */

#include <cstdint>

#include <etl/span.h>

#include <tinycrypt/ecc.h>

namespace tinycryptpp
{
    class Rng
    {
    public:
        using Output = etl::span<uint8_t>;
    
        Rng();
        virtual ~Rng();

        void setGlobal();

        virtual bool generate(Output) = 0;

    private:
        static Rng* globalInstance;
        static int wrapper(uint8_t* dest, unsigned int size);
    };
}