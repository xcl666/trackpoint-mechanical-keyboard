#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7304
#define DEVICE_VER      0x0002
#define MANUFACTURER    Leo Deng
#define PRODUCT         Redox Lite
#define DESCRIPTION     Split Ergodox-like 5x7 custom keyboard

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* Matrix */
#define MATRIX_ROWS 10
#define MATRIX_COLS 7
#define MATRIX_ROW_PINS { D4, C6, E6, B4, B5 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* Split */
#define USE_SERIAL
#define MASTER_LEFT // #define MASTER_RIGHT
#define SOFT_SERIAL_PIN D0

/* WS2812 RGB */
#define RGB_DI_PIN D3
#define RGBLED_NUM 12
#define RGBLIGHT_SPLIT
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#endif
