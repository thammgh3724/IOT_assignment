#include "global.h"
#include "dispatch.h"
void setup()
{
  Serial.begin(115200);
  dispatch();
}

void loop() {}