#include <iostream>

void printString(const char str[])
{
    for (; *str != '\0'; ++str)
        std::cout << *str;
}

void printReverseString(const char str[])
{
    const auto* begin { str };

    while (*str != '\0')
        ++str;

    for (; str-- != begin;)
        std::cout << *str;
}

int main()
{
    printString("Hello, world!");
    std::cout << '\n';

    printReverseString("Hello, world!");
    std::cout << '\n';

    return 0;
}
