#include "Point.hpp"

//   Calculate the area of a triangle.
//   Formula: |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2

Fixed area(Point const a, Point const b, Point const c)
{
    return ((a.getx() * (b.gety() - c.gety()) +
             b.getx() * (c.gety() - a.gety()) +
             c.getx() * (a.gety() - b.gety()))
                .abs() /
            Fixed(2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed area_abc = area(a, b, c);
    Fixed area_abp = area(a, b, point);
    Fixed area_acp = area(a, c, point);
    Fixed area_bcp = area(b, c, point);

    return (area_abc == area_abp + area_acp + area_bcp) && area_abp != Fixed(0) && area_acp != Fixed(0) && area_bcp != Fixed(0);
}
