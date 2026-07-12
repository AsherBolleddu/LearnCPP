#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

namespace Items
{
    enum Type
    {
        health_potion,
        torch,
        arrow,
        max_items,
    };

} // namespace Items

constexpr std::string_view getItemName(Items::Type type, int count)
{
    bool pluralize { count != 1 };

    switch (type)
    {
    case Items::health_potion: return pluralize ? "health potions" : "health potion";
    case Items::torch:         return pluralize ? "torches" : "torch";
    case Items::arrow:         return pluralize ? "arrows" : "arrow";
    default:                   return "???";
    }
}

void printInventory(const std::vector<int>& inventory)
{
    int itemCount { 0 };
    for (std::size_t i { 0 }; i < inventory.size(); ++i)
    {
        std::cout << "You have " << inventory[i] << ' ' << getItemName(static_cast<Items::Type>(i), inventory[i])
                  << '\n';
        itemCount += inventory[i];
    }

    std::cout << "You have " << itemCount << " total items\n";
}

int main()
{
    std::vector inventory { 1, 5, 10 };
    assert(std::size(inventory) == Items::max_items);

    printInventory(inventory);

    return 0;
}
