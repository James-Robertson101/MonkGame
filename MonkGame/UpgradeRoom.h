#pragma once
#include "Room.h"
class UpgradeRoom : public Room {
public:
    UpgradeRoom();
    void onEnter(Monk& monk) override;

};
