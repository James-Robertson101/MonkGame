#ifndef MONK_H
#define MONK_H

#include "Observer.h"
#include <vector>
#include <string>
#include "Entity.h"

class Monk : public Entity {
public:
    // Constructor with hardcoded health (15) and attack (3)
    Monk(const std::string& name, const std::string& description);
    // Getters
    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getMaxHealth() const;

    // Setters
    void setName(const std::string& name);
    void setHealth(int health);
    void setAttack(int attack);
    void setMaxHealth(int maxHealth);

    // Methods for game mechanics
    void increaseHealth(int amount); //increases max health
    void increaseAttack(int amount); //increases attack stat
    void meditate(); //restores hp to maximum
    void heal(int amount); //heals by given amount (used when the player guards during combat)

    // Observer methods
    void addObserver(Observer* observer);// Method to add hud to observers
    void notifyObservers(); // observer method used to notify the Hud when the players stats change e.g. damage taken

private:
    std::vector<Observer*> observers; // List of observers (HUD, etc.) 
    std::string name;
    std::string description;
    int health;
    int attack;
    int maxHealth;
};

#endif // MONK_H
