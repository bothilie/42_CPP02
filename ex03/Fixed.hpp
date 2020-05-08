#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

class Fixed {
    private:
        int value;
        const static int bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed&);
        Fixed &operator=(const Fixed&a);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
        Fixed(const int value);
        Fixed(const float value);
        int toInt(void) const;
        float toFloat(void) const;
        bool operator<(const Fixed &a) const;
        bool operator>(const Fixed &a) const;
        bool operator>=(const Fixed &a) const;
        bool operator<=(const Fixed &a) const;
        bool operator==(const Fixed &a) const;
        bool operator!=(const Fixed &a) const;
        Fixed operator+(const Fixed &a) const;
        Fixed operator-(const Fixed &a) const;
        Fixed operator/(const Fixed &a) const;
        Fixed operator*(const Fixed &a) const;
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);
        Fixed &min(Fixed &a, Fixed &b);
        Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);        
};

std::ostream &operator<<(std::ostream &fichier, const Fixed &a);
#endif