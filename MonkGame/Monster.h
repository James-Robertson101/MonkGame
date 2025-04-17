#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"

class Monster : public Entity {
public:
    Monster(const std::string& name, int health, int attack);
    virtual ~Monster() = default;

    // Optional: could add monster-specific behavior here
};

#endif // MONSTER_H
