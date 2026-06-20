#include <iostream>

int getInt()
{
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;

    return num;
}

constexpr bool isEven(int num)
{
    return (num % 2) == 0;
}

int main()
{
    const int num{getInt()};

    if (isEven(num))
        std::cout << num << " is even\n";
    else
        std::cout << num << " is odd\n";

    return 0;
}
