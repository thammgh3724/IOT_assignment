#include "LedFanRelay.h"

Adafruit_NeoPixel pixels(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void turn_on_led() {
  digitalWrite(LED_PIN, HIGH);
}
void turn_off_led() {
  digitalWrite(LED_PIN, LOW);
}

void turn_on_fan() {
  digitalWrite(FAN_PIN, HIGH);
}
void turn_off_fan() {
  digitalWrite(FAN_PIN, LOW);
}

void turn_on_pixel() {
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));
  pixels.setPixelColor(1, pixels.Color(0, 150, 0));
  pixels.setPixelColor(2, pixels.Color(0, 150, 0));
  pixels.setPixelColor(3, pixels.Color(0, 150, 0));
  pixels.show();
}

void turn_off_pixel() {
  pixels.clear();
}

void turn_on_relay() {
  digitalWrite(RELAY_PIN, HIGH);
}
void turn_off_relay() {
  digitalWrite(RELAY_PIN, LOW);
}

void ledFanRelay_init_task(void *pvParameters){
  pinMode(LED_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pixels.begin();
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  turn_off_led();
  turn_off_pixel();
  turn_off_relay();
  vTaskDelete(NULL); // Delete the task when done
}

int led_state = 0;

void led_blink_task(void *pvParameters)
{
  while (1)
  {
    if (led_state == 0)
    {
      turn_on_led();
    }
    else
    {
      turn_off_led();
    }
    led_state = 1 - led_state;
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void ledFanRelay_init() {
  xTaskCreate(ledFanRelay_init_task, "ledFanRelay_init_task", 4096, 0, 1, 0);
  xTaskCreate(led_blink_task, "led_blink_task", 4096, 0, 1, 0);
}
