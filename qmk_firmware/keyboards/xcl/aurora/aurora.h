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

#endif
