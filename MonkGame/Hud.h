#ifndef HUD_H
#define HUD_H

#include "Observer.h"
#include "Monk.h"
#include <memory>

class HUD : public Observer {
public:
    // Constructor that takes a shared pointer to the Monk
    HUD(std::shared_ptr<Monk> monk);

    // The update method called when the Monk's status changes
    void update() override;

private:
    std::shared_ptr<Monk> observedMonk;  // The Monk being observed
};

#endif // HUD_H
