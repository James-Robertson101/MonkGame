#include "MonsterRoom.h"
// MonsterRoom implementation
MonsterRoom::MonsterRoom() : Room("Monster", "A room with a dangerous goblin!") {}

void MonsterRoom::onEnter() {
    std::cout << "You entered a monster room. Prepare for combat!\n";
}
