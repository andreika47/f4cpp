#ifndef _MODULAR_HPP_
#define _MODULAR_HPP_

#include <vector>

namespace f4
{

struct modular
{
    modular(uint64_t value);

    modular operator+(const modular &rhs) const;
    modular operator*(const modular &rhs) const;

    modular &operator+=(const modular &rhs);
    modular &operator*=(const modular &rhs);

    static uint64_t MOD;

  private:
    uint64_t value;
};

using modulars = std::vector< modular >;

} /* namespace f4 */

#endif /* _MODULAR_HPP_ */
