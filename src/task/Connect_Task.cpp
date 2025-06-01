#include "Connect_Task.h"
OTA_Firmware_Update<> ota;
Server_Side_RPC<MAX_RPC_SUBSCRIPTIONS, MAX_RPC_RESPONSE> rpc;
Shared_Attribute_Update<MAX_ATTRIBUTES_SUBSCRIPTIONS, MAX_ATTRIBUTES> shared_attributes;
Attribute_Request<2U, MAX_ATTRIBUTES> attr_request;
const std::array<IAPI_Implementation *, MAX_APIS> apis = {
    &rpc,
    &ota,
    &shared_attributes,
    &attr_request};

WiFiClient wifiClient;
Arduino_MQTT_Client mqttClient(wifiClient);
ThingsBoard tbClient(mqttClient, MAX_MESSAGE_RECEIVE_SIZE, MAX_MESSAGE_SEND_SIZE, Default_Max_Stack_Size, apis);
HTTPClient http;
void connect_task_init()
{
    wifi_task();
    thingsboard_task();
}