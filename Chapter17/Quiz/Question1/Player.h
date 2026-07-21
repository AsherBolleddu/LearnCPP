#if !defined(PLAYER_H)
#define PLAYER_H

#include "Potion.h"
#include <array>
#include <string>
#include <string_view>

class Player
{
private:
    static constexpr int s_minStartingGold { 80 };
    static constexpr int s_maxStartingGold { 120 };

    std::string m_name {};
    int m_gold {};
    std::array<int, Potion::max_potions> m_inventory {};

public:
    explicit Player(std::string_view name);

    int getGold() const { return m_gold; }
    const std::string& getName() const { return m_name; }

    bool buyPotion(Potion::Type type);

    void displayInventory() const;
};

#endif // PLAYER_H
