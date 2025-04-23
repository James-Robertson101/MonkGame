// Observer.h
#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;  // Virtual destructor to ensure correct deletion of derived classes
    virtual void update() = 0;      // Pure virtual function to be implemented by concrete observers
};

#endif // OBSERVER_H
