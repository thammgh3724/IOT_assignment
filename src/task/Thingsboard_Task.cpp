#include "Thingsboard_Task.h"

bool ota_subscribed = false;
bool rpc_subscribed = false;
bool shared_attributes_subscribed = false;
bool requested_client_attributes = false;


void sendAttribute(const String &data)
{
    tbClient.sendAttributeString(data.c_str());
}
void sendTelemetry(const String &data)
{
    tbClient.sendTelemetryString(data.c_str());
}
void init(void *pvParameters)
{
    while (true)
    {
        delay(1000);
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(1000);
        }
        if (!tbClient.connected())
        {
            while (!tbClient.connect(THINGSBOARD_SERVER, DEVICE_TOKEN, THINGSBOARD_PORT))
            {
                ESP_LOGI("TB", "Unable to connect to ThingsBoard MQTT server");
                delay(1000);
            }
        }
        if (!rpc_subscribed)
        {
            rpc_subscribed = rpc_setup();
        }
        if (!shared_attributes_subscribed)
        {
            shared_attributes_subscribed = shared_attributes_setup();
        }
        if (!ota_subscribed)
        {
            ota_subscribed = ota_setup();
        }
        if (!requested_client_attributes)
        {
            requested_client_attributes = request_client_attributes();
        }
        tbClient.loop();
    }
}

void thingsboard_task()
{
    xTaskCreate(init, "ThingsBoard_Task_Init", 4096, NULL, 1, NULL);
}