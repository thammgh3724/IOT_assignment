#ifndef RFID_TASK_H_
#define RFID_TASK_H_

#include "global.h"
#include <SPI.h>
#include <MFRC522.h>

extern byte door1_uid[4];

void rfid_init();

#endif