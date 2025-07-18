#ifndef BUTTON_H
#define BUTTON_H

#include "Event.h"
#include "Component.h"

class Button : public Component {
public:
  Button(int pin);
  virtual ~Button() = default;

  virtual void update() = 0;
  virtual void setEventCallback(Event::Callback cb);

protected:
  Event buttonEvent;
};

#endif