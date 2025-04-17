#include "UpgradeRoom.h"
UpgradeRoom::UpgradeRoom() : Room("Upgrade", "A room with an upgrade station.") {}

void UpgradeRoom::onEnter() {
    std::cout << "You entered an upgrade room. Choose an upgrade:\n";
    std::cout << "1. Increase health by 5\n";
    std::cout << "2. Increase attack by 2\n";
}