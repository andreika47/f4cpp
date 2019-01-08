#ifndef _DECODER_HPP_
#define _DECODER_HPP_

#include <istream>

namespace f4
{

struct decoder
{
    decoder(std::istream *stream);

  private:
    std::istream *stream;
};

} /* namespace f4 */

#endif /* _DECODER_HPP_ */
