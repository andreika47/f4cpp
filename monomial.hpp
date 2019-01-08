#ifndef _MONOMIAL_HPP_
#define _MONOMIAL_HPP_

#include <vector>

namespace f4
{

struct monomial
{
    monomial(size_t vars);

    uint8_t degree() const;

    bool operator|(const monomial &rhs) const;

    bool operator==(const monomial &rhs) const;
    bool operator!=(const monomial &rhs) const;

    monomial operator*(const monomial &rhs) const;
    monomial operator/(const monomial &rhs) const;

    monomial &operator*=(const monomial &rhs);
    monomial &operator/=(const monomial &rhs);

  private:
    std::vector< uint8_t > degrees;

    friend monomial gcd(const monomial &lhs, const monomial &rhs);
    friend monomial lcm(const monomial &lhs, const monomial &rhs);
};

/* greatest common divisor */
monomial gcd(const monomial &lhs, const monomial &rhs);

/* least common multiple */
monomial lcm(const monomial &lhs, const monomial &rhs);

using monomials = std::vector< monomial >;

} /* namespace f4 */

#endif /* _MONOMIAL_HPP_ */
