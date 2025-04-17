#include "RoomFactory.h"
#include "MonsterRoom.h"
#include "EmptyRoom.h"
#include "TreasureRoom.h"
#include "UpgradeRoom.h"

// RoomFactory implementation
std::shared_ptr<Room> RoomFactory::createRoom(const std::string& type) {
    if (type == "Empty") return std::make_shared<EmptyRoom>();
    if (type == "Monster") return std::make_shared<MonsterRoom>();
    if (type == "Upgrade") return std::make_shared<UpgradeRoom>();
    if (type == "Treasure") return std::make_shared<TreasureRoom>();
    throw std::invalid_argument("Unknown room type");
}