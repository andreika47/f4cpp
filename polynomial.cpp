#include "polynomial.hpp"

namespace f4
{

polynomial &
polynomial::operator*=(const modular &rhs)
{
    for (auto &c : coeffs)
    {
        c *= rhs;
    }

    return *this;
}

polynomial &
polynomial::operator*=(const monomial &rhs)
{
    for (auto &m : monoms)
    {
        m *= rhs;
    }

    return *this;
}

std::ostream &
operator<<(std::ostream &os, const polynomial &p)
{
    size_t size = p.coeffs.size();
    assert(size == p.monoms.size());

    bool empty = true;
    for (size_t i = 0; i < size; ++i)
    {
        auto c = p.coeffs[i].get();
        auto d = p.monoms[i].degree();

        if (c == 0)
        {
            continue;
        }

        if (!empty)
        {
            os << "+";
        }

        if (c != 1)
        {
            os << c;
        }

        if (d != 0)
        {
            if (c != 1)
            {
                os << "*";
            }

            os << p.monoms[i];
        }

        if (empty)
        {
            empty = false;
        }
    }

    return os;
}

} /* namespace f4 */
