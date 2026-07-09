#pragma once

#include <iostream>


class Fixed
{
private:
    int N;
    static const int FractionBits = 8;

public:
    Fixed();
    Fixed(int n);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};