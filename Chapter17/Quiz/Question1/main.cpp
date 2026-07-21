#include "Player.h"
#include "Potion.h"
#include <iostream>
#include <limits>
#include <string>

int charNumToInt(char ch)
{
    return ch - '0';
}

std::string getPlayerName()
{
    std::cout << "Enter your name: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);

    return name;
}

Potion::Type getPotionChoice()
{
    std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";

    while (true)
    {
        char input {};
        std::cin >> input;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That is an invalid input.  Try again: ";
            continue;
        }

        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That is an invalid input.  Try again: ";
            continue;
        }

        if (input == 'q')
            return Potion::max_potions;

        int potionChoice { charNumToInt(input) };
        if (potionChoice < 0 || potionChoice >= Potion::max_potions)
        {
            std::cout << "That is an invalid input.  Try again: ";
            continue;
        }

        return static_cast<Potion::Type>(potionChoice);
    }
}

void shop(Player& player)
{

    while (true)
    {
        std::cout << "\nHere is our selection for today:\n";
        for (auto type : Potion::types)
            std::cout << type << ") " << Potion::name[type] << " costs " << Potion::price[type] << '\n';

        Potion::Type type { getPotionChoice() };

        if (type == Potion::max_potions)
            return;

        if (!player.buyPotion(type))
            std::cout << "You can not afford that.\n";
        else
            std::cout << "You purchased a potion of " << Potion::name[type] << "  You have " << player.getGold()
                      << " gold left.\n";
    }
}

int main()
{
    Player player { getPlayerName() };
    std::cout << "Hello, " << player.getName() << ", you have " << player.getGold() << " gold.\n";

    shop(player);

    std::cout << '\n';

    player.displayInventory();
    std::cout << "You escaped with " << player.getGold() << " gold remaining.\n";

    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
    return 0;
}
