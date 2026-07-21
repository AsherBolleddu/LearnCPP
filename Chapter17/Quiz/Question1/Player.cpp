#include "Player.h"
#include "Potion.h"
#include "Random.h"
#include <iostream>
#include <string_view>

Player::Player(std::string_view name) : m_name { name }, m_gold { Random::get(s_minStartingGold, s_maxStartingGold) } {}

bool Player::buyPotion(Potion::Type type)
{
    const int price { Potion::price[type] };

    if (m_gold < price)
        return false;

    m_gold -= price;
    ++m_inventory[type];

    return true;
}

void Player::displayInventory() const
{
    std::cout << "Your inventory contains:\n";

    for (auto type : Potion::types)
    {
        int potionCount { m_inventory[type] };
        if (potionCount > 0)
            std::cout << potionCount << "x potion of " << Potion::name[type] << '\n';
    }
}
