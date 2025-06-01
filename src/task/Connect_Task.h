#ifndef CONNECT_TASK_
#define CONNECT_TASK_

#include "global.h"
#include "Wifi_Task.h"
#include "Thingsboard_Task.h"
extern Arduino_MQTT_Client mqttClient;
// THINGSBOARD
extern ThingsBoard tbClient;

extern OTA_Firmware_Update<> ota;
extern Server_Side_RPC<MAX_RPC_SUBSCRIPTIONS, MAX_RPC_RESPONSE> rpc;
extern Shared_Attribute_Update<MAX_ATTRIBUTES_SUBSCRIPTIONS, MAX_ATTRIBUTES> shared_attributes;
extern Attribute_Request<2U, MAX_ATTRIBUTES> attr_request;
extern const std::array<IAPI_Implementation*, MAX_APIS> apis;

void connect_task_init();


#endif