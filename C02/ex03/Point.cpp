#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const Fixed& X, const Fixed& Y) : x(X), y(Y) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {}
Point::~Point() {}
Fixed Point::getx() const
{
    return this->x;
}
Fixed Point::gety() const
{
    return this->y;
}
void Point::setx(const Fixed& X)
{
    this->x = X;
}
void Point::sety(const Fixed& Y)
{
    this->y = Y;
}

Point& Point::operator=(const Point& other)
{
    if (this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}
