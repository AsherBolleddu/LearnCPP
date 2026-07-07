#if !defined(MONSTERGENERATOR_H)
#define MONSTERGENERATOR_H

#include "Monster.h"
#include <string_view>

namespace MonsterGenerator
{
    constexpr std::string_view getName(int num);
    constexpr std::string_view getRoar(int num);
    Monster generate();
} // namespace MonsterGenerator

#endif // MONSTERGENERATOR_H
