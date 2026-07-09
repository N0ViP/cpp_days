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

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed& operator++(int);
    Fixed operator++(void);
    Fixed& operator--(int);
    Fixed operator--(void);

    Fixed operator*(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    static  Fixed& min(Fixed &A, Fixed &B) ;
    static  Fixed& max(Fixed &A, Fixed &B) ;
    static const Fixed& min(const Fixed &A, const Fixed &B) ;
    static const Fixed& max(const Fixed &A, const Fixed &B) ;

};

std::ostream& operator<<(std::ostream& Cout, const Fixed &cls);
