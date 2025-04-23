#ifndef ENTITY_H
#define ENTITY_H

#include <string>
// Entity is the base class that monk and monsters inherit from
class Entity {
public:
    Entity(const std::string& name, int health, int attack);
    virtual ~Entity() = default;

    // Basic stats
    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    int getMaxHealth() const;
    bool isAlive() const;

    // Actions to be overwritten through polymorphism in inherited classes
    virtual void takeDamage(int amount);
    virtual void heal(int amount);
    virtual void attackEntity(Entity& target);

protected:
    std::string name;
    int health;
    int attack;
    int maxHealth;
};

#endif // ENTITY_H
