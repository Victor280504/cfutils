#ifndef EVENT_H
#define EVENT_H

#include <Arduino.h>

class Event
{
public:
  using Callback = void (*)();

  Event()
      : callback(nullptr) {}

  void setCallback(Event::Callback cb)
  {
    callback = cb;
  }

  void trigger()
  {
    if (callback)
    {
      callback();
    }
  }

protected:
  Callback callback;
};

#endif