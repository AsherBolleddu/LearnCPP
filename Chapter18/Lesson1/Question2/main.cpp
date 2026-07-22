#include <iostream>
#include <utility>

int main()
{
    int array[] { 30, 50, 20, 10, 40 };
    constexpr int length { static_cast<int>(std::size(array)) };

    for (int i { 0 }; i < length - 1; ++i)
    {
        int largestIndex { i };

        for (int j { i + 1 }; j < length; ++j)
        {
            if (array[j] > array[largestIndex])
                largestIndex = j;
        }

        std::swap(array[i], array[largestIndex]);
    }

    for (int index { 0 }; index < length; ++index)
        std::cout << array[index] << ' ';
    std::cout << '\n';

    return 0;
}
