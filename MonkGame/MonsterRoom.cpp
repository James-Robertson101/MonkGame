#include "MonsterRoom.h"
#include "Goblin.h"
#include "Monk.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

MonsterRoom::MonsterRoom() : Room("Monster", "A room with a dangerous goblin!") {}

void MonsterRoom::onEnter(Monk& monk) {
    std::cout << "You entered a monster room. A goblin appears!\n";
    Goblin goblin;

    std::srand(std::time(nullptr));
    while (monk.isAlive() && goblin.isAlive()) {
        std::cout << "\n--- Combat Turn ---\n";
        std::cout << "Monk HP: " << monk.getHealth() << " | Goblin HP: " << goblin.getHealth() << "\n";
        std::cout << "Choose your action:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Guard (+1 HP)\n";
        int choice;
        std::cin >> choice;

        bool monkSuccess = (std::rand() % 2 == 0);
        bool goblinSuccess = (std::rand() % 2 == 0);

        // Monk's turn
        if (monkSuccess) {
            if (choice == 1) {
                monk.attackEntity(goblin);
                std::cout << "You attack the goblin!\n";
            }
            else if (choice == 2) {
                monk.heal(1);
                std::cout << "You guard and regain 1 HP.\n";
            }
            else {
                std::cout << "Invalid action.\n";
            }
        }
        else {
            std::cout << "Your action failed!\n";
        }

        // Goblin's turn
        if (goblin.isAlive()) {
            if (goblinSuccess) {
                if (std::rand() % 2 == 0) {
                    goblin.attackEntity(monk);
                    std::cout << "The goblin attacks you!\n";
                }
                else {
                    goblin.heal(1);
                    std::cout << "The goblin guards and regains 1 HP.\n";
                }
            }
            else {
                std::cout << "The goblin's action failed!\n";
            }
        }
    }

    if (monk.isAlive()) {
        std::cout << "\nYou defeated the goblin!\n";
    }
    else {
        std::cout << "\nYou have been defeated by the goblin...\n";
    }
}
