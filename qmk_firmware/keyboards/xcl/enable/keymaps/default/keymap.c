#include "adafruit_ble.h"
#include "enable.h"

enum dg_custom_keycodes {
  DG_BATT = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_CAPS, KC_UP,   KC_RSFT,
    KC_LCTL, KC_LGUI,          KC_LALT,          KC_SPC,           MO(1),   MO(2),   KC_LEFT, KC_DOWN, KC_RGHT),

  [1] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT,          KC_TRNS,
    KC_TRNS,          KC_DEL,  KC_END,  KC_PGDN, KC_TRNS, KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS,          KC_TRNS,
    KC_TRNS,          KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, OUT_BT,  KC_TRNS,
    KC_TRNS, KC_TRNS,          KC_TRNS,          RESET,            KC_TRNS, KC_TRNS, DG_BATT, OUT_USB, OUT_AUTO),

  [3] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
    KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,            KC_NO,            KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO)

};

uint8_t battery_level(void) {
  float min_voltage = 3.2;
  float max_voltage = 4.2;
  float voltage = adafruit_ble_read_battery_voltage() * 2 * 3.3 / 1024;
  if (voltage < min_voltage) return 0;
  if (voltage > max_voltage) return 100;
  return (voltage - min_voltage) / (max_voltage - min_voltage) * 100;
}

void tap_battery_level(void) {
  int digits[10] = { KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9 };
  uint8_t percentage = battery_level();

  if (percentage <= 0) {
    tap_code(KC_0);
  } else if (percentage >= 100) {
    tap_code(KC_O);
    tap_code(KC_K);
  } else {
    if (percentage >= 10) {
      int index10 = (percentage / 10) % 10;
      int digit10 = digits[index10];
      tap_code(digit10);
    }
    int index1 = percentage % 10;
    int digit1 = digits[index1];
    tap_code(digit1);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DG_BATT:
      if (record->event.pressed) {
        tap_battery_level();
      }
      break;
  }
  return true;
}
