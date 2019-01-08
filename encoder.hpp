#ifndef _ENCODER_HPP_
#define _ENCODER_HPP_

#include <ostream>

namespace f4
{

struct encoder
{
    encoder(std::ostream *stream);

  private:
    std::ostream *stream;
};

} /* namespace f4 */

#endif /* _ENCODER_HPP_ */
