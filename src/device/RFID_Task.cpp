#include "RFID_Task.h"
MFRC522 rfid(SDA_PIN, RST_PIN);

const char *room1_attr_name = "valid_card_e1_01";
std::vector<String> room1_allowedUIDs;

String getUIDString()
{
    String uidStr = "";
    for (byte i = 0; i < rfid.uid.size; i++)
    {
        if (rfid.uid.uidByte[i] < 0x10)
            uidStr += "0";  // Thêm số 0 phía trước nếu < 0x10
        uidStr += String(rfid.uid.uidByte[i], HEX);
    }
    uidStr.toUpperCase();
    return uidStr;
}

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
            String scannedUID = getUIDString();
            Serial.print("Scanned UID: ");
            Serial.println(scannedUID);
            // Compare UID
            bool matched = false;
            for (const auto &validUID : room1_allowedUIDs)
            {
                if (scannedUID.equalsIgnoreCase(validUID))
                {
                    matched = true;
                    break;
                }
            }

            if (matched)
            {
                Serial.println("Valid UID. Open Door...");
                turn_on_relay();
                sendBoolTelemetry("door_status", true);
            }
            else
            {
                Serial.println("Invalid UID");
            }
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