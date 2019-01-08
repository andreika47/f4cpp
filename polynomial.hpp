#ifndef _POLYNOMIAL_HPP_
#define _POLYNOMIAL_HPP_

#include "modular.hpp"
#include "monomial.hpp"

namespace f4
{

struct polynomial
{
    /* leading monomial */
    const monomial &LM() const;

    polynomial &operator*=(const modular &rhs);
    polynomial &operator*=(const monomial &rhs);

  private:
    modulars  coeffs;
    monomials monoms;
};

using polynomials = std::vector< polynomial >;

} /* namespace f4 */

#endif /* _POLYNOMIAL_HPP_ */
