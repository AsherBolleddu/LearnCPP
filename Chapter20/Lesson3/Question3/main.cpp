#include <iostream>

void decimalToBinary(unsigned int decimal)
{
    if (decimal > 1)
        decimalToBinary(decimal / 2);

    std::cout << decimal % 2;
}

int main()
{
    std::cout << "Enter a integer: ";
    int input {};
    std::cin >> input;

    decimalToBinary(static_cast<unsigned int>(input));

    std::cout << '\n';

    return 0;
}
