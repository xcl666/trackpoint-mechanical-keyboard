#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7302
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         Knoboy
#define DESCRIPTION     Palm pad with an encoder

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* Matrix */
#define MATRIX_ROWS 3
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { B6, B4, D7 }
#define MATRIX_COL_PINS { B5, C6, C7, B7 }
#define DIODE_DIRECTION ROW2COL // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* Encoder */
#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D5 }

#endif