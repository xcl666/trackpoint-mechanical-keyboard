#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7320
#define DEVICE_VER      0x0001
#define MANUFACTURER    Leo Deng
#define PRODUCT         SCBH60
#define DESCRIPTION     2U left shift 64 layout

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 14
#define MATRIX_ROW_PINS { B2, B1, B0, A7, A1, B8 }
#define MATRIX_COL_PINS { A2, A3, A4, A5, A6, B10, B11, B13, A15, B9, B3, B4, B6, B7 }
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

#define LED_CAPS_LOCK_PIN B12
#define LED_PIN_ON_STATE 0

// #ifdef BACKLIGHT_ENABLE
//   #define BACKLIGHT_PIN B0
//   #define BACKLIGHT_PWM_DRIVER PWMD3
//   #define BACKLIGHT_PWM_CHANNEL 3
// #endif

#ifdef RGBLIGHT_ENABLE
  #define RGB_DI_PIN B5
  #define RGBLED_NUM 16
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_RGB_TEST
  #define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
  /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
  #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
  /*==== use exp() and sin() ====*/
  #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
  #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif
