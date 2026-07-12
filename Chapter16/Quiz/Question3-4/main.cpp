#include <iostream>
#include <optional>
#include <utility>
#include <vector>

std::vector<int> initVector()
{
    std::vector<int> nums {};

    std::cout << "Enter numbers to add (use -1 to stop): ";
    int num {};
    while (std::cin >> num && num != -1)
        nums.push_back(num);

    return nums;
}

template <typename T>
void printArray(const std::vector<T>& arr)
{
    if (arr.empty())
    {
        std::cout << "There exists no elements in the array\n";
        return;
    }

    std::cout << "With array ( ";
    for (std::size_t i { 0 }; i < arr.size(); ++i)
    {
        if (i == arr.size() - 1)
            std::cout << arr[i] << ' ';
        else
            std::cout << arr[i] << ", ";
    }

    std::cout << "):\n";
}

using OptionalPair = std::optional<std::pair<std::size_t, std::size_t>>;

template <typename T>
OptionalPair getMinMax(const std::vector<T>& arr)
{
    if (arr.empty())
        return {};

    OptionalPair minMax { { 0, 0 } };

    for (std::size_t i { 0 }; i < arr.size(); ++i)
    {
        if (arr[i] < arr[minMax->first])
            minMax->first = i;
        if (arr[i] > arr[minMax->second])
            minMax->second = i;
    }

    return minMax;
}

template <typename T>
void printMinMax(const std::vector<T>& arr, const OptionalPair& minMax)
{
    if (!minMax)
    {
        std::cout << "There is no min or max element because the array is empty\n";
        return;
    }

    std::cout << "The min element has index " << minMax->first << " and value " << arr[minMax->first] << '\n';
    std::cout << "The max element has index " << minMax->second << " and value " << arr[minMax->second] << '\n';
}

int main()
{

    std::vector<int> nums { initVector() };
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    printArray(nums);
    printMinMax(nums, getMinMax(nums));

    std::cout << '\n';

    printArray(v1);
    printMinMax(v1, getMinMax(v1));

    std::cout << '\n';

    printArray(v2);
    printMinMax(v2, getMinMax(v2));

    return 0;
}
