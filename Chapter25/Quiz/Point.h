#if !defined(POINT_H)
#define POINT_H

#include <iostream>

class Point
{
private:
    int m_x {};
    int m_y {};

public:
    Point(int x, int y) : m_x { x }, m_y { y } {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
};

#endif // POINT_H
