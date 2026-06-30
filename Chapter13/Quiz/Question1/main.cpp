#include <iostream>
#include <string_view>

struct Monster
{
    enum MonsterType
    {
        ogre,
        dragon,
        orc,
        giant_spider,
        slime,
    };

    std::string name {};
    MonsterType monsterType {};
    int health {};
};

constexpr std::string_view getMonsterName(Monster::MonsterType monsterType)
{

    switch (monsterType)
    {
    case Monster::ogre:
        return "Ogre";
    case Monster::dragon:
        return "Dragon";
    case Monster::orc:
        return "Orc";
    case Monster::giant_spider:
        return "Giant Spider";
    case Monster::slime:
        return "Slime";
    }

    return "???";
}

void printMonster(const Monster& monster)
{
    std::cout << "This " << getMonsterName(monster.monsterType) << " is named " << monster.name << " and has "
              << monster.health << " health.\n";
}

int main()
{

    printMonster(Monster { "Torg", Monster::ogre, 145 });
    printMonster(Monster { "Blurp", Monster::slime, 23 });

    return 0;
}
