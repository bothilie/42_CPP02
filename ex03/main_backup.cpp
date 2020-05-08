#include <iostream>
#include <ostream>
#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(10); Fixed const c(42.42f); Fixed const d(b);
    a = Fixed(1234.4321f);
    
   //std::ostream fichier("fichier.txt");
    std::cout << a << std::endl;
    if (c < b)
        std::cout << "c plus petit que b" << std::endl;
    if (c > b)
        std::cout << "c plus grand que b" << std::endl;
    if (c >= b)
        std::cout << "c plus grand ou égal à b" << std::endl;
    if (c <= b)
        std::cout << "b plus grand ou égal à c" << std::endl;
    if (c == b)
        std::cout << "b est égal à c" << std::endl;
    if (c != b)
        std::cout << "b différent de c" << std::endl;
    c + d;
    std::cout << "value of c = c + d " << c + d << std::endl;
    std::cout << "value of c = c + d " << c - d << std::endl;
    std::cout << "value of c = c + d " << c * d << std::endl;
    std::cout << "value of c = c + d " << c / d << std::endl;
    
    //b++;
    std::cout << "value of b " << b << std::endl;
    std::cout << "value of ++b " << ++b << std::endl;
    std::cout << "value of b " << b << std::endl;
    std::cout << "value of b++ " << b++ << std::endl;
    std::cout << "value of b " << b << std::endl;
    std::cout << "value of b-- " << b-- << std::endl;
    std::cout << "value of b " << b << std::endl;
    std::cout << "value of --b " << --b << std::endl;
    
    std::cout << "value max entre a et b " << max(a,b) << std::endl;
    std::cout << "value min entre a et b " << min(a,b) << std::endl;
    std::cout << "value max entre a et b " << c.max(b) << std::endl;
    std::cout << "value min entre a et b " << c.min(b) << std::endl;
    std::cout << "value min entre a et b " << Fixed::max(a, b) << std::endl;
    return 0;
}