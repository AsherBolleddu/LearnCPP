#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class MyString
{
private:
    std::string m_str {};

public:
    explicit MyString(std::string_view str) : m_str { str } {}

    std::string_view operator()(std::size_t index, std::size_t length) const;

    friend std::ostream& operator<<(std::ostream& out, const MyString& myStr);
};

std::string_view MyString::operator()(std::size_t start, std::size_t length) const
{
    assert(start >= 0);
    assert(start + length <= m_str.length() && "MyString::operator(int, int): Substring is out of range");

    return std::string_view { m_str }.substr(start, length);
}

std::ostream& operator<<(std::ostream& out, const MyString& myStr)
{
    return out << myStr.m_str;
}

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}
