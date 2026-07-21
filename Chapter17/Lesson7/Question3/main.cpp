#include <iostream>
#include <limits>

namespace ProgramData
{
    constexpr int perfectSquares[] { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
}

bool isPerfectSquare(int searchSquare)
{
    for (const auto square : ProgramData::perfectSquares)
    {
        if (square == searchSquare)
            return true;
    }

    return false;
}

int main()
{
    while (true)
    {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        int num {};
        std::cin >> num;

        if (!std::cin)
        {
            std::cin.clear();
            std::cout << "Invalid input, please try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (num == -1)
            break;

        if (isPerfectSquare(num))
            std::cout << num << " is a perfect square\n";
        else
            std::cout << num << " is not a perfect square\n";

        std::cout << '\n';
    }

    std::cout << "Bye\n";
    return 0;
}
