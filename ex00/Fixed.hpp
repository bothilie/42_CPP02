#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>

class Fixed {
    private:
        int value;
        static const int bits;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed&);
        Fixed &operator=(const Fixed &a);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif