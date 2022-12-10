#include "enable.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
  {
    { 0, 1, 2 },
    { NO_LED, NO_LED, NO_LED },
  },
  {
    { 0, 0 }, { 112, 0 }, { 224, 0 },
  },
  {
    4, 4, 4,
  }
};

#endif
