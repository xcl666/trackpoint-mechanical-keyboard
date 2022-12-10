#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    qmkbuilder
#define PRODUCT         keyboard
#define DESCRIPTION     Keyboard

#define MATRIX_ROWS 4
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D4, D6, D7, B4 }
#define MATRIX_COL_PINS { B7, B3, B2, B1, E6, F0 }
#define UNUSED_PINS

#define DIODE_DIRECTION ROW2COL

#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }
#define ENCODER_RESOLUTION 4

#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 100000

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

#define DEBOUNCING_DELAY 5

#define LOCKING_SUPPORT_ENABLE

#define LOCKING_RESYNC_ENABLE

#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN B0
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 25
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 8