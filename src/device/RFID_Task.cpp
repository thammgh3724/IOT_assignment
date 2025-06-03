#include "RFID_Task.h"
MFRC522 rfid(SDA_PIN, RST_PIN);
void rfid_task(void *pvParameters)
{
    while (true)
    {
        if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
        {
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
        else
        {
            // Print card UID
            Serial.print("Card UID: ");
            for (byte i = 0; i < rfid.uid.size; i++)
            {
                Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
                Serial.print(rfid.uid.uidByte[i], HEX);
            }
            Serial.println();
            rfid.PICC_HaltA();
        }
    }
}
void rfid_init()
{
    SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, SDA_PIN);
    rfid.PCD_Init();
    // pinMode(BUZZER, OUTPUT);
    Serial.println("RC522 initialized. Waiting for RFID tags...");
    xTaskCreate(rfid_task, "RFID_Task", 4096, NULL, 1, NULL);
}