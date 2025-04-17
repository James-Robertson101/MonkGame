#include "Monk.h"
#include <iostream>

Monk::Monk(const std::string& name, const std::string& description)
    : Entity(name, 15, 3), description(description) {
}

void Monk::increaseHealth(int amount) {
    maxHealth += amount;
    health = maxHealth;
}

void Monk::increaseAttack(int amount) {
    attack += amount;
}

void Monk::meditate() {
    health = maxHealth;
    std::cout << name << " meditates and fully restores health.\n";
}

std::string Monk::getDescription() const {
    return description;
}
