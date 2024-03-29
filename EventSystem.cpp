#include "EventSystem.h"

void EventManager::addListener(EventListener* listener) {
    listeners_.push_back(listener);
}

void EventManager::dispatchEvent(Event* event) {
    for (auto listener : listeners_) {
        listener->onEvent(event);
    }
    delete event; // Assuming dynamic allocation of events
}
