#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

class Fixed {
    private:
        int value;
        const static int bits;
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
};

std::ostream &operator<<(std::ostream &fichier, const Fixed &a);

#endif