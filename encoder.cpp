#include "encoder.hpp"

#include <iostream>

namespace f4
{

encoder::encoder(std::ostream *stream)
{
    if (stream == nullptr)
    {
        stream = &std::cout;
    }

    this->stream = stream;
}

} /* namespace f4 */
