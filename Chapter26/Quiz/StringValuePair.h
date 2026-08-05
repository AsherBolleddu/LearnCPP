#if !defined(STRINGVALUEPAIR_H)
#define STRINGVALUEPAIR_H

#include "Pair.h"
#include <string>
#include <string_view>

template <typename S>
class StringValuePair : public Pair<std::string, S>
{
public:
    StringValuePair(std::string_view key, const S& value)
        : Pair<std::string, S> { static_cast<std::string>(key), value }
    {
    }
};

#endif // STRINGVALUEPAIR_H
