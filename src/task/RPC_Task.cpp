#include "RPC_Task.h"
void process_light_control(const JsonVariantConst &data, JsonDocument &response){
    bool state = data.as<bool>();
    if (state) {
        turn_on_pixel();
        Serial.println("RPC: turn on pixel");
    }
    else {
        turn_off_pixel();
        Serial.println("RPC: turn off pixel");
    }
    response.set(state);
    sendBoolTelemetry("light_status", state); 
}

void process_door_control(const JsonVariantConst &data, JsonDocument &response){
    bool state = data.as<bool>();
    if (state) {
        turn_on_relay();
        Serial.println("RPC: open door");
    }
    else {
        turn_off_relay();
        Serial.println("RPC: close door");
    }
    response.set(state);
    sendBoolTelemetry("door_status", state);
}

void process_fan_control(const JsonVariantConst &data, JsonDocument &response){
    bool state = data.as<bool>();
    if (state) {
        turn_on_fan();
        Serial.println("RPC: turn on fan");
    }
    else {
        turn_off_fan();
        Serial.println("RPC: turn off fan");
    }
    response.set(state);
    sendBoolTelemetry("fan_status", state);
}

const std::array<RPC_Callback, MAX_RPC_SUBSCRIPTIONS> callbacks = {
    RPC_Callback {RPC_LIGHT_CONTROL, process_light_control},
    RPC_Callback {RPC_DOOR_CONTROL, process_door_control},
    RPC_Callback {RPC_FAN_CONTROL, process_fan_control}
};

bool rpc_setup()
{
    if (!rpc.RPC_Subscribe(callbacks.cbegin(), callbacks.cend()))
    {
        // ESP_LOGE("RPC", "Failed to subscribe to RPC methods");
        Serial.println("RPC : Failed to subscribe to RPC methods");
        return false;
    }
    // ESP_LOGI("RPC", "Subscribed to RPC methods");
    Serial.println("RPC : Subscribed to RPC methods");
    return true;
}