#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <array>
#include <list>
#include <map>
#include <vector>
#include <fcntl.h>
// #include <termios.h>
#include <unistd.h>
#include "esp_partition.h"
#include "esp_system.h"
#include "esp_event.h"
#include <esp_err.h>
#include "esp_log.h"
#include <cstdio>
// #include "esp_ota_ops.h"
// #include "esp_wifi.h"
#include "esp_sntp.h"

#include "nvs.h"
#include "nvs_flash.h"

// Global Libraries for the project
#include "WiFi.h"
#include "SPIFFS.h"
#include "DHT20.h"
#include "device/DHT20.h"
#include "device/LedFanRelay.h"
#include "device/PIR.h"
#include "device/RFID_Task.h"
#include "HardwareSerial.h"
// #include "SoftwareSerial.h"
#include "Adafruit_NeoPixel.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// #include "PubSubClient.h"
#include "ThingsBoard.h"
#include "Arduino_MQTT_Client.h"
// #include "ArduinoJson.h"
#include <Espressif_Updater.h>
#include <OTA_Firmware_Update.h>
#include "RPC_Request_Callback.h"
#include <Server_Side_RPC.h>
// #include <Client_Side_RPC.h>
#include <Shared_Attribute_Update.h>
#include <Attribute_Request.h>
#include <HTTPClient.h>

// Global constants and structs
#include "constants.h"
#include "../src/task/Connect_Task.h"
#include "../src/task/LightAuto_Task.h"
#include "../src/task/HTTP_Task.h"
// Include configs

#endif
