#include <iostream>
#include <vector>

int main()
{
    // Question 1
    std::vector squares { 1, 4, 9, 16, 25 };

    // Question 3
    std::vector<double> highestTemperatures(365);

    // Question 4
    std::cout << "Enter 3 integers: ";
    std::vector<int> vals(3);
    std::cin >> vals[0] >> vals[1] >> vals[2];

    std::cout << "The sum is: " << vals[0] + vals[1] + vals[2] << '\n';
    std::cout << "The product is: " << vals[0] * vals[1] * vals[2] << '\n';

    return 0;
}
