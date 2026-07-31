#include <cassert>
#include <cstddef>
#include <iostream>
#include <utility>

class IntArray
{
private:
    int* m_data { nullptr };
    int m_size { 0 };

public:
    explicit IntArray(int size) : m_size { size }
    {
        assert(m_size > 0);
        m_data = new int[static_cast<std::size_t>(m_size)] {};
    }

    IntArray(const IntArray& source) : m_size { source.m_size }
    {
        m_data = new int[static_cast<std::size_t>(m_size)] {};

        for (int i { 0 }; i < m_size; ++i)
            m_data[i] = source.m_data[i];
    }

    int& operator[](int index) { return const_cast<int&>(std::as_const(*this)[index]); }
    const int& operator[](int index) const
    {
        assert(index >= 0 && index < m_size);
        return m_data[index];
    }

    IntArray& operator=(const IntArray& source)
    {
        if (this == &source)
            return *this;

        delete[] m_data;

        m_size = source.m_size;

        m_data = new int[static_cast<std::size_t>(m_size)] {};
        for (int i { 0 }; i < m_size; ++i)
            m_data[i] = source.m_data[i];

        return *this;
    }

    ~IntArray() { delete[] m_data; }

    friend std::ostream& operator<<(std::ostream& out, const IntArray& arr);
};

std::ostream& operator<<(std::ostream& out, const IntArray& arr)
{
    for (int i { 0 }; i < arr.m_size; ++i)
        out << arr.m_data[i] << ' ';

    return out;
}

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a { fillArray() };

    std::cout << a << '\n';

    auto& ref { a };
    a = ref;

    IntArray b(1);
    b = a;

    a[4] = 7;

    std::cout << b << '\n';

    return 0;
}
