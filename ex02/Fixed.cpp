#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
}

Fixed::~Fixed()
{
}
        
Fixed::Fixed(const Fixed &a)
{
    this->value = a.value;
}

Fixed& Fixed::operator=(const Fixed &a)
{
    this->value = a.value;
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

Fixed::Fixed(const int intValue) : value(intValue << bits)
{
}

Fixed::Fixed(const float floatValue): value(roundf(floatValue * 256))
{
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
    return Fixed(toFloat() + a.toFloat());
}

Fixed Fixed::operator-(const Fixed &a) const
{
    return Fixed(toFloat() - a.toFloat());
}

Fixed Fixed::operator/(const Fixed &a) const
{
    return Fixed(toFloat() / a.toFloat());
}

Fixed Fixed::operator*(const Fixed &a) const
{
    return Fixed(toFloat() * a.toFloat());
}

Fixed &Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int entier)
{
    (void)entier;
    Fixed f = *this;
    value++;
    return f;
}

Fixed &Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int entier)
{
    (void)entier;
    Fixed f = *this;
    value--;
    return f;
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

