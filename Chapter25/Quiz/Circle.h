#if !defined(CIRCLE_H)
#define CIRCLE_H

#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
private:
    Point m_center;
    int m_radius {};

public:
    Circle(const Point& center, int radius);
    int getRadius() const { return m_radius; }
    std::ostream& print(std::ostream&) const override;
};

#endif // CIRCLE_H
