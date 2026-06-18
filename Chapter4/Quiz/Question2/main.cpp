#include <iostream>

double getDouble()
{
    std::cout << "Enter a double value: ";
    double num{};
    std::cin >> num;

    return num;
}

char getOperation()
{
    std::cout << "Enter +, -, *, or /: ";
    char ch{};
    std::cin >> ch;

    return ch;
}

void displayResult(double x, double y, char op)
{
    double result{};

    if (op == '+')
        result = x + y;
    else if (op == '-')
        result = x - y;
    else if (op == '*')
        result = x * y;
    else if (op == '/')
        result = x / y;
    else
        return;

    std::cout << x << ' ' << op << ' ' << y << " is " << result << '\n';
}

int main()
{
    double x{getDouble()};
    double y{getDouble()};
    char op{getOperation()};

    displayResult(x, y, op);
    return 0;
}
