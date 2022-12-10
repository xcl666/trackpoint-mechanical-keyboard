#include "weekin21.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		TO(1), LCTL(KC_C), LCTL(KC_X), LCTL(KC_V),
		LALT(KC_F4), LCTL(KC_Z), LCTL(LSFT(KC_Z)), LCTL(LALT(KC_DEL)), LGUI(KC_L), LGUI(KC_D),
		LCTL(KC_A), KC_1, KC_2, KC_3, KC_4, KC_5,
		KC_6, KC_7, KC_8, KC_9, KC_0, LSFT(KC_DEL)),

	KEYMAP(
		TO(2), LGUI(KC_C), LGUI(KC_X), LGUI(KC_V),
		LGUI(LSFT(KC_4)), KC_A, KC_B, KC_C, KC_D, KC_E,
		KC_F, KC_G, KC_H, KC_I, KC_J, KC_K,
		KC_L, KC_M, KC_N, KC_O, KC_P, RESET),

	KEYMAP(
		TO(3), LGUI(KC_PLUS), KC_TRNS, KC_TRNS,
		KC_Q, KC_R, KC_S, KC_T, KC_U, KC_V,
		KC_W, KC_X, KC_Y, KC_Z, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC),

	KEYMAP(
		TO(0), KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}

// {编码器功能} -----------------------------------------------//
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {  // 层检查
        case 0:  // MacOS
            if (clockwise) {
                register_code(KC_VOLD);
                wait_ms(10);
                unregister_code(KC_VOLD);
            } else {
                register_code(KC_VOLU);
                wait_ms(10);
                unregister_code(KC_VOLU);
            }
       	default:  // FCPX
            if (clockwise) {
                register_code16(dynamic_keymap_get_keycode(biton32(layer_state), 0, 1)); // 旋钮时触发第1层第0行第1列的按键 //
				wait_ms(10);
                unregister_code16(dynamic_keymap_get_keycode(biton32(layer_state), 0, 1));
            } else {
                register_code16(dynamic_keymap_get_keycode(biton32(layer_state), 0, 2)); // 旋钮时触发第1层第0行第1列的按键 //
				wait_ms(10);
                unregister_code16(dynamic_keymap_get_keycode(biton32(layer_state), 0, 2));
            }
    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
        oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Macos\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("FCPX\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("LrC\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Win\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("CAD\n"), false);
            break;
        case 5:
            oled_write_P(PSTR("Davinci\n"), false);
            break;
        case 6:
            oled_write_P(PSTR("AU\n"), false);
            break;
        case 7:
            oled_write_P(PSTR("AI\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}
#endif
