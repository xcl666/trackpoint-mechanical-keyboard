#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7316
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         LS64
#define DESCRIPTION     2U left shift 64 layout

/* Matrix */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14
#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6 }
#define MATRIX_COL_PINS { B0, B1, B2, B3, B4, B5, B6, B7, D0, D1, D2, D3, D4, D5 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* LED Indicators */
#define LED_CAPS_LOCK_PIN D6
#define LED_PIN_ON_STATE 0

/* WS2812 RGB */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN E6
#define RGBLED_NUM 76
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

#define DRIVER_LED_TOTAL (RGBLED_NUM)
#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_TIMEOUT 0
#define RGB_DISABLE_AFTER_TIMEOUT 0
#define RGB_DISABLE_WHEN_USB_SUSPENDED false
#define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5
#define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
#define RGB_MATRIX_STARTUP_HUE 0
#define RGB_MATRIX_STARTUP_SAT 255
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_STARTUP_SPD 127
#endif

/* VIA */
// #ifdef VIA_ENABLE
// #define DYNAMIC_KEYMAP_LAYER_COUNT 2
// #endif

#endif
