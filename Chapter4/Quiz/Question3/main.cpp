#include <iostream>

double getTowerHeight()
{
    std::cout << "Enter the height of the tower in in meters: ";
    double height{};
    std::cin >> height;

    return height;
}

double calculateBallHeight(double towerHeight, int seconds)
{
    double gravity{9.8};
    double distanceFallen{(gravity * seconds * seconds) / 2};
    double ballHeight{towerHeight - distanceFallen};

    if (ballHeight < 0.0)
        return 0.0;

    return ballHeight;
}

void displayBallHeight(double towerHeight, int seconds)
{
    double ballHeight{calculateBallHeight(towerHeight, seconds)};

    std::cout << "At " << seconds << " seconds, the ball is ";
    if (ballHeight > 0.0)
        std::cout << "at height: " << ballHeight << " meters\n";
    else
        std::cout << "on the ground.\n";
}

int main()
{
    double towerHeight{getTowerHeight()};

    displayBallHeight(towerHeight, 0);
    displayBallHeight(towerHeight, 1);
    displayBallHeight(towerHeight, 2);
    displayBallHeight(towerHeight, 3);
    displayBallHeight(towerHeight, 4);
    displayBallHeight(towerHeight, 5);

    return 0;
}
