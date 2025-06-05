#ifndef HTTP_TASK_H_
#define HTTP_TASK_H_

#include "global.h"
extern HTTPClient http;
void sendWebHook(String cardUUID, String roomUUID);
#endif