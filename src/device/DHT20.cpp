#include "DHT20.h"

DHT20 dht20(&Wire);

void dht_task(void *pvParameters)
{
    bool startWireStatus = Wire.begin(DHT_SDA, DHT_SCL);

    while (true)
    {
        if (startWireStatus)
        {
            int status = dht20.read();

            switch (status)
            {
            case DHT20_OK:
            {
                float dht_temp = dht20.getTemperature();
                float dht_humi = dht20.getHumidity();
                String env_data = "{\"env_temp\":" + String(dht_temp) +
                                  ",\"env_humi\":" + String(dht_humi) + "}";
                sendTelemetry(env_data);
                // ESP_LOGI("DHT", "TEMP: %.2f HUMI: %.2f", dht_temp, dht_humi);
                Serial.printf("DHT TEMP: %.2f HUMI: %.2f", dht_temp, dht_humi);
                Serial.println("");
            }
            break;
            case DHT20_ERROR_CHECKSUM:
                Serial.println("DHT Checksum error");
                break;
            case DHT20_ERROR_CONNECT:
                Serial.println("DHT Connect error");
                break;
            case DHT20_MISSING_BYTES:
                Serial.println("DHT Missing bytes");
                break;
            case DHT20_ERROR_BYTES_ALL_ZERO:
                Serial.println("DHT All bytes read zero");
                break;
            case DHT20_ERROR_READ_TIMEOUT:
                Serial.println("DHT Read time out");
                break;
            case DHT20_ERROR_LASTREAD:
                Serial.println("DHT Error read too fast");
                break;
            default:
                Serial.println("DHT Unknown error");
                break;
            }
        }
        else
        {
            Serial.println("DHT Fail to connect to DHT");
        }
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

void dht_task_init()
{
    xTaskCreate(dht_task, "DHT_Task", 4096, 0, 1, 0);
}