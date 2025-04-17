#include "Room.h"
#include <iostream>
// Constructor
Room::Room(const std::string& type, const std::string& description)
    : type(type), description(description) {
    std::cout << "Room created: " << type << " - " << description << "\n";
}

// Destructor
Room::~Room() {
    std::cout << "Room destroyed: " << type << " - " << description << "\n";
}

// Getters
std::string Room::getType() const {
    return type;
}

std::string Room::getDescription() const {
    return description;
}

// Add a connection to another room
void Room::addConnection(const std::shared_ptr<Room>& room) {
    connectedRooms.push_back(room);
}

// Get connected rooms
const std::vector<std::shared_ptr<Room>>& Room::getConnectedRooms() const {
    return connectedRooms;
}