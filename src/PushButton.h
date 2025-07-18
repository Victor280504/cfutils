#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "Event.h"
#include "Component.h"

class PushButton : public Component
{
private:
  int state;
  int lastState = LOW;
  unsigned long lastDebounceTime = 0;
  unsigned long debounceDelay = 50;
  Event buttonEvent;
  Event buttonFeedback;

public:
  PushButton(uint8_t pin);
  void setEventCallback(Event::Callback cb);
  void setFeedbackCallback(Event::Callback cb);
  void readButton();
};

#endif