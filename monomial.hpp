#ifndef _MONOMIAL_HPP_
#define _MONOMIAL_HPP_

#include <ostream>
#include <vector>

namespace f4
{

struct monomial
{
    monomial(size_t vars = VARS);
    monomial(std::vector< uint8_t > &&degrees);

    uint8_t degree() const;

    uint8_t &operator[](size_t i);

    bool operator|(const monomial &rhs) const;

    bool operator==(const monomial &rhs) const;
    bool operator!=(const monomial &rhs) const;

    /* degrevlex order */
    bool operator<(const monomial &rhs) const;

    monomial operator*(const monomial &rhs) const;
    monomial operator/(const monomial &rhs) const;

    monomial &operator*=(const monomial &rhs);
    monomial &operator/=(const monomial &rhs);

    static size_t VARS;

  private:
    std::vector< uint8_t > degrees;

    friend monomial gcd(const monomial &lhs, const monomial &rhs);
    friend monomial lcm(const monomial &lhs, const monomial &rhs);

    friend std::ostream &operator<<(std::ostream &os, const monomial &m);
};

/* greatest common divisor */
monomial gcd(const monomial &lhs, const monomial &rhs);

/* least common multiple */
monomial lcm(const monomial &lhs, const monomial &rhs);

std::ostream &operator<<(std::ostream &os, const monomial &m);

using monomials = std::vector< monomial >;

} /* namespace f4 */

#endif /* _MONOMIAL_HPP_ */
