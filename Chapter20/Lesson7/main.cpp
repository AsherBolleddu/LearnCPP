#include "Random.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string_view>
#include <vector>

namespace Config
{
    constexpr int min { 2 };
    constexpr int max { 4 };
} // namespace Config

int getValues(std::string_view prompt)
{
    std::cout << prompt;
    int val {};
    std::cin >> val;

    return val;
}

std::vector<int> initializeVector(int startNum, int numbersToGenerate, int multiplier)
{
    std::vector<int> squares {};

    for (int i { 0 }; i < numbersToGenerate; ++i, ++startNum)
        squares.push_back(startNum * startNum * multiplier);

    return squares;
}

int main()
{
    int startNum { getValues("Start where? ") };
    int numbersToGenerate { getValues("How many? ") };
    int multiplier { Random::get(Config::min, Config::max) };

    std::vector squares { initializeVector(startNum, numbersToGenerate, multiplier) };

    std::cout << "I generated " << numbersToGenerate
              << " square numbers. Do you know what each number is after multiplying it by " << multiplier << "?\n";

    for (int i { 0 }; i < numbersToGenerate; ++i)
    {
        int guess { getValues("> ") };
        auto found { std::find(squares.begin(), squares.end(), guess) };

        if (found == squares.end())
        {
            const auto minElement { std::min_element(squares.begin(), squares.end(), [=](auto a, auto b) {
                return std::abs(guess - a) < std::abs(guess - b);
            }) };
            std::cout << guess << " is wrong! Try " << *minElement << " next time.\n";
            break;
        }
        else
        {
            squares.erase(found);

            if (!squares.empty())
                std::cout << "Nice! " << squares.size() << " number(s) left.\n";
            else
                std::cout << "Nice! You found all numbers, good job!\n";
        }
    }

    return 0;
}
