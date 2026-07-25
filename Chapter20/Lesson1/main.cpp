#include <functional>
#include <iostream>

int getInteger()
{
    std::cout << "Enter an integer: ";
    int input;
    std::cin >> input;

    return input;
}

char getOperation()
{
    char operation;

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> operation;
    } while (operation != '+' && operation != '-' && operation != '*' && operation != '/');

    return operation;
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

using ArthmeticFunction = std::function<int(int, int)>;
ArthmeticFunction getArithmeticFunction(char operation)
{
    switch (operation)
    {
    case '+': return add;
    case '-': return subtract;
    case '*': return multiply;
    case '/': return divide;
    }

    return nullptr;
}

int main()
{
    int x { getInteger() };
    char operation { getOperation() };
    int y { getInteger() };
    ArthmeticFunction fcn { getArithmeticFunction(operation) };

    if (fcn)
        std::cout << x << ' ' << operation << ' ' << y << " = " << fcn(x, y) << '\n';

    return 0;
}
