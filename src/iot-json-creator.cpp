#include "iot-json-creator.h"

const char* jsonTemplate =  "{\"type\":\"%s\", \"place\":\"%s\", \"sensorName\": \"%s\", \"isChangeEvt\": \"%s\", \"value\": %s}";
const char* trueStr = "true";
const char* falseStr = "false";

char* createJson(const char* type, const char* place, const char* sensorName, const bool isChangeEvt, const char* value) {
    return new char[3];
}

char* createJson(const char* type, const char* place, const char* sensorName, const bool isChangeEvt, const bool value) {
    const char* valueStr = (value)?trueStr:falseStr;
    return createJson(type, place, sensorName, isChangeEvt, valueStr);
}

char* createJson(const char* type, const char* place, const char* sensorName, const bool isChangeEvt, const float value) {
    return "";
}

