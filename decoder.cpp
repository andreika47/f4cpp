#include "decoder.hpp"

#include <iostream>

namespace f4
{

decoder::decoder(std::istream *stream)
{
    if (stream == nullptr)
    {
        stream = &std::cin;
    }

    this->stream = stream;
}

} /* namespace f4 */
