#include "Point.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Point& p)
{
    return out << "Point(" << p.m_x << ", " << p.m_y << ')';
}
