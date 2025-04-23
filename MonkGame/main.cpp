#include <iostream>
#include "Dungeon.h"

int main() {
    // Create a Monk instance
    std::string monkName;
    std::string monkDescription;

    std::cout << "Enter your Monk's name: ";
    std::getline(std::cin, monkName);

    std::cout << "Enter a description for your Monk: ";
    std::getline(std::cin, monkDescription);
    
    Monk monk(monkName, monkDescription);

    // Generate a dungeon and explore
    Dungeon dungeon;
    dungeon.generate();
    dungeon.explore(monk);

    return 0;
}