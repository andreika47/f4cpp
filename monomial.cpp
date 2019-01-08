#include "monomial.hpp"

#include <numeric>

namespace f4
{

monomial::monomial(size_t vars)
{
    degrees.resize(vars);
}

uint8_t
monomial::degree() const
{
    return std::accumulate(degrees.cbegin(), degrees.cend(), 0);
}

bool
monomial::operator==(const monomial &rhs) const
{
    size_t size = degrees.size();
    assert(size == rhs.degrees.size());

    for (size_t i = 0; i < size; ++i)
    {
        if (degrees[i] != rhs.degrees[i])
        {
            return false;
        }
    }

    return true;
}

bool
monomial::operator!=(const monomial &rhs) const
{
    return !(*this == rhs);
}

bool
monomial::operator|(const monomial &rhs) const
{
    size_t size = degrees.size();
    assert(size == rhs.degrees.size());

    for (size_t i = 0; i < size; ++i)
    {
        if (degrees[i] > rhs.degrees[i])
        {
            return false;
        }
    }

    return true;
}

monomial
    monomial::operator*(const monomial &rhs) const
{
    size_t size = degrees.size();
    assert(size == rhs.degrees.size());

    monomial result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result.degrees[i] = degrees[i] + rhs.degrees[i];
    }

    return result;
}

monomial
monomial::operator/(const monomial &rhs) const
{
    size_t size = degrees.size();
    assert(size == rhs.degrees.size());

    monomial result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result.degrees[i] = degrees[i] - rhs.degrees[i];
    }

    return result;
}

monomial &
monomial::operator*=(const monomial &rhs)
{
    size_t size = degrees.size();
    assert(size == rhs.degrees.size());

    for (size_t i = 0; i < size; ++i)
    {
        degrees[i] += rhs.degrees[i];
    }

    return *this;
}

monomial &
monomial::operator/=(const monomial &rhs)
{
    size_t size = degrees.size();
    assert(size == rhs.degrees.size());

    for (size_t i = 0; i < size; ++i)
    {
        degrees[i] -= rhs.degrees[i];
    }

    return *this;
}

monomial
gcd(const monomial &lhs, const monomial &rhs)
{
    size_t size = lhs.degrees.size();
    assert(size == rhs.degrees.size());

    monomial result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result.degrees[i] = std::min(lhs.degrees[i], rhs.degrees[i]);
    }

    return result;
}

monomial
lcm(const monomial &lhs, const monomial &rhs)
{
    size_t size = lhs.degrees.size();
    assert(size == rhs.degrees.size());

    monomial result(size);
    for (size_t i = 0; i < size; ++i)
    {
        result.degrees[i] = std::max(lhs.degrees[i], rhs.degrees[i]);
    }

    return result;
}

} /* namespace f4 */
