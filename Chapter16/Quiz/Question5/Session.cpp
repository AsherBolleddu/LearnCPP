#include "Session.h"

bool Session::isLetterInWord(char c) const
{
    for (auto ch : m_word)
    {
        if (c == ch)
            return true;
    }

    return false;
}

bool Session::won() const
{
    for (auto c : m_word)
    {
        if (!isLetterGuessed(c))
            return false;
    }

    return true;
}
