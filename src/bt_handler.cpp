#include "bt_handler.h"

const char bt_name_sample[] = "obd_sigeauto";

BluetoothSerial serial_bt;

bool bt_begin(void) {
    serial_bt.begin(bt_name_sample);

    delay(100);

    uint8_t mac[8];

    serial_bt.getBtAddress(mac);

    for(uint8_t i = 0; i < ESP_BD_ADDR_LEN; i++) {
        Serial.printf("%02x ", mac[i]);
    }

    Serial.printf("\n");

    return true;
}

bool bt_client_cmd_recv(struct bt_cmd_data *bt_cmd_info) {
    int cmd_size = serial_bt.available();

    bt_cmd_info->size = cmd_size;

    if (cmd_size > 0 && cmd_size <= 32) {

        for(uint8_t i = 0; i < cmd_size; i++) {

            char data = (char) serial_bt.read();

            // CR é mandatório nos envios de comando
            if(data == '\r') {
                bt_cmd_info->cmd[i] = '\0';
                serial_bt.flush();
                break;
            }

            bt_cmd_info->cmd[i] = data;
        }

        if(bt_client_valid_cmd(bt_cmd_info->cmd)) {
            return true;
        }
    }

    return false;
}

bool bt_client_valid_cmd(const char cmd[32]) {
    const char cmds[2][32] {
        "/get_vin",
        "/get_km"
    };

    for(uint8_t i = 0; i < 2; i++) {
        if(strncmp(cmd, cmds[i], 32) == 0) {
            return true;
        }
    }

    return false;
}