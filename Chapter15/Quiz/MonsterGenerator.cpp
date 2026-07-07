#include "MonsterGenerator.h"
#include "Monster.h"
#include "Random.h"
#include <string_view>

namespace MonsterGenerator
{

    constexpr std::string_view getName(int num)
    {
        switch (num)
        {
        case 0:
            return "Cavernfreak";
        case 1:
            return "Bouldersword";
        case 2:
            return "Venomvine";
        case 3:
            return "Slagmirage";
        case 4:
            return "Frostthing";
        case 5:
            return "Foulwing";
        }

        return "???";
    }

    constexpr std::string_view getRoar(int num)
    {
        switch (num)
        {
        case 0:
            return "*RAAAAWWWRRGHHH*";
        case 1:
            return "*GRRROOOAAAARRR*";
        case 2:
            return "*SKREEEEEONNNK*";
        case 3:
            return "*HHHRRRAAAUUUGHHH*";
        case 4:
            return "*VRRROOOOMMMGHHAAA*";
        case 5:
            return "*YEEEARRRGHHHHKKK*";
        }

        return "???";
    }

    Monster generate()
    {
        return Monster { static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)),
                         getName(Random::get(0, 5)), getRoar(Random::get(0, 5)), Random::get(1, 100) };
    }
} // namespace MonsterGenerator
