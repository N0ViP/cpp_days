#include "Fixed.hpp"

Fixed::Fixed() : N(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
    std::cout << "Int constructor called" << std::endl;
    N = n << FractionBits;
}

Fixed::Fixed(float f)
{
    std::cout << "Float constructor called" << std::endl;
    N = roundf(f * (1 << FractionBits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->N = other.N;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &other)
        return *this;

    this->N = other.N;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return N;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    N = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(N) / (1 << FractionBits);
}

int Fixed::toInt(void) const
{
    return N >> FractionBits;
}

std::ostream& operator<<(std::ostream& Cout, const Fixed &cls)
{
    Cout << cls.toFloat();
    return Cout;
}

