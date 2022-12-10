#pragma once

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7322
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         328P
#define DESCRIPTION     Try ATMEGA328P

/* Matrix */
#define MATRIX_ROWS 2
#define MATRIX_COLS 3
#define MATRIX_ROW_PINS { B1, B0 }
#define MATRIX_COL_PINS { B3, B4, B5 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* LED Indicators */
#define LED_CAPS_LOCK_PIN C0
#define LED_PIN_ON_STATE 0

/* Encoder */
#define ENCODERS_PAD_A { D1 }
#define ENCODERS_PAD_B { D0 }
