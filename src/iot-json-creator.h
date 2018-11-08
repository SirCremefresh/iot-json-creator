#ifndef iotJsonCreator_h
#define iotJsonCreator_h

namespace bmw12
{
char *createJson(const char *type, const char *place, const char *sensorName, const char *value, const bool isChangeEvt = false);
char *createJson(const char *type, const char *place, const char *sensorName, const float value, const bool isChangeEvt = false);
char *createJson(const char *type, const char *place, const char *sensorName, const bool value, const bool isChangeEvt = false);
} // namespace bmw12

#endif