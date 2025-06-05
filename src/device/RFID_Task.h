#ifndef RFID_TASK_H_
#define RFID_TASK_H_

#include "global.h"
#include <SPI.h>
#include <MFRC522.h>
extern const char *room1_attr_name;
extern std::vector<String> room1_allowedUIDs;

void rfid_init();
#endif