#if !defined(DECK_H)
#define DECK_H

#include "Card.h"
#include <array>

class Deck
{
private:
    std::size_t m_pointer { 0 };
    std::array<Card, 52> m_cards {};

public:
    Deck();
    Card dealCard();
    void shuffle();
};

#endif // DECK_H
