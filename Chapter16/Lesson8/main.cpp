#include <iostream>
#include <string>
#include <string_view>
#include <vector>

std::string getName()
{
    std::cout << "Enter a name: ";
    std::string name {};
    std::cin >> name;

    return name;
}

template <typename T>
bool isValueInArray(const std::vector<T>& v, const T& searchVal)
{
    for (const auto& val : v)
    {
        if (val == searchVal)
            return true;
    }

    return false;
}

int main()
{
    std::vector<std::string_view> names { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
    std::string searchName { getName() };

    std::cout << searchName << " was ";
    if (!isValueInArray<std::string_view>(names, searchName))
        std::cout << "not found.\n";
    else
        std::cout << "found.\n";

    return 0;
}
