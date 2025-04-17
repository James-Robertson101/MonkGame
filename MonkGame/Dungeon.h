#ifndef DUNGEON_H
#define DUNGEON_H

#include "RoomFactory.h"
#include <vector>
#include <memory>
#include <string>

class Dungeon {
public:
    Dungeon();

    void generate(); // Generate the dungeon
    void explore();  // Explore the dungeon

private:
    std::vector<std::shared_ptr<Room>> rooms;
    std::shared_ptr<Room> startingRoom;

    void connectRooms(); // ? Declaration added here
};

#endif // DUNGEON_H
