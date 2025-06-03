#include "LightAuto_Task.h"

int light_auto_state = 0;
int counter = 0;

void light_auto_task(void *pvParameters)
{
    while (true)
    {
        if (light_auto_state == 1) {
            int pir_value = read_pir();
            if (pir_value == 1) {
                turn_on_pixel();
                sendBoolTelemetry("light_status", true); 
                Serial.println("Turn on pixel");
                counter = 0;
            }
            if (pixel_state == 1){
                if (counter >= 5) {
                    turn_off_pixel();
                    sendBoolTelemetry("light_status", false); 
                    Serial.println("Turn off pixel");
                    counter = 0;
                }
                else {
                    counter++;
                }
            }
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void light_auto_task_init() {
    xTaskCreate(light_auto_task, "Light_Auto_task", 4096, 0, 1, 0);
}