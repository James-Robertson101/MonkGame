
#include "Room.h"
#include <memory> // For std::shared_ptr
#include <string> // For std::string
#include <stdexcept> // For std::invalid_argument

class RoomFactory {
public:
    static std::shared_ptr<Room> createRoom(const std::string& type);
};


