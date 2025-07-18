#include "EventHandler.h"

EventHandler::EventHandler()
  : eventCount(0) {}

void EventHandler::addEvent(Event* event) {
  if (eventCount < MAX_EVENTS) {
    events[eventCount++] = event; 
  }
}

void EventHandler::triggerAll() {
  for (int i = 0; i < eventCount; i++) {
    events[i]->trigger();
  }
}