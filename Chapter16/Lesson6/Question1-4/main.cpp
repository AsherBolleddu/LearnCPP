#include <iostream>
#include <limits>
#include <optional>
#include <string_view>
#include <vector>

template <typename T>
T getValidNumber(std::string_view prompt, T low, T high)
{
    T val {};
    do
    {
        std::cout << prompt;
        std::cin >> val;

        if (!std::cin)
            std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (val < low || val > high);

    return val;
}

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (std::size_t i { 0 }; i < arr.size(); ++i)
    {
        std::cout << arr[i] << ' ';
    }

    if (arr.size() > 0)
        std::cout << '\n';
}

template <typename T>
std::optional<std::size_t> findIndex(const std::vector<T>& arr, const T& searchValue)
{
    for (std::size_t i { 0 }; i < arr.size(); ++i)
    {
        if (arr[i] == searchValue)
            return i;
    }

    return {};
}

int main()
{
    // std::vector arr { 4, 6, 7, 3, 8, 2, 1, 9 };
    std::vector arr { 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };
    auto searchValue { getValidNumber("Enter a number between 1 and 9: ", 1.0, 9.0) };

    printArray(arr);
    auto index { findIndex(arr, searchValue) };

    std::cout << "The number " << searchValue;

    if (!index)
        std::cout << " was not found\n";
    else
        std::cout << " has index " << *index << '\n';

    return 0;
}
