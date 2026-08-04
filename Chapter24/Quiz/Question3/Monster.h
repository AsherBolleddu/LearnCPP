#if !defined(MONSTER_H)
#define MONSTER_H

#include "Creature.h"

class Monster : public Creature
{
public:
    enum Type
    {
        dragon,
        orc,
        slime,
        max_types,
    };

private:
    static inline Creature monsterData[] { Creature { "dragon", 'D', 20, 4, 100 }, Creature { "orc", 'o', 4, 2, 25 },
                                           Creature { "slime", 's', 1, 1, 10 } };

    static_assert(std::size(monsterData) == max_types);

public:
    Monster(Type type);

    static Monster getRandomMonster();
};

#endif // MONSTER_H
