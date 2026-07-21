#include <array>
#include <iostream>

template <typename T, auto N>
void printArray(const std::array<T, N>& arr)
{
    std::cout << "The array (";
    bool comma { false };
    for (const auto& e : arr)
    {
        if (comma)
            std::cout << ", ";

        std::cout << e;
        comma = true;
    }

    std::cout << ") has length " << N << '\n';
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
