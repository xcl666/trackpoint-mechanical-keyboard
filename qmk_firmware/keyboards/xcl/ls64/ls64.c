#include "ls64.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
  {
    /* Key Matrix to LED Index */
    { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13 },
    { 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14 },
    { 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, NO_LED },
    { 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41 },
    { 55, 56, 57, 58, 59, 60, 61, 62, 63, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
  }, {
    /* LED Index to Physical Position */
    // Switch LEDs
    {0,0},    {16,0},   {32,0},   {48,0},   {64,0},   {80,0},   {96,0},   {112,0},  {128,0},  {144,0},  {160,0},  {176,0},  {192,0},  {216,0},
    {220,16}, {200,16}, {184,16}, {168,16}, {152,16}, {136,16}, {120,16}, {104,16}, {88,16},  {72,16},  {56,16},  {40,16},  {24,16},  {4,16},
    {6,32},   {28,32},  {44,32},  {60,32},  {76,32},  {92,32},  {108,32}, {124,32}, {140,32}, {156,32}, {172,32}, {188,32},           {214,32},
    {224,48}, {208,48}, {192,48}, {176,48}, {160,48}, {144,48}, {128,48}, {112,48}, {96,48},  {80,48},  {64,48},  {48,48},  {32,48},  {8,48},
    {2,64},   {22,64},  {42,64},                      {102,64},                               {160,64}, {176,64}, {192,64}, {208,64}, {224,64},
    // Underglow LEDs
    {200,3},  {152,3},  {104,3},  {40,3},
    {32,24},  {80,24},  {128,24}, {192,24},
    {216,64}, {168,64}, {72,64},  {32,64}
  }, {
    /* LED Index to Flag */
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4,       4,          4, 4, 4, 4, 4,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2
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

// void rgb_matrix_indicators_kb(void) {
//   if (host_keyboard_led_state().caps_lock) {
//     rgb_matrix_set_color(28, 255, 255, 255);
//   } else {
//     rgb_matrix_set_color(28, 0, 0, 0);
//   }

//   if (!rgb_matrix_is_enabled()) {
//     rgb_matrix_driver.flush();
//   }
// }
#endif
