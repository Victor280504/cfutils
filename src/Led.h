#ifndef LED_H
#define LED_H

#include "Component.h"

class Led : public Component {
private:
    int initialState;
    int currentState;
    int repeatValue;
    long delayTime;

public:
    int hz;

    Led(int init, uint8_t pin, long delayTime);
    void setState(int newState, long delayT);
    void setAnalogState(int newState, long delayT);
    void setDelaytime(long newTime);
    int getCurrentState();
    void resetState();
    void blink(int time, int repeat);
    static void blink(int time, int repeat, uint8_t pin);
    void blink();
};

#endif