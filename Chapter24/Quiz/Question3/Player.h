#if !defined(PLAYER_H)
#define PLAYER_H

#include "Creature.h"
#include <string_view>

class Player : public Creature
{
private:
    int m_level { 1 };

public:
    Player(std::string_view name);

    void levelUp();

    int getLevel() const { return m_level; }
    bool hasWon() const { return m_level >= 20; }
};

#endif // PLAYER_H
