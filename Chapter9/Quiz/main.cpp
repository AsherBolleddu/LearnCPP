#include "Random.h"
#include <iostream>
#include <limits>

int getGuess(int guessNum, int minVal, int maxVal)
{
    while (true)
    {
        std::cout << "Guess #" << guessNum << ": ";
        int guess{};
        std::cin >> guess;

        bool success{std::cin};
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!success || guess < minVal || guess > maxVal)
        {
            std::cout << "Invalid guess. Please try again.\n";
            continue;
        }

        return guess;
    }
}

bool playAgain()
{
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        char ch{};
        std::cin >> ch;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (ch)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        }
    }
}

bool playHiLo(int minVal, int maxVal, int numGuesses)
{

    const int randomNum{Random::get(minVal, maxVal)};
    std::cout << "Let's play a game. I'm thinking of a number between " << minVal << " and " << maxVal << ". You have "
              << numGuesses << " tries to guess what it is.\n";

    for (int guessNum{1}; guessNum <= numGuesses; ++guessNum)
    {
        int guess{getGuess(guessNum, minVal, maxVal)};

        if (guess > randomNum)
            std::cout << "Your guess is too high.\n";
        else if (guess < randomNum)
            std::cout << "Your guess is too low.\n";
        else
        {
            std::cout << "Correct! You win!\n";
            return true;
        }
    }

    std::cout << "Sorry, you lose. The correct number was " << randomNum << ".\n";
    return false;
}

int main()
{
    constexpr int minVal{1};
    constexpr int maxVal{100};
    constexpr int numGuesses{7};

    do
    {
        playHiLo(minVal, maxVal, numGuesses);
    } while (playAgain());

    std::cout << "Thank you for playing.\n";

    return 0;
}
