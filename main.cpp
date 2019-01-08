#include "decoder.hpp"
#include "encoder.hpp"

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

    if (src != "-")
    {
        input.reset(new std::ifstream(src));

        if (input->fail())
        {
            std::cerr << "can't open input `" << src << "'" << std::endl;
            return 1;
        }
    }

    if (dst != "-")
    {
        output.reset(new std::ofstream(dst));

        if (output->fail())
        {
            std::cerr << "can't open output `" << dst << "'" << std::endl;
            return 1;
        }
    }

    f4::decoder reader(input.get());
    f4::encoder writer(output.get());
}
