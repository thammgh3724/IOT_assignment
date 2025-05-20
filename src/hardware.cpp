#include "hardware.h"

Adafruit_NeoPixel pixels(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void init_hardware() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(FAN_PIN, OUTPUT);
    pixels.begin();
    delay(1000);
    turn_off_led();
    pixels.clear();
}

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