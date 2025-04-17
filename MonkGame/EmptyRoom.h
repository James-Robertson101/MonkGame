#pragma once
#include "Room.h"
class EmptyRoom : public Room {
public:
    EmptyRoom();
    void onEnter(Monk& monk) override;

};