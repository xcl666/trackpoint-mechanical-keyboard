#include "think84.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
  {
        /* Key Matrix to LED Index */
        { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11 },
        { 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 },
        { 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 },
        { 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47 }
      }, {
          /* LED Index to Physical Position */
          // Switch LEDs
          {0,0},    {20,0},   {41,0},   {61,0},   {81,0},   {102,0},  {122,0},  {143,0},  {163,0},  {183,0},  {204,0},  {224,0},
          {0,21},   {20,21},  {41,21},  {61,21},  {81,21},  {102,21}, {122,21}, {143,21}, {163,21}, {183,21}, {204,21}, {224,21},
          {0,43},   {20,43},  {41,43},  {61,43},  {81,43},  {102,43}, {122,43}, {143,43}, {163,43}, {183,43}, {204,43}, {224,43},
          {0,64},   {20,64},  {41,64},  {61,64},  {81,64},  {102,64}, {122,64}, {143,64}, {163,64}, {183,64}, {204,64}, {224,64},
          // Underglow LEDs
          {10,10},  {78,10},  {146,10}, {214,10},
          {10,53},  {78,53},  {146,53}, {214,53},
          // Alternative Underglow LEDs
          // {20,10},  {81,10},  {143,10}, {204,10},
          // {20,53},  {81,53},  {143,53}, {204,53},
        }, {
            /* LED Index to Flag */
            // Switch LEDs
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            // Underglow LEDs
            2, 2, 2, 2,
            2, 2, 2, 2,
          }
};

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

void rgb_matrix_indicators_kb(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(12, 255, 255, 255);
    }
    else {
        rgb_matrix_set_color(12, 0, 0, 0);
    }

    if (!rgb_matrix_is_enabled()) {
        rgb_matrix_driver.flush();
    }
}

#endif

