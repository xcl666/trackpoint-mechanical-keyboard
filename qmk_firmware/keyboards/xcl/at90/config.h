#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7317
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         AT90
#define DESCRIPTION     Try AT90USB646

/* Matrix */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { F0, F1, F2, F3 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, A0, A1, A2, A3, A4, A5, A6, A7 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* LED Indicators */
#define LED_CAPS_LOCK_PIN D6
#define LED_PIN_ON_STATE 0

/* BLE */
#define AdafruitBleResetPin C4
#define AdafruitBleIRQPin C3
#define AdafruitBleCSPin C2
#define BATTERY_LEVEL_PIN C1

#endif
