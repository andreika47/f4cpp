#ifndef _F4_HPP_
#define _F4_HPP_

#include "polynomial.hpp"

namespace f4
{

using spair  = std::pair< polynomial, polynomial >;
using spairs = std::vector< spair >;

polynomials GB(polynomials &F);

} /* namespace f4 */

#endif /* _F4_HPP_ */
