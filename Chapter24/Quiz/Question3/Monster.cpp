#include "Monster.h"
#include "Random.h"

Monster::Monster(Type type) : Creature { monsterData[type] } {}

Monster Monster::getRandomMonster()
{
    Type type { static_cast<Type>(Random::get(0, max_types - 1)) };

    return Monster { type };
}
