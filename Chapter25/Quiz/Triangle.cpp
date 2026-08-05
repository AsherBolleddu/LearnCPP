#include "Triangle.h"

Triangle::Triangle(const Point& x, const Point& y, const Point& z) : m_x { x }, m_y { y }, m_z { z } {}

std::ostream& Triangle::print(std::ostream& out) const
{
    return out << "Triangle(" << m_x << ", " << m_y << ", " << m_z << ')';
}
