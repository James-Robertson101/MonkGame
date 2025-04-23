#ifndef MONK_H
#define MONK_H

#include "Entity.h"
#include <string>

class Monk : public Entity {
public:
    Monk(const std::string& name, const std::string& description);

    void increaseHealth(int amount);
    void increaseAttack(int amount);
    void meditate();  // Restores health
    std::string getDescription() const;  // Get the Monk's description

private:
    std::string description;
};

#endif // MONK_H
