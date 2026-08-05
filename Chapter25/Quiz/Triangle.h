#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include "Point.h"
#include "Shape.h"

class Triangle : public Shape
{
private:
    Point m_x;
    Point m_y;
    Point m_z;

public:
    Triangle(const Point& x, const Point& y, const Point& z);
    std::ostream& print(std::ostream& out) const override;
};

#endif // TRIANGLE_H
