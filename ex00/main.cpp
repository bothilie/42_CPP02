#include <iostream>
#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    int const raw = 4;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    c.setRawBits(raw);
    std::cout << c.getRawBits() << std::endl;
    return 0;
}