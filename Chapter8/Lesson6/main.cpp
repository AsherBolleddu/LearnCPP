#include <iostream>
#include <string_view>

int getInteger(std::string_view prompt)
{
    std::cout << prompt;
    int num{};
    std::cin >> num;

    return num;
}

char getOperation()
{
    std::cout << "Enter +, -, *, /, or %: ";
    char op{};
    std::cin >> op;

    return op;
}

int calculate(int x, int y, char operation)
{
    switch (operation)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '%':
        return x % y;
    default:
        std::cout << "calculate(): Unhandled case\n";
        return 0;
    }
}

int main()
{
    int x{getInteger("Enter an integer: ")};
    int y{getInteger("Enter another integer: ")};
    char operation{getOperation()};

    int result{calculate(x, y, operation)};

    std::cout << x << ' ' << operation << ' ' << y << " is " << result << '\n';
    return 0;
}
