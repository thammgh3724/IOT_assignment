#include "DHT20.h"
#include "Adafruit_NeoPixel.h"

#define LED_PIN 48

#define FAN_PIN 6

#define PIXEL_PIN 8
#define NUMPIXELS 4

#define SDA_PIN 11
#define SCL_PIN 12

#define DHT20_EN 0

void init_hardware();

void turn_on_led();
void turn_off_led();

void turn_on_fan();
void turn_off_fan();

void turn_on_pixel();