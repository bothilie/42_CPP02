#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    //std::cout << "Default constructor called" << std::endl;
}

//Fixed::Fixed(const int valeur)
//{
//    this->value = valeur;
//    std::cout << "Default constructor called" << std::endl;
//}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}
        
Fixed::Fixed(const Fixed &a)
{
    value=a.value;
    // bits=a.bits; impossible car const
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &a)
{
    //if (*this == a)
     //   return *this;
    //std::cout << "Assignation operator called" << std::endl;
    this->value = a.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw){
    //st::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

Fixed::Fixed(const int intValue) : value(intValue << bits)
{
    //std::cout << "Int constructor called" << std::endl;
    //value = intValue << bits;
}

Fixed::Fixed(const float floatValue): value(roundf(floatValue * 256))
{
    //std::cout << "Float constructor called" << std::endl;
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

bool Fixed::operator<(const Fixed &a) const
{
    if (a.getRawBits() > this->getRawBits())
        return 1;
    return 0;
}

bool Fixed::operator>(const Fixed &a) const
{
    if (a.getRawBits() < this->getRawBits())
        return 1;
    return 0;
}

bool Fixed::operator>=(const Fixed &a) const
{
     if (a.getRawBits() <= this->getRawBits())
        return 1;
    return 0;
}
bool Fixed::operator<=(const Fixed &a) const
{
    if (a.getRawBits() >= this->getRawBits())
        return 1;
    return 0;
}
bool Fixed::operator==(const Fixed &a) const
{
    if (a.getRawBits() == this->getRawBits())
        return 1;
    return 0;
}
bool Fixed::operator!=(const Fixed &a) const
{
    if (a.getRawBits() != this->getRawBits())
        return 1;
    return 0;
}

Fixed Fixed::operator+(const Fixed &a) const
{
    return value + a.value;
}

Fixed Fixed::operator-(const Fixed &a) const
{
    return value - a.value;
}

Fixed Fixed::operator/(const Fixed &a) const
{
    //return value / a.value;
    return Fixed(toFloat() / a.toFloat());
}

Fixed Fixed::operator*(const Fixed &a) const
{
    //return value * a.value;
    return Fixed(toFloat() * a.toFloat());
}

Fixed Fixed::operator++()
{
    //int valeur;
    //int i;
    //i = value;
    //valeur = ++i;
    //return valeur;
    Fixed f = *this;
    value++;
    return f;
}

Fixed Fixed::operator++(int)
{
    Fixed f = *this;
    value++;
    return f;
}

Fixed Fixed::operator--()
{
    int valeur;
    int i;
    i = value;
    valeur = --i;
    return valeur;
}

Fixed Fixed::operator--(int)
{
    int valeur;
    int i;
    i = value;
    valeur = i--;
    return valeur;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
 {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
 {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

