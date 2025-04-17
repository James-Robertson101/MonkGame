#include "Entity.h"
#include <iostream>

Entity::Entity(const std::string& name, int health, int attack)
    : name(name), health(health), attack(attack), maxHealth(health) {
}

std::string Entity::getName() const {
    return name;
}

int Entity::getHealth() const {
    return health;
}

int Entity::getAttack() const {
    return attack;
}

int Entity::getMaxHealth() const {
    return maxHealth;
}

bool Entity::isAlive() const {
    return health > 0;
}

void Entity::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
    std::cout << name << " took " << amount << " damage. Remaining health: " << health << "\n";
}

void Entity::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
    std::cout << name << " healed for " << amount << ". Current health: " << health << "\n";
}

void Entity::attackEntity(Entity& target) {
    std::cout << name << " attacks " << target.getName() << " for " << attack << " damage!\n";
    target.takeDamage(attack);
}
