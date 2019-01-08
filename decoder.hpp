#ifndef _DECODER_HPP_
#define _DECODER_HPP_

#include "polynomial.hpp"

#include <istream>

namespace f4
{

struct decoder
{
    decoder(std::istream *stream);

    size_t vars();

    size_t modn();

    polynomials F();

  private:
    std::istream *stream;
};

} /* namespace f4 */

#endif /* _DECODER_HPP_ */
