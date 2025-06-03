#include "PIR.h"

int read_pir() {
    return digitalRead(PIR_PIN);
}

void pir_task(void *pvParameters)
{
    pinMode(PIR_PIN, INPUT);
    vTaskDelete(NULL); // Delete the task when done
}


void pir_task_init(){
    xTaskCreate(pir_task, "PIR_task", 4096, 0, 1, 0);
}