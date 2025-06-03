
#ifndef CONSTANT_H_
#define CONSTANT_H_
#include <cstdint>
#include <array>

#define LED_PIN 48

#define FAN_PIN 6

#define PIXEL_PIN 8
#define NUMPIXELS 4

#define RELAY_PIN 18

#define PIR_PIN 10

#define DHT_SDA 11     // Sensor DHT
#define DHT_SCL 12      // Sensor DHT


#define MOSI_PIN 17
#define MISO_PIN 21
#define RST_PIN 38
#define SDA_PIN 47
#define SCK_PIN 48


#define DEVICE_TOKEN "wbhpocw2uo37sartan4h"

#define THINGSBOARD_SERVER "app.coreiot.io"
#define THINGSBOARD_PORT 1883U

// #define WIFI_SSID "Home Coffee 2"
// #define WIFI_PASSWORD "hihomies"
#define WIFI_SSID "Vu Van Binh"
#define WIFI_PASSWORD "BITHANNG"

#define MY_BOARD "YOLO-UNO"
#define MY_VERSION "1.0.1"

constexpr uint16_t MAX_MESSAGE_SEND_SIZE = 512U;
constexpr uint16_t MAX_MESSAGE_RECEIVE_SIZE = 512U;
constexpr uint8_t MAX_APIS = 5U;

// RPC //
// https://github.com/thingsboard/thingsboard-client-sdk/tree/master/examples/0010-esp8266_esp32_rpc
constexpr uint8_t MAX_RPC_SUBSCRIPTIONS = 9U;
constexpr uint8_t MAX_RPC_RESPONSE = 5U;

// EXAMPLE RPC
constexpr const char RPC_LIGHT_CONTROL[] = "light_control";
constexpr const char RPC_DOOR_CONTROL[] = "door_control";
constexpr const char RPC_FAN_CONTROL[] = "fan_control";

/* OTA */
// https://github.com/thingsboard/thingsboard-client-sdk/tree/master/examples/0009-esp8266_esp32_process_OTA_MQTT
constexpr char CURRENT_FIRMWARE_TITLE[] = MY_BOARD;
constexpr char CURRENT_FIRMWARE_VERSION[] = MY_VERSION;
constexpr uint8_t FIRMWARE_FAILURE_RETRIES = 12U;
constexpr uint16_t FIRMWARE_PACKET_SIZE = 16384U;

/* SHARED ATTRIBUTES */
// https://github.com/thingsboard/thingsboard-client-sdk/blob/master/examples/0006-esp8266_esp32_process_shared_attribute_update
// EXAMPLE constexpr const char RELAY_1_STATUS[] = "relay_1_status";
constexpr uint8_t MAX_ATTRIBUTES_SUBSCRIPTIONS = 1U;
constexpr uint8_t MAX_ATTRIBUTES = 10U;
constexpr std::array<const char *, MAX_ATTRIBUTES> SHARED_ATTRIBUTES_LIST = {};

constexpr std::array<const char *, MAX_ATTRIBUTES> REQUESTED_SHARED_ATTRIBUTES = {};



constexpr uint64_t REQUEST_TIMEOUT_MICROSECONDS = 20000U * 1000U;
#endif
