#include "Monk.h"
#include <iostream>

Monk::Monk(const std::string& name, const std::string& description)
    : Entity(name, 15, 3),  // Hardcoded health (15) and attack (3)
    name(name), health(15), attack(3), maxHealth(15), description(description) {
}

void Monk::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Monk::notifyObservers() {
    for (auto* observer : observers) {
        observer->update();
    }
}

std::string Monk::getName() const {
    return name;
}

int Monk::getHealth() const {
    return health;
}

int Monk::getAttack() const {
    return attack;
}

int Monk::getMaxHealth() const {
    return maxHealth;
}

void Monk::setName(const std::string& newName) {
    name = newName;
}

void Monk::setHealth(int newHealth) {
    health = newHealth;
    if (health > maxHealth) {
        health = maxHealth;  // Ensure health doesn't exceed maxHealth
    }
    if (health <= 0) {
        health = 0;
        std::cout << name << " has died!\n";
        notifyObservers();  // Notify HUD or any other observers of death
    }
}

void Monk::setAttack(int newAttack) {
    attack = newAttack;
}

void Monk::setMaxHealth(int newMaxHealth) {
    maxHealth = newMaxHealth;
    if (health > maxHealth) {
        health = maxHealth;  // Ensure health doesn't exceed maxHealth
    }
}

void Monk::increaseHealth(int amount) {
    maxHealth += amount;
    health = maxHealth;  // Restore health to maxHealth
    notifyObservers();    // Notify observers after changing health
}

void Monk::increaseAttack(int amount) {
    attack += amount;
    notifyObservers();    // Notify observers after changing attack
}

void Monk::meditate() {
    health = maxHealth;   // Fully restore health
    std::cout << name << " meditates and fully restores health.\n";
    notifyObservers();    // Notify observers after healing
}

void Monk::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
    notifyObservers();  // Update HUD or any other observers
}
