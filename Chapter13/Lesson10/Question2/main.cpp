#include <iostream>

struct Fraction
{
    int numerator { 0 };
    int denominator { 1 };
};

Fraction getFraction()
{
    Fraction temp {};

    std::cout << "Enter a value for the numerator: ";
    std::cin >> temp.numerator;

    std::cout << "Enter a value for the denominator: ";
    std::cin >> temp.denominator;

    return temp;
}

constexpr Fraction multiply(const Fraction& x, const Fraction& y)
{
    return { x.numerator * y.numerator, x.denominator * y.denominator };
}

void printFraction(const Fraction& fraction)
{
    std::cout << fraction.numerator << '/' << fraction.denominator << '\n';
}

int main()
{
    Fraction x { getFraction() };
    std::cout << '\n';

    Fraction y { getFraction() };
    std::cout << '\n';

    std::cout << "Your fractions multiplied together: ";
    printFraction(multiply(x, y));

    return 0;
}
