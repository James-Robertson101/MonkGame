#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <memory> // For smart pointers
#include <iostream>
#include "Monk.h"

class Room {
public:
    Room(const std::string& type, const std::string& description);
    virtual ~Room(); // Destructor

    // Getters
    std::string getType() const;
    std::string getDescription() const;

    // Add a connection to another room
    void addConnection(const std::shared_ptr<Room>& room);

    // Get connected rooms
    const std::vector<std::shared_ptr<Room>>& getConnectedRooms() const;

    // Virtual function for room-specific behavior
    virtual void onEnter(Monk& monk) = 0;

protected:
    std::string type; // Type of room (e.g., "Empty", "Monster", "Upgrade", "Treasure")
    std::string description; // Description of the room (e.g. this room does this)
    std::vector<std::shared_ptr<Room>> connectedRooms; // List of connected rooms
};

#endif // ROOM_H