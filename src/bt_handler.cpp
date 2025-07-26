#include "bt_handler.h"

const char bt_name_sample[] = "obd_sigeauto";

BluetoothSerial serial_bt;

bool bt_begin(void) {
    serial_bt.begin(bt_name_sample);

    delay(100);

    uint8_t mac[8];

    serial_bt.getBtAddress(mac);

    for(uint8_t i = 0; i < 8; i++) {
        Serial.printf("%02x ", mac[i]);
    }

    Serial.printf("\n");
}