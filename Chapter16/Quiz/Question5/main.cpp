#include "Session.h"
#include <iostream>
#include <limits>

char getLetterGuess(const Session& session)
{
    while (true)
    {
        std::cout << "Enter your next letter: ";
        char ch {};
        std::cin >> ch;

        if (!std::cin)
        {
            std::cin.clear();
            std::cout << "That wasn't a valid input.  Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (ch < 'a' || ch > 'z')
        {
            std::cout << "That wasn't a valid input.  Try again.\n";
            continue;
        }

        if (session.isLetterGuessed(ch))
        {
            std::cout << "You already guessed that.  Try again.\n";
            continue;
        }

        return ch;
    }
}

void draw(const Session& session)
{
    std::cout << '\n';

    std::cout << "The word: ";
    for (auto c : session.getWord())
    {
        if (session.isLetterGuessed(c))
            std::cout << c;
        else
            std::cout << "_";
    }

    std::cout << "   Wrong guesses: ";
    for (int i { 0 }; i < session.wrongGuessesLeft(); ++i)
        std::cout << '+';

    for (char c { 'a' }; c <= 'z'; ++c)
        if (session.isLetterGuessed(c) && !session.isLetterInWord(c))
            std::cout << c;

    std::cout << '\n';
}

void handleGuess(Session& session, char c)
{
    session.setLetterGuessed(c);

    if (!session.isLetterInWord(c))
    {
        std::cout << "No, '" << c << "' is not in the word!\n";
        session.removeGuess();
        return;
    }

    std::cout << "Yes, '" << c << "' is in the word!\n";
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    Session session {};

#ifndef NDEBUG
    std::cout << "Hint: the word is: " << session.getWord() << '\n';
#endif

    while (session.wrongGuessesLeft() && !session.won())
    {
        draw(session);
        char guess { getLetterGuess(session) };
        handleGuess(session, guess);
    }

    draw(session);

    if (!session.wrongGuessesLeft())
        std::cout << "You lost!  The word was: " << session.getWord() << '\n';
    else
        std::cout << "You won!\n";

    return 0;
}
