#if !defined(SESSION_H)
#define SESSION_H

#include "Settings.h"
#include "WordList.h"
#include <string_view>
#include <vector>

class Session
{
private:
    std::string_view m_word { WordList::getRandomWord() };
    int m_wrongGuessesLeft { Settings::numGuesses };
    std::vector<bool> m_letterGuessed { std::vector<bool>(26) };

public:
    std::string_view getWord() const { return m_word; }

    int wrongGuessesLeft() const { return m_wrongGuessesLeft; }
    void removeGuess() { --m_wrongGuessesLeft; }

    bool isLetterGuessed(char c) const { return m_letterGuessed[static_cast<std::size_t>(c - 'a')]; }
    void setLetterGuessed(char c) { m_letterGuessed[static_cast<std::size_t>(c - 'a')] = true; }

    bool isLetterInWord(char c) const;

    bool won() const;
};

#endif // SESSION_H
