#include "global.h"
#include "dispatch.h"
#define THINGSBOARD_ENABLE_PROGMEM 0
void setup()
{
  Serial.begin(115200);
  dispatch();
}

void loop() {}