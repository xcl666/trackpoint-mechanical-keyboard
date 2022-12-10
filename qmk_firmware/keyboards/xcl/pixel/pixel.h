#ifndef DGKB_H
#define DGKB_H

#include "quantum.h"

#define LAYOUT( \
  K000, K101, K202 \
) { \
  { K000,  KC_NO, KC_NO }, \
  { KC_NO, K101,  KC_NO }, \
  { KC_NO, KC_NO, K202 }   \
}

enum terrazzo_matrix_effects {
  TERRAZZO_NONE = 0,
  // --------------------------------------
  // -----Begin led effect enum macros-----
#define TERRAZZO_EFFECT(name, ...) TERRAZZO_EFFECT_##name,
#include "effects.inc"
#undef TERRAZZO_EFFECT
  // -----End led effect enum macros-------
  // All new effects go above this line
  TERRAZZO_EFFECT_MAX
};

enum terrazzo_keycodes {
  TZ_OFF = SAFE_RANGE,
  TZ_NEXT,
  TZ_PLAY,
};

void terrazzo_render(void);
void terrazzo_set_pixel(uint8_t x, uint8_t y, uint8_t value);
void terrazzo_draw_at(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t image[]);
void terrazzo_scroll_pixel(bool clockwise);
void terrazzo_step_mode(void);
void terrazzo_step_mode_reverse(void);
void terrazzo_mode_off(void);

#endif
