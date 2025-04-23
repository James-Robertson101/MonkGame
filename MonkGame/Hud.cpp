#include "HUD.h"
#include <iostream>

HUD::HUD(std::shared_ptr<Monk> monk) : observedMonk(std::move(monk)) {
    observedMonk->addObserver(this);  // Register this HUD as an observer of the Monk
}

void HUD::update() {
    // Display the Monk's current stats
    std::cout << "\n== MONK STATUS ==\n";
    std::cout << "Name: " << observedMonk->getName() << "\n";
    std::cout << "Health: " << observedMonk->getHealth() << "/" << observedMonk->getMaxHealth() << "\n";
    std::cout << "Attack: " << observedMonk->getAttack() << "\n";
    std::cout << "=================\n";
}
