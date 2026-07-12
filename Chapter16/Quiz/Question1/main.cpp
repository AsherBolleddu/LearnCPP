#include <string_view>
#include <vector>

int main()
{
    // A.
    std::vector evens { 2, 4, 6, 8, 10, 12 };

    // B.
    const std::vector d { 1.2, 3.4, 5.6, 7.8 };

    // C.
    using namespace std::literals::string_view_literals;
    const std::vector names { "Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv };

    // D.
    std::vector single { 12 };

    // E.
    std::vector<int> multiple(12);

    return 0;
}
