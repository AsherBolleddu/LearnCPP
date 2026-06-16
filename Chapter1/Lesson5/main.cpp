#include <iostream>

/**
 * This program asks the user for three integers,
 * then prints the integers to the console.
 */
int main()
{
    std::cout << "Enter three numbers: ";
    int x{}, y{}, z{};
    std::cin >> x >> y >> z;

    std::cout << "You entered " << x << ", " << y << ", " << "and " << z << ".\n";
    return 0;
}
