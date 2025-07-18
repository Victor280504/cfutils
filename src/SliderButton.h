#ifndef SLIDERBUTTON_H
#define SLIDERBUTTON_H

#include "Component.h"
#include "Event.h"

class SliderButton : public Component
{
private:
  bool activeState = false;
  Event buttonEvent[2];
  Event buttonFeedback[2];

public:
  SliderButton(uint8_t pin);
  void update();
  void getStateFeedback();
  void updateIf(int index, bool state);
  void updateOne(int index);
  void updateAlways();
  void setEventCallback(Event::Callback cb, int index);
  void setFeedbackCallback(Event::Callback cb, int index);
  bool isActive() const;
};

#endif