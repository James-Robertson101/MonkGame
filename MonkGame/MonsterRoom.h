#ifndef MONSTERROOM_H
#define MONSTERROOM_H

#include "Room.h"
#include "Goblin.h"
#include "Monk.h"

class MonsterRoom : public Room {
public:
    MonsterRoom();

    // Accept Monk as parameter for combat
    void onEnter(Monk& monk) override;


private:
    Goblin goblin; // Room contains one Goblin
};

#endif // MONSTERROOM_H
