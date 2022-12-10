#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7305
#define DEVICE_VER      0x0002
#define MANUFACTURER    Leo Deng
#define PRODUCT         Plancky
#define DESCRIPTION     Pro Micro driven 40% ortholinear layout keyboard

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* Matrix */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { D3, D7, E6, B3 }
#define MATRIX_COL_PINS { D2, C6, D4, D0, D1, B6, B2, F4, F5, F6, F7, B1 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* Backlight */
#define BACKLIGHT_PIN B5
#define BACKLIGHT_LEVELS 5
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 5
#define BACKLIGHT_ON_STATE 1

#endif