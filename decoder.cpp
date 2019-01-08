#include "decoder.hpp"

namespace f4
{

decoder::decoder(std::istream *stream) : stream(stream)
{
}

size_t
decoder::vars()
{
    std::string line;

    std::getline(*stream, line);

    return std::strtoull(line.c_str(), NULL, 10);
}

size_t
decoder::modn()
{
    std::string line;

    std::getline(*stream, line);

    return std::strtoull(line.c_str(), NULL, 10);
}

polynomials
decoder::F()
{
    return {};
}

} /* namespace f4 */
