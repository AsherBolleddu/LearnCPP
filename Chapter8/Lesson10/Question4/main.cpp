#include <iostream>

void fizzbuzz(int count)
{
    for (int i{1}; i <= count; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
            std::cout << "fizzbuzz";
        else if (i % 5 == 0)
            std::cout << "buzz";
        else if (i % 3 == 0)
            std::cout << "fizz";
        else
            std::cout << i;
        std::cout << '\n';
    }
}

int main()
{
    fizzbuzz(15);
    return 0;
}
