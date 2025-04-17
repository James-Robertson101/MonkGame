#ifndef MONK_H
#define MONK_H

#include "Entity.h"

class Monk : public Entity {
public:
    Monk(const std::string& name, const std::string& description);

    void increaseHealth(int amount);
    void increaseAttack(int amount);
    void meditate();

    std::string getDescription() const;

private:
    std::string description;
};

#endif // MONK_H
