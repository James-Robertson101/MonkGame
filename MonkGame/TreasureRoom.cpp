#include "TreasureRoom.h"

TreasureRoom::TreasureRoom() : Room("Treasure", "The treasure room!") {}

void TreasureRoom::onEnter(Monk& monk) {
    std::cout << "You found the treasure! You win!\n";
}