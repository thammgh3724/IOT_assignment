#include "Wifi_Task.h"

void wifi_connect()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    // Loop if not connected
    while (WiFi.status() != WL_CONNECTED)
    {
        // Print status
        // ESP_LOGI("WIFI", "WiFi Status: %d ", WiFi.status());
        Serial.printf("WiFi Status: %d ", WiFi.status());
        delay(1000);
    }

    // ESP_LOGI("WIFI", "Connected to SSID: %s", WIFI_SSID);
    Serial.printf("WIFI Connected to SSID: %s", WIFI_SSID);
    // ESP_LOGI("WIFI", "IP Address: %s", WiFi.localIP().toString().c_str());
    Serial.printf("WIFI IP Address: %s", WiFi.localIP().toString().c_str());
}

bool wifi_need_reconnect()
{
    if (WiFi.status() == WL_CONNECTED)
        return false;
    wifi_connect();
    return false;
}

// Task to handle Wi-Fi connection
void wifi_init(void *pvParameters)
{
    while (true)
    {
        if (wifi_need_reconnect())
            continue;
        String wifi_data = "{\"rssi\":\"" + String(WiFi.RSSI()) +
                           "\",\"channel\":\"" + String(WiFi.channel()) +
                           "\",\"bssid\":\"" + WiFi.BSSIDstr() +
                           "\",\"localIp\":\"" + WiFi.localIP().toString() +
                           "\",\"ssid\":\"" + WiFi.SSID() + "\"}";
        // sendAttribute(wifi_data);
        delay(1000);
    }
}

// Function to initialize the Wi-Fi task
void wifi_task()
{
    wifi_connect();
    xTaskCreate(wifi_init, "WiFi_Task", 4096, NULL, 1, NULL);
}