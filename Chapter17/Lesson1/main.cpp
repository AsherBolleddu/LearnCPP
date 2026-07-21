#include <array>
#include <iostream>

int main()
{
    // Question 1
    [[maybe_unused]] std::array<double, 365> highestTempForDay {};

    constexpr std::array arr { 'h', 'e', 'l', 'l', 'o' };
    std::cout << arr[1] << '\n';

    return 0;
}
