#include <iostream>
#include <ostream>
#include "Fixed.hpp"

int main(void)
{
   
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed c(Fixed(1.0f) * Fixed(3));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout <<  "max: " << Fixed::max(a, b) << std::endl;
    std::cout <<  "min: " << Fixed::min(a, b) << std::endl;
    std::cout << b * c << std::endl;
    std::cout << b / c << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << b - 1 << std::endl; 
    std::cout << Fixed(Fixed(b) - Fixed(c)) << std::endl; 
    std::cout << b + c << std::endl;
    std::cout << b - c << std::endl;  
    std::cout << (b == c) << std::endl; 
    std::cout << (b != c) << std::endl; 
    std::cout << (b <= c) << std::endl; 
    std::cout << (b >= c) << std::endl; 
    std::cout << (b < c) << std::endl; 
    std::cout << (b > c) << std::endl; 
    return 0;
}