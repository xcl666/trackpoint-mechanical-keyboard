#include "print.h"
#include "adafruit_ble.h"
#include "enable.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT(
    KC_1,    KC_2,    KC_3,
    RGB_TOG, RGB_MOD, RGB_RMOD)
};

void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  uint32_t vol = adafruit_ble_read_battery_voltage();
  uprintf("Battery Voltage 2: %lu", vol);
#endif
  return true;
};
