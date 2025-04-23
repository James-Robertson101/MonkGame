#ifndef DUNGEON_H
#define DUNGEON_H

#include "RoomFactory.h"
#include "HUD.h"
#include <vector>
#include <memory>
#include <string>

class Dungeon {
public:
    Dungeon();
    void generate();              // Generate the dungeon
    void explore(std::shared_ptr<Monk> monk); // Explore the dungeon

private:
    std::vector<std::shared_ptr<Room>> rooms;
    std::shared_ptr<Room> startingRoom;
    std::shared_ptr<HUD> hud;

    void connectRooms(); // Connect the rooms in a linear fashion
};

#endif // DUNGEON_H
