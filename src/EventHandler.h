#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "Event.h"

class EventHandler {
public:
  static const int MAX_EVENTS = 10;

  EventHandler();
  void addEvent(Event* event);
  void triggerAll();

private:
  Event* events[MAX_EVENTS]; 
  int eventCount;      
};

#endif