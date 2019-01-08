#include "modular.hpp"

namespace f4
{

uint64_t modular::MOD = 2;

modular::modular(uint64_t value) : value(value % MOD)
{
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

} /* namespace f4 */
