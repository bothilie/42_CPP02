#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
        
Fixed::Fixed(const Fixed &a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
    this->value = a.value;
}

Fixed& Fixed::operator=(const Fixed &a)
{
     std::cout << "Assignation operator called" << std::endl;
    this->value = a.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    value = intValue << bits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(floatValue * 256);
}

int Fixed::toInt(void) const
{
    return value >> bits;
}

float Fixed::toFloat(void) const
{
    return float(value) / 256;
}

std::ostream &operator<<(std::ostream &out, const Fixed &a)
{
    out << a.toFloat();
    return out;
}

