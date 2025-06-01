#include "global.h"
#include "RPC_Task.h"
#include "OTA_Task.h"
#include "Shared_Attribute_Task.h"

void sendTelemetry(const String&data);
void sendAttribute(const String&data);
void thingsboard_task();
