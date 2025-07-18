#include "PushButton.h"
#include "Logger.h"
#include <Arduino.h>

PushButton::PushButton(uint8_t pin)
    : Component(pin) {}

void PushButton::setEventCallback(Event::Callback cb)
{
  buttonEvent.setCallback(cb);
}

void PushButton::setFeedbackCallback(Event::Callback cb)
{
  buttonFeedback.setCallback(cb);
}

void PushButton::readButton()
{

  int reading = digitalRead(pin);

  if (reading != lastState)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != state)
    {
      state = reading;

      if (state == HIGH)
      {
        buttonEvent.trigger();
        buttonFeedback.trigger();
      }
    }
  }

  lastState = reading;
}
