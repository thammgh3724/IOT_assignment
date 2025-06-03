#include "RPC_Task.h"
void process_switch_control(const JsonVariantConst &data, JsonDocument &response){
    // do something
    bool state = data.as<bool>();
    Serial.print("RPC: Switch state = ");
    Serial.println(state ? "ON" : "OFF");
}
const std::array<RPC_Callback, MAX_RPC_SUBSCRIPTIONS> callbacks = {
    RPC_Callback {RPC_SWITCH_CONTROL, process_switch_control},
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