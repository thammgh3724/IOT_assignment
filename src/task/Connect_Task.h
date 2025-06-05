#ifndef CONNECT_TASK_H
#define CONNECT_TASK_H

#include "global.h"
#include "Wifi_Task.h"
#include "Thingsboard_Task.h"

extern OTA_Firmware_Update<> ota;
extern Server_Side_RPC<MAX_RPC_SUBSCRIPTIONS, MAX_RPC_RESPONSE> rpc;
extern Shared_Attribute_Update<MAX_ATTRIBUTES_SUBSCRIPTIONS, MAX_ATTRIBUTES> shared_attributes;
extern Attribute_Request<2U, MAX_ATTRIBUTES> attr_request;
extern const std::array<IAPI_Implementation *, MAX_APIS> apis;
extern WiFiClient wifiClient;
extern Arduino_MQTT_Client mqttClient;
extern ThingsBoard tbClient;

void connect_task_init();

#endif