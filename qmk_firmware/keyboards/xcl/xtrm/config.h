#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7303
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         Xtrm
#define DESCRIPTION     Extremely borderless 40% keyboard with an encoder

/* DFU */
#define QMK_ESC_INPUT D2  // usually ROW
#define QMK_ESC_OUTPUT F0 // usually COL
#define QMK_LED D1

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* Matrix */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { D2, D3, F1, B7 }
#define MATRIX_COL_PINS { F0, D5, F4, F5, F6, F7, C7, C6, B6, B5, B4, D4 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* LED Indicators */
#define LED_CAPS_LOCK_PIN D1
#define LED_PIN_ON_STATE 0

/* Encoder */
#define ENCODERS_PAD_A { D7 }
#define ENCODERS_PAD_B { D6 }

#endif