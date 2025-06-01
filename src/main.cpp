#include "global.h"
// int led_state = 0;

// void ledBlinkTask(void *pvParameters)
// {
//   while (1)
//   {
//     if (led_state == 0)
//     {
//       turn_on_led();
//     }
//     else
//     {
//       turn_off_led();
//     }
//     led_state = 1 - led_state;
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }

// void reconnectWifiTask(void *pvParameters)
// {
//   while (1)
//   {
//     if (WiFi.status() != WL_CONNECTED)
//     {
//       WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//       Serial.print("Connecting again to WiFi..");
//     }
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }

// void InitWiFiTask(void *pvParameters)
// {
//   Serial.println("Connecting to AP ...");
//   // Attempting to establish a connection to the given WiFi network
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     // Delay 1000ms until a connection has been successfully established
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//     Serial.print(".");
//   }
//   Serial.println("Connected to AP");
//   xTaskCreate(reconnectWifiTask, "reconnectWifiTask ", 8192, NULL, 1, NULL);
//   vTaskDelete(NULL); // Delete the task when done
// }

// void DHT20Task(void *pvParameters)
// {
//   while (1)
//   {
//     vTaskDelay(5000 / portTICK_PERIOD_MS);
//     if (millis() - dht20.lastRead() >= 2000)
//     {
//       int status = dht20.read();
//       float temperature = dht20.getTemperature();
//       float humidity = dht20.getHumidity();

//       Serial.print("DHT20 Temperature: ");
//       Serial.print(temperature, 1);
//       Serial.println(" °C");

//       Serial.print("DHT20 Humidity: ");
//       Serial.print(humidity, 1);
//       Serial.println(" %");

//       Serial.print("Status: ");
//       switch (status)
//       {
//       case DHT20_OK:
//         Serial.println("OK");
//         break;
//       case DHT20_ERROR_CHECKSUM:
//         Serial.println("Checksum error");
//         break;
//       case DHT20_ERROR_CONNECT:
//         Serial.println("Connect error");
//         break;
//       case DHT20_MISSING_BYTES:
//         Serial.println("Missing bytes");
//         break;
//       case DHT20_ERROR_BYTES_ALL_ZERO:
//         Serial.println("All bytes read zero");
//         break;
//       case DHT20_ERROR_READ_TIMEOUT:
//         Serial.println("Read time out");
//         break;
//       case DHT20_ERROR_LASTREAD:
//         Serial.println("Read too fast");
//         break;
//       default:
//         Serial.println("Unknown error");
//         break;
//       }
//       Serial.println();
//     }
//   }
//   vTaskDelete(NULL); // Delete the task when done
// }

// void checkPirTask(void *pvParameters)
// {
//   while (1)
//   {
//     int pir_value = read_pir();
//     Serial.print("PIR Value: ");
//     Serial.print(pir_value);
//     vTaskDelay(1000 / portTICK_PERIOD_MS);
//   }
// }

void setup()
{
  // Initalize serial connection for debugging
  Serial.begin(115200);

  //   init_hardware();

  // #ifdef DHT20_EN
  //   Wire.begin(SDA_PIN, SCL_PIN);
  //   if (!dht20.begin())
  //   {
  //     Serial.println("Failed to initialize DHT20 sensor!");
  //   }
  //   else
  //   {
  //     xTaskCreate(DHT20Task, "DHT20Task", 8192, NULL, 1, NULL);
  //     Serial.println("DHT20 sensor initialized.");
  //   }
  // #endif

  //   xTaskCreate(ledBlinkTask, "ledBlinkTask", 4096, NULL, 1, NULL);
  //   xTaskCreate(InitWiFiTask, "InitWiFiTask", 4096, NULL, 1, NULL);
  //   xTaskCreate(checkPirTask, "checkPirTask", 4096, NULL, 1, NULL);

  //   turn_on_pixel();

  //   turn_on_fan();
  //   delay(5000);
  //   turn_off_fan();
  // connect_task_init();
}

void loop()
{
}