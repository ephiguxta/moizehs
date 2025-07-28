#include "bt_handler.h"


void setup() {
    Serial.begin(115200);
    bt_begin();
}

void loop(){
    struct bt_cmd_data bt_cmd_info;

    if (bt_client_cmd_recv(&bt_cmd_info) == true) {
        Serial.printf("[%s](%d)\n", bt_cmd_info.cmd, bt_cmd_info.size);
    }

    delay(250);
}