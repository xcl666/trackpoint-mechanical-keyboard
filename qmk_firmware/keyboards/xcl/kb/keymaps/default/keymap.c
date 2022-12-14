#include "kb.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
		KC_P7, KC_P8, KC_P9, KC_PPLS,
		KC_P4, KC_P5, KC_P6,
		KC_P1, KC_P2, KC_P3, KC_ENT,
		KC_P0, KC_PDOT),

	[1] = LAYOUT(
		KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
		KC_P7, KC_P8, KC_P9, KC_PPLS,
		KC_P4, KC_P5, KC_P6,
		KC_P1, KC_P2, KC_P3, KC_ENT,
		KC_P0, KC_PDOT),


};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
		return false;
}


#ifdef OLED_DRIVER_ENABLE
    static const char PROGMEM test[] = {
0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xf7, 0xb7, 0xb7, 0xb6, 0xb0, 0xb1, 0x07, 0x07, 0xb1, 0xb4, 0xb6, 0xb7, 0xb3, 0xf7, 0xff,
0xff, 0xff, 0x7f, 0x1d, 0xbd, 0xad, 0xad, 0xad, 0xad, 0xa0, 0xa0, 0xad, 0xad, 0xa5, 0xa5, 0x3c,
0x9d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0x73, 0x73, 0x63, 0x07, 0x8f,
0xff, 0xff, 0x1f, 0x0f, 0xe7, 0xf3, 0xf3, 0x73, 0x73, 0x73, 0x67, 0xff, 0xff, 0xff, 0x03, 0x03,
0x73, 0x73, 0x63, 0x07, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xcf, 0x53, 0x9c, 0xce,
0xe7, 0x03, 0x01, 0x69, 0x69, 0x68, 0x68, 0x69, 0x69, 0x61, 0x3f, 0xff, 0xff, 0xfe, 0x3e, 0x02,
0xd8, 0xde, 0x1e, 0xfe, 0xfe, 0x02, 0x42, 0x7e, 0x7e, 0x7e, 0x00, 0x78, 0x7f, 0xff, 0xff, 0xff,
0xbf, 0xa0, 0xa0, 0xb6, 0x36, 0x20, 0x8e, 0x8f, 0xa0, 0x20, 0x86, 0x96, 0xa0, 0x9e, 0xbf, 0xff,
0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0x00, 0x80, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xf9, 0xfb,
0xff, 0xff, 0x7e, 0x7e, 0xbf, 0x9f, 0xc0, 0xe0, 0xfe, 0xfe, 0xfe, 0xc0, 0x80, 0x9f, 0x9f, 0x9f,
0x9f, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xfe, 0xfe, 0xf8, 0xe0, 0xc3,
0xdf, 0xff, 0xf0, 0xe0, 0xc7, 0xcf, 0xcf, 0xce, 0xce, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xc0, 0xc0,
0xce, 0xce, 0xce, 0xc0, 0xe0, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xe8, 0xe4, 0x65, 0x94,
0xc7, 0xf0, 0x80, 0x80, 0xfb, 0xc0, 0xfb, 0xc0, 0xbb, 0x1b, 0x80, 0xff, 0xff, 0xfe, 0xff, 0x80,
0xf7, 0xf7, 0xe0, 0xfb, 0xfb, 0xfa, 0xfb, 0xfb, 0xdb, 0x99, 0x1b, 0x83, 0xe0, 0xff, 0xff, 0xfb,
0xfb, 0xf9, 0x81, 0xd8, 0xd8, 0x81, 0xd9, 0xff, 0x81, 0xd9, 0xd8, 0xd8, 0x81, 0xf9, 0xf9, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff



      };


void oled_task_user(void) {
   // oled_write_P(PSTR("MARK YE"), false);
//    oled_write_P(qmk_logo, false);
    oled_write_raw_P(test, sizeof(test));
}

#endif






/*
0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xf7, 0xb7, 0xb7, 0xb6, 0xb0, 0xb1, 0x07, 0x07, 0xb1, 0xb4, 0xb6, 0xb7, 0xb3, 0xf7, 0xff,
0xff, 0xff, 0x7f, 0x1d, 0xbd, 0xad, 0xad, 0xad, 0xad, 0xa0, 0xa0, 0xad, 0xad, 0xa5, 0xa5, 0x3c,
0x9d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0x73, 0x73, 0x63, 0x07, 0x8f,
0xff, 0xff, 0x1f, 0x0f, 0xe7, 0xf3, 0xf3, 0x73, 0x73, 0x73, 0x67, 0xff, 0xff, 0xff, 0x03, 0x03,
0x73, 0x73, 0x63, 0x07, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xcf, 0x53, 0x9c, 0xce,
0xe7, 0x03, 0x01, 0x69, 0x69, 0x68, 0x68, 0x69, 0x69, 0x61, 0x3f, 0xff, 0xff, 0xfe, 0x3e, 0x02,
0xd8, 0xde, 0x1e, 0xfe, 0xfe, 0x02, 0x42, 0x7e, 0x7e, 0x7e, 0x00, 0x78, 0x7f, 0xff, 0xff, 0xff,
0xbf, 0xa0, 0xa0, 0xb6, 0x36, 0x20, 0x8e, 0x8f, 0xa0, 0x20, 0x86, 0x96, 0xa0, 0x9e, 0xbf, 0xff,
0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0x00, 0x80, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xf9, 0xfb,
0xff, 0xff, 0x7e, 0x7e, 0xbf, 0x9f, 0xc0, 0xe0, 0xfe, 0xfe, 0xfe, 0xc0, 0x80, 0x9f, 0x9f, 0x9f,
0x9f, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xfe, 0xfe, 0xf8, 0xe0, 0xc3,
0xdf, 0xff, 0xf0, 0xe0, 0xc7, 0xcf, 0xcf, 0xce, 0xce, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xc0, 0xc0,
0xce, 0xce, 0xce, 0xc0, 0xe0, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xe8, 0xe4, 0x65, 0x94,
0xc7, 0xf0, 0x80, 0x80, 0xfb, 0xc0, 0xfb, 0xc0, 0xbb, 0x1b, 0x80, 0xff, 0xff, 0xfe, 0xff, 0x80,
0xf7, 0xf7, 0xe0, 0xfb, 0xfb, 0xfa, 0xfb, 0xfb, 0xdb, 0x99, 0x1b, 0x83, 0xe0, 0xff, 0xff, 0xfb,
0xfb, 0xf9, 0x81, 0xd8, 0xd8, 0x81, 0xd9, 0xff, 0x81, 0xd9, 0xd8, 0xd8, 0x81, 0xf9, 0xf9, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
*/
