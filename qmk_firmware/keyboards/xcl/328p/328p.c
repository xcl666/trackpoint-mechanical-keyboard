#include QMK_KEYBOARD_H

// place overrides here
void set_scramble_LED(uint8_t mode) {
  switch(mode) {
    case LED_ON:
      setPinOutput(PIN_LED);
      writePin(PIN_LED, GPIO_STATE_HIGH);
      break;

    case LED_DIM:
      setPinInput(PIN_LED);
      break;

    case LED_OFF:
      setPinOutput(PIN_LED);
      writePin(PIN_LED, GPIO_STATE_LOW);
      break;

    default:
      break;
  }
}
