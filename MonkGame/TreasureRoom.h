#pragma once
#include "Room.h"
class TreasureRoom : public Room {
public:
    TreasureRoom();
    void onEnter() override;
};