#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t length {};
    std::cin >> length;

    std::string* names { new std::string[length] {} };

    for (std::size_t i { 0 }; i < length; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }

    std::sort(&names[0], &names[0] + length);

    std::cout << "\nHere is your sorted list:\n";
    for (std::size_t i { 0 }; i < length; ++i)
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';

    delete[] names;

    return 0;
}
