#include "aurora.h"

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 * driver
 * |  R location
 * |  |      G location
 * |  |      |      B location
 * |  |      |      | */
  { 0, C3_2,  C3_7,  C3_8 },
  { 0, C6_6,  C6_5,  C6_4 },
  { 0, C1_9,  C1_10, C1_15 },
  { 0, C6_14, C6_13, C6_12 },
};

led_config_t g_led_config = {
  {
    // Key Matrix to LED Index
    { 1, 3, NO_LED }
  }, {
    // LED Index to Physical Position
    { 0, 64 },
    { 0, 0 },
    { 224, 64 },
    { 224, 0 }
  }, {
    // LED Index to Flag
    2, 4, 2, 4
  }
};

void suspend_power_down_kb(void) {
  rgb_matrix_set_suspend_state(true);
  suspend_power_down_user();
};

void suspend_wakeup_init_kb(void) {
  rgb_matrix_set_suspend_state(false);
  suspend_wakeup_init_user();
};
