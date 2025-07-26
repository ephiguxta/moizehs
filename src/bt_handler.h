#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth não está habilitado!
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error SPP para o Bluetooth não está habilitado!
#endif

bool bt_begin(void);