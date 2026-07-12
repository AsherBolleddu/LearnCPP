#include <iostream>
#include <vector>

int main()
{
    std::vector hello { 'h', 'e', 'l', 'l', 'o' };
    std::cout << "The array has " << std::ssize(hello) << " elements.\n";
    std::cout << hello[1] << hello.at(1) << '\n';
    return 0;
}
