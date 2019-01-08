#include "monomial.hpp"

#include <numeric>

namespace f4
{

size_t monomial::VARS = 0;

monomial::monomial(size_t vars)
{
    degrees.resize(vars);
}

monomial::monomial(std::vector< uint8_t > &&degrees) : degrees(std::move(degrees))
{
}

uint8_t
monomial::degree() const
{
    return std::accumulate(degrees.cbegin(), degrees.cend(), 0);
}

uint8_t &
    monomial::operator[](size_t i)
{
    assert(i < degrees.size());

    return degrees[i];
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

bool
monomial::operator<(const monomial &rhs) const
{
    size_t size = degrees.size();
    assert(size == rhs.degrees.size());

    auto l = degree();
    auto r = rhs.degree();

    if (l != r)
    {
        return l < r;
    }

    for (size_t i = 1; i <= size; ++i)
    {
        l = degrees[size - i];
        r = rhs.degrees[size - i];

        if (l != r)
        {
            return l > r;
        }
    }

    return false;
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

std::ostream &
operator<<(std::ostream &os, const monomial &m)
{
    size_t size = m.degrees.size();

    bool empty = true;
    for (size_t i = 0; i < size; ++i)
    {
        size_t d = m.degrees[i];

        if (d == 0)
        {
            continue;
        }

        if (!empty)
        {
            os << "*";
        }

        os << "x" << i + 1;

        if (d != 1)
        {
            os << "^" << d;
        }

        if (empty)
        {
            empty = false;
        }
    }

    return os;
}

} /* namespace f4 */
