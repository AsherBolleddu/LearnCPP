#include <array>
#include <iostream>
#include <string_view>

struct Item
{
    std::string_view name {};
    int gold {};
};

template <auto N>
void printShop(const std::array<Item, N>& items)
{
    for (const auto& item : items)
    {
        std::cout << "A " << item.name << " costs " << item.gold << ".\n";
    }
}

int main()
{
    constexpr std::array<Item, 4> items { { { "sword", 5 }, { "dagger", 3 }, { "club", 2 }, { "spear", 7 } } };

    printShop(items);

    return 0;
}
