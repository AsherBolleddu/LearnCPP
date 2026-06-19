#include <iostream>
#include <string>
#include <string_view>

std::string getName(int id)
{
    std::cout << "Enter the name of person #" << id << ": ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    return name;
}

int getAge(std::string_view name)
{
    std::cout << "Enter the age of " << name << ": ";
    int age{};
    std::cin >> age;

    return age;
}

void displayOlder(std::string_view personOne, int ageOne, std::string_view personTwo, int ageTwo)
{
    if (ageOne > ageTwo)
        std::cout << personOne << " (age " << ageOne << ") is older than " << personTwo << " (age " << ageTwo << ").\n";
    else
        std::cout << personTwo << " (age " << ageTwo << ") is older than " << personOne << " (age " << ageOne << ").\n";
}

int main()
{
    const std::string personOne{getName(1)};
    const int ageOne{getAge(personOne)};

    const std::string personTwo{getName(2)};
    const int ageTwo{getAge(personTwo)};

    displayOlder(personOne, ageOne, personTwo, ageTwo);

    return 0;
}
