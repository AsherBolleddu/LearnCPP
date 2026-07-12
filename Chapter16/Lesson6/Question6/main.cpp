#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

void FizzBuzz(int iterations)
{
    static const std::vector divisors { 3, 5, 7, 11, 13, 17, 19 };
    static const std::vector<std::string_view> words { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
    assert(divisors.size() == words.size() && "Fizzbuzz: array sizes don't match");

    for (int i { 1 }; i <= iterations; ++i)
    {
        bool printed { false };
        for (std::size_t index { 0 }; index < divisors.size(); ++index)
        {
            if (i % divisors[index] == 0)
            {
                std::cout << words[index];
                printed = true;
            }
        }

        if (!printed)
            std::cout << i;

        std::cout << '\n';
    }
}

int main()
{

    FizzBuzz(150);
    return 0;
}
