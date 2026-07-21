#include "Deck.h"
#include "Player.h"
#include "Settings.h"
#include <iostream>
#include <limits>

char getPlayerChoice()
{
    std::cout << "(h) to hit, or (s) to stand: ";
    while (true)
    {
        char input {};
        std::cin >> input;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That was invalid input. Please try again: ";
            continue;
        }

        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That was invalid input. Please try again: ";
            continue;
        }

        if (input != 'h' && input != 's')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That was invalid input. Please try again: ";
            continue;
        }

        return input;
    }
}

// Returns true if dealer busts, otherwise false
bool dealerTurn(Deck& deck, Player& dealer)
{
    while (dealer.score < Settings::dealerStopsAt)
    {
        Card card { deck.dealCard() };
        dealer.score += card.value();
        std::cout << "The dealer flips a " << card << ".  They now have: " << dealer.score << '\n';
    }

    if (dealer.score > Settings::bust)
    {
        std::cout << "The dealer went bust!\n";
        return true;
    }

    return false;
}

// Returns true if player busts, otherwise false
bool playerTurn(Deck& deck, Player& player)
{
    while (!(player.score > Settings::bust))
    {
        char input { getPlayerChoice() };

        switch (input)
        {
        case 'h': {
            Card card { deck.dealCard() };
            player.score += card.value();
            std::cout << "You were dealt " << card << ".  You now have: " << player.score << '\n';
            break;
        }
        case 's': return false;
        }
    }

    std::cout << "You went bust!\n";
    return true;
}

// Returns true if player wins, otherwise false is dealer wins
bool playBlackjack()
{
    Deck deck {};
    deck.shuffle();

    Player dealer { deck.dealCard().value() };
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    Player player { deck.dealCard().value() + deck.dealCard().value() };
    std::cout << "You have score: " << player.score << '\n';

    if (playerTurn(deck, player))
        return false;

    if (dealerTurn(deck, dealer))
        return true;

    return player.score > dealer.score;
}

int main()
{
    if (playBlackjack())
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";

    return 0;
}
