#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include <functional>
#include <vector>

// Base class for all events
class Event {
public:
    virtual ~Event() = default;
};

// Event listener interface
class EventListener {
public:
    virtual void onEvent(Event* event) = 0;
    virtual ~EventListener() = default;
};

// Event manager class
class EventManager {
public:
    void addListener(EventListener* listener);
    void dispatchEvent(Event* event);

private:
    std::vector<EventListener*> listeners_;
};

#endif // EVENTSYSTEM_H
