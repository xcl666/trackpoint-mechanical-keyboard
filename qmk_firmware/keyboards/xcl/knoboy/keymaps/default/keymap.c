#include "knoboy.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,  KC_SPC,  KC_ENT,             KC_UP,   // ←  These two keys are bond to encoder anti-clockwise and clockwise.
    MO(1),   KC_LEFT, KC_RGHT,            KC_DOWN, // ←  They are physically invisible.
    MO(2),
    MO(3),      KC_CAPS),

  [1] = LAYOUT(
    RESET,   KC_TAB,  KC_BSPC,            KC_PGUP, // ←  These two keys are bond to encoder anti-clockwise and clockwise.
    KC_TRNS, KC_HOME, KC_END,             KC_PGDN, // ←  They are physically invisible.
    KC_TRNS,
    KC_TRNS,    KC_TRNS),

  [2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS,            KC_VOLU, // ←  These two keys are bond to encoder anti-clockwise and clockwise.
    KC_TRNS, KC_TRNS, KC_TRNS,            KC_VOLD, // ←  They are physically invisible.
    KC_TRNS,
    KC_TRNS,    KC_TRNS),

  [3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS,            KC_BRIU, // ←  These two keys are bond to encoder anti-clockwise and clockwise.
    KC_TRNS, KC_TRNS, KC_TRNS,            KC_BRID, // ←  They are physically invisible.
    KC_TRNS,
    KC_TRNS,    KC_TRNS)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {}
  return MACRO_NONE;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    DDRF |= (1 << 5); PORTF &= ~(1 << 5);
  } else {
    DDRF &= ~(1 << 5); PORTF &= ~(1 << 5);
  }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  uint8_t layer = biton32(layer_state);

  if (clockwise) {
    tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 1, .col = 3 }));
  } else {
    tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 0, .col = 3 }));
  }
  return true;
}