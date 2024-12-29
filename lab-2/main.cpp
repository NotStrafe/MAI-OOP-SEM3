#include <iostream>
#include "../include/bitstring.hpp"

int main()
{
    try
    {
        std::string bitstr1, bitstr2;
        std::cout << "Enter first bit string: ";
        std::cin >> bitstr1;

        std::cout << "Enter second bit string: ";
        std::cin >> bitstr2;

        BitString bitString1(bitstr1);
        BitString bitString2(bitstr2);

        bitString1 &= bitString2;

        std::cout << "Result of AND operation: ";
        for (size_t i = 0; i < bitString1.getSize(); ++i)
        {
            std::cout << bitString1.getData()[i];
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}