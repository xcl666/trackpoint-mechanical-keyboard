#include "think48.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SLSH, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
    KC_LCTL, KC_LGUI, KC_CAPS, KC_LALT, MO(2),   KC_SPC,  KC_SPC,  MO(1),   KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),

  [1] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    KC_CAPS, KC_INS,  KC_HOME, KC_PGUP, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_DEL,  KC_END,  KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, RGB_MOD, RGB_TOG, RGB_RMOD),

  [3] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO)

};
// 在keymap.c添加
uint16_t sampletime = 0; // 本次采样的时间
void ps2_mouse_moved_user (report_mouse_t *mouse_report) {
// mouse_report->v 纵向滚动
    if (mouse_report->v > 0) {
        if (timer_elapsed(sampletime) < 50) // 如果距离上次采样时间小于50毫秒，则不滚动
            mouse_report->v = 0;
        else {
            mouse_report->v = 1;
            sampletime = timer_read ();
        }
    }
    else if (mouse_report->v < 0) {
        if (timer_elapsed(sampletime) < 50)
            mouse_report->v = 0;
        else {
            mouse_report->v = -1;
            sampletime = timer_read ();
        }
    }

// mouse_report->h 横向滚动
    if (mouse_report->h > 0) {
        if (timer_elapsed(sampletime) < 50)
            mouse_report->h = 0;
        else {
            mouse_report->h = 1;
            sampletime = timer_read ();
        }
    }
    else if (mouse_report->h < 0) {
        if (timer_elapsed(sampletime) < 50)
            mouse_report->h = 0;
        else {
            mouse_report->h = -1;
            sampletime = timer_read ();
        }
    }
}