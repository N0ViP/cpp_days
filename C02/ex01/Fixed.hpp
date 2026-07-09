#pragma once

#include <iostream>
#include <cmath>


class Fixed
{
private:
    int N;
    static const int FractionBits = 8;

public:
    Fixed();
    Fixed(int n);
    Fixed(float f);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& Cout, const Fixed &cls);
