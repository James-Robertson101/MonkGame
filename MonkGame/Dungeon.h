#ifndef DUNGEON_H
#define DUNGEON_H

#include "RoomFactory.h"
#include "Monk.h" // ✅ You now need this to use Monk in explore()

#include <vector>
#include <memory>
#include <string>

class Dungeon {
public:
    Dungeon();

    void generate();          // Generate the dungeon
    void explore(Monk& monk); // ✅ Pass the Monk to allow interaction in rooms

private:
    std::vector<std::shared_ptr<Room>> rooms;
    std::shared_ptr<Room> startingRoom;

    void connectRooms();      // Declaration is fine here
};

#endif // DUNGEON_H
