#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7311
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         Alps
#define DESCRIPTION     RKJXT1F42001

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* Matrix */
#define MATRIX_ROWS 1
#define MATRIX_COLS 5
#define MATRIX_ROW_PINS { B5 }
#define MATRIX_COL_PINS { D1, D0, D4, C6, D7 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* Encoder */
#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }

/* WS2812 RGB */
#define RGB_DI_PIN F4
#define RGBLED_NUM 3
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#endif
