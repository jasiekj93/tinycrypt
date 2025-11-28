#pragma once

/**
 * @file Rng.hpp
 * @author Adrian Szczepanski
 * @date 28-11-2025
 */

#include <cstdint>

#include <tinycrypt/ecc.h>

namespace tinycryptpp
{
    class Rng
    {
    private:
       

    public:
        Rng();
        virtual ~Rng();

        void setGlobal();

        virtual int generate(uint8_t* dest, unsigned int size) = 0;

    private:
        static Rng* globalInstance;
        static int wrapper(uint8_t* dest, unsigned int size);
    };
}