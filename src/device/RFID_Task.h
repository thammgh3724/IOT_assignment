#ifndef RFID_TASK_H_
#define RFID_TASK_H_

#include "global.h"
#include <SPI.h>
#include <MFRC522.h>
extern String room_attr_name;
extern std::vector<String> room_allowedUIDs;

void rfid_init();
#endif