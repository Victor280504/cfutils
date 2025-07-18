#include "Buzzer.h"

Buzzer::Buzzer(int p) : pin(p)
{
    pinMode(pin, OUTPUT);
}

void Buzzer::beep(int duration)
{
    tone(pin, 1000);
    delay(duration);
    noTone(pin);
}

void Buzzer::success()
{
    beep(100);
    delay(100);
    beep(100);
}

void Buzzer::error()
{
    beep(300);
    delay(100);
    beep(300);
}

void Buzzer::pattern(int *durations, int count)
{
    for (int i = 0; i < count; i++)
    {
        beep(durations[i]);
        delay(100);
    }
}

void Buzzer::playMelody(const Note *melody, int length)
{
    for (int i = 0; i < length; i++)
    {
#ifdef DEBUG_WITH_LED
        digitalWrite(LED_BUILTIN, HIGH);
#else
        tone(pin, melody[i].frequency);
#endif

        delay(melody[i].duration);

#ifdef DEBUG_WITH_LED
        digitalWrite(LED_BUILTIN, LOW);
#else
        noTone(pin);
#endif
        delay(20);
    }
}
