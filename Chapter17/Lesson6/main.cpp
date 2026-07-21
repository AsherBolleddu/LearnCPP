#include <array>
#include <iostream>
#include <string>
#include <string_view>

namespace Animal
{
    enum Type
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals,
    };

    struct Data
    {
        std::string_view animalName {};
        std::string_view animalSound {};
        int numLegs {};
    };

    constexpr std::array<Data, max_animals> animals { { { "chicken", "cluck", 2 },
                                                        { "dog", "woof", 4 },
                                                        { "cat", "meow", 4 },
                                                        { "elephant", "pawoo", 4 },
                                                        { "duck", "quack", 2 },
                                                        { "snake", "hissss", 0 } } };
    constexpr std::array<Type, max_animals> types { chicken, dog, cat, elephant, duck, snake };

    static_assert(max_animals == std::size(animals));
    static_assert(max_animals == std::size(types));

} // namespace Animal

std::istream& operator>>(std::istream& in, Animal::Type& type)
{

    std::string input {};
    std::getline(in >> std::ws, input);

    for (auto i(0uz); i < Animal::animals.size(); ++i)
    {
        if (input == Animal::animals[i].animalName)
        {
            type = static_cast<Animal::Type>(i);
            return in;
        }
    }

    in.setstate(std::ios_base::failbit);

    return in;
}

void printAnimal(Animal::Type type)
{
    const auto& animalData { Animal::animals[type] };
    std::cout << "A " << animalData.animalName << " has " << animalData.numLegs << " and says "
              << animalData.animalSound << ".\n";
}

void printAnimals(Animal::Type findType)
{
    std::cout << "\nHere is the data for the rest of the animals:\n";
    for (auto type : Animal::types)
    {
        if (findType != type)
            printAnimal(type);
    }
}

int main()
{
    std::cout << "Enter an animal: ";
    Animal::Type type {};
    std::cin >> type;

    if (!std::cin)
    {
        std::cin.clear();
        std::cout << "That animal couldn't be found.\n";
        type = Animal::max_animals;
    }
    else
        printAnimal(type);

    printAnimals(type);
    return 0;
}
