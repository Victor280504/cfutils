#ifndef COMPONENT_H
#define COMPONENT_H

#include <Arduino.h>

class Component
{
protected:
    uint8_t pin;

public:
    Component(uint8_t pin)
    {
        this->pin = pin;
    }
    virtual void initializePinOUT()
    {
        pinMode(pin, OUTPUT);
        delay(10);
    }
    virtual void initializePinIN()
    {
        pinMode(pin, INPUT);
        delay(10);
    }
    virtual uint8_t getPin()
    {
        return pin;
    }

    virtual void setPin(uint8_t pin)
    {
        this->pin = pin;
    }

    virtual void setPinMode(uint8_t mode)
    {
        pinMode(pin, mode);
    }

    virtual void setState(bool state)
    {
        digitalWrite(pin, state ? HIGH : LOW);
    }

    virtual void setAnalogState(int state)
    {
        analogWrite(pin, state);
    }

    virtual bool readState()
    {
        return digitalRead(pin);
    }
};

#endif