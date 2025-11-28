#include "Rng.hpp"

using namespace tinycryptpp;

Rng* Rng::globalInstance = nullptr;

Rng::Rng()
{
    if(globalInstance == nullptr)
    {
        globalInstance = this;
        uECC_set_rng(wrapper);
    }
}

Rng::~Rng()
{
    if(globalInstance == this)
    {
        uECC_set_rng(nullptr);
        globalInstance = nullptr;
    }
}

void Rng::setGlobal()
{
    globalInstance = this;
    uECC_set_rng(wrapper);
}

int Rng::wrapper(uint8_t* dest, unsigned int size)
{
    if (globalInstance != nullptr)
        return static_cast<int>(globalInstance->generate({ dest, size }));
    else
        return 0; 
}