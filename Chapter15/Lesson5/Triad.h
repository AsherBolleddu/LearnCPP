#if !defined(TRIAD_H)
#define TRIAD_H

#include <iostream>

template <typename T, typename U, typename V>
class Triad
{
private:
    T m_first {};
    U m_second {};
    V m_third {};

public:
    Triad(const T& first, const U& second, const V& third);

    const T& first() const { return m_first; }
    const U& second() const { return m_second; }
    const V& third() const { return m_third; }

    void print() const;
};

template <typename T, typename U, typename V>
Triad<T, U, V>::Triad(const T& first, const U& second, const V& third)
    : m_first { first }, m_second { second }, m_third { third }
{
}

template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const
{
    std::cout << '[' << m_first << ", " << m_second << ", " << m_third << ']';
}

#endif // TRIAD_H
