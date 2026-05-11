#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <vector>
#include "Event.h"

class EventManager {

public:
    static void addEvent();
    static void viewEvents();
    static void deleteEvent();
    static void searchEvents();
};

#endif