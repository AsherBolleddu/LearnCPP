#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr { 'h', 'e', 'l', 'l', 'o' };

    std::cout << "The length is " << arr.size() << '\n';
    std::cout << arr[1] << arr.at(1) << std::get<1>(arr) << '\n';

    return 0;
}
