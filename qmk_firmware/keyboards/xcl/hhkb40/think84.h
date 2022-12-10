#ifndef DGKB_H
#define DGKB_H

#include "quantum.h"

#define LAYOUT( \
	K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, \
	      K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, \
	      K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, \
	      K301, K302, K303, K304,             K307,       K309, K310, K311  \
) { \
	{ KC_NO, K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012 }, \
	{ KC_NO, K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112 }, \
	{ KC_NO, K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212 }, \
	{ KC_NO, K301,  K302,  K303,  K304,  KC_NO, KC_NO, K307,  KC_NO, K309,  K310,  K311,  KC_NO }  \
}
#endif
