#include "Logger.h"

void Logger::begin(unsigned long baudRate) {
  Serial.begin(baudRate);
}

void Logger::log(LogLevel level, const String& message) {
  String levelText;
  switch (level) {
    case DEBUG: levelText = "[DEBUG] "; break;
    case INFO: levelText = "[INFO] "; break;
    case WARNING: levelText = "[WARNING] "; break;
    case ERROR: levelText = "[ERROR] "; break;
  }

  Serial.println(levelText + message);
}