#include "OTA_Task.h"

Espressif_Updater<> updater;

void update_starting_callback() {
    // ESP_LOGI("OTA", "Starting update...");
    Serial.println("OTA : Starting update...");
}

void finished_callback(const bool &success) {
    if (success) {
        // ESP_LOGI("OTA", "Done, Reboot now");
        Serial.println("OTA : Done, Reboot now");
        esp_restart();
        return;
    }
    // ESP_LOGE("OTA", "Downloading firmware failed");
    Serial.println("OTA : Downloading firmware failed");
}

void progress_callback(const size_t &current, const size_t &total) {
    // ESP_LOGI("OTA", "Progress %.2f%%", static_cast<float>(current * 100U) / total);
    Serial.printf("OTA : Progress %.2f%%", static_cast<float>(current * 100U) / total);
}

const OTA_Update_Callback callback(
    CURRENT_FIRMWARE_TITLE,         // ESP32-S3
    CURRENT_FIRMWARE_VERSION,       // 1.0.0
    &updater, 
    &finished_callback, 
    &progress_callback, 
    &update_starting_callback, 
    FIRMWARE_FAILURE_RETRIES,       // 12
    FIRMWARE_PACKET_SIZE            // 16384
);

bool ota_setup() {
    // ESP_LOGI("OTA", "Current FW: %s %s", CURRENT_FIRMWARE_TITLE, CURRENT_FIRMWARE_VERSION);
    Serial.printf("OTA Current FW: %s %s", CURRENT_FIRMWARE_TITLE, CURRENT_FIRMWARE_VERSION);
    ota.Firmware_Send_Info(CURRENT_FIRMWARE_TITLE, CURRENT_FIRMWARE_VERSION);

    // See https://thingsboard.io/docs/user-guide/ota-updates/
   if (!ota.Subscribe_Firmware_Update(callback)) {
        // ESP_LOGI("OTA", "Failed to subscribe to firmware update");
        Serial.println("OTA : Failed to subscribe to firmware update");
        return false;
    }
    // ESP_LOGI("OTA", "Subscribed to firmware update");
    Serial.println("OTA : Subscribed to firmware update");
    return true;
}
