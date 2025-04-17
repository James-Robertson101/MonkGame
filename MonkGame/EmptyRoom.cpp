#include "EmptyRoom.h"

EmptyRoom::EmptyRoom() : Room("Empty", "A quiet, empty room.") {}

void EmptyRoom::onEnter() {
    std::cout << "You entered an empty room. Meditating to restore health.\n";
}