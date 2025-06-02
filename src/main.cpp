#include "global.h"

void setup()
{
  // Initalize serial connection for debugging
  Serial.begin(115200);

  ledFanRelay_init();
  dht_task_init();
  pir_task_init();

  connect_task_init();
}

void loop()
{
}