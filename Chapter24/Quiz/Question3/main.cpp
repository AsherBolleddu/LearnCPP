#include "Monster.h"
#include "Player.h"
#include "Random.h"
#include <iostream>
#include <string>

std::string getPlayerName()
{
    std::cout << "Enter your name: ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);

    return name;
}

void attackPlayer(Player& player, const Monster& monster)
{
    if (monster.isDead())
        return;

    player.reduceHealth(monster.getDamage());
    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
}

void attackMonster(Player& player, Monster& monster)
{
    if (player.isDead())
        return;

    monster.reduceHealth(player.getDamage());
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";

    if (monster.isDead())
    {
        std::cout << "You killed the " << monster.getName() << ".\n";
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";
        std::cout << "You found " << monster.getGold() << ".\n";
        player.addGold(monster.getGold());
    }
}

void fightMonster(Player& player)
{
    Monster monster { Monster::getRandomMonster() };
    std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

    while (!monster.isDead() && !player.isDead())
    {
        std::cout << "(R)un or (F)ight: ";
        char choice {};
        std::cin >> choice;

        switch (choice)
        {
        case 'f':
        case 'F':
            attackMonster(player, monster);
            attackPlayer(player, monster);
            break;

        case 'r':
        case 'R':
            if (Random::get(0, 1))
            {
                std::cout << "You successfully fled.\n";
                return;
            }

            std::cout << "You failed to flee.\n";
            attackPlayer(player, monster);
            continue;
        }
    }
}

int main()
{
    Player player { getPlayerName() };
    std::cout << "Welcome " << player.getName() << ".\n";

    while (!player.isDead() && !player.hasWon())
        fightMonster(player);

    if (player.isDead())
    {
        std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
        std::cout << "Too bad you can't take it with you!\n";
    }
    else
        std::cout << "You won the game with " << player.getGold() << " gold!\n";

    return 0;
}
