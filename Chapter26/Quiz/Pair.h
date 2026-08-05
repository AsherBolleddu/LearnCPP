#if !defined(PAIR_H)
#define PAIR_H

template <typename T, typename S>
class Pair
{
private:
    T m_x;
    S m_y;

public:
    Pair(const T& x, const S& y) : m_x { x }, m_y { y } {}

    T& first() { return m_x; }
    S& second() { return m_y; }
    const T& first() const { return m_x; }
    const S& second() const { return m_y; }
};

#endif // PAIR_H
