#include "UpgradeRoom.h"
UpgradeRoom::UpgradeRoom() : Room("Upgrade", "A room with an upgrade station.") {}

void UpgradeRoom::onEnter(Monk& monk) {
    std::cout << "You entered an upgrade room. Choose an upgrade:\n";
    std::cout << "1. Increase health by 5\n";
    std::cout << "2. Increase attack by 2\n";

    int choice = -1;
    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
        }
        else if (choice == 1) {
            monk.increaseHealth(5);
            std::cout << "Max health increased!\n";
            break;
        }
        else if (choice == 2) {
            monk.increaseAttack(2);
            std::cout << "Attack power increased!\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}
