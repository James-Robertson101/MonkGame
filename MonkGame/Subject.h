#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
#include <memory>

class Subject {
public:
    virtual ~Subject() = default;

    void addObserver(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<Observer> observer) {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

protected:
    void notifyObservers() {
        for (const auto& observer : observers) {
            if (observer) {
                observer->update();
            }
        }
    }

private:
    std::vector<std::shared_ptr<Observer>> observers;
};

#endif // SUBJECT_H
