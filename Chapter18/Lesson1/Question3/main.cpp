#include <iostream>
#include <utility>

int main()
{
    int array[] { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length { static_cast<int>(std::size(array)) };

    for (int iteration { 0 }; iteration < length - 1; ++iteration)
    {
        bool swapped { false };
        for (int i { 1 }; i < length - iteration; ++i)
        {
            if (array[i - 1] > array[i])
            {
                std::swap(array[i - 1], array[i]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            std::cout << "Early termination on iteration " << iteration + 1 << '\n';
            break;
        }
    }

    for (auto e : array)
    {
        std::cout << e << ' ';
    }

    std::cout << '\n';

    return 0;
}
