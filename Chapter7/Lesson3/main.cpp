#include <iostream>
#include <string_view>

int getInt(std::string_view prompt)
{
    std::cout << prompt;
    int num{};
    std::cin >> num;

    return num;
}

int main()
{
    int smaller{getInt("Enter an integer: ")};
    int larger{getInt("Enter a larger integer: ")};

    if (smaller > larger)
    {
        std::cout << "Swapping the values\n";
        int temp{larger};
        larger = smaller;
        smaller = temp;
    }

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
}
