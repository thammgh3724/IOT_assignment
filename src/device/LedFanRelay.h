#ifndef LedFanRelay_
#define LedFanRelay_

#include "global.h"

void ledFanRelay_init();

void turn_on_led();
void turn_off_led();

void turn_on_fan();
void turn_off_fan();

void turn_on_pixel();

int read_pir();

#endif