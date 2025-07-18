#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

enum LogLevel {
  DEBUG,
  INFO,
  WARNING,
  ERROR
};

class Logger {
public:
  static void begin(unsigned long baudRate);
  static void log(LogLevel level, const String& message);
};

#endif