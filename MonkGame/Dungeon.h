#ifndef DUNGEON_H
#define DUNGEON_H

#include "RoomFactory.h"
#include <vector>
#include <memory>
#include <string>
#include "Monk.h"

class Dungeon {
public:
    Dungeon();
    void generate(); // Generate the dungeon
    void explore(Monk& monk);  // Explore the dungeon

private:
    std::vector<std::shared_ptr<Room>> rooms;
    std::shared_ptr<Room> startingRoom;

    void connectRooms(); // Connect the rooms in a linear fashion
    void displayMonkStatus(const Monk& monk); // Display Monk's status (HP)
};

#endif // DUNGEON_H
