#pragma once

#include "Fixed.hpp"

class Point
{

private:
    Fixed x;
    Fixed y;

public:
    Point();
    Fixed getx() const;
    Fixed gety() const;
    void setx(const Fixed& X);
    void sety(const Fixed& Y);
    Point(const Fixed& X, const Fixed& Y);
    Point(const Point& other);
    ~Point();
    Point& operator=(const Point& other);

};

Fixed   area(Point const a, Point const b, Point const c);
bool    bsp( Point const a, Point const b, Point const c, Point const point);