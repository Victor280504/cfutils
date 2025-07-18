#include "Led.h"

Led::Led(int init, uint8_t pin, long delayTime) : Component(pin), hz(0)
{
    this->delayTime = delayTime;
    this->initialState = init;
    this->currentState = init;
    this->repeatValue = 3;
}

void Led::setState(int newState, long delayT)
{
    this->currentState = newState;
    Component::setState(newState); 
    delay(delayT);
}

void Led::setAnalogState(int newState, long delayT)
{
    this->currentState = newState;
    Component::setAnalogState(newState); 
}

void Led::setDelaytime(long newTime)
{
    this->delayTime = newTime;
}

int Led::getCurrentState()
{
    return this->currentState;
}

void Led::resetState()
{
    this->currentState = this->initialState;
    Component::setState(this->currentState); // Usa método da classe base
}

void Led::blink(int time, int repeat)
{
    for (int i = 0; i < repeat; i++)
    {
        setState(HIGH, time);
        setState(LOW, time);
    }
}

void Led::blink(int time, int repeat, uint8_t pin)
{
    for (int i = 0; i < repeat; i++)
    {
        digitalWrite(pin, HIGH);
        delay(time);
        digitalWrite(pin, LOW);
        delay(time);
    }
}

void Led::blink()
{
    for (int i = 0; i < repeatValue; i++)
    {
        setState(HIGH, delayTime);
        setState(LOW, delayTime);
    }
}