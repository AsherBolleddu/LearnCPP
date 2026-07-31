#if !defined(FIXEDPOINT2_H)
#define FIXEDPOINT2_H

#include <cstdint>
#include <iostream>

class FixedPoint2
{
private:
    std::int16_t m_base {};
    std::int8_t m_decimal {};

public:
    FixedPoint2(std::int16_t base = 0, std::int8_t decimal = 0);
    FixedPoint2(double d = 0.0);
    explicit operator double() const;
    FixedPoint2 operator-() const;
    friend bool testDecimal(const FixedPoint2& fp);
    friend bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& num);
std::istream& operator>>(std::istream& in, FixedPoint2& fp);
FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2);

#endif // FIXEDPOINT2_H
