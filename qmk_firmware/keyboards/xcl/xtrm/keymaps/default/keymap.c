#include "xtrm.h"

bool dg_ctrl_pressed = false;
bool dg_alt_pressed = false;

enum dg_custom_keycodes {
  DG_IME = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    DG_IME,  KC_UP,   KC_CAPS,
    KC_LCTL, KC_LGUI,          KC_LALT,          KC_SPC,           MO(1),   MO(2),   KC_LEFT, KC_DOWN, KC_RGHT,

                                                                                              KC_PGUP, KC_PGDN),

  [1] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    KC_CAPS, KC_INS,  KC_HOME, KC_PGUP, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT,          KC_TRNS,
    KC_TRNS,          KC_DEL,  KC_END,  KC_PGDN, KC_TRNS, KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS, KC_TRNS, KC_MUTE,
    KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                                                              KC_VOLD, KC_VOLU),

  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS,          KC_TRNS,
    KC_TRNS,          KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,          KC_TRNS,          RESET,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                                                              KC_BRID, KC_BRIU),

  [3] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
    KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,            KC_NO,            KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

                                                                                              KC_NO,   KC_NO)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {}
  return MACRO_NONE;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LCTL:
      dg_ctrl_pressed = record->event.pressed;
      break;

    case KC_LALT:
      dg_alt_pressed = record->event.pressed;
      break;

    case DG_IME:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_SPC);
      } else {
        unregister_code(KC_SPC);
        unregister_code(KC_LCTL);
      }
      break;

  }
  return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  uint8_t layer = biton32(layer_state);

  if (layer == 0 && dg_ctrl_pressed) {
    tap_code(clockwise ? KC_RGHT : KC_LEFT);
    return true;
  }
  if (layer == 0 && dg_alt_pressed) {
    if (clockwise) {
      tap_code(KC_TAB);
    } else {
      register_code(KC_LSFT);
      tap_code(KC_TAB);
      unregister_code(KC_LSFT);
    }
    return true;
  }

  if (clockwise) {
    tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 6 }));
  } else {
    tap_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 4 }));
  }

  return true;
}
