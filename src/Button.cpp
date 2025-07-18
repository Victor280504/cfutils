#include "Button.h"
#include <Arduino.h>

Button::Button(int pin)
    : Component(pin) {}

void Button::setEventCallback(Event::Callback cb)
{
    buttonEvent.setCallback(cb);
}