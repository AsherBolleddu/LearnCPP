#include "WordList.h"
#include "Random.h"
#include <string_view>
#include <vector>

namespace
{
    std::vector<std::string_view> words { "mystery", "broccoli",  "account",  "almost", "spaghetti",
                                          "opinion", "beautiful", "distance", "luggage" };
} // namespace

namespace WordList
{
    std::string_view getRandomWord()
    {
        return words[Random::get<std::size_t>(0, words.size() - 1)];
    }

} // namespace WordList
