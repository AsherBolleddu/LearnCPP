#include <iostream>

int convertToInt(char ch)
{
    return ch;
}

int main()
{
    std::cout << "Enter a single character: ";
    char ch{};
    std::cin >> ch;

    std::cout << "You entered '" << ch << "', which has ASCII code " << static_cast<int>(ch) << ".\n";
    std::cout << "You entered '" << ch << "', which has ASCII code " << convertToInt(ch) << ".\n";

    return 0;
}
