#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
    std::cout << "\t(Stack:";
    if (stack.empty())
        std::cout << " empty";
    else
    {
        for (auto num : stack)
            std::cout << ' ' << num;
    }

    std::cout << ")\n";
}

void printPush(int num, std::vector<int>& stack)
{
    std::cout << "Push " << num;
    stack.push_back(num);
    printStack(stack);
}

void printPop(std::vector<int>& stack)
{
    std::cout << "Pop";
    stack.pop_back();
    printStack(stack);
}

int main()
{
    std::vector<int> stack {};

    printStack(stack);
    printPush(1, stack);
    printPush(2, stack);
    printPush(3, stack);
    printPop(stack);
    printPush(4, stack);
    printPop(stack);
    printPop(stack);
    printPop(stack);

    return 0;
}
