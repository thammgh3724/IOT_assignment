#include "device.h"

void device_init(){
    ledFanRelay_init();
    dht_task_init();
    pir_task_init();
    rfid_init();
}