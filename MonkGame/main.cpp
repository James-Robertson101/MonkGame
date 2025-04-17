#include <iostream>
#include "Dungeon.h"
int main() {
    // Create a Monk instance
    Monk monk("Hero", "A brave monk seeking adventure!");

    // Generate a dungeon and explore
    Dungeon dungeon;
    dungeon.generate();
    dungeon.explore(monk);

    return 0;
}