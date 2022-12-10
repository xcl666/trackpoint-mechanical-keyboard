#include "lightdance.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,
    _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,
    RGB_M_T, RGB_M_P, RGB_M_G, RGB_M_B, RGB_M_SW,
    _______, RGB_M_K, RGB_M_R, RGB_M_X, RGB_M_SN,
    KC_ESC,  KC_LCTL, KC_CAPS, MO(1),   MO(2)),

  [1] = LAYOUT(
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______),

  [2] = LAYOUT(
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______)

};

uint8_t blinkState1 = 0;
uint16_t blinkThreshold1 = 300;
uint16_t blinkTimestamp1 = 0;
bool blinkState2 = false;
uint16_t blinkThreshold2 = 3000;
uint16_t blinkTimestamp2 = 0;

// Layer Indicator LEDs
void matrix_scan_user(void) {
  if (timer_elapsed(blinkTimestamp1) > blinkThreshold1 && blinkState1 > 0) {
    blinkTimestamp1 = timer_read();
    blinkState1 = 3 - blinkState1;
  }

  if (timer_elapsed(blinkTimestamp2) > blinkThreshold2) {
    blinkState2 = false;
  }

  uint8_t layer = biton32(layer_state);
  if (layer == 1 || blinkState1 == 1) {
    DDRB |= (1 << 0); PORTB &= ~(1 << 0);
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  } else if (layer == 2 || blinkState1 == 2) {
    DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
    DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  } else {
    DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  }

  // switch (layer) {
  //   case 1:
  //     DDRB |= (1 << 0); PORTB &= ~(1 << 0);
  //     DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  //     break;
  //   case 2:
  //     DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
  //     DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  //     break;
  //   default:
  //     DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
  //     DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  // }
};

// RGB indicator LEDs
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {2, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_blink_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 3, HSV_CYAN}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_capslock_layer,
  my_layer1_layer,
  my_layer2_layer,
  my_blink_layer
);

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, 0));
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(1, layer_state_cmp(state, 1));
  rgblight_set_layer_state(2, layer_state_cmp(state, 2));
  return state;
}

// Custom LED effects
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ESC:
      if (record->event.pressed && !blinkState2) {
        blinkState2 = true;
        blinkTimestamp2 = timer_read();
        rgblight_blink_layer(3, blinkThreshold2);
      }
      break;

    case KC_LCTL:
      blinkState1 = record->event.pressed ? 1 : 0;
      // if (record->event.pressed) {
      //   rgblight_enable();
      //   sethsv(HSV_RED, (LED_TYPE *)&led[0]);
      //   sethsv(HSV_YELLOW, (LED_TYPE *)&led[1]);
      //   sethsv(HSV_GREEN, (LED_TYPE *)&led[2]);
      //   rgblight_set();
      // } else {
      //   rgblight_disable();
      //   sethsv(HSV_OFF, (LED_TYPE *)&led[0]);
      //   sethsv(HSV_OFF, (LED_TYPE *)&led[1]);
      //   sethsv(HSV_OFF, (LED_TYPE *)&led[2]);
      //   rgblight_set();
      // }
      break;
  }
}
