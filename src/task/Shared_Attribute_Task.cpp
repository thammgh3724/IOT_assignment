#include "Shared_Attribute_Task.h"
const std::vector<const char *> REQUESTED_CLIENT_ATTRIBUTES = {"light_status","door_status","fan_status"};

void requestTimedOut()
{
    Serial.printf("Attribute request timed out did not receive a response in (%llu) microseconds. Ensure client is connected to the MQTT broker and that the keys actually exist on the target device\n", REQUEST_TIMEOUT_MICROSECONDS);
}

void processRoom1Card(const JsonObjectConst &data) {
    JsonObjectConst roomData = data[room1_attr_name];
    if (roomData.isNull()) {
        Serial.println("Ivalid Data");
        return;
    }

    if (!roomData.containsKey("rfid_access")) {
        Serial.println("No rfid_access field in attribute.");
        return;
    }

    room1_allowedUIDs.clear();
    JsonArrayConst rfidArray = roomData["rfid_access"];
    for (JsonVariantConst uidVal : rfidArray) {
        String uidStr = uidVal.as<String>();
        room1_allowedUIDs.push_back(uidStr);
        Serial.println("Allowed UID: " + uidStr);
    }
}

void processLightAuto(const JsonObjectConst &data) {
    bool state = data["light_auto"];
    Serial.print("Light Auto status: ");
    Serial.println(state ? "ON" : "OFF");
    if (state) {
        light_auto_state = 1;
        Serial.println("Turn on Light Auto feature");
    }
    else {
        light_auto_state = 0;
        Serial.println("Turn off Light Auto feature");
    }
}

void processSharedAttributeUpdate(const JsonObjectConst &data)
{

    for (auto it = data.begin(); it != data.end(); ++it)
    {
        Serial.println(it->key().c_str());
        Serial.println(it->value().as<const char *>());
        const char *key = it->key().c_str();
        if (strcmp(key, room1_attr_name) == 0) {
            processRoom1Card(data);
        }
        else if (strcmp(key, "light_auto") == 0) {
            processLightAuto(data);
        }
        else{
            Serial.println("Invalid Attribute.");
            return;
        }
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

void processClientAttributeRequest(const JsonObjectConst &data)
{
    for (auto it = data.begin(); it != data.end(); ++it)
    {
        Serial.println(it->key().c_str());
        // Shared attributes have to be parsed by their type.
        Serial.println(it->value().as<const char *>());
        const char *key = it->key().c_str();
        if (strcmp(key, "light_status") == 0)
        {
            bool state = it->value().as<bool>();
            Serial.print("Light status: ");
            Serial.println(state ? "ON" : "OFF");
            if (state) {
                turn_on_pixel();
                Serial.println("Turn on pixel");
            }
            else {
                turn_off_pixel();
                Serial.println("Turn off pixel");
            }
        }
        else if (strcmp(key, "door_status") == 0)
        {
            bool state = it->value().as<bool>();
            Serial.print("Door status: ");
            Serial.println(state ? "ON" : "OFF");
            if (state) {
                turn_on_relay();
                Serial.println("Turn on relay");
            }
            else {
                turn_off_relay();
                Serial.println("Turn off relay");
            }
        }
        else if (strcmp(key, "fan_status") == 0)
        {
            bool state = it->value().as<bool>();
            Serial.print("Fan status: ");
            Serial.println(state ? "ON" : "OFF");
            if (state) {
                turn_on_fan();
                Serial.println("Turn on fan");
            }
            else {
                turn_off_fan();
                Serial.println("Turn off fan");
            }
        }
    }
    const size_t jsonSize = Helper::Measure_Json(data);
    char buffer[jsonSize];
    serializeJson(data, buffer, jsonSize);
    Serial.println(buffer);
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
        const char *key = it->key().c_str();
        if (strcmp(key, room1_attr_name) == 0) {
            processRoom1Card(data);
        }
        else if (strcmp(key, "light_auto") == 0) {
            processLightAuto(data);
        }
        else{
            Serial.println("Invalid Attribute.");
            return;
        }
    }
    const size_t jsonSize = Helper::Measure_Json(data);
    char buffer[jsonSize];
    serializeJson(data, buffer, jsonSize);
    Serial.println(buffer);
}

bool request_shared_attributes()
{
    Serial.println("Requesting shared attributes...");
    // Shared attributes we want to request from the server
    const Attribute_Request_Callback<MAX_ATTRIBUTES> sharedCallback(&processSharedAttributeRequest, REQUEST_TIMEOUT_MICROSECONDS, &requestTimedOut, REQUESTED_SHARED_ATTRIBUTES);
    bool requestedShared = attr_request.Shared_Attributes_Request(sharedCallback);
    if (!requestedShared)
    {
        Serial.println("Failed to request shared attributes");
    }
    return requestedShared;
}