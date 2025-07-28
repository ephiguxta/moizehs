#include "BluetoothSerial.h"
#include <string.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth não está habilitado!
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error SPP para o Bluetooth não está habilitado!
#endif

struct bt_cmd_data {
    char cmd[32];
    uint8_t size;
};

bool bt_begin(void);
bool bt_client_cmd_recv(struct bt_cmd_data *bt_cmd_info);
bool bt_client_valid_cmd(const char cmd[32]);