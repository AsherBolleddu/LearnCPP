#include "Circle.h"
#include "Point.h"
#include "Triangle.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

int getLargestRadius(const std::vector<std::unique_ptr<Shape>>& v)
{
    int largestRadius { 0 };

    for (const auto& elem : v)
    {
        if (auto* c { dynamic_cast<const Circle*>(elem.get()) })
            largestRadius = std::max(c->getRadius(), largestRadius);
    }

    return largestRadius;
}

int main()
{

    std::vector<std::unique_ptr<Shape>> v;
    v.reserve(3);
    v.push_back(std::make_unique<Circle>(Point { 1, 2 }, 7));
    v.push_back(std::make_unique<Triangle>(Point { 1, 2 }, Point { 3, 4 }, Point { 5, 6 }));
    v.push_back(std::make_unique<Circle>(Point { 7, 8 }, 3));

    // print each shape in vector v on its own line here
    for (const auto& elem : v)
    {
        std::cout << *elem << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    return 0;
}
