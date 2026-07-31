#include "Average.h"
#include <cstdint>
#include <iostream>

Average& Average::operator+=(std::int32_t num)
{
    m_sum += num;
    ++m_count;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
    if (avg.m_count == 0)
        return out << 0;

    return out << static_cast<double>(avg.m_sum) / avg.m_count;
}
