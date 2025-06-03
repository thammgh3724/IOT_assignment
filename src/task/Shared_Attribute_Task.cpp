#include "Shared_Attribute_Task.h"
const std::vector<const char *> REQUESTED_CLIENT_ATTRIBUTES = {};

void requestTimedOut()
{
    Serial.printf("Attribute request timed out did not receive a response in (%llu) microseconds. Ensure client is connected to the MQTT broker and that the keys actually exist on the target device\n", REQUEST_TIMEOUT_MICROSECONDS);
}

void processSharedAttributeUpdate(const JsonObjectConst &data)
{

    for (auto it = data.begin(); it != data.end(); ++it)
    {
        Serial.println(it->key().c_str());
        Serial.println(it->value().as<const char *>());
    }

    const size_t jsonSize = Helper::Measure_Json(data);
    char buffer[jsonSize];
    serializeJson(data, buffer, jsonSize);
    Serial.println(buffer);
}

const Shared_Attribute_Callback<MAX_ATTRIBUTES> callback(
    &processSharedAttributeUpdate,
    SHARED_ATTRIBUTES_LIST);

bool shared_attributes_setup()
{
    if (!shared_attributes.Shared_Attributes_Subscribe(callback))
    {
        // ESP_LOGE("SHARED_ATTR", "Failed to subscribe to shared attributes");
        Serial.println("SHARED_ATTR : Failed to subscribe to shared attributes");
        return false;
    }
    // ESP_LOGI("SHARED_ATTR", "Subscribed to shared attributes");
    Serial.println("SHARED_ATTR : Subscribed to shared attributes");
    return true;
}

void processRelay(const JsonObjectConst &data)
{

}
void processClientAttributeRequest(const JsonObjectConst &data)
{
    processRelay(data); 
}


bool request_client_attributes()
{
    Serial.println("Requesting client-side attributes...");
    // Client-side attributes we want to request from the server
    const Attribute_Request_Callback<MAX_ATTRIBUTES> clientCallback(&processClientAttributeRequest, REQUEST_TIMEOUT_MICROSECONDS, &requestTimedOut, REQUESTED_CLIENT_ATTRIBUTES);
    bool requestedClient = attr_request.Client_Attributes_Request(clientCallback);
    if (!requestedClient)
    {
        Serial.println("Failed to request client-side attributes");
    }
    return requestedClient;
}

void processSharedAttributeRequest(const JsonObjectConst &data)
{
    for (auto it = data.begin(); it != data.end(); ++it)
    {
        Serial.println(it->key().c_str());
        // Shared attributes have to be parsed by their type.
        Serial.println(it->value().as<const char *>());
    }
    const size_t jsonSize = Helper::Measure_Json(data);
    char buffer[jsonSize];
    serializeJson(data, buffer, jsonSize);
    Serial.println(buffer);
}

void request_shared_attributes()
{
    Serial.println("Requesting shared attributes...");
    // Shared attributes we want to request from the server
    const Attribute_Request_Callback<MAX_ATTRIBUTES> sharedCallback(&processSharedAttributeRequest, REQUEST_TIMEOUT_MICROSECONDS, &requestTimedOut, REQUESTED_SHARED_ATTRIBUTES);
    bool requestedShared = attr_request.Shared_Attributes_Request(sharedCallback);
    if (!requestedShared)
    {
        Serial.println("Failed to request shared attributes");
    }
}