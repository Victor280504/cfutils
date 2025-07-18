#include "SliderButton.h"
#include <Arduino.h>

SliderButton::SliderButton(uint8_t pin)
    : Component(pin) {
    activeState = digitalRead(pin);
    }

void SliderButton::updateIf(int index, bool state)
{
  bool newState = digitalRead(pin) == HIGH;
  if (newState != activeState)
  {
    activeState = newState;
    if (newState == state)
      buttonEvent[index].trigger();
  }
}

void SliderButton::update()
{
  bool newState = digitalRead(pin) == HIGH;
  if (newState != activeState)
  {
    activeState = newState;
    buttonEvent[newState].trigger();
  }
}

void SliderButton::getStateFeedback()
{
  bool newState = digitalRead(pin) == HIGH;
  if (newState != activeState)
  {
    activeState = newState;
    buttonFeedback[newState].trigger();
  }
}

void SliderButton::updateOne(int index)
{
  bool newState = digitalRead(pin) == HIGH;
  if (newState != activeState)
  {
    activeState = newState;
    buttonEvent[index].trigger();
  }
}

void SliderButton::updateAlways()
{
  buttonEvent[digitalRead(pin)].trigger();
}

void SliderButton::setEventCallback(Event::Callback cb, int index)
{
  buttonEvent[index].setCallback(cb);
}

void SliderButton::setFeedbackCallback(Event::Callback cb, int index)
{
  buttonFeedback[index].setCallback(cb);
}

bool SliderButton::isActive() const
{
  return activeState;
}
