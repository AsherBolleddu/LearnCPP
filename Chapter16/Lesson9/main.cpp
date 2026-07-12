#include <cassert>
#include <iostream>
#include <vector>

namespace Animals
{
    enum Type
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals,
    };

    const std::vector legs { 2, 4, 4, 4, 2, 0 };

} // namespace Animals

int main()
{
    assert(std::ssize(Animals::legs) == Animals::max_animals &&
           "Animals: legs array and enum Type length does not match");

    std::cout << "An elephant has " << Animals::legs[Animals::elephant] << " legs.\n";

    return 0;
}
