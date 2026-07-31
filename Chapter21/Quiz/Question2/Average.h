#if !defined(AVERAGE_H)
#define AVERAGE_H

#include <cstdint>
#include <iostream>

class Average
{
public:
    std::int32_t m_sum { 0 };
    int m_count { 0 };

public:
    Average& operator+=(std::int32_t num);

    friend std::ostream& operator<<(std::ostream& out, const Average& avg);
};

#endif // AVERAGE_H
