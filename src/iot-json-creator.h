#ifndef iotJsonCreator_h
#define iotJsonCreator_h



char* createJson(const char* type, const char* place, const char* sensorName, const float value, const bool isChangeEvt = false);
char* createJson(const char* type, const char* place, const char* sensorName, const bool value, const bool isChangeEvt = false);


#endif