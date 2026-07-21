#include "Deck.h"
#include "Card.h"
#include "Random.h"
#include <algorithm>
#include <cassert>

Deck::Deck()
{
    for (auto suit : Card::allSuits)
        for (auto rank : Card::allRanks)
            m_cards[m_pointer++] = Card { rank, suit };

    m_pointer = 0;
}

Card Deck::dealCard()
{
    assert(m_pointer < m_cards.size() && "Deck::dealCard ran out of cards");
    return m_cards[m_pointer++];
}

void Deck::shuffle()
{
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    m_pointer = 0;
}
