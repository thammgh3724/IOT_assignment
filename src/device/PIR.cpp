#include "PIR.h"

int read_pir() {
    return digitalRead(PIR_PIN);
}

void pir_task(void *pvParameters)
{
    pinMode(PIR_PIN, INPUT);

    while (true)
    {
        int pir_value = read_pir();
        Serial.printf("PIR Value: %d", pir_value);
        Serial.println("");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}


void pir_task_init(){
    xTaskCreate(pir_task, "PIR_task", 4096, 0, 1, 0);
}