#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7307
#define DEVICE_VER      0x0004
#define MANUFACTURER    Leo Deng
#define PRODUCT         Plancky3
#define DESCRIPTION     40% ortholinear layout keyboard

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* Matrix */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { B5, D7, B3, F4 }
#define MATRIX_COL_PINS { B4, E6, C6, D4, D1, D0, B6, B2, F5, F6, F7, B1 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

#endif