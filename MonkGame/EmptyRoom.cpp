#include "EmptyRoom.h"

EmptyRoom::EmptyRoom() : Room("Empty", "A quiet, empty room.") {}

void EmptyRoom::onEnter(Monk& monk) {
    std::cout << "You entered an empty room. Meditating to restore full health.\n";
    monk.heal(monk.getMaxHealth()); // Fully heal
}