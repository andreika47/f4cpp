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

} /* namespace f4 */
