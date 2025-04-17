#include "TreasureRoom.h"

TreasureRoom::TreasureRoom() : Room("Treasure", "The treasure room!") {}

void TreasureRoom::onEnter() {
    std::cout << "You found the treasure! Congratulations!\n";
}