#include "FixedPoint2.h"
#include <cmath>
#include <iostream>

FixedPoint2::FixedPoint2(std::int16_t base, std::int8_t decimal) : m_base { base }, m_decimal { decimal }
{
    if (m_base < 0 || m_decimal < 0)
    {
        if (m_base > 0)
            m_base = static_cast<std::int16_t>(-m_base);
        if (m_decimal > 0)
            m_decimal = static_cast<std::int8_t>(-m_decimal);
    }

    m_base += m_decimal / 100;
    m_decimal = m_decimal % 100;
}

FixedPoint2::FixedPoint2(double d)
    : FixedPoint2 { static_cast<std::int16_t>(std::trunc(d)),
                    static_cast<std::int8_t>(std::round(d * 100) - std::trunc(d) * 100) }
{
}

FixedPoint2::operator double() const
{
    return m_base + (static_cast<double>(m_decimal) / 100);
}

bool testDecimal(const FixedPoint2& fp)
{
    if (fp.m_base >= 0)
        return fp.m_decimal >= 0 && fp.m_decimal < 100;
    else
        return fp.m_decimal <= 0 && fp.m_decimal > -100;
}

std::ostream& operator<<(std::ostream& out, const FixedPoint2& num)
{
    return out << static_cast<double>(num);
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp)
{
    double d {};
    in >> d;
    fp = FixedPoint2 { d };

    return in;
}

bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
    return fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal;
}

FixedPoint2 FixedPoint2::operator-() const
{
    return FixedPoint2 { -static_cast<double>(*this) };
}

FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
    return FixedPoint2 { static_cast<double>(fp1) + static_cast<double>(fp2) };
}
