#pragma once

#include <etl/array.h>
#include <initializer_list>

namespace tinycryptpp
{
    template<typename T, size_t N>
    class SecretArray : public etl::array<T, N>
    {
    public:
        SecretArray() : etl::array<T, N>() {}

        template<typename... Args>
        SecretArray(Args&&... args) : etl::array<T, N>(std::forward<Args>(args)...) {}

        SecretArray(std::initializer_list<T> init)
        {
            etl::copy(init.begin(), init.end(), this->begin());
        }

        SecretArray(const SecretArray& other) : etl::array<T, N>(other) {}
        SecretArray(SecretArray&& other) noexcept : etl::array<T, N>(std::move(other)) {}

        SecretArray& operator=(const SecretArray& other)
        {
            if (this != &other) 
                etl::array<T, N>::operator=(other);
            return *this;
        }

        SecretArray& operator=(SecretArray&& other) noexcept
        {
            if (this != &other) 
                etl::array<T, N>::operator=(std::move(other));
            return *this;
        }

        virtual ~SecretArray()
        {
            this->fill(T{});
        }
    };
}