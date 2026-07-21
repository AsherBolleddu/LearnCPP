#if !defined(CARD_H)
#define CARD_H

#include <array>
#include <iostream>

struct Card
{
    enum Rank
    {
        ace,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        max_ranks,
    };

    enum Suits
    {
        club,
        diamond,
        heart,
        spade,
        max_suits,
    };

    static constexpr std::array<Rank, max_ranks> allRanks {
        ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king,
    };
    static constexpr std::array<Suits, max_suits> allSuits {
        club,
        diamond,
        heart,
        spade,
    };

    static_assert(allRanks.size() == max_ranks);
    static_assert(allSuits.size() == max_suits);

    Rank rank {};
    Suits suit {};

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    int value() const;
};

#endif // CARD_H
