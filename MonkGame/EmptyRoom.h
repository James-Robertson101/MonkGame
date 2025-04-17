#pragma once
#include "Room.h"
class EmptyRoom : public Room {
public:
    EmptyRoom();
    void onEnter() override;
};