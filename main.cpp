#include "decoder.hpp"
#include "f4.hpp"

#include <fstream>
#include <iostream>

int
main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "usage: " << argv[0] << " <input> <output>" << std::endl;
        return 1;
    }

    std::string src = argv[1];
    std::string dst = argv[2];

    std::unique_ptr< std::ifstream > input;
    std::unique_ptr< std::ofstream > output;

    std::istream *is = &std::cin;
    std::ostream *os = &std::cout;

    if (src != "-")
    {
        input.reset(new std::ifstream(src));

        if (input->fail())
        {
            std::cerr << "can't open input `" << src << "'" << std::endl;
            return 1;
        }

        is = input.get();
    }

    if (dst != "-")
    {
        output.reset(new std::ofstream(dst));

        if (output->fail())
        {
            std::cerr << "can't open output `" << dst << "'" << std::endl;
            return 1;
        }

        os = output.get();
    }

    f4::decoder reader(is);

    f4::monomial::VARS = reader.vars();
    f4::modular::MOD   = reader.modn();
    f4::polynomials F  = reader.F();

    auto G = f4::GB(F);

    for (const auto g : G)
    {
        *os << g << std::endl;
    }
}
