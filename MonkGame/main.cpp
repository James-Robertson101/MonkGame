#include "RoomFactory.h"
#include <iostream>

int main() {
    // Create rooms using the factory
    auto emptyRoom = RoomFactory::createRoom("Empty");
    auto monsterRoom = RoomFactory::createRoom("Monster");
    auto upgradeRoom = RoomFactory::createRoom("Upgrade");
    auto treasureRoom = RoomFactory::createRoom("Treasure");

    // Simulate entering rooms
    emptyRoom->onEnter();
    monsterRoom->onEnter();
    upgradeRoom->onEnter();
    treasureRoom->onEnter();
    emptyRoom->addConnection(monsterRoom);
    emptyRoom->addConnection(upgradeRoom);

    return 0;
}