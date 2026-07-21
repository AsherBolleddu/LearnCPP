#include "Card.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    static constexpr std::array ranks { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
    static constexpr std::array suits { 'C', 'D', 'H', 'S' };

    static_assert(ranks.size() == Card::max_ranks);
    static_assert(suits.size() == Card::max_suits);

    return out << ranks[card.rank] << suits[card.suit];
}

int Card::value() const
{
    static constexpr std::array rankValues { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
    static_assert(rankValues.size() == max_ranks);

    return rankValues[rank];
}
