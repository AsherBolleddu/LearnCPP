#if !defined(POTION_H)
#define POTION_H

#include <array>
#include <string_view>

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_potions,
    };

    inline constexpr std::array types { healing, mana, speed, invisibility };
    inline constexpr std::array price { 20, 30, 12, 50 };

    using namespace std::string_view_literals;
    inline constexpr std::array name { "healing"sv, "mana"sv, "speed"sv, "invisibility"sv };

    static_assert(types.size() == max_potions);
    static_assert(price.size() == max_potions);
    static_assert(name.size() == max_potions);

} // namespace Potion

#endif // POTION_H
