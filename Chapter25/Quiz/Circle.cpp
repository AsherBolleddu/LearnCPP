#include "Circle.h"

Circle::Circle(const Point& center, int radius) : m_center { center }, m_radius { radius } {}

std::ostream& Circle::print(std::ostream& out) const
{
    return out << "Circle(" << m_center << ", radius " << m_radius << ')';
}
