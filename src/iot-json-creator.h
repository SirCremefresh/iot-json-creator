#ifndef iotJsonCreator_h
#define iotJsonCreator_h

#include "Arduino.h"
#include "vector"

namespace bmw12
{
String *createJson(const String type, const String place, const String arduinoName, const String sensorName, const String value, const bool isChangeEvt = false);
String *createJson(const String type, const String place, const String arduinoName, const String sensorName, const float value, const bool isChangeEvt = false);
String *createJson(const String type, const String place, const String arduinoName, const String sensorName, const bool value, const bool isChangeEvt = false);
String *createJson(const String type, const String place, const String arduinoName);
String *createJson(const std::vector<std::pair<const String, const String>> keyValues);
} // namespace bmw12

#endif