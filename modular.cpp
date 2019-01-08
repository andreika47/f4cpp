#include "modular.hpp"

namespace f4
{

uint64_t modular::MOD = 2;

modular::modular(uint64_t value) : value(value % MOD)
{
}

uint64_t
modular::get() const
{
    return value;
}

modular
modular::operator+(const modular &rhs) const
{
    return modular(value + rhs.value);
}

modular
    modular::operator*(const modular &rhs) const
{
    return modular(value * rhs.value);
}

modular &
modular::operator+=(const modular &rhs)
{
    value += rhs.value;
    value %= MOD;

    return *this;
}

modular &
modular::operator*=(const modular &rhs)
{
    value *= rhs.value;
    value %= MOD;

    return *this;
}

modular
modular::operator~() const
{
    uint64_t p = MOD - 2;
    uint64_t m = value;
    uint64_t v = 1;

    while (p > 0)
    {
        if (p & 1)
        {
            v = (v * m) % MOD;
        }

        m = (m * m) % MOD;

        p >>= 1;
    }

    return modular(v);
}

} /* namespace f4 */
