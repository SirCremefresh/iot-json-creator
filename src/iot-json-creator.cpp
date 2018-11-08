#include "iot-json-creator.h"
#include "Arduino.h"

const char *jsonTemplate = "{\"type\":\"%s\", \"place\":\"%s\", \"sensorName\": \"%s\", \"isChangeEvt\": %s, \"value\": %s}";
const char *trueStr = "true";
const char *falseStr = "false";

char *bmw12::createJson(const char *type, const char *place, const char *sensorName, const char *value, const bool isChangeEvt)
{
    const char *isChangeEvtStr = (isChangeEvt) ? trueStr : falseStr;
    int lenght = strlen(type) + strlen(place) + strlen(sensorName) + strlen(isChangeEvtStr) + strlen(value);
    char *outString = (char *)malloc(sizeof(char) * (lenght + 1));
    sprintf(outString, jsonTemplate, type, place, sensorName, isChangeEvtStr, value);
    return outString;
}

char *bmw12::createJson(const char *type, const char *place, const char *sensorName, const bool value, const bool isChangeEvt)
{
    const char *valueStr = (value) ? trueStr : falseStr;
    return bmw12::createJson(type, place, sensorName, valueStr, isChangeEvt);
}

char *bmw12::createJson(const char *type, const char *place, const char *sensorName, const float value, const bool isChangeEvt)
{
    char valueStr[20];
    dtostrf(value, 20, 6, valueStr);
    return bmw12::createJson(type, place, sensorName, valueStr, isChangeEvt);
}
