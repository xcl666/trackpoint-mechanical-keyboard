#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,  KC_ENT,  KC_CAPS,
    KC_SPC,  KC_A,    MO(1)),

  [1] = LAYOUT(
    RESET,   _______, _______,
    _______, _______, _______),

};

void matrix_init_user(void) {
  set_scramble_LED(LED_OFF);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
  return true;
}
