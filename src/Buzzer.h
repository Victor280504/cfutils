#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
#include "Note.h"

class Buzzer {
private:
    int pin;

public:
    Buzzer(int p);
    void beep(int duration = 200);
    void success();
    void error();
    void pattern(int* durations, int count);
    void playMelody(const Note* melody, int length);
};

#endif
