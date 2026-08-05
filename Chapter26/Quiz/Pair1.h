#if !defined(PAIR1_H)
#define PAIR1_H

template <typename T>
class Pair1
{
private:
    T m_x;
    T m_y;

public:
    Pair1(const T& x, const T& y) : m_x { x }, m_y { y } {}

    T& first() { return m_x.first; }
    T& second() { return m_y.second; }
    const T& first() const { return m_x.first; }
    const T& second() const { return m_y.second; }
};

#endif // PAIR1_H
