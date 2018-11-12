#include "iot-json-creator.h"
#include "Arduino.h"
#include "utility"
#include "vector"

const char *trueStr = "true";
const char *falseStr = "false";

String *bmw12::createJson(const std::vector<std::pair<const String, const String>> keyValues)
{
    String *outString = new String("{");
    for (std::pair<String, String> keyValue : keyValues)
    {
        *outString += "\"" + keyValue.first + "\":";
        *outString += keyValue.second + ",";
    }
    outString->remove(outString->length() - 1);
    *outString += "}";

    return outString;
}

String *bmw12::createJson(const String type, const String place, const String arduinoName)
{
    std::vector<std::pair<const String, const String>> keyValues;

    keyValues.push_back(std::pair<const String, const String>("type", "\"" + type + "\""));
    keyValues.push_back(std::pair<const String, const String>("arduinoName", "\"" + arduinoName + "\""));
    keyValues.push_back(std::pair<const String, const String>("place", "\"" + place + "\""));

    return bmw12::createJson(keyValues);
}

String *bmw12::createJson(const String type, const String place, const String arduinoName, const String sensorName, const String value, const bool isChangeEvt)
{
    const String isChangeEvtStr = (isChangeEvt) ? "true" : "false";
    std::vector<std::pair<const String, const String>> keyValues;

    keyValues.push_back(std::pair<const String, const String>("type", "\"" + type + "\""));
    keyValues.push_back(std::pair<const String, const String>("arduinoName", "\"" + arduinoName + "\""));
    keyValues.push_back(std::pair<const String, const String>("place", "\"" + place + "\""));

    keyValues.push_back(std::pair<const String, const String>("sensorName", "\"" + sensorName + "\""));
    keyValues.push_back(std::pair<const String, const String>("isChangeEvt", isChangeEvtStr));
    keyValues.push_back(std::pair<const String, const String>("value", value));

    return bmw12::createJson(keyValues);
}

String *bmw12::createJson(const String type, const String place, const String arduinoName, const String sensorName, const bool value, const bool isChangeEvt)
{
    const String valueStr = (value) ? "true" : "false";
    return bmw12::createJson(type, arduinoName, place, sensorName, valueStr, isChangeEvt);
}

String *bmw12::createJson(const String type, const String place, const String arduinoName, const String sensorName, const float value, const bool isChangeEvt)
{
    const String valueStr(value);
    return bmw12::createJson(type, arduinoName, place, sensorName, valueStr, isChangeEvt);
}
