#pragma once
#include "Room.h"
class MonsterRoom : public Room {
public:
	MonsterRoom();
	void onEnter() override;
};