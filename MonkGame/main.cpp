#include <iostream>
#include <memory>
#include "Dungeon.h"
#include "HUD.h" // Include HUD header

int main() {
    // Get Monk details from user
    std::string monkName;
    std::string monkDescription;

    std::cout << "Enter your Monk's name: ";
    std::getline(std::cin, monkName);

    std::cout << "Enter a description for your Monk: ";
    std::getline(std::cin, monkDescription);

    // Create a shared pointer to the Monk (with hardcoded health and attack)
    std::shared_ptr<Monk> monk = std::make_shared<Monk>(monkName, monkDescription);

    // Create and initialize HUD as observer
    HUD hud(monk);

    // Create and generate the dungeon
    Dungeon dungeon;
    dungeon.generate();

    // Begin exploration
    dungeon.explore(monk);

    return 0;
}
