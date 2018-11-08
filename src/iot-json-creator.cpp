#include "iot-json-creator.h"
#include "Arduino.h"

const char *jsonTemplate = "{\"type\":\"%s\", \"place\":\"%s\", \"sensorName\": \"%s\", \"isChangeEvt\": %s, \"value\": %s}";
const char *trueStr = "true";
const char *falseStr = "false";

char *createJson(const char *type, const char *place, const char *sensorName, const bool isChangeEvt, const char *value)
{
    const char *isChangeEvtStr = (isChangeEvt) ? trueStr : falseStr;
    int lenght = strlen(type) + strlen(place) + strlen(sensorName) + strlen(isChangeEvtStr) + strlen(value);
    char *outString = (char*)malloc(sizeof(char) * (lenght + 1));
    sprintf(outString, jsonTemplate, type, place, sensorName, isChangeEvtStr, value);
    return outString;
}

char *createJson(const char *type, const char *place, const char *sensorName, const bool value, const bool isChangeEvt)
{
    const char *valueStr = (value) ? trueStr : falseStr;
    return createJson(type, place, sensorName, isChangeEvt, valueStr);
}

char *createJson(const char *type, const char *place, const char *sensorName, const bool value, const bool isChangeEvt)
{
    char valueStr[20];
    dtostrf(value, 20, 6, valueStr);
    return createJson(type, place, sensorName, isChangeEvt, valueStr);
}
